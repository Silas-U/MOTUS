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
    vs movel-style 'ts'), never a raw joint-angle target. Mixing
    arbitrary joint targets with pose targets in a script has no
    continuity guarantee between steps; raw joint control is a
    deliberately separate, non-scriptable capability (joint_jog_server)."""
    target_pose: object = None   # geometry_msgs/Pose
    traj_method: str = 'ts'      # 'js' (movej-style) | 'ts' (movel-style)
    traj_type: str = 'blend'
    blend_radius: float = 0.0
    speed_scale: float = 1.0


@dataclass
class ToolStep(Step):
    tool_id: str = ''
    command: str = ''
    params: list = field(default_factory=list)
    # If set, overrides `params` at dispatch time with the position
    # (x, y, z) from the named VisionStep's detected_pose result —
    # this is the vision->grasp threading link (see GraspAttachBackend,
    # object_pose_resolver). Must reference a VisionStep step_id that
    # is ALSO listed in this step's depends_on as a full completion
    # dependency (not a progress tuple) — recipe_compiler validates
    # this at compile time so the result can never be missing at
    # dispatch time.
    from_vision_step: str = ''


@dataclass
class IOStep(Step):
    """Discrete digital I/O / vacuum-style backends — same ExecuteToolOp
    interface as ToolStep, kept as a distinct type for script clarity
    since I/O is a categorically different action than a tool/gripper op."""
    io_id: str = ''
    command: str = ''
    params: list = field(default_factory=list)


@dataclass
class WaitStep(Step):
    duration_sec: float = 0.0
    # no external action call — resolved by a one-shot timer


@dataclass
class VisionStep(Step):
    vision_id: str = ''
    operation: str = ''
    params: list = field(default_factory=list)


@dataclass
class SpawnStep(Step):
    """Spawns or despawns a catalog object instance at recipe time
    (see object_spawner.py, objects.yaml). Two modes via `operation`:

      operation='spawn'   — type_id required; x,y,z(,qx,qy,qz,qw) give
                             the spawn pose. Assigns a free instance
                             from the bounded catalog pool for that
                             type; the assigned child_model comes back
                             in this step's stored result.

      operation='despawn' — needs exactly one of child_model (hand-typed
                             instance name) or from_spawn_step (pull the
                             child_model from an earlier SpawnStep's
                             result instead — analogous to
                             ToolStep.from_vision_step). If
                             from_spawn_step is set it must also be a
                             full completion dependency of this step,
                             same rule and same reason as
                             from_vision_step.
    """
    operation: str = 'spawn'   # 'spawn' | 'despawn'
    type_id: str = ''
    x: float = 0.0
    y: float = 0.0
    z: float = 0.0
    qx: float = 0.0
    qy: float = 0.0
    qz: float = 0.0
    qw: float = 1.0
    child_model: str = ''      # despawn only — hand-typed target instance
    from_spawn_step: str = ''  # despawn only — pull child_model from this SpawnStep's result