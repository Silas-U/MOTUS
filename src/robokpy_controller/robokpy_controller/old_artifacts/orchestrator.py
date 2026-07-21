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
from robokpy_interfaces.srv import ResumeExecution, LoadRecipe

from .recipe_compiler import RecipeCompiler, RecipeValidationError


from .steps import (
    RecoveryPolicy, Step, MoveStep, ToolStep, IOStep, WaitStep, VisionStep,
)


class CellState(enum.Enum):
    IDLE = 'idle'
    PLANNING = 'planning'
    EXECUTING = 'executing'
    PAUSED = 'paused'
    ERROR = 'error'
    ESTOP = 'estop'


class Orchestrator(Node):
    def __init__(self):
        super().__init__('orchestrator')
        self._cb_group = ReentrantCallbackGroup()

        self._motion_client = ActionClient(
            self, ExecuteMotion, 'execute_motion', callback_group=self._cb_group)
        self._tool_client = ActionClient(
            self, ExecuteToolOp, 'execute_tool_op', callback_group=self._cb_group)
        self._vision_client = ActionClient(
            self, ExecuteVisionOp, 'execute_vision_op', callback_group=self._cb_group)

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

        self.state = CellState.PLANNING
        self._publish_cell_state()

    def start(self):
        self.state = CellState.EXECUTING
        self._publish_cell_state()
        for step_id, degree in self._in_degree.items():
            if degree == 0:
                self._dispatch(step_id)

    # ---- dispatch ---------------------------------------------------------

    def _dispatch(self, step_id: str):
        step = self._steps[step_id]
        self.get_logger().info(f'[DAG] dispatching {step_id} ({type(step).__name__})')
        if isinstance(step, MoveStep):
            self._dispatch_motion(step)
        elif isinstance(step, (ToolStep, IOStep)):
            self._dispatch_tool(step)
        elif isinstance(step, VisionStep):
            self._dispatch_vision(step)
        elif isinstance(step, WaitStep):
            self._dispatch_wait(step)

    def _dispatch_motion(self, step: MoveStep):
        goal = ExecuteMotion.Goal()
        goal.step_id = step.step_id
        goal.traj_method = step.traj_method
        goal.traj_type = step.traj_type
        goal.blend_radius = step.blend_radius
        goal.speed_scale = step.speed_scale
        goal.target_type = ExecuteMotion.Goal.POSE_TARGET
        goal.target_pose = step.target_pose

        if not self._motion_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(
                f'[DAG] {step.step_id}: /execute_motion action server not available — is motion_planner running?')
            self._on_step_failed(step.step_id)
            return

        def feedback_cb(feedback_msg):
            self.get_logger().info(
                f'[DAG] {step.step_id}: motion feedback percent_complete={feedback_msg.feedback.percent_complete:.2f}')
            self._on_progress(step.step_id, feedback_msg.feedback.percent_complete)

        future = self._motion_client.send_goal_async(goal, feedback_callback=feedback_cb)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f))

    def _dispatch_tool(self, step):
        goal = ExecuteToolOp.Goal()
        goal.tool_id = step.tool_id if isinstance(step, ToolStep) else step.io_id
        goal.command = step.command
        goal.params = step.params

        if not self._tool_client.wait_for_server(timeout_sec=2.0):
            self.get_logger().error(
                f'[DAG] {step.step_id}: /execute_tool_op action server not available — is tool_action_server running?')
            self._on_step_failed(step.step_id)
            return

        future = self._tool_client.send_goal_async(goal)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f))

    def _dispatch_vision(self, step: VisionStep):
        goal = ExecuteVisionOp.Goal()
        goal.vision_id = step.vision_id
        goal.operation = step.operation
        goal.params = step.params
        future = self._vision_client.send_goal_async(goal)
        future.add_done_callback(lambda f: self._on_goal_accepted(step.step_id, f))

    def _dispatch_wait(self, step: WaitStep):
        def fire():
            timer.cancel()
            self.get_logger().info(f'[DAG] {step.step_id}: wait complete')
            self._on_step_completed(step.step_id)
        timer = self.create_timer(step.duration_sec, fire, callback_group=self._cb_group)

    def _on_goal_accepted(self, step_id: str, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error(f'[DAG] {step_id}: goal REJECTED by action server')
            self._on_step_failed(step_id)
            return
        self.get_logger().info(f'[DAG] {step_id}: goal accepted')
        self._goal_handles[step_id] = goal_handle
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(lambda f: self._on_step_result(step_id, f))

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

    def _on_step_result(self, step_id: str, future):
        result = future.result().result
        self.get_logger().info(
            f'[DAG] {step_id}: result success={result.success} error_code={result.error_code}')
        if result.success:
            self._results[step_id] = result
            self._on_step_completed(step_id)
        else:
            self._on_step_failed(step_id)

    def _on_step_completed(self, step_id: str):
        self._completed.add(step_id)
        self.get_logger().info(f'[DAG] {step_id}: COMPLETED ({len(self._completed)}/{len(self._steps)})')

        # A completed step has, by definition, reached 100% progress —
        # resolve any progress-watchers still pending for it, regardless
        # of whether their threshold's feedback message ever actually
        # arrived (short/fast moves may complete between feedback ticks,
        # or a controller may not publish feedback frequently enough).
        # Without this, a progress dependency that never fires deadlocks
        # its dependent forever even though the step it's watching is done.
        for dep_step_id, threshold in self._progress_watchers.get(step_id, []):
            key = (dep_step_id, threshold)   # must match the key format _on_progress uses —
                                              # was (step_id, threshold) before, a mismatch that
                                              # would double-decrement if progress fires first
            if key not in self._progress_fired:
                self.get_logger().info(
                    f'[DAG] {step_id} completed before progress({threshold}) ever fired -> unblocking {dep_step_id} anyway')
                self._progress_fired.add(key)
                self._in_degree[dep_step_id] -= 1
                if self._in_degree[dep_step_id] == 0:
                    self._dispatch(dep_step_id)

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