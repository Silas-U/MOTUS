"""
ready_pose.py — ROS-free search for a safe, well-conditioned "ready" pose.

Why this exists
---------------
A robot's spawn/home pose is often a stretched, singular pose (the Motus
builder spawns arms "upright and straight" to keep them off the floor).
Seeding IK from a singular pose makes the elbow/wrist branch arbitrary,
which shows up as sudden sweeps and elbow up/down flips. The planner
therefore moves the arm to a *ready* pose (bent, far from singularities)
before planning from it (see planner_core.plan_trajectory(ready_q=...)).

The builder writes `ready_pose` into robot.yaml for every robot it
generates (motus_cli/builder/safe_pose.py::choose_ready_pose). This module
is the runtime fallback for projects whose robot.yaml has no `ready_pose`
and whose `home_pose` is singular: arm_executor calls
find_ready_pose() once at startup.

The search routine below (search_ready_pose) is intentionally identical in
motus_cli/builder/safe_pose.py — keep the two in sync.
"""

from __future__ import annotations

import math
import random
from typing import Callable, Optional, Sequence, Tuple

import numpy as np

# Smallest singular value of the (length-scaled) Jacobian below which a
# pose is treated as singular. Healthy 6-DOF arm poses are ~0.15-0.5.
DEFAULT_SIGMA_MIN = 0.05

LIMIT_FRACTION = 0.8   # candidates stay within 80% of each joint's range
NEAR_BEST_FRACTION = 0.85
TOOL_DOWN_COS = 0.9    # tool z-axis within ~25 deg of straight down


def search_ready_pose(
    lo: Sequence[float],
    hi: Sequence[float],
    q_ref: Sequence[float],
    evaluate: Callable[[np.ndarray], Optional[Tuple[float, bool]]],
    n_samples: int = 800,
    seed: int = 0,
    near_frac: float = NEAR_BEST_FRACTION,
) -> Optional[Tuple[np.ndarray, float]]:
    """Pick a well-conditioned pose close to q_ref.

    evaluate(q) -> None if q is unacceptable (e.g. below the floor), else
    (sigma, tool_down) where sigma is the length-scaled Jacobian's smallest
    singular value and tool_down says the tool approach axis points down.

    Strategy: sample joint space uniformly inside [lo, hi]; keep the
    candidates whose sigma is within near_frac of the best seen; among
    those prefer tool-down poses (pick-and-place), then take the one with
    the smallest joint-space distance to q_ref so the pre-move is short.
    """
    lo = np.asarray(lo, dtype=float)
    hi = np.asarray(hi, dtype=float)
    q_ref = np.asarray(q_ref, dtype=float)
    rng = random.Random(seed)

    cands = []
    for _ in range(n_samples):
        q = np.array([rng.uniform(a, b) for a, b in zip(lo, hi)])
        r = evaluate(q)
        if r is None:
            continue
        cands.append((q, float(r[0]), bool(r[1])))
    if not cands:
        return None

    best = max(c[1] for c in cands)
    if best <= 0.0:
        return None
    short = [c for c in cands if c[1] >= near_frac * best]
    down = [c for c in short if c[2]]
    pool = down if down else short
    q, sigma, _ = min(pool, key=lambda c: float(np.linalg.norm(c[0] - q_ref)))
    return q, sigma


def find_ready_pose(
    kin,
    q_ref: Sequence[float],
    pos_limits: Optional[np.ndarray] = None,
    min_tcp_z: float = 0.10,
    n_samples: int = 800,
    seed: int = 0,
) -> Optional[Tuple[np.ndarray, float]]:
    """Runtime ready-pose search using a KinematicsFacade.

    pos_limits: (N, 2) joint limits; defaults to the model's own limits.
    Revolute ranges wider than 2*pi are folded to [-pi, pi]; every range is
    shrunk to LIMIT_FRACTION of its width about its midpoint.
    """
    n = kin.num_joints
    if pos_limits is None:
        q_min, q_max = kin.model.model.get_joint_limits_in_chain(
            kin.base_link, kin.tip_link)
        pos_limits = np.column_stack([q_min, q_max])
    limits = np.asarray(pos_limits, dtype=float).reshape(n, 2)

    lo, hi = [], []
    for a, b in limits:
        if not (math.isfinite(a) and math.isfinite(b)) or b - a > 2 * math.pi:
            a, b = -math.pi, math.pi
        mid, half = 0.5 * (a + b), 0.5 * (b - a) * LIMIT_FRACTION
        lo.append(mid - half)
        hi.append(mid + half)

    def evaluate(q):
        pose = kin.compute_fk(q)
        if pose is None:
            return None
        pose = np.asarray(pose, dtype=float)
        if not np.all(np.isfinite(pose)) or pose[2] < min_tcp_z:
            return None
        sigma = kin.min_singular_value(q)
        z_axis = _quat_z_axis(pose[3:7])
        return sigma, bool(z_axis[2] <= -TOOL_DOWN_COS)

    return search_ready_pose(lo, hi, q_ref, evaluate,
                             n_samples=n_samples, seed=seed)


def _quat_z_axis(q: np.ndarray) -> np.ndarray:
    x, y, z, w = q / max(np.linalg.norm(q), 1e-12)
    return np.array([
        2.0 * (x * z + w * y),
        2.0 * (y * z - w * x),
        1.0 - 2.0 * (x * x + y * y),
    ])
