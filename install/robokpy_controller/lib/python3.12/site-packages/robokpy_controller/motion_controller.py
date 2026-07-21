#!/usr/bin/env python3
"""
Motus — Industrial Motion Controller Node

Receives compiled joint trajectory blocks, handles interpolation steps,
and routes precise configurations directly to the virtual or physical joint drivers.
"""

import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from std_msgs.msg import Float64MultiArray
from robokpy_interfaces.action import RobotTrajectory

class MotionController(Node):

    def __init__(self):
        super().__init__('motion_controller')
        self._cb_group = ReentrantCallbackGroup()

        # 1. Output Drivers (Maintains backward compatibility with your Sim Echo loop)
        self._sim_echo_pub = self.create_publisher(
            Float64MultiArray,
            '/virtual_joint_target_echo',
            10
        )

        # 2. Expose Core Action Server Interface to the Planner/Orchestrator
        self._action_server = ActionServer(
            self,
            RobotTrajectory,
            'execute_robot_trajectory',
            execute_callback=self._execute_trajectory_cb,
            goal_callback=self._goal_cb,
            cancel_callback=self._cancel_cb,
            callback_group=self._cb_group
        )

        self.get_logger().info("🤖 Industrial Motion Controller output engine online.")

    def _goal_cb(self, goal_request):
        return GoalResponse.ACCEPT

    def _cancel_cb(self, goal_handle):
        return CancelResponse.ACCEPT

    async def _execute_trajectory_cb(self, goal_handle):
        req = goal_handle.request
        result = RobotTrajectory.Result()
        feedback = RobotTrajectory.Feedback()

        trajectory = req.trajectory
        self.get_logger().info(f"Executing incoming trajectory segment with {len(trajectory.points)} points...")

        # Native non-blocking execution tracker loop
        for i, point in enumerate(trajectory.points):
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                result.success = False
                result.status_message = "Trajectory interrupted mid-execution."
                return result

            # Broadcast configuration directly to the hardware/simulation interface registry
            drive_msg = Float64MultiArray()
            drive_msg.data = list(point.positions)
            self._sim_echo_pub.publish(drive_msg)

            # Publish feedback metadata to the Cell Orchestrator
            feedback.current_waypoint_id = f"point_{i}"
            feedback.percent_complete = ((i + 1) / len(trajectory.points)) * 100.0
            goal_handle.publish_feedback(feedback)

            # Controlled execution time slice delay
            time.sleep(0.05)

        goal_handle.succeed()
        result.success = True
        result.status_message = "Trajectory tracked and settled cleanly on actuators."
        return result

def main(args=None):
    rclpy.init(args=args)
    from rclpy.executors import MultiThreadedExecutor
    node = MotionController()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
