#!/usr/bin/env python3
"""
preflight_recipe.py

Validates a recipe WITHOUT moving anything, in three layers:

  1. Compile — RecipeCompiler.compile_file(): DAG structure, references,
     recovery policies, and (as of the earlier fix) literal duplicate
     consecutive poses within one recipe's text.

  2. Group + resolve — reuses the REAL, unmodified
     CellOrchestrator._detect_runs() and
     CellOrchestrator._resolve_move_target_pose() (including
     from_spawn_step catalog resolution) by calling them, unbound,
     against a lightweight duck-typed shim instead of constructing a
     full CellOrchestrator. _detect_runs/_resolve_move_target_pose only
     ever touch self._steps / self._dependents / self._catalog /
     self.get_logger() — never ArmRegistry, ResourceLock, or any
     action/service client — so the shim needs nothing else, and this
     stays offline: no live ROS graph interaction, safe to run before
     the stack is even launched. This is the SAME reasoning that led
     recipe_compiler.py to duplicate planner_core's tiny
     _normalize_traj_type rather than import planner_core's whole
     dependency chain — except here the reused logic (run detection,
     spawn-pose resolution) is genuinely complex, so it's called
     directly instead of re-derived, at zero duplication risk.

  3. Plan — for each detected run, in order, actually calls the REAL
     plan_trajectory() (the same function arm_executor_node.py calls)
     against a KinematicsFacade built the same way arm_executor builds
     its own (same xacro robot_description, same IK fallback seeding,
     same preferred-posture/joint-limit wiring) — so this exercises the
     real IK-along-blended-path behavior, not just per-waypoint
     reachability. A successfully planned run's predicted_q seeds the
     next run, so a multi-run recipe is checked under realistic
     sequential seeding, not reset-to-home between every run.

     Also runs the same degenerate-consecutive-pose distance check
     arm_executor_node.py runs at dispatch time (DEGENERATE_POS_EPS_M /
     DEGENERATE_ANGLE_EPS_RAD below) — plan_trajectory can SILENTLY
     corrupt orientation on a degenerate segment rather than raising,
     which is exactly what made that bug hard to find originally, so a
     bare try/except around plan_trajectory alone would miss it.

Usage (same params file as arm_executor, plus recipe_path):

    ros2 run robokpy_controller preflight_recipe --ros-args \\
        --params-file install/robokpy_controller/share/robokpy_controller/config/robokpy_base.yaml \\
        --params-file install/robokpy_controller/share/robokpy_controller/config/robots/ur5e.yaml \\
        -p recipe_path:=/path/to/recipe.yaml

Exits 0 if every run planned cleanly, 1 otherwise — composes in scripts
and run_recipe.py's single-command wrapper below.
"""

import os
import sys
import threading

import numpy as np
import rclpy
from rclpy.node import Node

from ament_index_python.packages import get_package_share_directory

import yaml
import xacro

from .recipe_compiler import RecipeCompiler, RecipeValidationError
from .object_catalog import ObjectCatalog
from .cell_orchestrator_node import CellOrchestrator
from .steps import MoveStep
from .mp_kinematics import KinematicsFacade
from .mp_types import TrajectoryConfig
from .planner_core import plan_trajectory, PlanningError, TrajectoryLeg


# Mirrors arm_executor_node.py's DEGENERATE_POS_EPS_M /
# DEGENERATE_ANGLE_EPS_RAD / _pose_array_dist / _find_degenerate_leg_pair
# by hand — kept in sync manually, same as recipe_compiler's
# _normalize_traj_type. Small and stable enough that duplicating it here
# is lower-risk than constructing a full ArmExecutor node just to reach
# three instance methods.
DEGENERATE_POS_EPS_M = 1e-4
DEGENERATE_ANGLE_EPS_RAD = 1e-3


def _pose_array_dist(a: np.ndarray, b: np.ndarray):
    pos_dist = float(np.linalg.norm(a[:3] - b[:3]))
    dot = float(np.clip(abs(np.dot(a[3:], b[3:])), -1.0, 1.0))
    angle = 2.0 * float(np.arccos(dot))
    return pos_dist, angle


def _find_degenerate_leg_pair(seed_pose: np.ndarray, legs):
    prev_pose = seed_pose
    prev_label = '<seed>'
    for leg in legs:
        pos_dist, angle = _pose_array_dist(prev_pose, leg.target_pose)
        if pos_dist < DEGENERATE_POS_EPS_M and angle < DEGENERATE_ANGLE_EPS_RAD:
            return prev_label, leg.step_id, pos_dist, angle
        prev_pose = leg.target_pose
        prev_label = leg.step_id
    return None


class _OrchestratorShim:
    """Duck-typed stand-in for CellOrchestrator — provides exactly the
    attributes _detect_runs / _resolve_move_target_pose touch, nothing
    else. See module docstring for why this exists instead of
    constructing a real CellOrchestrator."""

    def __init__(self, steps, catalog, logger):
        self._steps = {s.step_id: s for s in steps}
        self._dependents = {s.step_id: [] for s in steps}
        for s in steps:
            for dep in s.depends_on:
                if isinstance(dep, str):
                    self._dependents.setdefault(dep, []).append(s.step_id)
        self._catalog = catalog
        self._lock = threading.RLock()
        self._logger = logger
        self._run_of = {}

    def get_logger(self):
        return self._logger


