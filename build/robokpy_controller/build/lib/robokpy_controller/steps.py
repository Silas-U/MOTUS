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