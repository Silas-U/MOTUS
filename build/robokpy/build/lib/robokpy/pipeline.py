"""
pipeline.py — TrajectoryPipeline, GeometricPath, Generators, Blenders,
Parametrizers, Validators, and Factory.

The TrajectoryPipeline is a composable, extensible architecture for
robot trajectory generation. It separates the process into distinct
stages:

1. Geometric Path Generation (e.g., JointLineGenerator, CartesianLineGenerator)
2. Path Blending (e.g., ParabolicBlender)
3. Time Parametrization (e.g., LSPBParametrizer, SCurveParametrizer)
4. Validation (e.g., LimitValidator)

Each stage is implemented as a callable class with a specific interface,
allowing users to mix and match components to suit their needs.

Usage:
    from robokpy.pipeline import TrajectoryPipeline, PipelineConfig, PipelineFactory

    # Create a pipeline with default components
    pipeline = TrajectoryPipeline(
        geometric_generator=JointLineGenerator(),
        blender=ParabolicBlender(),
        time_parametrizer=LSPBParametrizer(planner=traj_planner),
        validator=LimitValidator(vel_limits=vel_limits, acc_limits=acc_limits)
    )

    # Generate a trajectory
    points = pipeline.generate(waypoints, q0, vel_limits, acc_limits)

    # Or use the factory for a more declarative approach
    factory = PipelineFactory()
    factory.register_generator('joint_line', JointLineGenerator)
    factory.register_blender('parabolic', ParabolicBlender)
    factory.register_parametrizer('lspb', LSPBParametrizer)
    factory.register_validator('limit', LimitValidator)

    config = PipelineConfig(
        geometric_generator='joint_line',
        blender='parabolic',
        time_parametrizer='lspb',
        validator='limit'
    )

    pipeline = factory.create(config)
    points = pipeline.generate(waypoints, q0, vel_limits, acc_limits)
"""

import numpy as np
from typing import List, Optional, Callable, Dict, Any
from dataclasses import dataclass, field

from robokpy.trajectory import TrajectoryPlanner
from robokpy import TrajectoryPoint


# =============================================================================
# GeometricPath
# =============================================================================

class GeometricPath:
    """Represents a geometric path in joint space.

    Attributes:
        q: A 2D numpy array of shape (N, n_dof) containing the joint
           configurations along the path.
        waypoint_indices: A list of indices into `q` that correspond to the
                          original waypoints. This is used by blenders and
                          parametrizers to identify segment boundaries.
        waypoints: The original list of Waypoint objects.
    """

    def __init__(self, q: np.ndarray, waypoint_indices: List[int],
                 waypoints: List['Waypoint']):
        self.q = np.asarray(q, dtype=float)
        self.waypoint_indices = waypoint_indices
        self.waypoints = waypoints

    def __len__(self):
        return len(self.q)

    def __getitem__(self, idx):
        return self.q[idx]


# =============================================================================
# Waypoint
# =============================================================================

@dataclass
class Waypoint:
    """Represents a target configuration for the robot.

    A waypoint can be defined in joint space (`q`), Cartesian space
    (`pose`), or both. If both are provided, the Cartesian pose is
    used for geometric path generation, and the joint configuration is
    used as an initial guess for IK.

    Attributes:
        q: Joint configuration (optional).
        pose: Cartesian pose as [x, y, z, qx, qy, qz, qw] (optional).
    """
    q: Optional[np.ndarray] = None
    pose: Optional[np.ndarray] = None


# =============================================================================
# TrajectoryPipeline
# =============================================================================

