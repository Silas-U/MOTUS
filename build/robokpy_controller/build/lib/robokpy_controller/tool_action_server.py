#!/usr/bin/env python3
# """
# Author: Silas Udofia
# Motus — Tool Manager Node
#
# Hardware boundary node for end-effector tooling.
# Sits between the MotionController and physical hardware.
#
# Receives:  /tool_command  (String) — "tool_id:command"
# Publishes: /tool_status   (String) — "tool_id:status"
#
# Supported backends (configured per tool in launch file):
#   'digital_io'  — GPIO HIGH/LOW via gpiozero or RPi.GPIO
#   'ros_service' — ROS2 service call to a hardware driver
#   'ros_topic'   — publish to a hardware driver topic
#   'modbus'      — Modbus TCP register write (requires pymodbus)
#   'mock'        — simulated tool for testing (no hardware needed)
#   'gripper_action' — mimic-joint gripper via GripperActionController
#                   (control_msgs/action/GripperCommand — same
#                   interface a real UR/Robotiq driver exposes).
#                   Requires an action server (e.g.
#                   gripper_mimic_action_server) — gives max_effort
#                   force-limiting and stall/grasp detection.
#   'gripper_position' — mimic-joint gripper via a plain position
#                   ForwardCommandController, no action server needed.
#                   Matches gz_ros2_control_demos'
#                   gripper_mimic_joint_example_position pattern —
#                   the follower joints are driven entirely by
#                   gz_ros2_control's native mimic support. No
#                   max_effort/stall feedback; fire-and-forget position
#                   command.
#   'grasp_attach'  — sim-only pick backend calling GraspAttach.srv to
#                   weld/un-weld a target object to the gripper's
#                   parent_link. Vision-driven: params=[x,y,z(,max_distance)]
#                   resolved to a child_model via object_pose_resolver's
#                   /resolve_object_pose service. Manual/primitive:
#                   command "attach:<child_model>" bypasses the resolver.
#                   Detach targets the joint_id returned by the prior
#                   attach call.
#
# Tool configuration is loaded from the 'tools' ROS2 parameter
# which is a JSON string defining each tool's backend and settings.
#
# Example launch parameter:
#   tools: |
#     {
#       "gripper_1": {
#         "backend": "gripper_position",
#         "topic": "/gripper_action_controller/commands",
#         "open_position": 0.0,
#         "closed_position": 0.79
#       },
#       "vacuum": {
#         "backend": "ros_topic",
#         "topic": "/vacuum_controller/cmd",
#         "msg_type": "std_msgs/String",
#         "on_value": "on",
#         "off_value": "off"
#       },
#       "gripper_sim": {
#         "backend": "mock",
#         "open_delay": 0.3,
#         "close_delay": 0.5
#       }
#     }
#
# Dependencies (install only what your backend needs):
#   pip install gpiozero --break-system-packages       # digital I/O
#   pip install pymodbus --break-system-packages       # Modbus TCP
# """

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String, Bool, Float64MultiArray
from control_msgs.action import ParallelGripperCommand
from sensor_msgs.msg import JointState

import json
import time
import asyncio
import inspect
import threading
from typing import Optional, Dict, Any, Callable
from rclpy.task import Future
from robokpy_interfaces.srv import GraspAttach, ResolveObjectPose
from robokpy_interfaces.action import ExecuteToolOp


# =========================================================
# ASYNC PRIMITIVES BUILT ONLY ON rclpy Future/timers
# =========================================================
# rclpy's action-server coroutine execution here manually drives each
# `async def` callback and only understands `await`ing rclpy Futures —
# it does not run under a real asyncio event loop. asyncio.Lock,
# asyncio.get_running_loop(), and run_in_executor all internally
# require a genuine running loop and fail with "no running event
# loop" / "no current event loop" in this environment (asyncio.Lock
# only appeared to work earlier because an *uncontended* acquire()
# short-circuits without touching the loop — it breaks the instant a
# second goal for the same tool actually queues up). Everything below
# is built only on rclpy.task.Future + node timers instead, which is
# the same mechanism motion_planner.py's existing async handlers
# already rely on successfully.

def _future_with_timeout(node: Node, future, timeout_sec: float):
    """Arm `future` with a timeout. If it doesn't complete first, a
    TimeoutError is set on it so `await future` raises cleanly instead
    of hanging. Uses a one-shot node timer, not a blocked thread.

    Cleanup is idempotent: future.set_exception() inside _on_timeout
    synchronously fires the future's own done-callback (_on_done)
    before _on_timeout itself finishes running — both paths would
    otherwise cancel/destroy the same timer twice, crashing with
    rclpy._rclpy_pybind11.InvalidHandle. The 'cleaned' guard ensures
    only whichever path runs first actually touches the timer.
    """
    if future.done():
        return future

    state = {'cleaned': False}

    def _cleanup():
        if state['cleaned']:
            return
        state['cleaned'] = True
        state['timer'].cancel()
        state['timer'].destroy()

    def _on_timeout():
        if not future.done():
            future.set_exception(TimeoutError())
        _cleanup()

    def _on_done(_):
        _cleanup()

    state['timer'] = node.create_timer(timeout_sec, _on_timeout)
    future.add_done_callback(_on_done)
    return future


async def _wait_for_server_async(node: Node, client, timeout_sec: float,
                                  poll_period: float = 0.05) -> bool:
    """Non-blocking equivalent of client.wait_for_server(timeout_sec=...)
    — polls readiness via a repeating node timer instead of blocking a
    thread. No executor thread is held while waiting.

    Shared between rclpy.action.ActionClient instances (readiness via
    server_is_ready()) and plain node.create_client(...) service Client
    instances (readiness via service_is_ready() — no server_is_ready()
    method exists on that class). Both are passed through this same
    helper (see call sites), so it has to support both rather than
    assuming one."""
    is_service_client = hasattr(client, 'service_is_ready')

    fut = Future()
    state = {'elapsed': 0.0}

    def _poll():
        ready = (client.service_is_ready() if is_service_client
                  else client.server_is_ready())
        if ready:
            state['timer'].cancel()
            state['timer'].destroy()
            if not fut.done():
                fut.set_result(True)
            return
        state['elapsed'] += poll_period
        if state['elapsed'] >= timeout_sec:
            state['timer'].cancel()
            state['timer'].destroy()
            if not fut.done():
                fut.set_result(False)

    state['timer'] = node.create_timer(poll_period, _poll)
    return await fut


