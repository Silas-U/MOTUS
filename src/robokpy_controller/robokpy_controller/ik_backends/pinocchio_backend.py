"""Pinocchio backend adapter.

Requires:  pip install pin

Handles URDFs where model.nq > active_joint_count by mapping
only the joints in the base_link -> tip_link chain into the
full Pinocchio configuration vector.
"""
import numpy as np
from .base import IKSolverBackend

try:
    import pinocchio as pin
    _HAS_PINOCCHIO = True
except ImportError:
    _HAS_PINOCCHIO = False


class PinocchioBackend(IKSolverBackend):
    """Pinocchio-based IK using damped Newton iteration.

    Only the joints in the kinematic chain from base_link to
    tip_link are controlled; the rest of the configuration vector
    is kept at neutral values.
    """

    def __init__(self):
        self._model = None
        self._data = None
        self._ee_id = None
        self._base_link = None
        self._tip_link = None
        self._success = False
        self._limit_bound = False
        self._q_min = None
        self._q_max = None
        self._q_pref = None

        # Mapping: active joint index -> idx_q in full configuration
        self._active_q_indices = []
        self._num_active = 0

    def initialize(self, robot_description: str, base_link: str,
                   tip_link: str, **kwargs):
        if not _HAS_PINOCCHIO:
            raise RuntimeError(
                "Pinocchio backend requires 'pinocchio'. "
                "Install it with: pip install pin"
            )

        import tempfile
        with tempfile.NamedTemporaryFile(mode='w', suffix='.urdf', delete=False) as f:
            f.write(robot_description)
            urdf_path = f.name

        self._model = pin.buildModelFromUrdf(urdf_path)
        self._data = self._model.createData()
        self._base_link = base_link
        self._tip_link = tip_link

        # Validate frames exist
        self._validate_frame(base_link, 'base_link')
        self._validate_frame(tip_link, 'tip_link')

        self._ee_id = self._model.getFrameId(tip_link)
        self._build_chain_map(base_link, tip_link)

    def _validate_frame(self, link_name: str, role: str):
        """Raise clear error if link doesn't exist in URDF."""
        frame_id = self._model.getFrameId(link_name)
        if frame_id >= len(self._model.frames):
            available = [self._model.frames[i].name for i in range(len(self._model.frames))]
            raise ValueError(
                f"PinocchioBackend: {role} '{link_name}' not found in URDF. "
                f"Available frames: {available}"
            )

    def _build_chain_map(self, base_link: str, tip_link: str):
        """Traverse from tip joint back to base joint, collecting
        active joint configuration indices (in base->tip order)."""
        tip_frame_id = self._model.getFrameId(tip_link)
        tip_joint_id = self._model.frames[tip_frame_id].parentJoint

        base_frame_id = self._model.getFrameId(base_link)
        base_joint_id = self._model.frames[base_frame_id].parentJoint

        self._active_q_indices = []
        current = tip_joint_id
        while current != base_joint_id and current > 0:
            joint = self._model.joints[current]
            if joint.nq > 0:          # skip fixed joints
                self._active_q_indices.insert(0, joint.idx_q)
            current = self._model.parents[current]

        self._num_active = len(self._active_q_indices)
        if self._num_active == 0:
            raise ValueError(
                f"PinocchioBackend: no active joints found between "
                f"'{base_link}' and '{tip_link}'"
            )

    def _expand_q(self, q_active: np.ndarray) -> np.ndarray:
        """Embed active joints into a full configuration vector."""
        q_full = pin.neutral(self._model)
        for i, idx in enumerate(self._active_q_indices):
            q_full[idx] = q_active[i]
        return q_full

    def _extract_q(self, q_full: np.ndarray) -> np.ndarray:
        """Extract active joints from a full configuration vector."""
        return np.array([q_full[idx] for idx in self._active_q_indices])

    def solve(self, target_pose, q0=None, mask=None,
              tol_pos: float = 1e-3, tol_rot: float = 1e-3,
              max_iter: int = 30, **kwargs) -> np.ndarray:
        """target_pose: [x, y, z, qx, qy, qz, qw]"""
        from scipy.spatial.transform import Rotation as R

        # Seed: either provided or neutral
        if q0 is not None and len(q0) == self._num_active:
            q_active = np.array(q0, dtype=float)
        elif q0 is not None and len(q0) != self._num_active:
            # Caller passed a full configuration — extract active part
            q_active = self._extract_q(np.array(q0, dtype=float))
        else:
            q_active = np.zeros(self._num_active)

        q_full = self._expand_q(q_active)
        mask_arr = np.array(mask if mask is not None else [1, 1, 1, 1, 1, 1], dtype=float)

        p_des = np.array(target_pose[:3])
        q_des = np.array(target_pose[3:7])
        q_des = q_des / (np.linalg.norm(q_des) + 1e-12)

        self._success = False
        self._limit_bound = False

        for _ in range(max_iter):
            pin.forwardKinematics(self._model, self._data, q_full)
            pin.updateFramePlacements(self._model, self._data)
            T = self._data.oMf[self._ee_id]
            p_cur = T.translation
            R_cur = T.rotation
            q_cur = R.from_matrix(R_cur).as_quat()

            if np.dot(q_des, q_cur) < 0:
                q_cur = -q_cur

            e_pos = (p_des - p_cur) * mask_arr[:3]
            q_err = self._quat_mul(q_des, self._quat_conj(q_cur))
            e_rot = R.from_quat(q_err).as_rotvec() * mask_arr[3:]

            pos_err = float(np.linalg.norm(e_pos))
            rot_err = float(np.linalg.norm(e_rot))

            if pos_err < tol_pos and rot_err < tol_rot:
                self._success = True
                return self._extract_q(q_full)

            # Jacobian: 6 x nv (full model)
            J_full = pin.computeFrameJacobian(
                self._model, self._data, q_full, self._ee_id,
                pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)[:6, :]

            # Extract only the active-joint columns
            J_active = np.zeros((6, self._num_active))
            for i, idx in enumerate(self._active_q_indices):
                J_active[:, i] = J_full[:, idx]

            W = np.diag(mask_arr)
            J_w = W @ J_active
            err_w = W @ np.concatenate([e_pos, e_rot])

            damp = 1e-2 + 0.1 * float(np.linalg.norm(err_w))
            try:
                x = np.linalg.solve(
                    J_w @ J_w.T + damp**2 * np.eye(6),
                    err_w
                )
                dq_active = J_w.T @ x
            except np.linalg.LinAlgError:
                dq_active = np.linalg.pinv(J_w) @ err_w

            # Null-space posture bias
            if self._q_pref is not None:
                dq_posture = self._q_pref - q_active
                dq_posture = (dq_posture + np.pi) % (2 * np.pi) - np.pi
                N = np.eye(self._num_active) - np.linalg.pinv(J_w) @ J_w
                dq_active += 0.5 * (N @ dq_posture)

            # Update active joints
            q_active += dq_active

            # Hard limits
            if self._q_min is not None and self._q_max is not None:
                clamped = np.clip(q_active, self._q_min, self._q_max)
                if not np.allclose(clamped, q_active, atol=1e-9):
                    self._limit_bound = True
                q_active = clamped

            # Step-size convergence check
            if float(np.linalg.norm(dq_active)) < 1e-8:
                self._success = (pos_err < tol_pos * 10) and (rot_err < tol_rot * 10)
                return self._extract_q(q_full)

            # Rebuild full configuration for next FK
            q_full = self._expand_q(q_active)

        self._success = False
        return self._extract_q(q_full)

    @staticmethod
    def _quat_mul(q1, q2):
        x1, y1, z1, w1 = q1
        x2, y2, z2, w2 = q2
        return np.array([
            w1*x2 + x1*w2 + y1*z2 - z1*y2,
            w1*y2 - x1*z2 + y1*w2 + z1*x2,
            w1*z2 + x1*y2 - y1*x2 + z1*w2,
            w1*w2 - x1*x2 - y1*y2 - z1*z2,
        ])

    @staticmethod
    def _quat_conj(q):
        return np.array([-q[0], -q[1], -q[2], q[3]])

    @property
    def success(self) -> bool:
        return self._success

    @property
    def limit_bound(self) -> bool:
        return self._limit_bound

    def set_joint_limits(self, q_min, q_max):
        self._q_min = np.array(q_min) if q_min is not None else None
        self._q_max = np.array(q_max) if q_max is not None else None

    def set_preferred_posture(self, q_pref):
        self._q_pref = np.array(q_pref) if q_pref is not None else None

    @property
    def tip_link(self) -> str:
        return self._tip_link

    @tip_link.setter
    def tip_link(self, value: str):
        self._tip_link = value
        if self._model is not None:
            self._validate_frame(value, 'tip_link')
            self._ee_id = self._model.getFrameId(value)
            self._build_chain_map(self._base_link, value)

    @property
    def base_link(self) -> str:
        return self._base_link

    @base_link.setter
    def base_link(self, value: str):
        self._base_link = value
        if self._model is not None:
            self._validate_frame(value, 'base_link')
            self._build_chain_map(value, self._tip_link)
