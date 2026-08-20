"""
RecipeCompiler — the authoring layer between a human-written script and
the orchestrator's DAG.

Validates before handing anything to the orchestrator:
  - every depends_on reference points to a step_id that exists
  - no dependency cycles
  - recovery policy names are valid
  - vision/spawn cross-references are correct

Also computes a content hash of the raw recipe text for traceability.
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


def _parse_resources(raw_resources) -> list:
    if not raw_resources:
        return []
    if not isinstance(raw_resources, list) or not all(isinstance(r, str) for r in raw_resources):
        raise RecipeValidationError(f'resources must be a list of strings, got {raw_resources!r}')
    return list(raw_resources)


def _parse_depends_on(raw_deps: list) -> list:
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


@_register('move')
def _build_move(step_id, d, common):
    from_spawn_step = str(d.get('from_spawn_step', ''))
    use_spawn_orientation = bool(d.get('use_spawn_orientation', False))
    has_target_pose = 'target_pose' in d

    if use_spawn_orientation and not from_spawn_step:
        raise RecipeValidationError(
            f"Step \"{step_id}\": use_spawn_orientation requires "
            f"from_spawn_step to be set (there is no spawn step to "
            f"inherit orientation from)")

    if from_spawn_step and not has_target_pose and not use_spawn_orientation:
        raise RecipeValidationError(
            f"Step \"{step_id}\": from_spawn_step still needs target_pose "
            f"alongside it — position (x/y/z) is pulled from the spawn "
            f"step and ignored here, but orientation (qx/qy/qz/qw) is a "
            f"grasp-approach decision this recipe still has to make (the "
            f"spawned object's own orientation isn't necessarily the "
            f"approach orientation you want). Give target_pose with just "
            f"qx/qy/qz/qw set, or set use_spawn_orientation: true to "
            f"inherit the spawn orientation automatically.")

    if not from_spawn_step and not has_target_pose:
        raise RecipeValidationError(
            f"Step \"{step_id}\": move requires target_pose (optionally "
            f"with from_spawn_step for position)")

    return MoveStep(
        step_id=step_id, **common,
        target_pose=_pose_from_dict(d['target_pose']) if has_target_pose else None,
        traj_method=d.get('traj_method', 'ts'),
        traj_type=d.get('traj_type', 'blend'),
        blend_radius=float(d.get('blend_radius', 0.0)),
        speed_scale=float(d.get('speed_scale', 1.0)),
        from_spawn_step=from_spawn_step,
        use_spawn_orientation=use_spawn_orientation,
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
    def compile(raw_text: str, known_arms: set = None) -> tuple[list[Step], str, str]:
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
                arm_id=str(entry.get('arm_id', 'arm1')),
                resources=_parse_resources(entry.get('resources', [])),
            )
            steps.append(_STEP_BUILDERS[step_type](step_id, entry, common))

        RecipeCompiler._validate_references(steps, seen_ids)
        RecipeCompiler._validate_acyclic(steps)
        RecipeCompiler._validate_vision_refs(steps, seen_ids)
        RecipeCompiler._validate_spawn_refs(steps, seen_ids)
        if known_arms is not None:
            RecipeCompiler._validate_arm_ids(steps, known_arms)

        return steps, recipe_id, content_hash

    @staticmethod
    def compile_file(path: str, known_arms: set = None) -> tuple[list[Step], str, str]:
        with open(path, 'r') as f:
            raw_text = f.read()
        return RecipeCompiler.compile(raw_text, known_arms=known_arms)

    @staticmethod
    def _validate_arm_ids(steps: list[Step], known_arms: set):
        for step in steps:
            if isinstance(step, MoveStep) and step.arm_id not in known_arms:
                raise RecipeValidationError(
                    f'Step "{step.step_id}" targets arm_id="{step.arm_id}", '
                    f'but this cell only has arms: {sorted(known_arms)}')

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
                    f'but does not list it as a full completion dependency')

    @staticmethod
    def _validate_spawn_refs(steps: list[Step], known_ids: set[str]):
        by_id = {s.step_id: s for s in steps}
        for step in steps:
            is_despawn_ref = isinstance(step, SpawnStep) and step.operation == 'despawn'
            is_move_ref = isinstance(step, MoveStep)
            if not (is_despawn_ref or is_move_ref):
                continue
            if not step.from_spawn_step:
                continue
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
                        f'but does not list it as a full completion dependency')

    @staticmethod
    def _validate_acyclic(steps: list[Step]):
        graph = {s.step_id: [] for s in steps}
        for s in steps:
            for dep in s.depends_on:
                dep_id = dep[1] if isinstance(dep, tuple) else dep
                graph[dep_id].append(s.step_id)
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