# """
# Author: Silas Udofia
# Date: 2024-08-02
# GitHub: https://github.com/Silas-U/RoboKpy/tree/main
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
# """

import numpy as np
from dataclasses import dataclass, field
from typing import List, Optional, Tuple
from scipy.interpolate import make_interp_spline, CubicSpline
from scipy.spatial.transform import Rotation as R, Slerp


# =========================================================
# DATA STRUCTURES
# =========================================================

@dataclass
class TrajectoryPoint:
    """
    Single point in a trajectory with full kinematic state.
    Timed methods (lspb, tqu, blend) return List[TrajectoryPoint].
    Position-only methods return List[np.ndarray] for backward compatibility.
    """
    q:    np.ndarray                   # Joint positions     (n_joints,)
    qd:   np.ndarray                   # Joint velocities    (n_joints,)
    qdd:  np.ndarray                   # Joint accelerations (n_joints,)
    t:    float = 0.0                  # Timestamp  (seconds from trajectory start)
    pose: Optional[np.ndarray] = None  # Cartesian pose [x,y,z,qx,qy,qz,qw] if known


@dataclass
class SegmentConfig:
    """
    Per-segment trajectory settings passed from the motion planner.
    Lets every segment carry its own profile, blend radius and speed.
    """
    traj_method:          str   = 'js'   # 'js' | 'ts'
    traj_type:            str   = 'lspb' # see dispatch table
    blend_radius:         float = 0.0    # 0 = sharp stop, >0 = blended corner
    n_blend:              int   = 0     # points inside blend arc
    duration_per_segment: float = 1.0   # nominal segment time at full speed (s)
    dt:                   float = 0.04  # time step (s)
    speed_factor:         float = 1.0   # (0, 1] — 1.0 = full programmed speed
    n_samples:            int   = 50   # points for position-only methods


@dataclass
class TrajectoryMetrics:
    """Kinematic metrics for a completed trajectory."""
    total_time:            float
    path_length:           float          # Cartesian arc length (m); 0 if JS-only
    max_joint_vel:         np.ndarray     # Per-joint peak velocity   (rad/s)
    max_joint_acc:         np.ndarray     # Per-joint peak acceleration (rad/s²)
    n_points:              int
    continuity_ok:         bool
    discontinuity_indices: List[int]

    def report(self) -> str:
        lines = [
            f"  Points        : {self.n_points}",
            f"  Duration      : {self.total_time:.3f} s",
            f"  Path length   : {self.path_length:.4f} m",
            f"  Max joint vel : {np.round(self.max_joint_vel, 4)} rad/s",
            f"  Max joint acc : {np.round(self.max_joint_acc, 4)} rad/s²",
            f"  Continuity    : {'OK' if self.continuity_ok else 'FAIL at ' + str(self.discontinuity_indices)}",
        ]
        return "\n".join(lines)


# =========================================================
# TRAJECTORY PLANNER
# =========================================================

