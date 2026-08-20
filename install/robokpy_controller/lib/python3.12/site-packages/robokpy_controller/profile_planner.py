"""
profile_planner.py — quick profiling harness for planner_core.plan_trajectory

Wraps every KinematicsFacade call (solve_ik, compute_fk, shortest_equivalent,
get_fk_xyz) and the robokpy trajectory-generation entry points
(create_trajectory / create_general_scurve_joint_trajectory /
create_topp_blended_cartesian_trajectory) with wall-clock timers, then runs
plan_trajectory on a single leg and prints a per-call-site breakdown: call
count, total time, avg time, and % of the whole plan_trajectory call.

Goal: find out WHICH bucket owns the ~627ms before touching any algorithm.
Fill in the placeholders in __main__ to match your real node setup, then run.
"""

import time
import functools
from collections import defaultdict
import numpy as np

from robokpy_controller.planner_core import plan_trajectory, TrajectoryLeg
from robokpy_controller.mp_types import TrajectoryConfig
from robokpy_controller.mp_kinematics import KinematicsFacade


_stats = defaultdict(lambda: {"calls": 0, "total_s": 0.0})


def _timed(label):
    def deco(fn):
        @functools.wraps(fn)
        def wrapper(*args, **kwargs):
            t0 = time.perf_counter()
            try:
                return fn(*args, **kwargs)
            finally:
                dt = time.perf_counter() - t0
                _stats[label]["calls"] += 1
                _stats[label]["total_s"] += dt
        return wrapper
    return deco


def instrument(kin: KinematicsFacade):
    """Instance-level monkey-patch only — doesn't touch the class, so it's
    safe to call on a throwaway KinematicsFacade instance for profiling."""
    for name in ("solve_ik", "compute_fk", "shortest_equivalent", "get_fk_xyz"):
        if hasattr(kin, name):
            setattr(kin, name, _timed(f"kin.{name}")(getattr(kin, name)))

    tp = kin.traj_planner
    for name in (
        "create_trajectory",
        "create_general_scurve_joint_trajectory",
        "create_topp_blended_cartesian_trajectory",
        "_ik_chain",
    ):
        if hasattr(tp, name):
            setattr(tp, name, _timed(f"traj_planner.{name}")(getattr(tp, name)))


def reset_stats():
    """Clear accumulated timing stats. Call before each plan_trajectory
    call you want an isolated (not cumulative) breakdown for."""
    _stats.clear()


def report(total_s: float, logger=None):
    """Prints the breakdown via logger.info() (one line per row) when a
    ROS logger is passed — matches how the rest of arm_executor's output
    is captured/viewed. Falls back to print() when logger is None (e.g.
    running profile_single_leg standalone outside ROS)."""
    emit = logger.info if logger is not None else print

    emit(f"[plan-profile] {'call site':40s} {'count':>6s} {'total ms':>10s} {'avg ms':>9s} {'% of total':>11s}")
    for label, s in sorted(_stats.items(), key=lambda kv: -kv[1]["total_s"]):
        total_ms = s["total_s"] * 1000
        avg_ms = total_ms / s["calls"] if s["calls"] else 0.0
        pct = (s["total_s"] / total_s * 100) if total_s else 0.0
        emit(f"[plan-profile] {label:40s} {s['calls']:6d} {total_ms:10.2f} {avg_ms:9.3f} {pct:10.1f}%")
    accounted = sum(s["total_s"] for s in _stats.values())
    unaccounted = total_s - accounted
    emit(f"[plan-profile] TOTAL (measured buckets):    {accounted*1000:.2f} ms")
    emit(f"[plan-profile] TOTAL (wall clock):           {total_s*1000:.2f} ms")
    emit(f"[plan-profile] Unaccounted (bookkeeping/py): {unaccounted*1000:.2f} ms")


def profile_single_leg(kin, config, q_seed, target_pose,
                        traj_method="js", traj_type="scurve", n_runs=5):
    """Runs plan_trajectory n_runs times on a single-leg plan and reports
    per-call-site timing each run. Run 1 often includes one-off cold-start
    cost (lazy-init / first-call JIT inside robokpy) that won't repeat on
    later legs — comparing run 1 vs run 2+ tells you whether cold start is
    inflating your single-leg baseline vs. a real per-call cost."""
    leg = TrajectoryLeg(
        step_id="profile_leg",
        target_pose=target_pose,
        traj_method=traj_method,
        traj_type=traj_type,
        blend_radius=0.0,
    )

    instrument(kin)

    for i in range(n_runs):
        _stats.clear()
        t0 = time.perf_counter()
        plan_trajectory([leg], q_seed, config, kin)
        total_s = time.perf_counter() - t0
        print(f"\n=== run {i + 1}/{n_runs} — wall clock: {total_s * 1000:.2f} ms ===")
        report(total_s)


if __name__ == "__main__":
    # --- fill these in to match your actual node startup ---
    # kin = KinematicsFacade(...)        # however trajectory_generator_node builds it
    # config = TrajectoryConfig(...)     # your real vel/acc/jerk limits etc.
    # q_seed = np.array([...])           # current joint state (radians)
    # target_pose = np.array([x, y, z, qx, qy, qz, qw])
    #
    # profile_single_leg(kin, config, q_seed, target_pose)
    raise SystemExit(
        "Fill in kin/config/q_seed/target_pose below to match your real "
        "node setup, then re-run."
    )