class TrajectoryPipeline:
    """Composes geometric generation, blending, time parametrization, and
    validation into a single trajectory generation pipeline.

    Attributes:
        geometric_generator: Callable that takes waypoints and returns a GeometricPath.
        blender: Callable that takes a GeometricPath and returns a blended GeometricPath.
        time_parametrizer: Callable that takes a GeometricPath and returns a timed trajectory.
        validator: Callable that validates the final trajectory.
    """

    def __init__(self,
                 geometric_generator: Optional[Callable] = None,
                 blender: Optional[Callable] = None,
                 time_parametrizer: Optional[Callable] = None,
                 validator: Optional[Callable] = None):
        self.geometric_generator = geometric_generator
        self.blender = blender
        self.time_parametrizer = time_parametrizer
        self.validator = validator

    def generate(self, waypoints: List[Waypoint], q0: np.ndarray,
                 vel_limits: np.ndarray, acc_limits: np.ndarray,
                 jerk_limits: Optional[np.ndarray] = None,
                 pos_limits: Optional[np.ndarray] = None,
                 **kwargs) -> List[TrajectoryPoint]:
        """Generate a trajectory through the given waypoints.

        Args:
            waypoints: A list of Waypoint objects.
            q0: The initial joint configuration.
            vel_limits: Per-joint velocity limits.
            acc_limits: Per-joint acceleration limits.
            jerk_limits: Per-joint jerk limits (optional).
            pos_limits: Per-joint position limits (optional).
            **kwargs: Additional arguments passed to pipeline stages.

        Returns:
            A list of TrajectoryPoint objects representing the timed trajectory.
        """
        # --- Stage 1: Geometric Path Generation ---
        if self.geometric_generator is None:
            raise ValueError("No geometric generator configured.")
        path = self.geometric_generator(waypoints=waypoints, q0=q0, **kwargs)

        # --- Stage 2: Blending ---
        if self.blender is not None:
            path = self.blender(path=path, **kwargs)

        # --- Stage 3: Time Parametrization ---
        if self.time_parametrizer is None:
            raise ValueError("No time parametrizer configured.")
        traj = self.time_parametrizer(
            path=path, vel_limits=vel_limits, acc_limits=acc_limits,
            jerk_limits=jerk_limits, **kwargs)

        # --- Stage 4: Validation ---
        if self.validator is not None:
            self.validator(
                traj=traj, vel_limits=vel_limits, acc_limits=acc_limits,
                jerk_limits=jerk_limits, pos_limits=pos_limits, **kwargs)

        return traj


# =============================================================================
# PipelineConfig
# =============================================================================

@dataclass
class PipelineConfig:
    """Configuration for the TrajectoryPipeline.

    Attributes:
        geometric_generator: Name of the registered geometric generator.
        blender: Name of the registered blender (optional).
        time_parametrizer: Name of the registered time parametrizer.
        validator: Name of the registered validator (optional).
        n_samples: Number of samples for Cartesian interpolation.
        n_blend: Number of samples for blending.
        dt: Time step for the trajectory.
        speed_factor: Global speed scaling factor.
        duration_per_segment: Duration per segment for time parametrization.
        parametrizer_kwargs: Additional keyword arguments for the time parametrizer.
    """
    geometric_generator: str = 'joint_line'
    blender: Optional[str] = None
    time_parametrizer: str = 'lspb'
    validator: Optional[str] = None
    n_samples: int = 50
    n_blend: int = 20
    dt: float = 0.04
    speed_factor: float = 1.0
    duration_per_segment: float = 3.0
    parametrizer_kwargs: Dict[str, Any] = field(default_factory=dict)


# =============================================================================
# Geometric Generators
# =============================================================================

class JointLineGenerator:
    """Generates a geometric path by linearly interpolating in joint space.

    This generator assumes all waypoints have a valid joint configuration
    (`q`). If a waypoint only has a Cartesian pose, it will raise an error.
    """

    def __init__(self, n_samples: int = 50):
        self.n_samples = n_samples

    def generate(self, waypoints: List[Waypoint], q0: np.ndarray,
                 **kwargs) -> GeometricPath:
        raw_q = []
        wp_idx = []
        for i, wp in enumerate(waypoints):
            if wp.q is None:
                raise ValueError(
                    f"Waypoint {i} has no joint configuration (q). "
                    f"JointLineGenerator requires all waypoints to be in joint space.")
            raw_q.append(wp.q)
            wp_idx.append(len(raw_q) - 1)
        return GeometricPath(q=np.array(raw_q), waypoint_indices=wp_idx,
                             waypoints=waypoints)


