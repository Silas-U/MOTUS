"""
pinocchio_backend.py — Optimized Pinocchio IK backend.

Performance-oriented implementation for Motus / RoboKpy.

Key design goals
----------------
1. Keep the existing IKSolverBackend interface.
2. Avoid unnecessary allocations inside the IK iteration.
3. Keep the Pinocchio model/data persistent.
4. Reuse the full Pinocchio configuration vector.
5. Avoid SciPy Rotation conversions inside the iteration loop.
6. Avoid Python loops for Jacobian column extraction.
7. Avoid expensive pseudoinverse calculations for the posture term.
8. Preserve the existing damped-Newton IK behavior.

Target pose format
------------------
    [x, y, z, qx, qy, qz, qw]

The active joints are the joints on the base_link -> tip_link
kinematic chain. All other joints remain at Pinocchio neutral values.
"""

from __future__ import annotations

import time
from typing import Optional

import numpy as np

from .base import IKSolverBackend


try:
    import pinocchio as pin

    _HAS_PINOCCHIO = True
except ImportError:
    _HAS_PINOCCHIO = False


class PinocchioBackend(IKSolverBackend):
    """
    Optimized Pinocchio-based IK using damped Newton iteration.

    Only joints belonging to the kinematic chain between base_link
    and tip_link are controlled.

    Performance characteristics
    ---------------------------
    - Pinocchio Model/Data are created once during initialize().
    - Full q configuration is allocated once per solve().
    - Active joint indices are cached as a NumPy array.
    - Jacobian extraction uses vectorized indexing.
    - Orientation error is computed with Pinocchio directly.
    - Null-space posture projection uses a damped solve rather than
      an expensive Moore-Penrose pseudoinverse.
    """

    def __init__(self):
        if not _HAS_PINOCCHIO:
            # Do not import-time fail. Preserve the previous behavior where
            # initialization raises the useful dependency error.
            pass

        # Persistent Pinocchio objects.
        self._model = None
        self._data = None
        self._ee_id = None

        # Active chain.
        self._base_link = None
        self._tip_link = None

        # Solver state.
        self._success = False
        self._limit_bound = False

        # Optional joint constraints.
        self._q_min = None
        self._q_max = None
        self._q_pref = None

        # ------------------------------------------------------------------
        # Cached chain mapping.
        #
        # _active_q_indices:
        #     Full Pinocchio q indices corresponding to active joints.
        #
        # _active_v_indices:
        #     Full Pinocchio velocity indices corresponding to active joints.
        #
        # For ordinary revolute 1-DoF joints these are normally identical,
        # but keeping them separate makes the implementation correct for
        # Pinocchio models where nq and nv differ.
        # ------------------------------------------------------------------
        self._active_q_indices = np.empty(0, dtype=np.int64)
        self._active_v_indices = np.empty(0, dtype=np.int64)
        self._num_active = 0

        # ------------------------------------------------------------------
        # Cached numerical constants.
        # ------------------------------------------------------------------
        self._eye6 = np.eye(6, dtype=float)

        # Small damping used by the null-space projector.
        self._nullspace_damping = 1e-6

        # ------------------------------------------------------------------
        # Optional profiling.
        #
        # Disabled by default so normal Motus operation has effectively
        # zero profiling overhead.
        # ------------------------------------------------------------------
        self._profile_enabled = False
        self._last_iterations = 0
        self._last_solve_time = 0.0

    # ======================================================================
    # INITIALIZATION
    # ======================================================================

    def initialize(
        self,
        robot_description: str,
        base_link: str,
        tip_link: str,
        **kwargs,
    ):
        """
        Load URDF and initialize persistent Pinocchio structures.
        """

        if not _HAS_PINOCCHIO:
            raise RuntimeError(
                "Pinocchio backend requires 'pinocchio'. "
                "Install it with: pip install pin"
            )

        import tempfile

        with tempfile.NamedTemporaryFile(
            mode="w",
            suffix=".urdf",
            delete=False,
        ) as f:
            f.write(robot_description)
            urdf_path = f.name

        # Build the model ONCE.
        self._model = pin.buildModelFromUrdf(urdf_path)

        # Create Data ONCE.
        self._data = self._model.createData()

        self._base_link = base_link
        self._tip_link = tip_link

        self._validate_frame(base_link, "base_link")
        self._validate_frame(tip_link, "tip_link")

        self._ee_id = self._model.getFrameId(tip_link)

        self._build_chain_map(
            base_link,
            tip_link,
        )

        # Optional initialization arguments.
        self._profile_enabled = bool(
            kwargs.get("profile", False)
        )

        if "nullspace_damping" in kwargs:
            self._nullspace_damping = float(
                kwargs["nullspace_damping"]
            )

    # ======================================================================
    # FRAME / CHAIN SETUP
    # ======================================================================

    def _validate_frame(
        self,
        link_name: str,
        role: str,
    ):
        """Raise a clear error if a requested frame does not exist."""

        frame_id = self._model.getFrameId(link_name)

        if frame_id >= len(self._model.frames):
            available = [
                self._model.frames[i].name
                for i in range(len(self._model.frames))
            ]

            raise ValueError(
                f"PinocchioBackend: {role} '{link_name}' "
                f"not found in URDF. "
                f"Available frames: {available}"
            )

    def _build_chain_map(
        self,
        base_link: str,
        tip_link: str,
    ):
        """
        Build cached active q/v index mappings.

        Traverses from tip toward base and stores active joints in
        base -> tip order.
        """

        tip_frame_id = self._model.getFrameId(tip_link)
        tip_joint_id = self._model.frames[tip_frame_id].parentJoint

        base_frame_id = self._model.getFrameId(base_link)
        base_joint_id = self._model.frames[base_frame_id].parentJoint

        q_indices = []
        v_indices = []

        current = tip_joint_id

        while current != base_joint_id and current > 0:
            joint = self._model.joints[current]

            if joint.nq > 0:
                # Pinocchio joints can theoretically have nq != nv.
                #
                # The existing Motus backend is designed around ordinary
                # 1-DoF revolute/prismatic arm joints. For those joints,
                # idx_q and idx_v are scalar indices.
                if joint.nq != 1 or joint.nv != 1:
                    raise ValueError(
                        "PinocchioBackend currently expects 1-DoF "
                        "active joints. "
                        f"Joint '{self._model.names[current]}' has "
                        f"nq={joint.nq}, nv={joint.nv}."
                    )

                q_indices.insert(0, joint.idx_q)
                v_indices.insert(0, joint.idx_v)

            current = self._model.parents[current]

        if not q_indices:
            raise ValueError(
                f"PinocchioBackend: no active joints found between "
                f"'{base_link}' and '{tip_link}'"
            )

        self._active_q_indices = np.asarray(
            q_indices,
            dtype=np.int64,
        )

        self._active_v_indices = np.asarray(
            v_indices,
            dtype=np.int64,
        )

        self._num_active = len(q_indices)

        # Cache an identity matrix of the active dimension.
        self._eye_active = np.eye(
            self._num_active,
            dtype=float,
        )

    # ======================================================================
    # CONFIGURATION HELPERS
    # ======================================================================

    def _expand_q(
        self,
        q_active: np.ndarray,
    ) -> np.ndarray:
        """
        Embed active joints into a full Pinocchio configuration.

        This method is kept for compatibility, but the solve() hot path
        deliberately does NOT call it every iteration.
        """

        q_full = pin.neutral(self._model)

        q_full[self._active_q_indices] = q_active

        return q_full

    def _extract_q(
        self,
        q_full: np.ndarray,
    ) -> np.ndarray:
        """
        Extract active joint values from full configuration.

        NumPy advanced indexing returns a copy, which is desirable here
        because callers should not receive a mutable view into q_full.
        """

        return np.asarray(
            q_full[self._active_q_indices],
            dtype=float,
        ).copy()

    # ======================================================================
    # TARGET PREPARATION
    # ======================================================================

    @staticmethod
    def _normalize_quaternion(
        q: np.ndarray,
    ) -> np.ndarray:
        """Normalize [qx, qy, qz, qw]."""

        norm = float(np.linalg.norm(q))

        if norm < 1e-12:
            # Identity quaternion.
            return np.array(
                [0.0, 0.0, 0.0, 1.0],
                dtype=float,
            )

        return q / norm

    @staticmethod
    def _quaternion_to_rotation_matrix(
        q_xyzw: np.ndarray,
    ) -> np.ndarray:
        """
        Convert [qx, qy, qz, qw] directly to a 3x3 rotation matrix.

        This avoids importing/using scipy.spatial.transform.Rotation
        inside solve().
        """

        x, y, z, w = q_xyzw

        xx = x * x
        yy = y * y
        zz = z * z

        xy = x * y
        xz = x * z
        yz = y * z

        wx = w * x
        wy = w * y
        wz = w * z

        return np.array(
            [
                [
                    1.0 - 2.0 * (yy + zz),
                    2.0 * (xy - wz),
                    2.0 * (xz + wy),
                ],
                [
                    2.0 * (xy + wz),
                    1.0 - 2.0 * (xx + zz),
                    2.0 * (yz - wx),
                ],
                [
                    2.0 * (xz - wy),
                    2.0 * (yz + wx),
                    1.0 - 2.0 * (xx + yy),
                ],
            ],
            dtype=float,
        )

    # ======================================================================
    # IK SOLVER
    # ======================================================================

    def solve(
        self,
        target_pose,
        q0=None,
        mask=None,
        tol_pos: float = 1e-3,
        tol_rot: float = 1e-3,
        max_iter: int = 30,
        **kwargs,
    ) -> np.ndarray:
        """
        Solve inverse kinematics.

        Parameters
        ----------
        target_pose:
            [x, y, z, qx, qy, qz, qw]

        q0:
            Either:
                - active joint configuration, or
                - full Pinocchio configuration.

        mask:
            Six-element Cartesian mask:
                [x, y, z, rx, ry, rz]

        tol_pos:
            Position tolerance in meters.

        tol_rot:
            Orientation tolerance in radians.

        max_iter:
            Maximum damped-Newton iterations.

        kwargs
        ------
        profile:
            Enable per-solve iteration timing.
        """

        if self._model is None or self._data is None:
            raise RuntimeError(
                "PinocchioBackend.solve() called before initialize()."
            )

        # --------------------------------------------------------------
        # Optional profiling.
        # --------------------------------------------------------------
        profile_enabled = bool(
            kwargs.get(
                "profile",
                self._profile_enabled,
            )
        )

        solve_start = (
            time.perf_counter()
            if profile_enabled
            else 0.0
        )

        self._success = False
        self._limit_bound = False
        self._last_iterations = 0
        self._last_solve_time = 0.0

        # --------------------------------------------------------------
        # Seed.
        #
        # Avoid unnecessary copies where possible, but always own the
        # active vector because it is modified in-place.
        # --------------------------------------------------------------
        if q0 is not None:
            q0_arr = np.asarray(
                q0,
                dtype=float,
            )

            if q0_arr.size == self._num_active:
                q_active = q0_arr.reshape(
                    self._num_active
                ).copy()

            else:
                if q0_arr.size != self._model.nq:
                    raise ValueError(
                        "PinocchioBackend.solve(): q0 must contain "
                        f"{self._num_active} active joints or "
                        f"{self._model.nq} full configuration values; "
                        f"got {q0_arr.size}."
                    )

                q_active = q0_arr[
                    self._active_q_indices
                ].copy()

        else:
            q_active = np.zeros(
                self._num_active,
                dtype=float,
            )

        # --------------------------------------------------------------
        # Create q_full ONLY ONCE.
        #
        # The old implementation rebuilt this on every iteration.
        # --------------------------------------------------------------
        q_full = pin.neutral(self._model)

        q_full[
            self._active_q_indices
        ] = q_active

        # --------------------------------------------------------------
        # Cartesian mask.
        # --------------------------------------------------------------
        if mask is None:
            mask_arr = np.ones(
                6,
                dtype=float,
            )
        else:
            mask_arr = np.asarray(
                mask,
                dtype=float,
            )

            if mask_arr.size != 6:
                raise ValueError(
                    "PinocchioBackend.solve(): mask must contain "
                    f"6 values, got {mask_arr.size}."
                )

            mask_arr = mask_arr.reshape(6)

        # Cache boolean/full mask behavior.

        # Fast path for the common case where the mask is all ones.
        full_mask = bool(
            np.all(mask_arr == 1.0)
        )

        # --------------------------------------------------------------
        # Target position.
        # --------------------------------------------------------------
        target = np.asarray(
            target_pose,
            dtype=float,
        )

        if target.size != 7:
            raise ValueError(
                "PinocchioBackend.solve(): target_pose must contain "
                f"7 values [x,y,z,qx,qy,qz,qw], got {target.size}."
            )

        p_des = target[:3]

        q_des = self._normalize_quaternion(
            target[3:7]
        )

        # Target rotation matrix is constant throughout the solve.
        R_des = self._quaternion_to_rotation_matrix(
            q_des
        )

        # --------------------------------------------------------------
        # Preallocate common buffers.
        # --------------------------------------------------------------
        J_full = None
        J_active = np.empty(
            (6, self._num_active),
            dtype=float,
        )

        e6 = np.empty(
            6,
            dtype=float,
        )

        # --------------------------------------------------------------
        # Main damped-Newton loop.
        # --------------------------------------------------------------
        for iteration in range(1, max_iter + 1):
            self._last_iterations = iteration

            # ----------------------------------------------------------
            # Forward kinematics.
            # ----------------------------------------------------------
            pin.forwardKinematics(
                self._model,
                self._data,
                q_full,
            )

            pin.updateFramePlacements(
                self._model,
                self._data,
            )

            T = self._data.oMf[self._ee_id]

            p_cur = T.translation
            R_cur = T.rotation

            # ----------------------------------------------------------
            # Position error.
            # ----------------------------------------------------------
            e_pos = p_des - p_cur

            # ----------------------------------------------------------
            # Orientation error.
            #
            # Existing implementation:
            #
            #   R_cur -> quaternion
            #   desired * conjugate(current)
            #   quaternion -> rotvec
            #
            # This implementation uses Pinocchio directly:
            #
            #   R_err = R_des * R_cur.T
            #   e_rot = log3(R_err)
            #
            # This avoids two SciPy Rotation conversions on every
            # iteration.
            # ----------------------------------------------------------
            R_err = R_des @ R_cur.T

            e_rot = np.asarray(
                pin.log3(R_err),
                dtype=float,
            )

            # Apply Cartesian mask.
            if not full_mask:
                e_pos = e_pos * mask_arr[:3]
                e_rot = e_rot * mask_arr[3:]

            # Store combined error.
            e6[:3] = e_pos
            e6[3:] = e_rot

            pos_err = float(
                np.linalg.norm(e_pos)
            )

            rot_err = float(
                np.linalg.norm(e_rot)
            )

            # ----------------------------------------------------------
            # Convergence.
            # ----------------------------------------------------------
            if (
                pos_err < tol_pos
                and rot_err < tol_rot
            ):
                self._success = True

                if profile_enabled:
                    self._last_solve_time = (
                        time.perf_counter()
                        - solve_start
                    )

                return self._extract_q(q_full)

            # ----------------------------------------------------------
            # Compute frame Jacobian.
            #
            # LOCAL_WORLD_ALIGNED matches the original backend.
            # ----------------------------------------------------------
            J_full = pin.computeFrameJacobian(
                self._model,
                self._data,
                q_full,
                self._ee_id,
                pin.ReferenceFrame.LOCAL_WORLD_ALIGNED,
            )

            J_full = J_full[:6, :]

            # Vectorized extraction instead of a Python loop.
            J_active[:, :] = J_full[
                :,
                self._active_v_indices,
            ]

            # ----------------------------------------------------------
            # Apply Cartesian mask.
            #
            # The original implementation constructed:
            #
            #     W = np.diag(mask_arr)
            #
            # every iteration.
            #
            # Avoid that allocation.
            # ----------------------------------------------------------
            if full_mask:
                J_w = J_active
                err_w = e6
            else:
                J_w = J_active * mask_arr[:, None]
                err_w = e6 * mask_arr

            # ----------------------------------------------------------
            # Damped least-squares step.
            #
            # Solve:
            #
            #   dq = J.T (J J.T + lambda^2 I)^-1 e
            #
            # This preserves the structure of the previous solver.
            # ----------------------------------------------------------
            err_norm = float(
                np.linalg.norm(err_w)
            )

            damp = 1e-2 + 0.1 * err_norm
            damp2 = damp * damp

            A = (
                J_w @ J_w.T
                + damp2 * self._eye6
            )

            try:
                x = np.linalg.solve(
                    A,
                    err_w,
                )

                dq_active = J_w.T @ x

            except np.linalg.LinAlgError:
                # Very rare fallback.
                #
                # Keep the robust original behavior.
                dq_active = (
                    np.linalg.pinv(J_w)
                    @ err_w
                )

            # ----------------------------------------------------------
            # Null-space preferred-posture bias.
            #
            # OLD:
            #
            #   pinv(J) -> N = I - pinv(J)J
            #
            # That requires an SVD/pseudoinverse on every iteration.
            #
            # NEW:
            #
            #   J# ~= J.T (J J.T + lambda^2 I)^-1
            #
            # and:
            #
            #   N dq = dq - J# (J dq)
            #
            # This keeps the same conceptual behavior while avoiding
            # the expensive pseudoinverse.
            # ----------------------------------------------------------
            if self._q_pref is not None:
                dq_posture = (
                    self._q_pref - q_active
                ).copy()

                # Preserve the original wrap-to-pi behavior.
                dq_posture = (
                    dq_posture + np.pi
                ) % (
                    2.0 * np.pi
                ) - np.pi

                # Damped projector.
                #
                # A_posture is already available as J J^T + damping.
                # Use a small additional regularization so that the
                # posture projector remains numerically stable near
                # singularities.
                A_ns = (
                    J_w @ J_w.T
                    + self._nullspace_damping
                    * self._eye6
                )

                try:
                    y = np.linalg.solve(
                        A_ns,
                        J_w @ dq_posture,
                    )

                    dq_projected = (
                        dq_posture
                        - J_w.T @ y
                    )

                    dq_active += (
                        0.5
                        * dq_projected
                    )

                except np.linalg.LinAlgError:
                    # If the null-space projection fails, retain the
                    # primary IK step rather than failing the solve.
                    pass

            # ----------------------------------------------------------
            # Update active configuration.
            # ----------------------------------------------------------
            q_active += dq_active

            # ----------------------------------------------------------
            # Hard joint limits.
            # ----------------------------------------------------------
            if (
                self._q_min is not None
                and self._q_max is not None
            ):
                clamped = np.clip(
                    q_active,
                    self._q_min,
                    self._q_max,
                )

                if not np.array_equal(
                    clamped,
                    q_active,
                ):
                    self._limit_bound = True

                q_active[:] = clamped

            # ----------------------------------------------------------
            # Step-size convergence.
            #
            # IMPORTANT:
            # The old backend returned q_full here BEFORE copying the
            # updated q_active into q_full.
            #
            # That could return the previous configuration.
            #
            # Update q_full first, then test/return.
            # ----------------------------------------------------------
            q_full[
                self._active_q_indices
            ] = q_active

            step_norm = float(
                np.linalg.norm(dq_active)
            )

            if step_norm < 1e-8:
                self._success = (
                    pos_err < tol_pos * 10.0
                    and rot_err < tol_rot * 10.0
                )

                if profile_enabled:
                    self._last_solve_time = (
                        time.perf_counter()
                        - solve_start
                    )

                return self._extract_q(q_full)

        # ------------------------------------------------------------------
        # Maximum iterations reached.
        # ------------------------------------------------------------------
        self._success = False

        if profile_enabled:
            self._last_solve_time = (
                time.perf_counter()
                - solve_start
            )

        return self._extract_q(q_full)

    # ======================================================================
    # OPTIONAL PROFILING ACCESSORS
    # ======================================================================

    @property
    def last_iterations(self) -> int:
        """Number of iterations used by the most recent solve()."""
        return self._last_iterations

    @property
    def last_solve_time(self) -> float:
        """Wall-clock duration of the most recent profiled solve()."""
        return self._last_solve_time

    # ======================================================================
    # BACKEND STATE
    # ======================================================================

    @property
    def success(self) -> bool:
        return self._success

    @property
    def limit_bound(self) -> bool:
        return self._limit_bound

    # ======================================================================
    # JOINT LIMITS / POSTURE
    # ======================================================================

    def set_joint_limits(
        self,
        q_min,
        q_max,
    ):
        self._q_min = (
            np.asarray(
                q_min,
                dtype=float,
            ).copy()
            if q_min is not None
            else None
        )

        self._q_max = (
            np.asarray(
                q_max,
                dtype=float,
            ).copy()
            if q_max is not None
            else None
        )

        if (
            self._q_min is not None
            and self._q_min.size != self._num_active
        ):
            raise ValueError(
                "PinocchioBackend: q_min size "
                f"{self._q_min.size} does not match "
                f"active joint count {self._num_active}."
            )

        if (
            self._q_max is not None
            and self._q_max.size != self._num_active
        ):
            raise ValueError(
                "PinocchioBackend: q_max size "
                f"{self._q_max.size} does not match "
                f"active joint count {self._num_active}."
            )

    def set_preferred_posture(
        self,
        q_pref,
    ):
        self._q_pref = (
            np.asarray(
                q_pref,
                dtype=float,
            ).copy()
            if q_pref is not None
            else None
        )

        if (
            self._q_pref is not None
            and self._q_pref.size != self._num_active
        ):
            raise ValueError(
                "PinocchioBackend: q_pref size "
                f"{self._q_pref.size} does not match "
                f"active joint count {self._num_active}."
            )

    # ======================================================================
    # TIP LINK
    # ======================================================================

    @property
    def tip_link(self) -> str:
        return self._tip_link

    @tip_link.setter
    def tip_link(
        self,
        value: str,
    ):
        self._tip_link = value

        if self._model is not None:
            self._validate_frame(
                value,
                "tip_link",
            )

            self._ee_id = (
                self._model.getFrameId(value)
            )

            self._build_chain_map(
                self._base_link,
                value,
            )

    # ======================================================================
    # BASE LINK
    # ======================================================================

    @property
    def base_link(self) -> str:
        return self._base_link

    @base_link.setter
    def base_link(
        self,
        value: str,
    ):
        self._base_link = value

        if self._model is not None:
            self._validate_frame(
                value,
                "base_link",
            )

            self._build_chain_map(
                value,
                self._tip_link,
            )