"""
RecipeCompiler — the authoring layer between a human-written script and
the orchestrator's DAG.

A recipe is a YAML file: a flat, ordered list of typed steps with
explicit dependencies. This is the thing an operator or integrator
actually edits — MoveStep/ToolStep/etc are the orchestrator's runtime
representation, not the authoring format.

Validates before handing anything to the orchestrator:
  - every depends_on reference points to a step_id that exists
  - no dependency cycles (a bad recipe should fail to load, not
    deadlock mid-cell)
  - recovery policy names are one of the real RecoveryPolicy values
  - a ToolStep's from_vision_step (if set) references a real VisionStep
    that's also a full completion dependency of that same step

Also computes a content hash of the raw recipe text — this is the
recipe-versioning half of the persistence/traceability layer: every
execution log entry can cite exactly which recipe version ran.
"""

import hashlib
import yaml
from typing import Any

from geometry_msgs.msg import Pose

from .steps import (
    Step, MoveStep, ToolStep, IOStep, WaitStep, VisionStep, SpawnStep,
    RecoveryPolicy,
)


class RecipeValidationError(Exception):
    pass


def _pose_from_dict(d: dict) -> Pose:
    pose = Pose()
    pose.position.x = float(d.get('x', 0.0))
    pose.position.y = float(d.get('y', 0.0))
    pose.position.z = float(d.get('z', 0.0))
    pose.orientation.x = float(d.get('qx', 0.0))
    pose.orientation.y = float(d.get('qy', 0.0))
    pose.orientation.z = float(d.get('qz', 0.0))
    pose.orientation.w = float(d.get('qw', 1.0))
    return pose


def _parse_recovery(value: str) -> RecoveryPolicy:
    try:
        return RecoveryPolicy(value)
    except ValueError:
        valid = [p.value for p in RecoveryPolicy]
        raise RecipeValidationError(
            f'Unknown recovery policy "{value}". Valid: {valid}')


def _parse_depends_on(raw_deps: list) -> list:
    """
    Each entry is either:
      - a plain string  -> step-completion dependency
      - {progress: <step_id>, threshold: <float>} -> overlap dependency
    """
    parsed = []
    for dep in raw_deps or []:
        if isinstance(dep, str):
            parsed.append(dep)
        elif isinstance(dep, dict) and 'progress' in dep:
            parsed.append(('progress', dep['progress'], float(dep.get('threshold', 1.0))))
        else:
            raise RecipeValidationError(f'Malformed depends_on entry: {dep!r}')
    return parsed


_STEP_BUILDERS = {}


def _register(step_type):
    def wrap(fn):
        _STEP_BUILDERS[step_type] = fn
        return fn
    return wrap


# NOTE: there is no 'move_joint' step type. Recipe scripts only ever
# target a Pose — raw joint-angle targets have no continuity guarantee
# with a preceding or following pose move, which is exactly what caused
# a real tolerance-violation bug in testing. Manual/direct joint control
# is available separately via joint_jog_server, deliberately unreachable
# from a recipe.

@_register('move')
def _build_move(step_id, d, common):
    from_spawn_step = str(d.get('from_spawn_step', ''))
    has_target_pose = 'target_pose' in d
    if from_spawn_step and not has_target_pose:
        raise RecipeValidationError(
            f'Step "{step_id}": from_spawn_step still needs target_pose '
            f'alongside it — position (x/y/z) is pulled from the spawn '
            f'step and ignored here, but orientation (qx/qy/qz/qw) is a '
            f'grasp-approach decision this recipe still has to make (the '
            f'spawned object\'s own orientation isn\'t necessarily the '
            f'approach orientation you want). Give target_pose with just '
            f'qx/qy/qz/qw set.')
    if not from_spawn_step and not has_target_pose:
        raise RecipeValidationError(
            f'Step "{step_id}": move requires target_pose (optionally '
            f'with from_spawn_step for position)')
    return MoveStep(
        step_id=step_id, **common,
        target_pose=_pose_from_dict(d['target_pose']) if has_target_pose else None,
        traj_method=d.get('traj_method', 'ts'),
        traj_type=d.get('traj_type', 'blend'),
        blend_radius=float(d.get('blend_radius', 0.0)),
        speed_scale=float(d.get('speed_scale', 1.0)),
        from_spawn_step=from_spawn_step,
        engagement_fraction=float(d.get('engagement_fraction', 0.5)),
        approach_axis=str(d.get('approach_axis', 'z')),
    )


@_register('tool')
def _build_tool(step_id, d, common):
    return ToolStep(
        step_id=step_id, **common,
        tool_id=str(d['tool_id']), command=str(d['command']),
        params=list(d.get('params', [])),
        from_vision_step=str(d.get('from_vision_step', '')),
    )