class TrajectoryPlanner:

    def __init__(self, model, fk, ik, jacobian):
        self.model    = model
        self.fk       = fk
        self.ik       = ik
        self.jacobian = jacobian

    # =========================================================
    # MATH UTILITIES
    # =========================================================

    @staticmethod
    def _quintic_s(t: np.ndarray) -> np.ndarray:
        """Quintic position scaling — zero vel & accel at t = 0, 1."""
        return 10*t**3 - 15*t**4 + 6*t**5

    @staticmethod
    def _quintic_sd(t: np.ndarray, T: float) -> np.ndarray:
        """Quintic velocity scaling (first derivative w.r.t. real time T)."""
        return (30*t**2 - 60*t**3 + 30*t**4) / T

    @staticmethod
    def _quintic_sdd(t: np.ndarray, T: float) -> np.ndarray:
        """Quintic acceleration scaling (second derivative w.r.t. real time T)."""
        return (60*t - 180*t**2 + 120*t**3) / (T**2)

    @staticmethod
    def _arc_length_reparametrize(positions_dense: np.ndarray,
                                   t_dense: np.ndarray,
                                   n_samples: int) -> Tuple[np.ndarray, np.ndarray]:
        """
        Reparametrize a dense Cartesian path by arc length so uniform
        samples give constant end-effector speed.
        Returns (s_uniform, t_uniform) both in [0, 1].
        """
        dist     = np.linalg.norm(np.diff(positions_dense, axis=0), axis=1)
        arc      = np.insert(np.cumsum(dist), 0, 0.0)
        total    = arc[-1]
        if total < 1e-9:
            u = np.linspace(0, 1, n_samples)
            return u, u
        arc_norm  = arc / total
        s_uniform = np.linspace(0, 1, n_samples)
        t_uniform = np.interp(s_uniform, arc_norm, t_dense)
        return s_uniform, t_uniform

    @staticmethod
    def _finite_diff_kinematics(q_arr: np.ndarray,
                                 dt: float) -> Tuple[np.ndarray, np.ndarray]:
        """
        Estimate joint velocities and accelerations via numpy central
        differences.  More accurate than forward differences at segment
        boundaries.
        Returns (qd, qdd) both shape (N, n_joints).
        """
        qd  = np.gradient(q_arr, dt, axis=0)
        qdd = np.gradient(qd,    dt, axis=0)
        return qd, qdd

    # =========================================================
    # WAYPOINT PRECHECK
    # =========================================================

    @staticmethod
    def precheck_waypoints(waypoints: list,
                            require_pose: bool = False) -> Tuple[bool, str]:
        """
        Validate a waypoint list before planning.
        Returns (ok, reason_string).
        """
        if len(waypoints) < 2:
            return False, f"Need at least 2 waypoints, got {len(waypoints)}"

        n_joints = None

        for i, wp in enumerate(waypoints):
            if "q" not in wp:
                return False, f"Waypoint {i} missing 'q'"
            q = np.asarray(wp["q"])
            if q.ndim != 1:
                return False, f"Waypoint {i}: 'q' must be 1D, got shape {q.shape}"
            if n_joints is None:
                n_joints = len(q)
            elif len(q) != n_joints:
                return False, (f"Waypoint {i}: joint count {len(q)} "
                               f"!= expected {n_joints}")
            if require_pose:
                if "pose" not in wp:
                    return False, f"Waypoint {i} missing 'pose'"
                p = np.asarray(wp["pose"])
                if p.shape != (7,):
                    return False, (f"Waypoint {i}: 'pose' must be shape (7,), "
                                   f"got {p.shape}")

        return True, "ok"

    # =========================================================
    # IK CHAIN SOLVER
    # =========================================================

    def _ik_chain(self,
                  poses:    np.ndarray,
                  q0:       np.ndarray,
                  max_iter: int = 50) -> Optional[List[np.ndarray]]:
        """
        Solve IK sequentially along a Cartesian pose sequence using the
        previous solution as the warm-start seed (no-flip guarantee).
        Returns None on the first failure.
        """
        traj   = []
        q_prev = q0.copy()
        # DIAGNOSTIC — per-solve iteration counts for this call, read by
        # profile_planner's instrument(). Doesn't affect solve behavior.
        iters  = []
        for i, pose in enumerate(poses):
            q_sol = self.ik.solve(pose, q0=q_prev, max_iter=max_iter)
            if not self.ik.success:
                print(f"[TrajectoryPlanner] IK failed at step {i}")
                return None
            traj.append(q_sol)
            q_prev = q_sol
            iters.append(getattr(self.ik, "last_iterations", -1))
        self.last_chain_iterations = iters
        return traj

    # =========================================================
    # SPEED SCALING
    # =========================================================

    @staticmethod
    def scale_trajectory_speed(traj: List[TrajectoryPoint],
                                speed_factor: float) -> List[TrajectoryPoint]:
        """
        Scale a timed trajectory by speed_factor in (0, 1].
        Timestamps stretch, velocities scale linearly,
        accelerations scale quadratically — kinematically consistent.
        """
        if not (0.0 < speed_factor <= 1.0):
            raise ValueError(f"speed_factor must be in (0, 1], got {speed_factor}")
        return [
            TrajectoryPoint(
                q    = pt.q.copy(),
                qd   = pt.qd  * speed_factor,
                qdd  = pt.qdd * speed_factor**2,
                t    = pt.t   / speed_factor,
                pose = pt.pose.copy() if pt.pose is not None else None
            )
            for pt in traj
        ]

    def enforce_velocity_limits(self,
                                 traj:       List[np.ndarray],
                                 vel_limits: np.ndarray,
                                 dt:         float = 0.01
                                 ) -> List[TrajectoryPoint]:
        """
        Enforce per-joint velocity limits on a raw position trajectory by
        locally stretching time wherever a limit would be violated.
        Returns a timed TrajectoryPoint list with correct timestamps.
        vel_limits : (n_joints,) in rad/s
        """
        q_arr = np.array(traj)
        dq    = np.diff(q_arr, axis=0)
        with np.errstate(divide='ignore', invalid='ignore'):
            dt_req = np.where(np.abs(dq) > 1e-9,
                              np.abs(dq) / vel_limits, dt)
        dt_per_step = np.maximum(np.max(dt_req, axis=1), dt)
        qd, qdd     = self._finite_diff_kinematics(q_arr, dt)
        result      = []
        t_cursor    = 0.0
        for i, q in enumerate(q_arr):
            result.append(TrajectoryPoint(q=q, qd=qd[i], qdd=qdd[i], t=t_cursor))
            if i < len(dt_per_step):
                t_cursor += dt_per_step[i]
        return result

    def time_parametrize_raw(self,
                              traj: List[np.ndarray],
                              dt:   float = 0.01) -> List[TrajectoryPoint]:
        """
        Attach timestamps and kinematic derivatives to a raw position list
        at a fixed time step dt.
        Velocities / accelerations via central differences.
        """
        q_arr   = np.array(traj)
        qd, qdd = self._finite_diff_kinematics(q_arr, dt)
        return [
            TrajectoryPoint(q=q_arr[i], qd=qd[i], qdd=qdd[i], t=i * dt)
            for i in range(len(q_arr))
        ]

    # =========================================================
    # MINIMUM-TIME SEGMENT DURATION
    # =========================================================

    def minimum_time_duration(self,
                               q0:         np.ndarray,
                               q1:         np.ndarray,
                               vel_limits: np.ndarray,
                               acc_limits: np.ndarray,
                               t_blend_frac: float = 0.35) -> float:
        """
        Compute the minimum achievable duration for a joint-space segment
        respecting both velocity and acceleration limits (LSPB model).

        This replaces the fixed duration_per_segment with a physically
        grounded estimate — the same approach used by KUKA WorkVisual and
        ABB RobotStudio cycle-time optimisation.

        Returns duration in seconds.
        """
        dq       = np.abs(q1 - q0)
        tb_frac  = np.clip(t_blend_frac, 0.1, 0.45)

        # Minimum time from velocity limit:  v_max = dq / (T - T*tb_frac)
        T_vel = dq / (vel_limits * (1.0 - tb_frac) + 1e-12)

        # Minimum time from acceleration limit: a = v_max / T_blend
        # => T >= sqrt(dq / (acc * tb_frac * (1 - tb_frac)))
        T_acc = np.sqrt(dq / (acc_limits * tb_frac * (1.0 - tb_frac) + 1e-12))

        # Worst-case joint drives the segment time
        T = float(np.max(np.maximum(T_vel, T_acc)))
        return max(T, 0.05)  # floor at 50 ms

    # =========================================================
    # LSPB — VECTORISED
    # =========================================================

    def _lspb_segment(self,
                      q0:       np.ndarray,
                      q1:       np.ndarray,
                      duration: float,
                      dt:       float = 0.01) -> List[TrajectoryPoint]:
        """
        LSPB (trapezoidal velocity profile) — fully vectorised over joints.

        Blend time = 35 % of total duration (KUKA default ~33 %).
        All joints are computed simultaneously as arrays — no Python
        inner loop over joints.
        """
        t_arr   = np.arange(0, duration + dt * 0.5, dt)   # (N,)
        t_blend = max(0.35 * duration, 1e-6)
        dq      = q1 - q0                                  # (n_joints,)

        # Per-joint cruise velocity and constant acceleration
        v_max = dq / (duration - t_blend + 1e-12)          # (n_joints,)
        a     = v_max / t_blend                             # (n_joints,)

        # Build phase masks  (N,) booleans
        ramp_up   = t_arr <= t_blend
        cruise    = (t_arr > t_blend) & (t_arr <= duration - t_blend)
        ramp_dn   = t_arr > duration - t_blend

        # Broadcast: t_arr (N,1) × joints (n_joints,)
        t = t_arr[:, None]

        q_arr   = np.zeros((len(t_arr), len(q0)))
        qd_arr  = np.zeros_like(q_arr)
        qdd_arr = np.zeros_like(q_arr)

        # --- Acceleration ramp ---
        q_arr[ramp_up]   = q0 + 0.5 * a * t[ramp_up]**2
        qd_arr[ramp_up]  = a  * t[ramp_up]
        qdd_arr[ramp_up] = a

        # --- Cruise ---
        q_arr[cruise]    = q0 + v_max * (t[cruise] - 0.5 * t_blend)
        qd_arr[cruise]   = v_max
        qdd_arr[cruise]  = 0.0

        # --- Deceleration ramp ---
        tau              = t[ramp_dn] - (duration - t_blend)
        q_arr[ramp_dn]   = q1 - 0.5 * a * (t_blend - tau)**2
        qd_arr[ramp_dn]  = a * (t_blend - tau)
        qdd_arr[ramp_dn] = -a

        # Clamp stationary joints
        still = np.abs(dq) < 1e-12
        q_arr[:, still]   = q0[still]
        qd_arr[:, still]  = 0.0
        qdd_arr[:, still] = 0.0

        return [
            TrajectoryPoint(q=q_arr[k], qd=qd_arr[k], qdd=qdd_arr[k], t=t_arr[k])
            for k in range(len(t_arr))
        ]

    # =========================================================
    # TIMED JOINT TRAJECTORY  (LSPB / QUINTIC)
    # =========================================================

    def create_timed_joint_trajectory(self,
                                       waypoints:             list,
                                       duration_per_segment:  float = 2.0,
                                       dt:                    float = 0.01,
                                       profile:               str   = 'lspb',
                                       speed_factor:          float = 1.0,
                                       vel_limits:  Optional[np.ndarray] = None,
                                       acc_limits:  Optional[np.ndarray] = None
                                       ) -> List[TrajectoryPoint]:
        """
        Time-parametrized joint-space trajectory with per-segment minimum-time
        planning when vel_limits and acc_limits are supplied.

        Args:
            waypoints             : List of dicts with 'q' key
            duration_per_segment  : Fallback time (s) if limits not provided
            dt                    : Time step (s)
            profile               : 'lspb' | 'quintic'
            speed_factor          : Global speed scale in (0, 1]
            vel_limits            : (n_joints,) rad/s  — enables min-time planning
            acc_limits            : (n_joints,) rad/s² — enables min-time planning
        """
        if not (0.0 < speed_factor <= 1.0):
            raise ValueError(f"speed_factor must be in (0, 1], got {speed_factor}")

        q_points = [np.array(wp["q"]) for wp in waypoints]
        result   = []
        t_offset = 0.0

        for i in range(len(q_points) - 1):
            q0 = q_points[i]
            q1 = q_points[i + 1]

            # Minimum-time duration if limits provided; else use fixed value
            if vel_limits is not None and acc_limits is not None:
                T_nominal = self.minimum_time_duration(q0, q1, vel_limits, acc_limits)
            else:
                T_nominal = duration_per_segment

            T = T_nominal / speed_factor   # stretch for slower speed

            if profile == 'lspb':
                seg_pts = self._lspb_segment(q0, q1, T, dt)

            elif profile == 'quintic':
                t_arr = np.arange(0, T + dt * 0.5, dt)
                tau   = t_arr / T
                s     = self._quintic_s(tau)
                sd    = self._quintic_sd(tau, T)
                sdd   = self._quintic_sdd(tau, T)
                seg_pts = [
                    TrajectoryPoint(
                        q   = q0 + s[k]   * (q1 - q0),
                        qd  = sd[k]  * (q1 - q0),
                        qdd = sdd[k] * (q1 - q0),
                        t   = t
                    )
                    for k, t in enumerate(t_arr)
                ]
            else:
                raise ValueError(f"Unknown profile: {profile}")

            for pt in seg_pts:
                pt.t += t_offset

            if result:
                seg_pts = seg_pts[1:]   # drop duplicate boundary point

            result.extend(seg_pts)
            t_offset += T

        return result

    # =========================================================
    # BLEND RADIUS — CARTESIAN SPACE  (true blend radius)
    # =========================================================

    def _blend_radius_cartesian(self,
                                 pose_prev:   np.ndarray,
                                 pose_corner: np.ndarray,
                                 pose_next:   np.ndarray,
                                 radius:      float,
                                 q0:          np.ndarray,
                                 n_blend:     int = 20
                                 ) -> Optional[List[np.ndarray]]:
        """
        Cartesian corner blend arc with SLERP orientation + sequential IK.
        Returns list of (n_joints,) arrays, or None on IK failure.
        """
        p_prev, p_corner, p_next = pose_prev[:3], pose_corner[:3], pose_next[:3]
        v_in    = p_corner - p_prev
        v_out   = p_next   - p_corner
        len_in  = np.linalg.norm(v_in)  + 1e-12
        len_out = np.linalg.norm(v_out) + 1e-12

        r       = np.clip(radius, 0.0, 0.499)
        p_entry = p_corner - r * v_in  / len_in  * len_in
        p_exit  = p_corner + r * v_out / len_out * len_out

        half = n_blend // 2
        s1   = self._quintic_s(np.linspace(0, 1, half))
        s2   = self._quintic_s(np.linspace(0, 1, n_blend - half))

        pos_blend = np.zeros((n_blend, 3))
        pos_blend[:half] = p_entry  + s1[:, None] * (p_corner - p_entry)
        pos_blend[half:] = p_corner + s2[:, None] * (p_exit   - p_corner)

        r_entry  = R.from_quat(pose_prev[3:])
        r_corner = R.from_quat(pose_corner[3:])
        r_exit   = R.from_quat(pose_next[3:])

        slerp1 = Slerp([0, 1], R.concatenate([r_entry,  r_corner]))
        slerp2 = Slerp([0, 1], R.concatenate([r_corner, r_exit]))

        oris = np.vstack([
            slerp1(np.linspace(0, 1, half)).as_quat(),
            slerp2(np.linspace(0, 1, n_blend - half)).as_quat()
        ])

        return self._ik_chain(np.hstack([pos_blend, oris]), q0)

    # =========================================================
    # BLENDED CARTESIAN TRAJECTORY  (true blend radius)
    # =========================================================

    def create_blended_cartesian_trajectory(self,
                                             waypoints:    list,
                                             blend_radius: float = 0.05,
                                             n_samples:    int   = 100,
                                             n_blend:      int   = 20,
                                             speed_factor: float = 1.0,
                                             dt:           float = 0.01
                                             ) -> Optional[List[TrajectoryPoint]]:
        """
        Cartesian trajectory with corner blending, sequential IK,
        and full kinematic state at every point.
        Returns List[TrajectoryPoint] or None on IK failure.
        """
        n             = len(waypoints)
        raw_positions = []
        q_prev        = np.array(waypoints[0]["q"])

        if n < 2:
            return []

        for i in range(n - 1):
            pose0 = np.array(waypoints[i]["pose"])
            pose1 = np.array(waypoints[i + 1]["pose"])
            p0, p1 = pose0[:3], pose1[:3]
            tau    = np.linspace(0, 1, n_samples)
            s      = self._quintic_s(tau)

            positions    = p0 + s[:, None] * (p1 - p0)
            orientations = Slerp([0, 1], R.from_quat(
                np.vstack([pose0[3:], pose1[3:]])
            ))(tau).as_quat()

            if i < n - 2:
                r   = np.clip(blend_radius, 0.0, 0.499)
                cut = int(r * n_samples)
                seg_traj = self._ik_chain(
                    np.hstack([positions[:n_samples - cut],
                               orientations[:n_samples - cut]]), q_prev
                )
                if seg_traj is None:
                    return None
                raw_positions.extend(seg_traj)
                q_prev = seg_traj[-1]

                blend_traj = self._blend_radius_cartesian(
                    pose_prev=pose0, pose_corner=pose1,
                    pose_next=np.array(waypoints[i + 2]["pose"]),
                    radius=blend_radius, q0=q_prev, n_blend=n_blend
                )
                if blend_traj is None:
                    return None
                raw_positions.extend(blend_traj)
                q_prev = blend_traj[-1]
            else:
                seg_traj = self._ik_chain(
                    np.hstack([positions, orientations]), q_prev
                )
                if seg_traj is None:
                    return None
                raw_positions.extend(seg_traj)

        return self.time_parametrize_raw(raw_positions, dt=dt / speed_factor)

    # =========================================================
    # TRAJECTORY METRICS
    # =========================================================

    def compute_metrics(self,
                        traj:          List[TrajectoryPoint],
                        vel_threshold: float = 0.5) -> TrajectoryMetrics:
        """
        Kinematic metrics from a timed trajectory.
        Useful for cycle-time estimation and limit auditing.
        """
        qd_arr  = np.array([pt.qd  for pt in traj])
        qdd_arr = np.array([pt.qdd for pt in traj])

        total_time  = traj[-1].t - traj[0].t
        path_length = 0.0

        if traj[0].pose is not None:
            pos = np.array([pt.pose[:3] for pt in traj if pt.pose is not None])
            if len(pos) > 1:
                path_length = float(
                    np.sum(np.linalg.norm(np.diff(pos, axis=0), axis=1))
                )

        max_vel   = np.max(np.abs(qd_arr),  axis=0)
        max_acc   = np.max(np.abs(qdd_arr), axis=0)
        vel_jumps = np.abs(np.diff(qd_arr, axis=0))
        bad       = np.where(np.any(vel_jumps > vel_threshold, axis=1))[0].tolist()

        return TrajectoryMetrics(
            total_time            = total_time,
            path_length           = path_length,
            max_joint_vel         = max_vel,
            max_joint_acc         = max_acc,
            n_points              = len(traj),
            continuity_ok         = (len(bad) == 0),
            discontinuity_indices = bad
        )

    def compute_raw_metrics(self,
                             traj: List[np.ndarray],
                             dt:   float = 0.01) -> dict:
        """Lightweight metrics for raw position-only trajectories."""
        q_arr   = np.array(traj)
        qd, qdd = self._finite_diff_kinematics(q_arr, dt)
        return {
            "n_points"     : len(traj),
            "max_joint_vel": np.max(np.abs(qd),  axis=0),
            "max_joint_acc": np.max(np.abs(qdd), axis=0),
            "total_travel" : np.sum(np.abs(np.diff(q_arr, axis=0)), axis=0),
        }

    # =========================================================
    # CONTINUITY VALIDATOR
    # =========================================================

    def validate_continuity(self,
                             traj:          List[TrajectoryPoint],
                             vel_threshold: float = 0.5,
                             acc_threshold: float = 5.0) -> dict:
        """
        Check C1 (velocity) and C2 (acceleration) continuity.
        Call before execution to catch planning errors early.
        """
        qd_arr    = np.array([pt.qd  for pt in traj])
        qdd_arr   = np.array([pt.qdd for pt in traj])
        vel_jumps = np.abs(np.diff(qd_arr,  axis=0))
        acc_jumps = np.abs(np.diff(qdd_arr, axis=0))
        c1_bad    = np.where(np.any(vel_jumps > vel_threshold, axis=1))[0].tolist()
        c2_bad    = np.where(np.any(acc_jumps > acc_threshold, axis=1))[0].tolist()

        return {
            "c1_ok"        : len(c1_bad) == 0,
            "c2_ok"        : len(c2_bad) == 0,
            "c1_violations": c1_bad,
            "c2_violations": c2_bad,
        }

    # =========================================================
    # JOINT LIMIT CHECKER
    # =========================================================

    def check_joint_limits(self,
                            traj:       List[TrajectoryPoint],
                            pos_limits: np.ndarray,
                            vel_limits: np.ndarray,
                            acc_limits: Optional[np.ndarray] = None) -> dict:
        """
        Verify a timed trajectory stays within hardware limits.

        Args:
            pos_limits : (n_joints, 2) [[min, max], ...] in rad
            vel_limits : (n_joints,)   in rad/s
            acc_limits : (n_joints,)   in rad/s²  (optional)
        """
        q_arr   = np.array([pt.q   for pt in traj])
        qd_arr  = np.array([pt.qd  for pt in traj])
        qdd_arr = np.array([pt.qdd for pt in traj])

        pos_lo = np.where(np.any(q_arr  < pos_limits[:, 0],    axis=1))[0].tolist()
        pos_hi = np.where(np.any(q_arr  > pos_limits[:, 1],    axis=1))[0].tolist()
        vel_v  = np.where(np.any(np.abs(qd_arr) > vel_limits,  axis=1))[0].tolist()

        result = {
            "pos_limit_ok"      : len(pos_lo) == 0 and len(pos_hi) == 0,
            "vel_limit_ok"      : len(vel_v) == 0,
            "pos_lo_violations" : pos_lo,
            "pos_hi_violations" : pos_hi,
            "vel_violations"    : vel_v,
        }

        if acc_limits is not None:
            acc_v = np.where(
                np.any(np.abs(qdd_arr) > acc_limits, axis=1)
            )[0].tolist()
            result["acc_limit_ok"]   = len(acc_v) == 0
            result["acc_violations"] = acc_v

        return result

    # =========================================================
    # ORIGINAL METHODS — position-only, backward-compatible
    # =========================================================

    def create_spline_cartesian(self, waypoints, n_samples=200):
        points = np.array([wp["pose"][:3] for wp in waypoints])
        quats  = np.array([wp["pose"][3:] for wp in waypoints])
        t      = np.linspace(0, 1, len(points))
        cs_x, cs_y, cs_z = (CubicSpline(t, points[:, i]) for i in range(3))
        slerp        = Slerp(t, R.from_quat(quats))
        t_sample     = np.linspace(0, 1, n_samples)
        positions    = np.vstack((cs_x(t_sample), cs_y(t_sample), cs_z(t_sample))).T
        orientations = slerp(t_sample).as_quat()
        traj   = []
        q_prev = np.array(waypoints[0]["q"])
        for i in range(n_samples):
            pose  = np.concatenate((positions[i], orientations[i]))
            q_sol = self.ik.solve(pose, q0=q_prev, max_iter=50)
            if not self.ik.success:
                print(f"IK failed at step {i}"); return None
            traj.append(q_sol); q_prev = q_sol
        return traj

    def create_quintic_cartesian(self, waypoints, n_samples=200):
        points   = np.array([wp["pose"][:3] for wp in waypoints])
        quats    = np.array([wp["pose"][3:] for wp in waypoints])
        t        = np.linspace(0, 1, len(points))
        t_sample = np.linspace(0, 1, n_samples)
        positions = []
        for ts in t_sample:
            seg = min(int(ts * (len(points) - 1)), len(points) - 2)
            t0  = seg / (len(points) - 1)
            t1  = (seg + 1) / (len(points) - 1)
            tau = (ts - t0) / (t1 - t0 + 1e-12)
            positions.append(
                points[seg] + self._quintic_s(np.array([tau]))[0]
                * (points[seg + 1] - points[seg])
            )
        positions    = np.array(positions)
        orientations = Slerp(t, R.from_quat(quats))(t_sample).as_quat()
        traj   = []
        q_prev = np.array(waypoints[0]["q"])
        for i in range(n_samples):
            pose  = np.concatenate((positions[i], orientations[i]))
            q_sol = self.ik.solve(pose, q0=q_prev, max_iter=50)
            if not self.ik.success:
                print(f"IK failed at step {i}"); return None
            traj.append(q_sol); q_prev = q_sol
        return traj

    def create_cubic_jointspace(self, waypoints, n_samples=200):
        q_points = np.array([wp if isinstance(wp, np.ndarray) else wp["q"]
                              for wp in waypoints])
        t_sample = np.linspace(0, 1, n_samples)
        traj     = []
        for ts in t_sample:
            seg = min(int(ts * (len(q_points) - 1)), len(q_points) - 2)
            t0  = seg / (len(q_points) - 1)
            tau = (ts - t0) / (1.0 / (len(q_points) - 1) + 1e-12)
            traj.append(q_points[seg]
                        + (3*tau**2 - 2*tau**3) * (q_points[seg+1] - q_points[seg]))
        return traj

    def create_quintic_jointspace(self, waypoints, n_samples=200):
        q_points = np.array([wp if isinstance(wp, np.ndarray) else wp["q"]
                              for wp in waypoints])
        t_sample = np.linspace(0, 1, n_samples)
        traj     = []
        for ts in t_sample:
            seg = min(int(ts * (len(q_points) - 1)), len(q_points) - 2)
            t0  = seg / (len(q_points) - 1)
            tau = (ts - t0) / (1.0 / (len(q_points) - 1) + 1e-12)
            traj.append(q_points[seg]
                        + self._quintic_s(np.array([tau]))[0]
                        * (q_points[seg + 1] - q_points[seg]))
        return traj

    def create_spline_jointspace(self, waypoints, n_samples=100):
        q_points   = np.array([wp["q"] for wp in waypoints])
        n_pts, n_j = q_points.shape
        k          = min(3, n_pts - 1)
        t          = np.linspace(0, 1, n_pts)
        t_sample   = np.linspace(0, 1, n_samples)
        splines    = [make_interp_spline(t, q_points[:, j], k=k) for j in range(n_j)]
        return [np.array([s(ts) for s in splines]) for ts in t_sample]

    def create_constant_speed_spline(self, waypoints, n_samples=100):
        points  = np.array([wp["pose"][:3] for wp in waypoints])
        quats   = np.array([wp["pose"][3:] for wp in waypoints])
        t       = np.linspace(0, 1, len(points))
        t_dense = np.linspace(0, 1, n_samples * 5)
        cs_x, cs_y, cs_z = (CubicSpline(t, points[:, i]) for i in range(3))
        pos_dense = np.vstack((cs_x(t_dense), cs_y(t_dense), cs_z(t_dense))).T
        slerp     = Slerp(t, R.from_quat(quats))
        _, t_uni  = self._arc_length_reparametrize(pos_dense, t_dense, n_samples)
        s_uni     = np.linspace(0, 1, n_samples)
        pos_uni   = np.zeros((n_samples, 3))
        for i in range(3):
            pos_uni[:, i] = np.interp(s_uni,
                                       np.linspace(0, 1, len(pos_dense)),
                                       pos_dense[:, i])
        oris   = slerp(t_uni).as_quat()
        traj   = []
        q_prev = np.array(waypoints[0]["q"])
        for i in range(n_samples):
            pose  = np.concatenate((pos_uni[i], oris[i]))
            q_sol = self.ik.solve(pose, q0=q_prev, max_iter=50)
            if not self.ik.success:
                print(f"IK failed at step {i}"); return None
            traj.append(q_sol); q_prev = q_sol
        return traj

    def create_constant_speed_joint(self, waypoints, n_samples=100):
        traj = []
        for i in range(len(waypoints) - 1):
            q0  = np.array(waypoints[i]["q"])
            q1  = np.array(waypoints[i + 1]["q"])
            tau = np.linspace(0, 1, n_samples)
            traj.extend((q0 + self._quintic_s(tau)[:, None] * (q1 - q0)).tolist())
        return traj

    # =========================================================
    # UNIFIED DISPATCH
    # =========================================================

    def create_trajectory(self,
                           waypoints,
                           traj_method:          str   = 'ts',
                           traj_type:            str   = 'qu',
                           n_samples:            int   = 100,
                           blend_radius:         float = 0.0,
                           n_blend:              int   = 20,
                           duration_per_segment: float = 2.0,
                           dt:                   float = 0.01,
                           speed_factor:         float = 1.0,
                           vel_limits:  Optional[np.ndarray] = None,
                           acc_limits:  Optional[np.ndarray] = None
                           ) -> Optional[list]:
        """
        Unified trajectory creation entry point.

        Args:
            waypoints             : List of waypoint dicts
            traj_method           : 'js' (joint-space) | 'ts' (Cartesian)
            traj_type             : See table below
            n_samples             : Points per segment (position-only methods)
            blend_radius          : Corner blend radius 0.0–0.5 (0 = sharp stop)
            n_blend               : Points inside blend arc
            duration_per_segment  : Nominal segment time (s); overridden by
                                    min-time planning when vel/acc limits given
            dt                    : Time step (s) for timed/blended methods
            speed_factor          : Global speed override (0, 1]
            vel_limits            : (n_joints,) rad/s   — enables min-time planning
            acc_limits            : (n_joints,) rad/s²  — enables min-time planning

        Return type
        ──────────────────────────────────────────────────────
        List[np.ndarray]       — position-only methods
        List[TrajectoryPoint]  — timed / blended methods
        None                   — IK failure (Cartesian methods)

        traj_type table
        ──────────────────────────────────────────────────────
        method  type    description
        ──────  ──────  ────────────────────────────────────────
        js      cu      Cubic joint-space
        js      qu      Quintic joint-space
        js      spl     B-spline joint-space
        js      csj     Constant-speed joint-space
        js      lspb    LSPB timed            → TrajectoryPoint
        js      tqu     Timed quintic         → TrajectoryPoint
        ts      qu      Quintic Cartesian (IK)
        ts      cu      Cubic Cartesian (IK)
        ts      spl     Spline Cartesian (IK)
        ts      cspl    Constant-speed spline
        ts      blend   Blended Cartesian     → TrajectoryPoint
        ──────────────────────────────────────────────────────
        """
        ok, reason = self.precheck_waypoints(
            waypoints, require_pose=(traj_method == 'ts')
        )
        if not ok:
            raise ValueError(f"[TrajectoryPlanner] Waypoint precheck failed: {reason}")

        if traj_method == 'js':

            if traj_type == 'cu':
                return self.create_cubic_jointspace(waypoints, n_samples)
            elif traj_type == 'qu':
                return self.create_quintic_jointspace(waypoints, n_samples)
            elif traj_type == 'spl':
                return self.create_spline_jointspace(waypoints, n_samples)
            elif traj_type == 'csj':
                return self.create_constant_speed_joint(waypoints, n_samples)
            elif traj_type == 'lspb':
                return self.create_timed_joint_trajectory(
                    waypoints, duration_per_segment, dt,
                    profile='lspb', speed_factor=speed_factor,
                    vel_limits=vel_limits, acc_limits=acc_limits
                )
            elif traj_type == 'tqu':
                return self.create_timed_joint_trajectory(
                    waypoints, duration_per_segment, dt,
                    profile='quintic', speed_factor=speed_factor,
                    vel_limits=vel_limits, acc_limits=acc_limits
                )
            else:
                raise ValueError(f"Unsupported joint traj type: {traj_type}")

        elif traj_method == 'ts':

            if traj_type in ('qu', 'cu'):
                return self.create_quintic_cartesian(waypoints, n_samples)
            elif traj_type == 'spl':
                return self.create_spline_cartesian(waypoints, n_samples)
            elif traj_type == 'cspl':
                return self.create_constant_speed_spline(waypoints, n_samples)
            elif traj_type == 'blend':
                return self.create_blended_cartesian_trajectory(
                    waypoints, blend_radius, n_samples, n_blend,
                    speed_factor=speed_factor, dt=dt
                )
            else:
                raise ValueError(f"Unsupported task traj type: {traj_type}")

        else:
            raise ValueError(f"Unsupported trajectory method: {traj_method}")