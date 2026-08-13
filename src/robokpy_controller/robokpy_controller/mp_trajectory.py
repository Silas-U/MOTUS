"""
mp_trajectory.py  —  TrajectoryDispatcher

The ONLY place that decides how a motion goal is turned into a trajectory.
All recipe logic lives here. Callers get back a TrajectoryResult or a
LegResult with an error code.

Design principle: for LSPB single-leg trajectories, call the planner
directly with full parameter control. For Cartesian (ts) legs, we
manually interpolate in Cartesian space and solve IK at each sample —
exactly what the pipeline's CartesianLineGenerator did — then feed the
resulting joint-space path to create_trajectory as traj_method='js'.
"""

import numpy as np
from typing import List, Optional, Tuple

from robokpy import TrajectoryPoint
from robokpy.pipeline import PipelineFactory, TrajectoryValidationError

from .mp_types import (
    TrajectoryConfig,
    TrajectoryResult,
    LegResult,
)
from .mp_kinematics import KinematicsFacade


class TrajectoryDispatcher:
    """Groups consecutive same-method legs into single planner calls."""

    def __init__(self,
                 kinematics: KinematicsFacade,
                 pipeline_factory: PipelineFactory,
                 logger,
                 default_n_samples: int = 50,
                 default_n_blend: int = 20,
                 default_dt: float = 0.04,
                 enable_continuity_check: bool = True,
                 abort_on_limit_violation: bool = False):
        self._kin = kinematics
        self._factory = pipeline_factory
        self._logger = logger
        self._default_n_samples = default_n_samples
        self._default_n_blend = default_n_blend
        self._default_dt = default_dt
        self._enable_continuity_check = enable_continuity_check
        self._abort_on_limit_violation = abort_on_limit_violation

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------
    def dispatch(self, goal, q_seed: np.ndarray, config: TrajectoryConfig) -> TrajectoryResult:
        """Main entry point. Returns a fully resolved TrajectoryResult.

        Groups the goal's legs into maximal runs of consecutive legs
        sharing the same (traj_method, normalized traj_type) and plans
        each run with ONE call to the planner, so intermediate legs
        within a run get whatever native multi-waypoint continuity the
        planner provides instead of being forced to a full stop at
        every leg boundary. A hard stop (zero velocity/accel knot) is
        still forced only at a genuine traj_method change between runs
        — see _run_grouped.
        """
        q_seed = np.asarray(q_seed, dtype=float)
        return self._run_grouped(goal, q_seed, config)

    def generate_single_leg(self,
                          q_seed: np.ndarray,
                          config: TrajectoryConfig,
                          target_pose: Optional[np.ndarray] = None,
                          target_joints: Optional[np.ndarray] = None) -> LegResult:
        """Generate a single leg. Direct planner calls for full control."""
        q_seed = np.asarray(q_seed, dtype=float)
        active_joints = self._kin.get_active_joints()

        # Resolve target joints
        if target_joints is not None:
            q_target = np.asarray(target_joints, dtype=float)
        else:
            q_target = self._kin.solve_ik(np.asarray(target_pose, dtype=float), q_seed)
            if q_target is None:
                self._logger.error(
                    f'generate_single_leg: IK failed for target pose {target_pose[:3]}')
                return LegResult(points=[], q_target=q_seed, error_code=3)
            q_target = self._kin.shortest_equivalent(
                q_target, q_seed, active_joints, config.pos_limits)

        return self._generate_direct(q_seed, q_target, config, target_pose)

    # ------------------------------------------------------------------
    # Internal: direct planner call
    # ------------------------------------------------------------------
    def _generate_direct(self, q_seed: np.ndarray, q_target: np.ndarray,
                         config: TrajectoryConfig,
                         target_pose: Optional[np.ndarray] = None) -> LegResult:
        """Call traj_planner.create_trajectory directly with ALL parameters.

        traj_method='js': joint-space trajectory. Maps recipe 'blend' type
        to 'lspb' since true Cartesian blending doesn't apply in joint space.

        traj_method='ts': task-space (Cartesian) trajectory. Passes
        traj_type through as-is — the planner handles 'blend' natively
        in task space. Waypoints MUST include poses.
        """
        # Determine traj_type for the planner
        if config.traj_method == 'js':
            # In joint space, 'blend' is not a real trajectory type — map to lspb
            if config.traj_type in ('blend', 'qu'):
                traj_type = 'lspb'
            elif config.traj_type == 'topp_blend':
                self._logger.warn(
                    'traj_type="topp_blend" no longer supported — falling back to lspb')
                traj_type = 'lspb'
            else:
                traj_type = config.traj_type  # 'lspb', 'scurve'
            if config.blend_radius > 1e-9:
                self._logger.warn(
                    'Joint-space blend_radius is not a true Cartesian blend — ignoring')
            waypoints = [{'q': q_seed}, {'q': q_target}]
        else:
            # Task space: pass traj_type through unchanged ('blend', etc.)
            traj_type = config.traj_type
            start_pose = self._kin.compute_fk(q_seed)
            end_pose = (np.asarray(target_pose, dtype=float)
                        if target_pose is not None
                        else self._kin.compute_fk(q_target))
            waypoints = [
                {'q': q_seed, 'pose': start_pose},
                {'q': q_target, 'pose': end_pose},
            ]

        jerk_limits = config.jerk_limits if traj_type == 'scurve' else None

        try:
            points = self._kin.traj_planner.create_trajectory(
                waypoints=waypoints,
                traj_method=config.traj_method,
                traj_type=traj_type,
                duration_per_segment=config.duration_per_segment,
                dt=config.dt,
                n_blend=config.n_blend,
                speed_factor=config.speed_factor,
                vel_limits=config.vel_limits,
                acc_limits=config.acc_limits,
                jerk_limits=jerk_limits,
            )
        except Exception as e:
            self._logger.error(f"Direct trajectory generation failed: {e}")
            return LegResult(points=[], q_target=q_seed, error_code=3)

        if not points:
            return LegResult(points=[], q_target=q_seed, error_code=3)

        # Continuity audit
        if self._enable_continuity_check:
            timed = [pt for pt in points if isinstance(pt, TrajectoryPoint)]
            if timed:
                cont = self._kin.traj_planner.validate_continuity(timed)
                if not cont['c1_ok']:
                    self._logger.warn(
                        f"velocity discontinuities at: {cont['c1_violations']}")
                if not cont['c2_ok']:
                    self._logger.warn(
                        f"acceleration discontinuities at: {cont['c2_violations']}")

        return LegResult(points=points, q_target=q_target, error_code=0)

    # ------------------------------------------------------------------
    # Internal: grouped-run assembly (replaces old per-leg + whole-goal-
    # only-blended paths — see dispatch()'s docstring)
    # ------------------------------------------------------------------
    def _normalize_traj_type(self, method: str, traj_type: str) -> str:
        """Same mapping _generate_direct already applied for js — pulled
        out so grouping can key on the type the planner will actually
        see, not the raw recipe string (so e.g. two 'js' legs recipe'd
        as 'blend' and 'lspb' still group together, since both map to
        'lspb' for js)."""
        if method != 'js':
            return traj_type
        if traj_type in ('blend', 'qu'):
            return 'lspb'
        if traj_type == 'topp_blend':
            return 'lspb'
        return traj_type

    def _group_by_method(self, goal) -> List[Tuple[int, int]]:
        """Partition leg indices into maximal runs sharing the same
        (traj_method, normalized traj_type). Returns a list of
        (start_idx, end_idx) inclusive ranges. Only a change in this
        key still forces a group boundary (hard stop)."""
        n_legs = len(goal.leg_step_ids)
        keys = [
            (goal.leg_traj_methods[i],
             self._normalize_traj_type(goal.leg_traj_methods[i], goal.leg_traj_types[i]))
            for i in range(n_legs)
        ]
        groups = []
        start = 0
        for i in range(1, n_legs):
            if keys[i] != keys[start]:
                groups.append((start, i - 1))
                start = i
        groups.append((start, n_legs - 1))
        return groups

    def _resolve_group_waypoints(self, goal, start: int, end: int,
                                  q_seed: np.ndarray, config: TrajectoryConfig) -> List[dict]:
        """Solve IK for each leg's target in [start, end], chaining seeds
        leg-to-leg. Returns a waypoints list of length (end-start+2):
        the group's entry state plus one entry per leg, each with both
        'q' and 'pose' (js groups drop 'pose' before calling the
        planner; ts groups need it)."""
        active_joints = self._kin.get_active_joints()
        q_prev = q_seed.copy()
        pose_prev = self._kin.compute_fk(q_prev)
        waypoints = [{'q': q_prev.copy(), 'pose': pose_prev}]

        for i in range(start, end + 1):
            p = goal.leg_target_poses[i]
            pose_arr = np.array([
                p.position.x, p.position.y, p.position.z,
                p.orientation.x, p.orientation.y,
                p.orientation.z, p.orientation.w,
            ])
            q = self._kin.solve_ik(pose_arr, q_prev)
            if q is None:
                raise TrajectoryDispatchError(step_id=goal.leg_step_ids[i], error_code=2)
            q = self._kin.shortest_equivalent(q, q_prev, active_joints, config.pos_limits)
            waypoints.append({'q': q, 'pose': pose_arr})
            q_prev = q.copy()

        return waypoints

    def _generate_group(self, goal, start: int, end: int,
                         q_seed: np.ndarray, config: TrajectoryConfig):
        """Plan the whole [start, end] run of same-method legs in ONE
        planner call. Returns (points, leg_time_ranges, q_final).

        js: no native blend support in RoboKpy (confirmed — see
        robokpy_base.yaml's comment), so no blend_radius is passed, but
        the FULL waypoint chain still goes in one create_trajectory
        call rather than one call per leg — whatever native multi-
        waypoint continuity the planner provides is no longer discarded
        by artificially isolating each leg.

        ts: uses create_topp_blended_cartesian_trajectory — real
        vel/acc-limit-aware time-optimal parametrization (TOPP) over a
        properly corner-blended path, with actual per-leg boundary
        times returned by the planner (return_leg_times=True) instead
        of an approximation.
        """
        method = goal.leg_traj_methods[start]
        step_ids = list(goal.leg_step_ids[start:end + 1])
        waypoints = self._resolve_group_waypoints(goal, start, end, q_seed, config)
        q_final = waypoints[-1]['q']

        if method == 'js':
            traj_type = self._normalize_traj_type(method, goal.leg_traj_types[start])
            if any(goal.leg_blend_radii[i] > 1e-9 for i in range(start, end)):
                self._logger.warn(
                    f'Joint-space blend_radius is not a true Cartesian blend — '
                    f'ignoring (legs {step_ids})')
            jerk_limits = config.jerk_limits if traj_type == 'scurve' else None
            call_waypoints = [{'q': wp['q']} for wp in waypoints]
            try:
                points = self._kin.traj_planner.create_trajectory(
                    waypoints=call_waypoints,
                    traj_method='js',
                    traj_type=traj_type,
                    duration_per_segment=config.duration_per_segment,
                    dt=config.dt,
                    n_blend=config.n_blend,
                    speed_factor=goal.speed_scale,
                    vel_limits=config.vel_limits,
                    acc_limits=config.acc_limits,
                    jerk_limits=jerk_limits,
                )
            except Exception as e:
                self._logger.error(
                    f"Group trajectory generation failed (js, legs {step_ids}): {e}")
                raise TrajectoryDispatchError(step_id=step_ids[0], error_code=3)

            if not points:
                raise TrajectoryDispatchError(step_id=step_ids[0], error_code=3)

            if self._enable_continuity_check:
                timed = [pt for pt in points if isinstance(pt, TrajectoryPoint)]
                if timed:
                    cont = self._kin.traj_planner.validate_continuity(timed)
                    if not cont['c1_ok']:
                        self._logger.warn(f"velocity discontinuities at: {cont['c1_violations']}")
                    if not cont['c2_ok']:
                        self._logger.warn(f"acceleration discontinuities at: {cont['c2_violations']}")

            dist_fn = lambda a, b: float(np.linalg.norm(b['q'] - a['q']))

            # js: no leg_end_times from the planner, so approximate the
            # split proportional to path distance.
            total_time = points[-1].t if isinstance(points[-1], TrajectoryPoint) else (len(points) - 1) * config.dt
            seg_dists = [max(dist_fn(waypoints[i], waypoints[i + 1]), 1e-9)
                         for i in range(len(waypoints) - 1)]
            total_dist = sum(seg_dists)

            leg_time_ranges = []
            t_cursor = 0.0
            for i, step_id in enumerate(step_ids):
                frac = seg_dists[i] / total_dist if total_dist > 1e-9 else 1.0 / len(step_ids)
                t_end = t_cursor + total_time * frac
                leg_time_ranges.append((step_id, t_cursor, t_end))
                t_cursor = t_end

            return points, leg_time_ranges, q_final

        else:
            # ts: create_topp_blended_cartesian_trajectory runs real
            # time-optimal parametrization (TOPP) over the geometrically
            # blended path using ACTUAL vel_limits/acc_limits — closing
            # the vel/acc-limit-blindness create_blended_cartesian_
            # trajectory had (confirmed via source: that call has no
            # vel/acc-limit params at all, timing was purely n_samples *
            # dt). Also does real Bezier corner blending, not the known-
            # buggy sharp-corner one in the base class's
            # _blend_radius_cartesian. cart_vel_cap reuses the
            # cartesian_vel_limit config as an extra TCP-speed cap
            # layered on top of the joint-limit-derived timing, not a
            # replacement for it — TOPP is the real fix here, that
            # config value is now a secondary safety cap, not load-
            # bearing the way it was for the n_samples-derivation
            # workaround it replaces.
            if config.vel_limits is None or config.acc_limits is None:
                self._logger.error(
                    f"ts group (legs {step_ids}) has no vel_limits/acc_limits "
                    f"configured — required for TOPP parametrization")
                raise TrajectoryDispatchError(step_id=step_ids[0], error_code=3)

            n_corners = end - start
            blend_radius = (
                [float(np.clip(goal.leg_blend_radii[i], 0.0, 0.499)) for i in range(start, end)]
                if n_corners > 0 else 0.0
            )
            cart_cap = config.cartesian_vel_limit if config.cartesian_vel_limit > 1e-9 else None

            try:
                result = self._kin.traj_planner.create_topp_blended_cartesian_trajectory(
                    waypoints,
                    vel_limits=config.vel_limits,
                    acc_limits=config.acc_limits,
                    blend_radius=blend_radius,
                    n_samples=self._default_n_samples,
                    n_blend=self._default_n_blend,
                    cart_vel_cap=cart_cap,
                    return_leg_times=True,
                )
            except Exception as e:
                self._logger.error(
                    f"Group trajectory generation failed (ts TOPP, legs {step_ids}): {e}")
                raise TrajectoryDispatchError(step_id=step_ids[0], error_code=3)

            if result is None:
                # IK failure somewhere along the blended path
                raise TrajectoryDispatchError(step_id=step_ids[0], error_code=2)
            points, leg_end_times = result
            if not points:
                raise TrajectoryDispatchError(step_id=step_ids[0], error_code=3)

            leg_time_ranges = []
            t_cursor = 0.0
            for i, step_id in enumerate(step_ids):
                t_end = leg_end_times[i]
                leg_time_ranges.append((step_id, t_cursor, t_end))
                t_cursor = t_end

            return points, leg_time_ranges, q_final

    def _run_grouped(self, goal, q_seed: np.ndarray, config: TrajectoryConfig) -> TrajectoryResult:
        groups = self._group_by_method(goal)

        full_points = []
        leg_time_ranges = []
        t_offset = 0.0
        q_current = q_seed.copy()
        dt_default = self._default_dt

        for group_idx, (start, end) in enumerate(groups):
            group_points, group_ranges, q_current = self._generate_group(
                goal, start, end, q_current, config)

            # Force a true zero-velocity/zero-accel knot at a genuine
            # traj_method-change boundary — NOT velocity-averaging
            # (that was found to desync .q from .qd at a seam earlier
            # this session). Only the retained boundary point (the
            # previous group's last point) needs this: the new group's
            # own first point is the same physical waypoint and gets
            # dropped below.
            if full_points and isinstance(full_points[-1], TrajectoryPoint):
                if full_points[-1].qd is not None:
                    full_points[-1].qd = np.zeros_like(full_points[-1].qd)
                if full_points[-1].qdd is not None:
                    full_points[-1].qdd = np.zeros_like(full_points[-1].qdd)

            points_to_add = group_points if group_idx == 0 else group_points[1:]
            for pt in points_to_add:
                if isinstance(pt, TrajectoryPoint):
                    pt.t = pt.t + t_offset
                full_points.append(pt)

            for step_id, t_start, t_end in group_ranges:
                leg_time_ranges.append((step_id, t_start + t_offset, t_end + t_offset))

            group_duration = group_ranges[-1][2] if group_ranges else 0.0
            t_offset += group_duration

        return self.package_result(full_points, leg_time_ranges, q_current, dt_default)

    def package_result(self, points, leg_time_ranges, predicted_q, dt_default) -> TrajectoryResult:
        from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
        from builtin_interfaces.msg import Duration

        joint_names = self._kin.joint_names
        jtc_msg = JointTrajectory()
        jtc_msg.joint_names = joint_names
        fk_path = []

        for i, pt in enumerate(points):
            jtp = JointTrajectoryPoint()
            if isinstance(pt, TrajectoryPoint):
                jtp.positions = pt.q.tolist()
                jtp.velocities = pt.qd.tolist() if pt.qd is not None else []
                jtp.accelerations = pt.qdd.tolist() if pt.qdd is not None else []
                t_sec = pt.t
                q_forfk = pt.q
            else:
                jtp.positions = np.asarray(pt).tolist()
                jtp.velocities = []
                jtp.accelerations = []
                t_sec = i * dt_default
                q_forfk = np.asarray(pt)
            sec = int(t_sec)
            nanosec = int((t_sec - sec) * 1e9)
            jtp.time_from_start = Duration(sec=sec, nanosec=nanosec)
            jtc_msg.points.append(jtp)
            fk_path.append(self._kin.get_fk_xyz(q_forfk))

        # Force zero velocity/acceleration on final point
        if jtc_msg.points:
            last = jtc_msg.points[-1]
            last.velocities = [0.0] * len(last.positions)
            last.accelerations = [0.0] * len(last.positions)

        total_duration = leg_time_ranges[-1][2] if leg_time_ranges else 0.0
        return TrajectoryResult(
            points=points,
            leg_time_ranges=leg_time_ranges,
            predicted_q=np.array(predicted_q),
            jtc_msg=jtc_msg,
            fk_path=fk_path,
            total_duration=total_duration,
        )


class TrajectoryDispatchError(Exception):
    """Internal exception for early-exit during dispatch."""
    def __init__(self, step_id: str, error_code: int):
        self.step_id = step_id
        self.error_code = error_code
        super().__init__(f"Dispatch failed at {step_id} (code {error_code})")