class _AsyncLock:
    """Mutual-exclusion lock usable with `async with` inside rclpy's
    coroutine-driven action callbacks. Built only on rclpy.task.Future
    for waiters + a plain threading.Lock for internal bookkeeping
    (thread-safe, event-loop-independent) — see module note above for
    why asyncio.Lock doesn't work here. Ownership transfers directly
    to the next waiter on release (no window where the lock reads as
    free), so it's safe under MultiThreadedExecutor's real concurrent
    worker threads."""

    def __init__(self):
        self._held = False
        self._waiters = []
        self._guard = threading.Lock()

    async def acquire(self):
        with self._guard:
            if not self._held:
                self._held = True
                return True
            waiter = Future()
            self._waiters.append(waiter)
        await waiter
        return True  # ownership already granted by release()

    def release(self):
        with self._guard:
            if self._waiters:
                nxt = self._waiters.pop(0)
                if not nxt.done():
                    nxt.set_result(None)
                # _held stays True — ownership handed directly to nxt
            else:
                self._held = False

    async def __aenter__(self):
        await self.acquire()
        return self

    async def __aexit__(self, exc_type, exc, tb):
        self.release()


# =========================================================
# TOOL BACKENDS
# =========================================================

class ToolBackend:
    """Base class for all tool backends."""

    def __init__(self, tool_id: str, config: dict, logger):
        self.tool_id = tool_id
        self.config  = config
        self.logger  = logger

    def execute(self, command: str) -> str:
        """
        Execute a command and return the resulting status string.
        Returned string is published on /tool_status as
        "<tool_id>:<status>".
        """
        raise NotImplementedError

    def cleanup(self):
        """Release hardware resources on shutdown."""
        pass


# ── Mock backend (simulation / testing) ──────────────────

