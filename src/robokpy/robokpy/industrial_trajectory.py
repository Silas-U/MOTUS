"""
Author: Silas Udofia
GitHub: https://github.com/Silas-U/RoboKpy/tree/main

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0

Industrial-grade trajectory generation, built on top of trajectory.py's
TrajectoryPlanner. Adds four capabilities standard on FANUC/KUKA/ABB/UR
controllers that the original planner did not have:

  1. Jerk-limited (7-segment S-curve) joint moves, multi-axis synchronized.
  2. Whole-path time-optimal parametrization (TOPP: forward/backward
     reachability analysis under joint vel+accel limits, à la Pham's
     TOPP-RA) instead of independent per-segment timing.
  3. Velocity/acceleration-continuous corner blending "for free": TOPP is
     run over the already-geometrically-blended path, so it naturally
     decelerates through tight curvature and re-accelerates on straights
     -- no separate seam-matching logic needed within one trajectory call.
  4. Circular and helical Cartesian arc primitives (3-point, center-radius,
     helix), IK-chained and then time-optimally parametrized like any
     other Cartesian path.

IndustrialTrajectoryPlanner subclasses TrajectoryPlanner, so every
existing method (lspb, blend, spline, etc.) still works unchanged; this
file is additive.

PLACEMENT: robokpy/trajectory.py  (replaces/extends your existing core file)
"""

import numpy as np
from dataclasses import dataclass
from typing import List, Optional, Tuple
from scipy.spatial.transform import Rotation as R, Slerp
from scipy.signal import savgol_filter

# NOTE: If your base TrajectoryPlanner lives in a separate submodule,
# change this line to:
#   from .trajectory_base import TrajectoryPlanner, TrajectoryPoint
# In the standard Motus layout both classes are available from robokpy.
try:
    from .trajectory import TrajectoryPlanner, TrajectoryPoint
except ImportError:
    from trajectory import TrajectoryPlanner, TrajectoryPoint


# =========================================================
# 1. JERK-LIMITED S-CURVE (7-SEGMENT) SCALAR PROFILE
# =========================================================
#
# Standard trapezoidal-jerk point-to-point profile (v0 = vf = 0),
# per Biagiotti & Melchiorri's canonical construction. Handles all
# three physical cases automatically: full profile (amax and vmax both
# reached), reduced-vmax profile (amax reached, vmax not), and the
# short-move cubic profile (neither amax nor vmax reached).

def _scurve_profile_params(h: float, vmax: float, amax: float, jmax: float) -> dict:
    h = float(h)
    if h <= 1e-12:
        return dict(Tj=0.0, Ta=0.0, Tv=0.0, Td=0.0, vlim=0.0, alim=0.0, T=0.0)

    vmax, amax, jmax = float(vmax), float(amax), float(jmax)

    if (vmax * jmax) < (amax ** 2):
        Tj = np.sqrt(vmax / jmax)
        Ta = 2 * Tj
        alim = jmax * Tj
    else:
        Tj = amax / jmax
        Ta = Tj + vmax / amax
        alim = amax
    Td = Ta

    sa = 0.5 * vmax * Ta
    sd = 0.5 * vmax * Td

    if sa + sd <= h:
        vlim = vmax
        Tv = (h - sa - sd) / vmax
    else:
        Tv = 0.0
        a_, b_, c_ = 1.0 / amax, amax / jmax, -h
        v = (-b_ + np.sqrt(b_ ** 2 - 4 * a_ * c_)) / (2 * a_)
        if v * jmax >= amax ** 2 - 1e-9:
            Tj = amax / jmax
            Ta = Tj + v / amax
            alim = amax
        else:
            v = (h * np.sqrt(jmax) / 2.0) ** (2.0 / 3.0)
            Tj = np.sqrt(v / jmax)
            Ta = 2 * Tj
            alim = jmax * Tj
        vlim = v
        Td = Ta

    T = Ta + Tv + Td
    return dict(Tj=Tj, Ta=Ta, Tv=Tv, Td=Td, vlim=vlim, alim=alim, T=T)


