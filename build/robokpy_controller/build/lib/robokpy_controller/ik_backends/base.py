"""Abstract base class for IK solver backends."""
from abc import ABC, abstractmethod
import numpy as np


class IKSolverBackend(ABC):
    """Common interface for all IK backends.

    Every backend must expose the same surface that the four
    robokpy_controller nodes (kinematic_solver, motion_planner,
    pose_target_interface, robot_state_manager) already expect
    from robokpy.InverseKinematics.
    """

    @abstractmethod
    def initialize(self, robot_description: str, base_link: str,
                   tip_link: str, **kwargs):
        """Load URDF, build chain, prepare solver."""
        ...

    @abstractmethod
    def solve(self, target_pose, q0=None, mask=None,
              tol_pos: float = 1e-3, tol_rot: float = 1e-3,
              max_iter: int = 30, **kwargs) -> np.ndarray:
        """Solve IK.  Must set self.success and self.limit_bound."""
        ...

    @property
    @abstractmethod
    def success(self) -> bool:
        """True if the last solve() converged."""
        ...

    @property
    @abstractmethod
    def limit_bound(self) -> bool:
        """True if the last solve() clamped to joint limits."""
        ...

    @abstractmethod
    def set_joint_limits(self, q_min, q_max):
        """Hard limits for the active chain."""
        ...

    @abstractmethod
    def set_preferred_posture(self, q_pref):
        """Null-space posture bias."""
        ...

    @property
    @abstractmethod
    def tip_link(self) -> str:
        ...

    @tip_link.setter
    @abstractmethod
    def tip_link(self, value: str):
        ...

    @property
    @abstractmethod
    def base_link(self) -> str:
        ...

    @base_link.setter
    @abstractmethod
    def base_link(self, value: str):
        ...
