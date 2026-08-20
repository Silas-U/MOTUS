"""
planner_core.py  —  Pure-Python trajectory planning.

The only code that calls robokpy trajectory generation.  Runs in a
ThreadPoolExecutor inside trajectory_generator_node so it never blocks
the DDS event loop.
"""

from dataclasses import dataclass
from typing import List, Optional, Tuple

import numpy as np
from robokpy import TrajectoryPoint

from .mp_types import TrajectoryConfig
from .mp_kinematics import KinematicsFacade

# Fraction of each joint's vel_limit used when estimating a hand-off
# velocity toward the next leg (see estimate_exit_boundary). 0.3 = a
# conservative "coast through the seam", not a full-speed hand-off —
# matches the default used by the earlier (superseded) horizon-seam
# implementation this design is ported from.
_EXIT_HINT_SPEED_FRACTION = 0.3


@dataclass
class PlannedTrajectory:
    points: List[TrajectoryPoint]
    leg_time_ranges: List[Tuple[str, float, float]]
    predicted_q: np.ndarray
    total_duration: float
    fk_path: List[np.ndarray]
    # Real, ACHIEVED boundary velocity/acceleration at this plan's very
    # last point. None means the plan ends at rest — either no exit
    # hint was requested, or the last group's traj_method/traj_type
    # can't honor one (see _generate_group). The caller
    # (arm_executor_node.py) threads this forward as the next leg's
    # qd_seed/qdd_seed instead of always forcing a stop at leg
    # boundaries.
    exit_qd: Optional[np.ndarray] = None
    exit_qdd: Optional[np.ndarray] = None


@dataclass
class TrajectoryLeg:
    step_id: str
    target_pose: np.ndarray          # [x,y,z,qx,qy,qz,qw]
    traj_method: str
    traj_type: str
    blend_radius: float


class PlanningError(Exception):
    def __init__(self, step_id: str, error_code: int, message: str = ""):
        self.step_id = step_id
        self.error_code = error_code
        super().__init__(f"Planning failed at {step_id} (code {error_code}): {message}")


def estimate_exit_boundary(
    current_leg: TrajectoryLeg,
    next_leg: Optional[TrajectoryLeg],
    q_seed_before_current: np.ndarray,
    config: TrajectoryConfig,
    kin: KinematicsFacade,
    fraction: float = _EXIT_HINT_SPEED_FRACTION,
) -> Tuple[Optional[np.ndarray], Optional[np.ndarray]]:
    """One-step look-ahead: estimate a hand-off (qd, qdd) at the END of
    current_leg that points toward next_leg, instead of always forcing
    a stop at the seam between two consecutive legs.

    q_seed_before_current is the joint state BEFORE current_leg starts
    (i.e. whatever precedes it — the encoder state for the run's first
    leg, or the previous leg's own predicted end state otherwise).
    This function resolves current_leg's OWN end configuration via IK
    first, then estimates the direction from THAT point toward
    next_leg — not a direct jump from q_seed_before_current straight to
    next_leg's target, which would skip current_leg's own motion
    entirely and estimate a direction unrelated to what current_leg
    actually does.

    Returns (None, None) when there's no next leg, either IK solve
    fails, or the direction is negligible — the caller should then
    leave that seam at rest exactly as before (safe, conservative
    fallback).

    Velocity magnitude is capped at `fraction` of the fastest uniform
    scalar speed that respects every joint's vel_limit. Acceleration
    hint is left at zero — the intent is constant-velocity continuity
    through the seam, not an accelerating hand-off.
    """
    if next_leg is None:
        return None, None

    if config.vel_limits is None:
        return None, None

    active = kin.get_active_joints()

    # Step 1: resolve where current_leg itself actually ends. The exit
    # hint is a boundary condition on the LAST point of current_leg's
    # own trajectory, so this has to be current_leg's own end
    # configuration — not the state before it starts.
    q_end_current = kin.solve_ik(
        np.asarray(current_leg.target_pose, dtype=float), q_seed_before_current
    )
    if q_end_current is None:
        return None, None
    q_end_current = kin.shortest_equivalent(
        q_end_current, q_seed_before_current, active, config.pos_limits
    )

    # Step 2: resolve next_leg's target, seeded from current_leg's own
    # end — matches how the real planner chains IK leg-to-leg.
    q_next = kin.solve_ik(
        np.asarray(next_leg.target_pose, dtype=float), q_end_current
    )
    if q_next is None:
        return None, None

    q_next = kin.shortest_equivalent(q_next, q_end_current, active, config.pos_limits)
    delta = q_next - q_end_current
    abs_delta = np.abs(delta)

    if np.max(abs_delta) < 1e-6:
        return None, None

    vel_limits = np.asarray(config.vel_limits, dtype=float)

    # Largest uniform scalar speed s such that s * |delta_j| <=
    # fraction * vel_limits[j] for every joint that actually moves in
    # this leg — i.e. no joint exceeds its own capped speed.
    with np.errstate(divide='ignore', invalid='ignore'):
        per_joint_cap = np.where(
            abs_delta > 1e-9,
            fraction * vel_limits / abs_delta,
            np.inf,
        )
    s = float(np.min(per_joint_cap))
    if not np.isfinite(s) or s <= 0.0:
        return None, None

    qd_hint = s * delta
    qdd_hint = np.zeros_like(qd_hint)
    return qd_hint, qdd_hint