def _scurve_eval(t: float, h: float, p: dict) -> Tuple[float, float, float]:
    """Returns (s, v, a) at time t for a 0 -> h S-curve move."""
    Tj, Ta, Tv, Td = p['Tj'], p['Ta'], p['Tv'], p['Td']
    vlim, alim, T = p['vlim'], p['alim'], p['T']
    if T <= 1e-12:
        return 0.0, 0.0, 0.0
    t = np.clip(t, 0.0, T)
    jmax = alim / Tj if Tj > 1e-12 else 0.0

    if t <= Tj:
        a = jmax * t
        v = 0.5 * jmax * t ** 2
        s = jmax * t ** 3 / 6.0
    elif t <= Ta - Tj:
        tau = t - Tj
        a = alim
        v0 = 0.5 * jmax * Tj ** 2
        v = v0 + alim * tau
        s0 = jmax * Tj ** 3 / 6.0
        s = s0 + v0 * tau + 0.5 * alim * tau ** 2
    elif t <= Ta:
        tau = Ta - t
        a = jmax * tau
        v = vlim - 0.5 * jmax * tau ** 2
        sa = 0.5 * vlim * Ta
        s = sa - (vlim * tau - jmax * tau ** 3 / 6.0)
    elif t <= Ta + Tv:
        tau = t - Ta
        a = 0.0
        v = vlim
        sa = 0.5 * vlim * Ta
        s = sa + vlim * tau
    elif t <= Ta + Tv + Tj:
        tau = t - (Ta + Tv)
        a = -jmax * tau
        v = vlim - 0.5 * jmax * tau ** 2
        sa = 0.5 * vlim * Ta
        s = sa + vlim * Tv + vlim * tau - jmax * tau ** 3 / 6.0
    elif t <= Ta + Tv + Td - Tj:
        tau = t - (Ta + Tv + Tj)
        a = -alim
        v1 = vlim - 0.5 * jmax * Tj ** 2
        sa = 0.5 * vlim * Ta
        s1 = sa + vlim * Tv + (vlim * Tj - jmax * Tj ** 3 / 6.0)
        v = v1 - alim * tau
        s = s1 + v1 * tau - 0.5 * alim * tau ** 2
    else:
        tau = (Ta + Tv + Td) - t
        a = -jmax * tau
        v = 0.5 * jmax * tau ** 2
        s = h - (jmax * tau ** 3 / 6.0)

    return float(s), float(v), float(a)


def _scurve_duration(h, vmax, amax, jmax):
    return _scurve_profile_params(h, vmax, amax, jmax)['T']


def _scurve_time_scaled(h, T_target, vmax_bound, amax, jmax, iters=60):
    """
    Bisect for a reduced vmax (<= vmax_bound) so this joint's S-curve
    profile takes exactly T_target seconds -- the multi-axis
    synchronization step ("slowest joint sets the pace").
    """
    h = abs(float(h))
    if h <= 1e-12 or T_target <= 1e-9:
        return _scurve_profile_params(h, vmax_bound, amax, jmax)
    T_min = _scurve_duration(h, vmax_bound, amax, jmax)
    if T_target <= T_min + 1e-9:
        return _scurve_profile_params(h, vmax_bound, amax, jmax)
    lo, hi = 1e-9, vmax_bound
    for _ in range(iters):
        mid = 0.5 * (lo + hi)
        Tm = _scurve_duration(h, mid, amax, jmax)
        if Tm > T_target:
            lo = mid
        else:
            hi = mid
    return _scurve_profile_params(h, hi, amax, jmax)


# =========================================================
# 2. TOPP -- WHOLE-PATH TIME-OPTIMAL PARAMETRIZATION
# =========================================================

