"""
GraspAttachBackend (v2) — ToolBackend for Motus's ToolManager.

Drives the gripper via control_msgs/action/ParallelGripperCommand
(same action interface as GripperActionBackend), and uses the
controller's own result.stalled field — driven by
allow_stalling/stall_velocity_threshold/stall_timeout in
controllers.yaml — as the grasp-detected signal, instead of manually
polling /joint_states. On a stalled close, calls the
robokpy_interfaces/srv/GraspAttach service to attach the object found
near parent_link (auto-detected by the GraspAttachPlugin). On open,
detaches first (if attached) then sends the open goal.

Also cancels the in-flight goal on client-side timeout so a jammed
gripper never leaves a dangling goal on the action server — combined
with ToolManager's per-tool locks, one stuck gripper no longer blocks
other tools OR leaves this tool itself wedged on the next command.

Config keys:
  action_name     : action server name
                     (default '/gripper_action_controller/gripper_cmd')
  joint_name      : primary joint name — must match the controller's
                     'joint' param in controllers.yaml
                     (default 'robotiq_85_left_knuckle_joint')
  parent_link     : URDF link name passed to GraspAttach as parent_link
                     (default 'robotiq_85_base_link' — CONFIRM against
                     your actual URDF)
  open_position   : target position for 'open'/'release' (default 0.001)
  closed_position : target position for 'close'/'grip'   (default 0.79)
  max_effort      : effort value forwarded in the goal (default 5.0,
                     matches controllers.yaml's max_effort — note this
                     is metadata only in sim since gz_ros2_control has
                     no effort command interface; real hardware uses it)
  action_timeout  : seconds to wait for the action result before
                     cancelling and reporting timeout (default 5.0)
  service_name    : GraspAttach service name (default '/motus/grasp_attach')
  service_timeout : seconds to wait for the service call result (default 2.0)
"""

import threading

from rclpy.action import ActionClient
from rclpy.node import Node
from sensor_msgs.msg import JointState
from control_msgs.action import ParallelGripperCommand

from robokpy_interfaces.srv import GraspAttach

from tool_manager import ToolBackend  # adjust import path to match your package layout