@_register('io')
def _build_io(step_id, d, common):
    return IOStep(
        step_id=step_id, **common,
        io_id=str(d['io_id']), command=str(d['command']),
        params=list(d.get('params', [])),
    )


@_register('wait')
def _build_wait(step_id, d, common):
    return WaitStep(step_id=step_id, **common, duration_sec=float(d['duration_sec']))


@_register('vision')
def _build_vision(step_id, d, common):
    return VisionStep(
        step_id=step_id, **common,
        vision_id=str(d['vision_id']), operation=str(d['operation']),
        params=list(d.get('params', [])),
    )


@_register('spawn')
def _build_spawn(step_id, d, common):
    operation = str(d.get('operation', 'spawn'))
    if operation not in ('spawn', 'despawn'):
        raise RecipeValidationError(
            f'Step "{step_id}": spawn operation must be "spawn" or '
            f'"despawn", got "{operation}"')

    if operation == 'spawn':
        return SpawnStep(
            step_id=step_id, **common,
            operation=operation,
            type_id=str(d['type_id']),
            x=float(d.get('x', 0.0)), y=float(d.get('y', 0.0)), z=float(d.get('z', 0.0)),
            qx=float(d.get('qx', 0.0)), qy=float(d.get('qy', 0.0)),
            qz=float(d.get('qz', 0.0)), qw=float(d.get('qw', 1.0)),
            color=str(d.get('color', '')),
        )

    # despawn
    child_model = str(d.get('child_model', ''))
    from_spawn_step = str(d.get('from_spawn_step', ''))
    if bool(child_model) == bool(from_spawn_step):
        raise RecipeValidationError(
            f'Step "{step_id}": despawn requires exactly one of '
            f'child_model or from_spawn_step, got '
            f'child_model={child_model!r} from_spawn_step={from_spawn_step!r}')
    return SpawnStep(
        step_id=step_id, **common,
        operation=operation,
        child_model=child_model,
        from_spawn_step=from_spawn_step,
    )