def _topp_parametrize(q_path: np.ndarray,
                       vel_limits: np.ndarray,
                       acc_limits: np.ndarray,
                       extra_vel_cap: Optional[np.ndarray] = None) -> dict:
    """
    Numerical TOPP via forward/backward reachability analysis (the same
    physical idea as Pham's TOPP-RA, without the LP -- a closed-form
    per-sample accel bound is used instead, which is exact for this
    "one active constraint at a time" formulation).

    q_path : (M, n_joints) dense geometric path (e.g. an already
             corner-blended raw position list).
    Returns dict with s, sdot, t (cumulative time), q, qd, qdd -- all
    length M, resampled onto physically-consistent timing.
    """
    q_path = np.asarray(q_path, dtype=float)
    M, n = q_path.shape
    if M < 2:
        raise ValueError("TOPP needs at least 2 path samples")

    # ---- FIX: guard against short paths for Savitzky-Golay ----
    if M < 5:
        s_old = np.linspace(0.0, 1.0, M)
        s_new = np.linspace(0.0, 1.0, 5)
        q_path = np.stack([np.interp(s_new, s_old, q_path[:, j]) for j in range(n)], axis=1)
        M = 5
    # -----------------------------------------------------------

    s = np.linspace(0.0, 1.0, M)
    ds = s[1] - s[0]

    window = min(M - (1 - M % 2), 21)  # odd, <= M
    if window < 5:
        window = 5 if M >= 5 else (M if M % 2 == 1 else M - 1)
    polyorder = min(3, window - 1)
    dqds = savgol_filter(q_path, window, polyorder, deriv=1, delta=ds, axis=0)
    d2qds2 = savgol_filter(q_path, window, polyorder, deriv=2, delta=ds, axis=0)

    with np.errstate(divide='ignore', invalid='ignore'):
        per_joint_cap = np.where(np.abs(dqds) > 1e-9,
                                  vel_limits[None, :] / np.abs(dqds), np.inf)
    mvc_vel = np.minimum(np.min(per_joint_cap, axis=1), 1e6)

    with np.errstate(divide='ignore', invalid='ignore'):
        per_joint_curv_cap = np.where(np.abs(d2qds2) > 1e-9,
                                       np.sqrt(acc_limits[None, :] / np.abs(d2qds2)),
                                       np.inf)
    mvc_curv = np.minimum(np.min(per_joint_curv_cap, axis=1), 1e6)
    mvc = np.minimum(mvc_vel, mvc_curv)

    if extra_vel_cap is not None:
        mvc = np.minimum(mvc, np.asarray(extra_vel_cap, dtype=float))

    def accel_bounds(i, sdot):
        dq, d2q = dqds[i], d2qds2[i]
        base = -d2q * sdot ** 2
        with np.errstate(divide='ignore', invalid='ignore'):
            upper = np.where(dq > 1e-9, (acc_limits + base) / dq,
                     np.where(dq < -1e-9, (-acc_limits + base) / dq, np.inf))
            lower = np.where(dq > 1e-9, (-acc_limits + base) / dq,
                     np.where(dq < -1e-9, (acc_limits + base) / dq, -np.inf))
        return float(np.min(upper)), float(np.max(lower))

    sdot_f = np.zeros(M)
    for i in range(M - 1):
        sddot_max, sddot_min = accel_bounds(i, sdot_f[i])
        sddot_max = max(sddot_max, sddot_min, 1e-6)
        sdot_f[i + 1] = min(np.sqrt(max(sdot_f[i] ** 2 + 2 * sddot_max * ds, 0.0)),
                             mvc[i + 1])

    sdot_b = np.zeros(M)
    for i in range(M - 1, 0, -1):
        sddot_max, sddot_min = accel_bounds(i, sdot_b[i])
        decel_mag = max(-sddot_min, -sddot_max, 1e-6)
        sdot_b[i - 1] = min(np.sqrt(max(sdot_b[i] ** 2 + 2 * decel_mag * ds, 0.0)),
                             mvc[i - 1])

    sdot = np.minimum(np.minimum(sdot_f, sdot_b), mvc)
    sdot = np.maximum(sdot, 1e-6)
    sdot[0] = 0.0
    sdot[-1] = 0.0

    denom = np.maximum(sdot[:-1] + sdot[1:], 1e-6)
    dt = 2.0 * ds / denom
    t = np.concatenate([[0.0], np.cumsum(dt)])

    sddot_step = (sdot[1:] ** 2 - sdot[:-1] ** 2) / (2.0 * ds)
    sddot = np.empty(M)
    sddot[0] = sddot_step[0]
    sddot[-1] = sddot_step[-1]
    sddot[1:-1] = 0.5 * (sddot_step[:-1] + sddot_step[1:])

    qd = dqds * sdot[:, None]
    qdd = d2qds2 * (sdot[:, None] ** 2) + dqds * sddot[:, None]

    return dict(s=s, sdot=sdot, t=t, q=q_path, qd=qd, qdd=qdd)


# =========================================================
# 3. CIRCULAR / HELICAL ARC GEOMETRY
# =========================================================

