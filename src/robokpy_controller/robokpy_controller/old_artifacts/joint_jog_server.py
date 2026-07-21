"""
joint_jog_server

Standalone node for direct, full manual joint control — calibration,
jogging, teaching, override. Deliberately NOT part of the orchestrator's
recipe DAG: no recipe step can ever reach this, by construction (steps.py
only has a pose-targeted move step; there is no path from a recipe into
this action).

Kept as a thin translator onto motion_planner's existing ExecuteMotion
action server rather than re-implementing trajectory generation or JTC
driving here — that means it automatically inherits motion_planner's
ACTIVE-mode guard, joint-limit checks, and JTC error handling for free,
and there's only one place that logic can ever drift out of sync.
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup

from robokpy_interfaces.action import SetJointTarget, ExecuteMotion


class JointJogServer(Node):
    def __init__(self):
        super().__init__('joint_jog_server')
        self._cb_group = ReentrantCallbackGroup()

        self._motion_client = ActionClient(
            self, ExecuteMotion, 'execute_motion', callback_group=self._cb_group)

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
            self.get_logger().error('set_joint_target: /execute_motion server not available')
            goal_handle.abort()
            result.success = False
            result.error_code = 1
            return result

        motion_goal = ExecuteMotion.Goal()
        motion_goal.step_id = 'manual_joint_jog'
        motion_goal.target_type = ExecuteMotion.Goal.JOINT_TARGET
        motion_goal.target_joints = goal.target_joints
        motion_goal.traj_method = 'js'
        motion_goal.traj_type = 'lspb'
        motion_goal.blend_radius = 0.0   # manual moves always come to a full, clean stop
        motion_goal.speed_scale = goal.speed_scale

        def feedback_cb(feedback_msg):
            fb = SetJointTarget.Feedback()
            fb.percent_complete = feedback_msg.feedback.percent_complete
            fb.current_state = feedback_msg.feedback.current_state
            goal_handle.publish_feedback(fb)

        send_future = self._motion_client.send_goal_async(motion_goal, feedback_callback=feedback_cb)
        motion_goal_handle = await send_future

        if not motion_goal_handle.accepted:
            # motion_planner rejects for two reasons: robot state not ready,
            # or system_mode != ACTIVE — either way, surface it plainly
            # rather than translating into a different error here.
            self.get_logger().error(
                'set_joint_target: /execute_motion rejected the goal — '
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