"""
trajectory_generator_node.py

ROS node exposing /plan_trajectory.
All heavy work is off-loaded to a ThreadPoolExecutor so the DDS spin
is never blocked.
"""

import asyncio
from concurrent.futures import ThreadPoolExecutor
from typing import Optional

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import Float64MultiArray
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration

from robokpy_interfaces.action import PlanTrajectory

from .planner_core import plan_trajectory, TrajectoryLeg, PlanningError
from .mp_kinematics import KinematicsFacade
from .mp_types import TrajectoryConfig


class TrajectoryGeneratorNode(Node):
    def __init__(self):
        super().__init__('trajectory_generator')

        # --- Parameters ---
        self.declare_parameter('robot_description', '')
        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link', 'tcp')
        self.declare_parameter('kinematic_solver_backend', 'robokpy')
        self.declare_parameter('mask', [0] * 6)
        self.declare_parameter('vel_limits', [1.5, 1.5, 2.0, 2.0, 2.5, 2.5])
        self.declare_parameter('acc_limits', [5.0, 5.0, 8.0, 8.0, 10.0, 10.0])
        self.declare_parameter('jerk_limits', [50.0, 50.0, 80.0, 80.0, 100.0, 100.0])
        self.declare_parameter('pos_limits_lo', [-3.14] * 6)
        self.declare_parameter('pos_limits_hi', [3.14] * 6)
        self.declare_parameter('cartesian_vel_limit', 0.25)
        self.declare_parameter('default_traj_method', 'js')
        self.declare_parameter('default_traj_type', 'lspb')
        self.declare_parameter('default_speed_factor', 1.0)
        self.declare_parameter('default_blend_radius', 0.0)
        self.declare_parameter('default_duration_per_segment', 3.0)
        self.declare_parameter('default_dt', 0.04)
        self.declare_parameter('default_n_samples', 50)
        self.declare_parameter('default_n_blend', 20)
        self.declare_parameter('home_pose', [0.0] * 6)
        self.declare_parameter('world_frame', 'world')

        # --- Validate robot_description ---
        robot_description = self.get_parameter('robot_description').value
        if not robot_description or not robot_description.strip():
            self.get_logger().error(
                'robot_description parameter is empty. '
                'This node must be launched with a URDF string. '
                'Use: ros2 launch robokpy_controller motus.launch.py '
                'or pass -p robot_description:=$(xacro ...)')
            raise RuntimeError(
                'robot_description is empty — cannot initialize kinematics. '
                'Run via launch file or pass the URDF parameter.')

        # --- Kinematics ---
        backend = self.get_parameter('kinematic_solver_backend').value
        self._kin = KinematicsFacade(
            robot_description=robot_description,
            base_link=self.get_parameter('planning_base_link').value,
            tip_link=self.get_parameter('planning_tip_link').value,
            backend=backend,
            mask=list(self.get_parameter('mask').value),
            logger=self.get_logger(),
        )
        self._config = TrajectoryConfig.from_node_params(self)
        self._world_frame = self.get_parameter('world_frame').value
        self._q_current: Optional[np.ndarray] = None

        # --- Thread pool for robokpy ---
        self._executor_pool = ThreadPoolExecutor(max_workers=2)

        # --- Subscriptions ---
        self.create_subscription(
            Float64MultiArray, '/current_joint_state',
            self._joint_cb, 10
        )

        # --- Action Server ---
        self._action_cb_group = ReentrantCallbackGroup()
        self._plan_server = ActionServer(
            self, PlanTrajectory, 'plan_trajectory',
            execute_callback=self._plan_cb,
            callback_group=self._action_cb_group,
        )

        self.get_logger().info('TrajectoryGenerator ready')

    # ------------------------------------------------------------------
    # Callbacks
    # ------------------------------------------------------------------
    def _joint_cb(self, msg: Float64MultiArray):
        self._q_current = np.array(msg.data)

    # ------------------------------------------------------------------
    # Action handler
    # ------------------------------------------------------------------
    async def _plan_cb(self, goal_handle):
        request = goal_handle.request
        result = PlanTrajectory.Result()

        # Resolve seed
        if request.seed_state:
            q_seed = np.array(request.seed_state, dtype=float)
        elif self._q_current is not None:
            q_seed = self._q_current.copy()
        else:
            goal_handle.abort()
            result.success = False
            result.error_code = 1
            return result

        q_seed = self._kin.normalize_joints(q_seed, self._kin.get_active_joints())

        # Build legs
        try:
            legs = []
            for i in range(len(request.leg_step_ids)):
                p = request.leg_target_poses[i]
                pose_arr = np.array([
                    p.position.x, p.position.y, p.position.z,
                    p.orientation.x, p.orientation.y,
                    p.orientation.z, p.orientation.w,
                ])
                legs.append(TrajectoryLeg(
                    step_id=request.leg_step_ids[i],
                    target_pose=pose_arr,
                    traj_method=request.leg_traj_methods[i] if i < len(request.leg_traj_methods) else 'ts',
                    traj_type=request.leg_traj_types[i] if i < len(request.leg_traj_types) else 'blend',
                    blend_radius=request.leg_blend_radii[i] if i < len(request.leg_blend_radii) else 0.0,
                ))
        except Exception as e:
            self.get_logger().error(f'Bad goal format: {e}')
            goal_handle.abort()
            result.success = False
            result.error_code = 1
            return result

        # Override config with goal-level overrides if present
        config = self._config
        if request.speed_scale > 0.0:
            config = TrajectoryConfig(
                traj_method=config.traj_method,
                traj_type=config.traj_type,
                blend_radius=config.blend_radius,
                n_blend=config.n_blend,
                duration_per_segment=config.duration_per_segment,
                dt=config.dt,
                speed_factor=request.speed_scale,
                n_samples=config.n_samples,
                vel_limits=config.vel_limits,
                acc_limits=config.acc_limits,
                jerk_limits=config.jerk_limits,
                pos_limits=config.pos_limits,
                cartesian_vel_limit=config.cartesian_vel_limit,
            )

        # Run planning in thread pool so DDS spin is never blocked.
        # _plan_cb is async, so there IS a running event loop here.
        # We grab it and submit the blocking work to the ThreadPoolExecutor.
        loop = asyncio.get_running_loop()
        try:
            planned = await loop.run_in_executor(
                self._executor_pool,
                plan_trajectory,
                legs,
                q_seed,
                config,
                self._kin,
            )
        except PlanningError as e:
            self.get_logger().error(f"Planning failed: {e}")
            goal_handle.abort()
            result.success = False
            result.error_code = e.error_code
            return result
        except Exception as e:
            self.get_logger().error(f"Unexpected planning error: {e}")
            goal_handle.abort()
            result.success = False
            result.error_code = 3
            return result

        # Convert to ROS message
        jtc_msg = JointTrajectory()
        jtc_msg.joint_names = self._kin.joint_names

        dt_default = config.dt
        for i, pt in enumerate(planned.points):
            jtp = JointTrajectoryPoint()
            if hasattr(pt, 'q') and hasattr(pt, 't'):  # TrajectoryPoint
                jtp.positions = pt.q.tolist()
                jtp.velocities = pt.qd.tolist() if pt.qd is not None else []
                jtp.accelerations = pt.qdd.tolist() if pt.qdd is not None else []
                t_sec = pt.t
            else:
                jtp.positions = np.asarray(pt).tolist()
                jtp.velocities = []
                jtp.accelerations = []
                t_sec = i * dt_default
            sec = int(t_sec)
            nanosec = int((t_sec - sec) * 1e9)
            jtp.time_from_start = Duration(sec=sec, nanosec=nanosec)
            jtc_msg.points.append(jtp)

        result.trajectory = jtc_msg
        result.success = True
        result.error_code = 0
        result.predicted_final_state = planned.predicted_q.tolist()
        result.total_duration = planned.total_duration

        goal_handle.succeed()
        self.get_logger().info(
            f"Planned {len(planned.points)} pts, {planned.total_duration:.2f}s "
            f"for legs {list(request.leg_step_ids)}"
        )
        return result

    def destroy_node(self):
        self._executor_pool.shutdown(wait=False)
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = TrajectoryGeneratorNode()
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
