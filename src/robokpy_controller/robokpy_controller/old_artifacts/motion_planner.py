import rclpy
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
from control_msgs.action import FollowJointTrajectory
from robokpy_interfaces.action import ExecuteMotion


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

        self.waypoint_point_indices: dict = {}   # wp_id → point index in full[]

        # =====================================================
        # ExecuteMotion action server (orchestrator-driven steps)
        # Separate execution path from the /joint_trajectory + motion_controller
        # Teach-mode path below — this one drives JTC directly for goal/
        # feedback/result semantics the topic-based path doesn't give.
        # =====================================================
        self._action_cb_group = ReentrantCallbackGroup()
        self._jtc_client = ActionClient(
            self, FollowJointTrajectory,
            '/arm_controller/follow_joint_trajectory',
            callback_group=self._action_cb_group,
        )
        self._execute_motion_server = ActionServer(
            self, ExecuteMotion, 'execute_motion',
            execute_callback=self._execute_motion_cb,
            goal_callback=self._execute_motion_goal_cb,
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
        self.declare_parameter('default_speed_factor',         0.5)
        self.declare_parameter('default_blend_radius',         0.0)
        self.declare_parameter('default_duration_per_segment', 3.0)
        self.declare_parameter('default_dt',                   0.02)
        self.declare_parameter('default_n_samples',            100)
        self.declare_parameter('default_n_blend',              20)

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
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL  # late joiners get last value, like sys_mode

        self.create_subscription(String, '/planning_tip_link', self.tip_link_cb, qos)  # same TRANSIENT_LOCAL qos


        # =====================================================
        # Publishers (visualization only — execution goes direct to JTC
        # via the ExecuteMotion action server, no /joint_trajectory topic)
        # =====================================================
        self.marker_pub  = self.create_publisher(
            Marker, '/trajectory_marker', 10)
        self.ee_path_pub = self.create_publisher(
            Marker, '/ee_trajectory_marker', 10)

        # in __init__:
        self.scripted_wp_status_pub = self.create_publisher(
            String, '/scripted_waypoint_status', 10)
                
        self.get_logger().info('Motion Planner Ready')

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
    

    # =========================================================
    # STATE CHECK
    # =========================================================

    def robot_state_ready(self) -> bool:
        return self.q_current is not None and self.pose_current is not None

    # =========================================================
    # COMMAND ROUTER
    # =========================================================

    def cmd_cb(self, msg):
        cmd = msg.data.strip()
        low = cmd.lower()
        self.command = low

        # ── Waypoint management ───────────────────────────────
        if low == 'record_waypoint':
            self.record_waypoint()
        elif low == 'clear_waypoints':
            self.clear_waypoints()
        elif low.startswith('delete_waypoint:'):
            self.delete_waypoint(cmd.split(':', 1)[1].strip())
        elif low == 'list_waypoints':
            self.list_waypoints()

        # ── Execution ─────────────────────────────────────────
        # NOTE: 'execute' (whole-recipe batch build), go_home, goto_approach,
        # goto_pose, and set_approach/clear_approach all removed — those were
        # old-architecture debug/recovery tools (assuming a stuck robot).
        # All production motion now goes through the ExecuteMotion action
        # server, including any home-recovery move, authored as a plain
        # step in the orchestrator's recipe like any other move.
        elif low == 'stage_home_waypoint':
            self.add_waypoint_at_joints(self.home_q.copy())

        # ── Motion mode ───────────────────────────────────────
        elif low == 'movel':
            self.pending_config.traj_method = 'ts'
            self.pending_config.traj_type   = 'blend'
        elif low == 'movej':
            self.pending_config.traj_method = 'js'
            self.pending_config.traj_type   = 'lspb'

        # ── Trajectory config ─────────────────────────────────
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

        q_target = self.model.ik.solve(target_pose, q0=q_seed, mask=self.mask)
        if not self.model.ik.success:
            self.get_logger().error(f'Scripted waypoint IK failed at {target_pose[:3]} — not added')
            self._publish_wp_status('failed:ik')
            return None

        wp_id = self._append_waypoint(target_pose, q_target)
        self.get_logger().info(f'Scripted waypoint {wp_id} @ pose {target_pose[:3]}')
        self._publish_wp_status(f'success:{wp_id}')
        return wp_id

    def add_waypoint_at_joints(self, q_target: np.ndarray) -> str:
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
    # =========================================================
    # EXECUTE MOTION ACTION SERVER (orchestrator-driven steps)
    # =========================================================
    # Generates ONE step's trajectory just-in-time (same create_trajectory
    # call pattern the old go_home/goto_approach/goto_pose/segment-loop all
    # used independently) and drives it directly via the JTC action client.
    # blend_radius is author-set per step (same as the old SegmentConfig),
    # not derived from a look-ahead target — matching how create_trajectory
    # is actually called elsewhere in this file.

    def _execute_motion_goal_cb(self, goal_request):
        if not self.robot_state_ready():
            return GoalResponse.REJECT
        if not self.active_mode_flag:
            # Accepting this would seed the trajectory from q_raw
            # (kinematic_solver's interactive-jogging output — disconnected
            # from the real robot) instead of q_current (the real robot's
            # actual state), which is exactly what caused a tolerance-
            # violation abort further down the recipe. Reject outright
            # rather than execute against a seed we know is wrong.
            self.get_logger().error(
                f'{goal_request.step_id}: rejected — system_mode is not ACTIVE. '
                f'Call /set_system_mode {{new_mode: "ACTIVE"}} before running a recipe.')
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def _execute_motion_cancel_cb(self, goal_handle):
        return CancelResponse.ACCEPT

    async def _execute_motion_cb(self, goal_handle):
        goal = goal_handle.request
        result = ExecuteMotion.Result()

        raw = self.q_current.copy() if self.active_mode_flag else self.q_raw.copy()
        q_start = self._normalize_joints(raw)
        self.get_logger().info(
            f'{goal.step_id}: seeding from raw={raw.tolist()} '
            f'normalized={q_start.tolist()} (active_mode_flag={self.active_mode_flag})')
        # pose_start is derived via FK from q_start — NOT from
        # self.pose_current, which only reflects the last manually-set
        # target pose (interactive marker / scripted waypoint) and stays
        # frozen at whatever it was initialized to (home pose's FK, at
        # boot) if nothing has moved the marker since. Using it as the
        # start pose for 'ts'-mode moves silently anchored the whole
        # trajectory to a stale pose while the joint seed (q_start) was
        # correct the entire time — confirmed via diagnostic logging
        # showing the correct seed but a trajectory starting at home_pose.
        if goal.traj_method == 'ts':
            self.fk.compute_chain(q_start, self.base_link, self.tip_link)
            pose_start = self.fk.get_pose_quart()
        else:
            pose_start = None

        if goal.target_type == ExecuteMotion.Goal.JOINT_TARGET:
            q_target = np.array(goal.target_joints)
            pose_target = None
        else:
            target_pose = np.array([
                goal.target_pose.position.x,
                goal.target_pose.position.y,
                goal.target_pose.position.z,
                goal.target_pose.orientation.x,
                goal.target_pose.orientation.y,
                goal.target_pose.orientation.z,
                goal.target_pose.orientation.w,
            ])
            q_target = self.model.ik.solve(target_pose, q0=q_start, mask=self.mask)
            if not self.model.ik.success:
                goal_handle.abort()
                result.success = False
                result.error_code = 2  # IK failed
                return result
            pose_target = target_pose

        vel_limits, acc_limits, pos_limits = self._get_limits()

        traj = self.traj_planner.create_trajectory(
            waypoints=[
                {'q': q_start,  'pose': pose_start,  'mode': goal.traj_method},
                {'q': q_target, 'pose': pose_target, 'mode': goal.traj_method},
            ],
            traj_method          = goal.traj_method,
            traj_type            = goal.traj_type,
            n_samples            = self.get_parameter('default_n_samples').value,
            blend_radius         = goal.blend_radius,
            n_blend              = self.get_parameter('default_n_blend').value,
            duration_per_segment = self.get_parameter('default_duration_per_segment').value,
            dt                   = self.get_parameter('default_dt').value,
            speed_factor         = goal.speed_scale,
            vel_limits           = vel_limits,
            acc_limits           = acc_limits,
        )

        if traj is None or len(traj) == 0:
            self.get_logger().warn(f'{goal.step_id}: trajectory generation failed')
            goal_handle.abort()
            result.success = False
            result.error_code = 3  # trajectory generation failed
            return result

        # ── Pre-execution checks (same as the old build_task_trajectory) ──
        timed = [pt for pt in traj if isinstance(pt, TrajectoryPoint)]
        if timed:
            if self.get_parameter('enable_continuity_check').value:
                cont = self.traj_planner.validate_continuity(timed)
                if not cont['c1_ok']:
                    self.get_logger().warn(f"Velocity discontinuities at: {cont['c1_violations']}")
                if not cont['c2_ok']:
                    self.get_logger().warn(f"Acceleration discontinuities at: {cont['c2_violations']}")
            if self.get_parameter('enable_limit_check').value:
                lim = self.traj_planner.check_joint_limits(timed, pos_limits, vel_limits, acc_limits)
                if not lim['pos_limit_ok']:
                    msg_str = (f"Position limit violations at: "
                               f"{lim['pos_lo_violations'] + lim['pos_hi_violations']}")
                    if self.get_parameter('abort_on_limit_violation').value:
                        self.get_logger().error(f'ABORT — {msg_str}')
                        goal_handle.abort()
                        result.success = False
                        result.error_code = 4  # limit violation
                        return result
                    self.get_logger().warn(msg_str)
                if not lim['vel_limit_ok']:
                    self.get_logger().warn(f"Velocity limit violations at: {lim['vel_violations']}")

        # ── Build JointTrajectory + FK visualization ──────────────────────
        joint_names = self.model.model.get_joint_names_in_chain(self.base_link, self.tip_link)
        dt_default  = self.get_parameter('default_dt').value

        jtc_msg = JointTrajectory()
        jtc_msg.joint_names = joint_names
        fk_path = []

        for i, pt in enumerate(traj):
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

        self.clear_ee_path()
        self.ee_path_pub.publish(self.create_ee_dotted_path(fk_path, frame_id=self.world_frame))

        # TEMPORARY: force the last point to zero velocity/acceleration.
        # joint_trajectory_controller rejects any goal whose final point has
        # nonzero velocity (correctly — nothing guarantees another goal
        # follows to continue the motion). blend_radius intentionally leaves
        # nonzero exit velocity for continuation into a NEXT step, but since
        # each step is now its own independent JTC goal, there's no next
        # goal for the controller to know about. This unblocks testing at
        # the cost of a real stop at every step boundary — the actual fix is
        # merging consecutive motion steps into one JTC goal so only the
        # true end-of-run point gets zeroed, preserving real blending.
        if jtc_msg.points:
            last = jtc_msg.points[-1]
            last.velocities = [0.0] * len(last.positions)
            last.accelerations = [0.0] * len(last.positions)

        # ── Drive JTC directly ────────────────────────────────────────────
        if not self._jtc_client.wait_for_server(timeout_sec=2.0):
            goal_handle.abort()
            result.success = False
            result.error_code = 5  # JTC server unavailable
            return result

        jtc_goal = FollowJointTrajectory.Goal()
        jtc_goal.trajectory = jtc_msg
        self.get_logger().info(
            f'{goal.step_id}: sending trajectory to JTC — '
            f'first_point={list(jtc_msg.points[0].positions)} '
            f'last_point={list(jtc_msg.points[-1].positions)} '
            f'n_points={len(jtc_msg.points)}')
        total = jtc_msg.points[-1].time_from_start
        total_sec = total.sec + total.nanosec * 1e-9

        def jtc_feedback_cb(jtc_feedback_msg):
            fb = ExecuteMotion.Feedback()
            actual = jtc_feedback_msg.feedback.actual
            fb.current_state.position = list(actual.positions)
            actual_sec = actual.time_from_start.sec + actual.time_from_start.nanosec * 1e-9
            fb.percent_complete = min(1.0, actual_sec / total_sec) if total_sec > 0 else 0.0
            goal_handle.publish_feedback(fb)

        send_future = self._jtc_client.send_goal_async(jtc_goal, feedback_callback=jtc_feedback_cb)
        jtc_goal_handle = await send_future

        if not jtc_goal_handle.accepted:
            goal_handle.abort()
            result.success = False
            result.error_code = 6  # JTC rejected goal
            return result

        if goal_handle.is_cancel_requested:
            await jtc_goal_handle.cancel_goal_async()
            goal_handle.canceled()
            result.success = False
            result.error_code = 7  # canceled
            return result

        jtc_result = await jtc_goal_handle.get_result_async()
        result.success = jtc_result.result.error_code == FollowJointTrajectory.Result.SUCCESSFUL
        if result.success:
            result.error_code = 0
        else:
            # control_msgs' error_code is signed (e.g. PATH_TOLERANCE_VIOLATED=-4,
            # GOAL_TOLERANCE_VIOLATED=-5) — ExecuteMotion.Result.error_code is
            # uint32, so passing the raw value through overflows and crashes
            # the node at serialization time. Map to a fixed positive code and
            # log JTC's actual code for diagnosis instead.
            result.error_code = 9  # JTC execution failure (see log for JTC's own code)
            self.get_logger().error(
                f'{goal.step_id}: JTC execution failed, '
                f'jtc_error_code={jtc_result.result.error_code} '
                f'(see control_msgs/FollowJointTrajectory/Result for meaning)')
        if hasattr(jtc_result.result, 'actual'):
            result.final_state.position = list(jtc_result.result.actual.positions)

        goal_handle.succeed() if result.success else goal_handle.abort()
        return result


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
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()