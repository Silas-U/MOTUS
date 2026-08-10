"""RoboKpy IK backend adapter — thin wrapper around existing solver."""
import numpy as np
from robokpy import Init_Model
from .base import IKSolverBackend


class RobokpyBackend(IKSolverBackend):
    """Wraps robokpy.InverseKinematics to satisfy IKSolverBackend."""

    def __init__(self):
        self._ik = None
        self._model = None
        self._fk = None
        self._jacobian = None

    def initialize(self, robot_description: str, base_link: str,
                   tip_link: str, **kwargs):
        # Build a temporary Init_Model just to grab the internal solver.
        # We keep the model/fk/jacobian references so tip_link swaps work.
        tmp = Init_Model(robot_description, base_link=base_link, tip_link=tip_link)
        self._model = tmp.model
        self._fk = tmp.fk
        self._jacobian = tmp.jacobian
        self._ik = tmp.ik

    def solve(self, target_pose, q0=None, mask=None,
              tol_pos: float = 1e-3, tol_rot: float = 1e-3,
              max_iter: int = 30, **kwargs) -> np.ndarray:
        return self._ik.solve(
            target_pose, q0=q0, mask=mask,
            tol_pos=tol_pos, tol_rot=tol_rot, max_iter=max_iter,
            **kwargs
        )

    @property
    def success(self) -> bool:
        return self._ik.success

    @property
    def limit_bound(self) -> bool:
        return self._ik.limit_bound

    def set_joint_limits(self, q_min, q_max):
        self._ik.set_joint_limits(q_min, q_max)

    def set_preferred_posture(self, q_pref):
        self._ik.set_preferred_posture(q_pref)

    @property
    def tip_link(self) -> str:
        return self._ik.tip_link

    @tip_link.setter
    def tip_link(self, value: str):
        self._ik.tip_link = value

    @property
    def base_link(self) -> str:
        return self._ik.base_link

    @base_link.setter
    def base_link(self, value: str):
        self._ik.base_link = value