def plan_trajectory(
    legs: List[TrajectoryLeg],
    q_seed: np.ndarray,
    config: TrajectoryConfig,
    kin: KinematicsFacade,
    qd_seed: Optional[np.ndarray] = None,
    qdd_seed: Optional[np.ndarray] = None,
    qd_exit_hint: Optional[np.ndarray] = None,
    qdd_exit_hint: Optional[np.ndarray] = None,
    compute_fk_path: bool = False,
) -> PlannedTrajectory:
    """Plan a full motion run in ONE call per homogeneous method group.

    Rest-to-rest at both ends by default (qd_seed/qd_exit_hint left
    None) — identical to the original behavior and bit-identical
    output when neither is supplied. Passing qd_seed/qdd_seed asks the
    FIRST group to start from that boundary instead of rest; passing
    qd_exit_hint/qdd_exit_hint asks the LAST group to end at that
    boundary instead of rest. Only 'ts' groups and 'js'+'scurve'
    groups can actually honor a nonzero boundary (see _generate_group)
    — for any other group type the hint is silently ignored and that
    end is forced to rest exactly as before. The caller is responsible
    for seeding q_seed from the actual encoder state.

    compute_fk_path: PlannedTrajectory.fk_path is diagnostic-only (was
    consumed by trajectory_plotter.py, since removed from the stack) —
    it costs one extra FK solve per trajectory point and is not used
    by the execution path. Defaults to False; pass True only if you
    have a real consumer for fk_path (e.g. a future visualization
    tool). When False, fk_path is an empty list.
    """
    q_seed = np.asarray(q_seed, dtype=float)
    groups = _group_by_method(legs)

    full_points: List[TrajectoryPoint] = []
    leg_time_ranges: List[Tuple[str, float, float]] = []
    t_offset = 0.0
    q_current = q_seed.copy()

    final_exit_qd: Optional[np.ndarray] = None
    final_exit_qdd: Optional[np.ndarray] = None

    n_groups = len(groups)

    for group_idx, (start, end) in enumerate(groups):
        is_first = group_idx == 0
        is_last = group_idx == n_groups - 1

        group_qd0 = qd_seed if is_first else None
        group_qdd0 = qdd_seed if is_first else None
        group_qd_exit_hint = qd_exit_hint if is_last else None
        group_qdd_exit_hint = qdd_exit_hint if is_last else None

        pts, ranges, q_current, exit_qd, exit_qdd = _generate_group(
            legs, start, end, q_current, config, kin,
            qd0=group_qd0, qdd0=group_qdd0,
            qd_exit_hint=group_qd_exit_hint, qdd_exit_hint=group_qdd_exit_hint,
        )

        if is_last:
            final_exit_qd, final_exit_qdd = exit_qd, exit_qdd

        # Hard zero-velocity knot at method-change boundaries.
        # The new group's first point is the same physical waypoint, so we
        # drop it and force the previous group's last point to zero.
        if full_points and not is_first:
            if isinstance(full_points[-1], TrajectoryPoint):
                if full_points[-1].qd is not None:
                    full_points[-1].qd = np.zeros_like(full_points[-1].qd)
                if full_points[-1].qdd is not None:
                    full_points[-1].qdd = np.zeros_like(full_points[-1].qdd)
            pts = pts[1:]

        for pt in pts:
            if isinstance(pt, TrajectoryPoint):
                pt.t = pt.t + t_offset
            full_points.append(pt)

        for step_id, t0, t1 in ranges:
            leg_time_ranges.append((step_id, t0 + t_offset, t1 + t_offset))

        group_dur = ranges[-1][2] if ranges else 0.0
        t_offset += group_dur

    # Force final stop UNLESS the last group actually honored a real
    # exit boundary (final_exit_qd is not None in that case).
    if full_points and isinstance(full_points[-1], TrajectoryPoint):
        if final_exit_qd is None:
            if full_points[-1].qd is not None:
                full_points[-1].qd = np.zeros_like(full_points[-1].qd)
            if full_points[-1].qdd is not None:
                full_points[-1].qdd = np.zeros_like(full_points[-1].qdd)

    fk_path = (
        [
            kin.get_fk_xyz(pt.q if isinstance(pt, TrajectoryPoint) else np.asarray(pt))
            for pt in full_points
        ]
        if compute_fk_path
        else []
    )

    total_duration = leg_time_ranges[-1][2] if leg_time_ranges else 0.0
    predicted_q = np.array(q_current)

    return PlannedTrajectory(
        points=full_points,
        leg_time_ranges=leg_time_ranges,
        predicted_q=predicted_q,
        total_duration=total_duration,
        fk_path=fk_path,
        exit_qd=final_exit_qd,
        exit_qdd=final_exit_qdd,
    )


