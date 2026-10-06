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

# ---------------------------------------------------------------------------
# READY POSE
#
# home_pose (above) is the SPAWN pose: upright and stretched, i.e. a
# singularity. Motus also seeds IK from home_pose, and from a singular seed the
# elbow/wrist branch is arbitrary -- which is the "sudden sweep / elbow
# up<->down flip" failure. So every generated robot.yaml also gets a
# `ready_pose`: a bent, well-conditioned pose near the spawn pose. The
# executor uses it as the IK seed / preferred posture and, when a plan starts
# from a singular pose, first moves the arm there in joint space (see
# robokpy_controller/planner_core.py). robokpy_controller/ready_pose.py
# derives one at runtime if a project's robot.yaml has none -- keep the search
# routine below in sync with it.
# ---------------------------------------------------------------------------

READY_SIGMA_MIN = 0.05        # same threshold the runtime uses (length-scaled Jacobian)
READY_NEAR_BEST = 0.85        # accept candidates within this fraction of the best sigma
READY_TOOL_DOWN_COS = 0.9     # prefer tool z-axis within ~25 deg of straight down
READY_SAMPLES = 3000
READY_ELBOW_UP_FRAC = 0.05    # elbow >= this fraction of the arm length above the shoulder-wrist line
READY_FORWARD_FRAC = 0.10     # tool >= this fraction of the arm length in FRONT of the base


def _chain_jacobian(chain, q_by_joint):
    """(lowest joint-frame z, tip z, tip z-axis, 6xN Jacobian, characteristic
    length, elbow height) for a pose, in the base frame. Elbow height is the
    signed height of joint 3's origin above the line joint 2 -> joint 5
    (shoulder -> wrist centre): > 0 is elbow-up, 0.0 for chains under 5 joints. numpy imported lazily so the rest
    of the builder doesn't depend on it."""
    import numpy as np
    T = np.eye(4)
    cols, started = [], False
    lowest, length = math.inf, 0.0
    for j in chain:
        Tj = np.array(j["T"], dtype=float)
        length += float(np.linalg.norm(Tj[:3, 3]))
        T = T @ Tj
        if j["type"] in ("revolute", "continuous", "prismatic"):
            started = True
            ax = np.array(j["axis"], dtype=float)
            ax = ax / (np.linalg.norm(ax) or 1.0)
            cols.append((j["type"], T[:3, :3] @ ax, T[:3, 3].copy()))
            q = q_by_joint.get(j["name"], 0.0)
            if j["type"] == "prismatic":
                step = np.eye(4)
                step[:3, 3] = ax * q
            else:
                step = np.array(_axis_rotation(j["axis"], q), dtype=float)
            T = T @ step
        if started:
            lowest = min(lowest, T[2, 3])
    p_tip = T[:3, 3]
    J = np.zeros((6, len(cols)))
    for k, (typ, axis_w, origin_w) in enumerate(cols):
        if typ == "prismatic":
            J[:3, k] = axis_w
        else:
            J[:3, k] = np.cross(axis_w, p_tip - origin_w)
            J[3:, k] = axis_w
    elbow_h = 0.0
    if len(cols) >= 5:
        sh, el, wr = cols[1][2], cols[2][2], cols[4][2]
        d = wr - sh
        dd = float(np.dot(d, d))
        if dd > 1e-12:
            elbow_h = float((el - (sh + float(np.dot(el - sh, d)) / dd * d))[2])
    return ((lowest if started else math.inf), float(T[2, 3]), T[:3, 2].copy(), J,
            max(length, 1e-3), elbow_h)


def _tip_xy(chain, q_by_joint):
    """Tip (x, y) in the base frame (plain FK; numpy imported lazily)."""
    import numpy as np
    T = np.eye(4)
    for j in chain:
        T = T @ np.array(j["T"], dtype=float)
        if j["type"] in ("revolute", "continuous"):
            T = T @ np.array(_axis_rotation(j["axis"], q_by_joint.get(j["name"], 0.0)), dtype=float)
        elif j["type"] == "prismatic":
            step = np.eye(4)
            ax = np.array(j["axis"], dtype=float)
            step[:3, 3] = ax / (np.linalg.norm(ax) or 1.0) * q_by_joint.get(j["name"], 0.0)
            T = T @ step
    return T[:2, 3].copy()


def _forward_reach(chain, joint_names, q):
    """Tip distance along the arm's forward direction (where it points when
    stretched out, all joints 0, after rotating only joint 1 to q[0]).
    +inf when undetermined. Negative = tool behind the base."""
    import numpy as np
    f = _tip_xy(chain, {joint_names[0]: q[0]})
    n = float(np.linalg.norm(f))
    if n < 1e-6:
        return math.inf
    return float(np.dot(_tip_xy(chain, dict(zip(joint_names, q))), f / n))


