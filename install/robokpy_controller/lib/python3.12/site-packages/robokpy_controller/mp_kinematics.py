"""
mp_kinematics.py — Optimized KinematicsFacade

Thread-safe facade around the RoboKpy kinematics model.

Responsibilities
----------------
- Serialize all FK / IK / Jacobian access.
- Prevent concurrent mutation of the underlying RoboKpy model.
- Keep the stateful RoboKpy FK object protected by one lock.
- Return independent numpy data to callers.
- Cache static chain metadata.
- Cache the analytical Jacobian API during construction.
- Provide a robust numerical Jacobian fallback.
- Keep joint normalization and shortest-equivalent utilities pure.

Performance
-----------
The planner uses this facade in a hot path. The implementation therefore
avoids repeated API discovery, repeated metadata construction, and
unnecessary FK calls.

Important
---------
RoboKpy FK is stateful, so the complete FK operation remains under the
same lock.

For callers that need both pose and XYZ, prefer:

    compute_fk_pose_xyz()

This performs exactly one RoboKpy FK operation and returns both results.
"""

from __future__ import annotations

import threading
from typing import Callable, List, Optional, Tuple

import numpy as np

from robokpy_controller.ik_factory import build_model


class KinematicsFacade:
    # ==================================================================
    # Construction
    # ==================================================================

    def __init__(
        self,
        robot_description: str,
        base_link: str,
        tip_link: str,
        backend: str,
        mask: List[int],
        logger,
        fallback_seeds: Optional[List] = None,
    ):
        self._lock = threading.RLock()

        self._base = base_link
        self._tip = tip_link
        self._mask = tuple(mask)
        self._logger = logger

        # --------------------------------------------------------------
        # Fallback IK seeds.
        #
        # solve_ik() always tries the caller-supplied seed first (the
        # live/expected current pose — the common, cheap, usually-
        # sufficient case). If that fails to converge, it retries from
        # each of these in order before giving up. This is what lets a
        # bad seed (arm left in an awkward configuration by a previous
        # recipe, near a singularity/joint limit) recover WITHOUT
        # relaunching the pipeline — relaunching only ever helped
        # because it reset the seed source back to a known-good
        # default; this does the same thing on demand.
        #
        # Empty by default — existing callers see identical behavior
        # (single-seed solve) until they opt in via set_fallback_seeds()
        # or the constructor kwarg.
        # --------------------------------------------------------------
        self._fallback_seeds: List[np.ndarray] = []
        if fallback_seeds:
            self.set_fallback_seeds(fallback_seeds)

        # --------------------------------------------------------------
        # Build RoboKpy model.
        # --------------------------------------------------------------
        self._model = build_model(
            robot_description,
            base_link=base_link,
            tip_link=tip_link,
            backend=backend,
        )

        self._fk = self._model.fk

        # --------------------------------------------------------------
        # Upgrade trajectory planner.
        # --------------------------------------------------------------
        from robokpy.industrial_trajectory import (
            IndustrialTrajectoryPlanner,
        )

        if not isinstance(
            self._model.traj,
            IndustrialTrajectoryPlanner,
        ):
            self._model.traj.__class__ = IndustrialTrajectoryPlanner

        self._traj_planner = self._model.traj

        # --------------------------------------------------------------
        # Cache static chain information.
        # --------------------------------------------------------------
        self._refresh_chain_metadata_locked()

        # --------------------------------------------------------------
        # Cache analytical Jacobian implementation once.
        #
        # The old implementation searched several objects and several
        # signatures on every Jacobian request.
        # --------------------------------------------------------------
        self._jacobian_method: Optional[Callable] = None
        self._jacobian_method_mode: Optional[int] = None
        self._discover_jacobian_api()

        self._logger.debug(
            "[KinematicsFacade] initialized "
            f"chain={self._base}->{self._tip} "
            f"joints={self._joint_names}"
        )

    # ==================================================================
    # Internal metadata
    # ==================================================================

    def _refresh_chain_metadata_locked(self) -> None:
        """
        Refresh cached chain information.

        Caller must hold self._lock.
        """
        self._joint_names = tuple(
            self._model.model.get_joint_names_in_chain(
                self._base,
                self._tip,
            )
        )

        self._active_joints = tuple(
            dict(joint)
            for joint in self._model.model.get_active_joints_in_chain(
                self._base,
                self._tip,
            )
        )

        self._num_joints = len(self._joint_names)

    # ==================================================================
    # Jacobian API discovery
    # ==================================================================

    def _discover_jacobian_api(self) -> None:
        """
        Discover a compatible analytical Jacobian implementation once.

        The old implementation performed API discovery every time
        compute_jacobian() was called. That is unnecessary overhead.

        Stores:
            _jacobian_method
            _jacobian_method_mode

        mode:
            0 -> method(q, base, tip)
            1 -> method(q)
        """
        candidates = (
            self._model,
            getattr(self._model, "model", None),
            self._fk,
        )

        method_names = (
            "jacobian",
            "compute_jacobian",
            "get_jacobian",
        )

        for obj in candidates:
            if obj is None:
                continue

            for name in method_names:
                method = getattr(obj, name, None)

                if not callable(method):
                    continue

                # ------------------------------------------------------
                # Try q, base, tip signature.
                # ------------------------------------------------------
                try:
                    result = method(
                        np.zeros(self._num_joints, dtype=float),
                        self._base,
                        self._tip,
                    )

                    if self._is_valid_jacobian(result):
                        self._jacobian_method = method
                        self._jacobian_method_mode = 0

                        self._logger.debug(
                            "[KinematicsFacade] cached analytical "
                            f"Jacobian API: {type(obj).__name__}.{name}"
                            "(q, base, tip)"
                        )
                        return

                except TypeError:
                    pass
                except Exception:
                    # A method may be callable but reject an artificial
                    # zero configuration. Continue probing.
                    pass

                # ------------------------------------------------------
                # Try q-only signature.
                # ------------------------------------------------------
                try:
                    result = method(
                        np.zeros(self._num_joints, dtype=float),
                    )

                    if self._is_valid_jacobian(result):
                        self._jacobian_method = method
                        self._jacobian_method_mode = 1

                        self._logger.debug(
                            "[KinematicsFacade] cached analytical "
                            f"Jacobian API: {type(obj).__name__}.{name}"
                            "(q)"
                        )
                        return

                except TypeError:
                    pass
                except Exception:
                    pass

        self._logger.debug(
            "[KinematicsFacade] no compatible analytical Jacobian API; "
            "numerical fallback will be used"
        )

    # ==================================================================
    # Properties
    # ==================================================================

    @property
    def model(self):
        """
        Underlying RoboKpy model.

        WARNING
        -------
        Direct access bypasses the facade lock.

        Existing compatibility is preserved, but planning code should
        prefer the facade methods.
        """
        return self._model

    @property
    def traj_planner(self):
        return self._traj_planner

    @property
    def num_joints(self) -> int:
        return self._num_joints

    @property
    def joint_names(self) -> List[str]:
        return list(self._joint_names)

    @property
    def base_link(self) -> str:
        return self._base

    @property
    def tip_link(self) -> str:
        return self._tip

    # ==================================================================
    # Mutators
    # ==================================================================

    def set_tip_link(
        self,
        tip_link: str,
    ) -> None:
        """
        Change the active IK tip link.

        Chain metadata and the cached Jacobian API are refreshed.
        """
        with self._lock:
            self._tip = tip_link

            self._model.ik.tip_link = tip_link

            self._refresh_chain_metadata_locked()

            # Jacobian implementations may depend on the active tip.
            self._jacobian_method = None
            self._jacobian_method_mode = None
            self._discover_jacobian_api()

            self._logger.debug(
                "[KinematicsFacade] tip link changed "
                f"to {tip_link}; "
                f"joints={self._joint_names}"
            )

    # ==================================================================
    # Fallback IK seeds
    # ==================================================================

    def set_fallback_seeds(self, seeds: List) -> None:
        """
        Replace the fallback seed list used by solve_ik() when the
        primary (caller-supplied) seed fails to converge.

        Seeds of the wrong dimension are dropped with a warning rather
        than raising — num_joints may not be finalized yet if this is
        called during construction, and a bad entry here shouldn't be
        fatal to an otherwise-working solver.
        """
        with self._lock:
            cleaned: List[np.ndarray] = []
            for s in seeds:
                arr = np.asarray(s, dtype=float)
                if getattr(self, '_num_joints', None) is not None and \
                        arr.size != self._num_joints:
                    self._logger.warning(
                        "[KinematicsFacade] dropping fallback seed of "
                        f"size {arr.size}, expected {self._num_joints}"
                    )
                    continue
                cleaned.append(arr)
            self._fallback_seeds = cleaned

    def add_fallback_seed(self, seed) -> None:
        """Append one seed (e.g. 'wherever the arm ended up successfully
        last time') to the fallback list without disturbing the rest."""
        with self._lock:
            arr = np.asarray(seed, dtype=float)
            if getattr(self, '_num_joints', None) is not None and \
                    arr.size != self._num_joints:
                self._logger.warning(
                    "[KinematicsFacade] refusing to add fallback seed of "
                    f"size {arr.size}, expected {self._num_joints}"
                )
                return
            self._fallback_seeds.append(arr)

    # ==================================================================
    # IK
    # ==================================================================

    def solve_ik(
        self,
        pose: np.ndarray,
        q_seed: np.ndarray,
    ) -> Optional[np.ndarray]:
        """
        Thread-safe IK.

        Parameters
        ----------
        pose:
            Pose vector expected by RoboKpy.

        q_seed:
            Initial joint configuration.

        Returns
        -------
        numpy.ndarray or None
            Independent copy of the IK solution.
        """
        pose_arr = np.asarray(
            pose,
            dtype=float,
        )

        q_seed_arr = np.asarray(
            q_seed,
            dtype=float,
        )

        if pose_arr.ndim != 1:
            raise ValueError(
                f"IK pose must be 1-D, got shape={pose_arr.shape}"
            )

        if q_seed_arr.ndim != 1:
            raise ValueError(
                f"IK seed must be 1-D, got shape={q_seed_arr.shape}"
            )

        if q_seed_arr.size != self._num_joints:
            raise ValueError(
                "IK seed dimension mismatch: "
                f"got {q_seed_arr.size}, "
                f"expected {self._num_joints}"
            )

        if not np.all(np.isfinite(pose_arr)):
            raise ValueError(
                "IK pose contains non-finite values"
            )

        if not np.all(np.isfinite(q_seed_arr)):
            raise ValueError(
                "IK seed contains non-finite values"
            )

        # Copy only after validation.
        pose_work = np.array(
            pose_arr,
            dtype=float,
            copy=True,
        )

        q_seed_work = np.array(
            q_seed_arr,
            dtype=float,
            copy=True,
        )

        with self._lock:
            solution = self._try_seed_locked(pose_work, q_seed_work)
            if solution is not None:
                return solution

            for i, fallback in enumerate(self._fallback_seeds):
                if fallback.size != self._num_joints:
                    continue
                # Skip a fallback that's ~identical to the seed we just
                # tried — no point retrying the same starting point.
                if np.allclose(fallback, q_seed_work, atol=1e-6):
                    continue

                solution = self._try_seed_locked(pose_work, fallback)
                if solution is not None:
                    self._logger.info(
                        "[KinematicsFacade] IK converged from fallback "
                        f"seed #{i} after primary seed failed"
                    )
                    return solution

            self._logger.debug(
                "[KinematicsFacade] IK failed from primary seed and all "
                f"{len(self._fallback_seeds)} fallback seed(s)"
            )
            return None

    def _try_seed_locked(
        self,
        pose_work: np.ndarray,
        q_seed_work: np.ndarray,
    ) -> Optional[np.ndarray]:
        """One IK attempt from one seed. Caller must hold self._lock."""
        try:
            q = self._model.ik.solve(
                pose_work,
                q0=q_seed_work,
                mask=self._mask,
            )
        except Exception as exc:
            self._logger.debug(
                "[KinematicsFacade] IK exception: %s",
                exc,
            )
            return None

        if not getattr(
            self._model.ik,
            "success",
            False,
        ):
            return None

        if q is None:
            return None

        q_result = np.asarray(
            q,
            dtype=float,
        )

        if q_result.ndim != 1:
            return None

        if q_result.size != self._num_joints:
            return None

        if not np.all(np.isfinite(q_result)):
            return None

        return np.array(
            q_result,
            dtype=float,
            copy=True,
        )

    # ==================================================================
    # FK
    # ==================================================================

    def compute_fk(
        self,
        q: np.ndarray,
    ) -> np.ndarray:
        """
        Thread-safe FK.

        Returns
        -------
        numpy.ndarray
            [x, y, z, qx, qy, qz, qw]
        """
        q_arr = self._validate_joint_vector(
            q,
            "FK joint vector",
        )

        with self._lock:
            self._fk.compute_chain(
                q_arr,
                self._base,
                self._tip,
            )

            pose = np.asarray(
                self._fk.get_pose_quart(),
                dtype=float,
            )

            if pose.ndim != 1 or pose.size != 7:
                raise RuntimeError(
                    "FK pose must contain 7 values "
                    "[x,y,z,qx,qy,qz,qw], "
                    f"got shape={pose.shape}"
                )

            if not np.all(np.isfinite(pose)):
                raise RuntimeError(
                    "FK returned non-finite values"
                )

            return np.array(
                pose,
                dtype=float,
                copy=True,
            )

    def get_fk_xyz(
        self,
        q: np.ndarray,
    ) -> np.ndarray:
        """
        Thread-safe FK returning only XYZ.
        """
        q_arr = self._validate_joint_vector(
            q,
            "FK joint vector",
        )

        with self._lock:
            self._fk.compute_chain(
                q_arr,
                self._base,
                self._tip,
            )

            xyz = np.asarray(
                self._fk.get_xyz(),
                dtype=float,
            )

            if xyz.ndim != 1 or xyz.size != 3:
                raise RuntimeError(
                    "FK xyz must contain 3 values, "
                    f"got shape={xyz.shape}"
                )

            if not np.all(np.isfinite(xyz)):
                raise RuntimeError(
                    "FK xyz contains non-finite values"
                )

            return np.array(
                xyz,
                dtype=float,
                copy=True,
            )

    def compute_fk_pose_xyz(
        self,
        q: np.ndarray,
    ) -> Tuple[np.ndarray, np.ndarray]:
        """
        Compute FK once and return both pose and XYZ.

        This is the preferred method when a caller needs both:

            pose = [x,y,z,qx,qy,qz,qw]
            xyz  = [x,y,z]

        The RoboKpy FK chain is evaluated exactly once.
        """
        q_arr = self._validate_joint_vector(
            q,
            "FK joint vector",
        )

        with self._lock:
            self._fk.compute_chain(
                q_arr,
                self._base,
                self._tip,
            )

            pose = np.asarray(
                self._fk.get_pose_quart(),
                dtype=float,
            )

            if pose.ndim != 1 or pose.size != 7:
                raise RuntimeError(
                    "FK pose must contain 7 values "
                    "[x,y,z,qx,qy,qz,qw], "
                    f"got shape={pose.shape}"
                )

            xyz = np.asarray(
                self._fk.get_xyz(),
                dtype=float,
            )

            if xyz.ndim != 1 or xyz.size != 3:
                raise RuntimeError(
                    "FK xyz must contain 3 values, "
                    f"got shape={xyz.shape}"
                )

            if not np.all(np.isfinite(pose)):
                raise RuntimeError(
                    "FK returned non-finite values"
                )

            if not np.all(np.isfinite(xyz)):
                raise RuntimeError(
                    "FK xyz contains non-finite values"
                )

            return (
                np.array(
                    pose,
                    dtype=float,
                    copy=True,
                ),
                np.array(
                    xyz,
                    dtype=float,
                    copy=True,
                ),
            )

    # ==================================================================
    # Active joints
    # ==================================================================

    def get_active_joints(self) -> List[dict]:
        """
        Return independent copies of active-joint metadata.
        """
        return [
            dict(joint)
            for joint in self._active_joints
        ]

    # ==================================================================
    # Jacobian
    # ==================================================================

    def compute_jacobian(
        self,
        q: np.ndarray,
    ) -> Optional[np.ndarray]:
        """
        Thread-safe geometric Jacobian.

        Returns:
            6 x N matrix

        An analytical implementation is used when available.
        Otherwise a numerical central-difference Jacobian is computed.
        """
        q_arr = self._validate_joint_vector(
            q,
            "Jacobian joint vector",
        )

        with self._lock:
            if self._jacobian_method is not None:
                analytical = self._call_cached_jacobian_locked(
                    q_arr,
                )

                if analytical is not None:
                    return analytical

            return self._numerical_jacobian_locked(
                q_arr,
            )

    def _call_cached_jacobian_locked(
        self,
        q: np.ndarray,
    ) -> Optional[np.ndarray]:
        """
        Call the cached analytical Jacobian implementation.

        Caller must hold self._lock.
        """
        method = self._jacobian_method
        mode = self._jacobian_method_mode

        if method is None or mode is None:
            return None

        try:
            if mode == 0:
                J = method(
                    q,
                    self._base,
                    self._tip,
                )
            else:
                J = method(q)

        except Exception as exc:
            self._logger.debug(
                "[KinematicsFacade] analytical Jacobian failed: %s",
                exc,
            )
            return None

        if not self._is_valid_jacobian(J):
            return None

        J_arr = np.asarray(
            J,
            dtype=float,
        )

        if J_arr.shape == (
            self._num_joints,
            6,
        ):
            return J_arr.T.copy()

        return J_arr.copy()

    def _is_valid_jacobian(
        self,
        J,
    ) -> bool:
        """
        Check whether an object is a usable 6xN or Nx6 Jacobian.
        """
        if J is None:
            return False

        try:
            J_arr = np.asarray(
                J,
                dtype=float,
            )
        except Exception:
            return False

        if J_arr.ndim != 2:
            return False

        valid_shape = (
            J_arr.shape == (
                6,
                self._num_joints,
            )
            or J_arr.shape == (
                self._num_joints,
                6,
            )
        )

        if not valid_shape:
            return False

        return bool(
            np.all(
                np.isfinite(J_arr)
            )
        )

    # ==================================================================
    # Numerical Jacobian
    # ==================================================================

    def _numerical_jacobian_locked(
        self,
        q: np.ndarray,
        eps: float = 1e-6,
    ) -> np.ndarray:
        """
        Numerical geometric Jacobian.

        Uses central finite differences.

        Caller must hold self._lock.
        """
        if eps <= 0.0:
            raise ValueError(
                "Jacobian finite-difference epsilon must be positive"
            )

        n = self._num_joints

        if q.size != n:
            raise ValueError(
                "Jacobian input dimension mismatch"
            )

        J = np.empty(
            (6, n),
            dtype=float,
        )

        # --------------------------------------------------------------
        # Nominal FK.
        # --------------------------------------------------------------
        self._fk.compute_chain(
            q,
            self._base,
            self._tip,
        )

        pose0 = np.asarray(
            self._fk.get_pose_quart(),
            dtype=float,
        )

        if pose0.shape != (7,):
            raise RuntimeError(
                "FK returned invalid pose shape "
                f"{pose0.shape} during Jacobian calculation"
            )

        p0 = pose0[:3]

        # Keep this value because it documents the nominal orientation
        # and protects against accidentally removing the nominal FK in
        # future modifications. The current central difference only
        # requires the +/- orientations.
        quat0 = pose0[3:]
        _ = self._quat_to_rotmat(quat0)

        step = 2.0 * eps

        for i in range(n):
            q_plus = q.copy()
            q_minus = q.copy()

            q_plus[i] += eps
            q_minus[i] -= eps

            # ----------------------------------------------------------
            # +epsilon
            # ----------------------------------------------------------
            self._fk.compute_chain(
                q_plus,
                self._base,
                self._tip,
            )

            pose_plus = np.asarray(
                self._fk.get_pose_quart(),
                dtype=float,
            )

            if pose_plus.shape != (7,):
                raise RuntimeError(
                    "FK returned invalid +epsilon pose shape"
                )

            p_plus = pose_plus[:3].copy()
            R_plus = self._quat_to_rotmat(
                pose_plus[3:]
            )

            # ----------------------------------------------------------
            # -epsilon
            # ----------------------------------------------------------
            self._fk.compute_chain(
                q_minus,
                self._base,
                self._tip,
            )

            pose_minus = np.asarray(
                self._fk.get_pose_quart(),
                dtype=float,
            )

            if pose_minus.shape != (7,):
                raise RuntimeError(
                    "FK returned invalid -epsilon pose shape"
                )

            p_minus = pose_minus[:3].copy()
            R_minus = self._quat_to_rotmat(
                pose_minus[3:]
            )

            # ----------------------------------------------------------
            # Translational Jacobian.
            # ----------------------------------------------------------
            J[:3, i] = (
                p_plus - p_minus
            ) / step

            # ----------------------------------------------------------
            # Rotational Jacobian.
            # ----------------------------------------------------------
            dR = R_plus @ R_minus.T

            axis, angle = self._rotmat_to_axis_angle(
                dR
            )

            J[3:, i] = (
                axis * angle / step
            )

        # --------------------------------------------------------------
        # Restore nominal state.
        # --------------------------------------------------------------
        self._fk.compute_chain(
            q,
            self._base,
            self._tip,
        )

        if not np.all(np.isfinite(J)):
            raise RuntimeError(
                "numerical Jacobian contains non-finite values"
            )

        return J

    # ==================================================================
    # Rotation utilities
    # ==================================================================

    @staticmethod
    def _quat_to_rotmat(
        q: np.ndarray,
    ) -> np.ndarray:
        """
        Convert quaternion [x,y,z,w] to a rotation matrix.
        """
        q_arr = np.asarray(
            q,
            dtype=float,
        )

        if q_arr.shape != (4,):
            raise ValueError(
                "quaternion must have shape (4,)"
            )

        if not np.all(np.isfinite(q_arr)):
            raise ValueError(
                "quaternion contains non-finite values"
            )

        norm = float(
            np.linalg.norm(q_arr)
        )

        if norm < 1e-12:
            raise ValueError(
                "cannot convert zero-length quaternion"
            )

        x, y, z, w = q_arr / norm

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

    @staticmethod
    def _rotmat_to_axis_angle(
        R: np.ndarray,
    ) -> Tuple[np.ndarray, float]:
        """
        Convert rotation matrix to axis-angle.

        Returns:
            (unit_axis, angle)
        """
        R = np.asarray(
            R,
            dtype=float,
        )

        if R.shape != (3, 3):
            raise ValueError(
                "rotation matrix must have shape (3,3)"
            )

        # --------------------------------------------------------------
        # Fast path:
        #
        # For finite-difference rotations R should already be very
        # close to SO(3). Avoid the SVD used by the previous version
        # on every Jacobian column.
        # --------------------------------------------------------------
        RtR = R.T @ R

        if not np.allclose(
            RtR,
            np.eye(3),
            rtol=1e-6,
            atol=1e-8,
        ) or not np.isclose(
            np.linalg.det(R),
            1.0,
            rtol=1e-6,
            atol=1e-8,
        ):
            U, _, Vt = np.linalg.svd(R)
            R = U @ Vt

            if np.linalg.det(R) < 0.0:
                U[:, -1] *= -1.0
                R = U @ Vt

        trace_term = (
            float(np.trace(R)) - 1.0
        ) * 0.5

        angle = float(
            np.arccos(
                np.clip(
                    trace_term,
                    -1.0,
                    1.0,
                )
            )
        )

        # --------------------------------------------------------------
        # Very small rotation.
        # --------------------------------------------------------------
        if angle < 1e-8:
            return (
                np.array(
                    [0.0, 0.0, 1.0],
                    dtype=float,
                ),
                0.0,
            )

        sin_angle = float(
            np.sin(angle)
        )

        # --------------------------------------------------------------
        # Normal case.
        # --------------------------------------------------------------
        if abs(sin_angle) > 1e-7:
            axis = np.array(
                [
                    R[2, 1] - R[1, 2],
                    R[0, 2] - R[2, 0],
                    R[1, 0] - R[0, 1],
                ],
                dtype=float,
            )

            axis /= (
                2.0 * sin_angle
            )

            norm = float(
                np.linalg.norm(axis)
            )

            if norm > 1e-10:
                axis /= norm

                return (
                    axis,
                    angle,
                )

        # --------------------------------------------------------------
        # Near pi.
        # --------------------------------------------------------------
        diag = np.diag(R)

        axis = np.zeros(
            3,
            dtype=float,
        )

        i = int(
            np.argmax(diag)
        )

        axis[i] = np.sqrt(
            max(
                (
                    diag[i] + 1.0
                ) * 0.5,
                0.0,
            )
        )

        if axis[i] > 1e-8:
            j = (i + 1) % 3
            k = (i + 2) % 3

            denom = (
                4.0 * axis[i]
            )

            axis[j] = (
                R[j, i] + R[i, j]
            ) / denom

            axis[k] = (
                R[k, i] + R[i, k]
            ) / denom

            norm = float(
                np.linalg.norm(axis)
            )

            if norm > 1e-10:
                axis /= norm

                return (
                    axis,
                    angle,
                )

        return (
            np.array(
                [0.0, 0.0, 1.0],
                dtype=float,
            ),
            angle,
        )

    # ==================================================================
    # Joint validation
    # ==================================================================

    def _validate_joint_vector(
        self,
        q: np.ndarray,
        name: str,
    ) -> np.ndarray:
        """
        Validate a joint vector.

        A contiguous float64 array is returned so the underlying
        RoboKpy/Python layer receives a predictable representation.
        """
        q_arr = np.asarray(
            q,
            dtype=float,
        )

        if q_arr.ndim != 1:
            raise ValueError(
                f"{name} must be 1-D, "
                f"got shape={q_arr.shape}"
            )

        if q_arr.size != self._num_joints:
            raise ValueError(
                f"{name} dimension mismatch: "
                f"got {q_arr.size}, "
                f"expected {self._num_joints}"
            )

        if not np.all(np.isfinite(q_arr)):
            raise ValueError(
                f"{name} contains non-finite values"
            )

        # Avoid a copy when already suitable.
        if (
            q_arr.dtype == np.float64
            and q_arr.flags.c_contiguous
        ):
            return q_arr

        return np.ascontiguousarray(
            q_arr,
            dtype=np.float64,
        )

    # ==================================================================
    # Joint utilities
    # ==================================================================

    @staticmethod
    def normalize_joints(
        q: np.ndarray,
        active_joints: List[dict],
    ) -> np.ndarray:
        """
        Normalize revolute/continuous joints to [-pi, pi).

        Prismatic joints are unchanged.
        """
        q_norm = np.asarray(
            q,
            dtype=float,
        ).copy()

        if q_norm.ndim != 1:
            raise ValueError(
                "joint vector must be 1-D"
            )

        if q_norm.size != len(active_joints):
            raise ValueError(
                "joint vector and active-joint "
                "metadata lengths do not match"
            )

        two_pi = 2.0 * np.pi

        for i, joint in enumerate(active_joints):
            joint_type = joint.get("type")

            if joint_type in (
                "revolute",
                "continuous",
            ):
                q_norm[i] = (
                    (
                        q_norm[i] + np.pi
                    )
                    % two_pi
                ) - np.pi

        return q_norm

    @staticmethod
    def shortest_equivalent(
        q_target: np.ndarray,
        q_seed: np.ndarray,
        active_joints: List[dict],
        pos_limits: Optional[np.ndarray] = None,
    ) -> np.ndarray:
        """
        Select the equivalent revolute angle closest to q_seed.

        For limited revolute joints, the wrapped candidate is only used
        when it remains inside supplied position limits.

        Continuous joints are always allowed to wrap.
        """
        q_target_arr = np.asarray(
            q_target,
            dtype=float,
        )

        q_seed_arr = np.asarray(
            q_seed,
            dtype=float,
        )

        if q_target_arr.ndim != 1:
            raise ValueError(
                "q_target must be 1-D"
            )

        if q_seed_arr.ndim != 1:
            raise ValueError(
                "q_seed must be 1-D"
            )

        n = q_target_arr.size

        if q_seed_arr.size != n:
            raise ValueError(
                "q_target and q_seed lengths differ"
            )

        if n != len(active_joints):
            raise ValueError(
                "joint vector and active-joint "
                "metadata lengths differ"
            )

        # --------------------------------------------------------------
        # Validate position limits ONCE, not once per joint.
        # --------------------------------------------------------------
        limits = None

        if pos_limits is not None:
            limits = np.asarray(
                pos_limits,
                dtype=float,
            )

            expected_shape = (
                len(active_joints),
                2,
            )

            if limits.shape != expected_shape:
                raise ValueError(
                    "pos_limits must have shape "
                    f"{expected_shape}"
                )

        q_adj = q_target_arr.copy()

        two_pi = 2.0 * np.pi

        for i, joint in enumerate(active_joints):
            joint_type = joint.get("type")

            if joint_type not in (
                "revolute",
                "continuous",
            ):
                continue

            delta = (
                q_target_arr[i]
                - q_seed_arr[i]
            )

            wrapped = (
                (
                    delta + np.pi
                )
                % two_pi
            ) - np.pi

            candidate = (
                q_seed_arr[i]
                + wrapped
            )

            # ----------------------------------------------------------
            # Continuous joint or no position limits.
            # ----------------------------------------------------------
            if (
                joint_type == "continuous"
                or limits is None
            ):
                q_adj[i] = candidate
                continue

            # ----------------------------------------------------------
            # Limited revolute joint.
            # ----------------------------------------------------------
            lo = limits[i, 0]
            hi = limits[i, 1]

            if lo <= candidate <= hi:
                q_adj[i] = candidate

        return q_adj