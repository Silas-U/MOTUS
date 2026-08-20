"""
execution_monitor.py  —  Ground-truth verifier for arm motion.

Watches /current_joint_state and maintains a sliding window.
Provides is_at_target() and is_diverged() so the orchestrator can
declare completion from encoders, not just DDS action results.
"""

import collections
import threading
from typing import Optional

import numpy as np


class ExecutionMonitor:
    def __init__(
        self,
        target_tolerance: float = 0.05,
        stable_window_sec: float = 0.5,
        divergence_tolerance: float = 0.15,
        history_window_sec: float = 2.0,
        logger=None,
    ):
        self._target_q: Optional[np.ndarray] = None
        self._tolerance = target_tolerance
        self._stable_window_sec = stable_window_sec
        self._divergence_tol = divergence_tolerance
        self._history_window_sec = history_window_sec
        self._logger = logger

        # (timestamp_sec, q_array)
        self._history: collections.deque = collections.deque()
        self._lock = threading.Lock()

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------
    def reset(self, target_q: np.ndarray):
        """Call when a new trajectory starts."""
        with self._lock:
            self._target_q = np.asarray(target_q, dtype=float).flatten()
            self._history.clear()

    def update(self, q: np.ndarray, stamp_sec: float):
        """Feed a new joint state sample."""
        with self._lock:
            self._history.append((stamp_sec, np.asarray(q, dtype=float).flatten()))
            self._prune(stamp_sec)

    def is_at_target(self) -> bool:
        """True if joints have been within tolerance for > stable_window_sec."""
        with self._lock:
            if self._target_q is None or len(self._history) < 2:
                return False
            now = self._history[-1][0]
            cutoff = now - self._stable_window_sec
            # Check every sample in the window
            for t, q in self._history:
                if t < cutoff:
                    continue
                if float(np.max(np.abs(q - self._target_q))) > self._tolerance:
                    return False
            return True

    def is_diverged(self, predicted_path: list[np.ndarray]) -> bool:
        """True if current position is far from the nearest predicted waypoint."""
        with self._lock:
            if not self._history or not predicted_path:
                return False
            q_current = self._history[-1][1]
            min_err = min(
                float(np.max(np.abs(q_current - np.asarray(wp, dtype=float).flatten())))
                for wp in predicted_path
            )
            return min_err > self._divergence_tol

    # ------------------------------------------------------------------
    # Internal
    # ------------------------------------------------------------------
    def _prune(self, now_sec: float):
        cutoff = now_sec - self._history_window_sec
        while self._history and self._history[0][0] < cutoff:
            self._history.popleft()
