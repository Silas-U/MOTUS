"""
cell_orchestrator_node.py

DAG dispatch for one cell, N arm executors. This node knows step types,
dependencies, recovery policies, and named resources — nothing about
trajectories, JTC, or IK. Motion goes out as one ExecuteMoveStep call per
arm executor; the arm executor's own look-ahead pipeline (see
arm_executor_node.py) is what actually hides planning latency.

Requires two small additions to steps.py (not included here — this repo
doesn't have that file's current source to edit safely):
  Step.arm_id: str = 'arm1'       # which arm executor owns this step
  Step.resources: list[str] = []  # named resources this step must hold
recipe_compiler.py should validate arm_id against the loaded ArmRegistry
and resources as a plain string list.
"""

import os
import enum
import threading
from typing import Optional

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import Bool
from std_srvs.srv import Trigger
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import Pose

from robokpy_interfaces.action import ExecuteToolOp, ExecuteVisionOp, ExecuteMoveStep
from robokpy_interfaces.msg import CellState as CellStateMsg
from robokpy_interfaces.srv import ResumeExecution, LoadRecipe, SpawnObject, DespawnObject

from .recipe_compiler import RecipeCompiler, RecipeValidationError
from .object_catalog import ObjectCatalog, ObjectInstance
from .arm_registry import ArmRegistry
from .resource_lock import ResourceLock

from .steps import (
    RecoveryPolicy, Step, MoveStep, ToolStep, IOStep, WaitStep, VisionStep, SpawnStep,
)


class CellState(enum.Enum):
    IDLE = 'idle'
    PLANNING = 'planning'
    EXECUTING = 'executing'
    PAUSED = 'paused'
    ERROR = 'error'
    ESTOP = 'estop'


