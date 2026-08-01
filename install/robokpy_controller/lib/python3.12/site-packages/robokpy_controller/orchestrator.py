"""
Orchestrator — indexed-script DAG dispatch.

Steps are typed (Move, MovePose, Tool, IO, Wait, Vision) and dispatched
the instant their dependencies are satisfied. Motion trajectories are
generated JIT per step by motion_planner (blend_radius is author-set
per step, no look-ahead needed) rather than precomputed for the whole
recipe — this is what allows dynamic replanning (a VisionStep's result
can change a later MoveStep's target before it's dispatched).

Dependency types:
  - step_id                          : fire after that step completes
  - ('progress', step_id, threshold) : fire when that MOTION step's
                                        percent_complete feedback crosses
                                        threshold — for genuine overlap
                                        (e.g. start closing a gripper at
                                        80% into an approach)
"""

import os
import enum
from typing import Optional

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import Bool
from std_srvs.srv import Trigger
from ament_index_python.packages import get_package_share_directory

from robokpy_interfaces.action import ExecuteMotion, ExecuteToolOp, ExecuteVisionOp
from robokpy_interfaces.msg import CellState as CellStateMsg
from robokpy_interfaces.srv import ResumeExecution, LoadRecipe, SpawnObject, DespawnObject

from .recipe_compiler import RecipeCompiler, RecipeValidationError


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


