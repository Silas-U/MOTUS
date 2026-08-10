"""
steps — the DAG's typed step vocabulary.

Split out from orchestrator.py so both orchestrator.py and
recipe_compiler.py can import these without a circular import
(recipe_compiler builds Step objects; orchestrator dispatches them —
neither should own the other's module).
"""

import enum
from dataclasses import dataclass, field
from typing import Union

Dependency = Union[str, tuple]  # step_id, or ('progress', step_id, threshold)


class RecoveryPolicy(enum.Enum):
    ABORT = 'abort'
    RETRY = 'retry'
    DEGRADE = 'degrade'
    HOLD_FOR_OPERATOR = 'hold_for_operator'


@dataclass
class Step:
    step_id: str
    depends_on: list[Dependency] = field(default_factory=list)
    recovery: RecoveryPolicy = RecoveryPolicy.ABORT
    retry_count: int = 0
    max_retries: int = 2


@dataclass
class MoveStep(Step):
    """The only motion step type authorable in a recipe. Always targets a
    Pose — traj_method picks the interpolation space (movej-style 'js'
    vs movel-style 'ts'), never a raw joint-angle target."""
    target_pose: object = None   # geometry_msgs/Pose
    traj_method: str = 'ts'      # 'js' (movej-style) | 'ts' (movel-style)
    traj_type: str = 'blend'
    blend_radius: float = 0.0
    speed_scale: float = 1.0
    from_spawn_step: str = ''
    # If True AND from_spawn_step is set, the resolved grasp target's
    # ORIENTATION is pulled from the referenced SpawnStep's own
    # qx/qy/qz/qw (composed with gripper-down) instead of
    # target_pose.orientation. Default False preserves existing semantics.
    use_spawn_orientation: bool = False
    engagement_fraction: float = 0.5
    approach_axis: str = 'z'


@dataclass
class ToolStep(Step):
    tool_id: str = ''
    command: str = ''
    params: list = field(default_factory=list)
    from_vision_step: str = ''


@dataclass
class IOStep(Step):
    io_id: str = ''
    command: str = ''
    params: list = field(default_factory=list)


@dataclass
class WaitStep(Step):
    duration_sec: float = 0.0


@dataclass
class VisionStep(Step):
    vision_id: str = ''
    operation: str = ''
    params: list = field(default_factory=list)


@dataclass
class SpawnStep(Step):
    """Spawns or despawns a catalog object instance at recipe time.

    operation='spawn': type_id required; x,y,z,qx,qy,qz,qw give spawn pose.
    Optional `color` sets visual material. Assigned child_model comes back
    in stored result.

    operation='despawn': needs exactly one of child_model or from_spawn_step.
    """
    operation: str = 'spawn'
    type_id: str = ''
    x: float = 0.0
    y: float = 0.0
    z: float = 0.0
    qx: float = 0.0
    qy: float = 0.0
    qz: float = 0.0
    qw: float = 1.0
    color: str = ''            # spawn only — visual material color
    child_model: str = ''      # despawn only
    from_spawn_step: str = ''  # despawn only
