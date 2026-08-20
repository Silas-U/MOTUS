"""
mp_types.py  —  Shared dataclasses for the refactored stack.
ROS-free. TrajectoryConfig still has a from_node_params helper.
"""

from dataclasses import dataclass, field
from typing import List, Optional, Tuple
import numpy as np


# ------------------------------------------------------------------
# WAYPOINTS
# ------------------------------------------------------------------

@dataclass(frozen=True)
class JointWaypoint:
    q: np.ndarray
    id: Optional[str] = None

    def __post_init__(self):
        object.__setattr__(
            self, 'q',
            np.atleast_1d(np.asarray(self.q, dtype=float)).flatten()
        )


@dataclass(frozen=True)
class CartesianWaypoint:
    pose: np.ndarray
    id: Optional[str] = None

    def __post_init__(self):
        object.__setattr__(
            self, 'pose',
            np.asarray(self.pose, dtype=float).flatten()
        )


Waypoint = JointWaypoint | CartesianWaypoint


# ------------------------------------------------------------------
# SEGMENTS
# ------------------------------------------------------------------

@dataclass
class MotionSegment:
    start_id: str
    end_id: str
    mode: str = 'js'
    traj_type: str = 'scurve'
    blend_radius: float = 0.0
    speed_factor: float = 1.0
    duration_per_segment: float = 3.0
    n_samples: int = 10
    n_blend: int = 10
    dt: float = 0.04
    cached: bool = False
    trajectory: Optional[List] = None

    def invalidate(self):
        self.cached = False
        self.trajectory = None


# ------------------------------------------------------------------
# CONFIG
# ------------------------------------------------------------------

@dataclass
class TrajectoryConfig:
    traj_method: str = 'js'
    traj_type: str = 'scurve'
    blend_radius: float = 0.0
    n_blend: int = 10
    duration_per_segment: float = 3.0
    dt: float = 0.04
    speed_factor: float = 1.0
    n_samples: int = 10
    vel_limits: Optional[np.ndarray] = None
    acc_limits: Optional[np.ndarray] = None
    jerk_limits: Optional[np.ndarray] = None
    pos_limits: Optional[np.ndarray] = None
    cartesian_vel_limit: float = 0.25

    @classmethod
    def from_node_params(cls, node) -> "TrajectoryConfig":
        return cls(
            traj_method=node.get_parameter('default_traj_method').value,
            traj_type=node.get_parameter('default_traj_type').value,
            blend_radius=node.get_parameter('default_blend_radius').value,
            n_blend=node.get_parameter('default_n_blend').value,
            duration_per_segment=node.get_parameter('default_duration_per_segment').value,
            dt=node.get_parameter('default_dt').value,
            speed_factor=node.get_parameter('default_speed_factor').value,
            n_samples=node.get_parameter('default_n_samples').value,
            vel_limits=np.array(node.get_parameter('vel_limits').value),
            acc_limits=np.array(node.get_parameter('acc_limits').value),
            jerk_limits=np.array(node.get_parameter('jerk_limits').value),
            pos_limits=np.column_stack([
                np.array(node.get_parameter('pos_limits_lo').value),
                np.array(node.get_parameter('pos_limits_hi').value),
            ]),
            cartesian_vel_limit=node.get_parameter('cartesian_vel_limit').value,
        )


# ------------------------------------------------------------------
# RESULT TYPES  (ROS-free)
# ------------------------------------------------------------------

@dataclass
class LegResult:
    points: List
    q_target: np.ndarray
    error_code: int = 0
    failed_step_id: Optional[str] = None


@dataclass
class TrajectoryResult:
    points: List
    leg_time_ranges: List[Tuple[str, float, float]]
    predicted_q: np.ndarray
    fk_path: List[np.ndarray]
    total_duration: float
