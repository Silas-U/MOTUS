"""
orchestrator_v2.py  —  Refactored orchestrator.

Key changes from v1:
  • No motion_planner middleman. Orchestrator talks to JTC DIRECTLY.
  • Planning is async via /plan_trajectory action (separate node/process).
  • ExecutionMonitor verifies completion from /current_joint_state encoders.
  • Watchdog checks ground truth before declaring failure.
  • Removed: plan cache, windowed executor, prefetch futures, exit-hint system.
  • Kept: DAG logic, step types, recovery policies, progress watchers.
"""

import os
import enum
import threading
import asyncio
from typing import Optional

import numpy as np
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import Bool, Float64MultiArray
from std_srvs.srv import Trigger
from ament_index_python.packages import get_package_share_directory
from geometry_msgs.msg import Pose
from control_msgs.action import FollowJointTrajectory

from robokpy_interfaces.action import ExecuteToolOp, ExecuteVisionOp, PlanTrajectory
from robokpy_interfaces.msg import CellState as CellStateMsg
from robokpy_interfaces.srv import ResumeExecution, LoadRecipe, SpawnObject, DespawnObject

from .recipe_compiler import RecipeCompiler, RecipeValidationError
from .object_catalog import ObjectCatalog, ObjectInstance
from .execution_monitor import ExecutionMonitor

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
    """Indexed-script DAG dispatch with direct JTC control."""

    # Timeouts
    DEFAULT_GOAL_TIMEOUT_SEC = 30.0
    GOAL_ACCEPT_TIMEOUT_SEC = 2.0
    MOTION_RESULT_TIMEOUT_SEC = 75.0

    # ExecutionMonitor tuning
    TARGET_TOLERANCE = 0.05          # rad
    STABLE_WINDOW_SEC = 0.5        # must be stable this long
    DIVERGENCE_TOLERANCE = 0.15    # rad

    def __init__(self):
        super().__init__('orchestrator')
        self._cb_group = ReentrantCallbackGroup()
        self._lock = threading.RLock()

        # --- Action clients ---
        self._plan_client = ActionClient(
            self, PlanTrajectory, 'plan_trajectory', callback_group=self._cb_group)
        self._jtc_client = ActionClient(
            self, FollowJointTrajectory,
            '/arm_controller/follow_joint_trajectory',
            callback_group=self._cb_group)
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
            raise RuntimeError('orchestrator requires objects_config_path')
        self._catalog = ObjectCatalog(objects_config_path)

        # --- Subscriptions ---
        self._safety_sub = self.create_subscription(
            Bool, '/safety_state', self._safety_cb, 10, callback_group=self._cb_group)
        self._joint_state_sub = self.create_subscription(
            Float64MultiArray, '/current_joint_state', self._joint_cb, 10,
            callback_group=self._cb_group)

        # --- Publishers ---
        self._cell_state_pub = self.create_publisher(CellStateMsg, '/cell_state', 10)

        # --- Services ---
        self._resume_srv = self.create_service(
            ResumeExecution, 'resume_execution', self._resume_cb, callback_group=self._cb_group)
        self._load_recipe_srv = self.create_service(
            LoadRecipe, 'load_recipe', self._load_recipe_cb, callback_group=self._cb_group)
        self._start_recipe_srv = self.create_service(
            Trigger, 'start_recipe', self._start_recipe_cb, callback_group=self._cb_group)

        # --- State ---
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
        self._q_current: Optional[np.ndarray] = None

        # --- Execution monitor ---
        self._exec_mon = ExecutionMonitor(
            target_tolerance=self.TARGET_TOLERANCE,
            stable_window_sec=self.STABLE_WINDOW_SEC,
            divergence_tolerance=self.DIVERGENCE_TOLERANCE,
            logger=self.get_logger(),
        )

        # --- Next-run lookahead ---
        # Maps run tuple -> asyncio.Future for the plan of the NEXT run
        self._next_plan_futures: dict[tuple, asyncio.Future] = {}

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
            steps, recipe_id, content_hash = RecipeCompiler.compile_file(path)
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

        self.get_logger().info(
            f'Recipe loaded: {recipe_id} [{content_hash}] ({len(steps)} steps)')
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

    def load_recipe(self, steps: list[Step], recipe_id: str = ''):
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
            self._next_plan_futures = {}

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
        """Detect maximal chains of MoveSteps for merged dispatch."""
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
            self.get_logger().info(f'[DAG] {len(merged)} merged motion run(s): {list(merged)}')

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
    # Joint state
    # =================================================================
    def _joint_cb(self, msg: Float64MultiArray):
        q = np.array(msg.data)
        self._q_current = q
        now = self.get_clock().now().nanoseconds * 1e-9
        self._exec_mon.update(q, now)

    # =================================================================
    # Goal epoch / watchdog
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
            failed = False
            with self._lock:
                self._watchdogs.pop(step_id, None)
                timer.cancel()
                if not self._is_current(step_id, epoch):
                    return
                if step_id in self._completed:
                    return
                # GROUND TRUTH CHECK: if arm is physically at target, succeed anyway
                if self._exec_mon.is_at_target():
                    self.get_logger().warn(
                        f'[DAG] {step_id}: watchdog fired but arm is at target — '
                        f'completing from encoder data')
                    # Mark complete outside lock to avoid deadlock
                    self._schedule_completion(step_id)
                    return
                self.get_logger().error(
                    f'[DAG] {step_id}: no result within {timeout_sec:.1f}s '
                    f'and arm NOT at target — treating as failed')
                failed = True
            if failed:
                self._on_step_failed(step_id)

        timer = self.create_timer(timeout_sec, _check, callback_group=self._cb_group)
        self._watchdogs[step_id] = timer

    def _cancel_watchdog(self, step_id: str):
        with self._lock:
            timer = self._watchdogs.pop(step_id, None)
            if timer is not None:
                timer.cancel()

    def _schedule_completion(self, step_id: str):
        """Called from watchdog when encoder data says we're done.
        Must not hold _lock."""
        self._on_step_completed(step_id)

    # =================================================================
    # Dispatch
    # =================================================================
    def _dispatch(self, step_id: str):
        with self._lock:
            run = self._run_of.get(step_id)

        if run is not None:
            sub_run = run[run.index(step_id):]
            self.get_logger().info(f'[DAG] dispatching motion run {sub_run}')
            # _dispatch_motion_run is async; schedule it on the executor's
            # event loop so sync callbacks (watchdogs, progress handlers)
            # don't create un-awaited coroutine objects.
            if self.executor is not None:
                self.executor.create_task(self._dispatch_motion_run(sub_run))
            else:
                self.get_logger().error(
                    f'[DAG] {step_id}: no executor available to schedule motion run')
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
    # Motion runs
    # ------------------------------------------------------------------
    def _resolve_move_target_pose(self, step: MoveStep) -> Optional[Pose]:
        if not step.from_spawn_step:
            return step.target_pose

        spawn_step = self._steps.get(step.from_spawn_step)
        if spawn_step is None or not isinstance(spawn_step, SpawnStep):
            self.get_logger().error(
                f"[DAG] {step.step_id}: from_spawn_step invalid")
            return None

        otype = self._catalog.types.get(spawn_step.type_id)
        if otype is None:
            self.get_logger().error(
                f"[DAG] {step.step_id}: type_id not in catalog")
            return None

        inst = ObjectInstance(
            child_model='(resolved)',
            child_link=otype.child_link,
            type_id=spawn_step.type_id)
        offset = self._catalog.grasp_approach_offset(
            inst,
            approach_axis=step.approach_axis,
            engagement_fraction=step.engagement_fraction)

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

    def _build_plan_goal(self, run: list) -> Optional[PlanTrajectory.Goal]:
        goal = PlanTrajectory.Goal()
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
            self._on_step_failed(failed_step_id)
            return None
        return goal

    async def _dispatch_motion_run(self, run: list):
        # 1. Plan (async — may already be prefetched)
        run_key = tuple(run)
        plan_goal = self._build_plan_goal(run)
        if plan_goal is None:
            return

        # Check if next-run prefetch already produced a plan
        prefetched = None
        with self._lock:
            future = self._next_plan_futures.pop(run_key, None)
        if future is not None and not future.done():
            self.get_logger().info(f'[DAG] run {run}: waiting for prefetched plan')
            try:
                prefetched = await asyncio.wait_for(future, timeout=20.0)
            except asyncio.TimeoutError:
                self.get_logger().warn(f'[DAG] run {run}: prefetch timeout, planning fresh')

        if prefetched is not None:
            plan_res = prefetched
            self.get_logger().info(f'[DAG] run {run}: using prefetched plan')
        else:
            if not self._plan_client.wait_for_server(timeout_sec=2.0):
                self.get_logger().error('[DAG] /plan_trajectory unavailable')
                self._on_step_failed(run[0])
                return
            plan_handle = await self._plan_client.send_goal_async(plan_goal)
            if not plan_handle.accepted:
                self.get_logger().error('[DAG] /plan_trajectory goal rejected')
                self._on_step_failed(run[0])
                return
            plan_res = await plan_handle.get_result_async()
            plan_res = plan_res.result
            if not plan_res.success:
                self.get_logger().error(
                    f'[DAG] Planning failed (code {plan_res.error_code})')
                self._on_step_failed(run[0])
                return

        # 2. Execute via JTC directly
        jtc_goal = FollowJointTrajectory.Goal()
        jtc_goal.trajectory = plan_res.trajectory
        predicted_q = np.array(plan_res.predicted_final_state)
        traj_dur = plan_res.total_duration

        self.get_logger().info(
            f'[DAG] run {run}: executing {traj_dur:.2f}s trajectory '
            f'({len(plan_res.trajectory.points)} points)')

        if not self._jtc_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error('[DAG] JTC unavailable')
            self._on_step_failed(run[0])
            return

        # Reset execution monitor
        self._exec_mon.reset(predicted_q)

        # Fire lookahead plan for NEXT run in background
        self._maybe_prefetch_next_run(run)

        with self._lock:
            epoch = self._new_epoch(run[-1])
            self._arm_watchdog(run[-1], epoch, self.MOTION_RESULT_TIMEOUT_SEC)

        def feedback_cb(msg):
            fb = msg.feedback
            actual_sec = fb.actual.time_from_start.sec + fb.actual.time_from_start.nanosec * 1e-9
            # Map to leg progress
            # (simplified: just report overall progress)
            pct = min(1.0, actual_sec / traj_dur) if traj_dur > 0 else 0.0
            # Find which leg we're in based on time ranges if needed
            # For now, use simple time-based mapping
            self._on_progress_time_based(run, actual_sec, traj_dur)

        jtc_handle_future = self._jtc_client.send_goal_async(
            jtc_goal, feedback_callback=feedback_cb)

        try:
            jtc_handle = await asyncio.wait_for(jtc_handle_future, timeout=5.0)
        except asyncio.TimeoutError:
            self.get_logger().error('[DAG] JTC goal send timeout')
            with self._lock:
                self._cancel_watchdog(run[-1])
            self._on_step_failed(run[0])
            return

        if not jtc_handle.accepted:
            self.get_logger().error('[DAG] JTC goal rejected')
            with self._lock:
                self._cancel_watchdog(run[-1])
            self._on_step_failed(run[0])
            return

        # Store handle for cancel
        with self._lock:
            for sid in run:
                self._goal_handles[sid] = jtc_handle

        # Wait for result with ground-truth fallback
        result_future = jtc_handle.get_result_async()
        done = False
        success = False
        check_interval = 0.1
        elapsed = 0.0
        while not done and elapsed < self.MOTION_RESULT_TIMEOUT_SEC + 10.0:
            await asyncio.sleep(check_interval)
            elapsed += check_interval

            if result_future.done():
                try:
                    jtc_res = result_future.result().result
                    success = getattr(jtc_res, 'error_code', 0) == 0
                except Exception as e:
                    self.get_logger().warn(f'[DAG] JTC result exception: {e}')
                    success = False
                done = True
            elif self._exec_mon.is_at_target():
                self.get_logger().info(
                    f'[DAG] run {run}: arm at target via encoder — completing')
                success = True
                done = True

        with self._lock:
            self._cancel_watchdog(run[-1])

        if not success:
            self._on_step_failed(run[0] if not success else run[-1])
        else:
            # Mark intermediate members complete, then cascade final
            to_dispatch = []
            with self._lock:
                for sid in run[:-1]:
                    self._completed.add(sid)
                    to_dispatch.extend(self._resolve_pending_progress(sid))
            for sid in to_dispatch:
                self._dispatch(sid)
            self._on_step_completed(run[-1])

    def _on_progress_time_based(self, run: list, actual_sec: float, total_sec: float):
        """Simple progress mapping for motion runs."""
        pct = min(1.0, actual_sec / total_sec) if total_sec > 0 else 0.0
        for sid in run:
            self._on_progress(sid, pct)

    def _maybe_prefetch_next_run(self, current_run: list):
        """Fire an async plan for the next motion run if unambiguous."""
        with self._lock:
            cur = current_run[-1]
            seen = set(current_run)
            while True:
                deps = self._dependents.get(cur, [])
                if len(deps) != 1:
                    return
                nxt = deps[0]
                if nxt in seen:
                    return
                seen.add(nxt)
                nxt_step = self._steps.get(nxt)
                if isinstance(nxt_step, MoveStep):
                    next_run = tuple(self._run_of.get(nxt, [nxt]))
                    if next_run == tuple(current_run):
                        return
                    # Already have one in flight?
                    if next_run in self._next_plan_futures:
                        return
                    break
                cur = nxt
            # Build goal for next run
            next_goal = self._build_plan_goal(list(next_run))
            if next_goal is None:
                return

        # Send async plan goal
        async def _do_prefetch():
            try:
                if not self._plan_client.wait_for_server(timeout_sec=2.0):
                    return
                handle = await self._plan_client.send_goal_async(next_goal)
                if not handle.accepted:
                    return
                res = await handle.get_result_async()
                return res.result
            except Exception as e:
                self.get_logger().warn(f'[DAG] Prefetch failed: {e}')
                return None

        loop = asyncio.get_event_loop()
        future = loop.create_future()

        async def _wrapper():
            try:
                result = await _do_prefetch()
                if not future.done():
                    future.set_result(result)
            except Exception as e:
                if not future.done():
                    future.set_exception(e)

        loop.create_task(_wrapper())

        with self._lock:
            self._next_plan_futures[next_run] = future
        self.get_logger().info(f'[DAG] Prefetching plan for {list(next_run)}')

    # ------------------------------------------------------------------
    # Tool / Vision / Spawn / Wait
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
                    self.get_logger().error(
                        f'[DAG] {step.step_id}: missing vision result')
                    failed = True
                else:
                    pos = vision_result.detected_pose.position
                    goal.params = [pos.x, pos.y, pos.z]
            else:
                goal.params = step.params

        if failed:
            self._on_step_failed(step.step_id)
            return

        if not self._tool_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error('[DAG] /execute_tool_op unavailable')
            self._on_step_failed(step.step_id)
            return

        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.GOAL_ACCEPT_TIMEOUT_SEC)

        future = self._tool_client.send_goal_async(goal)
        future.add_done_callback(
            lambda f: self._on_goal_accepted(step.step_id, f, epoch))

    def _dispatch_vision(self, step: VisionStep):
        goal = ExecuteVisionOp.Goal()
        goal.vision_id = step.vision_id
        goal.operation = step.operation
        goal.params = step.params

        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.GOAL_ACCEPT_TIMEOUT_SEC)

        future = self._vision_client.send_goal_async(goal)
        future.add_done_callback(
            lambda f: self._on_goal_accepted(step.step_id, f, epoch))

    def _dispatch_spawn(self, step: SpawnStep):
        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        if step.operation == 'spawn':
            if not self._spawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error('[DAG] /spawn_object unavailable')
                with self._lock:
                    self._cancel_watchdog(step.step_id)
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
                with self._lock:
                    self._cancel_watchdog(step.step_id)
                self._on_step_failed(step.step_id)
                return
            failed = False
            with self._lock:
                if step.from_spawn_step:
                    spawn_result = self._results.get(step.from_spawn_step)
                    if spawn_result is None:
                        self.get_logger().error(
                            f'[DAG] {step.step_id}: missing spawn result')
                        self._cancel_watchdog(step.step_id)
                        failed = True
                    else:
                        child_model = spawn_result.child_model
                else:
                    child_model = step.child_model
            if failed:
                self._on_step_failed(step.step_id)
                return
            req = DespawnObject.Request()
            req.child_model = child_model
            future = self._despawn_client.call_async(req)

        future.add_done_callback(
            lambda f: self._on_spawn_result(step.step_id, f, epoch))

    def _dispatch_wait(self, step: WaitStep):
        def fire():
            timer.cancel()
            self.get_logger().info(f'[DAG] {step.step_id}: wait complete')
            self._on_step_completed(step.step_id)
        timer = self.create_timer(step.duration_sec, fire, callback_group=self._cb_group)

    # =================================================================
    # Goal / result callbacks
    # =================================================================
    def _on_goal_accepted(self, step_id: str, future, epoch: int):
        goal_handle = future.result()
        rejected = False
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

        if rejected:
            self._on_step_failed(step_id)
            return

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(
            lambda f: self._on_step_result(step_id, f, epoch))

    def _on_step_result(self, step_id: str, future, epoch: int):
        result = future.result().result
        success = False
        with self._lock:
            if not self._is_current(step_id, epoch):
                return
            self._cancel_watchdog(step_id)
            self.get_logger().info(
                f'[DAG] {step_id}: result success={result.success}')
            if result.success:
                self._results[step_id] = result
                success = True
        if success:
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_spawn_result(self, step_id: str, future, epoch: int):
        response = future.result()
        success = False
        with self._lock:
            if not self._is_current(step_id, epoch):
                return
            self._cancel_watchdog(step_id)
            self.get_logger().info(
                f'[DAG] {step_id}: spawn result success={response.success}')
            if response.success:
                self._results[step_id] = response
                success = True
        if success:
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    # =================================================================
    # DAG events
    # =================================================================
    def _on_progress(self, step_id: str, percent_complete: float):
        to_dispatch = []
        with self._lock:
            for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
                key = (dep_step_id, threshold)
                if percent_complete >= threshold and key not in self._progress_fired:
                    self.get_logger().info(
                        f'[DAG] progress({step_id})={percent_complete:.2f} >= {threshold} '
                        f'-> unblocking {dep_step_id}')
                    self._progress_fired.add(key)
                    self._in_degree[dep_step_id] -= 1
                    if self._in_degree[dep_step_id] == 0:
                        to_dispatch.append(dep_step_id)
        for dep_id in to_dispatch:
            self._dispatch(dep_id)

    def _resolve_pending_progress(self, step_id: str) -> list[str]:
        """Caller must hold _lock. Returns step_ids to dispatch after release."""
        ready = []
        for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
            key = (dep_step_id, threshold)
            if key not in self._progress_fired:
                self.get_logger().info(
                    f'[DAG] {step_id} completed before progress({threshold}) fired '
                    f'-> unblocking {dep_step_id} anyway')
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
        action = None
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
    node = Orchestrator()
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