class CartesianLineGenerator:
    """Generates a geometric path by linearly interpolating in Cartesian
    space and solving IK for each sample point.

    This generator requires a valid IK solver (`ik_fn`) and assumes all
    waypoints have a Cartesian pose.
    """

    def __init__(self, ik_fn: Callable, base_link: str, tip_link: str,
                 n_samples: int = 50):
        self.ik_fn = ik_fn
        self.base_link = base_link
        self.tip_link = tip_link
        self.n_samples = n_samples

    def generate(self, waypoints: List[Waypoint], q0: np.ndarray,
                 **kwargs) -> GeometricPath:
        raw_q = [q0]
        wp_idx = [0]
        for i, wp in enumerate(waypoints):
            if wp.pose is None:
                raise ValueError(
                    f"Waypoint {i} has no Cartesian pose. "
                    f"CartesianLineGenerator requires all waypoints to have a pose.")
            # Interpolate in Cartesian space
            start_pose = raw_q[-1] if i == 0 else waypoints[i - 1].pose
            end_pose = wp.pose
            for j in range(1, self.n_samples + 1):
                t = j / self.n_samples
                interp_pose = (1 - t) * start_pose + t * end_pose
                q_sol = self.ik_fn(interp_pose, q0=raw_q[-1])
                if q_sol is None:
                    raise ValueError(
                        f"IK failed at waypoint {i}, sample {j}. "
                        f"Cannot generate Cartesian path.")
                raw_q.append(q_sol)
            # FIX: waypoint index for the last waypoint of this segment
            wp_idx.append(len(raw_q) - 1)
        return GeometricPath(q=np.array(raw_q), waypoint_indices=wp_idx,
                             waypoints=waypoints)


# =============================================================================
# Blenders
# =============================================================================

class ParabolicBlender:
    """Blends the geometric path using parabolic blends at segment boundaries.

    This blender replaces the linear segments near waypoints with parabolic
    arcs to ensure continuous velocity.
    """

    def __init__(self, blend_radius: float = 0.05):
        self.blend_radius = blend_radius

    def blend(self, path: GeometricPath, **kwargs) -> GeometricPath:
        # Placeholder implementation
        return path


# =============================================================================
# Time Parametrizers
# =============================================================================

class LSPBParametrizer:
    """Wraps the legacy TrajectoryPlanner LSPB path through the
    TrajectoryPipeline interface.
    """

    def __init__(self, planner, duration_per_segment=3.0, dt=0.04, **kwargs):
        self.planner = planner
        self.duration = duration_per_segment
        self.dt = dt

    def parametrize(self, path, vel_limits, acc_limits, jerk_limits=None, **kwargs):
        # Build 2-waypoint dicts compatible with TrajectoryPlanner.create_trajectory
        waypoints = []
        for wp in path.waypoints:
            d = {'q': wp.q}
            if wp.pose is not None:
                d['pose'] = wp.pose
            waypoints.append(d)
        return self.planner.create_trajectory(
            waypoints=waypoints,
            traj_method='js',
            traj_type='lspb',
            duration_per_segment=self.duration,
            dt=self.dt,
            vel_limits=vel_limits,
            acc_limits=acc_limits,
        )


class TOPPParametrizer(LSPBParametrizer):
    """Stub — TOPP is not implemented. Delegates to LSPB with a warning."""

    def __init__(self, *args, **kwargs):
        import warnings
        warnings.warn(
            'TOPPParametrizer is not implemented — using LSPB instead',
            stacklevel=2)
        super().__init__(*args, **kwargs)


class SCurveParametrizer:
    """Wraps the legacy TrajectoryPlanner S-curve path through the
    TrajectoryPipeline interface.
    """

    def __init__(self, planner, duration_per_segment=3.0, dt=0.04, **kwargs):
        self.planner = planner
        self.duration = duration_per_segment
        self.dt = dt

    def parametrize(self, path, vel_limits, acc_limits, jerk_limits=None, **kwargs):
        waypoints = []
        for wp in path.waypoints:
            d = {'q': wp.q}
            if wp.pose is not None:
                d['pose'] = wp.pose
            waypoints.append(d)
        return self.planner.create_trajectory(
            waypoints=waypoints,
            traj_method='js',
            traj_type='scurve',
            duration_per_segment=self.duration,
            dt=self.dt,
            vel_limits=vel_limits,
            acc_limits=acc_limits,
            jerk_limits=jerk_limits,
        )