class Orchestrator(Node):
    # Fallback deadline for any dispatched goal (tool/vision/motion run).
    # If no result arrives within this window, the step is treated as
    # failed (going through the recipe's own recovery policy) instead
    # of leaving the DAG stuck at EXECUTING forever — covers cases like
    # a stale/duplicate action-server response being swallowed at the
    # DDS layer (see 'Ignoring unexpected goal response' warning) or
    # any other silently-dropped result.
    DEFAULT_GOAL_TIMEOUT_SEC = 30.0

    def __init__(self):
        super().__init__('orchestrator')
        self._cb_group = ReentrantCallbackGroup()

        self._motion_client = ActionClient(
            self, ExecuteMotion, 'execute_motion', callback_group=self._cb_group)
        self._tool_client = ActionClient(
            self, ExecuteToolOp, 'execute_tool_op', callback_group=self._cb_group)
        self._vision_client = ActionClient(
            self, ExecuteVisionOp, 'execute_vision_op', callback_group=self._cb_group)

        # Plain services, not actions — object_spawner.py has no
        # feedback/progress concept, just a request/response.
        self._spawn_client = self.create_client(
            SpawnObject, 'spawn_object', callback_group=self._cb_group)
        self._despawn_client = self.create_client(
            DespawnObject, 'despawn_object', callback_group=self._cb_group)

        self._safety_sub = self.create_subscription(
            Bool, '/safety_state', self._safety_cb, 10, callback_group=self._cb_group)

        self._cell_state_pub = self.create_publisher(CellStateMsg, '/cell_state', 10)
        self._resume_srv = self.create_service(
            ResumeExecution, 'resume_execution', self._resume_cb, callback_group=self._cb_group)
        self._load_recipe_srv = self.create_service(
            LoadRecipe, 'load_recipe', self._load_recipe_cb, callback_group=self._cb_group)
        self._start_recipe_srv = self.create_service(
            Trigger, 'start_recipe', self._start_recipe_cb, callback_group=self._cb_group)

        self.state = CellState.IDLE
        self._steps: dict[str, Step] = {}
        self._in_degree: dict[str, int] = {}
        self._dependents: dict[str, list[str]] = {}
        self._progress_watchers: dict[str, list[tuple[str, float]]] = {}  # step_id -> [(dep_step_id, threshold)]
        self._progress_fired: set[tuple[str, float]] = set()
        self._completed: set[str] = set()
        self._goal_handles: dict[str, object] = {}
        self._results: dict[str, object] = {}   # e.g. VisionStep results feeding later MoveStep targets
        self._held_step_id: Optional[str] = None
        self._active_recipe_id: str = ''
        self._active_content_hash: str = ''
        self._run_of: dict[str, list] = {}
        # Monotonic per-step dispatch counter — lets callbacks/watchdogs
        # tell a stale response (or a stale timeout firing after a retry
        # already redispatched) apart from the currently active attempt.
        self._goal_epoch: dict[str, int] = {}
        self._watchdogs: dict[str, object] = {}

    # ---- recipe loading (runtime entry point) ---------------------------

    def _resolve_recipe_path(self, recipe_path: str) -> str:
        if os.path.isabs(recipe_path) and os.path.exists(recipe_path):
            return recipe_path
        # try relative to cwd first (handy for dev/testing)
        if os.path.exists(recipe_path):
            return recipe_path
        # fall back to <robokpy_controller share>/recipes/<name>
        share_dir = get_package_share_directory('robokpy_controller')
        candidate = os.path.join(share_dir, 'recipes', recipe_path)
        return candidate

    def _load_recipe_cb(self, request, response):
        if self.state == CellState.EXECUTING:
            response.success = False
            response.message = 'Cannot load a new recipe while EXECUTING — cancel or wait first'
            return response

        path = self._resolve_recipe_path(request.recipe_path)
        if not os.path.exists(path):
            response.success = False
            response.message = f'Recipe not found: {path}'
            return response

        try:
            steps, recipe_id, content_hash = RecipeCompiler.compile_file(path)
        except RecipeValidationError as e:
            response.success = False
            response.message = f'Recipe validation failed: {e}'
            return response
        except Exception as e:
            response.success = False
            response.message = f'Recipe compile failed: {e}'
            return response

        self.load_recipe(steps, recipe_id)
        self._active_content_hash = content_hash

        self.get_logger().info(
            f'Recipe loaded: {recipe_id} [{content_hash}]  ({len(steps)} step(s)) from {path}')

        response.success = True
        response.message = f'Loaded {recipe_id} ({len(steps)} steps)'
        response.recipe_id = recipe_id
        response.content_hash = content_hash
        return response

    def _start_recipe_cb(self, request, response):
        if self.state != CellState.PLANNING:
            response.success = False
            response.message = (
                f'No recipe ready to start (state={self.state.value}) — '
                f'call load_recipe first')
            return response

        self.start()
        response.success = True
        response.message = f'Started {self._active_recipe_id}'
        return response



    def load_recipe(self, steps: list[Step], recipe_id: str = ''):
        self._steps = {s.step_id: s for s in steps}
        self._dependents = {s.step_id: [] for s in steps}
        self._in_degree = {}
        self._progress_watchers = {}
        self._active_recipe_id = recipe_id

        # Reset all per-run state — without this, reloading the SAME
        # recipe a second time carries over stale entries from the
        # previous run: old _progress_fired keys would silently block
        # overlap dependencies from ever firing again, and stale
        # _goal_handles could be mistaken for goals still in flight.
        self._completed = set()
        self._progress_fired = set()
        self._goal_handles = {}
        self._results = {}
        self._held_step_id = None
        for timer in self._watchdogs.values():
            timer.cancel()
        self._watchdogs = {}
        self._goal_epoch = {}

        for s in steps:
            unmet = 0
            for dep in s.depends_on:
                if isinstance(dep, tuple):  # ('progress', dep_step_id, threshold)
                    _, dep_step_id, threshold = dep
                    self._progress_watchers.setdefault(dep_step_id, []).append((s.step_id, threshold))
                    unmet += 1
                else:
                    unmet += 1
                    self._dependents[dep].append(s.step_id)
            self._in_degree[s.step_id] = unmet

        self._detect_runs()
        self.state = CellState.PLANNING
        self._publish_cell_state()

    def _detect_runs(self):
        """Detect maximal chains of MoveSteps connected by a single plain
        (non-progress) dependency, so they dispatch as ONE merged
        ExecuteMotion goal instead of stopping at every step boundary.
        Every MoveStep ends up in exactly one run — self._run_of maps
        every member to its full ordered run list (a lone, unchained
        MoveStep is simply a run of length 1)."""
        self._run_of = {}

        next_in_run = {}
        for a_id, step in self._steps.items():
            if not isinstance(step, MoveStep):
                continue
            dependents_of_a = self._dependents.get(a_id, [])
            if len(dependents_of_a) != 1:
                continue
            b_id = dependents_of_a[0]
            b_step = self._steps.get(b_id)
            if not isinstance(b_step, MoveStep):
                continue
            if b_step.depends_on != [a_id]:
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
            self.get_logger().info(f'[DAG] detected {len(merged)} merged motion run(s): {list(merged)}')

    def start(self):
        self.state = CellState.EXECUTING
        self._publish_cell_state()
        # Snapshot before dispatching anything — dispatching one step can
        # cascade synchronously (e.g. a merged run's feedback firing a
        # progress dependency) and mutate _in_degree for a step this same
        # iteration hasn't reached yet, which would otherwise get
        # re-dispatched a second time when the iterator gets to it.
        ready = [step_id for step_id, degree in self._in_degree.items() if degree == 0]
        for step_id in ready:
            self._dispatch(step_id)

    # ---- goal epoch / watchdog --------------------------------------------

    def _new_epoch(self, step_id: str) -> int:
        """Bump and return the dispatch epoch for step_id. Call this once
        per actual dispatch attempt (including retries) — callbacks and
        watchdogs capture the epoch at dispatch time and check it's still
        current before acting, so a stale/duplicate response (e.g. from
        the DDS 'unexpected goal response' scenario) or a watchdog firing
        after a legitimate late result can't corrupt state for whatever
        the CURRENT attempt is doing."""
        epoch = self._goal_epoch.get(step_id, 0) + 1
        self._goal_epoch[step_id] = epoch
        return epoch

    def _is_current(self, step_id: str, epoch: int) -> bool:
        return self._goal_epoch.get(step_id) == epoch

    def _arm_watchdog(self, step_id: str, epoch: int, timeout_sec: float):
        old = self._watchdogs.pop(step_id, None)
        if old is not None:
            old.cancel()

        def _check():
            self._watchdogs.pop(step_id, None)
            timer.cancel()
            if not self._is_current(step_id, epoch):
                return  # a retry/new dispatch already superseded this
            if step_id in self._completed:
                return  # legitimately completed already
            self.get_logger().error(
                f'[DAG] {step_id}: no result within {timeout_sec:.1f}s — '
                f'treating as failed (possible stale/duplicate action '
                f'server response or dropped result)')
            self._on_step_failed(step_id)

        timer = self.create_timer(timeout_sec, _check, callback_group=self._cb_group)
        self._watchdogs[step_id] = timer

    def _cancel_watchdog(self, step_id: str):
        timer = self._watchdogs.pop(step_id, None)
        if timer is not None:
            timer.cancel()

    # ---- dispatch ---------------------------------------------------------

    def _dispatch(self, step_id: str):
        run = self._run_of.get(step_id)
        if run is not None:
            # Dispatching from a point mid-run (a retry of a failed leg)
            # correctly re-dispatches only the remaining sub-run from
            # there, not the whole original run from its head.
            sub_run = run[run.index(step_id):]
            self.get_logger().info(f'[DAG] dispatching motion run {sub_run}')
            self._dispatch_motion_run(sub_run)
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

    def _dispatch_motion_run(self, run: list):
        goal = ExecuteMotion.Goal()
        goal.leg_step_ids = list(run)
        for step_id in run:
            step = self._steps[step_id]
            goal.leg_target_poses.append(step.target_pose)
            goal.leg_traj_methods.append(step.traj_method)
            goal.leg_traj_types.append(step.traj_type)
            goal.leg_blend_radii.append(step.blend_radius)
        goal.speed_scale = self._steps[run[0]].speed_scale

        if not self._motion_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(
                f'[DAG] run {run}: /execute_motion action server not available — is motion_planner running?')
            self._on_step_failed(run[0])
            return

        def feedback_cb(feedback_msg):
            self.get_logger().info(
                f'[DAG] run {run}: leg={feedback_msg.feedback.current_leg_step_id} '
                f'leg_percent_complete={feedback_msg.feedback.leg_percent_complete:.2f}')
            self._on_progress(feedback_msg.feedback.current_leg_step_id, feedback_msg.feedback.leg_percent_complete)

        # Watchdog/epoch keyed on the run's final member — that's the one
        # whose completion actually cascades (see _on_run_result).
        epoch = self._new_epoch(run[-1])
        self._arm_watchdog(run[-1], epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        future = self._motion_client.send_goal_async(goal, feedback_callback=feedback_cb)
        future.add_done_callback(lambda f: self._on_run_goal_accepted(run, f, epoch))

    def _dispatch_tool(self, step):
        goal = ExecuteToolOp.Goal()
        goal.tool_id = step.tool_id if isinstance(step, ToolStep) else step.io_id
        goal.command = step.command

        # Vision->grasp threading: recipe_compiler already guarantees (at
        # compile time) that from_vision_step, if set, is a real VisionStep
        # AND a full completion dependency of this step — so self._results
        # is guaranteed populated by the time this dispatches. Defensive
        # check kept anyway since "guaranteed by another module" is still
        # worth verifying at the point it actually matters.
        if isinstance(step, ToolStep) and step.from_vision_step:
            vision_result = self._results.get(step.from_vision_step)
            if vision_result is None:
                self.get_logger().error(
                    f'[DAG] {step.step_id}: from_vision_step='
                    f'"{step.from_vision_step}" has no stored result — '
                    f'this should be unreachable given recipe_compiler\'s '
                    f'validation; treating as failed rather than guessing')
                self._on_step_failed(step.step_id)
                return
            pos = vision_result.detected_pose.position
            goal.params = [pos.x, pos.y, pos.z]
        else:
            goal.params = step.params

        if not self._tool_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(
                f'[DAG] {step.step_id}: /execute_tool_op action server not available — is tool_action_server running?')
            self._on_step_failed(step.step_id)
            return

        epoch = self._new_epoch(step.step_id)
        self._arm_watchdog(step.step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        future = self._tool_client.send_goal_async(goal)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f, epoch))

    def _dispatch_vision(self, step: VisionStep):
        goal = ExecuteVisionOp.Goal()
        goal.vision_id = step.vision_id
        goal.operation = step.operation
        goal.params = step.params

        epoch = self._new_epoch(step.step_id)
        self._arm_watchdog(step.step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        future = self._vision_client.send_goal_async(goal)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f, epoch))

    def _dispatch_spawn(self, step: SpawnStep):
        # Plain service calls, not actions — object_spawner.py has no
        # goal-accepted/feedback phase, just request/response, so this
        # skips the two-phase pattern _dispatch_tool/_dispatch_vision use.
        epoch = self._new_epoch(step.step_id)
        self._arm_watchdog(step.step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        if step.operation == 'spawn':
            if not self._spawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error(
                    f'[DAG] {step.step_id}: /spawn_object service not '
                    f'available — is object_spawner running?')
                self._cancel_watchdog(step.step_id)
                self._on_step_failed(step.step_id)
                return
            req = SpawnObject.Request()
            req.type_id = step.type_id
            req.x, req.y, req.z = step.x, step.y, step.z
            req.qx, req.qy, req.qz, req.qw = step.qx, step.qy, step.qz, step.qw
            future = self._spawn_client.call_async(req)

        else:  # despawn
            if not self._despawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error(
                    f'[DAG] {step.step_id}: /despawn_object service not '
                    f'available — is object_spawner running?')
                self._cancel_watchdog(step.step_id)
                self._on_step_failed(step.step_id)
                return

            # recipe_compiler guarantees (at compile time) that exactly
            # one of child_model/from_spawn_step is set, and that
            # from_spawn_step, if used, is a full completion dependency
            # of this step — so self._results is guaranteed populated
            # here. Defensive check kept anyway, same reasoning as the
            # from_vision_step check in _dispatch_tool.
            if step.from_spawn_step:
                spawn_result = self._results.get(step.from_spawn_step)
                if spawn_result is None:
                    self.get_logger().error(
                        f'[DAG] {step.step_id}: from_spawn_step='
                        f'"{step.from_spawn_step}" has no stored result — '
                        f'this should be unreachable given recipe_compiler\'s '
                        f'validation; treating as failed rather than guessing')
                    self._cancel_watchdog(step.step_id)
                    self._on_step_failed(step.step_id)
                    return
                child_model = spawn_result.child_model
            else:
                child_model = step.child_model

            req = DespawnObject.Request()
            req.child_model = child_model
            future = self._despawn_client.call_async(req)

        future.add_done_callback(lambda f: self._on_spawn_result(step.step_id, f, epoch))

    def _dispatch_wait(self, step: WaitStep):
        def fire():
            timer.cancel()
            self.get_logger().info(f'[DAG] {step.step_id}: wait complete')
            self._on_step_completed(step.step_id)
        timer = self.create_timer(step.duration_sec, fire, callback_group=self._cb_group)

    def _on_goal_accepted(self, step_id: str, future, epoch: int):
        if not self._is_current(step_id, epoch):
            self.get_logger().warn(
                f'[DAG] {step_id}: ignoring stale goal-response (epoch {epoch} superseded)')
            return
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error(f'[DAG] {step_id}: goal REJECTED by action server')
            self._cancel_watchdog(step_id)
            self._on_step_failed(step_id)
            return
        self.get_logger().info(f'[DAG] {step_id}: goal accepted')
        self._goal_handles[step_id] = goal_handle
        # Goal accepted — re-arm the watchdog for the (potentially longer)
        # result-wait phase now that we know it's actually running.
        self._arm_watchdog(step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self._on_step_result(step_id, f, epoch))

    def _on_run_goal_accepted(self, run: list, future, epoch: int):
        final_id = run[-1]
        if not self._is_current(final_id, epoch):
            self.get_logger().warn(
                f'[DAG] run {run}: ignoring stale goal-response (epoch {epoch} superseded)')
            return
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error(f'[DAG] run {run}: goal REJECTED by action server')
            self._cancel_watchdog(final_id)
            self._on_step_failed(run[0])
            return
        self.get_logger().info(f'[DAG] run {run}: goal accepted')
        for step_id in run:
            self._goal_handles[step_id] = goal_handle
        self._arm_watchdog(final_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self._on_run_result(run, f, epoch))

    # ---- events -------------------------------------------------------

    def _on_progress(self, step_id: str, percent_complete: float):
        for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
            key = (dep_step_id, threshold)
            if percent_complete >= threshold and key not in self._progress_fired:
                self.get_logger().info(
                    f'[DAG] progress({step_id})={percent_complete:.2f} >= {threshold} -> unblocking {dep_step_id}')
                self._progress_fired.add(key)
                self._in_degree[dep_step_id] -= 1
                if self._in_degree[dep_step_id] == 0:
                    self._dispatch(dep_step_id)

    def _on_step_result(self, step_id: str, future, epoch: int):
        if not self._is_current(step_id, epoch):
            self.get_logger().warn(
                f'[DAG] {step_id}: ignoring stale result (epoch {epoch} superseded)')
            return
        self._cancel_watchdog(step_id)
        result = future.result().result
        self.get_logger().info(
            f'[DAG] {step_id}: result success={result.success} error_code={result.error_code}')
        if result.success:
            self._results[step_id] = result
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_spawn_result(self, step_id: str, future, epoch: int):
        if not self._is_current(step_id, epoch):
            self.get_logger().warn(
                f'[DAG] {step_id}: ignoring stale spawn/despawn result (epoch {epoch} superseded)')
            return
        self._cancel_watchdog(step_id)
        # Plain service response, not an action result — no nested .result.
        response = future.result()
        self.get_logger().info(
            f'[DAG] {step_id}: spawn/despawn result success={response.success} '
            f'message={response.message}')
        if response.success:
            self._results[step_id] = response
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_run_result(self, run: list, future, epoch: int):
        final_id = run[-1]
        if not self._is_current(final_id, epoch):
            self.get_logger().warn(
                f'[DAG] run {run}: ignoring stale result (epoch {epoch} superseded)')
            return
        self._cancel_watchdog(final_id)
        result = future.result().result
        self.get_logger().info(
            f'[DAG] run {run}: result success={result.success} error_code={result.error_code}')
        if result.success:
            # Intermediate members' only "dependent" is the next run
            # member, already handled by being part of this same merged
            # goal — cascading their completion normally would re-dispatch
            # a step that's already done. Only the LAST member can have
            # real external dependents (guaranteed by _detect_runs), so
            # only it goes through the full cascade.
            for step_id in run[:-1]:
                self._mark_run_member_completed(step_id)
            self._on_step_completed(run[-1])
        else:
            failed_id = result.failed_leg_step_id or run[-1]
            self._on_step_failed(failed_id)

    def _resolve_pending_progress(self, step_id: str):
        """A step that just completed has, by definition, reached 100%
        progress — resolve any progress-watchers still pending for it,
        regardless of whether their threshold's feedback message ever
        actually arrived (short/fast moves may complete between feedback
        ticks). Without this, a progress dependency that never fires
        deadlocks its dependent forever even though the step it's
        watching is done."""
        for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
            key = (dep_step_id, threshold)
            if key not in self._progress_fired:
                self.get_logger().info(
                    f'[DAG] {step_id} completed before progress({threshold}) ever fired -> unblocking {dep_step_id} anyway')
                self._progress_fired.add(key)
                self._in_degree[dep_step_id] -= 1
                if self._in_degree[dep_step_id] == 0:
                    self._dispatch(dep_step_id)

    def _mark_run_member_completed(self, step_id: str):
        """Marks an intermediate (non-final) merged-run member complete
        WITHOUT cascading to its dependent — see _on_run_result for why
        that's safe. Progress-watcher fallback still applies exactly as
        for a normal completion."""
        self._completed.add(step_id)
        self.get_logger().info(
            f'[DAG] {step_id}: COMPLETED as part of merged run ({len(self._completed)}/{len(self._steps)})')
        self._resolve_pending_progress(step_id)

    def _on_step_completed(self, step_id: str):
        self._completed.add(step_id)
        self.get_logger().info(f'[DAG] {step_id}: COMPLETED ({len(self._completed)}/{len(self._steps)})')
        self._resolve_pending_progress(step_id)

        for dep_id in self._dependents.get(step_id, []):
            self._in_degree[dep_id] -= 1
            if self._in_degree[dep_id] == 0:
                self._dispatch(dep_id)
        if len(self._completed) == len(self._steps):
            self.state = CellState.IDLE
            self._publish_cell_state()

    def _on_step_failed(self, step_id: str):
        self.get_logger().error(f'[DAG] {step_id}: FAILED')
        step = self._steps[step_id]
        if step.recovery == RecoveryPolicy.RETRY and step.retry_count < step.max_retries:
            step.retry_count += 1
            self._dispatch(step_id)
        elif step.recovery == RecoveryPolicy.DEGRADE:
            self._on_step_completed(step_id)
        elif step.recovery == RecoveryPolicy.HOLD_FOR_OPERATOR:
            self.state = CellState.PAUSED
            self._held_step_id = step_id
            self._publish_cell_state(last_error=f'{step_id} held for operator')
        else:
            self._abort_all(last_error=f'{step_id} aborted')

    def _abort_all(self, last_error: str = ''):
        self.state = CellState.ERROR
        for handle in self._goal_handles.values():
            handle.cancel_goal_async()
        self._publish_cell_state(last_error=last_error)

    def _safety_cb(self, msg: Bool):
        if not msg.data:
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
        if self.state != CellState.PAUSED or request.step_id != self._held_step_id:
            response.accepted = False
            response.message = 'No matching held step'
            return response
        held_step_id = self._held_step_id
        self._held_step_id = None
        self.state = CellState.EXECUTING
        self._publish_cell_state()
        if request.proceed:
            self._dispatch(held_step_id)
        else:
            self._abort_all()
        response.accepted = True
        response.message = 'Resumed' if request.proceed else 'Aborted on operator command'
        return response


def main(args=None):
    rclpy.init(args=args)
    node = Orchestrator()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        executor.shutdown()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()