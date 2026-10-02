"""
safe_pose.py

Chooses the `home_pose` written into a generated project's robot.yaml, which
is ALSO the pose Gazebo spawns the arm in (see ros2_control_injector.py's
`initial_value` / arm.launch.py's `home_pose` xacro mapping).

POLICY: every arm starts UPRIGHT and STRAIGHT -- the pose that puts the joint
frames (summed) as high as the joint limits allow (the arm standing "like a candle"),
tidied so redundant joints sit at 0 and the others at clean multiples of
pi/2 where that costs <3% of the height. This also keeps the whole arm well
clear of the ground plane. (All-zeros was the old default; it spawned a
UR5's wrist BELOW the ground plane -- its shoulder is only 0.089 m up -- and
dartsim crawled at ~0.02x real time solving that contact every step.)

KINEMATICS ONLY (joint frames, not collision geometry). Two things to know:
  * a straight, upright arm is usually a kinematic SINGULARITY (elbow fully
    extended). home_pose is also the IK seed, so if IK from the start pose
    misbehaves, set a slightly bent home_pose in robot.yaml;
  * if the chain can't be evaluated this falls back to all zeros + a warning.
"""
from __future__ import annotations

import math
import random
import xml.etree.ElementTree as ET

TARGET_CLEARANCE = 0.10     # m: lowest joint frame must be at least this high (capped at the base pivot height)
LIMIT_FRACTION = 0.8        # poses stay within 80% of each joint's range
HEIGHT_TOLERANCE = 0.03     # tidying may give up this fraction of the maximum summed joint-frame height
_SAMPLES = 3000
_SEED = 0


def _mat_mul(a, b):
    return [[sum(a[i][k] * b[k][j] for k in range(4)) for j in range(4)] for i in range(4)]


def _origin_matrix(xyz, rpy):
    r, p, y = rpy
    cr, sr, cp, sp, cy, sy = math.cos(r), math.sin(r), math.cos(p), math.sin(p), math.cos(y), math.sin(y)
    return [
        [cy * cp, cy * sp * sr - sy * cr, cy * sp * cr + sy * sr, xyz[0]],
        [sy * cp, sy * sp * sr + cy * cr, sy * sp * cr - cy * sr, xyz[1]],
        [-sp,     cp * sr,                cp * cr,                xyz[2]],
        [0.0, 0.0, 0.0, 1.0],
    ]


def _axis_rotation(axis, q):
    x, y, z = axis
    n = math.sqrt(x * x + y * y + z * z) or 1.0
    x, y, z = x / n, y / n, z / n
    c, s, t = math.cos(q), math.sin(q), 1 - math.cos(q)
    return [
        [t * x * x + c,     t * x * y - s * z, t * x * z + s * y, 0.0],
        [t * x * y + s * z, t * y * y + c,     t * y * z - s * x, 0.0],
        [t * x * z - s * y, t * y * z + s * x, t * z * z + c,     0.0],
        [0.0, 0.0, 0.0, 1.0],
    ]


def _floats(text, default):
    try:
        v = [float(t) for t in (text or "").split()]
        return v if len(v) == 3 else default
    except ValueError:
        return default


def _parse_chain(expanded_xml: str, base_link: str, tip_link: str):
    """Ordered joints base->tip as dicts, or None if the chain can't be built."""
    root = ET.fromstring(expanded_xml)
    by_child = {}
    for j in root.iter("joint"):
        child, parent = j.find("child"), j.find("parent")
        if child is None or parent is None:
            continue
        o, a, lim = j.find("origin"), j.find("axis"), j.find("limit")
        by_child[child.get("link")] = {
            "name": j.get("name"), "type": j.get("type"), "parent": parent.get("link"),
            "T": _origin_matrix(_floats(o.get("xyz") if o is not None else None, [0.0] * 3),
                                _floats(o.get("rpy") if o is not None else None, [0.0] * 3)),
            "axis": _floats(a.get("xyz") if a is not None else None, [1.0, 0.0, 0.0]),
            "lo": float(lim.get("lower")) if lim is not None and lim.get("lower") is not None else None,
            "hi": float(lim.get("upper")) if lim is not None and lim.get("upper") is not None else None,
        }
    chain, link = [], tip_link
    while link != base_link:
        j = by_child.get(link)
        if j is None:
            return None
        chain.append(j)
        link = j["parent"]
    chain.reverse()
    return chain