# ------------------------------------------------------------------
# Internal helpers
# ------------------------------------------------------------------

def _normalize_traj_type(method: str, traj_type: str) -> str:
    if method != 'js':
        return traj_type
    if traj_type in ('blend', 'qu'):
        return 'lspb'
    if traj_type == 'topp_blend':
        return 'lspb'
    return traj_type


def _group_by_method(legs: List[TrajectoryLeg]) -> List[Tuple[int, int]]:
    n = len(legs)
    keys = [
        (legs[i].traj_method, _normalize_traj_type(legs[i].traj_method, legs[i].traj_type))
        for i in range(n)
    ]
    groups = []
    start = 0
    for i in range(1, n):
        if keys[i] != keys[start]:
            groups.append((start, i - 1))
            start = i
    groups.append((start, n - 1))
    return groups


def _resolve_group_waypoints(
    legs: List[TrajectoryLeg],
    start: int,
    end: int,
    q_seed: np.ndarray,
    config: TrajectoryConfig,
    kin: KinematicsFacade,
) -> List[dict]:
    """Returns waypoints with 'q' and 'pose' for each leg in the group."""
    active = kin.get_active_joints()
    q_prev = q_seed.copy()
    pose_prev = kin.compute_fk(q_prev)
    waypoints = [{'q': q_prev.copy(), 'pose': pose_prev}]

    for i in range(start, end + 1):
        pose_arr = np.asarray(legs[i].target_pose, dtype=float).flatten()
        q = kin.solve_ik(pose_arr, q_prev)
        if q is None:
            raise PlanningError(legs[i].step_id, 2, f"IK failed at {pose_arr[:3]}")
        q = kin.shortest_equivalent(q, q_prev, active, config.pos_limits)
        waypoints.append({'q': q, 'pose': pose_arr})
        q_prev = q.copy()

    return waypoints