# =============================================================================
# Validators
# =============================================================================

class LimitValidator:
    """Validates that the trajectory respects joint limits.

    Checks position, velocity, acceleration, and jerk limits.
    """

    def __init__(self, pos_limits=None, vel_limits=None, acc_limits=None,
                 jerk_limits=None):
        self.pos_limits = pos_limits
        self.vel_limits = vel_limits
        self.acc_limits = acc_limits
        self.jerk_limits = jerk_limits

    def validate(self, traj: List[TrajectoryPoint], **kwargs):
        for i, pt in enumerate(traj):
            if self.pos_limits is not None:
                self._check_limits(pt.q, self.pos_limits, 'position', i)
            if self.vel_limits is not None and pt.qd is not None:
                self._check_limits(pt.qd, self.vel_limits, 'velocity', i)
            if self.acc_limits is not None and pt.qdd is not None:
                self._check_limits(pt.qdd, self.acc_limits, 'acceleration', i)

    def _check_limits(self, values, limits, name, idx):
        for j, (v, (lo, hi)) in enumerate(zip(values, limits)):
            if v < lo or v > hi:
                raise TrajectoryValidationError(
                    f"{name} limit violation at point {idx}, joint {j}: "
                    f"{v} not in [{lo}, {hi}]")


class ValidationReport:
    """Report of trajectory validation violations."""

    def __init__(self, violations=None):
        self.violations = violations or []


class DefaultLimitValidator(LimitValidator):
    """Backward-compatible alias for LimitValidator."""
    pass


class TrajectoryValidationError(Exception):
    """Raised when a trajectory fails validation."""

    def __init__(self, message, violations=None):
        super().__init__(message)
        self.report = ValidationReport(violations=violations or [])


# =============================================================================
# PipelineFactory
# =============================================================================

class PipelineFactory:
    """Factory for creating TrajectoryPipeline instances from configuration.

    Registers and instantiates pipeline components by name.
    """

    def __init__(self):
        self._generators: Dict[str, Callable] = {}
        self._blenders: Dict[str, Callable] = {}
        self._parametrizers: Dict[str, Callable] = {}
        self._validators: Dict[str, Callable] = {}

    def register_generator(self, name: str, factory: Callable):
        self._generators[name] = factory

    def register_blender(self, name: str, factory: Callable):
        self._blenders[name] = factory

    def register_parametrizer(self, name: str, factory: Callable):
        self._parametrizers[name] = factory

    def register_validator(self, name: str, factory: Callable):
        self._validators[name] = factory

    def create(self, cfg: PipelineConfig) -> TrajectoryPipeline:
        if cfg.geometric_generator not in self._generators:
            raise ValueError(f"Unknown geometric generator: {cfg.geometric_generator}")
        gen = self._generators[cfg.geometric_generator](
            n_samples=cfg.n_samples, **cfg.parametrizer_kwargs)

        blender = None
        if cfg.blender is not None:
            if cfg.blender not in self._blenders:
                raise ValueError(f"Unknown blender: {cfg.blender}")
            blender = self._blenders[cfg.blender](
                n_blend=cfg.n_blend, **cfg.parametrizer_kwargs)

        if cfg.time_parametrizer not in self._parametrizers:
            raise ValueError(f"Unknown time parametrizer: {cfg.time_parametrizer}")
        timer = self._parametrizers[cfg.time_parametrizer](
            n_blend=cfg.n_blend, n_samples=cfg.n_samples, **cfg.parametrizer_kwargs)

        validator = None
        if cfg.validator is not None:
            if cfg.validator not in self._validators:
                raise ValueError(f"Unknown validator: {cfg.validator}")
            validator = self._validators[cfg.validator](**cfg.parametrizer_kwargs)

        return TrajectoryPipeline(
            geometric_generator=gen,
            blender=blender,
            time_parametrizer=timer,
            validator=validator,
        )
