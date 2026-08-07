import rclpy
import threading
import time
from rclpy.node import Node

from std_msgs.msg import String, Float64MultiArray
from geometry_msgs.msg import Point, Pose
from visualization_msgs.msg import Marker
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
from rclpy.qos import QoSProfile
from rclpy.qos import DurabilityPolicy

import numpy as np
import copy
from dataclasses import dataclass, field
from typing import List, Optional

from robokpy import Init_Model
from robokpy import TrajectoryPoint, SegmentConfig

from rclpy.action import ActionServer, ActionClient, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.task import Future
from control_msgs.action import FollowJointTrajectory
from robokpy_interfaces.action import ExecuteMotion, SetJointTarget


# =========================================================
# ASYNC HELPERS
# =========================================================

def _future_with_timeout(node: Node, future, timeout_sec: float):
    """Arm `future` with a timeout."""
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


# =========================================================
# DATA STRUCTURES
# =========================================================

@dataclass
class Waypoint:
    id:   str
    pose: np.ndarray
    q:    np.ndarray


@dataclass
class MotionSegment:
    start_id:   str
    end_id:     str
    mode:       str           = 'js'
    config:     SegmentConfig = field(default_factory=SegmentConfig)
    cached:     bool          = False
    trajectory: Optional[List] = None

    def invalidate(self):
        self.cached     = False
        self.trajectory = None


# =========================================================
# MOTION PLANNER NODE
# =========================================================

