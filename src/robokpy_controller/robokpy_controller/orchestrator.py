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

from robokpy_interfaces.action import ExecuteMotion, ExecuteToolOp, ExecuteVisionOp
from robokpy_interfaces.msg import CellState as CellStateMsg
from robokpy_interfaces.srv import ResumeExecution, LoadRecipe, SpawnObject, DespawnObject

from .recipe_compiler import RecipeCompiler, RecipeValidationError
from .object_catalog import ObjectCatalog, ObjectInstance


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
    # If the action-server goal-response is lost at the DDS layer (rclpy
    # "Ignoring unexpected goal response"), we want to detect that and retry
    # *before* the server has time to finish the operation.  This timeout is
    # used for the initial "wait for goal accepted" phase; _on_goal_accepted
    # re-arms the full DEFAULT_GOAL_TIMEOUT_SEC once we know the goal is
    # actually running.  Tuning: should be longer than your slowest goal
    # acceptance latency, but shorter than your fastest operation.
    GOAL_ACCEPT_TIMEOUT_SEC = 2.0
    # Motion runs specifically go through motion_planner's own internal
    # lost-JTC-response recovery (up to _jtc_goal_response_timeout=30s
    # waiting for the JTC accept, then leg-duration+2s, then a 5s
    # verify-arm-position check) BEFORE it can send a result back over
    # execute_motion. DEFAULT_GOAL_TIMEOUT_SEC (30s) is shorter than that
    # worst case, so this watchdog was firing and failing the step before
    # motion_planner's own recovery ever got a chance to confirm success —
    # confirmed via logs (descend_pick_a_2/4: no-result-within-30s FAILED
    # while feedback showed the arm still genuinely executing). Sized
    # generously above motion_planner's worst case; retune down only if
    # motion_planner's own timeouts are tightened to match.
    MOTION_RESULT_TIMEOUT_SEC = 75.0

    def __init__(self):
        super().__init__('orchestrator')
        self._cb_group = ReentrantCallbackGroup()
        # Every dict/state field below (_steps, _in_degree, _completed,
        # _goal_handles, _results, _watchdogs, _goal_epoch, self.state)
        # is read AND written from callbacks that ReentrantCallbackGroup
        # + MultiThreadedExecutor can run concurrently on different
        # threads (a safety trip, a watchdog timer, and an action result
        # can all land at once). This RLock protects every read-modify-
        # write of that state. RULE OF THUMB enforced throughout this
        # file: the lock must NEVER be held across a blocking call
        # (wait_for_server/wait_for_service) — those can take up to 2s,
        # and holding the lock that long would stall the e-stop path
        # (_safety_cb/_abort_all) behind an unrelated dispatch. So every
        # method below acquires the lock only for the pure state
        # transition, releases it, THEN performs any blocking call or
        # recursive dispatch. RLock (not Lock) because these methods
        # nest into each other on the same thread (e.g. _on_step_failed
        # -> _on_step_completed) and reentrant acquisition must not
        # deadlock.
        self._lock = threading.RLock()

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

        # Needed to resolve MoveStep.from_spawn_step at dispatch time
        # (grasp_approach_offset) — same objects_config_path convention
        # as object_spawner.py/grasp_attach_bridge.py/object_pose_resolver.py.
        self.declare_parameter('objects_config_path', '')
        objects_config_path = self.get_parameter('objects_config_path').value
        if not objects_config_path:
            raise RuntimeError(
                'orchestrator requires the objects_config_path parameter '
                '(path to objects.yaml) — none was provided')
        self._catalog = ObjectCatalog(objects_config_path)

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
        # Lookahead-planning: for a run that has exactly one unambiguous
        # motion run following it (see _detect_next_runs), maps
        # tuple(run) -> tuple(next_run). _prefetched tracks which runs
        # have already had their next run's prefetch fired, so a run's
        # feedback (which may repeat) never double-fires it.
        self._next_run_of: dict[tuple, tuple] = {}
        self._prefetched: set[tuple] = set()
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
        # File I/O + compilation happen unlocked -- they don't touch any
        # shared DAG state and compile_file can be slow for a large
        # recipe, no reason to block other callbacks for that.
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

        # The EXECUTING check and the load must happen atomically
        # together, or a start_recipe racing in on another thread could
        # flip state to EXECUTING in the gap between our check and our
        # load, corrupting a run already in flight.
        with self._lock:
            if self.state == CellState.EXECUTING:
                response.success = False
                response.message = 'Cannot load a new recipe while EXECUTING — cancel or wait first'
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
        # start() itself does the PLANNING check atomically with the
        # state flip (see its docstring) -- checking again here first
        # would just reopen the same race it's designed to close.
        if not self.start():
            response.success = False
            response.message = (
                f'No recipe ready to start (state={self.state.value}) — '
                f'call load_recipe first')
            return response
        response.success = True
        response.message = f'Started {self._active_recipe_id}'
        return response



    def load_recipe(self, steps: list[Step], recipe_id: str = ''):
        # No blocking calls anywhere in here (or in _detect_runs) -- safe
        # to hold the lock for the whole body. Caller (_load_recipe_cb)
        # already holds it too; RLock makes that a harmless no-op nest.
        with self._lock:
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
            self._prefetched = set()

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
            self._detect_next_runs()
            self.state = CellState.PLANNING
            self._publish_cell_state()

    def _detect_next_runs(self):
        """For each merged motion run, finds the single motion run that
        will execute immediately after it, by walking forward from the
        run's last member through any number of non-MoveStep steps
        (tool/spawn/wait/vision) — as long as each hop is unambiguous
        (exactly one dependent) — until it reaches a MoveStep. Records
        nothing if the path branches or dead-ends first; that just means
        this run's next step won't be prefetched, never a correctness
        problem (see _maybe_fire_prefetch — prefetching is best-effort).

        Safe to run at compile time because every MoveStep's target_pose
        is a compile-time literal (recipe YAML values, optionally
        combined with a SpawnStep's own literal x/y/z — see
        MoveStep.from_spawn_step's docstring in steps.py); unlike
        ToolStep.from_vision_step, no MoveStep pose ever depends on a
        runtime result, so planning a run ahead of its DAG dependencies
        actually firing is always structurally valid — only physical
        EXECUTION still has to wait its turn."""
        self._next_run_of = {}
        runs = sorted({tuple(v) for v in self._run_of.values()})
        for run in runs:
            cur = run[-1]
            seen = set(run)
            while True:
                deps = self._dependents.get(cur, [])
                if len(deps) != 1:
                    break  # branch or dead end -- ambiguous, skip prefetch
                nxt = deps[0]
                if nxt in seen:
                    break  # defensive; _validate_acyclic already forbids this
                seen.add(nxt)
                nxt_step = self._steps.get(nxt)
                if isinstance(nxt_step, MoveStep):
                    next_run = tuple(self._run_of.get(nxt, [nxt]))
                    if next_run != run:
                        self._next_run_of[run] = next_run
                    break
                cur = nxt
        if self._next_run_of:
            self.get_logger().info(
                f'[DAG] {len(self._next_run_of)} run(s) eligible for lookahead prefetch')

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

    def start(self) -> bool:
        """Transition PLANNING -> EXECUTING and dispatch every initially-
        ready step. Returns False (no-op) if not currently in PLANNING.
        The check-then-flip is done atomically under the lock so a
        second start_recipe call (or a racing load_recipe) can't land in
        the gap between the check and the flip. Dispatch itself happens
        AFTER the lock is released -- see the module-level note in
        __init__ on why blocking calls must never run while it's held."""
        with self._lock:
            if self.state != CellState.PLANNING:
                return False
            self.state = CellState.EXECUTING
            self._publish_cell_state()
            # Snapshot before dispatching anything — dispatching one step
            # can cascade synchronously (e.g. a merged run's feedback
            # firing a progress dependency) and mutate _in_degree for a
            # step this same iteration hasn't reached yet, which would
            # otherwise get re-dispatched a second time when the
            # iterator gets to it.
            ready = [step_id for step_id, degree in self._in_degree.items() if degree == 0]

        for step_id in ready:
            self._dispatch(step_id)
        return True

    # ---- goal epoch / watchdog --------------------------------------------

    def _new_epoch(self, step_id: str) -> int:
        """Bump and return the dispatch epoch for step_id. Call this once
        per actual dispatch attempt (including retries) — callbacks and
        watchdogs capture the epoch at dispatch time and check it's still
        current before acting, so a stale/duplicate response (e.g. from
        the DDS 'unexpected goal response' scenario) or a watchdog firing
        after a legitimate late result can't corrupt state for whatever
        the CURRENT attempt is doing. Caller must hold self._lock."""
        with self._lock:
            epoch = self._goal_epoch.get(step_id, 0) + 1
            self._goal_epoch[step_id] = epoch
            return epoch

    def _is_current(self, step_id: str, epoch: int) -> bool:
        # Caller must hold self._lock.
        return self._goal_epoch.get(step_id) == epoch

    def _arm_watchdog(self, step_id: str, epoch: int, timeout_sec: float):
        # Caller must hold self._lock.
        old = self._watchdogs.pop(step_id, None)
        if old is not None:
            old.cancel()

        def _check():
            # Runs on a timer thread, concurrently with whatever thread
            # the real result lands on. Without the lock here, both
            # threads could pass their "not yet completed" check before
            # either writes anything -- watchdog fails the step at the
            # exact moment the real result completes it, corrupting the
            # DAG (a step both failed-and-retried AND completed). The
            # lock makes "is this step already completed" and "act on
            # the timeout" one atomic decision.
            failed = False
            with self._lock:
                self._watchdogs.pop(step_id, None)
                timer.cancel()
                if not self._is_current(step_id, epoch):
                    pass  # a retry/new dispatch already superseded this
                elif step_id in self._completed:
                    pass  # legitimately completed already
                else:
                    self.get_logger().error(
                        f'[DAG] {step_id}: no result within {timeout_sec:.1f}s — '
                        f'treating as failed (possible stale/duplicate action '
                        f'server response or dropped result)')
                    failed = True
            # _on_step_failed can recurse into _dispatch/_abort_all, both
            # of which may block -- must run outside the lock.
            if failed:
                self._on_step_failed(step_id)

        timer = self.create_timer(timeout_sec, _check, callback_group=self._cb_group)
        self._watchdogs[step_id] = timer

    def _cancel_watchdog(self, step_id: str):
        # Caller must hold self._lock.
        timer = self._watchdogs.pop(step_id, None)
        if timer is not None:
            timer.cancel()

    # ---- dispatch ---------------------------------------------------------

    def _dispatch(self, step_id: str):
        # Callers of _dispatch never hold self._lock when calling it (see
        # each call site) — this only takes the lock briefly to read the
        # step/run lookup, then releases before doing anything that
        # could block or recurse.
        with self._lock:
            run = self._run_of.get(step_id)
            step = None if run is not None else self._steps[step_id]

        if run is not None:
            # Dispatching from a point mid-run (a retry of a failed leg)
            # correctly re-dispatches only the remaining sub-run from
            # there, not the whole original run from its head.
            sub_run = run[run.index(step_id):]
            self.get_logger().info(f'[DAG] dispatching motion run {sub_run}')
            self._dispatch_motion_run(sub_run)
            return
        self.get_logger().info(f'[DAG] dispatching {step_id} ({type(step).__name__})')
        if isinstance(step, (ToolStep, IOStep)):
            self._dispatch_tool(step)
        elif isinstance(step, VisionStep):
            self._dispatch_vision(step)
        elif isinstance(step, SpawnStep):
            self._dispatch_spawn(step)
        elif isinstance(step, WaitStep):
            self._dispatch_wait(step)

    def _resolve_move_target_pose(self, step: MoveStep) -> Optional[Pose]:
        """Returns step.target_pose unchanged if from_spawn_step isn't
        set. Otherwise composes the actual grasp target from the
        referenced SpawnStep's own compile-time pose plus the
        catalog's grasp_approach_offset() — this is what replaces
        hand-tuning a z value per recipe (see motus.md's whole TCP-
        offset saga this session). Returns None on failure so the
        caller can fail the dispatch cleanly instead of sending a
        bogus goal."""
        if not step.from_spawn_step:
            return step.target_pose

        spawn_step = self._steps.get(step.from_spawn_step)
        if spawn_step is None or not isinstance(spawn_step, SpawnStep):
            self.get_logger().error(
                f'[DAG] {step.step_id}: from_spawn_step='
                f'"{step.from_spawn_step}" does not resolve to a SpawnStep — '
                f'this should be unreachable given recipe_compiler\'s '
                f'validation; treating as failed rather than guessing')
            return None

        otype = self._catalog.types.get(spawn_step.type_id)
        if otype is None:
            self.get_logger().error(
                f'[DAG] {step.step_id}: from_spawn_step="{step.from_spawn_step}" '
                f'has type_id="{spawn_step.type_id}", which is not in the '
                f'loaded object catalog — treating as failed rather than guessing')
            return None

        # Throwaway instance — grasp_approach_offset only reads
        # type_id (via its ObjectType lookup) and child_link, neither
        # of which depends on which specific spawned instance this
        # ends up being; the actual child_model is decided later, at
        # runtime, by object_spawner's free-slot picker.
        inst = ObjectInstance(
            child_model='(resolved at dispatch time, not yet known)',
            child_link=otype.child_link, type_id=spawn_step.type_id)
        offset = self._catalog.grasp_approach_offset(
            inst, approach_axis=step.approach_axis,
            engagement_fraction=step.engagement_fraction)

        pose = Pose()
        pose.position.x = spawn_step.x
        pose.position.y = spawn_step.y
        pose.position.z = spawn_step.z
        # Orientation is the recipe's own grasp-approach decision, not
        # inherited from the spawned object's orientation — see
        # recipe_compiler._build_move, which requires target_pose to
        # still be given (for its orientation fields) alongside
        # from_spawn_step for exactly this reason.
        pose.orientation.x = step.target_pose.orientation.x
        pose.orientation.y = step.target_pose.orientation.y
        pose.orientation.z = step.target_pose.orientation.z
        pose.orientation.w = step.target_pose.orientation.w
        if step.approach_axis == 'x':
            pose.position.x += offset
        elif step.approach_axis == 'y':
            pose.position.y += offset
        else:
            pose.position.z += offset
        return pose

    def _build_motion_goal(self, run: list) -> Optional[object]:
        """Builds the ExecuteMotion.Goal for `run` (leg poses/methods/etc)
        without dispatching anything — shared by the real dispatch path
        (_dispatch_motion_run) and the lookahead-prefetch path
        (_maybe_fire_prefetch). Returns None and reports the failure via
        _on_step_failed if a target pose can't be resolved; a prefetch
        caller should just drop the prefetch silently on None (the real
        dispatch will hit + report the same failure again when its turn
        comes, which is the one that actually matters)."""
        goal = ExecuteMotion.Goal()
        goal.leg_step_ids = list(run)
        failed_step_id = None
        with self._lock:
            for step_id in run:
                step = self._steps[step_id]
                target_pose = self._resolve_move_target_pose(step)
                if target_pose is None:
                    failed_step_id = step_id
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

    def _maybe_fire_prefetch(self, run: list, predicted_final_state, from_real_dispatch: bool = True):
        """Called from a REAL motion run's feedback callback the moment
        its predicted_final_state feedback arrives (see
        ExecuteMotion.action) — i.e. as soon as ITS trajectory is
        planned, well before it physically finishes executing. If this
        run has an unambiguous next motion run (see _detect_next_runs),
        kicks off a plan_only goal for that next run right now, seeded
        from the predicted state, so its trajectory is ready and cached
        by the time the DAG actually gets around to dispatching it for
        real.

        Deliberately bounded to exactly ONE run of lookahead:
        from_real_dispatch=True only for calls from _dispatch_motion_run
        (a REAL, plan_only=false run). The prefetch goal fired here is
        sent WITHOUT a feedback callback wired back into this method —
        a plan_only goal's own predicted_final_state does NOT itself
        trigger prefetching run+2. Earlier this chained unbounded
        (prefetch -> prefetch -> prefetch...), which planned the entire
        rest of a long recipe in one burst of concurrent IK/trajectory
        computation on the MultiThreadedExecutor — that CPU/thread
        contention was enough to make the JTC action client mishandle
        a real in-flight goal's response (~30s stall recovered only by
        _verify_reached_target_async's fallback). One run of lookahead
        is all that's needed to close the planning-latency gap (the
        real dispatch's own feedback re-arms the next prefetch as soon
        as it starts), so there's no reason to risk that again.

        Entirely best-effort otherwise: any failure here (server
        unavailable, pose resolution failure, goal rejected) just means
        the real dispatch later falls back to planning fresh, exactly
        like before this feature existed — never a correctness issue,
        only a missed optimization."""
        if not from_real_dispatch:
            return
        run_key = tuple(run)
        with self._lock:
            if run_key in self._prefetched:
                return
            next_run = self._next_run_of.get(run_key)
            if next_run is None:
                return
            self._prefetched.add(run_key)

        goal = self._build_motion_goal(list(next_run))
        if goal is None:
            return
        goal.plan_only = True
        goal.seed_state = predicted_final_state

        if not self._motion_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().warn(
                f'[DAG] prefetch for {next_run}: motion_planner unavailable, skipping')
            return

        self.get_logger().info(
            f'[DAG] prefetch-planning run {list(next_run)} ahead of run {run}\'s completion')

        def _on_prefetch_done(f):
            try:
                goal_handle = f.result()
                if not goal_handle.accepted:
                    self.get_logger().warn(f'[DAG] prefetch for {next_run}: goal rejected')
            except Exception as e:
                self.get_logger().warn(f'[DAG] prefetch for {next_run}: send failed: {e}')

        # No feedback_callback here, deliberately — see docstring above
        # on why this prefetch's own predicted_final_state must NOT
        # re-trigger _maybe_fire_prefetch. Lookahead re-arms itself
        # naturally: once THIS next_run is eventually dispatched for
        # real (cache hit or not), _dispatch_motion_run's feedback_cb
        # calls back into _maybe_fire_prefetch for the run after that.
        future = self._motion_client.send_goal_async(goal)
        future.add_done_callback(_on_prefetch_done)

    def _dispatch_motion_run(self, run: list):
        goal = self._build_motion_goal(run)
        if goal is None:
            return

        # Log the full goal for debugging accuracy issues
        self.get_logger().info(
            f'[DAG] motion run {run}: goal poses: '
            + ' | '.join(
                f'{sid}→({goal.leg_target_poses[i].position.x:.4f}, '
                f'{goal.leg_target_poses[i].position.y:.4f}, '
                f'{goal.leg_target_poses[i].position.z:.4f})'
                for i, sid in enumerate(run)
            )
        )

        # Blocking call — deliberately outside the lock (see __init__).
        if not self._motion_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(
                f'[DAG] run {run}: /execute_motion action server not available — is motion_planner running?')
            self._on_step_failed(run[0])
            return

        def feedback_cb(feedback_msg):
            fb = feedback_msg.feedback
            # self.get_logger().info(
            #     f'[DAG] run {run}: leg={fb.current_leg_step_id} '
            #     f'leg_percent_complete={fb.leg_percent_complete:.2f}')
            if fb.current_leg_step_id:
                self._on_progress(fb.current_leg_step_id, fb.leg_percent_complete)
            if fb.predicted_final_state.position:
                self._maybe_fire_prefetch(run, fb.predicted_final_state)

        # Watchdog/epoch keyed on the run's final member — that's the one
        # whose completion actually cascades (see _on_run_result).
        with self._lock:
            epoch = self._new_epoch(run[-1])
            self._arm_watchdog(run[-1], epoch, self.GOAL_ACCEPT_TIMEOUT_SEC)

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
        failed = False
        with self._lock:
            if isinstance(step, ToolStep) and step.from_vision_step:
                vision_result = self._results.get(step.from_vision_step)
                if vision_result is None:
                    self.get_logger().error(
                        f'[DAG] {step.step_id}: from_vision_step='
                        f'"{step.from_vision_step}" has no stored result — '
                        f'this should be unreachable given recipe_compiler\'s '
                        f'validation; treating as failed rather than guessing')
                    failed = True
                else:
                    pos = vision_result.detected_pose.position
                    goal.params = [pos.x, pos.y, pos.z]
            else:
                goal.params = step.params

        if failed:
            self._on_step_failed(step.step_id)
            return

        # Blocking call — deliberately outside the lock (see __init__).
        if not self._tool_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(
                f'[DAG] {step.step_id}: /execute_tool_op action server not available — is tool_action_server running?')
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
        # Plain service calls, not actions — object_spawner.py has no
        # goal-accepted/feedback phase, just request/response, so this
        # skips the two-phase pattern _dispatch_tool/_dispatch_vision use.
        with self._lock:
            epoch = self._new_epoch(step.step_id)
            self._arm_watchdog(step.step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        if step.operation == 'spawn':
            # Blocking call — deliberately outside the lock (see __init__).
            if not self._spawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error(
                    f'[DAG] {step.step_id}: /spawn_object service not '
                    f'available — is object_spawner running?')
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

        else:  # despawn
            if not self._despawn_client.wait_for_service(timeout_sec=2.0):
                self.get_logger().error(
                    f'[DAG] {step.step_id}: /despawn_object service not '
                    f'available — is object_spawner running?')
                with self._lock:
                    self._cancel_watchdog(step.step_id)
                self._on_step_failed(step.step_id)
                return

            # recipe_compiler guarantees (at compile time) that exactly
            # one of child_model/from_spawn_step is set, and that
            # from_spawn_step, if used, is a full completion dependency
            # of this step — so self._results is guaranteed populated
            # here. Defensive check kept anyway, same reasoning as the
            # from_vision_step check in _dispatch_tool.
            failed = False
            with self._lock:
                if step.from_spawn_step:
                    spawn_result = self._results.get(step.from_spawn_step)
                    if spawn_result is None:
                        self.get_logger().error(
                            f'[DAG] {step.step_id}: from_spawn_step='
                            f'"{step.from_spawn_step}" has no stored result — '
                            f'this should be unreachable given recipe_compiler\'s '
                            f'validation; treating as failed rather than guessing')
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

        future.add_done_callback(lambda f: self._on_spawn_result(step.step_id, f, epoch))

    def _dispatch_wait(self, step: WaitStep):
        def fire():
            timer.cancel()
            self.get_logger().info(f'[DAG] {step.step_id}: wait complete')
            self._on_step_completed(step.step_id)
        timer = self.create_timer(step.duration_sec, fire, callback_group=self._cb_group)

    def _on_goal_accepted(self, step_id: str, future, epoch: int):
        goal_handle = future.result()
        rejected = False
        with self._lock:
            if not self._is_current(step_id, epoch):
                self.get_logger().warn(
                    f'[DAG] {step_id}: ignoring stale goal-response (epoch {epoch} superseded)')
                return
            if not goal_handle.accepted:
                self.get_logger().error(f'[DAG] {step_id}: goal REJECTED by action server')
                self._cancel_watchdog(step_id)
                rejected = True
            else:
                self.get_logger().info(f'[DAG] {step_id}: goal accepted')
                self._goal_handles[step_id] = goal_handle
                # Goal accepted — re-arm the watchdog for the (potentially
                # longer) result-wait phase now that we know it's running.
                self._arm_watchdog(step_id, epoch, self.DEFAULT_GOAL_TIMEOUT_SEC)

        if rejected:
            self._on_step_failed(step_id)
            return
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self._on_step_result(step_id, f, epoch))

    def _on_run_goal_accepted(self, run: list, future, epoch: int):
        final_id = run[-1]
        goal_handle = future.result()
        rejected = False
        with self._lock:
            if not self._is_current(final_id, epoch):
                self.get_logger().warn(
                    f'[DAG] run {run}: ignoring stale goal-response (epoch {epoch} superseded)')
                return
            if not goal_handle.accepted:
                self.get_logger().error(f'[DAG] run {run}: goal REJECTED by action server')
                self._cancel_watchdog(final_id)
                rejected = True
            else:
                self.get_logger().info(f'[DAG] run {run}: goal accepted')
                for step_id in run:
                    self._goal_handles[step_id] = goal_handle
                self._arm_watchdog(final_id, epoch, self.MOTION_RESULT_TIMEOUT_SEC)

        if rejected:
            self._on_step_failed(run[0])
            return
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self._on_run_result(run, f, epoch))

    # ---- events -------------------------------------------------------

    def _on_progress(self, step_id: str, percent_complete: float):
        to_dispatch = []
        with self._lock:
            for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
                key = (dep_step_id, threshold)
                if percent_complete >= threshold and key not in self._progress_fired:
                    self.get_logger().info(
                        f'[DAG] progress({step_id})={percent_complete:.2f} >= {threshold} -> unblocking {dep_step_id}')
                    self._progress_fired.add(key)
                    self._in_degree[dep_step_id] -= 1
                    if self._in_degree[dep_step_id] == 0:
                        to_dispatch.append(dep_step_id)
        for dep_id in to_dispatch:
            self._dispatch(dep_id)

    def _on_step_result(self, step_id: str, future, epoch: int):
        result = future.result().result
        success = False
        with self._lock:
            if not self._is_current(step_id, epoch):
                self.get_logger().warn(
                    f'[DAG] {step_id}: ignoring stale result (epoch {epoch} superseded)')
                return
            self._cancel_watchdog(step_id)
            self.get_logger().info(
                f'[DAG] {step_id}: result success={result.success} error_code={result.error_code}')
            if result.success:
                self._results[step_id] = result
                success = True
        if success:
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_spawn_result(self, step_id: str, future, epoch: int):
        # Plain service response, not an action result — no nested .result.
        response = future.result()
        success = False
        with self._lock:
            if not self._is_current(step_id, epoch):
                self.get_logger().warn(
                    f'[DAG] {step_id}: ignoring stale spawn/despawn result (epoch {epoch} superseded)')
                return
            self._cancel_watchdog(step_id)
            self.get_logger().info(
                f'[DAG] {step_id}: spawn/despawn result success={response.success} '
                f'message={response.message}')
            if response.success:
                self._results[step_id] = response
                success = True
        if success:
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_run_result(self, run: list, future, epoch: int):
        final_id = run[-1]
        result = future.result().result
        to_dispatch = []
        final_success = False
        failed_id = None
        with self._lock:
            if not self._is_current(final_id, epoch):
                self.get_logger().warn(
                    f'[DAG] run {run}: ignoring stale result (epoch {epoch} superseded)')
                return
            self._cancel_watchdog(final_id)
            self.get_logger().info(
                f'[DAG] run {run}: result success={result.success} error_code={result.error_code}')
            if result.success:
                # Intermediate members' only "dependent" is the next run
                # member, already handled by being part of this same
                # merged goal — cascading their completion normally
                # would re-dispatch a step that's already done. Only
                # the LAST member can have real external dependents
                # (guaranteed by _detect_runs), so only it goes through
                # the full cascade (via _on_step_completed, below,
                # outside this lock).
                for step_id in run[:-1]:
                    to_dispatch.extend(self._mark_run_member_completed(step_id))
                final_success = True
            else:
                failed_id = result.failed_leg_step_id or run[-1]

        for step_id in to_dispatch:
            self._dispatch(step_id)
        if final_success:
            self._on_step_completed(run[-1])
        else:
            self._on_step_failed(failed_id)

    def _resolve_pending_progress(self, step_id: str) -> list[str]:
        """A step that just completed has, by definition, reached 100%
        progress — resolve any progress-watchers still pending for it,
        regardless of whether their threshold's feedback message ever
        actually arrived (short/fast moves may complete between feedback
        ticks). Without this, a progress dependency that never fires
        deadlocks its dependent forever even though the step it's
        watching is done. Caller must hold self._lock. Returns the
        step_ids newly unblocked, for the caller to dispatch AFTER
        releasing the lock — this must never dispatch directly itself,
        since dispatch can block (see __init__)."""
        ready = []
        for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
            key = (dep_step_id, threshold)
            if key not in self._progress_fired:
                self.get_logger().info(
                    f'[DAG] {step_id} completed before progress({threshold}) ever fired -> unblocking {dep_step_id} anyway')
                self._progress_fired.add(key)
                self._in_degree[dep_step_id] -= 1
                if self._in_degree[dep_step_id] == 0:
                    ready.append(dep_step_id)
        return ready

    def _mark_run_member_completed(self, step_id: str) -> list[str]:
        """Marks an intermediate (non-final) merged-run member complete
        WITHOUT cascading to its dependent — see _on_run_result for why
        that's safe. Progress-watcher fallback still applies exactly as
        for a normal completion. Caller must hold self._lock; returns
        step_ids to dispatch, same contract as _resolve_pending_progress."""
        self._completed.add(step_id)
        self.get_logger().info(
            f'[DAG] {step_id}: COMPLETED as part of merged run ({len(self._completed)}/{len(self._steps)})')
        return self._resolve_pending_progress(step_id)

    def _on_step_completed(self, step_id: str):
        to_dispatch = []
        with self._lock:
            self._completed.add(step_id)
            self.get_logger().info(f'[DAG] {step_id}: COMPLETED ({len(self._completed)}/{len(self._steps)})')
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
        action = None  # 'retry' | 'complete' | 'hold' | 'abort'
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

        # Every branch below can eventually block (dispatch's
        # wait_for_server/wait_for_service, abort_all's
        # cancel_goal_async fan-out) — kept outside the lock, same rule
        # as everywhere else in this file.
        if action == 'retry':
            self._dispatch(step_id)
        elif action == 'complete':
            self._on_step_completed(step_id)
        elif action == 'abort':
            self._abort_all(last_error=f'{step_id} aborted')
        # 'hold' needs no further action here — _resume_cb drives it later.

    def _abort_all(self, last_error: str = ''):
        with self._lock:
            self.state = CellState.ERROR
            # Snapshot-then-release, not iterate-while-locked: a
            # dispatch on another thread can be writing a NEW entry into
            # _goal_handles at the same moment (e.g. _on_goal_accepted)
            # right as e-stop trips. Iterating .values() directly while
            # that write happens is a `dictionary changed size during
            # iteration` RuntimeError — in the e-stop path, of all
            # places. list(...) here takes a safe copy under the lock.
            handles = list(self._goal_handles.values())
            self._publish_cell_state(last_error=last_error)
        for handle in handles:
            handle.cancel_goal_async()

    def _safety_cb(self, msg: Bool):
        if not msg.data:
            # NOTE (pre-existing, not part of this fix): _abort_all sets
            # state to ERROR immediately after, so this ESTOP assignment
            # is observable only for the instant between the two calls —
            # worth a follow-up if ESTOP vs ERROR needs to be visibly
            # distinct downstream.
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

        # Outside the lock — both branches can eventually block
        # (dispatch's wait_for_server, abort_all's cancel_goal_async).
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
    # Explicit thread count, not the MultiThreadedExecutor() default
    # (os.cpu_count(), which silently varies across dev machines / CI
    # runners / the real cell controller and was never actually chosen
    # for this workload). Needs to be >=2 so a blocking wait_for_server/
    # wait_for_service on one thread can never starve the safety
    # subscription callback on another. 8 matches the value already
    # settled on for object_spawner.py this session — keep them in sync
    # if that gets tuned later.
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