def _pose_to_array(pose) -> np.ndarray:
    return np.array([
        pose.position.x, pose.position.y, pose.position.z,
        pose.orientation.x, pose.orientation.y,
        pose.orientation.z, pose.orientation.w,
    ])


def _resolve_recipe_path(recipe_path: str) -> str:
    """Mirrors CellOrchestrator._resolve_recipe_path exactly (that
    method touches no instance state, so this is a direct copy, not a
    reimplementation) — lets a bare filename like 'test4.yaml' resolve
    against share/robokpy_controller/recipes/, same as the live
    load_recipe service already does. Without this, preflight would
    reject a bare name the live service accepts just fine, forcing a
    full path here for no reason."""
    if os.path.isabs(recipe_path) and os.path.exists(recipe_path):
        return recipe_path
    if os.path.exists(recipe_path):
        return recipe_path
    share_dir = get_package_share_directory('robokpy_controller')
    return os.path.join(share_dir, 'recipes', recipe_path)


class PreflightNode(Node):
    """One-shot: construct, run the preflight, exit. Never spun."""

    def __init__(self):
        super().__init__('preflight_recipe')

        self.declare_parameter('recipe_path', '')
        recipe_path = self.get_parameter('recipe_path').value
        if not recipe_path:
            raise RuntimeError(
                'preflight_recipe requires -p recipe_path:=/path/to/recipe.yaml')

        self.declare_parameter('arm_type', 'ur5e')
        self.declare_parameter('namespace', 'arm1')
        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link', 'tcp')
        self.declare_parameter('kinematic_solver_backend', 'robokpy')
        self.declare_parameter('mask', [1] * 6)
        self.declare_parameter('objects_config_path', '')

        self.declare_parameter('vel_limits', [1.5, 1.5, 2.0, 2.0, 2.5, 2.5])
        self.declare_parameter('acc_limits', [5.0, 5.0, 8.0, 8.0, 10.0, 10.0])
        self.declare_parameter('jerk_limits', [50.0, 50.0, 80.0, 80.0, 100.0, 100.0])
        self.declare_parameter('pos_limits_lo', [-3.14] * 6)
        self.declare_parameter('pos_limits_hi', [3.14] * 6)
        self.declare_parameter('cartesian_vel_limit', 0.25)
        self.declare_parameter('default_traj_method', 'js')
        self.declare_parameter('default_traj_type', 'lspb')
        self.declare_parameter('default_speed_factor', 1.0)
        self.declare_parameter('default_blend_radius', 0.0)
        self.declare_parameter('default_duration_per_segment', 3.0)
        self.declare_parameter('default_dt', 0.04)
        self.declare_parameter('default_n_samples', 10)
        self.declare_parameter('default_n_blend', 20)

        pkg = get_package_share_directory('robokpy_controller')

        objects_config_path = (
            self.get_parameter('objects_config_path').value
            or os.path.join(pkg, 'config', 'objects.yaml')
        )
        self._catalog = ObjectCatalog(objects_config_path)

        arm_type = self.get_parameter('arm_type').value
        namespace = self.get_parameter('namespace').value
        robot_description = self._build_robot_description(pkg, arm_type, namespace)

        base_link = self.get_parameter('planning_base_link').value
        tip_link = self.get_parameter('planning_tip_link').value
        backend = self.get_parameter('kinematic_solver_backend').value

        self._kin = KinematicsFacade(
            robot_description=robot_description,
            base_link=base_link,
            tip_link=tip_link,
            backend=backend,
            mask=list(self.get_parameter('mask').value),
            logger=self.get_logger(),
        )

        num_joints = self._kin.num_joints
        self.declare_parameter('home_pose', [0.0] * num_joints)
        home_q = np.array(self.get_parameter('home_pose').value)

        # Mirrors arm_executor_node.py's IK fallback seeding + posture +
        # joint-limit wiring, so preflight tests under the same
        # conditions live execution actually runs under.
        self._kin.set_fallback_seeds([list(home_q)])
        q_min, q_max = self._kin.model.model.get_joint_limits_in_chain(base_link, tip_link)
        self._kin.model.ik.set_joint_limits(q_min, q_max)
        self._kin.model.ik.set_preferred_posture(home_q)

        self._config = TrajectoryConfig.from_node_params(self)
        self._home_q = home_q
        self._recipe_path = recipe_path

    def _build_robot_description(self, pkg, arm_type, namespace):
        """Mirrors arm.launch.py's configure() exactly — same xacro
        file, same mappings, same tool_type resolution — so preflight's
        model matches what's actually deployed."""
        robot_xacro_file = os.path.join(pkg, 'urdf', 'robokpy_robot.urdf.xacro')
        robot_config_yaml = os.path.join(pkg, 'config', 'robots', f'{arm_type}.yaml')
        controllers_yaml_path = os.path.join(
            pkg, 'config', 'ur5e_robotiq_85_gripper_controllers.yaml')

        tool_type_str = 'none'
        if os.path.isfile(robot_config_yaml):
            with open(robot_config_yaml, 'r') as f:
                robot_cfg = yaml.safe_load(f)
            if robot_cfg:
                root_params = robot_cfg.get('/**', {}).get('ros__parameters', {})
                tool_type_str = root_params.get('tool_type', 'none')

        return xacro.process_file(
            robot_xacro_file,
            mappings={
                'prefix': '', 'arm_type': arm_type, 'gripper_type': tool_type_str,
                'sim': 'true', 'position_proportional_gain': '0.5',
                'controllers_yaml_path': controllers_yaml_path,
                'namespace': namespace,
            },
        ).toxml()

    # ==================================================================
    # Preflight
    # ==================================================================

    def run(self) -> bool:
        """Returns True iff every run in the recipe planned cleanly."""

        report = []
        ok = True

        resolved_path = _resolve_recipe_path(self._recipe_path)
        if not os.path.exists(resolved_path):
            self.get_logger().error(
                f'[preflight] Recipe not found: {resolved_path}')
            return False

        # --- Layer 1: compile ---
        try:
            steps, recipe_id, content_hash = RecipeCompiler.compile_file(
                resolved_path)
        except RecipeValidationError as e:
            self.get_logger().error(f'[preflight] COMPILE FAILED: {e}')
            return False
        except Exception as e:
            self.get_logger().error(f'[preflight] COMPILE FAILED (unexpected): {e}')
            return False

        self.get_logger().info(
            f'[preflight] compiled {recipe_id} [{content_hash}] '
            f'({len(steps)} steps)'
        )

        # --- Layer 2: group + resolve (real orchestrator logic) ---
        shim = _OrchestratorShim(steps, self._catalog, self.get_logger())
        CellOrchestrator._detect_runs(shim)

        seen_runs = []
        for run in shim._run_of.values():
            if run not in seen_runs:
                seen_runs.append(run)
        # Singleton (non-batched) MoveSteps never appear in _run_of —
        # add them as their own one-leg runs, in declaration order.
        batched_ids = {sid for run in seen_runs for sid in run}
        for s in steps:
            if isinstance(s, MoveStep) and s.step_id not in batched_ids:
                seen_runs.append([s.step_id])

        q_seed = self._home_q.copy()

        for run in seen_runs:
            legs = []
            resolve_failed = False
            for sid in run:
                step = shim._steps[sid]
                pose = CellOrchestrator._resolve_move_target_pose(shim, step)
                if pose is None:
                    report.append(
                        f'  FAIL  {sid}: could not resolve target_pose '
                        f'(bad from_spawn_step / catalog reference)')
                    ok = False
                    resolve_failed = True
                    break
                legs.append(TrajectoryLeg(
                    step_id=sid,
                    target_pose=_pose_to_array(pose),
                    traj_method=step.traj_method,
                    traj_type=step.traj_type,
                    blend_radius=step.blend_radius,
                ))
            if resolve_failed:
                continue

            # --- Layer 3a: degenerate-segment check (silent-corruption
            # case — plan_trajectory won't always raise for this) ---
            seed_pose = self._kin.compute_fk(q_seed)
            dup = _find_degenerate_leg_pair(seed_pose, legs)
            if dup is not None:
                prev_label, cur_id, pos_dist, angle = dup
                report.append(
                    f'  FAIL  {run}: \'{prev_label}\' -> \'{cur_id}\' near-identical '
                    f'pose (\u0394pos={pos_dist*1000:.3f}mm, '
                    f'\u0394orient={np.degrees(angle):.3f}\u00b0) — would collapse '
                    f'to a zero-length segment')
                ok = False
                continue

            # --- Layer 3b: actually plan it ---
            try:
                planned = plan_trajectory(legs, q_seed.copy(), self._config, self._kin)
            except PlanningError as exc:
                report.append(f'  FAIL  {run}: {exc}')
                ok = False
                continue
            except Exception as exc:
                report.append(f'  FAIL  {run}: unexpected error: {exc}')
                ok = False
                continue

            report.append(
                f'  OK    {run} — {len(legs)} leg(s), '
                f'{planned.total_duration:.2f}s'
            )
            q_seed = planned.predicted_q

        self.get_logger().info(
            f'[preflight] {"PASSED" if ok else "FAILED"} — '
            f'{len(seen_runs)} run(s) checked:\n' + '\n'.join(report)
        )
        return ok


def main(args=None):
    rclpy.init(args=args)
    try:
        node = PreflightNode()
    except Exception as e:
        print(f'[preflight] setup failed: {e}', file=sys.stderr)
        rclpy.shutdown()
        sys.exit(1)

    ok = node.run()
    node.destroy_node()
    rclpy.shutdown()
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()