class MotionPlanner(Node):

    def __init__(self):

        super().__init__('motion_planner')

        # =====================================================
        # Robot State
        # =====================================================
        self.q_current    = None
        self.q_raw        = None
        self.pose_current = None

        # =====================================================
        # Execution State
        # =====================================================
        self.execution_state  = None
        self.active_mode_flag = None
        self.command          = None

        self._motion_busy = False
        self._motion_busy_lock = threading.Lock()
        self._model_lock = threading.Lock()

        # Lookahead-plan cache — populated by plan_only ExecuteMotion
        # goals (see ExecuteMotion.action), consumed by the matching
        # real (plan_only=false) goal for the same leg_step_ids, so the
        # orchestrator can pre-plan the next run while the current one
        # is still physically executing. Keyed by tuple(leg_step_ids);
        # popped (not just read) on use so a stale entry can't outlive
        # a retry with the same ids. _plan_cache_tolerance bounds how
        # far live state may drift from a cached plan's assumed seed
        # before it's discarded in favor of a fresh replan (max-abs
        # joint delta, radians) — same order of magnitude as the
        # existing _verify_reached_target_async tolerance elsewhere in
        # this file.
        self._plan_cache: dict = {}
        self._plan_cache_lock = threading.Lock()
        self._plan_cache_tolerance = 0.05
        # Tracks a run_key's plan_only computation while it's still in
        # progress (Future, resolved when that computation finishes,
        # success or not) — see _execute_motion_cb: a real dispatch that
        # misses the cache checks here before starting its OWN fresh
        # plan, so a real dispatch arriving just slightly ahead of its
        # prefetch's completion waits on the ALREADY-RUNNING computation
        # instead of kicking off a duplicate one that would just fight
        # it for self._model_lock and make both slower than either
        # alone.
        self._plan_pending: dict = {}

        # ---- JTC action-client cooldown + tracking ----
        self._last_jtc_send_time = 0.0
        self._jtc_send_cooldown_sec = 0.0
        # Aggressively short: if the JTC server doesn't respond within
        # this window, the DDS response is lost. Don't wait 30s
        # hoping it shows up — it won't. Fall back to joint-state
        # polling immediately instead.
        self._jtc_goal_response_timeout = 2.0

        # =====================================================
        # Waypoints + Segments
        # =====================================================
        self.waypoints:       List[Waypoint]      = []
        self.motion_segments: List[MotionSegment] = []
        self.wp_counter = 0

        # =====================================================
        # Pending segment config
        # =====================================================
        self.pending_config = SegmentConfig()

        self.waypoint_point_indices: dict = {}

        # =====================================================
        # Action servers + JTC client
        # =====================================================
        self._action_cb_group = ReentrantCallbackGroup()
        self._jtc_client = ActionClient(
            self, FollowJointTrajectory,
            '/arm_controller/follow_joint_trajectory',
            callback_group=self._action_cb_group,
        )
        # Cache server availability so wait_for_server only blocks once.
        # Set to True after first successful connection; never reset to
        # False so subsequent dispatches skip the blocking check entirely.
        self._jtc_server_known_available = False
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

        # =====================================================
        # Parameters
        # =====================================================
        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link',  'tcp')

        self.declare_parameter('robot_description', '')
        self.declare_parameter('world_frame',        'world')

        self.declare_parameter('vel_limits',
                               [1.5, 1.5, 2.0, 2.0, 2.5, 2.5])
        self.declare_parameter('acc_limits',
                               [5.0, 5.0, 8.0, 8.0, 10.0, 10.0])
        self.declare_parameter('pos_limits_lo',
                               [-3.14, -3.14, -3.14, -3.14, -3.14, -3.14])
        self.declare_parameter('pos_limits_hi',
                               [ 3.14,  3.14,  3.14,  3.14,  3.14,  3.14])

        self.declare_parameter('default_traj_type',            'lspb')
        self.declare_parameter('default_traj_method',          'js')
        self.declare_parameter('default_speed_factor',         1.0)
        self.declare_parameter('default_blend_radius',         0.0)
        self.declare_parameter('default_duration_per_segment', 3.0)
        self.declare_parameter('default_dt',                   0.04)
        self.declare_parameter('default_n_samples',            50)
        self.declare_parameter('default_n_blend',              20)
        self.declare_parameter('publish_ee_path',              False)

        self.declare_parameter('enable_limit_check',       True)
        self.declare_parameter('enable_continuity_check',  True)
        self.declare_parameter('abort_on_limit_violation', False)

        robot_description = self.get_parameter('robot_description').value
        self.world_frame  = self.get_parameter('world_frame').value
        self.base_link = self.get_parameter('planning_base_link').value
        self.tip_link  = self.get_parameter('planning_tip_link').value

        self.declare_parameter('mask', [0]*6)
        self.mask = list(self.get_parameter('mask').value)

        # =====================================================
        # Robot Model
        # =====================================================

        self.model = Init_Model(robot_description, base_link=self.base_link, tip_link=self.tip_link)
        self.traj_planner = self.model.traj
        self.fk           = self.model.fk

        # =====================================================
        # Home Pose
        # =====================================================
        num_joints = self.model.model.get_num_act_joints_in_chain(self.base_link, self.tip_link)
        self.declare_parameter('home_pose', [0.0] * num_joints)
        self.home_q = np.array(self.get_parameter('home_pose').value)
        self.fk.compute_chain(self.home_q, self.base_link, self.tip_link)
        self.home_pose = self.fk.get_pose_quart()

        # =====================================================
        # Subscribers
        # =====================================================
        self.create_subscription(
            Float64MultiArray, '/current_joint_state', self.joint_cb, 10)
        self.create_subscription(
            Float64MultiArray, '/joint_target_raw',    self.raw_cb,   10)
        self.create_subscription(
            Pose,   '/active_target_pose', self.pose_cb,      10)
        self.create_subscription(
            String, '/motion_command',     self.cmd_cb,       10)
        self.create_subscription(
            String, '/execution_state',    self.exec_state_cb, 10)
        self.create_subscription(
            String, '/system_mode',        self.sys_mode_cb,  10)
        self.create_subscription(
            Pose, '/scripted_waypoint_pose', self.scripted_waypoint_pose_cb, 10)
        self.create_subscription(
            Float64MultiArray, '/scripted_waypoint_joints', self.scripted_waypoint_joints_cb, 10)

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL

        self.create_subscription(String, '/planning_tip_link', self.tip_link_cb, qos)

        # =====================================================
        # Publishers
        # =====================================================
        self.marker_pub  = self.create_publisher(
            Marker, '/trajectory_marker', 10)
        self.ee_path_pub = self.create_publisher(
            Marker, '/ee_trajectory_marker', 10)

        self.scripted_wp_status_pub = self.create_publisher(
            String, '/scripted_waypoint_status', 10)

        self.get_logger().info('Motion Planner Ready')

    # =========================================================
    # ASYNC SLEEP HELPER
    # =========================================================
    async def _sleep_async(self, duration_sec: float):
        """Non-blocking sleep usable inside async action callbacks."""
        if duration_sec <= 0.0:
            return
        from rclpy.task import Future
        future = Future()
        timer = [None]
        def _cb():
            if timer[0] is not None:
                timer[0].cancel()
                timer[0].destroy()
                timer[0] = None
            if not future.done():
                future.set_result(None)
        timer[0] = self.create_timer(duration_sec, _cb)
        await future

    # =========================================================
    # TRAJECTORY-EXECUTION VERIFICATION (recovery path)
    # =========================================================
    async def _verify_reached_target_async(self, target_positions,
                                            tolerance: float = 0.05,
                                            timeout_sec: float = 5.0) -> bool:
        """Return True if current joints are within tolerance of target."""
        target = np.array(target_positions)
        start = self.get_clock().now()
        while (self.get_clock().now() - start).nanoseconds / 1e9 < timeout_sec:
            if self.q_current is not None:
                error = float(np.max(np.abs(self.q_current - target)))
                if error < tolerance:
                    self.get_logger().info(
                        f'Verified arm reached target (max joint error '
                        f'{error:.4f} rad < {tolerance} rad)')
                    return True
            await self._sleep_async(0.1)
        return False

    # =========================================================
    # PARAMETER HELPERS
    # =========================================================

    def _get_limits(self):
        vel = np.array(self.get_parameter('vel_limits').value)
        acc = np.array(self.get_parameter('acc_limits').value)
        lo  = np.array(self.get_parameter('pos_limits_lo').value)
        hi  = np.array(self.get_parameter('pos_limits_hi').value)
        pos = np.column_stack([lo, hi])
        return vel, acc, pos

    def _make_default_config(self) -> SegmentConfig:
        return SegmentConfig(
            traj_method          = self.get_parameter('default_traj_method').value,
            traj_type            = self.get_parameter('default_traj_type').value,
            blend_radius         = self.get_parameter('default_blend_radius').value,
            n_blend              = self.get_parameter('default_n_blend').value,
            duration_per_segment = self.get_parameter('default_duration_per_segment').value,
            dt                   = self.get_parameter('default_dt').value,
            speed_factor         = self.get_parameter('default_speed_factor').value,
            n_samples            = self.get_parameter('default_n_samples').value,
        )

    # =========================================================
    # CALLBACKS
    # =========================================================

    def scripted_waypoint_pose_cb(self, msg: Pose):
        pose = np.array([
            msg.position.x, msg.position.y, msg.position.z,
            msg.orientation.x, msg.orientation.y,
            msg.orientation.z, msg.orientation.w
        ])
        self.add_waypoint_at_pose(pose)

    def scripted_waypoint_joints_cb(self, msg: Float64MultiArray):
        self.add_waypoint_at_joints(np.array(msg.data))

    def tip_link_cb(self, msg):
        with self._model_lock:
            self.tip_link = msg.data
            self.model.ik.tip_link = msg.data
        self.get_logger().info(f'planning_tip_link updated -> {msg.data}')

    def joint_cb(self, msg):
        self.q_current = np.array(msg.data)

    def raw_cb(self, msg):
        self.q_raw = np.array(msg.data)

    def pose_cb(self, msg):
        self.pose_current = np.array([
            msg.position.x, msg.position.y, msg.position.z,
            msg.orientation.x, msg.orientation.y,
            msg.orientation.z, msg.orientation.w
        ])

    def exec_state_cb(self, msg):
        self.execution_state = msg.data

    def sys_mode_cb(self, msg: String):
        if msg.data == 'PLANNER':
            self.active_mode_flag = False
        elif msg.data == 'ACTIVE':
            self.active_mode_flag = True

    def robot_state_ready(self) -> bool:
        return self.q_current is not None and self.pose_current is not None

    # =========================================================
    # COMMAND ROUTER
    # =========================================================

    def cmd_cb(self, msg):
        cmd = msg.data.strip()
        low = cmd.lower()
        self.command = low

        if low == 'record_waypoint':
            self.record_waypoint()
        elif low == 'clear_waypoints':
            self.clear_waypoints()
        elif low.startswith('delete_waypoint:'):
            self.delete_waypoint(cmd.split(':', 1)[1].strip())
        elif low == 'list_waypoints':
            self.list_waypoints()
        elif low == 'stage_home_waypoint':
            self.add_waypoint_at_joints(self.home_q.copy())
        elif low == 'movel':
            self.pending_config.traj_method = 'ts'
            self.pending_config.traj_type   = 'blend'
        elif low == 'movej':
            self.pending_config.traj_method = 'js'
            self.pending_config.traj_type   = 'lspb'
        elif low.startswith('set_traj_type:'):
            self.pending_config.traj_type = cmd.split(':', 1)[1].strip().lower()
            self.get_logger().info(f'Pending traj type: {self.pending_config.traj_type}')
        elif low.startswith('set_traj_method:'):
            self.pending_config.traj_method = cmd.split(':', 1)[1].strip().lower()
            self.get_logger().info(f'Pending traj method: {self.pending_config.traj_method}')
        elif low.startswith('set_speed:'):
            try:
                sf = float(cmd.split(':', 1)[1])
                self.pending_config.speed_factor = float(np.clip(sf, 0.01, 1.0))
                self.get_logger().info(f'Pending speed factor: {self.pending_config.speed_factor:.2f}')
            except ValueError:
                self.get_logger().warn('set_speed: invalid value')
        elif low.startswith('set_blend:'):
            try:
                br = float(cmd.split(':', 1)[1])
                self.pending_config.blend_radius = float(np.clip(br, 0.0, 0.499))
                self.get_logger().info(f'Pending blend radius: {self.pending_config.blend_radius:.3f}')
            except ValueError:
                self.get_logger().warn('set_blend: invalid value')
        elif low.startswith('set_duration:'):
            try:
                d = float(cmd.split(':', 1)[1])
                self.pending_config.duration_per_segment = max(d, 0.05)
                self.get_logger().info(
                    f'Pending duration: {self.pending_config.duration_per_segment:.2f} s')
            except ValueError:
                self.get_logger().warn('set_duration: invalid value')
        else:
            self.get_logger().warn(f'Unknown command: {cmd}')

    def _publish_wp_status(self, status: str):
        msg = String()
        msg.data = status
        self.scripted_wp_status_pub.publish(msg)

    # =========================================================
    # HELPERS
    # =========================================================
    def _append_waypoint(self, pose: np.ndarray, q: np.ndarray) -> str:
        wp_id = f'wp_{self.wp_counter:03d}'
        self.wp_counter += 1

        wp = Waypoint(id=wp_id, pose=pose.copy(), q=q.copy())
        self.waypoints.append(wp)

        if len(self.waypoints) > 1:
            prev_id = self.waypoints[-2].id
            seg = MotionSegment(
                start_id = prev_id,
                end_id   = wp_id,
                mode     = self.pending_config.traj_method,
                config   = copy.deepcopy(self.pending_config)
            )
            self.motion_segments.append(seg)
            c = seg.config
            self.get_logger().info(
                f'Segment: {prev_id} -> {wp_id}  '
                f'[{c.traj_method}/{c.traj_type}  '
                f'spd={c.speed_factor:.2f}  blend={c.blend_radius:.2f}]'
            )

        self.publish_waypoints()
        return wp_id

    def _get_wp(self, wp_id: str) -> Optional[Waypoint]:
        return next((wp for wp in self.waypoints if wp.id == wp_id), None)

    def list_waypoints(self):
        if not self.waypoints:
            self.get_logger().info('No waypoints recorded')
            return
        self.get_logger().info(f'--- Waypoints ({len(self.waypoints)}) ---')
        for wp in self.waypoints:
            self.get_logger().info(
                f'  {wp.id}  pos=[{wp.pose[0]:.3f}, '
                f'{wp.pose[1]:.3f}, {wp.pose[2]:.3f}]'
            )
        self.get_logger().info(f'--- Segments ({len(self.motion_segments)}) ---')
        for seg in self.motion_segments:
            c = seg.config
            cached_str = '[cached]' if seg.cached else ''
            self.get_logger().info(
                f'  {seg.start_id} -> {seg.end_id}  '
                f'[{c.traj_method}/{c.traj_type}  '
                f'spd={c.speed_factor:.2f}  '
                f'blend={c.blend_radius:.2f}] {cached_str}'
            )

    # =========================================================
    # WAYPOINT RECORDING
    # =========================================================

    def record_waypoint(self):
        if not self.robot_state_ready():
            self.get_logger().warn('Robot state unavailable')
            return
        wp_id = self._append_waypoint(self.pose_current, self.q_raw)
        self.get_logger().info(f'Recorded waypoint {wp_id}')

    def add_waypoint_at_pose(self, target_pose: np.ndarray) -> Optional[str]:
        if self.waypoints:
            q_seed = self.waypoints[-1].q.copy()
        else:
            raw = self.q_current if self.active_mode_flag else self.q_raw
            if raw is None:
                self.get_logger().warn('Robot state unavailable — no joint state received yet')
                self._publish_wp_status('failed:no_robot_state')
                return None
            q_seed = self._normalize_joints(raw.copy())

        with self._model_lock:
            q_target = self.model.ik.solve(target_pose, q0=q_seed, mask=self.mask)
            ik_failed = not self.model.ik.success

        if ik_failed:
            self.get_logger().error(f'Scripted waypoint IK failed at {target_pose[:3]} — not added')
            self._publish_wp_status('failed:ik')
            return None

        wp_id = self._append_waypoint(target_pose, q_target)
        self.get_logger().info(f'Scripted waypoint {wp_id} @ pose {target_pose[:3]}')
        self._publish_wp_status(f'success:{wp_id}')
        return wp_id

    def add_waypoint_at_joints(self, q_target: np.ndarray) -> str:
        with self._model_lock:
            self.fk.compute_chain(q_target, self.base_link, self.tip_link)
            pose = self.fk.get_pose_quart()
        wp_id = self._append_waypoint(pose, q_target)
        self.get_logger().info(f'Scripted waypoint {wp_id} @ joints')
        self._publish_wp_status(f'success:{wp_id}')
        return wp_id

    # =========================================================
    # WAYPOINT DELETION
    # =========================================================

    def delete_waypoint(self, wp_id: str):
        target = self._get_wp(wp_id)
        if target is None:
            self.get_logger().warn(f'Waypoint {wp_id} not found')
            return

        incoming = next(
            (s for s in self.motion_segments if s.end_id   == wp_id), None)
        outgoing = next(
            (s for s in self.motion_segments if s.start_id == wp_id), None)

        self.motion_segments = [
            s for s in self.motion_segments
            if s.start_id != wp_id and s.end_id != wp_id
        ]

        if incoming and outgoing:
            bridge = MotionSegment(
                start_id = incoming.start_id,
                end_id   = outgoing.end_id,
                mode     = outgoing.config.traj_method,
                config   = copy.deepcopy(outgoing.config)
            )
            self.motion_segments.append(bridge)
            self.get_logger().info(f'Bridged: {bridge.start_id} -> {bridge.end_id}')

        self.waypoints.remove(target)
        self.publish_waypoints()
        self.get_logger().info(f'Deleted waypoint {wp_id}')

    # =========================================================
    # JOINT NORMALIZATION
    # =========================================================

    def _normalize_joints(self, q: np.ndarray) -> np.ndarray:
        q_norm = q.copy()
        active = self.model.model.get_active_joints_in_chain(self.base_link, self.tip_link)
        for i, joint in enumerate(active):
            if joint['type'] in ('revolute', 'continuous'):
                q_norm[i] = (q[i] + np.pi) % (2 * np.pi) - np.pi
        return q_norm

    # =========================================================
    # SHARED TRAJECTORY GENERATION
    # =========================================================

    def _generate_leg(self, q_seed, traj_method, traj_type, blend_radius, speed_scale,
                       target_pose_arr=None, target_joints_arr=None):
        with self._model_lock:
            if traj_method == 'ts' and target_pose_arr is not None:
                self.fk.compute_chain(q_seed, self.base_link, self.tip_link)
                pose_start = self.fk.get_pose_quart()
            else:
                pose_start = None

            if target_joints_arr is not None:
                q_target = np.array(target_joints_arr)
                pose_target = None
            else:
                q_target = self.model.ik.solve(target_pose_arr, q0=q_seed, mask=self.mask)
                if not self.model.ik.success:
                    return None, None, 2
                if self.model.ik.limit_bound:
                    self.get_logger().warn(f'IK solution for leg is joint-limit-bound (pose={target_pose_arr[:3]})')
                    if self.get_parameter('abort_on_limit_violation').value:
                        return None, None, 4
                pose_target = target_pose_arr

            vel_limits, acc_limits, pos_limits = self._get_limits()
            traj = self.traj_planner.create_trajectory(
                waypoints=[
                    {'q': q_seed,   'pose': pose_start,  'mode': traj_method},
                    {'q': q_target, 'pose': pose_target, 'mode': traj_method},
                ],
                traj_method          = traj_method,
                traj_type            = traj_type,
                n_samples            = self.get_parameter('default_n_samples').value,
                blend_radius         = blend_radius,
                n_blend              = self.get_parameter('default_n_blend').value,
                duration_per_segment = self.get_parameter('default_duration_per_segment').value,
                dt                   = self.get_parameter('default_dt').value,
                speed_factor         = speed_scale,
                vel_limits           = vel_limits,
                acc_limits           = acc_limits,
            )
            if traj is None or len(traj) == 0:
                return None, None, 3

            timed = [pt for pt in traj if isinstance(pt, TrajectoryPoint)]
            if timed:
                if self.get_parameter('enable_continuity_check').value:
                    cont = self.traj_planner.validate_continuity(timed)
                    if not cont['c1_ok']:
                        self.get_logger().warn(f"velocity discontinuities at: {cont['c1_violations']}")
                    if not cont['c2_ok']:
                        self.get_logger().warn(f"acceleration discontinuities at: {cont['c2_violations']}")
                if self.get_parameter('enable_limit_check').value:
                    lim = self.traj_planner.check_joint_limits(timed, pos_limits, vel_limits, acc_limits)
                    if not lim['pos_limit_ok']:
                        msg_str = (f"position limit violations at: "
                                   f"{lim['pos_lo_violations'] + lim['pos_hi_violations']}")
                        if self.get_parameter('abort_on_limit_violation').value:
                            self.get_logger().error(f'ABORT — {msg_str}')
                            return None, None, 4
                        self.get_logger().warn(msg_str)
                    if not lim['vel_limit_ok']:
                        self.get_logger().warn(f"velocity limit violations at: {lim['vel_violations']}")

            return traj, q_target, 0

    def _points_to_jtc_msg(self, points, joint_names, dt_default, force_final_zero_velocity=True):
        jtc_msg = JointTrajectory()
        jtc_msg.joint_names = joint_names
        fk_path = []

        with self._model_lock:
            for i, pt in enumerate(points):
                jtp = JointTrajectoryPoint()
                if isinstance(pt, TrajectoryPoint):
                    jtp.positions     = pt.q.tolist()
                    jtp.velocities    = pt.qd.tolist()
                    jtp.accelerations = pt.qdd.tolist()
                    t_sec   = pt.t
                    q_forfk = pt.q
                else:
                    jtp.positions     = np.asarray(pt).tolist()
                    jtp.velocities    = []
                    jtp.accelerations = []
                    t_sec   = i * dt_default
                    q_forfk = np.asarray(pt)

                sec     = int(t_sec)
                nanosec = int((t_sec - sec) * 1e9)
                jtp.time_from_start = Duration(sec=sec, nanosec=nanosec)
                jtc_msg.points.append(jtp)

                self.fk.compute_chain(q_forfk, self.base_link, self.tip_link)
                fk_path.append(self.fk.get_xyz().copy())

        if force_final_zero_velocity and jtc_msg.points:
            last = jtc_msg.points[-1]
            last.velocities = [0.0] * len(last.positions)
            last.accelerations = [0.0] * len(last.positions)

        return jtc_msg, fk_path

    def _map_jtc_result(self, jtc_result, step_id_for_log: str) -> tuple:
        success = jtc_result.result.error_code == FollowJointTrajectory.Result.SUCCESSFUL
        if success:
            return True, 0
        self.get_logger().error(
            f'{step_id_for_log}: JTC execution failed, '
            f'jtc_error_code={jtc_result.result.error_code} '
            f'(see control_msgs/FollowJointTrajectory/Result for meaning)')
        return False, 9

    # =========================================================
    # JTC SEND HELPER (shared by both action servers)
    # =========================================================
    async def _send_jtc_goal(self, jtc_goal: FollowJointTrajectory.Goal,
                              feedback_callback,
                              step_id_for_log: str,
                              trajectory_duration_sec: float = 0.0):
        """Send a goal to the JTC with cooldown and lost-response recovery.

        Returns (jtc_goal_handle, timed_out) where timed_out is True if
        the goal response was lost but the arm may still be executing.
        """
        # ---- 1. Enforce cooldown since last JTC send -----------------
        now = self.get_clock().now().nanoseconds / 1e9
        elapsed = now - self._last_jtc_send_time
        if elapsed < self._jtc_send_cooldown_sec:
            cooldown = self._jtc_send_cooldown_sec - elapsed
            self.get_logger().debug(
                f'{step_id_for_log}: JTC cooldown {cooldown:.3f}s')
            await self._sleep_async(cooldown)

        self._last_jtc_send_time = self.get_clock().now().nanoseconds / 1e9

        # ---- 2. Wait for server --------------------------------------
        if not self._jtc_server_known_available:
            if not self._jtc_client.wait_for_server(timeout_sec=2.0):
                self.get_logger().error(f'{step_id_for_log}: JTC server not available')
                return None, False
            self._jtc_server_known_available = True

        # ---- 3. Send goal --------------------------------------------
        send_future = self._jtc_client.send_goal_async(
            jtc_goal, feedback_callback=feedback_callback)

        # ---- 4. Await goal response (generous timeout) ---------------
        try:
            jtc_goal_handle = await _future_with_timeout(
                self, send_future,
                timeout_sec=self._jtc_goal_response_timeout)
        except TimeoutError:
            self.get_logger().error(
                f'{step_id_for_log}: no goal-response from JTC within '
                f'{self._jtc_goal_response_timeout:.1f}s (possible dropped '
                f'DDS response). The arm may still be executing the trajectory.')
            return None, True

        if not jtc_goal_handle.accepted:
            self.get_logger().error(f'{step_id_for_log}: JTC rejected the goal')
            return None, False

        return jtc_goal_handle, False

    # =========================================================
    # EXECUTE MOTION ACTION SERVER
    # =========================================================

    def _execute_motion_goal_cb(self, goal_request):
        if not self.robot_state_ready():
            return GoalResponse.REJECT
        if not self.active_mode_flag:
            self.get_logger().error(
                'ExecuteMotion goal rejected — system_mode is not ACTIVE.')
            return GoalResponse.REJECT
        if len(goal_request.leg_step_ids) == 0:
            return GoalResponse.REJECT
        if goal_request.plan_only:
            # Pure computation — never touches JTC or the physical robot,
            # so it's safe (and the whole point) to run concurrently with
            # whatever real motion is currently executing. Deliberately
            # skips the _motion_busy gate below, which exists only to
            # keep two REAL trajectories from racing each other onto JTC.
            return GoalResponse.ACCEPT
        with self._motion_busy_lock:
            if self._motion_busy:
                self.get_logger().error(
                    'ExecuteMotion goal rejected — another motion is already executing.')
                return GoalResponse.REJECT
            self._motion_busy = True
        return GoalResponse.ACCEPT

    def _execute_motion_cancel_cb(self, goal_handle):
        return CancelResponse.ACCEPT

    def _finish_pending(self, run_key, pending_future):
        """Resolves + clears a plan_only goal's entry in _plan_pending —
        called at every exit point of a plan_only computation (success
        or failure) so a real dispatch waiting on it (see
        _execute_motion_cb) is released promptly instead of sitting out
        its full timeout. No-op if pending_future is None (i.e. this
        wasn't a plan_only goal to begin with)."""
        if pending_future is None:
            return
        with self._plan_cache_lock:
            self._plan_pending.pop(run_key, None)
        if not pending_future.done():
            pending_future.set_result(None)

    async def _execute_motion_cb(self, goal_handle):
        run_key = None
        pending_future = None
        try:
            goal = goal_handle.request
            result = ExecuteMotion.Result()
            n_legs = len(goal.leg_step_ids)
            run_key = tuple(goal.leg_step_ids)

            if goal.seed_state.position:
                # Explicit seed (lookahead prefetch, or a real dispatch
                # reusing one) — this run's actual start hasn't happened
                # yet, or (plan_only) never will physically happen, so
                # live robot state would just reflect whatever OTHER run
                # is currently executing. Use the predicted seed instead.
                q_seed = self._normalize_joints(np.array(goal.seed_state.position))
                seed_source = 'explicit seed_state'
            else:
                raw = self.q_current.copy() if self.active_mode_flag else self.q_raw.copy()
                q_seed = self._normalize_joints(raw)
                seed_source = 'live robot state'
            q_seed_at_start = q_seed.copy()
            self.get_logger().info(
                f'execute_motion ({n_legs} leg(s) {list(goal.leg_step_ids)}, '
                f'plan_only={goal.plan_only}): seeding from q_seed={q_seed.tolist()} '
                f'({seed_source})')

            # Registered BEFORE any IK/trajectory computation starts, so
            # a real dispatch for this exact run_key that arrives while
            # we're still computing can find us and wait instead of
            # racing us — see _plan_pending's docstring in __init__.
            pending_future = None
            if goal.plan_only:
                pending_future = Future()
                with self._plan_cache_lock:
                    self._plan_pending[run_key] = pending_future

            cached = None
            if not goal.plan_only:
                with self._plan_cache_lock:
                    cached = self._plan_cache.pop(run_key, None)
                    waiting_on = None if cached is not None else self._plan_pending.get(run_key)

                if cached is None and waiting_on is not None:
                    self.get_logger().info(
                        f'execute_motion: a prefetch for {list(goal.leg_step_ids)} '
                        f'is already computing — waiting on it instead of starting '
                        f'a duplicate plan that would just contend for the same '
                        f'model lock and slow both down')
                    try:
                        await _future_with_timeout(self, waiting_on, timeout_sec=20.0)
                    except TimeoutError:
                        self.get_logger().warn(
                            f'execute_motion: prefetch for {list(goal.leg_step_ids)} '
                            f'did not finish within 20s — planning fresh instead')
                    with self._plan_cache_lock:
                        cached = self._plan_cache.pop(run_key, None)

                if cached is not None:
                    drift = float(np.max(np.abs(q_seed_at_start - cached['seed_q'])))
                    if drift > self._plan_cache_tolerance:
                        self.get_logger().warn(
                            f'execute_motion: discarding prefetched plan for '
                            f'{list(goal.leg_step_ids)} — actual seed drifted '
                            f'{drift:.4f} rad from the seed it was planned '
                            f'against (tolerance {self._plan_cache_tolerance}); '
                            f'replanning fresh')
                        cached = None
                    else:
                        self.get_logger().info(
                            f'execute_motion: reusing prefetched plan for '
                            f'{list(goal.leg_step_ids)} (seed drift {drift:.4f} rad) '
                            f'— skipping IK/trajectory generation')

            if cached is not None:
                jtc_msg = cached['jtc_msg']
                fk_path = cached['fk_path']
                leg_time_ranges = cached['leg_time_ranges']
                predicted_q = cached['predicted_q']
                full_points = None  # not needed again — jtc_msg already built
            else:
                full_points = []
                leg_time_ranges = []
                t_offset = 0.0
                dt_default = self.get_parameter('default_dt').value

                for i in range(n_legs):
                    step_id = goal.leg_step_ids[i]
                    traj_method = goal.leg_traj_methods[i]
                    traj_type = goal.leg_traj_types[i]
                    blend_radius = goal.leg_blend_radii[i] if i < n_legs - 1 else 0.0

                    p = goal.leg_target_poses[i]
                    target_pose_arr = np.array([
                        p.position.x, p.position.y, p.position.z,
                        p.orientation.x, p.orientation.y, p.orientation.z, p.orientation.w,
                    ])

                    leg_points, q_target, err = self._generate_leg(
                        q_seed, traj_method, traj_type, blend_radius, goal.speed_scale,
                        target_pose_arr=target_pose_arr)

                    if err != 0:
                        self.get_logger().warn(f'{step_id}: leg generation failed (error_code={err})')
                        goal_handle.abort()
                        result.success = False
                        result.error_code = err
                        result.failed_leg_step_id = step_id
                        self._finish_pending(run_key, pending_future)
                        return result

                    # ---- FIX: velocity continuity across js <-> ts seams ----
                    # When adjacent legs use different traj_methods, the exit
                    # velocity of leg i-1 (joint-space) and the entry velocity
                    # of leg i (Cartesian-derived via IK Jacobian) can differ
                    # wildly. We enforce C1 continuity by overwriting the
                    # boundary point's velocity to the average of both sides.
                    # The JTC spline then sees a smooth knot instead of a kink.
                    # ---------------------------------------------------------
                    if i > 0 and goal.leg_traj_methods[i] != goal.leg_traj_methods[i - 1]:
                        if full_points and isinstance(full_points[-1], TrajectoryPoint) and \
                           isinstance(leg_points[0], TrajectoryPoint):
                            v_prev = np.array(full_points[-1].qd)
                            v_next = np.array(leg_points[0].qd)
                            v_blend = 0.5 * (v_prev + v_next)
                            full_points[-1].qd = v_blend
                            leg_points[0].qd = v_blend
                            self.get_logger().debug(
                                f'{step_id}: method change {goal.leg_traj_methods[i-1]}->'
                                f'{traj_method}, blended seam velocity '
                                f'(|v_prev-v_next|={float(np.linalg.norm(v_prev-v_next)):.3f})')

                    first_t = leg_points[0].t if isinstance(leg_points[0], TrajectoryPoint) else 0.0
                    last_t = leg_points[-1].t if isinstance(leg_points[-1], TrajectoryPoint) else (len(leg_points) - 1) * dt_default
                    leg_duration = last_t - first_t

                    points_to_add = leg_points if i == 0 else leg_points[1:]

                    t_start = t_offset
                    for pt in points_to_add:
                        if isinstance(pt, TrajectoryPoint):
                            pt.t = pt.t + t_offset
                        full_points.append(pt)

                    t_offset = t_start + leg_duration
                    leg_time_ranges.append((step_id, t_start, t_offset))

                    q_seed = q_target

                if not full_points:
                    goal_handle.abort()
                    result.success = False
                    result.error_code = 3
                    self._finish_pending(run_key, pending_future)
                    return result

                # Final leg's IK target — the robot's predicted resting
                # joint state once this whole run's trajectory completes.
                # Captured BEFORE any physical execution, so it's valid
                # whether or not this run ever actually runs (plan_only).
                predicted_q = q_seed

                joint_names = self.model.model.get_joint_names_in_chain(self.base_link, self.tip_link)
                jtc_msg, fk_path = self._points_to_jtc_msg(full_points, joint_names, dt_default)

            # Predicted-final-state feedback — published once per goal,
            # right after a trajectory becomes available (fresh or a
            # prefetch-cache hit), before any physical execution. Lets
            # the orchestrator start lookahead-planning the NEXT run
            # immediately instead of waiting for this run's physical
            # completion (or, for plan_only, for nothing to ever
            # physically happen at all).
            predicted_fb = ExecuteMotion.Feedback()
            predicted_fb.predicted_final_state.position = predicted_q.tolist()
            goal_handle.publish_feedback(predicted_fb)

            if goal.plan_only:
                with self._plan_cache_lock:
                    self._plan_cache[run_key] = {
                        'jtc_msg': jtc_msg,
                        'fk_path': fk_path,
                        'leg_time_ranges': leg_time_ranges,
                        'predicted_q': predicted_q,
                        'seed_q': q_seed_at_start,
                    }
                total_duration = leg_time_ranges[-1][2]
                result.success = True
                result.error_code = 0
                result.final_state.position = predicted_q.tolist()
                result.actual_duration.sec = int(total_duration)
                result.actual_duration.nanosec = int((total_duration % 1.0) * 1e9)
                goal_handle.succeed()
                self.get_logger().info(
                    f'execute_motion: plan_only cached for {list(goal.leg_step_ids)} '
                    f'(predicted_final={predicted_q.tolist()}, duration={total_duration:.2f}s)')
                self._finish_pending(run_key, pending_future)
                return result

            if self.get_parameter('publish_ee_path').value:
                self.clear_ee_path()
                self.ee_path_pub.publish(self.create_ee_dotted_path(fk_path, frame_id=self.world_frame))

            self.get_logger().info(
                f'execute_motion: sending merged trajectory to JTC — '
                f'legs={list(goal.leg_step_ids)} n_points={len(jtc_msg.points)} '
                f'total_duration={leg_time_ranges[-1][2]:.2f}s')

            jtc_goal = FollowJointTrajectory.Goal()
            jtc_goal.trajectory = jtc_msg

            last_known_leg = {'step_id': goal.leg_step_ids[0]}

            def jtc_feedback_cb(jtc_feedback_msg):
                actual = jtc_feedback_msg.feedback.actual
                actual_sec = actual.time_from_start.sec + actual.time_from_start.nanosec * 1e-9
                for step_id, t_start, t_end in leg_time_ranges:
                    is_last_leg = step_id == leg_time_ranges[-1][0]
                    if actual_sec <= t_end or is_last_leg:
                        leg_dur = t_end - t_start
                        leg_pct = min(1.0, max(0.0, (actual_sec - t_start) / leg_dur)) if leg_dur > 0 else 1.0
                        last_known_leg['step_id'] = step_id
                        fb = ExecuteMotion.Feedback()
                        fb.current_leg_step_id = step_id
                        fb.leg_percent_complete = leg_pct
                        fb.current_state.position = list(actual.positions)
                        goal_handle.publish_feedback(fb)
                        break

            total_sec = leg_time_ranges[-1][2]
            jtc_goal_handle, timed_out = await self._send_jtc_goal(
                jtc_goal, jtc_feedback_cb,
                step_id_for_log=f'legs={list(goal.leg_step_ids)}',
                trajectory_duration_sec=total_sec)

            if timed_out:
                # Goal response lost in DDS — but the arm_controller may
                # still have received and be executing the trajectory.
                # Poll joint states aggressively instead of blind-waiting.
                final_positions = np.array(jtc_msg.points[-1].positions)
                poll_deadline = time.monotonic() + total_sec + 5.0
                poll_interval = 0.2
                reached = False
                while time.monotonic() < poll_deadline:
                    if self.q_current is not None:
                        err = float(np.max(np.abs(self.q_current - final_positions)))
                        if err < 0.05:
                            reached = True
                            break
                    await self._sleep_async(poll_interval)

                if reached:
                    self.get_logger().warn(
                        f'legs={list(goal.leg_step_ids)}: arm reached target '
                        f'despite lost goal response — treating as success')
                    result.success = True
                    result.error_code = 0
                    goal_handle.succeed()
                    return result
                else:
                    self.get_logger().error(
                        f'legs={list(goal.leg_step_ids)}: arm did NOT reach '
                        f'target after lost goal response — failing step')
                    goal_handle.abort()
                    result.success = False
                    result.error_code = 10
                    result.failed_leg_step_id = last_known_leg['step_id']
                    return result

            if jtc_goal_handle is None:
                goal_handle.abort()
                result.success = False
                result.error_code = 6
                result.failed_leg_step_id = last_known_leg['step_id']
                return result

            if goal_handle.is_cancel_requested:
                await jtc_goal_handle.cancel_goal_async()
                goal_handle.canceled()
                result.success = False
                result.error_code = 7
                result.failed_leg_step_id = last_known_leg['step_id']
                return result

            result_timeout = leg_time_ranges[-1][2] + 10.0
            result_wrapper = Future()
            result_timer = [None]

            def _cleanup_result_timer():
                t = result_timer[0]
                if t is not None:
                    result_timer[0] = None
                    try:
                        t.cancel()
                    except Exception:
                        pass
                    try:
                        t.destroy()
                    except Exception:
                        pass

            def _on_result_done(f):
                _cleanup_result_timer()
                if result_wrapper.done():
                    return
                try:
                    result_wrapper.set_result(('ok', f.result()))
                except Exception as e:
                    result_wrapper.set_result(('error', e))

            def _on_result_timeout():
                _cleanup_result_timer()
                if not result_wrapper.done():
                    result_wrapper.set_result(('timeout', None))

            result_future = jtc_goal_handle.get_result_async()
            result_future.add_done_callback(_on_result_done)
            result_timer[0] = self.create_timer(result_timeout, _on_result_timeout)

            res_status, res_value = await result_wrapper

            if res_status == 'timeout':
                self.get_logger().error(
                    f'legs={list(goal.leg_step_ids)}: no result from JTC within '
                    f'{result_timeout:.1f}s — attempting to cancel, trajectory '
                    f'may still be running')
                try:
                    cancel_future = jtc_goal_handle.cancel_goal_async()
                    cancel_wrapper = Future()
                    cancel_timer = [None]

                    def _cleanup_cancel_timer():
                        t = cancel_timer[0]
                        if t is not None:
                            cancel_timer[0] = None
                            try:
                                t.cancel()
                            except Exception:
                                pass
                            try:
                                t.destroy()
                            except Exception:
                                pass

                    def _on_cancel_done(f):
                        _cleanup_cancel_timer()
                        if cancel_wrapper.done():
                            return
                        try:
                            cancel_wrapper.set_result(f.result())
                        except Exception as e:
                            cancel_wrapper.set_result(e)

                    def _on_cancel_timeout():
                        _cleanup_cancel_timer()
                        if not cancel_wrapper.done():
                            cancel_wrapper.set_result(None)

                    cancel_future.add_done_callback(_on_cancel_done)
                    cancel_timer[0] = self.create_timer(5.0, _on_cancel_timeout)
                    await cancel_wrapper
                    self.get_logger().info(
                        f'legs={list(goal.leg_step_ids)}: cancel request sent')
                except Exception:
                    self.get_logger().error(
                        f'legs={list(goal.leg_step_ids)}: cancel request failed '
                        f'— arm state unknown, operator must verify manually')
                goal_handle.abort()
                result.success = False
                result.error_code = 11
                result.failed_leg_step_id = last_known_leg['step_id']
                return result

            if res_status == 'error':
                self.get_logger().error(
                    f'legs={list(goal.leg_step_ids)}: get_result_async failed: '
                    f'{res_value}')
                goal_handle.abort()
                result.success = False
                result.error_code = 11
                result.failed_leg_step_id = last_known_leg['step_id']
                return result

            jtc_result = res_value

            result.success, result.error_code = self._map_jtc_result(jtc_result, f'legs={list(goal.leg_step_ids)}')
            if not result.success:
                result.failed_leg_step_id = last_known_leg['step_id']
            if hasattr(jtc_result.result, 'actual'):
                result.final_state.position = list(jtc_result.result.actual.positions)

            goal_handle.succeed() if result.success else goal_handle.abort()
            return result
        finally:
            # Release busy flag immediately so the next goal can be
            # accepted without waiting for post-processing/logging.
            with self._motion_busy_lock:
                self._motion_busy = False
            # Safety net: every normal exit above already resolves a
            # plan_only goal's pending_future via _finish_pending. This
            # only fires if something raised before/without reaching one
            # of those (an unexpected exception) — otherwise it's a
            # harmless no-op (pending_future already popped and done()).
            self._finish_pending(run_key, pending_future)

    # =========================================================
    # SET JOINT TARGET ACTION SERVER
    # =========================================================

    def _set_joint_target_goal_cb(self, goal_request):
        if not self.robot_state_ready():
            return GoalResponse.REJECT
        if not self.active_mode_flag:
            self.get_logger().error(
                'SetJointTarget goal rejected — system_mode is not ACTIVE.')
            return GoalResponse.REJECT
        with self._motion_busy_lock:
            if self._motion_busy:
                self.get_logger().error(
                    'SetJointTarget goal rejected — another motion is already executing.')
                return GoalResponse.REJECT
            self._motion_busy = True
        return GoalResponse.ACCEPT

    async def _set_joint_target_cb(self, goal_handle):
        try:
            goal = goal_handle.request
            result = SetJointTarget.Result()

            raw = self.q_current.copy() if self.active_mode_flag else self.q_raw.copy()
            q_seed = self._normalize_joints(raw)

            points, q_target, err = self._generate_leg(
                q_seed, traj_method='js', traj_type='lspb', blend_radius=0.0,
                speed_scale=goal.speed_scale, target_joints_arr=list(goal.target_joints))

            if err != 0:
                goal_handle.abort()
                result.success = False
                result.error_code = err
                return result

            joint_names = self.model.model.get_joint_names_in_chain(self.base_link, self.tip_link)
            dt_default = self.get_parameter('default_dt').value
            jtc_msg, fk_path = self._points_to_jtc_msg(points, joint_names, dt_default)

            if self.get_parameter('publish_ee_path').value:
                self.clear_ee_path()
                self.ee_path_pub.publish(self.create_ee_dotted_path(fk_path, frame_id=self.world_frame))

            jtc_goal = FollowJointTrajectory.Goal()
            jtc_goal.trajectory = jtc_msg
            total = jtc_msg.points[-1].time_from_start
            total_sec = total.sec + total.nanosec * 1e-9

            def jtc_feedback_cb(jtc_feedback_msg):
                actual = jtc_feedback_msg.feedback.actual
                actual_sec = actual.time_from_start.sec + actual.time_from_start.nanosec * 1e-9
                fb = SetJointTarget.Feedback()
                fb.percent_complete = min(1.0, actual_sec / total_sec) if total_sec > 0 else 0.0
                fb.current_state.position = list(actual.positions)
                goal_handle.publish_feedback(fb)

            jtc_goal_handle, timed_out = await self._send_jtc_goal(
                jtc_goal, jtc_feedback_cb,
                step_id_for_log='set_joint_target',
                trajectory_duration_sec=total_sec)

            if timed_out:
                final_positions = np.array(jtc_msg.points[-1].positions)
                poll_deadline = time.monotonic() + total_sec + 5.0
                poll_interval = 0.2
                reached = False
                while time.monotonic() < poll_deadline:
                    if self.q_current is not None:
                        err = float(np.max(np.abs(self.q_current - final_positions)))
                        if err < 0.05:
                            reached = True
                            break
                    await self._sleep_async(poll_interval)

                if reached:
                    self.get_logger().warn(
                        'set_joint_target: arm reached target despite lost '
                        'goal response — treating as success')
                    result.success = True
                    result.error_code = 0
                    goal_handle.succeed()
                    return result
                else:
                    goal_handle.abort()
                    result.success = False
                    result.error_code = 10
                    return result

            if jtc_goal_handle is None:
                goal_handle.abort()
                result.success = False
                result.error_code = 6
                return result

            if goal_handle.is_cancel_requested:
                await jtc_goal_handle.cancel_goal_async()
                goal_handle.canceled()
                result.success = False
                result.error_code = 7
                return result

            result_timeout = total_sec + 10.0
            result_wrapper = Future()
            result_timer = [None]

            def _cleanup_result_timer_sj():
                t = result_timer[0]
                if t is not None:
                    result_timer[0] = None
                    try:
                        t.cancel()
                    except Exception:
                        pass
                    try:
                        t.destroy()
                    except Exception:
                        pass

            def _on_result_done_sj(f):
                _cleanup_result_timer_sj()
                if result_wrapper.done():
                    return
                try:
                    result_wrapper.set_result(('ok', f.result()))
                except Exception as e:
                    result_wrapper.set_result(('error', e))

            def _on_result_timeout_sj():
                _cleanup_result_timer_sj()
                if not result_wrapper.done():
                    result_wrapper.set_result(('timeout', None))

            result_future = jtc_goal_handle.get_result_async()
            result_future.add_done_callback(_on_result_done_sj)
            result_timer[0] = self.create_timer(result_timeout, _on_result_timeout_sj)

            res_status, res_value = await result_wrapper

            if res_status == 'timeout':
                self.get_logger().error(
                    f'set_joint_target: no result from JTC within '
                    f'{result_timeout:.1f}s — attempting to cancel, trajectory '
                    f'may still be running')
                try:
                    cancel_future = jtc_goal_handle.cancel_goal_async()
                    cancel_wrapper = Future()
                    cancel_timer = [None]

                    def _cleanup_cancel_timer_sj():
                        t = cancel_timer[0]
                        if t is not None:
                            cancel_timer[0] = None
                            try:
                                t.cancel()
                            except Exception:
                                pass
                            try:
                                t.destroy()
                            except Exception:
                                pass

                    def _on_cancel_done_sj(f):
                        _cleanup_cancel_timer_sj()
                        if cancel_wrapper.done():
                            return
                        try:
                            cancel_wrapper.set_result(f.result())
                        except Exception as e:
                            cancel_wrapper.set_result(e)

                    def _on_cancel_timeout_sj():
                        _cleanup_cancel_timer_sj()
                        if not cancel_wrapper.done():
                            cancel_wrapper.set_result(None)

                    cancel_future.add_done_callback(_on_cancel_done_sj)
                    cancel_timer[0] = self.create_timer(5.0, _on_cancel_timeout_sj)
                    await cancel_wrapper
                    self.get_logger().info('set_joint_target: cancel request sent')
                except Exception:
                    self.get_logger().error(
                        'set_joint_target: cancel request failed — '
                        'arm state unknown, operator must verify manually')
                goal_handle.abort()
                result.success = False
                result.error_code = 11
                return result

            if res_status == 'error':
                self.get_logger().error(
                    f'set_joint_target: get_result_async failed: {res_value}')
                goal_handle.abort()
                result.success = False
                result.error_code = 11
                return result

            jtc_result = res_value

            result.success, result.error_code = self._map_jtc_result(jtc_result, 'set_joint_target')
            if hasattr(jtc_result.result, 'actual'):
                result.final_state.position = list(jtc_result.result.actual.positions)

            goal_handle.succeed() if result.success else goal_handle.abort()
            return result
        finally:
            # Release busy flag immediately so the next goal can be
            # accepted without waiting for post-processing/logging.
            with self._motion_busy_lock:
                self._motion_busy = False

    # =========================================================
    # VISUALIZATION
    # =========================================================

    def publish_waypoints(self):
        marker                 = Marker()
        marker.header.frame_id = self.world_frame
        marker.header.stamp    = self.get_clock().now().to_msg()
        marker.type            = Marker.SPHERE_LIST
        marker.id              = 0
        marker.scale.x         = 0.03
        marker.scale.y         = 0.03
        marker.scale.z         = 0.03
        marker.color.a         = 1.0
        marker.color.r         = 1.0
        marker.points          = []
        for wp in self.waypoints:
            p     = Point()
            p.x, p.y, p.z = wp.pose[:3]
            marker.points.append(p)
        self.marker_pub.publish(marker)

    def create_ee_dotted_path(self, path_points, frame_id='world',
                               marker_id=100, dot_size=0.008,
                               color=(0.0, 1.0, 0.0), alpha=1.0,
                               lifetime=0.0):
        marker                 = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp    = self.get_clock().now().to_msg()
        marker.ns              = 'ee_trajectory'
        marker.id              = marker_id
        marker.type            = Marker.SPHERE_LIST
        marker.action          = Marker.ADD
        marker.scale.x         = dot_size
        marker.scale.y         = dot_size
        marker.scale.z         = dot_size
        marker.color.r         = color[0]
        marker.color.g         = color[1]
        marker.color.b         = color[2]
        marker.color.a         = alpha
        marker.lifetime        = Duration(
            sec=int(lifetime), nanosec=int((lifetime % 1.0) * 1e9))
        for p in path_points:
            pt = Point()
            pt.x, pt.y, pt.z = float(p[0]), float(p[1]), float(p[2])
            marker.points.append(pt)
        return marker

    def clear_ee_path(self):
        marker                 = Marker()
        marker.header.frame_id = self.world_frame
        marker.header.stamp    = self.get_clock().now().to_msg()
        marker.ns              = 'ee_trajectory'
        marker.id              = 100
        marker.action          = Marker.DELETE
        self.ee_path_pub.publish(marker)

    # =========================================================
    # CLEAR
    # =========================================================

    def clear_waypoints(self):
        self.waypoints.clear()
        self.motion_segments.clear()
        self.wp_counter = 0

        marker        = Marker()
        marker.header.frame_id = self.world_frame
        marker.action = Marker.DELETEALL
        self.marker_pub.publish(marker)
        self.ee_path_pub.publish(marker)

        self.get_logger().info('Cleared waypoints + segments')


# =========================================================
# MAIN
# =========================================================

def main():
    rclpy.init()
    node = MotionPlanner()
    executor = MultiThreadedExecutor(num_threads=8)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()