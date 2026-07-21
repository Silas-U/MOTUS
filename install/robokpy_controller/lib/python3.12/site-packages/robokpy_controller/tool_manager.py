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
from rclpy.action import ActionClient
from std_msgs.msg import String, Bool, Float64MultiArray
from control_msgs.action import ParallelGripperCommand
from sensor_msgs.msg import JointState

import json
import time
import threading
from typing import Optional, Dict, Any, Callable
import queue
from collections import deque
from robokpy_interfaces.srv import GraspAttach

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

    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        if cmd in ('open', 'release'):
            target, default_status = self._open_pos, 'opened'
        elif cmd in ('close', 'grip'):
            target, default_status = self._closed_pos, 'closed'
        else:
            self.logger.warn(
                f'[GRIPPER_ACTION] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_command_{cmd}'

        if not self._client.wait_for_server(timeout_sec=self._timeout):
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

        done_event    = threading.Event()
        result_holder = {}
        goal_handle_holder = {}

        def on_goal_response(future):
            goal_handle = future.result()
            goal_handle_holder['handle'] = goal_handle
            if not goal_handle.accepted:
                result_holder['error'] = 'goal_rejected'
                done_event.set()
                return
            result_future = goal_handle.get_result_async()
            result_future.add_done_callback(on_result)

        def on_result(future):
            result_holder['result'] = future.result().result
            done_event.set()

        send_future = self._client.send_goal_async(goal)
        send_future.add_done_callback(on_goal_response)

        if not done_event.wait(timeout=self._timeout):
            handle = goal_handle_holder.get('handle')
            if handle is not None:
                try:
                    handle.cancel_goal_async()
                    self.logger.warn(
                        f'[GRIPPER_ACTION] {self.tool_id}:{cmd} timed out — '
                        f'cancel requested')
                except Exception as e:
                    self.logger.error(
                        f'[GRIPPER_ACTION] {self.tool_id}: cancel failed: {e}')
            return 'timeout'

        if 'error' in result_holder:
            self.logger.error(
                f'[GRIPPER_ACTION] {self.tool_id}:{cmd} '
                f'{result_holder["error"]}')
            return result_holder['error']

        result = result_holder['result']
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


# =========================================================
# TOOL MANAGER NODE
# =========================================================

class ToolManager(Node):
    """
    Hardware boundary node for end-effector tooling.

    Receives /tool_command, routes to the correct backend,
    and publishes /tool_status with the result.

    Each tool action runs in a background thread so the
    ROS2 spin loop is never blocked by hardware delays.
    """

    def __init__(self):
        super().__init__('tool_manager')

        # ── Parameters ────────────────────────────────────────
        self.declare_parameter('tools', '{}')

        tools_json = self.get_parameter('tools').value

        # ── Backends ──────────────────────────────────────────
        self._backends: Dict[str, ToolBackend] = {}
        self._action_locks: Dict[str, threading.Lock] = {}
        self._action_locks_guard = threading.Lock()  # guards creation of per-tool locks


        self._load_backends(tools_json)

        # ── Subscribers ───────────────────────────────────────
        self.create_subscription(
            String,
            '/tool_command',
            self._tool_command_cb,
            10
        )

        # ── Publishers ────────────────────────────────────────
        self.status_pub = self.create_publisher(
            String, '/tool_status', 10)
        

        self._status_queue = queue.Queue()

        # Timer to drain the queue on the spin thread
        self.create_timer(0.02, self._drain_status_queue)

        self.get_logger().info(
            f'Tool Manager Ready  '
            f'({len(self._backends)} tool(s) loaded: '
            f'{list(self._backends.keys())})'
        )

    def _get_tool_lock(self, tool_id: str) -> threading.Lock:
        with self._action_locks_guard:
            if tool_id not in self._action_locks:
                self._action_locks[tool_id] = threading.Lock()
            return self._action_locks[tool_id]

    
    def _drain_status_queue(self):
        """Publish any pending status messages on the spin thread."""
        while not self._status_queue.empty():
            try:
                msg_data = self._status_queue.get_nowait()
                msg      = String()
                msg.data = msg_data
                self.status_pub.publish(msg)
                self.get_logger().info(f'Tool status → {msg_data}')
            except queue.Empty:
                break

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
        
        else:
            raise ValueError(
                f'Unknown backend type: "{backend_type}". '
                f'Valid: mock, gripper_action, gripper_position, grasp_attach'
                f'digital_io, ros_topic, modbus'
            )

    # =========================================================
    # COMMAND CALLBACK
    # =========================================================

    def _tool_command_cb(self, msg: String):
        """
        Parse incoming tool command and dispatch to the backend
        in a background thread so the spin loop is not blocked.

        Format: "<tool_id>:<command>"
        Example: "gripper_1:close"
        """
        raw = msg.data.strip()
        parts = raw.split(':', 1)

        if len(parts) != 2:
            self.get_logger().warn(
                f'Invalid tool command format: "{raw}"  '
                f'Expected "<tool_id>:<command>"')
            return

        tool_id, command = parts[0].strip(), parts[1].strip()

        if tool_id not in self._backends:
            self.get_logger().warn(
                f'Unknown tool: "{tool_id}"  '
                f'Available: {list(self._backends.keys())}')
            # Publish unknown status so controller doesn't hang
            self._publish_status(tool_id, 'unknown_tool')
            return

        # Dispatch to background thread — never block spin loop
        thread = threading.Thread(
            target=self._execute_in_thread,
            args=(tool_id, command),
            daemon=True
        )
        thread.start()


    def _execute_in_thread(self, tool_id: str, command: str):
        lock = self._get_tool_lock(tool_id)
        with lock:
            try:
                status = self._backends[tool_id].execute(command)
                self._publish_status(tool_id, status)
            except Exception as e:
                self.get_logger().error(
                    f'Tool execution error [{tool_id}:{command}]: {e}')
                self._publish_status(tool_id, 'error')


    def _publish_status(self, tool_id: str, status: str):
        """
        Publish tool status on /tool_status.
        Format: "<tool_id>:<status>"
        Example: "gripper_1:closed"
        """
        """Queue status for publishing on the spin thread."""
        self._status_queue.put(f'{tool_id}:{status}')

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
    node = ToolManager()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()