class GraspAttachBackend(ToolBackend):

    def __init__(self, tool_id: str, config: dict, logger, node: Node):
        super().__init__(tool_id, config, logger)
        self._node = node

        action_name = config.get(
            'action_name', '/gripper_action_controller/gripper_cmd')
        self._client = ActionClient(node, ParallelGripperCommand, action_name)

        self._joint_name = config.get(
            'joint_name', 'robotiq_85_left_knuckle_joint')
        self._parent_link = config.get(
            'parent_link', 'robotiq_85_base_link')
        self._open_pos = float(config.get('open_position', 0.001))
        self._closed_pos = float(config.get('closed_position', 0.79))
        self._max_effort = config.get('max_effort', 5.0)
        self._action_timeout = float(config.get('action_timeout', 5.0))

        self._service_name = config.get('service_name', '/motus/grasp_attach')
        self._service_timeout = float(config.get('service_timeout', 2.0))
        self._grasp_client = node.create_client(GraspAttach, self._service_name)

        # Persists across open/close so 'release' knows what to detach.
        self._attached_joint_id = 0

    # ---------------------------------------------------------------
    # GraspAttach service call (same bridging pattern as the action
    # calls below — background thread blocks on an Event set by the
    # service response callback running on the spin thread)
    # ---------------------------------------------------------------
    def _call_grasp_attach(self, attach: bool, joint_id: int = 0) -> GraspAttach.Response:
        if not self._grasp_client.wait_for_service(timeout_sec=self._service_timeout):
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: service '
                f'"{self._service_name}" unavailable')
            resp = GraspAttach.Response()
            resp.success = False
            resp.message = 'service_unavailable'
            return resp

        request = GraspAttach.Request()
        request.attach = attach
        request.parent_link = self._parent_link
        request.child_model = ''   # auto-detect
        request.child_link = ''    # auto-detect
        request.joint_id = joint_id

        done_event = threading.Event()
        result_holder = {}

        def on_response(future):
            try:
                result_holder['response'] = future.result()
            except Exception as e:  # noqa: BLE001
                result_holder['error'] = str(e)
            done_event.set()

        future = self._grasp_client.call_async(request)
        future.add_done_callback(on_response)

        if not done_event.wait(timeout=self._service_timeout):
            self.logger.warn(
                f'[GRASP_ATTACH] {self.tool_id}: service call timed out')
            resp = GraspAttach.Response()
            resp.success = False
            resp.message = 'service_timeout'
            return resp

        if 'error' in result_holder:
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: service error: '
                f'{result_holder["error"]}')
            resp = GraspAttach.Response()
            resp.success = False
            resp.message = result_holder['error']
            return resp

        return result_holder['response']

    # ---------------------------------------------------------------
    # Action call — cancels on timeout so the server never holds a
    # dangling goal after this call gives up on it.
    # ---------------------------------------------------------------
    def _send_gripper_goal(self, target_position: float):
        """
        Returns (reached_goal, stalled, position, error) — error is
        None on a normal completed call, or a short string tag
        ('no_server' / 'goal_rejected' / 'timeout') on failure.
        """
        if not self._client.wait_for_server(timeout_sec=self._action_timeout):
            return False, False, float('nan'), 'no_server'

        goal = ParallelGripperCommand.Goal()
        goal.command = JointState()
        goal.command.name = [self._joint_name]
        goal.command.position = [float(target_position)]
        goal.command.velocity = []
        goal.command.effort = (
            [float(self._max_effort)] if self._max_effort else []
        )

        done_event = threading.Event()
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

        if not done_event.wait(timeout=self._action_timeout):
            # Actively cancel so the server-side goal doesn't dangle —
            # this is the piece that was missing before and caused the
            # "stuck, unresponsive to any command" symptom.
            handle = goal_handle_holder.get('handle')
            if handle is not None:
                try:
                    handle.cancel_goal_async()
                    self.logger.warn(
                        f'[GRASP_ATTACH] {self.tool_id}: goal timed out — '
                        f'cancel requested')
                except Exception as e:  # noqa: BLE001
                    self.logger.error(
                        f'[GRASP_ATTACH] {self.tool_id}: cancel failed: {e}')
            return False, False, float('nan'), 'timeout'

        if 'error' in result_holder:
            return False, False, float('nan'), result_holder['error']

        result = result_holder['result']
        position = (
            result.state.position[0] if result.state.position else float('nan'))
        return result.reached_goal, result.stalled, position, None

    # ---------------------------------------------------------------
    # Main entrypoint (runs on ToolManager's background thread, under
    # this tool's own per-tool lock — see ToolManager patch)
    # ---------------------------------------------------------------
    def execute(self, command: str) -> str:
        cmd = command.lower().strip()

        if cmd in ('close', 'grip'):
            return self._do_close()
        elif cmd in ('open', 'release'):
            return self._do_open()
        else:
            self.logger.warn(
                f'[GRASP_ATTACH] {self.tool_id}: unknown command "{cmd}"')
            return f'unknown_command_{cmd}'

    def _do_close(self) -> str:
        reached_goal, stalled, position, error = self._send_gripper_goal(
            self._closed_pos)

        if error is not None:
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: close goal error: {error}')
            return f'error_{error}'

        self.logger.info(
            f'[GRASP_ATTACH] {self.tool_id}: close result '
            f'(reached_goal={reached_goal}, stalled={stalled}, '
            f'position={position:.4f})'
        )

        if not stalled:
            # Reached the fully-closed target without stalling — closed
            # on nothing, no object to attach.
            return 'closed_empty'

        resp = self._call_grasp_attach(attach=True)
        if resp.success:
            self._attached_joint_id = resp.joint_id
            self.logger.info(
                f'[GRASP_ATTACH] {self.tool_id}: grasp detected, attached '
                f'(joint_id={resp.joint_id})')
            return 'closed_grasped'

        self.logger.warn(
            f'[GRASP_ATTACH] {self.tool_id}: stall detected but attach '
            f'failed: {resp.message}')
        return 'closed_attach_failed'

    def _do_open(self) -> str:
        if self._attached_joint_id:
            resp = self._call_grasp_attach(
                attach=False, joint_id=self._attached_joint_id)
            if resp.success:
                self.logger.info(
                    f'[GRASP_ATTACH] {self.tool_id}: detached '
                    f'(joint_id={self._attached_joint_id})')
            else:
                self.logger.warn(
                    f'[GRASP_ATTACH] {self.tool_id}: detach failed: '
                    f'{resp.message}')
            self._attached_joint_id = 0

        _, _, _, error = self._send_gripper_goal(self._open_pos)
        if error is not None:
            self.logger.error(
                f'[GRASP_ATTACH] {self.tool_id}: open goal error: {error}')
            return f'error_{error}'

        return 'opened'