def _generate_group(
    legs: List[TrajectoryLeg],
    start: int,
    end: int,
    q_seed: np.ndarray,
    config: TrajectoryConfig,
    kin: KinematicsFacade,
    qd0: Optional[np.ndarray] = None,
    qdd0: Optional[np.ndarray] = None,
    qd_exit_hint: Optional[np.ndarray] = None,
    qdd_exit_hint: Optional[np.ndarray] = None,
):
    """Plan one homogeneous group.

    Returns (points, leg_time_ranges, q_final, exit_qd, exit_qdd).
    exit_qd/exit_qdd are the REAL achieved boundary at the group's
    last point — None when this group's method/type can't honor a
    nonzero boundary, or none was requested, meaning the caller should
    force that end to rest exactly as before.
    """
    method = legs[start].traj_method
    step_ids = [legs[i].step_id for i in range(start, end + 1)]
    waypoints = _resolve_group_waypoints(legs, start, end, q_seed, config, kin)
    q_final = waypoints[-1]['q']

    if method == 'js':
        traj_type = _normalize_traj_type(method, legs[start].traj_type)
        jerk_limits = config.jerk_limits if traj_type == 'scurve' else None
        call_wps = [{'q': wp['q']} for wp in waypoints]

        # Only js+scurve supports a real nonzero boundary today (same
        # scope as industrial_trajectory.py's general_scurve work —
        # lspb/quintic stay rest-to-rest, request is ignored below).
        wants_boundary = (
            traj_type == 'scurve'
            and (qd0 is not None or qdd0 is not None
                 or qd_exit_hint is not None or qdd_exit_hint is not None)
        )

        try:
            if wants_boundary:
                if config.vel_limits is None or config.acc_limits is None or jerk_limits is None:
                    raise ValueError(
                        "traj_type='scurve' boundary-aware planning requires "
                        "vel_limits, acc_limits, and jerk_limits")
                points = kin.traj_planner.create_general_scurve_joint_trajectory(
                    call_wps, config.vel_limits, config.acc_limits, jerk_limits,
                    dt=config.dt, speed_factor=config.speed_factor,
                    qd0=qd0, qdd0=qdd0, qdf=qd_exit_hint, qddf=qdd_exit_hint)
            else:
                points = kin.traj_planner.create_trajectory(
                    waypoints=call_wps,
                    traj_method='js',
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
            raise PlanningError(step_ids[0], 3, str(e))

        if not points:
            raise PlanningError(step_ids[0], 3, "empty trajectory")

        # Read back the ACHIEVED boundary rather than assuming the
        # hint landed exactly — the general-scurve profile can clip
        # against vel/acc/jerk limits.
        exit_qd = points[-1].qd if (wants_boundary and qd_exit_hint is not None) else None
        exit_qdd = points[-1].qdd if (wants_boundary and qdd_exit_hint is not None) else None

        # Approximate leg splits by joint-space distance
        total_time = points[-1].t if isinstance(points[-1], TrajectoryPoint) else (len(points) - 1) * config.dt
        seg_dists = [
            max(float(np.linalg.norm(waypoints[i + 1]['q'] - waypoints[i]['q'])), 1e-9)
            for i in range(len(waypoints) - 1)
        ]
        total_dist = sum(seg_dists)

        ranges = []
        t_cursor = 0.0
        for i, sid in enumerate(step_ids):
            frac = seg_dists[i] / total_dist if total_dist > 1e-9 else 1.0 / len(step_ids)
            t_end = t_cursor + total_time * frac
            ranges.append((sid, t_cursor, t_end))
            t_cursor = t_end

        return points, ranges, q_final, exit_qd, exit_qdd

    else:
        # ts — TOPP blended Cartesian
        if config.vel_limits is None or config.acc_limits is None:
            raise PlanningError(step_ids[0], 3, "ts requires vel_limits and acc_limits")

        n_corners = end - start
        blend_radius = (
            [float(np.clip(legs[i].blend_radius, 0.0, 0.499)) for i in range(start, end)]
            if n_corners > 0 else 0.0
        )
        cart_cap = config.cartesian_vel_limit if config.cartesian_vel_limit > 1e-9 else None

        # TOPP works in scalar path-parameter velocity (sdot), not a
        # per-joint vector. Approximate the requested joint-space
        # boundary by its norm — exact only when the seam's tangent
        # direction aligns with the joint-velocity vector; same
        # approximation the earlier horizon-seam design used.
        sdot_start = float(np.linalg.norm(qd0)) if qd0 is not None else None
        sdot_end = float(np.linalg.norm(qd_exit_hint)) if qd_exit_hint is not None else None

        try:
            result = kin.traj_planner.create_topp_blended_cartesian_trajectory(
                waypoints,
                vel_limits=config.vel_limits,
                acc_limits=config.acc_limits,
                blend_radius=blend_radius,
                n_samples=config.n_samples,
                n_blend=config.n_blend,
                cart_vel_cap=cart_cap,
                return_leg_times=True,
                sdot_start=sdot_start,
                sdot_end=sdot_end,
            )
        except Exception as e:
            raise PlanningError(step_ids[0], 3, str(e))

        if result is None:
            raise PlanningError(step_ids[0], 2, "IK failure along blended path")
        points, leg_end_times = result
        if not points:
            raise PlanningError(step_ids[0], 3, "empty trajectory")

        # TOPP computes real joint velocities from the parametrized
        # path, so read back the achieved boundary rather than assume
        # sdot_end landed exactly (mvc feasibility-clamps it).
        exit_qd = points[-1].qd if sdot_end is not None else None
        exit_qdd = points[-1].qdd if sdot_end is not None else None

        ranges = []
        t_cursor = 0.0
        for i, sid in enumerate(step_ids):
            t_end = leg_end_times[i]
            ranges.append((sid, t_cursor, t_end))
            t_cursor = t_end

        return points, ranges, q_final, exit_qd, exit_qdd