class RecipeCompiler:

    @staticmethod
    def compile(raw_text: str) -> tuple[list[Step], str, str]:
        """Returns (steps, recipe_id, content_hash)."""
        doc = yaml.safe_load(raw_text)
        recipe_id = doc.get('recipe_id', 'unnamed_recipe')
        content_hash = hashlib.sha256(raw_text.encode('utf-8')).hexdigest()[:16]

        steps: list[Step] = []
        seen_ids: set[str] = set()

        for entry in doc.get('steps', []):
            step_id = str(entry['id'])
            if step_id in seen_ids:
                raise RecipeValidationError(f'Duplicate step id: {step_id}')
            seen_ids.add(step_id)

            step_type = entry['type']
            if step_type not in _STEP_BUILDERS:
                raise RecipeValidationError(
                    f'Unknown step type "{step_type}" in step "{step_id}". '
                    f'Valid: {list(_STEP_BUILDERS.keys())}')

            common = dict(
                depends_on=_parse_depends_on(entry.get('depends_on', [])),
                recovery=_parse_recovery(entry.get('recovery', 'abort')),
                max_retries=int(entry.get('max_retries', 2)),
            )
            steps.append(_STEP_BUILDERS[step_type](step_id, entry, common))

        RecipeCompiler._validate_references(steps, seen_ids)
        RecipeCompiler._validate_acyclic(steps)
        RecipeCompiler._validate_vision_refs(steps, seen_ids)
        RecipeCompiler._validate_spawn_refs(steps, seen_ids)

        return steps, recipe_id, content_hash

    @staticmethod
    def compile_file(path: str) -> tuple[list[Step], str, str]:
        with open(path, 'r') as f:
            raw_text = f.read()
        return RecipeCompiler.compile(raw_text)

    # ---- validation -----------------------------------------------------

    @staticmethod
    def _validate_references(steps: list[Step], known_ids: set[str]):
        for step in steps:
            for dep in step.depends_on:
                dep_id = dep[1] if isinstance(dep, tuple) else dep
                if dep_id not in known_ids:
                    raise RecipeValidationError(
                        f'Step "{step.step_id}" depends on unknown step "{dep_id}"')

    @staticmethod
    def _validate_vision_refs(steps: list[Step], known_ids: set[str]):
        """A ToolStep's from_vision_step (if set) must:
          1. reference a step_id that actually exists
          2. be a VisionStep, not some other type
          3. appear in this same step's depends_on as a full completion
             dependency (a plain string, not a ('progress', ...) tuple)
        Rule 3 is what actually prevents the race condition this field
        exists to avoid — without it, nothing guarantees the vision
        result is stored (self._results in orchestrator.py) before the
        tool step dispatches and tries to read it."""
        by_id = {s.step_id: s for s in steps}
        for step in steps:
            if not isinstance(step, ToolStep) or not step.from_vision_step:
                continue

            target_id = step.from_vision_step
            if target_id not in known_ids:
                raise RecipeValidationError(
                    f'Step "{step.step_id}" has from_vision_step="{target_id}" '
                    f'but no step with that id exists')

            target_step = by_id[target_id]
            if not isinstance(target_step, VisionStep):
                raise RecipeValidationError(
                    f'Step "{step.step_id}" has from_vision_step="{target_id}" '
                    f'but that step is a {type(target_step).__name__}, not a VisionStep')

            plain_deps = [d for d in step.depends_on if isinstance(d, str)]
            if target_id not in plain_deps:
                raise RecipeValidationError(
                    f'Step "{step.step_id}" has from_vision_step="{target_id}" '
                    f'but does not list it as a full completion dependency in '
                    f'depends_on (a progress-only dependency is not enough — '
                    f'the vision result must be fully available before this '
                    f'step dispatches)')

    @staticmethod
    def _validate_spawn_refs(steps: list[Step], known_ids: set[str]):
        """Two different fields reference a SpawnStep by from_spawn_step,
        with two different rules:

        A despawn SpawnStep's from_spawn_step (if set) must:
          1. reference a step_id that actually exists
          2. be a SpawnStep with operation='spawn' (not another despawn,
             and not some other step type)
          3. appear in this same step's depends_on as a full completion
             dependency (a plain string, not a ('progress', ...) tuple)
        Same rationale as _validate_vision_refs: without rule 3, nothing
        guarantees the spawn's result (the assigned child_model) is
        stored in orchestrator.py's self._results before this despawn
        step dispatches and tries to read it.

        A MoveStep's from_spawn_step (if set) only needs rules 1 and 2.
        Unlike despawn's child_model, a SpawnStep's x/y/z/qx/qy/qz/qw
        are compile-time literals already sitting on the Step object —
        orchestrator.py reads them directly at dispatch time, no
        self._results lookup involved, so there's no data race to
        protect against with a completion-dependency requirement. See
        MoveStep.from_spawn_step's own docstring in steps.py."""
        by_id = {s.step_id: s for s in steps}
        for step in steps:
            is_despawn_ref = isinstance(step, SpawnStep) and step.operation == 'despawn'
            is_move_ref = isinstance(step, MoveStep)
            if not (is_despawn_ref or is_move_ref):
                continue
            if not step.from_spawn_step:
                continue  # despawn: hand-typed child_model instead; move: target_pose instead

            target_id = step.from_spawn_step
            if target_id not in known_ids:
                raise RecipeValidationError(
                    f'Step "{step.step_id}" has from_spawn_step="{target_id}" '
                    f'but no step with that id exists')

            target_step = by_id[target_id]
            if not isinstance(target_step, SpawnStep) or target_step.operation != 'spawn':
                raise RecipeValidationError(
                    f'Step "{step.step_id}" has from_spawn_step="{target_id}" '
                    f'but that step is not a spawn-operation SpawnStep')

            if is_despawn_ref:
                plain_deps = [d for d in step.depends_on if isinstance(d, str)]
                if target_id not in plain_deps:
                    raise RecipeValidationError(
                        f'Step "{step.step_id}" has from_spawn_step="{target_id}" '
                        f'but does not list it as a full completion dependency in '
                        f'depends_on (a progress-only dependency is not enough — '
                        f'the assigned child_model must be fully available before '
                        f'this step dispatches)')

    @staticmethod
    def _validate_acyclic(steps: list[Step]):
        """Plain DFS cycle check — a recipe with a dependency cycle must
        fail to load, not deadlock the cell mid-run."""
        graph = {s.step_id: [] for s in steps}
        for s in steps:
            for dep in s.depends_on:
                dep_id = dep[1] if isinstance(dep, tuple) else dep
                graph[dep_id].append(s.step_id)  # edge: dependency -> dependent

        WHITE, GRAY, BLACK = 0, 1, 2
        color = {node: WHITE for node in graph}

        def visit(node, stack):
            color[node] = GRAY
            for nxt in graph[node]:
                if color[nxt] == GRAY:
                    cycle = ' -> '.join(stack + [nxt])
                    raise RecipeValidationError(f'Dependency cycle detected: {cycle}')
                if color[nxt] == WHITE:
                    visit(nxt, stack + [nxt])
            color[node] = BLACK

        for node in graph:
            if color[node] == WHITE:
                visit(node, [node])