def _search_ready_pose(lo, hi, q_ref, evaluate, n_samples=READY_SAMPLES, seed=_SEED,
                      near_frac=READY_NEAR_BEST):
    """Well-conditioned pose near q_ref. IDENTICAL in intent to
    robokpy_controller.ready_pose.search_ready_pose (keep in sync).
    evaluate(q) -> None | (sigma, tool_down, elbow_up). Elbow-up poses only
    (unless there are none): elbow-down collides with the base/table and the
    ready pose is also the IK posture bias."""
    import numpy as np
    rng = random.Random(seed)
    q_ref = np.asarray(q_ref, dtype=float)
    cands = []
    for _ in range(n_samples):
        q = np.array([rng.uniform(a, b) for a, b in zip(lo, hi)])
        r = evaluate(q)
        if r is not None:
            cands.append((q, float(r[0]), bool(r[1]), bool(r[2]) if len(r) > 2 else True))
    if not cands:
        return None
    cands = [c for c in cands if c[3]] or cands
    best = max(c[1] for c in cands)
    if best <= 0.0:
        return None
    short = [c for c in cands if c[1] >= near_frac * best]
    pool = [c for c in short if c[2]] or short
    q, sigma, tool_down, elbow_up = min(
        pool, key=lambda c: float(np.linalg.norm(c[0] - q_ref)))
    # Pull each joint back toward q_ref where that costs nothing (e.g. the
    # base pan does not affect conditioning or the elbow), so the pre-move is
    # short instead of an arbitrary sweep. Accept only if still valid,
    # still well-conditioned, still elbow-up and still tool-down.
    for j in range(len(q)):
        q2 = q.copy()
        q2[j] = q_ref[j]
        r = evaluate(q2)
        if r is None or float(r[0]) < near_frac * best:
            continue
        if elbow_up and not (bool(r[2]) if len(r) > 2 else True):
            continue
        if tool_down and not bool(r[1]):
            continue
        q, sigma = q2, float(r[0])
    return q, sigma


def choose_ready_pose(expanded_xml: str, base_link: str, tip_link: str,
                      joint_names: list[str],
                      home_pose: list[float] | None = None) -> tuple[list[float] | None, str | None]:
    """Returns (ready_pose in joint_names order, note or None). ready_pose is
    None (with a note) if one can't be derived -- the runtime then derives its
    own if home_pose is singular.

    Criteria: above the floor (every joint frame and the tip), inside 80% of
    each joint's range, smallest singular value of the length-scaled Jacobian
    within 85% of the best found, tool pointing down if possible, and as
    close to home_pose as those allow (short first move)."""
    try:
        import numpy as np
    except ImportError:
        return None, "ready_pose: numpy not available; the runtime will derive one if home_pose is singular"
    try:
        chain = _parse_chain(expanded_xml, base_link, tip_link)
    except ET.ParseError:
        chain = None
    if not chain:
        return None, "ready_pose: could not rebuild the kinematic chain; the runtime will derive one"
    by_name = {j["name"]: j for j in chain}
    if any(n not in by_name for n in joint_names):
        return None, "ready_pose: chain joints don't match the analysis; the runtime will derive one"

    lo, hi = [], []
    for n in joint_names:
        j = by_name[n]
        a = j["lo"] if j["lo"] is not None else -math.pi
        b = j["hi"] if j["hi"] is not None else math.pi
        if j["type"] == "continuous" or b - a > 2 * math.pi:
            a, b = -math.pi, math.pi
        mid, half = (a + b) / 2, (b - a) / 2 * LIMIT_FRACTION
        lo.append(mid - half)
        hi.append(mid + half)

    required = min(TARGET_CLEARANCE, _first_pivot_z(chain)) - 1e-6
    q_ref = list(home_pose) if home_pose and len(home_pose) == len(joint_names) else [0.0] * len(joint_names)

    def evaluate(q):
        lowest, tip_z, z_axis, J, length, elbow_h = _chain_jacobian(chain, dict(zip(joint_names, q)))
        if lowest < required or tip_z < required:
            return None
        scale = np.array([1.0 / length] * 3 + [1.0] * 3)
        sigma = float(np.linalg.svd(scale[:, None] * J, compute_uv=False)[-1]) if J.shape[1] else 0.0
        # "elbow up" must hold on the working side: a pose reaching behind
        # the base can be elbow-up there yet leads into elbow-down in front.
        elbow_up = (elbow_h >= READY_ELBOW_UP_FRAC * length
                    and _forward_reach(chain, joint_names, q) >= READY_FORWARD_FRAC * length)
        return sigma, bool(z_axis[2] <= -READY_TOOL_DOWN_COS), bool(elbow_up)

    found = _search_ready_pose(lo, hi, q_ref, evaluate)
    if found is None or found[1] < READY_SIGMA_MIN:
        return None, ("ready_pose: no well-conditioned pose above the ground plane was found; "
                      "set ready_pose in robot.yaml by hand (a bent, non-singular pose)")
    q, sigma = found
    ready = [round(float(v), 4) + 0.0 for v in q]
    note = ("ready_pose: a bent, well-conditioned pose near home_pose; used as the IK seed and as the safe "
            "pose the arm moves to before planning when it starts from the singular home_pose. Verify it is "
            "clear of your cell before running on hardware.")
    return ready, note
