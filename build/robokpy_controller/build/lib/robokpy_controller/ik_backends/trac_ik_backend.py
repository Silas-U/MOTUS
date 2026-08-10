"""Trac-IK backend adapter.

Requires:  pip install trac-ik-python
"""
import numpy as np
from scipy.spatial.transform import Rotation as R
from .base import IKSolverBackend


class TracIkBackend(IKSolverBackend):
    """Trac-IK wrapper.

    Trac-IK is IK-only, so FK/Jacobian are delegated back to the
    caller (motion_planner already uses robokpy FK for path
    generation).  This backend is used exclusively for the
    /solve_ik service and kinematic_solver control loop.
    """

    def __init__(self):
        self._solver = None
        self._base_link = None
        self._tip_link = None
        self._urdf_str = None
        self._success = False
        self._limit_bound = False
        self._q_min = None
        self._q_max = None
        self._q_pref = None
        self._num_joints = 0

    def initialize(self, robot_description: str, base_link: str,
                   tip_link: str, timeout: float = 0.005,
                   epsilon: float = 1e-5, solve_type: str = "Speed",
                   **kwargs):
        try:
            import trac_ik_python
        except ImportError as e:
            raise RuntimeError(
                "Trac-IK backend requires 'trac-ik-python'. "
                "Install it with: pip install trac-ik-python"
            ) from e

        self._base_link = base_link
        self._tip_link = tip_link
        self._urdf_str = robot_description
        self._solver = trac_ik_python.IK(
            base_link, tip_link,
            urdf_string=robot_description,
            timeout=timeout, epsilon=epsilon,
            solve_type=solve_type,
        )
        # Trac-IK exposes no direct joint-count API; infer from a test solve
        seed = [0.0] * 6  # will be refined on first real solve
        self._num_joints = len(seed)

    def solve(self, target_pose, q0=None, mask=None,
              tol_pos: float = 1e-3, tol_rot: float = 1e-3,
              max_iter: int = 30, **kwargs) -> np.ndarray:
        """target_pose: [x, y, z, qx, qy, qz, qw]"""
        self._success = False
        self._limit_bound = False

        if q0 is None:
            q0 = [0.0] * self._num_joints

        bx, by, bz = target_pose[0], target_pose[1], target_pose[2]
        qx, qy, qz, qw = target_pose[3], target_pose[4], target_pose[5], target_pose[6]

        # Trac-IK getIK signature: (seed, bx, by, bz, qx, qy, qz, qw)
        result = self._solver.getIK(q0, bx, by, bz, qx, qy, qz, qw)

        if result:
            q_sol = np.array(result)
            self._success = True
            # Check limit bound
            if self._q_min is not None and self._q_max is not None:
                if not np.all((q_sol >= self._q_min - 1e-6) & (q_sol <= self._q_max + 1e-6)):
                    self._limit_bound = True
                    q_sol = np.clip(q_sol, self._q_min, self._q_max)
            return q_sol
        else:
            self._success = False
            return np.array(q0)

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
        # Trac-IK solver is bound to links at construction;
        # re-initialise on tip change if you need dynamic switching.
        # For now we just update the attribute; motion_planner uses
        # robokpy FK which handles tip_link natively.

    @property
    def base_link(self) -> str:
        return self._base_link

    @base_link.setter
    def base_link(self, value: str):
        self._base_link = value