def _eval(chain, q_by_joint) -> tuple[float, float]:
    """(lowest joint-frame z from the first movable joint outward, tip-frame z,
    sum of those joint-frame z's -- the "how upright is the WHOLE arm" measure)."""
    T = [[1.0 if i == j else 0.0 for j in range(4)] for i in range(4)]
    lowest, started, total = math.inf, False, 0.0
    for j in chain:
        T = _mat_mul(T, j["T"])
        if j["type"] in ("revolute", "continuous", "prismatic"):
            started = True
            q = q_by_joint.get(j["name"], 0.0)
            T = _mat_mul(T, _axis_rotation(j["axis"], q) if j["type"] != "prismatic" else
                         [[1, 0, 0, j["axis"][0] * q], [0, 1, 0, j["axis"][1] * q],
                          [0, 0, 1, j["axis"][2] * q], [0, 0, 0, 1]])
        if started:
            lowest = min(lowest, T[2][3])
            total += T[2][3]
    return (lowest if started else math.inf), T[2][3], total


def _min_frame_z(chain, q_by_joint) -> float:
    return _eval(chain, q_by_joint)[0]


def _first_pivot_z(chain) -> float:
    """z of the first movable joint's child frame (independent of that joint's q
    for a vertical-axis base joint; the arm's base-side pivot height)."""
    T = [[1.0 if i == j else 0.0 for j in range(4)] for i in range(4)]
    for j in chain:
        T = _mat_mul(T, j["T"])
        if j["type"] in ("revolute", "continuous", "prismatic"):
            return T[2][3]
    return math.inf


def choose_home_pose(expanded_xml: str, base_link: str, tip_link: str,
                     joint_names: list[str]) -> tuple[list[float], str | None]:
    """Returns (home_pose in joint_names order, note or None). Falls back to all
    zeros (with an explanatory note) if the chain can't be evaluated."""
    zeros = [0.0] * len(joint_names)
    try:
        chain = _parse_chain(expanded_xml, base_link, tip_link)
    except ET.ParseError:
        chain = None
    if not chain:
        return zeros, "home_pose: could not rebuild the kinematic chain from the description; using all zeros"

    by_name = {j["name"]: j for j in chain}
    if any(n not in by_name for n in joint_names):
        return zeros, "home_pose: chain joints don't match the analysis; using all zeros"

    ranges = []
    for n in joint_names:
        j = by_name[n]
        lo = j["lo"] if j["lo"] is not None else -math.pi
        hi = j["hi"] if j["hi"] is not None else math.pi
        if j["type"] == "continuous" or hi - lo > 2 * math.pi:
            lo, hi = -math.pi, math.pi
        mid, half = (lo + hi) / 2, (hi - lo) / 2 * LIMIT_FRACTION
        ranges.append((max(lo, mid - half), min(hi, mid + half)))

    # Floor clearance can't exceed the base-side pivot height (a UR5's shoulder
    # is fixed 0.089 m up), so cap the requirement there.
    required = min(TARGET_CLEARANCE, _first_pivot_z(chain)) - 1e-6

    def score(q):
        lowest, _tip, total = _eval(chain, dict(zip(joint_names, q)))
        return total if lowest >= required else -math.inf

    rng = random.Random(_SEED)
    best = [min(max(0.0, lo), hi) for lo, hi in ranges]
    best_s = score(best)
    for _ in range(_SAMPLES):
        q = [rng.uniform(lo, hi) for lo, hi in ranges]
        sc = score(q)
        if sc > best_s:
            best, best_s = q, sc
    if best_s == -math.inf:
        return zeros, ("home_pose: no pose with every joint frame above the ground plane was found; "
                       "using all zeros -- set home_pose in robot.yaml by hand")

    # Coordinate ascent on the summed joint-frame height, shrinking steps.
    for step in (0.5, 0.25, 0.1, 0.05, 0.02, 0.01, 0.005):
        improved = True
        while improved:
            improved = False
            for k, (lo, hi) in enumerate(ranges):
                for d in (step, -step):
                    q = list(best)
                    q[k] = min(max(q[k] + d, lo), hi)
                    sc = score(q)
                    if sc > best_s + 1e-9:
                        best, best_s, improved = q, sc, True

    # Tidy: pull each joint to the nearest "clean" value (0, then multiples of
    # pi/2) that gives up at most HEIGHT_TOLERANCE of the maximum tip height.
    floor = best_s - max(1e-3, HEIGHT_TOLERANCE * abs(best_s))
    for _ in range(2):
        for k, (lo, hi) in enumerate(ranges):
            cands = sorted({0.0, *(m * math.pi / 2 for m in range(-4, 5))}, key=abs)
            for c in [v for v in cands if lo - 1e-9 <= v <= hi + 1e-9] + [best[k]]:
                q = list(best)
                q[k] = c
                if score(q) >= floor:
                    best = q
                    break
    best = [round(v, 4) + 0.0 for v in best]
    lowest, tip, _ = _eval(chain, dict(zip(joint_names, best)))
    note = (f"home_pose: arms spawn UPRIGHT and straight (tip frame {tip:.2f} m high, lowest joint "
            f"frame {lowest:.2f} m). It is a stretched, near-singular pose and the IK seed -- if IK "
            f"misbehaves from the start, set a slightly bent home_pose in robot.yaml.")
    return best, note