"""
mp_cache.py  —  PlanCache

Thread-safe plan cache with prefetch support. Cache keys are collision-proof
because they include a hash of the target poses, not just step IDs.
"""

import threading
import time
import numpy as np
from typing import Optional, Dict, Any
from dataclasses import dataclass, field

from .mp_types import CachedPlan


@dataclass
class _PendingEntry:
    future: Any
    created_at: float = field(default_factory=time.time)


class PlanCache:
    def __init__(self, tolerance: float = 0.05, ttl_sec: float = 30.0):
        self._tolerance = tolerance
        self._ttl_sec = ttl_sec
        self._cache: Dict[str, CachedPlan] = {}
        self._pending: Dict[str, _PendingEntry] = {}
        self._lock = threading.Lock()

    # ------------------------------------------------------------------
    # Key generation  (collision-proof)
    # ------------------------------------------------------------------
    @staticmethod
    def make_key(goal) -> str:
        """Hash key includes step IDs AND pose data so different poses with
        the same IDs do not collide."""
        pose_hashes = []
        for p in goal.leg_target_poses:
            # Round to micrometre / micro-radian to keep key stable across float noise
            pose_hashes.append(hash((
                round(p.position.x, 6),
                round(p.position.y, 6),
                round(p.position.z, 6),
                round(p.orientation.x, 6),
                round(p.orientation.y, 6),
                round(p.orientation.z, 6),
                round(p.orientation.w, 6),
            )))
        return str(hash((
            tuple(goal.leg_step_ids),
            tuple(goal.leg_traj_methods),
            tuple(goal.leg_traj_types),
            tuple(round(r, 6) for r in goal.leg_blend_radii),
            goal.speed_scale,
            tuple(pose_hashes),
        )))

    # ------------------------------------------------------------------
    # Cache API
    # ------------------------------------------------------------------
    def get(self, key: str, q_seed: np.ndarray) -> Optional[CachedPlan]:
        with self._lock:
            plan = self._cache.get(key)
            if plan is None:
                return None
            age = time.time() - plan.created_at
            if age > self._ttl_sec:
                self._cache.pop(key, None)
                return None
            drift = float(np.max(np.abs(q_seed - plan.seed_q)))
            if drift > self._tolerance:
                return None
            return plan

    def put(self, key: str, plan: CachedPlan):
        with self._lock:
            self._cache[key] = plan

    def pop(self, key: str) -> Optional[CachedPlan]:
        with self._lock:
            return self._cache.pop(key, None)

    # ------------------------------------------------------------------
    # Prefetch API
    # ------------------------------------------------------------------
    def start_prefetch(self, key: str, future):
        with self._lock:
            self._pending[key] = _PendingEntry(future=future)

    def get_pending(self, key: str) -> Optional[Any]:
        with self._lock:
            entry = self._pending.get(key)
            if entry is None:
                return None
            if time.time() - entry.created_at > self._ttl_sec:
                self._pending.pop(key, None)
                return None
            return entry.future

    def finish_prefetch(self, key: str):
        with self._lock:
            self._pending.pop(key, None)
