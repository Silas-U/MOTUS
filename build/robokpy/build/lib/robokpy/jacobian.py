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


class Jacobian:

    def __init__(self, model, fk):
        self.model = model
        self.fk    = fk
        self.jac   = None

        # Singularity tracking
        self.singular_threshold = 1e-3   # manipulability below this = near-singular
        self.singular_confs     = []     # list of (q, manipulability) snapshots

    # =========================================================
    # FULL-ROBOT JACOBIAN  (used by IK)
    # =========================================================

    def compute(self) -> np.ndarray:
        """
        Compute the geometric Jacobian for the full robot using
        joint axes and origins already populated by fk.compute().

        Must be called after fk.compute() — reads fk cached state
        without modifying it.

        Returns J (6 x n).
        """
        tf_end        = self.fk.tf_end
        joint_axes    = self.fk.joint_axes
        joint_origins = self.fk.joint_origins
        active_joints = self.fk.active_joints

        o_n = tf_end[:3, 3]
        n   = len(joint_axes)

        J = np.zeros((6, n))

        for i in range(n):
            z_i        = joint_axes[i]
            o_i        = joint_origins[i]
            joint_type = active_joints[i]["type"]

            if joint_type in ("revolute", "continuous"):
                J[:3, i] = np.cross(z_i, o_n - o_i)   # linear
                J[3:, i] = z_i                          # angular
            elif joint_type == "prismatic":
                J[:3, i] = z_i                          # linear
                J[3:, i] = np.zeros(3)                  # no angular

        self.jac = J
        return J

    # =========================================================
    # CHAIN JACOBIAN
    # =========================================================

    def compute_chain(self, base_link: str, end_link: str) -> np.ndarray:
        """
        Compute the geometric Jacobian for a specific kinematic chain.

        Calls model.build_chain (not fk.build_chain) to resolve the
        joint list, then reads the tf_tree populated by the most
        recent fk.compute_chain() call.

        Returns J (6 x n) where n = active joints in chain.
        """
        chain    = self.model.build_chain(base_link, end_link)
        tf_tree  = self.fk.get_tf_tree()
        tf_end   = self.fk.tf_end

        o_n = tf_end[:3, 3]

        # Index into tf_tree correctly:
        # tf_tree[0] = base (identity), tf_tree[k] = transform after k-th joint
        # We need to map each active joint in the chain to its tf_tree index

        J       = np.zeros((6, sum(
            1 for j in chain if j["type"] in ("revolute", "prismatic", "continuous")
        )))
        j_col   = 0
        tf_idx  = 0   # tf_tree index — increments for every joint (active or fixed)

        for joint in chain:
            # tf_tree[tf_idx] is the transform BEFORE this joint
            # tf_tree[tf_idx + 1] is the transform AFTER this joint
            T   = tf_tree[tf_idx] if tf_idx < len(tf_tree) else tf_tree[-1]
            R_i = T[:3, :3]
            o_i = T[:3, 3]

            axis  = np.array(list(map(float, joint["axis"].split())), dtype=float)
            norm  = np.linalg.norm(axis)
            z_i   = R_i @ (axis / (norm + 1e-12))

            if joint["type"] in ("revolute", "continuous"):
                J[:3, j_col] = np.cross(z_i, o_n - o_i)
                J[3:, j_col] = z_i
                j_col += 1

            elif joint["type"] == "prismatic":
                J[:3, j_col] = z_i
                J[3:, j_col] = np.zeros(3)
                j_col += 1

            tf_idx += 1

        self.jac = J
        return J

    # =========================================================
    # NUMERICAL JACOBIAN  (debug / validation)
    # =========================================================

    def numerical_jacobian(self, q: np.ndarray, eps: float = 1e-6) -> np.ndarray:
        """
        Compute the Jacobian numerically via central differences.

        Restores fk state to the original q after computation
        so downstream code reads the correct FK state.

        Returns J_numeric (6 x n).
        """
        q     = np.asarray(q, dtype=float)
        n     = len(q)
        J_num = np.zeros((6, n))

        # Compute baseline at original q
        self.fk.compute(q)
        T0  = self.fk.tf_end.copy()
        o_0 = T0[:3, 3]
        R0  = R.from_matrix(T0[:3, :3])

        for i in range(n):
            q_fwd = q.copy()
            q_bwd = q.copy()
            q_fwd[i] += eps
            q_bwd[i] -= eps

            self.fk.compute(q_fwd)
            T_fwd = self.fk.tf_end.copy()

            self.fk.compute(q_bwd)
            T_bwd = self.fk.tf_end.copy()

            # Central difference — more accurate than forward diff
            J_num[:3, i] = (T_fwd[:3, 3] - T_bwd[:3, 3]) / (2 * eps)

            R_fwd  = R.from_matrix(T_fwd[:3, :3])
            R_bwd  = R.from_matrix(T_bwd[:3, :3])
            dR     = (R_fwd * R_bwd.inv()).as_rotvec()
            J_num[3:, i] = dR / (2 * eps)

        # Restore FK state to original q
        self.fk.compute(q)

        return J_num

    # =========================================================
    # SINGULARITY ANALYSIS
    # =========================================================

    def rank(self) -> int:
        """Return the rank of the most recently computed Jacobian."""
        if self.jac is None:
            raise RuntimeError(
                "Jacobian has not been computed yet. "
                "Call compute() or compute_chain() first."
            )
        return int(np.linalg.matrix_rank(self.jac))

    def manipulability(self) -> float:
        """
        Compute the Yoshikawa manipulability measure:
            w = sqrt(det(J * J^T))

        w = 0 means singular. Larger w = further from singularity.
        """
        if self.jac is None:
            raise RuntimeError("Jacobian not computed yet.")

        JJT = self.jac @ self.jac.T
        det = np.linalg.det(JJT)
        return float(np.sqrt(max(det, 0.0)))

    def is_near_singular(self) -> bool:
        """Return True if manipulability is below singular_threshold."""
        return self.manipulability() < self.singular_threshold

    def condition_number(self) -> float:
        """
        Condition number of the Jacobian via SVD.
        High condition number (> 100) indicates near-singularity.
        """
        if self.jac is None:
            raise RuntimeError("Jacobian not computed yet.")
        sv = np.linalg.svd(self.jac, compute_uv=False)
        if sv[-1] < 1e-12:
            return float('inf')
        return float(sv[0] / sv[-1])

    def record_singular_conf(self, q: np.ndarray):
        """
        Snapshot the current configuration and manipulability
        into singular_confs for offline analysis.
        """
        m = self.manipulability()
        self.singular_confs.append({
            "q":             q.copy(),
            "manipulability": m,
            "condition":     self.condition_number(),
        })

    def clear_singular_confs(self):
        self.singular_confs = []