class MockBackend(ToolBackend):
    """
    Simulated tool — no hardware required.
    Logs the command and returns status after a configurable delay.
    Use this for testing the full pipeline before real hardware.
    """

    def __init__(self, tool_id: str, config: dict, logger):
        super().__init__(tool_id, config, logger)
        self._state = 'idle'

        # Command → (status_to_report, delay_seconds)
        self._responses = {
            'open':  ('opened',  config.get('open_delay',  0.3)),
            'close': ('closed',  config.get('close_delay', 0.5)),
            'on':    ('on',      config.get('on_delay',    0.2)),
            'off':   ('off',     config.get('off_delay',   0.2)),
            'grip':  ('gripped', config.get('grip_delay',  0.5)),
            'release':('released',config.get('release_delay',0.3)),
        }

    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        if cmd in self._responses:
            status, delay = self._responses[cmd]
            self.logger.info(
                f'[MOCK] {self.tool_id}:{cmd} — '
                f'simulating {delay}s delay'
            )
            time.sleep(delay)
            self._state = status
            self.logger.info(f'[MOCK] {self.tool_id} → {status}')
            return status
        else:
            self.logger.warn(
                f'[MOCK] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_command_{cmd}'

# ── Mimic-joint gripper backend via GripperActionController ─────

class GripperActionBackend(ToolBackend):
    """
    Drives a mimic-joint gripper via parallel_gripper_action_controller's
    GripperActionController, using the control_msgs ParallelGripperCommand
    action. Commands the single primary joint; mimic joints follow
    automatically via gz_ros2_control's native mimic support.
    """

    def __init__(self, tool_id: str, config: dict, logger, node: Node):
        super().__init__(tool_id, config, logger)
        self._node = node
        action_name = config.get(
            'action_name', '/gripper_action_controller/gripper_cmd')
        self._client = ActionClient(node, ParallelGripperCommand, action_name)

        self._joint_name  = config.get(
            'joint_name', 'robotiq_85_left_knuckle_joint')
        self._open_pos    = config.get('open_position', 0.001)
        self._closed_pos  = config.get('closed_position', 0.03)
        self._max_effort  = config.get('max_effort', 50.0)
        self._timeout     = config.get('action_timeout', 5.0)

    async def execute(self, command: str) -> str:
        """
        Async — awaits the action client's futures directly instead of
        blocking a worker thread on a threading.Event. Awaiting an
        rclpy Future yields control back to the executor rather than
        holding a thread for the whole op, so N concurrent/retried
        gripper ops no longer require N free executor threads (this
        was the root cause of tool ops going silent forever under
        thread-pool exhaustion). Timeouts are enforced by
        _future_with_timeout (a node timer), not by blocking.
        """
        cmd = command.lower().strip()

        if cmd in ('open', 'release'):
            target, default_status = self._open_pos, 'opened'
        elif cmd in ('close', 'grip'):
            target, default_status = self._closed_pos, 'closed'
        else:
            self.logger.warn(
                f'[GRIPPER_ACTION] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_command_{cmd}'

        # One-time/rare wait (only if the server isn't up yet) — polled
        # via a node timer, never blocks a thread.
        server_ready = await _wait_for_server_async(
            self._node, self._client, self._timeout)
        if not server_ready:
            self.logger.error(
                f'[GRIPPER_ACTION] {self.tool_id}: action server unavailable')
            return 'error_no_server'

        goal = ParallelGripperCommand.Goal()
        goal.command = JointState()
        goal.command.name     = [self._joint_name]
        goal.command.position = [float(target)]
        goal.command.velocity = []
        goal.command.effort = (
            [float(self._max_effort)] if self._max_effort else []
        )

        send_future = self._client.send_goal_async(goal)
        try:
            goal_handle = await _future_with_timeout(
                self._node, send_future, self._timeout)
        except TimeoutError:
            self.logger.warn(
                f'[GRIPPER_ACTION] {self.tool_id}:{cmd} goal-send timed out '
                f'(server never accepted/rejected the goal)')
            return 'timeout'

        if not goal_handle.accepted:
            self.logger.error(
                f'[GRIPPER_ACTION] {self.tool_id}:{cmd} goal_rejected')
            return 'goal_rejected'

        result_future = goal_handle.get_result_async()
        try:
            result_response = await _future_with_timeout(
                self._node, result_future, self._timeout)
        except TimeoutError:
            try:
                goal_handle.cancel_goal_async()
                self.logger.warn(
                    f'[GRIPPER_ACTION] {self.tool_id}:{cmd} timed out — '
                    f'cancel requested')
            except Exception as e:
                self.logger.error(
                    f'[GRIPPER_ACTION] {self.tool_id}: cancel failed: {e}')
            return 'timeout'

        result = result_response.result
        reported_position = (
            result.state.position[0] if result.state.position else float('nan')
        )

        self.logger.info(
            f'[GRIPPER_ACTION] {self.tool_id}:{cmd} execution complete  '
            f'(reached_goal={result.reached_goal}, stalled={result.stalled}, '
            f'position={reported_position:.4f})'
        )

        # ── EXPLICIT HARDWARE STATE CHECKING ──
        if cmd in ('open', 'release'):
            if result.stalled and not result.reached_goal:
                self.logger.error(f'[GRIPPER_ACTION] {self.tool_id}: Failed to open. Gripper is stalled at position {reported_position:.4f}')
                return 'open_failed_stalled'
            return 'opened'
            
        elif cmd in ('close', 'grip'):
            if result.stalled:
                return 'closed_grasped'
            if result.reached_goal:
                return 'closed_empty'
            return 'closed'


# ── Mimic-joint gripper backend via plain position ForwardCommandController ──

class GripperPositionBackend(ToolBackend):
    """
    Drives a mimic-joint gripper via a plain position
    ForwardCommandController — no action server involved. Matches
    gz_ros2_control_demos/gripper_mimic_joint_example_position exactly:
    this backend publishes a single-element Float64MultiArray position
    command for the gripper's ONE actively-controlled (primary) joint;
    every other mimic joint is driven entirely by gz_ros2_control's own
    native mimic support (URDF <mimic> tag + ros2_control <param
    name="mimic">/<param name="multiplier">) — confirmed working on
    gz-physics7-dartsim via the same demo. No coordination logic is
    needed here at all.

    TRADE-OFF vs GripperActionBackend: this is fire-and-forget — no
    max_effort force-limiting, no stall/grasp detection, no action
    result to confirm the goal was actually reached (e.g. object width
    vs commanded target). Use GripperActionBackend + an action server
    instead if force-limited grasping against real/variable objects
    becomes a requirement later.

    Config keys:
      topic          : command topic for the position
                       ForwardCommandController (default
                       '/gripper_action_controller/commands')
      open_position  : target position (rad, or m for prismatic
                       grippers) for 'open'/'release' (default 0.0)
      closed_position: target position for 'close'/'grip'
                       (default 0.79) — keep inside the joint's
                       physical limits, same jamming caveat as
                       GripperActionBackend above.
    """

    def __init__(self, tool_id: str, config: dict, logger, node: Node):
        super().__init__(tool_id, config, logger)
        self._node   = node
        self._topic  = config.get(
            'topic', '/gripper_position_controller/commands')
        self._pub    = node.create_publisher(
            Float64MultiArray, self._topic, 10)

        self._open_pos   = config.get('open_position', 0.001)
        self._closed_pos = config.get('closed_position', 0.03)

    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        if cmd in ('open', 'release'):
            target, status = self._open_pos, 'opened'
        elif cmd in ('close', 'grip'):
            target, status = self._closed_pos, 'closed'
        else:
            self.logger.warn(
                f'[GRIPPER_POSITION] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_command_{cmd}'

        msg = Float64MultiArray()
        msg.data = [float(target)]
        self._pub.publish(msg)

        self.logger.info(
            f'[GRIPPER_POSITION] {self.tool_id}:{cmd} → {status} '
            f'(target={target:.4f}, fire-and-forget — no force-limit/'
            f'stall feedback)'
        )
        return status
    

class GripperEffortBackend(ToolBackend):
    """
    Drives a mimic-joint gripper through a ros2_control
    ForwardCommandController exposing the effort command interface.

    Commands are sent as a single-element Float64MultiArray
    representing the effort applied to the primary gripper joint.
    The mimic joint follows automatically through the Gazebo
    mimic constraint.

    Config keys:
      topic          : controller command topic
                       (default '/gripper_effort_controller/commands')

      open_effort    : effort applied when opening.
                       Usually negative.
                       (default -10.0)

      close_effort   : effort applied when closing.
                       Usually positive.
                       (default 10.0)

      clamp_effort   : optional absolute effort limit.
                       (default None)
    """

    def __init__(
        self,
        tool_id: str,
        config: dict,
        logger,
        node: Node,
    ):
        super().__init__(tool_id, config, logger)

        self._topic = config.get(
            "topic",
            "/gripper_effort_controller/commands"
        )

        self._open_effort = float(
            config.get("open_effort", -10.0)
        )

        self._close_effort = float(
            config.get("close_effort", 10.0)
        )

        self._clamp = config.get("clamp_effort", None)

        self._pub = node.create_publisher(
            Float64MultiArray,
            self._topic,
            10,
        )

    def _publish_effort(self, effort: float):

        if self._clamp is not None:
            limit = abs(float(self._clamp))
            effort = max(-limit, min(limit, effort))

        msg = Float64MultiArray()
        msg.data = [float(effort)]

        self._pub.publish(msg)

    def execute(self, command: str) -> str:

        cmd = command.lower().strip()

        if cmd in ("open", "release"):

            self._publish_effort(self._open_effort)

            self.logger.info(
                f"[GRIPPER_EFFORT] {self.tool_id}: "
                f"OPEN ({self._open_effort:.2f} N)"
            )

            return "opened"

        elif cmd in ("close", "grip"):

            self._publish_effort(self._close_effort)

            self.logger.info(
                f"[GRIPPER_EFFORT] {self.tool_id}: "
                f"CLOSE ({self._close_effort:.2f} N)"
            )

            return "closed"

        else:

            self.logger.warn(
                f"[GRIPPER_EFFORT] {self.tool_id}: "
                f"Unknown command '{command}'"
            )

            return f"unknown_command_{command}"

# ── Digital I/O backend ───────────────────────────────────

class DigitalIOBackend(ToolBackend):
    """
    GPIO digital output control via gpiozero.
    Suitable for relay-controlled pneumatic grippers,
    solenoid valves, and simple on/off actuators.

    Config keys:
      pin_open    : GPIO pin number for open signal
      pin_close   : GPIO pin number for close signal (optional)
      feedback_pin: GPIO input pin for status feedback (optional)
      open_state  : 'high' or 'low' — logic level for open command
      pulse_ms    : if set, sends a pulse instead of holding the pin
    """

    def __init__(self, tool_id: str, config: dict, logger):
        super().__init__(tool_id, config, logger)

        try:
            from gpiozero import OutputDevice, InputDevice
            self._OutputDevice = OutputDevice
            self._InputDevice  = InputDevice
        except ImportError:
            raise RuntimeError(
                'gpiozero not installed. '
                'Run: pip install gpiozero --break-system-packages'
            )

        active_high = config.get('open_state', 'high').lower() == 'high'

        self._pin_open  = None
        self._pin_close = None
        self._pin_fb    = None

        if 'pin_open' in config:
            self._pin_open = OutputDevice(
                config['pin_open'], active_high=active_high)

        if 'pin_close' in config:
            self._pin_close = OutputDevice(
                config['pin_close'], active_high=not active_high)

        if 'feedback_pin' in config:
            self._pin_fb = InputDevice(config['feedback_pin'])

        self._pulse_ms = config.get('pulse_ms', 0)
        self._state    = 'idle'

    def _pulse_or_hold(self, device):
        """Pulse the pin briefly or hold it depending on config."""
        if self._pulse_ms > 0:
            device.on()
            time.sleep(self._pulse_ms / 1000.0)
            device.off()
        else:
            device.on()

    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        if cmd in ('open', 'on', 'release'):
            if self._pin_open:
                self._pulse_or_hold(self._pin_open)
                if self._pin_close:
                    self._pin_close.off()
            self._state = 'opened' if cmd == 'open' else cmd
            self.logger.info(f'[GPIO] {self.tool_id}:{cmd} → {self._state}')

        elif cmd in ('close', 'off', 'grip'):
            if self._pin_close:
                self._pulse_or_hold(self._pin_close)
                if self._pin_open:
                    self._pin_open.off()
            elif self._pin_open:
                self._pin_open.off()
            self._state = 'closed' if cmd == 'close' else cmd
            self.logger.info(f'[GPIO] {self.tool_id}:{cmd} → {self._state}')

        else:
            self.logger.warn(f'[GPIO] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_{cmd}'

        # Read feedback pin if available
        if self._pin_fb is not None:
            fb = 'active' if self._pin_fb.is_active else 'inactive'
            return f'{self._state}_{fb}'

        return self._state

    def cleanup(self):
        if self._pin_open:  self._pin_open.close()
        if self._pin_close: self._pin_close.close()
        if self._pin_fb:    self._pin_fb.close()


# ── ROS2 topic backend ────────────────────────────────────

class RosTopicBackend(ToolBackend):
    """
    Publishes a command to a ROS2 topic connected to a hardware driver.
    Suitable for gripper drivers that expose a topic interface
    (e.g. Robotiq, Schunk, custom Arduino/ESP32 nodes).

    Config keys:
      topic      : target topic name
      on_value   : string to publish for 'on'/'open'/'grip' commands
      off_value  : string to publish for 'off'/'close'/'release' commands
      cmd_map    : optional dict mapping commands to publish values
    """

    def __init__(self, tool_id: str, config: dict, logger, node: Node):
        super().__init__(tool_id, config, logger)
        self._node    = node
        self._topic   = config.get('topic', f'/{tool_id}/cmd')
        self._pub     = node.create_publisher(String, self._topic, 10)
        self._on_val  = config.get('on_value',  'open')
        self._off_val = config.get('off_value', 'close')
        self._cmd_map = config.get('cmd_map', {})

    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        # Check explicit command map first
        if cmd in self._cmd_map:
            value = self._cmd_map[cmd]
        elif cmd in ('open', 'on', 'release', 'grip'):
            value = self._on_val
        elif cmd in ('close', 'off'):
            value = self._off_val
        else:
            value = cmd   # pass through unknown commands

        msg      = String()
        msg.data = str(value)
        self._pub.publish(msg)

        self.logger.info(
            f'[ROS_TOPIC] {self.tool_id}:{cmd} → {self._topic} "{value}"'
        )
        return f'{cmd}_sent'


# ── Modbus TCP backend ────────────────────────────────────

class ModbusBackend(ToolBackend):
    """
    Modbus TCP register write for industrial grippers and PLCs.
    Suitable for Robotiq 2F-85/140, OnRobot grippers,
    and any Modbus-enabled industrial I/O module.

    Config keys:
      host          : Modbus server IP address
      port          : Modbus port (default 502)
      coil_open     : coil address for open command
      coil_close    : coil address for close command
      register_cmd  : holding register address (alternative to coils)
      value_open    : value to write for open (if using register)
      value_close   : value to write for close (if using register)
      unit_id       : Modbus unit ID (default 1)
    """

    def __init__(self, tool_id: str, config: dict, logger):
        super().__init__(tool_id, config, logger)

        try:
            from pymodbus.client import ModbusTcpClient
            self._client = ModbusTcpClient(
                host=config.get('host', '192.168.1.1'),
                port=config.get('port', 502)
            )
            connected = self._client.connect()
            if not connected:
                raise RuntimeError(
                    f'Modbus TCP connection failed to '
                    f'{config.get("host")}:{config.get("port", 502)}'
                )
            self.logger.info(
                f'[MODBUS] {tool_id} connected to '
                f'{config.get("host")}:{config.get("port", 502)}'
            )
        except ImportError:
            raise RuntimeError(
                'pymodbus not installed. '
                'Run: pip install pymodbus --break-system-packages'
            )

        self._config  = config
        self._unit_id = config.get('unit_id', 1)
        self._state   = 'idle'

    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        try:
            if 'coil_open' in self._config and cmd in ('open', 'on', 'release'):
                self._client.write_coil(
                    self._config['coil_open'], True,
                    slave=self._unit_id)
                if 'coil_close' in self._config:
                    self._client.write_coil(
                        self._config['coil_close'], False,
                        slave=self._unit_id)
                self._state = 'opened'

            elif 'coil_close' in self._config and cmd in ('close', 'off', 'grip'):
                self._client.write_coil(
                    self._config['coil_close'], True,
                    slave=self._unit_id)
                if 'coil_open' in self._config:
                    self._client.write_coil(
                        self._config['coil_open'], False,
                        slave=self._unit_id)
                self._state = 'closed'

            elif 'register_cmd' in self._config:
                value_map = {
                    'open':    self._config.get('value_open',  1),
                    'close':   self._config.get('value_close', 2),
                    'on':      self._config.get('value_open',  1),
                    'off':     self._config.get('value_close', 2),
                    'grip':    self._config.get('value_close', 2),
                    'release': self._config.get('value_open',  1),
                }
                value = value_map.get(cmd, 0)
                self._client.write_register(
                    self._config['register_cmd'], value,
                    slave=self._unit_id)
                self._state = cmd

            else:
                self.logger.warn(f'[MODBUS] {self.tool_id}: unhandled command "{cmd}"')
                return f'unhandled_{cmd}'

            self.logger.info(f'[MODBUS] {self.tool_id}:{cmd} → {self._state}')
            return self._state

        except Exception as e:
            self.logger.error(f'[MODBUS] {self.tool_id} error: {e}')
            return 'error'

    def cleanup(self):
        if self._client:
            self._client.close()


def _load_object_catalog(path: Optional[str], logger) -> tuple:
    """Loads objects.yaml's `object_types` block for GraspAttachBackend.
    Returns (types_dict, reference_size) where reference_size is the
    largest single dimension across the whole catalog — ParallelJawActuator
    uses this as its "100% closed" reference, so grip scaling needs no
    manual tuning as object types are added/removed. Returns ({}, 0.0)
    if no path is configured or loading fails; callers fall back to
    always-fully-closed behavior."""
    if not path:
        return {}, 0.0
    try:
        import yaml
    except ImportError:
        logger.error(
            '[GRASP_ATTACH] pyyaml not installed — '
            'run: pip install pyyaml --break-system-packages')
        return {}, 0.0
    try:
        with open(path, 'r') as f:
            catalog = yaml.safe_load(f) or {}
    except (OSError, yaml.YAMLError) as e:
        logger.error(f'[GRASP_ATTACH] failed to load object catalog "{path}": {e}')
        return {}, 0.0

    object_types = catalog.get('object_types', {}) or {}
    reference_size = 0.0
    for cfg in object_types.values():
        size = (cfg.get('geometry', {}) or {}).get('size', [])
        if size:
            reference_size = max(reference_size, max(size))
    return object_types, reference_size


# ── Pluggable grasp-mechanism interface ───────────────────
#
# GraspAttachBackend does the weld/unweld (GraspAttach.srv) — that
# part is identical regardless of what kind of gripper is mounted.
# What differs per hardware is only *how the fingers/suction actuate*,
# so that's factored out here. Swapping grippers (parallel-jaw ->
# suction, or a future vacuum-array/soft-gripper) is then a single
# `gripper_mechanism` config value + a matching tools.yaml block —
# zero changes to GraspAttachBackend's weld logic.

class GraspActuator:
    """One instance per gripper mechanism. engage()/disengage() are
    run as background tasks by GraspAttachBackend (see _fire_and_forget)
    — sim correctness only depends on the weld/unweld state, not on
    the physical actuation finishing first, so callers never await
    these directly. Implementations should still await their own
    hardware/action calls internally so failures get logged."""

    async def engage(self, object_type_cfg: Optional[dict], reference_size: float = 0.0):
        raise NotImplementedError

    async def disengage(self):
        raise NotImplementedError


class ParallelJawActuator(GraspActuator):
    """Parallel-jaw gripper via ParallelGripperCommand (same action
    GripperActionBackend drives). Sim doesn't need full mechanical
    contact, so engage() drives to a position scaled by the target
    object's size (from objects.yaml) rather than always fully
    closed — grip width roughly matches whatever's being picked with
    no per-object tuning required.

    Config keys (read from the tool's config dict):
      gripper_action_name    : ParallelGripperCommand action name
      gripper_joint_name     : primary gripper joint
      gripper_open_position, gripper_closed_position, gripper_max_effort,
      gripper_action_timeout : same meaning as before
      gripper_min_close_ratio: fraction of full travel used even for
                                the smallest catalog object (default
                                0.7), so the grip always looks
                                committed rather than barely closing
    """

    def __init__(self, node: Node, config: dict, logger):
        self._node = node
        self.logger = logger
        action_name = config.get(
            'gripper_action_name', '/gripper_action_controller/gripper_cmd')
        self._client = ActionClient(node, ParallelGripperCommand, action_name)
        self._joint_name = config.get(
            'gripper_joint_name', 'robotiq_85_left_knuckle_joint')
        self._open_pos = config.get('gripper_open_position', 0.001)
        self._closed_pos = config.get('gripper_closed_position', 0.554)
        self._max_effort = config.get('gripper_max_effort', 50.0)
        self._timeout = config.get('gripper_action_timeout', 5.0)
        self._min_close_ratio = config.get('gripper_min_close_ratio', 0.7)

    def _target_position(self, object_type_cfg: Optional[dict], reference_size: float) -> float:
        if not object_type_cfg or reference_size <= 0:
            return self._closed_pos
        size = (object_type_cfg.get('geometry', {}) or {}).get('size', [reference_size])
        ratio = min(1.0, max(size) / reference_size)
        scaled = self._min_close_ratio + (1.0 - self._min_close_ratio) * ratio
        return self._open_pos + (self._closed_pos - self._open_pos) * scaled

    async def engage(self, object_type_cfg: Optional[dict], reference_size: float = 0.0):
        await self._move(self._target_position(object_type_cfg, reference_size))

    async def disengage(self):
        await self._move(self._open_pos)

    async def _move(self, position: float):
        server_ready = await _wait_for_server_async(self._node, self._client, self._timeout)
        if not server_ready:
            self.logger.warn('[PARALLEL_JAW] gripper action server unavailable')
            return

        goal = ParallelGripperCommand.Goal()
        goal.command = JointState()
        goal.command.name = [self._joint_name]
        goal.command.position = [float(position)]
        goal.command.velocity = []
        goal.command.effort = [float(self._max_effort)] if self._max_effort else []

        send_future = self._client.send_goal_async(goal)
        try:
            goal_handle = await _future_with_timeout(self._node, send_future, self._timeout)
        except TimeoutError:
            self.logger.warn('[PARALLEL_JAW] goal-send timed out')
            return
        if not goal_handle.accepted:
            self.logger.warn('[PARALLEL_JAW] goal rejected')
            return

        result_future = goal_handle.get_result_async()
        try:
            await _future_with_timeout(self._node, result_future, self._timeout)
        except TimeoutError:
            self.logger.warn('[PARALLEL_JAW] result timed out (arm may still be moving)')


class SuctionActuator(GraspActuator):
    """Vacuum/suction gripper — binary on/off, no travel to scale, so
    object geometry is ignored entirely. Publishes to a std_msgs/String
    topic, matching RosTopicBackend's driver interface — the same
    hardware driver a standalone vacuum_X tool uses works here too.

    Config keys:
      vacuum_topic     : target topic (default '/vacuum_controller/cmd')
      vacuum_on_value  : string published on engage (default 'on')
      vacuum_off_value : string published on disengage (default 'off')
    """

    def __init__(self, node: Node, config: dict, logger):
        self.logger = logger
        self._topic = config.get('vacuum_topic', '/vacuum_controller/cmd')
        self._on_val = config.get('vacuum_on_value', 'on')
        self._off_val = config.get('vacuum_off_value', 'off')
        self._pub = node.create_publisher(String, self._topic, 10)

    async def engage(self, object_type_cfg: Optional[dict], reference_size: float = 0.0):
        # No geometry scaling needed — contact point is handled by
        # objects.yaml's approach_offset, same as the parallel-jaw path.
        msg = String()
        msg.data = str(self._on_val)
        self._pub.publish(msg)
        self.logger.info(f'[SUCTION] vacuum ON -> {self._topic}')

    async def disengage(self):
        msg = String()
        msg.data = str(self._off_val)
        self._pub.publish(msg)
        self.logger.info(f'[SUCTION] vacuum OFF -> {self._topic}')


_ACTUATOR_TYPES = {
    'parallel_jaw': ParallelJawActuator,
    'suction': SuctionActuator,
}


# ── Sim grasp/attach backend (GraspAttach.srv) ────────────

class GraspAttachBackend(ToolBackend):
    """
    Grasp/release backend for simulated picking. Calls the GraspAttach
    service to weld/un-weld a target object (child_model/child_link)
    to the gripper's parent_link, matching GraspAttach.srv exactly:

        request:  parent_model, parent_link, child_model, child_link,
                  attach, joint_id (only used when attach=false)
        response: success, message, joint_id

    Detach is by joint_id (returned from the prior attach call), not
    by name — so only one object can be held per backend instance at
    a time, and there's no ambiguity about which weld is being undone
    even with multiple/stacked objects in the scene.

    params IS float64[] (confirmed against the real ExecuteToolOp.action
    — the earlier JSON-string assumption here was wrong and has been
    corrected). Two ways to specify the attach target, so this works
    both with real vision and by hand:

    Command format:
      "attach" / "grip" / "close" with params=[x, y, z] or
                                   params=[x, y, z, max_distance]
        — vision-driven path: resolves the position to a live catalog
          instance via object_pose_resolver's /resolve_object_pose
          service. max_distance overrides the resolve_max_distance
          config default if provided as a 4th element.

      "attach:<child_model>" / "grip:<child_model>" (params ignored)
        — manual/primitive path: skips the resolver entirely, for
          hand-authored recipes or testing without vision running.

      "detach" / "release" / "open"  — detach the currently-held joint

    Config keys:
      service_name         : GraspAttach service name (default '/grasp_attach')
      parent_model          : model owning parent_link (default '')
      parent_link           : gripper link objects are welded to (default '<tool_id>_tcp')
      service_timeout       : seconds to wait for service up / response (default 5.0)
      pose_resolver_service : ResolveObjectPose service name (default '/resolve_object_pose')
      resolve_max_distance  : meters, default threshold for the vision-driven
                              path when params doesn't supply a 4th element (default 0.05)
      gripper_mechanism     : 'parallel_jaw' (default) or 'suction' — selects
                              which GraspActuator drives the physical gripper.
                              Remaining gripper_*/vacuum_* keys are passed
                              through to whichever actuator is selected; see
                              ParallelJawActuator / SuctionActuator docstrings.
      objects_catalog_path  : path to objects.yaml (default None — if unset,
                              ParallelJawActuator always closes fully, same
                              as before this option existed)

    REALISM + SCALABILITY: attach engages the gripper mechanism and
    opens/releases it on detach, but — since sim doesn't need real
    mechanical contact — actuation is fire-and-forget (see
    _fire_and_forget) rather than awaited: the weld/unweld call is
    what the pipeline actually waits on, so pick/place proceeds at
    weld-service speed, and the visible gripper motion just catches
    up in the background. This also means grip *mechanism* (parallel
    jaw, suction, ...) is entirely decoupled from the weld logic below
    via GraspActuator — swapping grippers is a config change, not a
    code change.
    """

    def __init__(self, tool_id: str, config: dict, logger, node: Node):
        super().__init__(tool_id, config, logger)
        self._node = node
        service_name = config.get('service_name', '/grasp_attach')
        self._client = node.create_client(GraspAttach, service_name)
        self._parent_model = config.get('parent_model', '')
        self._parent_link = config.get('parent_link', f'{tool_id}_tcp')
        self._timeout = config.get('service_timeout', 5.0)

        pose_resolver_service = config.get('pose_resolver_service', '/resolve_object_pose')
        self._resolver_client = node.create_client(ResolveObjectPose, pose_resolver_service)
        self._default_max_distance = float(config.get('resolve_max_distance', 0.05))

        # Object catalog (objects.yaml) — used by ParallelJawActuator to
        # scale grip closing by object size. Ignored by SuctionActuator.
        catalog_path = config.get('objects_catalog_path')
        self._object_types, self._reference_size = _load_object_catalog(catalog_path, logger)

        mechanism = config.get('gripper_mechanism', 'parallel_jaw')
        actuator_cls = _ACTUATOR_TYPES.get(mechanism)
        if actuator_cls is None:
            logger.error(
                f'[GRASP_ATTACH] {tool_id}: unknown gripper_mechanism '
                f'"{mechanism}", falling back to parallel_jaw. '
                f'Valid options: {list(_ACTUATOR_TYPES)}')
            actuator_cls = ParallelJawActuator
        self._actuator: GraspActuator = actuator_cls(node, config, logger)

        # Background engage/disengage tasks, kept only so they aren't
        # garbage-collected mid-flight — see _fire_and_forget.
        self._bg_tasks: set = set()

        # currently-held joint, if any (detach targets this specific joint_id)
        self._held_joint_id: Optional[int] = None
        self._held_child_desc: Optional[str] = None  # for logging only

    def _resolve_object_type_cfg(self, child_model: str) -> Optional[dict]:
        """child_model is an *instance* name like 'cube_small_3'
        (see objects.yaml's naming convention); strip the trailing
        '_<N>' to get the type_id and look it up in the loaded
        catalog. Returns None if there's no catalog loaded or the
        type isn't found — actuators fall back to their own defaults."""
        if not self._object_types:
            return None
        type_id = child_model.rsplit('_', 1)[0] if '_' in child_model else child_model
        return self._object_types.get(type_id)

    def _fire_and_forget(self, coro, label: str):
        """Schedule an actuator coroutine as a background task on the
        node's own executor — NOT asyncio.ensure_future, which needs a
        real asyncio event loop that doesn't exist here (see the
        module-level note on rclpy's coroutine-driven action callbacks
        near the top of this file). node.executor.create_task() uses
        rclpy's own Task/Future machinery, consistent with everything
        else in this file, so it works whether the node is spinning
        under a single- or multi-threaded executor."""
        task = self._node.executor.create_task(coro)
        self._bg_tasks.add(task)

        def _on_done(t):
            self._bg_tasks.discard(t)
            try:
                t.result()
            except Exception as e:
                self.logger.warn(f'[GRASP_ATTACH] {self.tool_id}: background {label} failed: {e}')

        task.add_done_callback(_on_done)

    async def _resolve(self, x: float, y: float, z: float, max_distance: float):
        """Call object_pose_resolver to turn a position into a
        (child_model, child_link), or return (None, None) on failure."""
        server_ready = await _wait_for_server_async(
            self._node, self._resolver_client, self._timeout)
        if not server_ready:
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: pose resolver service unavailable')
            return None, None

        req = ResolveObjectPose.Request()
        req.x = x
        req.y = y
        req.z = z
        req.max_distance = max_distance

        future = self._resolver_client.call_async(req)
        try:
            response = await _future_with_timeout(self._node, future, self._timeout)
        except TimeoutError:
            self.logger.warn(f'[GRASP_ATTACH] {self.tool_id}: pose resolve timed out')
            return None, None

        if not response.success:
            self.logger.warn(
                f'[GRASP_ATTACH] {self.tool_id}: pose resolve failed: {response.message}')
            return None, None

        return response.child_model, response.child_link

    async def execute(self, command: str, params: list = None) -> str:
        cmd = command.lower().strip()
        params = params or []

        if cmd in ('attach', 'grip', 'close') or cmd.startswith(('attach:', 'grip:')):
            if self._held_joint_id is not None:
                # Idempotency: a prior attempt may have succeeded but the
                # result was dropped at the DDS layer (rclpy "Ignoring
                # unexpected goal response"). The orchestrator retries;
                # without this we would fail the recipe even though the
                # object is already grasped.
                target_model = None
                if ':' in cmd:
                    target_model = command.split(':', 1)[1].strip()

                if target_model and self._held_child_desc == target_model:
                    self.logger.info(
                        f'[GRASP_ATTACH] {self.tool_id}: idempotent success — '
                        f'already holding {target_model}')
                    return 'closed_grasped'
                elif target_model and self._held_child_desc != target_model:
                    # Genuine error: recipe is trying to pick a *different*
                    # object without releasing first.
                    self.logger.warn(
                        f'[GRASP_ATTACH] {self.tool_id}: already holding '
                        f'"{self._held_child_desc}", cannot attach different '
                        f'object "{target_model}"')
                    return 'error_already_holding'
                else:
                    # No explicit target (close/grip/vision attach) — we
                    # cannot verify sameness without re-resolving, and the
                    # resolver may fail now that the object is already
                    # picked. Treat as idempotent success.
                    self.logger.info(
                        f'[GRASP_ATTACH] {self.tool_id}: idempotent success — '
                        f'already holding "{self._held_child_desc}"')
                    return 'closed_grasped'

            if ':' in cmd:
                # manual/primitive path — explicit child_model, resolver skipped
                child_model = command.split(':', 1)[1].strip()
                if not child_model:
                    self.logger.warn(
                        f'[GRASP_ATTACH] {self.tool_id}: "{command}" missing child_model')
                    return 'error_missing_target'
                child_link = ''  # bridge/GraspAttach side resolves link via catalog if needed
                return await self._call(attach=True, child_model=child_model,
                                         child_link=child_link)

            # vision-driven path — params must carry a position
            if len(params) < 3:
                self.logger.warn(
                    f'[GRASP_ATTACH] {self.tool_id}: attach requires params=[x,y,z'
                    f'(,max_distance)], got {params!r}')
                return 'error_missing_target'

            x, y, z = params[0], params[1], params[2]
            max_distance = float(params[3]) if len(params) >= 4 else self._default_max_distance

            child_model, child_link = await self._resolve(x, y, z, max_distance)
            if child_model is None:
                return 'error_resolve_failed'

            return await self._call(attach=True, child_model=child_model,
                                     child_link=child_link)

        elif cmd in ('detach', 'release', 'open'):
            if self._held_joint_id is None:
                self.logger.info(
                    f'[GRASP_ATTACH] {self.tool_id}: release with nothing held — no-op')
                return 'released_empty'
            return await self._call(attach=False, child_model='', child_link='')

        else:
            self.logger.warn(
                f'[GRASP_ATTACH] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_command_{cmd}'

    async def _call(self, attach: bool, child_model: str, child_link: str) -> str:
        if attach:
            # Engage fires in the background — the weld below is what
            # the pipeline actually waits on (see class docstring), so
            # pick proceeds at weld-service speed instead of gripper
            # travel speed. object_type_cfg scales a parallel-jaw's
            # closing distance to the target's size; SuctionActuator
            # ignores it entirely.
            object_type_cfg = self._resolve_object_type_cfg(child_model) if child_model else None
            self._fire_and_forget(
                self._actuator.engage(object_type_cfg, self._reference_size), 'engage')
            self.logger.info(
                f'[GRASP_ATTACH] {self.tool_id}: gripper engaging (bg) — welding now')

        server_ready = await _wait_for_server_async(
            self._node, self._client, self._timeout)
        if not server_ready:
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: GraspAttach service unavailable')
            if attach:
                self._fire_and_forget(self._actuator.disengage(), 'disengage')
            return 'error_no_server'

        req = GraspAttach.Request()
        req.parent_model = self._parent_model
        req.parent_link = self._parent_link
        req.child_model = child_model
        req.child_link = child_link
        req.attach = attach
        # "only used when attach=false" per GraspAttach.srv
        req.joint_id = self._held_joint_id if (not attach and self._held_joint_id is not None) else 0

        send_future = self._client.call_async(req)
        action = 'attach' if attach else 'detach'
        try:
            response = await _future_with_timeout(
                self._node, send_future, self._timeout)
        except TimeoutError:
            target = f'{child_model}/{child_link}' if attach else str(self._held_joint_id)
            self.logger.warn(
                f'[GRASP_ATTACH] {self.tool_id}: {action} ({target}) timed out')
            if attach:
                self._fire_and_forget(self._actuator.disengage(), 'disengage')
            return 'timeout'

        if not response.success:
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: {action} failed: {response.message}')
            if attach:
                self._fire_and_forget(self._actuator.disengage(), 'disengage')
            return 'error_service_failed'

        if attach:
            self._held_joint_id = response.joint_id
            self._held_child_desc = child_model or child_link
            self.logger.info(
                f'[GRASP_ATTACH] {self.tool_id}: attached "{self._held_child_desc}" '
                f'to {self._parent_link} (joint_id={self._held_joint_id})')
            return 'closed_grasped'
        else:
            self.logger.info(
                f'[GRASP_ATTACH] {self.tool_id}: detached joint {self._held_joint_id} '
                f'("{self._held_child_desc}")')
            self._held_joint_id = None
            self._held_child_desc = None

            # Unweld already happened above — object is physically free.
            # Disengage (open/vacuum-off) fires in the background so the
            # orchestrator can dispatch the next MoveStep immediately,
            # same as engage above.
            self._fire_and_forget(self._actuator.disengage(), 'disengage')
            return 'opened'

    def cleanup(self):
        if self._held_joint_id is not None:
            self.logger.warn(
                f'[GRASP_ATTACH] {self.tool_id}: shutting down while still '
                f'holding joint {self._held_joint_id} ("{self._held_child_desc}")')


# =========================================================
# TOOL MANAGER NODE
# =========================================================

class ToolActionServer(Node):
    """
    Hardware boundary node for end-effector tooling.

    Exposes ExecuteToolOp — goal/feedback/result — instead of the old
    /tool_command topic dispatch. Per-tool locks are preserved so one
    stalled tool never blocks a goal on another tool_id; different
    tool_ids' goals run concurrently on separate executor threads,
    same-tool_id goals serialize on that tool's lock exactly as before.
    """

    def __init__(self):
        super().__init__('tool_action_server')

        # ── Parameters ────────────────────────────────────────
        self.declare_parameter('tools', '{}')
        tools_json = self.get_parameter('tools').value

        # ── Backends ──────────────────────────────────────────
        self._backends: Dict[str, ToolBackend] = {}
        # _AsyncLock (not asyncio.Lock — see module note above) — needs
        # to be held across an `await` inside _execute_cb without
        # depending on a real asyncio event loop.
        self._action_locks: Dict[str, _AsyncLock] = {}
        self._action_locks_guard = threading.Lock()  # guards creation of per-tool locks (fast, non-blocking)

        self._load_backends(tools_json)

        # ── ExecuteToolOp action server ─────────────────────────
        self._cb_group = ReentrantCallbackGroup()
        self._server = ActionServer(
            self, ExecuteToolOp, 'execute_tool_op',
            execute_callback=self._execute_cb,
            goal_callback=self._goal_cb,
            cancel_callback=self._cancel_cb,
            callback_group=self._cb_group,
        )

        self.get_logger().info(
            f'Tool Action Server Ready  '
            f'({len(self._backends)} tool(s) loaded: '
            f'{list(self._backends.keys())})'
        )

    def _get_tool_lock(self, tool_id: str) -> _AsyncLock:
        with self._action_locks_guard:
            if tool_id not in self._action_locks:
                self._action_locks[tool_id] = _AsyncLock()
            return self._action_locks[tool_id]

    # =========================================================
    # BACKEND LOADING
    # =========================================================

    def _load_backends(self, tools_json: str):
        """
        Parse the tools JSON parameter and instantiate
        the correct backend for each tool.
        """
        try:
            tools_config: Dict[str, dict] = json.loads(tools_json)
        except json.JSONDecodeError as e:
            self.get_logger().error(f'Invalid tools JSON: {e}')
            return

        for tool_id, config in tools_config.items():
            backend_type = config.get('backend', 'mock').lower()
            try:
                backend = self._create_backend(tool_id, backend_type, config)
                self._backends[tool_id] = backend
                self.get_logger().info(
                    f'Tool loaded: {tool_id} [{backend_type}]')
            except Exception as e:
                self.get_logger().error(
                    f'Failed to load tool "{tool_id}" '
                    f'[{backend_type}]: {e}')

    def _create_backend(self, tool_id: str,
                         backend_type: str,
                         config: dict) -> ToolBackend:
        if backend_type == 'mock':
            return MockBackend(tool_id, config, self.get_logger())

        elif backend_type == 'gripper_action':
            return GripperActionBackend(tool_id, config, self.get_logger(), self)

        elif backend_type == 'gripper_position':
            return GripperPositionBackend(tool_id, config, self.get_logger(), self)

        elif backend_type == "gripper_effort":
            return GripperEffortBackend(tool_id, config, self.get_logger(), self)

        elif backend_type == 'digital_io':
            return DigitalIOBackend(tool_id, config, self.get_logger())

        elif backend_type == 'ros_topic':
            return RosTopicBackend(tool_id, config, self.get_logger(), self)

        elif backend_type == 'modbus':
            return ModbusBackend(tool_id, config, self.get_logger())

        elif backend_type == 'grasp_attach':
            return GraspAttachBackend(tool_id, config, self.get_logger(), self)

        else:
            raise ValueError(
                f'Unknown backend type: "{backend_type}". '
                f'Valid: mock, gripper_action, gripper_position, gripper_effort, '
                f'digital_io, ros_topic, modbus, grasp_attach'
            )

    # =========================================================
    # EXECUTE TOOL OP ACTION SERVER
    # =========================================================

    def _goal_cb(self, goal_request):
        if goal_request.tool_id not in self._backends:
            self.get_logger().warn(
                f'Unknown tool: "{goal_request.tool_id}"  '
                f'Available: {list(self._backends.keys())}')
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def _cancel_cb(self, goal_handle):
        return CancelResponse.ACCEPT

    async def _execute_cb(self, goal_handle):
        goal = goal_handle.request
        result = ExecuteToolOp.Result()
        backend = self._backends[goal.tool_id]
        lock = self._get_tool_lock(goal.tool_id)

        fb = ExecuteToolOp.Feedback()
        fb.status = 'MOVING'
        fb.percent_complete = 0.0
        goal_handle.publish_feedback(fb)

        # Same-tool_id goals still serialize here (_AsyncLock instead
        # of threading.Lock/asyncio.Lock — safe to hold across the
        # `await` below without parking a worker thread or depending
        # on a real asyncio event loop). Different tool_ids run
        # concurrently. Backends that implement execute() as a coroutine
        # (e.g. GripperActionBackend) are awaited directly — no thread
        # is blocked for the op's duration, so concurrent/retried goals
        # no longer compete for a fixed executor thread pool. Backends
        # with a plain synchronous execute() (mock, digital_io,
        # ros_topic, modbus — all fast, non-blocking calls) run as
        # before, unchanged.
        async with lock:
            try:
                sig = inspect.signature(backend.execute)
                accepts_params = len(sig.parameters) >= 2
                if asyncio.iscoroutinefunction(backend.execute):
                    if accepts_params:
                        status = await backend.execute(goal.command, goal.params)
                    else:
                        status = await backend.execute(goal.command)
                else:
                    if accepts_params:
                        status = backend.execute(goal.command, goal.params)
                    else:
                        status = backend.execute(goal.command)
            except Exception as e:
                self.get_logger().error(
                    f'Tool execution error [{goal.tool_id}:{goal.command}]: {e}')
                status = 'error'

        success, error_code = self._classify_status(status)
        result.success = success
        result.error_code = error_code
        result.final_state = status

        self.get_logger().info(f'Tool result → {goal.tool_id}:{status}')
        goal_handle.succeed() if success else goal_handle.abort()
        return result

    @staticmethod
    def _classify_status(status: str) -> tuple:
        """Backends return a free-form status string (unchanged from the
        original design) — classify it into ExecuteToolOp's success/
        error_code. Kept centralized here rather than changing every
        backend's return convention."""
        failure_prefixes = ('error', 'unknown', 'timeout', 'unhandled')
        if status == 'open_failed_stalled':
            return False, 10
        if any(status.startswith(p) for p in failure_prefixes):
            if status.startswith('unknown_tool'):
                return False, 1
            if status.startswith('unknown_command') or status.startswith('unknown_'):
                return False, 2
            if status == 'timeout':
                return False, 3
            return False, 4  # error_* / unhandled_*
        return True, 0

    # =========================================================
    # CLEANUP
    # =========================================================

    def destroy_node(self):
        for backend in self._backends.values():
            try:
                backend.cleanup()
            except Exception as e:
                self.get_logger().warn(f'Backend cleanup error: {e}')
        super().destroy_node()


# =========================================================
# MAIN
# =========================================================

def main(args=None):
    rclpy.init(args=args)
    node = ToolActionServer()
    # Explicit num_threads, not the bare MultiThreadedExecutor() default
    # (os.cpu_count() — this is the exact same class of bug already hit
    # for real in object_spawner.py on a 2-core i3: each tool gets its
    # own _AsyncLock so DIFFERENT tools are meant to run concurrently,
    # and MockBackend/DigitalIOBackend each briefly block a thread
    # (time.sleep for a sim delay / GPIO pulse) rather than yielding via
    # await. On a small core count those can't all get a thread at once
    # and a request just queues forever with no error. 8 matches the
    # value already settled on for orchestrator.py/object_spawner.py
    # this session.
    executor = MultiThreadedExecutor(num_threads=8)
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()