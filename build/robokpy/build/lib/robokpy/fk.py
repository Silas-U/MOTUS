import numpy as np
from scipy.spatial.transform import Rotation as R


class ForwardKinematics:

    def __init__(self, model):
        self.model = model

        # ── Cached state (populated by compute / compute_chain) ──
        self.tf_tree      = []
        self.tf_end       = np.eye(4)
        self.joint_origins = []   # o_i  — end-effector-side origin per active joint
        self.joint_axes    = []   # z_i  — joint axis in world frame per active joint
        self.active_joints = []   # ordered list of active joint dicts

        # ── Pose cache (lazy, cleared on each compute) ──
        self._pose_cache   = None   # [x,y,z,qx,qy,qz,qw]

    # =========================================================
    # BASIC TRANSFORM PRIMITIVES
    # =========================================================

    @staticmethod
    def _translation(x, y, z) -> np.ndarray:
        T = np.eye(4)
        T[0, 3] = x
        T[1, 3] = y
        T[2, 3] = z
        return T

    @staticmethod
    def _rotx(theta) -> np.ndarray:
        c, s = np.cos(theta), np.sin(theta)
        return np.array([[1,0,0,0],[0,c,-s,0],[0,s,c,0],[0,0,0,1]], dtype=float)

    @staticmethod
    def _roty(theta) -> np.ndarray:
        c, s = np.cos(theta), np.sin(theta)
        return np.array([[c,0,s,0],[0,1,0,0],[-s,0,c,0],[0,0,0,1]], dtype=float)

    @staticmethod
    def _rotz(theta) -> np.ndarray:
        c, s = np.cos(theta), np.sin(theta)
        return np.array([[c,-s,0,0],[s,c,0,0],[0,0,1,0],[0,0,0,1]], dtype=float)

    
    def _rpy_matrix(self, r, p, y) -> np.ndarray:
        return self._rotz(y) @ self._roty(p) @ self._rotx(r)

    @staticmethod
    def _axis_angle_rotation(axis: np.ndarray, theta: float) -> np.ndarray:
        """
        General axis-angle rotation via Rodrigues' formula.
        Handles any unit-vector axis, not just cardinal axes.
        Returns a 4x4 homogeneous matrix.
        """
        axis = axis / (np.linalg.norm(axis) + 1e-12)
        c, s  = np.cos(theta), np.sin(theta)
        t     = 1.0 - c
        x, y, z = axis

        R_mat = np.array([
            [t*x*x + c,   t*x*y - s*z, t*x*z + s*y],
            [t*x*y + s*z, t*y*y + c,   t*y*z - s*x],
            [t*x*z - s*y, t*y*z + s*x, t*z*z + c  ],
        ], dtype=float)

        T = np.eye(4)
        T[:3, :3] = R_mat
        return T

    # =========================================================
    # JOINT TRANSFORM
    # =========================================================

    def joint_transform(self, joint: dict, q_value: float = 0.0) -> np.ndarray:
        """
        Compute the 4x4 homogeneous transform for a single joint
        given its current joint value q_value.

        Supports arbitrary rotation axes via Rodrigues' formula —
        not limited to cardinal axes.
        """
        # Wrap continuous joint angle into (-pi, pi]
        if joint["type"] == "continuous":
            q_value = np.mod(q_value + np.pi, 2.0 * np.pi) - np.pi

        # Static origin transform
        x, y, z = map(float, joint["xyz"].split())
        r, p, yaw = map(float, joint["rpy"].split())
        T_origin = self._translation(x, y, z) @ self._rpy_matrix(r, p, yaw)

        jtype = joint["type"]
        axis  = np.array(list(map(float, joint["axis"].split())), dtype=float)
        axis_norm = np.linalg.norm(axis)

        if jtype in ("revolute", "continuous"):
            if axis_norm < 1e-9:
                # Degenerate axis — treat as identity rotation
                T_joint = np.eye(4)
            else:
                T_joint = self._axis_angle_rotation(axis, q_value)

        elif jtype == "prismatic":
            if axis_norm < 1e-9:
                T_joint = np.eye(4)
            else:
                T_joint = self._translation(
                    *(axis / axis_norm * q_value)
                )

        else:  # fixed or unknown
            T_joint = np.eye(4)

        return T_origin @ T_joint

    # =========================================================
    # FULL-ROBOT FK
    # =========================================================

    def compute(self, q_list) -> list:
        """
        Compute FK for the full robot joint list.

        Populates:
          self.tf_tree      — list of cumulative transforms (one per joint + base)
          self.tf_end       — final end-effector transform
          self.joint_origins — world-frame origins of active joints
          self.joint_axes    — world-frame axes of active joints
          self.active_joints — ordered active joint dicts
        """
        self._pose_cache = None   # invalidate cached pose

        joints      = self.model.get_joints()
        active_jnts = [j for j in joints if j["type"] in
                       ("revolute", "prismatic", "continuous")]

        if len(q_list) != len(active_jnts):
            raise ValueError(
                f"DOF mismatch: expected {len(active_jnts)}, got {len(q_list)}"
            )

        T          = np.eye(4)
        qi         = 0
        tf_tree    = [T.copy()]

        joint_origins  = []
        joint_axes     = []
        active_joints  = []

        for joint in joints:

            if joint["type"] in ("revolute", "prismatic", "continuous"):
                T_joint = self.joint_transform(joint, q_list[qi])
                joint["q_value"] = q_list[qi]
                qi += 1
            else:
                T_joint = self.joint_transform(joint)

            T = T @ T_joint
            tf_tree.append(T.copy())

            # Populate Jacobian data for active joints only
            if joint["type"] in ("revolute", "prismatic", "continuous"):
                o_i   = T[:3, 3]
                R_i   = T[:3, :3]
                axis  = np.array(list(map(float, joint["axis"].split())), dtype=float)
                z_i   = R_i @ (axis / (np.linalg.norm(axis) + 1e-12))

                joint_origins.append(o_i.copy())
                joint_axes.append(z_i.copy())
                active_joints.append(joint)

        self.tf_tree       = tf_tree
        self.tf_end        = tf_tree[-1].copy()
        self.joint_origins = joint_origins
        self.joint_axes    = joint_axes
        self.active_joints = active_joints

        return tf_tree

    # =========================================================
    # CHAIN FK
    # =========================================================

    def compute_chain(self, q_list, base_link: str, end_link: str) -> list:
        """
        Compute FK for a specific kinematic chain.
        Uses model.build_chain to resolve the joint list.
        """
        self._pose_cache = None

        joints = self.model.build_chain(base_link, end_link)

        active_in_chain = [j for j in joints if j["type"] in
                           ("revolute", "prismatic", "continuous")]

        if len(q_list) != len(active_in_chain):
            raise ValueError(
                f"DOF mismatch for chain {base_link}->{end_link}: "
                f"expected {len(active_in_chain)}, got {len(q_list)}"
            )

        T          = np.eye(4)
        qi         = 0
        tf_tree    = [T.copy()]

        joint_origins = []
        joint_axes    = []
        active_joints = []

        for joint in joints:

            if joint["type"] in ("revolute", "prismatic", "continuous"):
                T_joint = self.joint_transform(joint, q_list[qi])
                joint["q_value"] = q_list[qi]
                qi += 1
            else:
                T_joint = self.joint_transform(joint)

            T = T @ T_joint
            tf_tree.append(T.copy())

            if joint["type"] in ("revolute", "prismatic", "continuous"):
                o_i  = T[:3, 3]
                R_i  = T[:3, :3]
                axis = np.array(list(map(float, joint["axis"].split())), dtype=float)
                z_i  = R_i @ (axis / (np.linalg.norm(axis) + 1e-12))

                joint_origins.append(o_i.copy())
                joint_axes.append(z_i.copy())
                active_joints.append(joint)

        self.tf_tree       = tf_tree
        self.tf_end        = tf_tree[-1].copy()
        self.joint_origins = joint_origins
        self.joint_axes    = joint_axes
        self.active_joints = active_joints

        return tf_tree

    # =========================================================
    # POSE ACCESSORS  (lazy cached)
    # =========================================================

    def _ensure_pose(self):
        """Compute and cache [x,y,z,qx,qy,qz,qw] from tf_end."""
        if self._pose_cache is None:
            T   = self.tf_end
            pos = T[:3, 3]
            quat = R.from_matrix(T[:3, :3]).as_quat(canonical=False)
            self._pose_cache = np.concatenate([pos, quat])
        return self._pose_cache

    def get_pose_quart(self) -> np.ndarray:
        """Return [x, y, z, qx, qy, qz, qw]."""
        return self._ensure_pose().copy()

    def get_xyz(self) -> np.ndarray:
        return self._ensure_pose()[:3].copy()

    def get_quart(self) -> np.ndarray:
        return self._ensure_pose()[3:].copy()

    def get_pose_euler(self) -> np.ndarray:
        """Return [x, y, z, roll, pitch, yaw] in radians."""
        pose = self._ensure_pose()
        euler = R.from_quat(pose[3:]).as_euler('xyz')
        return np.concatenate([pose[:3], euler])

    def get_rotation_matrix(self) -> np.ndarray:
        return self.tf_end[:3, :3].copy()

    def get_tf(self) -> np.ndarray:
        return self.tf_end.copy()

    def get_tf_tree(self) -> list:
        return self.tf_tree

    # =========================================================
    # JOINT STATE ACCESSOR
    # =========================================================

    def get_joint_states(self, in_degrees: bool = False) -> np.ndarray:
        """Return current joint values from the last compute() call."""
        vals = np.array([j.get("q_value", 0.0) for j in self.active_joints])
        if in_degrees:
            revolute_mask = np.array([
                j["type"] in ("revolute", "continuous")
                for j in self.active_joints
            ])
            vals[revolute_mask] = np.degrees(vals[revolute_mask])
        return vals

    # =========================================================
    # UTILITIES
    # =========================================================

    @staticmethod
    def matrix_to_pose(T: np.ndarray):
        """Return (position, quaternion) from a 4x4 transform."""
        pos  = T[:3, 3]
        quat = R.from_matrix(T[:3, :3]).as_quat()
        return pos, quat

    @staticmethod
    def quaternion_to_euler(quat: np.ndarray) -> np.ndarray:
        return R.from_quat(quat).as_euler('xyz')

    # ── Legacy aliases (backward compatibility) ──────────────
    def transform(self, x, y, z):
        return self._translation(x, y, z)

    def rotx(self, theta):
        return self._rotx(theta)

    def roty(self, theta):
        return self._roty(theta)

    def rotz(self, theta):
        return self._rotz(theta)

    def rpy_matrix(self, r, p, y):
        return self._rpy_matrix(r, p, y)

    def tf_to_pose(self, T: np.ndarray) -> np.ndarray:
        pos  = T[:3, 3]
        quat = R.from_matrix(T[:3, :3]).as_quat(canonical=False)
        return np.concatenate([pos, quat])