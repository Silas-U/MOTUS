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

Also computes a content hash of the raw recipe text — this is the
recipe-versioning half of the persistence/traceability layer: every
execution log entry can cite exactly which recipe version ran.
"""

import hashlib
import yaml
from typing import Any

from geometry_msgs.msg import Pose

from .steps import (
    Step, MoveStep, ToolStep, IOStep, WaitStep, VisionStep,
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
    return MoveStep(
        step_id=step_id, **common,
        target_pose=_pose_from_dict(d['target_pose']),
        traj_method=d.get('traj_method', 'ts'),
        traj_type=d.get('traj_type', 'blend'),
        blend_radius=float(d.get('blend_radius', 0.0)),
        speed_scale=float(d.get('speed_scale', 1.0)),
    )


@_register('tool')
def _build_tool(step_id, d, common):
    return ToolStep(
        step_id=step_id, **common,
        tool_id=str(d['tool_id']), command=str(d['command']),
        params=list(d.get('params', [])),
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