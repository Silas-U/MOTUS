# """
# Author: Silas Udofia
# Date: 2024-08-02
# GitHub: https://github.com/Silas-U/RoboKpy/tree/main

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
# """

import numpy as np
from scipy.spatial.transform import Rotation as R
from scipy.linalg import solve as linalg_solve


class InverseKinematics:

    def __init__(self, model, fk, jacobian, damp: float = 1e-2,
             base_link: str = "world", tip_link: str = "tcp"):
        
        self.model    = model
        self.fk       = fk
        self.jacobian = jacobian

        self.damp    = damp
        self.success = False
        self.last_err = float('inf')

        # DIAGNOSTIC — iteration count from the most recent solve() call.
        # Purely informational, never read by solve() itself; safe to
        # ignore/remove. Set at every break point below.
        self.last_iterations = 0

        # Set when a solution is only reached by clamping to joint limits
        # (see _precompute_limits / clamping in solve()) — distinguishes
        # "converged but limit-bound" from "converged cleanly".
        self.limit_bound = False

        self.base_link = base_link
        self.tip_link  = tip_link

        # ── Initial guess ────────────────────────────────────
        self.initial_guess_val = None

        # ── Preferred posture ────────────────────────────────
        self.q_pref    = None
        self.w_posture = 0.5

        # ── Joint limits ─────────────────────────────────────
        self.q_min   = None
        self.q_max   = None
        self.w_limit = 0.1

    # =========================================================
    # CONFIGURATION
    # =========================================================

    def set_preferred_posture(self, q_pref):
        self.q_pref = np.array(q_pref, dtype=float)

    def set_joint_limits(self, q_min=None, q_max=None):
        if q_min is not None:
            self.q_min = np.array(q_min, dtype=float)
        if q_max is not None:
            self.q_max = np.array(q_max, dtype=float)

    def initial_guess(self, q0):
        self.initial_guess_val = np.array(q0, dtype=float)

    def init_guess(self) -> np.ndarray:
        if self.initial_guess_val is None:
            return np.zeros(self.model.get_num_act_joints_in_chain(self.base_link, self.tip_link), dtype=float)
        return self.initial_guess_val.copy()

    # =========================================================
    # PRECOMPUTE LIMIT DATA
    # =========================================================

    def _precompute_limits(self, n: int):
        """
        Return (q_mid, range_sq) arrays for null-space limit avoidance.
        Infinite bounds default to midpoint=0, range_sq=1.
        """
        q_mid    = np.zeros(n)
        range_sq = np.ones(n)

        if self.q_min is None or self.q_max is None:
            return q_mid, range_sq

        for j in range(n):
            lo, hi = self.q_min[j], self.q_max[j]
            if np.isfinite(lo) and np.isfinite(hi):
                q_mid[j]    = 0.5 * (lo + hi)
                range_sq[j] = (hi - lo) ** 2 + 1e-6
            else:
                q_mid[j]    = 0.0
                range_sq[j] = 1.0

        return q_mid, range_sq

    def _clamp_to_limits(self, th: np.ndarray) -> np.ndarray:
        """
        Hard-clamp joint values to [q_min, q_max]. Sets self.limit_bound
        if any joint was actually clamped this call. No-op (with
        limit_bound left untouched) if limits aren't set.
        """
        if self.q_min is None or self.q_max is None:
            return th

        clamped = np.clip(th, self.q_min, self.q_max)
        if not np.allclose(clamped, th, atol=1e-9):
            self.limit_bound = True
        return clamped

    # =========================================================
    # QUATERNION UTILITIES
    # =========================================================

    @staticmethod
    def normalize_quat(q: np.ndarray) -> np.ndarray:
        q = np.array(q, dtype=float)
        n = np.linalg.norm(q)
        return q / n if n > 1e-12 else np.array([0., 0., 0., 1.])

    @staticmethod
    def quat_conjugate(q: np.ndarray) -> np.ndarray:
        return np.array([-q[0], -q[1], -q[2], q[3]])

    @staticmethod
    def quat_mul(q1: np.ndarray, q2: np.ndarray) -> np.ndarray:
        x1, y1, z1, w1 = q1
        x2, y2, z2, w2 = q2
        return np.array([
            w1*x2 + x1*w2 + y1*z2 - z1*y2,
            w1*y2 - x1*z2 + y1*w2 + z1*x2,
            w1*z2 + x1*y2 - y1*x2 + z1*w2,
            w1*w2 - x1*x2 - y1*y2 - z1*z2,
        ])

    @staticmethod
    def quat_to_rotvec(q: np.ndarray) -> np.ndarray:
        return R.from_quat(q).as_rotvec()

    # =========================================================
    # PSEUDOINVERSE  (numerically stable)
    # =========================================================

    @staticmethod
    def _damped_pinv(J: np.ndarray, damp: float) -> np.ndarray:
        """
        Damped least-squares pseudoinverse.
        Uses scipy.linalg.solve instead of explicit matrix inversion
        for numerical stability.

        J_pinv = J^T (J J^T + damp^2 I)^{-1}
        """
        m = J.shape[0]
        A = J @ J.T + damp**2 * np.eye(m)
        try:
            X = linalg_solve(A, J, assume_a='pos')
            return X.T
        except np.linalg.LinAlgError:
            return np.linalg.pinv(J)

    # =========================================================
    # IK SOLVER
    # =========================================================

    def solve(self,
              target_pose,
              mask=None,
              tol_pos:    float = 1e-3,
              tol_rot:    float = 1e-3,
              max_iter:   int   = 30,
              rpy_deg:    bool  = False,
              output_deg: bool  = False,
              q0=None) -> np.ndarray:
        """
        Solve IK for target_pose using damped least-squares with
        null-space posture bias and joint limit avoidance.

        Args:
            target_pose : [x,y,z,qx,qy,qz,qw] (length 7) or
                          [x,y,z,roll,pitch,yaw] (length 6)
            mask        : 6-element binary list [px,py,pz,rx,ry,rz]
            tol_pos     : convergence tolerance on position error norm (meters)
            tol_rot     : convergence tolerance on rotation error norm (radians)
            max_iter    : maximum iterations
            rpy_deg     : interpret RPY as degrees if True
            output_deg  : return joint angles in degrees if True
            q0          : initial joint configuration seed

        Returns:
            np.ndarray of joint angles

        Notes:
            Position and rotation errors live in different units (meters
            vs. radians), so they're checked against separate tolerances
            rather than folded into one combined norm — this avoids one
            error type silently dominating the convergence check.

            Joint values are hard-clamped to [q_min, q_max] every
            iteration when limits are set (see set_joint_limits), not
            just biased away from them in the null space. self.limit_bound
            is set True if any iteration required clamping — check this
            after solve() to distinguish a clean solve from one that only
            converged by sitting on a joint limit.
        """
        if mask is None:
            mask = [1, 1, 1, 1, 1, 1]

        mask_p = np.array(mask[:3], dtype=float)
        mask_r = np.array(mask[3:], dtype=float)
        target = np.array(target_pose, dtype=float)

        # ── Parse target pose ────────────────────────────────
        if target.size == 7:
            p_des = target[:3]
            q_des = self.normalize_quat(target[3:])
        elif target.size == 6:
            p_des = target[:3]
            rpy   = target[3:]
            if rpy_deg:
                rpy = np.deg2rad(rpy)
            q_des = R.from_euler("xyz", rpy).as_quat()
        else:
            raise ValueError(
                f"target_pose must be length 6 or 7, got {target.size}"
            )

        q_des = self.normalize_quat(q_des)

        # ── Initialise joints ────────────────────────────────
        th = np.array(q0, dtype=float) if q0 is not None else self.init_guess()
        n  = len(th)

        # Seed itself may be out-of-limits (e.g. bad q0 passed in) — clamp
        # before iterating so we never start outside bounds.
        self.limit_bound = False
        th = self._clamp_to_limits(th)

        # ── Precompute limit data ────────────────────────────
        q_mid_safe, range_sq_safe = self._precompute_limits(n)

        self.success  = False
        self.last_err = float('inf')
        i             = 0

        # ── Iterative solver ─────────────────────────────────
        while True:

            # Forward kinematics
            self.fk.compute_chain(th, self.base_link, self.tip_link)
            T     = self.fk.tf_end
            p_cur = T[:3, 3]
            q_cur = self.normalize_quat(
                R.from_matrix(T[:3, :3]).as_quat()
            )

            # Consistent quaternion hemisphere
            if np.dot(q_des, q_cur) < 0:
                q_cur = -q_cur

            # Error
            e_pos     = (p_des - p_cur) * mask_p
            q_err     = self.quat_mul(q_des, self.quat_conjugate(q_cur))
            e_rot     = self.quat_to_rotvec(q_err) * mask_r
            error     = np.concatenate([e_pos, e_rot])

            pos_err_norm = np.linalg.norm(e_pos)
            rot_err_norm = np.linalg.norm(e_rot)
            self.last_err = np.linalg.norm(error)  # kept for logging/back-compat

            if pos_err_norm < tol_pos and rot_err_norm < tol_rot:
                self.success = True
                self.last_iterations = i
                break

            if i >= max_iter:
                self.success = False
                self.last_iterations = i
                break

            # Jacobian with task-space weighting.
            # NOTE: this calls the full-robot compute(), not
            # compute_chain() — it works here because fk.compute_chain()
            # (above) overwrites the same joint_axes/joint_origins/
            # active_joints attributes that compute() reads. That's an
            # implicit coupling, not a documented contract — if
            # fk.compute_chain() is ever changed to stop clobbering that
            # shared state, this breaks silently. Use
            # jacobian.compute_chain(base_link, tip_link) instead if that
            # ever changes.
            J     = self.jacobian.compute()
            W     = np.diag(np.concatenate([mask_p, mask_r]))
            J_w   = W @ J
            err_w = W @ error

            # Damping scales with error — original behaviour preserved
            # Large error → more damping (original formula)
            damp   = self.damp + 0.1 * np.linalg.norm(error)

            # Stable pseudoinverse (improvement over original np.linalg.inv)
            J_pinv = self._damped_pinv(J_w, damp)

            # Null-space gradient
            N = np.eye(n) - J_pinv @ J_w
            z = np.zeros(n)

            # Posture bias — angle wrap only for revolute/continuous joints.
            # Wrapping unconditionally (as before) is a no-op for small
            # prismatic offsets but silently wrong for larger ones (a
            # prismatic joint's delta is in meters, not radians) — only
            # bites on chains with a longer linear axis (gantry rail,
            # linear 7th axis, etc.), which UR-series arms don't have.
            if self.q_pref is not None:
                dq_posture = self.q_pref - th
                revolute_mask = np.array([
                    j["type"] in ("revolute", "continuous")
                    for j in self.fk.active_joints
                ])
                dq_posture[revolute_mask] = (
                    (dq_posture[revolute_mask] + np.pi) % (2 * np.pi) - np.pi
                )
                z += self.w_posture * dq_posture

            # Joint limit avoidance (soft, null-space bias — kept as before)
            if self.q_min is not None and self.q_max is not None:
                z_limit = -(th - q_mid_safe) / range_sq_safe
                z      += self.w_limit * z_limit

            # Joint update
            d_theta = J_pinv @ err_w + N @ z
            th     += d_theta

            # Hard limit enforcement — a solution is never returned/iterated
            # on outside [q_min, q_max], regardless of what the soft bias
            # above allowed the raw update to do.
            th = self._clamp_to_limits(th)

            # Step size convergence
            if np.linalg.norm(d_theta) < 1e-8:
                self.success = (pos_err_norm < tol_pos * 10) and (rot_err_norm < tol_rot * 10)
                self.last_iterations = i
                break

            i += 1

        return np.rad2deg(th) if output_deg else th