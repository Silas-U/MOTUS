"""
motion_planner.py  —  Thin ROS node (refactored)

Entry point for the robokpy_controller package. Delegates all business logic
to focused subsystems in mp_*.py.
"""

import threading
import numpy as np
from typing import Optional

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.qos import QoSProfile, DurabilityPolicy
from rclpy.task import Future

from std_msgs.msg import String, Float64MultiArray
from geometry_msgs.msg import Pose
from control_msgs.action import FollowJointTrajectory
from robokpy_interfaces.action import ExecuteMotion, SetJointTarget

from robokpy.pipeline import PipelineFactory

from .mp_types import TrajectoryConfig, CachedPlan, JointWaypoint, CartesianWaypoint
from .mp_kinematics import KinematicsFacade
from .mp_waypoints import WaypointManager
from .mp_trajectory import TrajectoryDispatcher, TrajectoryDispatchError
from .mp_cache import PlanCache
from .mp_jtc import JtcExecutor
from .mp_viz import VizPublisher


class MotionPlannerNode(Node):
    def __init__(self):
        super().__init__('motion_planner')

        # --- State ---
        self.q_current: Optional[np.ndarray] = None
        self.q_raw: Optional[np.ndarray] = None
        self.pose_current: Optional[np.ndarray] = None
        self.execution_state: Optional[str] = None
        self.active_mode_flag = False

        self._motion_busy = False
        self._motion_busy_lock = threading.Lock()

        # --- Parameters ---
        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link', 'tcp')
        self.declare_parameter('robot_description', '')
        self.declare_parameter('world_frame', 'world')
        self.declare_parameter('vel_limits', [1.5, 1.5, 2.0, 2.0, 2.5, 2.5])
        self.declare_parameter('acc_limits', [5.0, 5.0, 8.0, 8.0, 10.0, 10.0])
        self.declare_parameter('jerk_limits', [50.0, 50.0, 80.0, 80.0, 100.0, 100.0])
        self.declare_parameter('pos_limits_lo', [-3.14] * 6)
        self.declare_parameter('pos_limits_hi', [3.14] * 6)
        self.declare_parameter('cartesian_vel_limit', 0.25)
        self.declare_parameter('default_traj_type', 'lspb')
        self.declare_parameter('default_traj_method', 'js')
        self.declare_parameter('default_speed_factor', 1.0)
        self.declare_parameter('default_blend_radius', 0.0)
        self.declare_parameter('default_duration_per_segment', 3.0)
        self.declare_parameter('default_dt', 0.04)
        self.declare_parameter('default_n_samples', 50)
        self.declare_parameter('default_n_blend', 20)
        self.declare_parameter('publish_ee_path', False)
        self.declare_parameter('enable_limit_check', True)
        self.declare_parameter('enable_continuity_check', True)
        self.declare_parameter('abort_on_limit_violation', False)
        self.declare_parameter('home_pose', [0.0] * 6)
        self.declare_parameter('mask', [0] * 6)
        self.declare_parameter('kinematic_solver_backend', 'robokpy')
        self.declare_parameter('plan_cache_tolerance', 0.05)
        self.declare_parameter('plan_cache_ttl_sec', 30.0)
        self.declare_parameter('jtc_goal_response_timeout', 2.0)
        self.declare_parameter('jtc_result_timeout_margin', 10.0)
        self.declare_parameter('jtc_cooldown_sec', 0.0)

        # --- Kinematics ---
        backend = self.get_parameter('kinematic_solver_backend').value
        self._kin = KinematicsFacade(
            robot_description=self.get_parameter('robot_description').value,
            base_link=self.get_parameter('planning_base_link').value,
            tip_link=self.get_parameter('planning_tip_link').value,
            backend=backend,
            mask=list(self.get_parameter('mask').value),
            logger=self.get_logger(),
        )
        self.world_frame = self.get_parameter('world_frame').value
        self.home_q = np.array(self.get_parameter('home_pose').value)

        # --- Subsystems ---
        self._waypoint_mgr = WaypointManager(self.get_logger())
        self._viz = VizPublisher(self, self.world_frame)
        self._cache = PlanCache(
            tolerance=self.get_parameter('plan_cache_tolerance').value,
            ttl_sec=self.get_parameter('plan_cache_ttl_sec').value,
        )

        # Pipeline factory
        self._pipeline_factory = PipelineFactory()
        self._pipeline_factory.register_generator(
            'cartesian_line',
            lambda n_samples, **kw: __import__('robokpy.pipeline', fromlist=['CartesianLineGenerator']).CartesianLineGenerator(
                ik_fn=self._kin.solve_ik,
                base_link=self._kin.base_link,
                tip_link=self._kin.tip_link,
                n_samples=n_samples
            )
        )

        self._dispatcher = TrajectoryDispatcher(
            kinematics=self._kin,
            pipeline_factory=self._pipeline_factory,
            logger=self.get_logger(),
            default_n_samples=self.get_parameter('default_n_samples').value,
            default_n_blend=self.get_parameter('default_n_blend').value,
            default_dt=self.get_parameter('default_dt').value,
            enable_continuity_check=self.get_parameter('enable_continuity_check').value,
            abort_on_limit_violation=self.get_parameter('abort_on_limit_violation').value,
        )

        # JTC
        self._action_cb_group = ReentrantCallbackGroup()
        self._jtc_client = ActionClient(
            self, FollowJointTrajectory,
            '/arm_controller/follow_joint_trajectory',
            callback_group=self._action_cb_group,
        )
        self._jtc = JtcExecutor(
            node=self,
            client=self._jtc_client,
            logger=self.get_logger(),
            goal_response_timeout=self.get_parameter('jtc_goal_response_timeout').value,
            result_timeout_margin=self.get_parameter('jtc_result_timeout_margin').value,
            cooldown_sec=self.get_parameter('jtc_cooldown_sec').value,
        )

        # --- Action Servers ---
        self._execute_motion_server = ActionServer(
            self, ExecuteMotion, 'execute_motion',
            execute_callback=self._execute_motion_cb,
            goal_callback=self._execute_motion_goal_cb,
            cancel_callback=self._execute_motion_cancel_cb,
            callback_group=self._action_cb_group,
        )
        self._set_joint_target_server = ActionServer(
            self, SetJointTarget, 'set_joint_target',
            execute_callback=self._set_joint_target_cb,
            goal_callback=self._set_joint_target_goal_cb,
            cancel_callback=self._execute_motion_cancel_cb,
            callback_group=self._action_cb_group,
        )

        # --- Subscriptions ---
        self.create_subscription(Float64MultiArray, '/current_joint_state', self._joint_cb, 10)
        self.create_subscription(Float64MultiArray, '/joint_target_raw', self._raw_cb, 10)
        self.create_subscription(Pose, '/active_target_pose', self._pose_cb, 10)
        self.create_subscription(String, '/motion_command', self._cmd_cb, 10)
        self.create_subscription(String, '/execution_state', self._exec_state_cb, 10)
        self.create_subscription(String, '/system_mode', self._sys_mode_cb, 10)
        self.create_subscription(Pose, '/scripted_waypoint_pose', self._scripted_pose_cb, 10)
        self.create_subscription(Float64MultiArray, '/scripted_waypoint_joints', self._scripted_joints_cb, 10)

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL
        self.create_subscription(String, '/planning_tip_link', self._tip_link_cb, qos)

        # --- Publishers ---
        self._scripted_wp_status_pub = self.create_publisher(String, '/scripted_waypoint_status', 10)

        self.get_logger().info('Motion Planner Node Ready (refactored)')
        # Diagnostic: log actual loaded parameter values
        self.get_logger().info(
            f'[PARAM] duration_per_segment={self.get_parameter("default_duration_per_segment").value} '
            f'speed_factor={self.get_parameter("default_speed_factor").value} '
            f'dt={self.get_parameter("default_dt").value} '
            f'blend_radius={self.get_parameter("default_blend_radius").value} '
            f'n_blend={self.get_parameter("default_n_blend").value} '
            f'traj_method={self.get_parameter("default_traj_method").value} '
            f'traj_type={self.get_parameter("default_traj_type").value}')

    # =================================================================
    # Properties
    # =================================================================
    @property
    def _base_config(self) -> TrajectoryConfig:
        return TrajectoryConfig.from_node_params(self)

    def _pending_config(self) -> TrajectoryConfig:
        if not hasattr(self, '_pending_cfg'):
            self._pending_cfg = self._base_config
        return self._pending_cfg

    def _set_pending_config(self, cfg: TrajectoryConfig):
        self._pending_cfg = cfg

    # =================================================================
    # Subscriptions
    # =================================================================
    def _joint_cb(self, msg: Float64MultiArray):
        self.q_current = np.array(msg.data)

    def _raw_cb(self, msg: Float64MultiArray):
        self.q_raw = np.array(msg.data)

    def _pose_cb(self, msg: Pose):
        self.pose_current = np.array([
            msg.position.x, msg.position.y, msg.position.z,
            msg.orientation.x, msg.orientation.y,
            msg.orientation.z, msg.orientation.w,
        ])

    def _exec_state_cb(self, msg: String):
        self.execution_state = msg.data

    def _sys_mode_cb(self, msg: String):
        self.active_mode_flag = (msg.data == 'ACTIVE')

    def _tip_link_cb(self, msg: String):
        self._kin.set_tip_link(msg.data)
        self.get_logger().info(f'planning_tip_link updated -> {msg.data}')

    def _scripted_pose_cb(self, msg: Pose):
        pose = np.array([
            msg.position.x, msg.position.y, msg.position.z,
            msg.orientation.x, msg.orientation.y,
            msg.orientation.z, msg.orientation.w,
        ])
        self._add_waypoint_at_pose(pose)

    def _scripted_joints_cb(self, msg: Float64MultiArray):
        self._add_waypoint_at_joints(np.array(msg.data))

    # =================================================================
    # Command parsing
    # =================================================================
    def _cmd_cb(self, msg: String):
        cmd = msg.data.strip().lower()
        cfg = self._pending_config()

        if cmd == 'record_waypoint':
            self._record_waypoint()
        elif cmd == 'clear_waypoints':
            self._clear_waypoints()
        elif cmd.startswith('delete_waypoint:'):
            self._delete_waypoint(cmd.split(':', 1)[1].strip())
        elif cmd == 'list_waypoints':
            self.get_logger().info("\n" + self._waypoint_mgr.summary())
        elif cmd == 'stage_home_waypoint':
            self._add_waypoint_at_joints(self.home_q.copy())
        elif cmd == 'movel':
            cfg.traj_method = 'ts'
            cfg.traj_type = 'blend'
            self._set_pending_config(cfg)
        elif cmd == 'movej':
            cfg.traj_method = 'js'
            cfg.traj_type = 'lspb'
            self._set_pending_config(cfg)
        elif cmd.startswith('set_traj_type:'):
            cfg.traj_type = cmd.split(':', 1)[1].strip().lower()
            self._set_pending_config(cfg)
            self.get_logger().info(f'Pending traj type: {cfg.traj_type}')
        elif cmd.startswith('set_traj_method:'):
            cfg.traj_method = cmd.split(':', 1)[1].strip().lower()
            self._set_pending_config(cfg)
            self.get_logger().info(f'Pending traj method: {cfg.traj_method}')
        elif cmd.startswith('set_speed:'):
            try:
                cfg.speed_factor = float(np.clip(float(cmd.split(':', 1)[1]), 0.01, 1.0))
                self._set_pending_config(cfg)
                self.get_logger().info(f'Pending speed factor: {cfg.speed_factor:.2f}')
            except ValueError:
                self.get_logger().warn('set_speed: invalid value')
        elif cmd.startswith('set_blend:'):
            try:
                cfg.blend_radius = float(np.clip(float(cmd.split(':', 1)[1]), 0.0, 0.499))
                self._set_pending_config(cfg)
                self.get_logger().info(f'Pending blend radius: {cfg.blend_radius:.3f}')
            except ValueError:
                self.get_logger().warn('set_blend: invalid value')
        elif cmd.startswith('set_duration:'):
            try:
                cfg.duration_per_segment = max(float(cmd.split(':', 1)[1]), 0.05)
                self._set_pending_config(cfg)
                self.get_logger().info(f'Pending duration: {cfg.duration_per_segment:.2f} s')
            except ValueError:
                self.get_logger().warn('set_duration: invalid value')
        else:
            self.get_logger().warn(f'Unknown command: {msg.data}')

    # =================================================================
    # Waypoint helpers
    # =================================================================
    def _publish_wp_status(self, status: str):
        msg = String()
        msg.data = status
        self._scripted_wp_status_pub.publish(msg)

    def _record_waypoint(self):
        if not self._robot_state_ready():
            self.get_logger().warn('Robot state unavailable')
            return
        raw = self.q_current if self.active_mode_flag else self.q_raw
        q = self._kin.normalize_joints(raw.copy(), self._kin.get_active_joints())
        wp = JointWaypoint(q=q)
        wp_id = self._waypoint_mgr.add_with_config(wp, self._pending_config())
        self.get_logger().info(f'Recorded waypoint {wp_id}')
        self._viz.publish_waypoints(self._waypoint_mgr.waypoints)

    def _add_waypoint_at_pose(self, target_pose: np.ndarray) -> Optional[str]:
        if self._waypoint_mgr.waypoints:
            q_seed = self._waypoint_mgr.waypoints[-1].q.copy()
        else:
            raw = self.q_current if self.active_mode_flag else self.q_raw
            if raw is None:
                self.get_logger().warn('Robot state unavailable')
                self._publish_wp_status('failed:no_robot_state')
                return None
            q_seed = self._kin.normalize_joints(raw.copy(), self._kin.get_active_joints())

        q_target = self._kin.solve_ik(target_pose, q_seed)
        if q_target is None:
            self.get_logger().error(f'Scripted waypoint IK failed at {target_pose[:3]}')
            self._publish_wp_status('failed:ik')
            return None

        active = self._kin.get_active_joints()
        pos_limits = self._base_config.pos_limits
        q_target = self._kin.shortest_equivalent(q_target, q_seed, active, pos_limits)

        wp = JointWaypoint(q=q_target)
        wp_id = self._waypoint_mgr.add_with_config(wp, self._pending_config())
        self.get_logger().info(f'Scripted waypoint {wp_id} @ pose {target_pose[:3]}')
        self._publish_wp_status(f'success:{wp_id}')
        self._viz.publish_waypoints(self._waypoint_mgr.waypoints)
        return wp_id

    def _add_waypoint_at_joints(self, q_target: np.ndarray) -> str:
        wp = JointWaypoint(q=q_target)
        wp_id = self._waypoint_mgr.add_with_config(wp, self._pending_config())
        self.get_logger().info(f'Scripted waypoint {wp_id} @ joints')
        self._publish_wp_status(f'success:{wp_id}')
        self._viz.publish_waypoints(self._waypoint_mgr.waypoints)
        return wp_id

    def _delete_waypoint(self, wp_id: str):
        if self._waypoint_mgr.delete(wp_id):
            self._viz.publish_waypoints(self._waypoint_mgr.waypoints)

    def _clear_waypoints(self):
        self._waypoint_mgr.clear()
        self._viz.clear_waypoints()
        self.get_logger().info('Cleared waypoints + segments')

    # =================================================================
    # Action server callbacks
    # =================================================================
    def _execute_motion_goal_cb(self, goal_request):
        if not self._robot_state_ready():
            return rclpy.action.GoalResponse.REJECT
        if not self.active_mode_flag:
            self.get_logger().error('ExecuteMotion rejected — system_mode is not ACTIVE')
            return rclpy.action.GoalResponse.REJECT
        if len(goal_request.leg_step_ids) == 0:
            return rclpy.action.GoalResponse.REJECT
        if goal_request.plan_only:
            return rclpy.action.GoalResponse.ACCEPT
        with self._motion_busy_lock:
            if self._motion_busy:
                self.get_logger().error('ExecuteMotion rejected — motion already executing')
                return rclpy.action.GoalResponse.REJECT
            self._motion_busy = True
        return rclpy.action.GoalResponse.ACCEPT

    def _set_joint_target_goal_cb(self, goal_request):
        if not self._robot_state_ready():
            return rclpy.action.GoalResponse.REJECT
        if not self.active_mode_flag:
            self.get_logger().error('SetJointTarget rejected — system_mode is not ACTIVE')
            return rclpy.action.GoalResponse.REJECT
        with self._motion_busy_lock:
            if self._motion_busy:
                self.get_logger().error('SetJointTarget rejected — motion already executing')
                return rclpy.action.GoalResponse.REJECT
            self._motion_busy = True
        return rclpy.action.GoalResponse.ACCEPT

    def _execute_motion_cancel_cb(self, goal_handle):
        return rclpy.action.CancelResponse.ACCEPT

    # =================================================================
    # ExecuteMotion handler
    # =================================================================
    async def _execute_motion_cb(self, goal_handle):
        goal = goal_handle.request
        result = ExecuteMotion.Result()
        run_key = None
        prefetch_future = None

        try:
            # --- Seed ---
            if goal.seed_state.position:
                q_seed = self._kin.normalize_joints(
                    np.array(goal.seed_state.position),
                    self._kin.get_active_joints())
                seed_source = 'explicit seed_state'
            else:
                raw = self.q_current.copy() if self.active_mode_flag else self.q_raw.copy()
                q_seed = self._kin.normalize_joints(raw, self._kin.get_active_joints())
                seed_source = 'live robot state'
            q_seed_at_start = q_seed.copy()

            self.get_logger().info(
                f'execute_motion ({len(goal.leg_step_ids)} leg(s) {list(goal.leg_step_ids)}, '
                f'plan_only={goal.plan_only}): seeding from {seed_source}')

            # --- Cache key ---
            run_key = self._cache.make_key(goal)

            # --- Plan-only: start prefetch ---
            if goal.plan_only:
                prefetch_future = Future()
                self._cache.start_prefetch(run_key, prefetch_future)

            # --- Try cache ---
            cached_plan = None
            if not goal.plan_only:
                cached_plan = self._cache.get(run_key, q_seed)
                if cached_plan is None:
                    pending = self._cache.get_pending(run_key)
                    if pending is not None:
                        self.get_logger().info('Prefetch already computing — waiting')
                        try:
                            await self._await_future_with_timeout(pending, 20.0)
                        except TimeoutError:
                            self.get_logger().warn('Prefetch timeout — planning fresh')
                        cached_plan = self._cache.get(run_key, q_seed)

            # --- Dispatch ---
            if cached_plan is not None:
                self.get_logger().info('Reusing prefetched plan (drift OK)')
                traj_res = self._cached_plan_to_result(cached_plan)
            else:
                config = self._base_config
                try:
                    traj_res = self._dispatcher.dispatch(goal, q_seed, config)
                except TrajectoryDispatchError as e:
                    self.get_logger().warn(
                        f'{e.step_id}: dispatch failed (error_code={e.error_code})')
                    goal_handle.abort()
                    result.success = False
                    result.error_code = e.error_code
                    result.failed_leg_step_id = e.step_id
                    return result

            # --- Publish predicted feedback ---
            fb = ExecuteMotion.Feedback()
            fb.predicted_final_state.position = traj_res.predicted_q.tolist()
            goal_handle.publish_feedback(fb)

            # --- Plan-only: cache and return ---
            if goal.plan_only:
                cached = CachedPlan(
                    jtc_msg=traj_res.jtc_msg,
                    fk_path=traj_res.fk_path,
                    leg_time_ranges=traj_res.leg_time_ranges,
                    predicted_q=traj_res.predicted_q,
                    seed_q=q_seed_at_start,
                )
                self._cache.put(run_key, cached)
                result.success = True
                result.error_code = 0
                result.final_state.position = traj_res.predicted_q.tolist()
                result.actual_duration.sec = int(traj_res.total_duration)
                result.actual_duration.nanosec = int((traj_res.total_duration % 1.0) * 1e9)
                goal_handle.succeed()
                self.get_logger().info(
                    f'plan_only cached for {list(goal.leg_step_ids)} '
                    f'(duration={traj_res.total_duration:.2f}s)')
                if prefetch_future is not None and not prefetch_future.done():
                    prefetch_future.set_result(None)
                return result

            # --- Visualize ---
            if self.get_parameter('publish_ee_path').value:
                self._viz.clear_ee_path()
                self._viz.publish_ee_path(traj_res.fk_path, frame_id=self.world_frame)

            # --- Execute ---
            self.get_logger().info(
                f'Sending merged trajectory to JTC — '
                f'legs={list(goal.leg_step_ids)} n_points={len(traj_res.jtc_msg.points)} '
                f'total_duration={traj_res.total_duration:.2f}s')

            jtc_goal = FollowJointTrajectory.Goal()
            jtc_goal.trajectory = traj_res.jtc_msg
            last_known_leg = {'step_id': goal.leg_step_ids[0]}

            def feedback_cb(msg):
                actual = msg.feedback.actual
                actual_sec = actual.time_from_start.sec + actual.time_from_start.nanosec * 1e-9
                for step_id, t_start, t_end in traj_res.leg_time_ranges:
                    is_last = step_id == traj_res.leg_time_ranges[-1][0]
                    if actual_sec <= t_end or is_last:
                        leg_dur = t_end - t_start
                        leg_pct = min(1.0, max(0.0, (actual_sec - t_start) / leg_dur)) if leg_dur > 0 else 1.0
                        last_known_leg['step_id'] = step_id
                        fb = ExecuteMotion.Feedback()
                        fb.current_leg_step_id = step_id
                        fb.leg_percent_complete = leg_pct
                        fb.current_state.position = list(actual.positions)
                        goal_handle.publish_feedback(fb)
                        break

            jtc_res = await self._jtc.execute(
                jtc_goal=jtc_goal,
                feedback_callback=feedback_cb,
                trajectory_duration_sec=traj_res.total_duration,
                step_id_for_log=f'legs={list(goal.leg_step_ids)}',
                q_current_fn=lambda: self.q_current,
            )

            if goal_handle.is_cancel_requested and jtc_res.timed_out:
                goal_handle.canceled()
                result.success = False
                result.error_code = 7
                result.failed_leg_step_id = last_known_leg['step_id']
                return result

            result.success = jtc_res.success
            result.error_code = jtc_res.error_code
            if not jtc_res.success:
                result.failed_leg_step_id = last_known_leg['step_id']
            if jtc_res.actual_positions is not None:
                result.final_state.position = jtc_res.actual_positions
            if result.success:
                goal_handle.succeed()
            else:
                goal_handle.abort()
            return result

        finally:
            with self._motion_busy_lock:
                self._motion_busy = False
            if run_key is not None and prefetch_future is not None:
                self._cache.finish_prefetch(run_key)

    # =================================================================
    # SetJointTarget handler
    # =================================================================
    async def _set_joint_target_cb(self, goal_handle):
        goal = goal_handle.request
        result = SetJointTarget.Result()
        try:
            raw = self.q_current.copy() if self.active_mode_flag else self.q_raw.copy()
            q_seed = self._kin.normalize_joints(raw, self._kin.get_active_joints())
            config = self._base_config

            leg_res = self._dispatcher.generate_single_leg(
                q_seed, config, target_joints=list(goal.target_joints))

            if leg_res.error_code != 0:
                goal_handle.abort()
                result.success = False
                result.error_code = leg_res.error_code
                return result

            traj_res = self._dispatcher.package_result(
                leg_res.points, [('set_joint_target', 0.0, leg_res.points[-1].t if hasattr(leg_res.points[-1], 't') else 0.0)],
                leg_res.q_target, config.dt)

            if self.get_parameter('publish_ee_path').value:
                self._viz.clear_ee_path()
                self._viz.publish_ee_path(traj_res.fk_path, frame_id=self.world_frame)

            jtc_goal = FollowJointTrajectory.Goal()
            jtc_goal.trajectory = traj_res.jtc_msg
            total_sec = traj_res.total_duration

            def feedback_cb(msg):
                actual = msg.feedback.actual
                actual_sec = actual.time_from_start.sec + actual.time_from_start.nanosec * 1e-9
                fb = SetJointTarget.Feedback()
                fb.percent_complete = min(1.0, actual_sec / total_sec) if total_sec > 0 else 0.0
                fb.current_state.position = list(actual.positions)
                goal_handle.publish_feedback(fb)

            jtc_res = await self._jtc.execute(
                jtc_goal=jtc_goal,
                feedback_callback=feedback_cb,
                trajectory_duration_sec=total_sec,
                step_id_for_log='set_joint_target',
                q_current_fn=lambda: self.q_current,
            )

            if goal_handle.is_cancel_requested and jtc_res.timed_out:
                goal_handle.canceled()
                result.success = False
                result.error_code = 7
                return result

            result.success = jtc_res.success
            result.error_code = jtc_res.error_code
            if jtc_res.actual_positions is not None:
                result.final_state.position = jtc_res.actual_positions
            if result.success:
                goal_handle.succeed()
            else:
                goal_handle.abort()
            return result
        finally:
            with self._motion_busy_lock:
                self._motion_busy = False

    # =================================================================
    # Utilities
    # =================================================================
    def _robot_state_ready(self) -> bool:
        return self.q_current is not None and self.pose_current is not None

    def _cached_plan_to_result(self, plan: CachedPlan):
        from .mp_types import TrajectoryResult
        total_duration = plan.leg_time_ranges[-1][2] if plan.leg_time_ranges else 0.0
        return TrajectoryResult(
            points=[],
            leg_time_ranges=plan.leg_time_ranges,
            predicted_q=plan.predicted_q,
            jtc_msg=plan.jtc_msg,
            fk_path=plan.fk_path,
            total_duration=total_duration,
        )

    async def _await_future_with_timeout(self, future: Future, timeout_sec: float):
        """Await an rclpy.task.Future with a timeout, without relying on
        asyncio's event loop (rclpy coroutines aren't driven by one)."""
        if future.done():
            return future.result()

        timer = [None]

        def _cleanup():
            if timer[0] is not None:
                timer[0].cancel()
                timer[0].destroy()
                timer[0] = None

        def _on_timeout():
            if not future.done():
                future.set_exception(TimeoutError())
            _cleanup()

        timer[0] = self.create_timer(timeout_sec, _on_timeout)
        try:
            return await future
        finally:
            _cleanup()


def main():
    rclpy.init()
    node = MotionPlannerNode()
    executor = MultiThreadedExecutor(num_threads=8)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()