def _arc_from_3points(p1, p2, p3):
    p1, p2, p3 = (np.asarray(p, dtype=float) for p in (p1, p2, p3))
    v1, v2 = p2 - p1, p3 - p1
    normal = np.cross(v1, v2)
    nnorm = np.linalg.norm(normal)
    if nnorm < 1e-9:
        raise ValueError("[arc_from_3points] points are collinear -- no unique circle")
    normal = normal / nnorm

    u = v1 / np.linalg.norm(v1)
    w = np.cross(normal, u)
    b = np.array([np.dot(v1, u), np.dot(v1, w)])
    c = np.array([np.dot(v2, u), np.dot(v2, w)])
    bx, by, cx, cy = *b, *c
    d = 2 * (bx * cy - by * cx)
    if abs(d) < 1e-12:
        raise ValueError("[arc_from_3points] points are collinear -- no unique circle")
    ux = (cy * (bx ** 2 + by ** 2) - by * (cx ** 2 + cy ** 2)) / d
    uy = (bx * (cx ** 2 + cy ** 2) - cx * (bx ** 2 + by ** 2)) / d

    center = p1 + ux * u + uy * w
    radius = np.linalg.norm(center - p1)
    u_out = (p1 - center) / radius
    v_out = np.cross(normal, u_out)
    return center, radius, normal, u_out, v_out


def _bezier_corner_blend(q_entry, q_corner, q_exit, n_blend):
    t = np.linspace(0.0, 1.0, n_blend)[:, None]
    return (1 - t) ** 2 * q_entry + 2 * t * (1 - t) * q_corner + t ** 2 * q_exit


def _sample_arc(center, radius, normal, u, v, start_angle, end_angle,
                 n_samples, pitch=0.0, ccw=True):
    if ccw and end_angle < start_angle:
        end_angle += 2 * np.pi
    elif not ccw and end_angle > start_angle:
        end_angle -= 2 * np.pi

    thetas = np.linspace(start_angle, end_angle, n_samples)
    axial = (thetas - start_angle) / (2 * np.pi) * pitch
    return (center[None, :]
            + radius * (np.cos(thetas)[:, None] * u[None, :]
                        + np.sin(thetas)[:, None] * v[None, :])
            + axial[:, None] * normal[None, :])



# =========================================================
# MODULE-LEVEL RESAMPLER (used by pipeline + class alias)
# =========================================================

def _resample_uniform_arclength(raw_positions, n_samples=None, aux_arrays=None):
    q = np.asarray(raw_positions, dtype=float)
    if n_samples is None:
        n_samples = len(q)
    dist = np.linalg.norm(np.diff(q, axis=0), axis=1)
    arc = np.insert(np.cumsum(dist), 0, 0.0)
    total = arc[-1]
    if total < 1e-9:
        out_aux = aux_arrays if aux_arrays is not None else None
        return (q, out_aux) if aux_arrays is not None else q
    s_uniform = np.linspace(0, total, n_samples)
    out = np.zeros((n_samples, q.shape[1]))
    for j in range(q.shape[1]):
        out[:, j] = np.interp(s_uniform, arc, q[:, j])
    if aux_arrays is None:
        return out
    out_aux = []
    for a in aux_arrays:
        a = np.asarray(a, dtype=float)
        oa = np.zeros((n_samples, a.shape[1]))
        for j in range(a.shape[1]):
            oa[:, j] = np.interp(s_uniform, arc, a[:, j])
        out_aux.append(oa)
    return out, out_aux

# =========================================================
# PUBLIC ALIASES for pipeline consumers
# =========================================================
resample_uniform_arclength = _resample_uniform_arclength
bezier_corner_blend = _bezier_corner_blend
arc_from_3points = _arc_from_3points
sample_arc = _sample_arc


# =========================================================
# STANDALONE PIPELINE HELPERS (stateless, no self required)
# =========================================================

