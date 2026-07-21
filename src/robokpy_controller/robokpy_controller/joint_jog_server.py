"""
joint_jog_server

Standalone node for direct, full manual joint control — calibration,
jogging, teaching, override. Deliberately NOT part of the orchestrator's
recipe DAG: no recipe step can ever reach this, by construction (steps.py
only has a pose-targeted move step; there is no path from a recipe into
this action).

Thin proxy onto motion_planner's own 'set_joint_target' action server
(same SetJointTarget interface on both sides) rather than re-implementing
trajectory generation or JTC driving here — motion_planner owns that
logic once, shared internally with its recipe-facing ExecuteMotion path,
so this node automatically inherits the ACTIVE-mode guard, joint-limit
checks, and JTC error handling for free, with nothing to drift out of
sync. This node exists as a separate process specifically so manual
control has its own independent, easily-validated entry point — and a
clean seam for adding jog-specific safety logic later (step-size limits,
an explicit confirm step, etc.) without touching motion_planner at all.
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup

from robokpy_interfaces.action import SetJointTarget


class JointJogServer(Node):
    def __init__(self):
        super().__init__('joint_jog_server')
        self._cb_group = ReentrantCallbackGroup()

        # Proxies directly to motion_planner's own set_joint_target action —
        # same message type on both sides, so this is a clean pass-through.
        self._motion_client = ActionClient(
            self, SetJointTarget, 'set_joint_target', callback_group=self._cb_group)

        self._server = ActionServer(
            self, SetJointTarget, 'set_joint_target',
            execute_callback=self._execute_cb,
            goal_callback=self._goal_cb,
            cancel_callback=self._cancel_cb,
            callback_group=self._cb_group,
        )

        self.get_logger().info('Joint Jog Server ready — manual joint control only, outside the recipe DAG')

    def _goal_cb(self, goal_request):
        return GoalResponse.ACCEPT

    def _cancel_cb(self, goal_handle):
        return CancelResponse.ACCEPT

    async def _execute_cb(self, goal_handle):
        goal = goal_handle.request
        result = SetJointTarget.Result()

        if not self._motion_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error('joint_jog_server: motion_planner/set_joint_target not available')
            goal_handle.abort()
            result.success = False
            result.error_code = 1
            return result

        def feedback_cb(feedback_msg):
            goal_handle.publish_feedback(feedback_msg.feedback)

        send_future = self._motion_client.send_goal_async(goal, feedback_callback=feedback_cb)
        motion_goal_handle = await send_future

        if not motion_goal_handle.accepted:
            # motion_planner rejects for two reasons: robot state not ready,
            # or system_mode != ACTIVE — surface it plainly rather than
            # translating into a different error here.
            self.get_logger().error(
                'joint_jog_server: motion_planner rejected the goal — '
                'check robot state is ready and system_mode is ACTIVE')
            goal_handle.abort()
            result.success = False
            result.error_code = 2
            return result

        if goal_handle.is_cancel_requested:
            await motion_goal_handle.cancel_goal_async()
            goal_handle.canceled()
            result.success = False
            result.error_code = 3
            return result

        motion_result = await motion_goal_handle.get_result_async()
        result.success = motion_result.result.success
        result.error_code = motion_result.result.error_code
        result.final_state = motion_result.result.final_state

        goal_handle.succeed() if result.success else goal_handle.abort()
        return result


def main(args=None):
    rclpy.init(args=args)
    node = JointJogServer()
    from rclpy.executors import MultiThreadedExecutor
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()