class CellOrchestrator(Node):
    """Indexed-script DAG dispatch. Motion steps go to a namespaced arm
    executor via ExecuteMoveStep; tool/vision/spawn/wait are dispatched
    directly, same as before."""

    DEFAULT_GOAL_TIMEOUT_SEC = 30.0
    GOAL_ACCEPT_TIMEOUT_SEC = 2.0
    MOVE_STEP_TIMEOUT_SEC = 90.0   # covers a whole batched run, arm executor owns per-leg timeouts

    def __init__(self):
        super().__init__('cell_orchestrator')
        self._cb_group = ReentrantCallbackGroup()
        self._lock = threading.RLock()

        # --- Arm registry ---
        self.declare_parameter('arm_namespaces', ['arm1'])
        arm_namespaces = list(self.get_parameter('arm_namespaces').value)
        if not arm_namespaces:
            raise RuntimeError('cell_orchestrator requires at least one entry in arm_namespaces')
        self._arms = ArmRegistry(self, arm_namespaces, self._cb_group)

        # --- Resource lock ---
        self._resource_lock = ResourceLock()
        self._active_resources: dict[str, list] = {}   # owner_step_id -> resources held

        # --- Action clients (tool/vision only — motion goes through ArmRegistry) ---
        self._tool_client = ActionClient(
            self, ExecuteToolOp, 'execute_tool_op', callback_group=self._cb_group)
        self._vision_client = ActionClient(
            self, ExecuteVisionOp, 'execute_vision_op', callback_group=self._cb_group)

        # --- Service clients ---
        self._spawn_client = self.create_client(
            SpawnObject, 'spawn_object', callback_group=self._cb_group)
        self._despawn_client = self.create_client(
            DespawnObject, 'despawn_object', callback_group=self._cb_group)

        # --- Parameters ---
        self.declare_parameter('objects_config_path', '')
        objects_config_path = self.get_parameter('objects_config_path').value
        if not objects_config_path:
            raise RuntimeError('cell_orchestrator requires objects_config_path')
        self._catalog = ObjectCatalog(objects_config_path)

        # --- Subscriptions / publishers / services ---
        self._safety_sub = self.create_subscription(
            Bool, '/safety_state', self._safety_cb, 10, callback_group=self._cb_group)
        self._cell_state_pub = self.create_publisher(CellStateMsg, '/cell_state', 10)
        self._resume_srv = self.create_service(
            ResumeExecution, 'resume_execution', self._resume_cb, callback_group=self._cb_group)
        self._load_recipe_srv = self.create_service(
            LoadRecipe, 'load_recipe', self._load_recipe_cb, callback_group=self._cb_group)
        self._start_recipe_srv = self.create_service(
            Trigger, 'start_recipe', self._start_recipe_cb, callback_group=self._cb_group)

        # --- DAG state ---
        self.state = CellState.IDLE
        self._steps: dict[str, Step] = {}
        self._in_degree: dict[str, int] = {}
        self._dependents: dict[str, list[str]] = {}
        self._progress_watchers: dict[str, list[tuple[str, float]]] = {}
        self._progress_fired: set[tuple[str, float]] = set()
        self._completed: set[str] = set()
        self._goal_handles: dict[str, object] = {}
        self._results: dict[str, object] = {}
        self._held_step_id: Optional[str] = None
        self._active_recipe_id: str = ''
        self._active_content_hash: str = ''
        self._run_of: dict[str, list] = {}
        self._goal_epoch: dict[str, int] = {}
        self._watchdogs: dict[str, object] = {}

        self.get_logger().info(f'CellOrchestrator ready, arms={sorted(arm_namespaces)}')

    # =================================================================
    # Recipe loading
    # =================================================================
    def _resolve_recipe_path(self, recipe_path: str) -> str:
        if os.path.isabs(recipe_path) and os.path.exists(recipe_path):
            return recipe_path
        if os.path.exists(recipe_path):
            return recipe_path
        share_dir = get_package_share_directory('robokpy_controller')
        return os.path.join(share_dir, 'recipes', recipe_path)

    def _load_recipe_cb(self, request, response):
        path = self._resolve_recipe_path(request.recipe_path)
        if not os.path.exists(path):
            response.success = False
            response.message = f'Recipe not found: {path}'
            return response
        try:
            steps, recipe_id, content_hash = RecipeCompiler.compile_file(
                path, known_arms=self._arms.known_arms())
        except RecipeValidationError as e:
            response.success = False
            response.message = f'Validation failed: {e}'
            return response
        except Exception as e:
            response.success = False
            response.message = f'Compile failed: {e}'
            return response

        with self._lock:
            if self.state == CellState.EXECUTING:
                response.success = False
                response.message = 'Cannot load while EXECUTING'
                return response
            self.load_recipe(steps, recipe_id)
            self._active_content_hash = content_hash

        self.get_logger().info(f'Recipe loaded: {recipe_id} [{content_hash}] ({len(steps)} steps)')
        response.success = True
        response.message = f'Loaded {recipe_id} ({len(steps)} steps)'
        response.recipe_id = recipe_id
        response.content_hash = content_hash
        return response

    def _start_recipe_cb(self, request, response):
        if not self.start():
            response.success = False
            response.message = f'No recipe ready (state={self.state.value})'
            return response
        response.success = True
        response.message = f'Started {self._active_recipe_id}'
        return response

    def load_recipe(self, steps: list, recipe_id: str = ''):
        with self._lock:
            self._steps = {s.step_id: s for s in steps}
            self._dependents = {s.step_id: [] for s in steps}
            self._in_degree = {}
            self._progress_watchers = {}
            self._active_recipe_id = recipe_id

            self._completed = set()
            self._progress_fired = set()
            self._goal_handles = {}
            self._results = {}
            self._held_step_id = None
            for timer in self._watchdogs.values():
                timer.cancel()
            self._watchdogs = {}
            self._goal_epoch = {}
            self._active_resources = {}

            for s in steps:
                unmet = 0
                for dep in s.depends_on:
                    if isinstance(dep, tuple):
                        _, dep_step_id, threshold = dep
                        self._progress_watchers.setdefault(dep_step_id, []).append(
                            (s.step_id, threshold))
                        unmet += 1
                    else:
                        unmet += 1
                        self._dependents[dep].append(s.step_id)
                self._in_degree[s.step_id] = unmet

            self._detect_runs()
            self.state = CellState.PLANNING
            self._publish_cell_state()

    def _detect_runs(self):
        """Detect maximal chains of same-arm MoveSteps so they can be
        batched into ONE ExecuteMoveStep goal — this is what gives the
        arm executor's look-ahead pipeline something to prefetch. Purely
        a latency/batching grouping, not a trajectory merge."""
        self._run_of = {}
        next_in_run = {}
        for a_id, step in self._steps.items():
            if not isinstance(step, MoveStep):
                continue
            deps = self._dependents.get(a_id, [])
            if len(deps) != 1:
                continue
            b_id = deps[0]
            b_step = self._steps.get(b_id)
            if not isinstance(b_step, MoveStep):
                continue
            if b_step.depends_on != [a_id]:
                continue
            if b_step.arm_id != step.arm_id:
                continue
            next_in_run[a_id] = b_id

        all_b = set(next_in_run.values())
        heads = [s_id for s_id, step in self._steps.items()
                 if isinstance(step, MoveStep) and s_id not in all_b]

        for head in heads:
            run = [head]
            cur = head
            while cur in next_in_run:
                cur = next_in_run[cur]
                run.append(cur)
            for member in run:
                self._run_of[member] = run

        merged = sorted({tuple(v) for v in self._run_of.values() if len(v) > 1})
        if merged:
            self.get_logger().info(f'[DAG] {len(merged)} batched motion run(s): {list(merged)}')

    def start(self) -> bool:
        with self._lock:
            if self.state != CellState.PLANNING:
                return False
            self.state = CellState.EXECUTING
            self._publish_cell_state()
            ready = [sid for sid, deg in self._in_degree.items() if deg == 0]
        for sid in ready:
            self._dispatch(sid)
        return True

    # =================================================================
    # Goal epoch / watchdog (pure timeout — no ground truth here, that
    # lives inside the arm executor now)
    # =================================================================
    def _new_epoch(self, step_id: str) -> int:
        with self._lock:
            epoch = self._goal_epoch.get(step_id, 0) + 1
            self._goal_epoch[step_id] = epoch
            return epoch

    def _is_current(self, step_id: str, epoch: int) -> bool:
        with self._lock:
            return self._goal_epoch.get(step_id) == epoch

    def _arm_watchdog(self, step_id: str, epoch: int, timeout_sec: float):
        old = self._watchdogs.pop(step_id, None)
        if old is not None:
            old.cancel()

        def _check():
            timer.cancel()
            with self._lock:
                self._watchdogs.pop(step_id, None)
                if not self._is_current(step_id, epoch) or step_id in self._completed:
                    return
            self.get_logger().error(f'[DAG] {step_id}: no result within {timeout_sec:.1f}s — failed')
            self._on_step_failed(step_id)

        timer = self.create_timer(timeout_sec, _check, callback_group=self._cb_group)
        self._watchdogs[step_id] = timer

    def _cancel_watchdog(self, step_id: str):
        with self._lock:
            timer = self._watchdogs.pop(step_id, None)
            if timer is not None:
                timer.cancel()

    # =================================================================
    # Resource lock helpers
    # =================================================================
    def _resources_for_run(self, run: list) -> list:
        seen, out = set(), []
        for sid in run:
            for r in getattr(self._steps[sid], 'resources', []):
                if r not in seen:
                    seen.add(r)
                    out.append(r)
        return out

    def _release_owner_resources(self, owner_id: str):
        resources = self._active_resources.pop(owner_id, None)
        if not resources:
            return
        unblocked = self._resource_lock.release(resources, owner_id)
        for uid in unblocked:
            with self._lock:
                ready = self._in_degree.get(uid) == 0 and uid not in self._completed
            if ready:
                self._dispatch(uid)

    # =================================================================
    # Dispatch
    # =================================================================
    def _dispatch(self, step_id: str):
        with self._lock:
            run = self._run_of.get(step_id)

        if run is not None:
            sub_run = run[run.index(step_id):]
            owner_id = sub_run[0]
            resources = self._resources_for_run(sub_run)
        else:
            owner_id = step_id
            resources = list(getattr(self._steps[step_id], 'resources', []))

        if resources and not self._resource_lock.try_acquire(resources, owner_id):
            self.get_logger().info(f'[DAG] {owner_id}: waiting on resource(s) {resources}')
            return
        if resources:
            self._active_resources[owner_id] = resources

        if run is not None:
            self.get_logger().info(f'[DAG] dispatching motion run {sub_run}')
            if self.executor is not None:
                self.executor.create_task(self._dispatch_motion_run(sub_run))
            else:
                self.get_logger().error(f'[DAG] {step_id}: no executor to schedule motion run')
                self._release_owner_resources(owner_id)
                self._on_step_failed(step_id)
            return

        step = self._steps[step_id]
        self.get_logger().info(f'[DAG] dispatching {step_id} ({type(step).__name__})')
        if isinstance(step, (ToolStep, IOStep)):
            self._dispatch_tool(step)
        elif isinstance(step, VisionStep):
            self._dispatch_vision(step)
        elif isinstance(step, SpawnStep):
            self._dispatch_spawn(step)
        elif isinstance(step, WaitStep):
            self._dispatch_wait(step)

    # ------------------------------------------------------------------
    # Motion runs — batched legs to ONE arm executor via ExecuteMoveStep
    # ------------------------------------------------------------------
    def _resolve_move_target_pose(self, step: MoveStep) -> Optional[Pose]:
        if not step.from_spawn_step:
            return step.target_pose

        spawn_step = self._steps.get(step.from_spawn_step)
        if spawn_step is None or not isinstance(spawn_step, SpawnStep):
            self.get_logger().error(f"[DAG] {step.step_id}: from_spawn_step invalid")
            return None

        otype = self._catalog.types.get(spawn_step.type_id)
        if otype is None:
            self.get_logger().error(f"[DAG] {step.step_id}: type_id not in catalog")
            return None

        inst = ObjectInstance(
            child_model='(resolved)', child_link=otype.child_link, type_id=spawn_step.type_id)
        offset = self._catalog.grasp_approach_offset(
            inst, approach_axis=step.approach_axis, engagement_fraction=step.engagement_fraction)

        pose = Pose()
        pose.position.x = spawn_step.x
        pose.position.y = spawn_step.y
        pose.position.z = spawn_step.z

        if step.use_spawn_orientation:
            import math
            yaw = math.atan2(
                2.0 * (spawn_step.qw * spawn_step.qz + spawn_step.qx * spawn_step.qy),
                1.0 - 2.0 * (spawn_step.qy * spawn_step.qy + spawn_step.qz * spawn_step.qz))
            half = yaw / 2.0
            pose.orientation.x = -math.sin(half)
            pose.orientation.y = math.cos(half)
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0
        elif step.target_pose is not None:
            pose.orientation = step.target_pose.orientation
        else:
            pose.orientation.x = 0.0
            pose.orientation.y = 1.0
            pose.orientation.z = 0.0
            pose.orientation.w = 0.0

        if step.approach_axis == 'x':
            pose.position.x += offset
        elif step.approach_axis == 'y':
            pose.position.y += offset
        else:
            pose.position.z += offset
        return pose

    def _build_move_goal(self, run: list) -> Optional[ExecuteMoveStep.Goal]:
        goal = ExecuteMoveStep.Goal()
        goal.leg_step_ids = list(run)
        failed_step_id = None
        with self._lock:
            for sid in run:
                step = self._steps[sid]
                target_pose = self._resolve_move_target_pose(step)
                if target_pose is None:
                    failed_step_id = sid
                    break
                goal.leg_target_poses.append(target_pose)
                goal.leg_traj_methods.append(step.traj_method)
                goal.leg_traj_types.append(step.traj_type)
                goal.leg_blend_radii.append(step.blend_radius)
            else:
                goal.speed_scale = self._steps[run[0]].speed_scale
        if failed_step_id is not None:
            self._release_owner_resources(run[0])
            self._on_step_failed(failed_step_id)
            return None
        return goal

    async def _dispatch_motion_run(self, run: list):
        owner_id = run[0]
        arm_id = self._steps[owner_id].arm_id
        goal = self._build_move_goal(run)
        if goal is None:
            return

        client = self._arms.client_for(arm_id)
        if not client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(f'[DAG] {arm_id}: execute_move_step unavailable')
            self._release_owner_resources(owner_id)
            self._on_step_failed(owner_id)
            return

        with self._lock:
            epoch = self._new_epoch(owner_id)
            self._arm_watchdog(owner_id, epoch, self.MOVE_STEP_TIMEOUT_SEC)

        def feedback_cb(msg):
            fb = msg.feedback
            if fb.percent_complete >= 1.0 and fb.current_step_id in run[:-1]:
                to_dispatch = []
                with self._lock:
                    self._completed.add(fb.current_step_id)
                    to_dispatch.extend(self._resolve_pending_progress(fb.current_step_id))
                for dep_id in to_dispatch:
                    self._dispatch(dep_id)

        handle = await client.send_goal_async(goal, feedback_callback=feedback_cb)
        with self._lock:
            self._cancel_watchdog(owner_id)
        if not handle.accepted:
            self.get_logger().error(f'[DAG] {arm_id}: ExecuteMoveStep goal rejected')
            self._release_owner_resources(owner_id)
            self._on_step_failed(owner_id)
            return

        with self._lock:
            for sid in run:
                self._goal_handles[sid] = handle
            epoch = self._new_epoch(owner_id)
            self._arm_watchdog(owner_id, epoch, self.MOVE_STEP_TIMEOUT_SEC)

        result = (await handle.get_result_async()).result
        with self._lock:
            self._cancel_watchdog(owner_id)

        self._release_owner_resources(owner_id)
        if result.success:
            self._results[owner_id] = result
            self._on_step_completed(run[-1])
        else:
            self.get_logger().error(
                f'[DAG] {owner_id}: ExecuteMoveStep failed, error_code={result.error_code}')
            self._on_step_failed(run[0])

    # ------------------------------------------------------------------
    # Tool / Vision / Spawn / Wait — unchanged from before
    # ------------------------------------------------------------------
    def _dispatch_tool(self, step):
        goal = ExecuteToolOp.Goal()
        goal.tool_id = step.tool_id if isinstance(step, ToolStep) else step.io_id
        goal.command = step.command

        failed = False
        with self._lock:
            if isinstance(step, ToolStep) and step.from_vision_step:
                vision_result = self._results.get(step.from_vision_step)
                if vision_result is None:
                    self.get_logger().error(f'[DAG] {step.step_id}: missing vision result')
                    failed = True
                else:
                    pos = vision_result.detected_pose.position
                    goal.params = [pos.x, pos.y, pos.z]
            else:
                goal.params = step.params
        if failed:
            self._release_owner_resources(step.step_id)
            self._on_step_failed(step.step_id)
            return

        if not self._tool_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error('[DAG] /execute_tool_op unavailable')
            self._release_owner_resources(step.step_id)
            self._on_step_failed(step.step_id)
            return

        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.GOAL_ACCEPT_TIMEOUT_SEC)

        future = self._tool_client.send_goal_async(goal)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f, epoch))

    def _dispatch_vision(self, step: VisionStep):
        goal = ExecuteVisionOp.Goal()
        goal.vision_id = step.vision_id
        goal.operation = step.operation
        goal.params = step.params
        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.GOAL_ACCEPT_TIMEOUT_SEC)
        future = self._vision_client.send_goal_async(goal)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f, epoch))

    def _dispatch_spawn(self, step: SpawnStep):
        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        if step.operation == 'spawn':
            if not self._spawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error('[DAG] /spawn_object unavailable')
                self._cancel_watchdog(step.step_id)
                self._release_owner_resources(step.step_id)
                self._on_step_failed(step.step_id)
                return
            req = SpawnObject.Request()
            req.type_id = step.type_id
            req.x, req.y, req.z = step.x, step.y, step.z
            req.qx, req.qy, req.qz, req.qw = step.qx, step.qy, step.qz, step.qw
            req.color = step.color
            future = self._spawn_client.call_async(req)
        else:
            if not self._despawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error('[DAG] /despawn_object unavailable')
                self._cancel_watchdog(step.step_id)
                self._release_owner_resources(step.step_id)
                self._on_step_failed(step.step_id)
                return
            failed = False
            with self._lock:
                if step.from_spawn_step:
                    spawn_result = self._results.get(step.from_spawn_step)
                    if spawn_result is None:
                        self.get_logger().error(f'[DAG] {step.step_id}: missing spawn result')
                        self._cancel_watchdog(step.step_id)
                        failed = True
                    else:
                        child_model = spawn_result.child_model
                else:
                    child_model = step.child_model
            if failed:
                self._release_owner_resources(step.step_id)
                self._on_step_failed(step.step_id)
                return
            req = DespawnObject.Request()
            req.child_model = child_model
            future = self._despawn_client.call_async(req)

        future.add_done_callback(lambda f: self._on_spawn_result(step.step_id, f, epoch))

    def _dispatch_wait(self, step: WaitStep):
        def fire():
            timer.cancel()
            self.get_logger().info(f'[DAG] {step.step_id}: wait complete')
            self._release_owner_resources(step.step_id)
            self._on_step_completed(step.step_id)
        timer = self.create_timer(step.duration_sec, fire, callback_group=self._cb_group)

    # =================================================================
    # Goal / result callbacks (tool/vision/spawn)
    # =================================================================
    def _on_goal_accepted(self, step_id: str, future, epoch: int):
        goal_handle = future.result()
        with self._lock:
            if not self._is_current(step_id, epoch):
                return
            if not goal_handle.accepted:
                self.get_logger().error(f'[DAG] {step_id}: goal REJECTED')
                self._cancel_watchdog(step_id)
                rejected = True
            else:
                self.get_logger().info(f'[DAG] {step_id}: goal accepted')
                self._goal_handles[step_id] = goal_handle
                self._arm_watchdog(step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)
                rejected = False
        if rejected:
            self._release_owner_resources(step_id)
            self._on_step_failed(step_id)
            return
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self._on_step_result(step_id, f, epoch))

    def _on_step_result(self, step_id: str, future, epoch: int):
        result = future.result().result
        with self._lock:
            if not self._is_current(step_id, epoch):
                return
            self._cancel_watchdog(step_id)
            self.get_logger().info(f'[DAG] {step_id}: result success={result.success}')
            success = result.success
            if success:
                self._results[step_id] = result
        self._release_owner_resources(step_id)
        if success:
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_spawn_result(self, step_id: str, future, epoch: int):
        response = future.result()
        with self._lock:
            if not self._is_current(step_id, epoch):
                return
            self._cancel_watchdog(step_id)
            self.get_logger().info(f'[DAG] {step_id}: spawn result success={response.success}')
            success = response.success
            if success:
                self._results[step_id] = response
        self._release_owner_resources(step_id)
        if success:
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    # =================================================================
    # DAG events
    # =================================================================
    def _resolve_pending_progress(self, step_id: str) -> list:
        """Caller must hold _lock. Returns step_ids to dispatch after release."""
        ready = []
        for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
            key = (dep_step_id, threshold)
            if key not in self._progress_fired:
                self._progress_fired.add(key)
                self._in_degree[dep_step_id] -= 1
                if self._in_degree[dep_step_id] == 0:
                    ready.append(dep_step_id)
        return ready

    def _on_step_completed(self, step_id: str):
        to_dispatch = []
        with self._lock:
            self._completed.add(step_id)
            self.get_logger().info(
                f'[DAG] {step_id}: COMPLETED ({len(self._completed)}/{len(self._steps)})')
            to_dispatch.extend(self._resolve_pending_progress(step_id))
            for dep_id in self._dependents.get(step_id, []):
                self._in_degree[dep_id] -= 1
                if self._in_degree[dep_id] == 0:
                    to_dispatch.append(dep_id)
            if len(self._completed) == len(self._steps):
                self.state = CellState.IDLE
                self._publish_cell_state()
        for dep_id in to_dispatch:
            self._dispatch(dep_id)

    def _on_step_failed(self, step_id: str):
        self.get_logger().error(f'[DAG] {step_id}: FAILED')
        with self._lock:
            step = self._steps[step_id]
            if step.recovery == RecoveryPolicy.RETRY and step.retry_count < step.max_retries:
                step.retry_count += 1
                action = 'retry'
            elif step.recovery == RecoveryPolicy.DEGRADE:
                action = 'complete'
            elif step.recovery == RecoveryPolicy.HOLD_FOR_OPERATOR:
                self.state = CellState.PAUSED
                self._held_step_id = step_id
                self._publish_cell_state(last_error=f'{step_id} held for operator')
                action = 'hold'
            else:
                action = 'abort'

        if action == 'retry':
            self._dispatch(step_id)
        elif action == 'complete':
            self._on_step_completed(step_id)
        elif action == 'abort':
            self._abort_all(last_error=f'{step_id} aborted')

    def _abort_all(self, last_error: str = ''):
        with self._lock:
            self.state = CellState.ERROR
            handles = list(self._goal_handles.values())
            self._publish_cell_state(last_error=last_error)
        for handle in handles:
            handle.cancel_goal_async()

    def _safety_cb(self, msg: Bool):
        if not msg.data:
            with self._lock:
                self.state = CellState.ESTOP
            self._abort_all(last_error='safety_state tripped')

    def _publish_cell_state(self, last_error: str = ''):
        msg = CellStateMsg()
        msg.state = {
            CellState.IDLE: CellStateMsg.IDLE,
            CellState.PLANNING: CellStateMsg.PLANNING,
            CellState.EXECUTING: CellStateMsg.EXECUTING,
            CellState.PAUSED: CellStateMsg.PAUSED,
            CellState.ERROR: CellStateMsg.ERROR,
            CellState.ESTOP: CellStateMsg.ESTOP,
        }[self.state]
        msg.active_recipe_id = self._active_recipe_id
        msg.last_error = last_error
        msg.stamp = self.get_clock().now().to_msg()
        self._cell_state_pub.publish(msg)

    def _resume_cb(self, request, response):
        with self._lock:
            if self.state != CellState.PAUSED or request.step_id != self._held_step_id:
                response.accepted = False
                response.message = 'No matching held step'
                return response
            held_step_id = self._held_step_id
            self._held_step_id = None
            self.state = CellState.EXECUTING
            self._publish_cell_state()
            proceed = request.proceed
        if proceed:
            self._dispatch(held_step_id)
        else:
            self._abort_all()
        response.accepted = True
        response.message = 'Resumed' if proceed else 'Aborted on operator command'
        return response


def main(args=None):
    rclpy.init(args=args)
    node = CellOrchestrator()
    executor = MultiThreadedExecutor(num_threads=8)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()