def scurve_joint_trajectory(waypoints,
                            vel_limits: np.ndarray,
                            acc_limits: np.ndarray,
                            jerk_limits: np.ndarray,
                            dt: float = 0.01,
                            speed_factor: float = 1.0) -> List[TrajectoryPoint]:
    """
    Fixed S-curve generator (extracted from IndustrialTrajectoryPlanner so
    the Motus pipeline can call it without instantiating a planner).

    CRITICAL FIX: the original implementation deleted entire segments with
    ``del result[-len(t_arr)]``.  That line is removed; instead we skip the
    duplicate t=0 sample for every segment after the first.
    """
    if not (0.0 < speed_factor <= 1.0):
        raise ValueError(f"speed_factor must be in (0, 1], got {speed_factor}")

    q_points = [np.array(wp["q"] if isinstance(wp, dict) else wp) for wp in waypoints]
    n_joints = len(q_points[0])
    result: List[TrajectoryPoint] = []
    t_offset = 0.0

    for i in range(len(q_points) - 1):
        q0, q1 = q_points[i], q_points[i + 1]
        dq = q1 - q0
        h = np.abs(dq)

        durations = np.array([
            _scurve_duration(h[j], vel_limits[j], acc_limits[j], jerk_limits[j])
            for j in range(n_joints)
        ])
        T_seg = max(np.max(durations), 1e-6) / speed_factor

        params = [
            _scurve_time_scaled(h[j], T_seg, vel_limits[j], acc_limits[j], jerk_limits[j])
            for j in range(n_joints)
        ]

        t_arr = np.arange(0, T_seg + dt * 0.5, dt)
        # FIX: skip the duplicate start-point instead of deleting the whole segment later
        if i > 0:
            t_arr = t_arr[1:]

        for t in t_arr:
            q = np.zeros(n_joints)
            qd = np.zeros(n_joints)
            qdd = np.zeros(n_joints)
            for j in range(n_joints):
                if h[j] < 1e-12:
                    continue
                s_j, v_j, a_j = _scurve_eval(t, h[j], params[j])
                sign = np.sign(dq[j])
                q[j] = q0[j] + sign * s_j
                qd[j] = sign * v_j
                qdd[j] = sign * a_j
            result.append(TrajectoryPoint(q=q, qd=qd, qdd=qdd, t=t + t_offset))

        t_offset += T_seg

    return result


def topp_parametrize_path(q_path: np.ndarray,
                          vel_limits: np.ndarray,
                          acc_limits: np.ndarray,
                          extra_vel_cap: Optional[np.ndarray] = None,
                          n_resample: Optional[int] = None) -> List[TrajectoryPoint]:
    """
    Standalone TOPP wrapper (extracted from IndustrialTrajectoryPlanner).
    Includes the M<5 upsample guard so short paths don't crash
    Savitzky-Golay.
    """
    if n_resample is not None:
        q_path = resample_uniform_arclength(q_path, n_resample)
    res = _topp_parametrize(
        np.asarray(q_path, dtype=float),
        np.asarray(vel_limits, dtype=float),
        np.asarray(acc_limits, dtype=float),
        extra_vel_cap
    )
    return [
        TrajectoryPoint(q=res['q'][k], qd=res['qd'][k], qdd=res['qdd'][k], t=res['t'][k])
        for k in range(len(res['t']))
    ]


# =========================================================
# 4. INDUSTRIAL TRAJECTORY PLANNER
# =========================================================

