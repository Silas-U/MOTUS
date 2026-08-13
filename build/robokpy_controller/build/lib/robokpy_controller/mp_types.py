"""
mp_types.py  —  Shared dataclasses and type definitions for the refactored
Motion Planner. Eliminates Optional[q] leaks by using tagged waypoint types.
"""

from dataclasses import dataclass, field
from typing import List, Optional, Tuple, Dict, Any
import numpy as np
from builtin_interfaces.msg import Duration
from trajectory_msgs.msg import JointTrajectory


# ------------------------------------------------------------------
# WAYPOINTS  (tagged union pattern — q is never Optional)
# ------------------------------------------------------------------

@dataclass(frozen=True)
class JointWaypoint:
    """A waypoint defined in joint space."""
    q: np.ndarray
    id: Optional[str] = None

    def __post_init__(self):
        object.__setattr__(
            self, 'q',
            np.atleast_1d(np.asarray(self.q, dtype=float)).flatten()
        )


@dataclass(frozen=True)
class CartesianWaypoint:
    """A waypoint defined in Cartesian space. Must be resolved to joints
    before entering a joint-space parametrizer."""
    pose: np.ndarray          # [x, y, z, qx, qy, qz, qw]
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
    mode: str = 'js'                     # 'js' | 'ts'
    traj_type: str = 'lspb'
    blend_radius: float = 0.0
    speed_factor: float = 1.0
    duration_per_segment: float = 3.0
    n_samples: int = 50
    n_blend: int = 20
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
    """Unified configuration — used by both legacy and pipeline paths."""
    traj_method: str = 'js'
    traj_type: str = 'lspb'
    blend_radius: float = 0.0
    n_blend: int = 20
    duration_per_segment: float = 3.0
    dt: float = 0.04
    speed_factor: float = 1.0
    n_samples: int = 50
    vel_limits: Optional[np.ndarray] = None
    acc_limits: Optional[np.ndarray] = None
    jerk_limits: Optional[np.ndarray] = None
    pos_limits: Optional[np.ndarray] = None   # (n_joints, 2)
    cartesian_vel_limit: float = 0.25   # m/s — see robokpy_base.yaml comment

    @classmethod
    def from_node_params(cls, node) -> "TrajectoryConfig":
        """Build from ROS parameter declarations."""
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
# RESULT TYPES
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
    jtc_msg: JointTrajectory
    fk_path: List[np.ndarray]
    total_duration: float


@dataclass
class JtcResult:
    success: bool
    error_code: int
    timed_out: bool = False
    actual_positions: Optional[List[float]] = None


@dataclass
class CachedPlan:
    jtc_msg: JointTrajectory
    fk_path: List[np.ndarray]
    leg_time_ranges: List[Tuple[str, float, float]]
    predicted_q: np.ndarray
    seed_q: np.ndarray
    created_at: float = field(default_factory=lambda: float(__import__('time').time()))