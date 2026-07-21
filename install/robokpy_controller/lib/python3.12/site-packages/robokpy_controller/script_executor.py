#!/usr/bin/env python3
"""
Motus — Industrial Cell Lifecycle Orchestrator Node

A generalized, non-blocking interface hub acting as the primary client to
the underlying motion planner and tool manager action server nodes. It contains 
no scenario-specific waypoint positions, serving purely as a reusable execution engine.
"""

import asyncio
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

# Import unified industrial action definitions
from robokpy_interfaces.action import RobotTrajectory, ToolExecution

class MotusScriptExecutor(Node):

    def __init__(self):
        super().__init__('motus_script_executor')
        
        # Instantiate dedicated ROS 2 action client interfaces
        self._planner_client = ActionClient(self, RobotTrajectory, 'plan_and_execute_trajectory')
        self._tool_client    = ActionClient(self, ToolExecution, 'execute_tool_action')
        
        self.get_logger().info("🏭 Motus Script Executor Framework Activated. Core APIs mapped.")

    async def execute_trajectory_async(self, label: str, joint_names: list, target_positions: list, duration: float = 2.0) -> bool:
        """
        Asynchronously packages and dispatches a target joint-space configuration
        to the planning server, yielding back control until completion.
        """
        if not self._planner_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(f"Execution failed for '{label}': Motion Planner Action Server offline!")
            return False

        # Package the standard robot trajectory goal payload
        goal_msg = RobotTrajectory.Goal()
        goal_msg.trajectory_mode = "blended"
        
        # Serialize trajectory metrics
        traj = JointTrajectory()
        traj.joint_names = joint_names
        
        point = JointTrajectoryPoint()
        point.positions = [float(q) for q in target_positions]
        point.time_from_start = rclpy.duration.Duration(seconds=duration).to_msg()
        traj.points.append(point)
        goal_msg.trajectory = traj

        self.get_logger().info(f"✈️ Dispatching path segment: '{label}'")
        goal_handle = await self._planner_client.send_goal_async(goal_msg)
        
        if not goal_handle.accepted:
            self.get_logger().error(f"Trajectory request '{label}' was REJECTED by the planning engine.")
            return False

        result = await goal_handle.get_result_async()
        return result.result.success

    async def execute_tool_async(self, tool_id: str, command: str, wait_duration: float) -> bool:
        """
        Asynchronously triggers a peripheral or CNC tool operation, tracking live
        percentage feedback states until the result status returns from the manager.
        """
        if not self._tool_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(f"Execution failed for '{tool_id}': Tool Manager Action Server offline!")
            return False

        # Package the standard tool execution goal payload
        goal_msg = ToolExecution.Goal()
        goal_msg.tool_id = tool_id
        goal_msg.command = command
        goal_msg.timeout_duration = wait_duration

        self.get_logger().info(f"🔧 Launching Tool → [{tool_id}] Command: '{command}' ({wait_duration}s)")
        goal_handle = await self._tool_client.send_goal_async(goal_msg)
        
        if not goal_handle.accepted:
            self.get_logger().error(f"Tool action request '{tool_id}:{command}' was REJECTED by the backend.")
            return False

        result = await goal_handle.get_result_async()
        return result.result.success
