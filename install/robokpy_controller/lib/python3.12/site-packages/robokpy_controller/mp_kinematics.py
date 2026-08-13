"""
mp_kinematics.py  —  KinematicsFacade

All model/IK/FK access is serialised behind one lock. Callers receive
*copies* of numpy arrays so the lock can be released immediately.
"""

import threading
import numpy as np
from typing import Optional, List

from robokpy_controller.ik_factory import build_model


class KinematicsFacade:
    def __init__(self, robot_description: str, base_link: str, tip_link: str,
                 backend: str, mask: List[int], logger):
        self._lock = threading.Lock()
        self._model = build_model(
            robot_description,
            base_link=base_link,
            tip_link=tip_link,
            backend=backend,
        )
        self._fk = self._model.fk
        self._base = base_link
        self._tip = tip_link
        self._mask = list(mask)
        self._logger = logger

        # Upgrade planner class in-place (preserves original behaviour)
        from robokpy.industrial_trajectory import IndustrialTrajectoryPlanner
        self._model.traj.__class__ = IndustrialTrajectoryPlanner
        self._traj_planner = self._model.traj

    # ------------------------------------------------------------------
    # Properties (read-only, safe to access without lock)
    # ------------------------------------------------------------------
    @property
    def model(self):
        return self._model

    @property
    def traj_planner(self):
        return self._traj_planner

    @property
    def num_joints(self) -> int:
        return self._model.model.get_num_act_joints_in_chain(self._base, self._tip)

    @property
    def joint_names(self) -> List[str]:
        return self._model.model.get_joint_names_in_chain(self._base, self._tip)

    @property
    def base_link(self) -> str:
        return self._base

    @property
    def tip_link(self) -> str:
        return self._tip

    # ------------------------------------------------------------------
    # Mutators (lock-protected)
    # ------------------------------------------------------------------
    def set_tip_link(self, tip_link: str):
        with self._lock:
            self._tip = tip_link
            self._model.ik.tip_link = tip_link

    # ------------------------------------------------------------------
    # IK / FK  (lock-protected, returns copies)
    # ------------------------------------------------------------------
    def solve_ik(self, pose: np.ndarray, q_seed: np.ndarray) -> Optional[np.ndarray]:
        """Thread-safe IK. Returns a copy of the solution or None."""
        with self._lock:
            q = self._model.ik.solve(np.asarray(pose, dtype=float),
                                      q0=np.asarray(q_seed, dtype=float),
                                      mask=self._mask)
            if self._model.ik.success:
                return np.array(q)
            return None

    def compute_fk(self, q: np.ndarray) -> np.ndarray:
        """Thread-safe FK. Returns pose quaternion [x,y,z,qx,qy,qz,qw]."""
        with self._lock:
            self._fk.compute_chain(np.asarray(q, dtype=float), self._base, self._tip)
            return np.array(self._fk.get_pose_quart())

    def get_fk_xyz(self, q: np.ndarray) -> np.ndarray:
        """Thread-safe FK returning only xyz position."""
        with self._lock:
            self._fk.compute_chain(np.asarray(q, dtype=float), self._base, self._tip)
            return np.array(self._fk.get_xyz())

    def get_active_joints(self) -> List[dict]:
        with self._lock:
            return list(self._model.model.get_active_joints_in_chain(self._base, self._tip))

    # ------------------------------------------------------------------
    # Joint utilities  (pure numpy, no lock needed)
    # ------------------------------------------------------------------
    @staticmethod
    def normalize_joints(q: np.ndarray, active_joints: List[dict]) -> np.ndarray:
        q_norm = np.array(q, dtype=float)
        for i, joint in enumerate(active_joints):
            if joint['type'] in ('revolute', 'continuous'):
                q_norm[i] = (q_norm[i] + np.pi) % (2 * np.pi) - np.pi
        return q_norm

    @staticmethod
    def shortest_equivalent(q_target: np.ndarray, q_seed: np.ndarray,
                            active_joints: List[dict],
                            pos_limits: Optional[np.ndarray] = None) -> np.ndarray:
        q_adj = np.array(q_target, dtype=float)
        for i, joint in enumerate(active_joints):
            if joint['type'] not in ('revolute', 'continuous'):
                continue
            delta = q_target[i] - q_seed[i]
            wrapped = (delta + np.pi) % (2 * np.pi) - np.pi
            candidate = q_seed[i] + wrapped
            if joint['type'] == 'continuous' or pos_limits is None:
                q_adj[i] = candidate
                continue
            lo, hi = pos_limits[i]
            if lo <= candidate <= hi:
                q_adj[i] = candidate
        return q_adj