class IndustrialTrajectoryPlanner(TrajectoryPlanner):
    """
    Drop-in superset of TrajectoryPlanner. All original methods
    (lspb, blend, spline, ...) are inherited unchanged; this class adds
    jerk-limited motion, time-optimal path parametrization, and arc/
    helix Cartesian primitives on top.
    """

    # ---------------------------------------------------------------
    # S-CURVE JOINT-SPACE (jerk-limited, multi-axis synchronized)
    # ---------------------------------------------------------------

    def create_scurve_joint_trajectory(self,
                                        waypoints: list,
                                        vel_limits:  np.ndarray,
                                        acc_limits:  np.ndarray,
                                        jerk_limits: np.ndarray,
                                        dt: float = 0.01,
                                        speed_factor: float = 1.0
                                        ) -> List[TrajectoryPoint]:
        """
        Thin wrapper around the standalone fixed S-curve generator.
        """
        return scurve_joint_trajectory(
            waypoints, vel_limits, acc_limits, jerk_limits,
            dt=dt, speed_factor=speed_factor
        )

    # ---------------------------------------------------------------
    # TOPP -- apply to an already-blended raw position path
    # ---------------------------------------------------------------

    @staticmethod
    def _resample_uniform_arclength(raw_positions, n_samples=None, aux_arrays=None):
        q = np.asarray(raw_positions, dtype=float)
        if n_samples is None:
            n_samples = len(q)
        dist = np.linalg.norm(np.diff(q, axis=0), axis=1)
        arc = np.insert(np.cumsum(dist), 0, 0.0)
        total = arc[-1]
        if total < 1e-9:
            out_aux = aux_arrays if aux_arrays is not None else None
            return (q, out_aux) if aux_arrays is not None else q
        s_uniform = np.linspace(0, total, n_samples)
        out = np.zeros((n_samples, q.shape[1]))
        for j in range(q.shape[1]):
            out[:, j] = np.interp(s_uniform, arc, q[:, j])
        if aux_arrays is None:
            return out
        out_aux = []
        for a in aux_arrays:
            a = np.asarray(a, dtype=float)
            oa = np.zeros((n_samples, a.shape[1]))
            for j in range(a.shape[1]):
                oa[:, j] = np.interp(s_uniform, arc, a[:, j])
            out_aux.append(oa)
        return out, out_aux

    def _topp_from_raw(self, raw_positions: list, vel_limits, acc_limits,
                        extra_vel_cap=None, n_resample: Optional[int] = None
                        ) -> List[TrajectoryPoint]:
        q_path = self._resample_uniform_arclength(raw_positions, n_resample)
        return topp_parametrize_path(q_path, vel_limits, acc_limits, extra_vel_cap)

    # ---------------------------------------------------------------
    # TOPP blended CARTESIAN trajectory  (true blend radius)
    # ---------------------------------------------------------------

    def create_topp_blended_cartesian_trajectory(self,
                                                  waypoints: list,
                                                  vel_limits: np.ndarray,
                                                  acc_limits: np.ndarray,
                                                  blend_radius=0.05,
                                                  n_samples: int = 100,
                                                  n_blend: int = 20,
                                                  cart_vel_cap: Optional[float] = None,
                                                  return_leg_times: bool = False
                                                  ):
        n = len(waypoints)
        if n < 2:
            empty = [] if not return_leg_times else ([], [])
            return empty
        n_corners = max(n - 2, 0)
        if np.isscalar(blend_radius):
            radii = [blend_radius] * n_corners
        else:
            radii = list(blend_radius)
            if len(radii) != n_corners:
                raise ValueError(
                    f"blend_radius list must have length {n_corners} "
                    f"(one per interior corner), got {len(radii)}")

        raw_positions, raw_cart = [], []
        marker_idx = [0]
        q_prev = np.array(waypoints[0]["q"])
        prev_exit = np.array(waypoints[0]["pose"])[:3]
        prev_exit_quat = np.array(waypoints[0]["pose"])[3:]

        for i in range(n - 1):
            pose0, pose1 = np.array(waypoints[i]["pose"]), np.array(waypoints[i + 1]["pose"])
            p0, p1 = pose0[:3], pose1[:3]
            tau = np.linspace(0, 1, n_samples)

            if i < n - 2:
                pose2 = np.array(waypoints[i + 2]["pose"])
                r = np.clip(radii[i], 0.0, 0.499)
                p_entry = p1 - r * (p1 - p0)
                positions = prev_exit + tau[:, None] * (p_entry - prev_exit)
                orientations = Slerp([0, 1], R.from_quat(
                    np.vstack([prev_exit_quat, pose0[3:]])))(tau).as_quat()

                seg_traj = self._ik_chain(np.hstack([positions[:-1], orientations[:-1]]), q_prev)
                if seg_traj is None:
                    return None
                raw_positions.extend(seg_traj)
                raw_cart.extend(positions[:-1].tolist())
                q_prev = seg_traj[-1]

                p_exit = p1 + r * (pose2[:3] - p1)
                blend_cart = _bezier_corner_blend(p_entry, p1, p_exit, n_blend)
                blend_quat = Slerp([0, 1], R.from_quat(
                    np.vstack([pose0[3:], pose1[3:]])))(np.linspace(0, 1, n_blend)).as_quat()
                blend_traj = self._ik_chain(np.hstack([blend_cart, blend_quat]), q_prev)
                if blend_traj is None:
                    return None
                raw_positions.extend(blend_traj)
                raw_cart.extend(blend_cart.tolist())
                marker_idx.append(len(raw_positions) - len(blend_traj) + len(blend_traj) // 2)
                q_prev = blend_traj[-1]
                prev_exit = p_exit
                prev_exit_quat = pose1[3:]
            else:
                positions = prev_exit + tau[:, None] * (p1 - prev_exit)
                orientations = Slerp([0, 1], R.from_quat(
                    np.vstack([prev_exit_quat, pose1[3:]])))(tau).as_quat()
                seg_traj = self._ik_chain(np.hstack([positions, orientations]), q_prev)
                if seg_traj is None:
                    return None
                raw_positions.extend(seg_traj)
                raw_cart.extend(positions.tolist())
        marker_idx.append(len(raw_positions) - 1)

        extra_cap = None
        if cart_vel_cap is not None and len(raw_cart) == len(raw_positions):
            q_path, (cart_arr,) = self._resample_uniform_arclength(
                raw_positions, aux_arrays=[np.array(raw_cart)])
            s_lin = np.linspace(0, 1, len(cart_arr))
            dpds = np.gradient(cart_arr, s_lin, axis=0)
            speed_density = np.linalg.norm(dpds, axis=1)
            with np.errstate(divide='ignore', invalid='ignore'):
                extra_cap = np.where(speed_density > 1e-9, cart_vel_cap / speed_density, 1e6)
        else:
            q_path = self._resample_uniform_arclength(raw_positions)

        res = _topp_parametrize(q_path, np.asarray(vel_limits, dtype=float),
                                 np.asarray(acc_limits, dtype=float), extra_cap)
        points = [
            TrajectoryPoint(q=res['q'][k], qd=res['qd'][k], qdd=res['qdd'][k], t=res['t'][k])
            for k in range(len(res['t']))
        ]
        if not return_leg_times:
            return points
        leg_end_times = self._marker_times(raw_positions, marker_idx[1:], res['s'], res['t'])
        return points, leg_end_times

    @staticmethod
    def _marker_times(raw_positions, marker_indices, res_s, res_t):
        raw = np.asarray(raw_positions, dtype=float)
        dist = np.linalg.norm(np.diff(raw, axis=0), axis=1)
        arc = np.insert(np.cumsum(dist), 0, 0.0)
        total = arc[-1] if arc[-1] > 1e-9 else 1.0
        marker_s = [arc[idx] / total for idx in marker_indices]
        return np.interp(marker_s, res_s, res_t).tolist()

    # ---------------------------------------------------------------
    # ARC / HELIX PRIMITIVES (Cartesian)
    # ---------------------------------------------------------------

    def _arc_pose_sequence(self, center, radius, normal, u, v,
                            start_angle, end_angle, n_samples, pitch,
                            ccw, quat_start, quat_end):
        positions = _sample_arc(center, radius, normal, u, v,
                                 start_angle, end_angle, n_samples, pitch, ccw)
        if quat_end is None:
            orientations = np.tile(quat_start, (n_samples, 1))
        else:
            tau = np.linspace(0, 1, n_samples)
            orientations = Slerp([0, 1], R.from_quat(np.vstack([quat_start, quat_end])))(tau).as_quat()
        return positions, orientations

    def create_arc3_trajectory(self,
                                p1, p2, p3,
                                q0: np.ndarray,
                                n_samples: int = 100,
                                quat_start: Optional[np.ndarray] = None,
                                quat_end:   Optional[np.ndarray] = None,
                                vel_limits: Optional[np.ndarray] = None,
                                acc_limits: Optional[np.ndarray] = None
                                ) -> Optional[List]:
        center, radius, normal, u, v = _arc_from_3points(p1, p2, p3)
        start_angle = 0.0
        end_angle = np.arctan2(np.dot(np.asarray(p3) - center, v),
                                np.dot(np.asarray(p3) - center, u))
        if quat_start is None:
            quat_start = np.array([0., 0., 0., 1.])
        positions, orientations = self._arc_pose_sequence(
            center, radius, normal, u, v, start_angle, end_angle,
            n_samples, 0.0, True, quat_start, quat_end)
        return self._finish_cartesian_primitive(positions, orientations, q0,
                                                  vel_limits, acc_limits)

    def create_arc_center_trajectory(self,
                                      center, radius, normal,
                                      start_angle: float, end_angle: float,
                                      q0: np.ndarray,
                                      n_samples: int = 100,
                                      ccw: bool = True,
                                      quat_start: Optional[np.ndarray] = None,
                                      quat_end:   Optional[np.ndarray] = None,
                                      vel_limits: Optional[np.ndarray] = None,
                                      acc_limits: Optional[np.ndarray] = None
                                      ) -> Optional[List]:
        center = np.asarray(center, dtype=float)
        normal = np.asarray(normal, dtype=float); normal /= np.linalg.norm(normal)
        ref = np.array([1., 0., 0.]) if abs(normal[0]) < 0.9 else np.array([0., 1., 0.])
        u = ref - np.dot(ref, normal) * normal; u /= np.linalg.norm(u)
        v = np.cross(normal, u)
        if quat_start is None:
            quat_start = np.array([0., 0., 0., 1.])
        positions, orientations = self._arc_pose_sequence(
            center, radius, normal, u, v, start_angle, end_angle,
            n_samples, 0.0, ccw, quat_start, quat_end)
        return self._finish_cartesian_primitive(positions, orientations, q0,
                                                  vel_limits, acc_limits)

    def create_helix_trajectory(self,
                                 center, radius, normal,
                                 start_angle: float, end_angle: float,
                                 pitch: float,
                                 q0: np.ndarray,
                                 n_samples: int = 200,
                                 ccw: bool = True,
                                 quat_start: Optional[np.ndarray] = None,
                                 quat_end:   Optional[np.ndarray] = None,
                                 vel_limits: Optional[np.ndarray] = None,
                                 acc_limits: Optional[np.ndarray] = None
                                 ) -> Optional[List]:
        center = np.asarray(center, dtype=float)
        normal = np.asarray(normal, dtype=float); normal /= np.linalg.norm(normal)
        ref = np.array([1., 0., 0.]) if abs(normal[0]) < 0.9 else np.array([0., 1., 0.])
        u = ref - np.dot(ref, normal) * normal; u /= np.linalg.norm(u)
        v = np.cross(normal, u)
        if quat_start is None:
            quat_start = np.array([0., 0., 0., 1.])
        positions, orientations = self._arc_pose_sequence(
            center, radius, normal, u, v, start_angle, end_angle,
            n_samples, pitch, ccw, quat_start, quat_end)
        return self._finish_cartesian_primitive(positions, orientations, q0,
                                                  vel_limits, acc_limits)

    def _finish_cartesian_primitive(self, positions, orientations, q0,
                                     vel_limits, acc_limits):
        traj = self._ik_chain(np.hstack([positions, orientations]), q0)
        if traj is None:
            return None
        if vel_limits is not None and acc_limits is not None:
            return self._topp_from_raw(traj, vel_limits, acc_limits)
        return traj

    # ---------------------------------------------------------------
    # UNIFIED DISPATCH OVERRIDE
    # ---------------------------------------------------------------

    def create_trajectory(self,
                           waypoints,
                           traj_method: str = 'ts',
                           traj_type:   str = 'qu',
                           n_samples:   int = 100,
                           blend_radius: float = 0.0,
                           n_blend: int = 20,
                           duration_per_segment: float = 2.0,
                           dt: float = 0.01,
                           speed_factor: float = 1.0,
                           vel_limits:  Optional[np.ndarray] = None,
                           acc_limits:  Optional[np.ndarray] = None,
                           jerk_limits: Optional[np.ndarray] = None
                           ) -> Optional[list]:
        if traj_method == 'js' and traj_type == 'scurve':
            ok, reason = self.precheck_waypoints(waypoints, require_pose=False)
            if not ok:
                raise ValueError(f"[IndustrialTrajectoryPlanner] Waypoint precheck failed: {reason}")
            if vel_limits is None or acc_limits is None or jerk_limits is None:
                raise ValueError(
                    "traj_type='scurve' requires vel_limits, acc_limits, and "
                    "jerk_limits (got None for at least one)")
            return self.create_scurve_joint_trajectory(
                waypoints, vel_limits, acc_limits, jerk_limits,
                dt=dt, speed_factor=speed_factor)

        return super().create_trajectory(
            waypoints,
            traj_method=traj_method,
            traj_type=traj_type,
            n_samples=n_samples,
            blend_radius=blend_radius,
            n_blend=n_blend,
            duration_per_segment=duration_per_segment,
            dt=dt,
            speed_factor=speed_factor,
            vel_limits=vel_limits,
            acc_limits=acc_limits,
        )
