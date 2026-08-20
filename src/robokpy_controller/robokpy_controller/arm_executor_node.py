"""
arm_executor_node.py

One instance per arm, launched namespaced (e.g. /arm1).

Owns the complete:
    plan -> execute -> confirm
pipeline for one arm and exposes it as a single action:
    execute_move_step

The cell orchestrator never sees:
    - trajectories
    - JTC goals
    - IK calls

It only receives success/failure from this node.

Look-ahead pipeline
-------------------
Leg 0 must be planned before motion starts.

Every subsequent leg is planned on a single background worker while the
previous leg is executing on the JTC.

IMPORTANT:
    The next leg is seeded from the previous leg's predicted_q.

It is deliberately NOT seeded from live /current_joint_state because live
feedback introduces a race between the executing JTC trajectory and the
planner.

Architecture:
    - a whole run's legs are planned in ONE plan_trajectory call and
      dispatched as ONE JTC goal (see _execute_move_step_cb's
      docstring for why — real velocity continuity across leg
      boundaries is only achievable WITHIN one goal's trajectory
      message; ros2_control's JTC has no "coast into the next goal"
      across separately dispatched goals, and this matches how
      MoveIt's own TrajectoryExecutionManager pushes a whole
      RobotTrajectory as one execution unit rather than chunking it)
    - one planning worker, used for that single whole-run plan
    - no queue, no epoch bookkeeping, no asyncio event loop

Current trajectory contract:
    - within a run, real interior blending (blend_radius / n_blend)
      for consecutive same-(traj_method, traj_type) legs; a hard stop
      only at genuine method/type changes (plan_trajectory's own
      internal grouping)
    - rest-to-rest at the very start and end of the whole run
    - boundary velocity/acceleration threading between SEPARATE JTC
      goals (planner_core.estimate_exit_boundary, qd_seed/
      qd_exit_hint, PlannedTrajectory.exit_qd/exit_qdd) exists in
      planner_core.py but is NOT used on this path — there is no
      cross-goal seam left to bridge once a whole run is one goal.
      Kept as a building block for a possible future genuine
      receding-horizon/streaming-replan design, not currently reachable.
"""

import time
import traceback
from concurrent.futures import ThreadPoolExecutor, Future
from typing import List, Optional

import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor

from std_msgs.msg import Float64MultiArray
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from builtin_interfaces.msg import Duration
from control_msgs.action import FollowJointTrajectory

from robokpy_interfaces.action import ExecuteMoveStep

from .planner_core import (
    plan_trajectory,
    estimate_exit_boundary,
    TrajectoryLeg,
    PlanningError,
    PlannedTrajectory,
)
from .mp_kinematics import KinematicsFacade
from .mp_types import TrajectoryConfig
from .execution_monitor import ExecutionMonitor

# TEMP PROFILING — remove instrument()/report()/reset_stats() calls
# below once done.
from .profile_planner import instrument, report, reset_stats


class ArmExecutorNode(Node):

    # ------------------------------------------------------------------
    # Timing / execution constants
    # ------------------------------------------------------------------

    DEFAULT_GOAL_TIMEOUT_SEC = 30.0

    JTC_SERVER_TIMEOUT_SEC = 2.0
    JTC_GOAL_SEND_TIMEOUT_SEC = 5.0
    JTC_RESULT_TIMEOUT_SEC = 75.0
    JTC_CANCEL_TIMEOUT_SEC = 1.0

    FUTURE_POLL_SEC = 0.005
    EXECUTION_CHECK_SEC = 0.05

    TARGET_TOLERANCE = 0.05
    STABLE_WINDOW_SEC = 0.5
    DIVERGENCE_TOLERANCE = 0.15

    # is_at_target() is a pure position check with no notion of
    # elapsed path — it can't tell "arrived early" from "never left,
    # because the run's final target happens to equal (or nearly
    # equal) its own starting pose" (a completely normal
    # home->...->home recipe shape). Only trust it once elapsed time
    # is within this margin of the trajectory's OWN planned duration,
    # so it can never fire before the arm could plausibly have moved.
    EARLY_CANCEL_MARGIN_SEC = 1.0

    # ------------------------------------------------------------------
    # Constructor
    # ------------------------------------------------------------------

    def __init__(self):
        super().__init__('arm_executor')

        # ==============================================================
        # Parameters
        # ==============================================================

        self.declare_parameter('robot_description', '')
        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link', 'tcp')
        self.declare_parameter('kinematic_solver_backend', 'robokpy')

        self.declare_parameter('mask', [0] * 6)

        self.declare_parameter(
            'vel_limits',
            [1.5, 1.5, 2.0, 2.0, 2.5, 2.5],
        )

        self.declare_parameter(
            'acc_limits',
            [5.0, 5.0, 8.0, 8.0, 10.0, 10.0],
        )

        self.declare_parameter(
            'jerk_limits',
            [50.0, 50.0, 80.0, 80.0, 100.0, 100.0],
        )

        self.declare_parameter(
            'pos_limits_lo',
            [-3.14] * 6,
        )

        self.declare_parameter(
            'pos_limits_hi',
            [3.14] * 6,
        )

        self.declare_parameter(
            'cartesian_vel_limit',
            0.25,
        )

        self.declare_parameter(
            'default_traj_method',
            'js',
        )

        self.declare_parameter(
            'default_traj_type',
            'lspb',
        )

        self.declare_parameter(
            'default_speed_factor',
            1.0,
        )

        self.declare_parameter(
            'default_blend_radius',
            0.0,
        )

        self.declare_parameter(
            'default_duration_per_segment',
            3.0,
        )

        self.declare_parameter(
            'default_dt',
            0.04,
        )

        self.declare_parameter(
            'default_n_samples',
            10,
        )

        self.declare_parameter(
            'default_n_blend',
            20,
        )

        self.declare_parameter(
            'jtc_action_name',
            'arm_controller/follow_joint_trajectory',
        )

        # ==============================================================
        # Robot description
        # ==============================================================

        robot_description = self.get_parameter(
            'robot_description'
        ).value

        if not robot_description or not robot_description.strip():
            raise RuntimeError(
                'robot_description is empty — arm_executor must be '
                'launched with a URDF string.'
            )

        # ==============================================================
        # Kinematics
        # ==============================================================

        backend = self.get_parameter(
            'kinematic_solver_backend'
        ).value

        self._kin = KinematicsFacade(
            robot_description=robot_description,
            base_link=self.get_parameter(
                'planning_base_link'
            ).value,
            tip_link=self.get_parameter(
                'planning_tip_link'
            ).value,
            backend=backend,
            mask=list(
                self.get_parameter('mask').value
            ),
            logger=self.get_logger(),
        )

        # TEMP PROFILING — instruments self._kin's IK/FK/traj_planner
        # calls with timers; report() below prints the breakdown after
        # each plan. Remove both this call and the report() call (and
        # the import above) once you're done profiling.
        instrument(self._kin)

        # ==============================================================
        # Trajectory configuration
        # ==============================================================

        self._config = TrajectoryConfig.from_node_params(self)

        # ==============================================================
        # Live joint state
        #
        # Used ONLY to initialize the first leg.
        #
        # Subsequent legs use planned.predicted_q.
        # ==============================================================

        self._q_current: Optional[np.ndarray] = None

        # ==============================================================
        # Look-ahead planner
        #
        # Exactly one worker and one prefetched trajectory.
        # ==============================================================

        self._plan_pool = ThreadPoolExecutor(
            max_workers=1,
            thread_name_prefix='arm_plan',
        )

        self._next_plan: Optional[Future] = None
        self._next_plan_step_id: Optional[str] = None

        # ==============================================================
        # Execution monitor
        # ==============================================================

        self._exec_mon = ExecutionMonitor(
            target_tolerance=self.TARGET_TOLERANCE,
            stable_window_sec=self.STABLE_WINDOW_SEC,
            divergence_tolerance=self.DIVERGENCE_TOLERANCE,
            logger=self.get_logger(),
        )

        # ==============================================================
        # ROS callback group
        # ==============================================================

        self._cb_group = ReentrantCallbackGroup()

        # ==============================================================
        # Joint state subscription
        # ==============================================================

        self.create_subscription(
            Float64MultiArray,
            'current_joint_state',
            self._joint_cb,
            10,
            callback_group=self._cb_group,
        )

        # ==============================================================
        # JTC action client
        # ==============================================================

        jtc_action_name = self.get_parameter(
            'jtc_action_name'
        ).value

        self._jtc_client = ActionClient(
            self,
            FollowJointTrajectory,
            jtc_action_name,
            callback_group=self._cb_group,
        )

        # ==============================================================
        # ExecuteMoveStep action server
        # ==============================================================

        self._move_server = ActionServer(
            self,
            ExecuteMoveStep,
            'execute_move_step',
            execute_callback=self._execute_move_step_cb,
            callback_group=self._cb_group,
        )

        self.get_logger().info(
            'ArmExecutor ready '
            f'(JTC: {self.resolve_topic_name(jtc_action_name)})'
        )

    # ==================================================================
    # Joint state callback
    # ==================================================================

    def _joint_cb(self, msg: Float64MultiArray):
        """
        Update live joint feedback.

        IMPORTANT:
            This state is used only to seed the first leg of a new
            ExecuteMoveStep goal.

            It must NOT be used to seed prefetched legs.
        """

        try:
            q = np.asarray(msg.data, dtype=float)

            self._q_current = q

            now = (
                self.get_clock().now().nanoseconds * 1e-9
            )

            self._exec_mon.update(q, now)

        except Exception as exc:
            self.get_logger().warn(
                f'[arm_executor] joint-state callback error: {exc}'
            )

    # ==================================================================
    # Goal parsing
    # ==================================================================

    def _legs_from_goal(self, request) -> List[TrajectoryLeg]:

        legs: List[TrajectoryLeg] = []

        count = len(request.leg_step_ids)

        for i in range(count):

            p = request.leg_target_poses[i]

            pose_arr = np.array(
                [
                    p.position.x,
                    p.position.y,
                    p.position.z,
                    p.orientation.x,
                    p.orientation.y,
                    p.orientation.z,
                    p.orientation.w,
                ],
                dtype=float,
            )

            legs.append(
                TrajectoryLeg(
                    step_id=request.leg_step_ids[i],
                    target_pose=pose_arr,

                    traj_method=(
                        request.leg_traj_methods[i]
                        if i < len(request.leg_traj_methods)
                        else 'ts'
                    ),

                    traj_type=(
                        request.leg_traj_types[i]
                        if i < len(request.leg_traj_types)
                        else 'blend'
                    ),

                    blend_radius=(
                        request.leg_blend_radii[i]
                        if i < len(request.leg_blend_radii)
                        else 0.0
                    ),
                )
            )

        return legs

    # ==================================================================
    # Configuration
    # ==================================================================

    def _resolve_config(
        self,
        request,
    ) -> TrajectoryConfig:

        if request.speed_scale <= 0.0:
            return self._config

        c = self._config

        return TrajectoryConfig(
            traj_method=c.traj_method,
            traj_type=c.traj_type,
            blend_radius=c.blend_radius,
            n_blend=c.n_blend,
            duration_per_segment=c.duration_per_segment,
            dt=c.dt,
            speed_factor=request.speed_scale,
            n_samples=c.n_samples,
            vel_limits=c.vel_limits,
            acc_limits=c.acc_limits,
            jerk_limits=c.jerk_limits,
            pos_limits=c.pos_limits,
            cartesian_vel_limit=c.cartesian_vel_limit,
        )

    # ==================================================================
    # Planning
    # ==================================================================

    def _plan_leg_sync(
        self,
        leg: TrajectoryLeg,
        q_seed: np.ndarray,
        config: TrajectoryConfig,
        qd_seed: Optional[np.ndarray] = None,
        qdd_seed: Optional[np.ndarray] = None,
        qd_exit_hint: Optional[np.ndarray] = None,
        qdd_exit_hint: Optional[np.ndarray] = None,
    ) -> PlannedTrajectory:

        return plan_trajectory(
            [leg],
            q_seed,
            config,
            self._kin,
            qd_seed=qd_seed,
            qdd_seed=qdd_seed,
            qd_exit_hint=qd_exit_hint,
            qdd_exit_hint=qdd_exit_hint,
        )

    # ------------------------------------------------------------------
    def _submit_next_plan(
        self,
        leg: TrajectoryLeg,
        q_seed: np.ndarray,
        config: TrajectoryConfig,
        qd_seed: Optional[np.ndarray] = None,
        qdd_seed: Optional[np.ndarray] = None,
        qd_exit_hint: Optional[np.ndarray] = None,
        qdd_exit_hint: Optional[np.ndarray] = None,
    ) -> Future:
        """
        Submit exactly one look-ahead planning task.

        q_seed MUST be the previous planned trajectory's predicted_q.
        qd_seed/qdd_seed (if given) MUST be that same previous plan's
        ACHIEVED exit_qd/exit_qdd — not just a hint — so this leg's
        entry boundary matches what the arm will actually be doing
        when it crosses into this trajectory.
        """

        if self._next_plan is not None:
            self.get_logger().warn(
                '[arm_executor] replacing existing prefetched plan '
                f"'{self._next_plan_step_id}'"
            )

        self._next_plan_step_id = leg.step_id

        submit_time = time.monotonic()

        future = self._plan_pool.submit(
            self._plan_leg_sync,
            leg,
            np.asarray(q_seed, dtype=float).copy(),
            config,
            qd_seed=qd_seed,
            qdd_seed=qdd_seed,
            qd_exit_hint=qd_exit_hint,
            qdd_exit_hint=qdd_exit_hint,
        )

        self._next_plan = future

        # Attach timing metadata without changing the Future type.
        future._arm_submit_time = submit_time
        future._arm_step_id = leg.step_id

        self.get_logger().debug(
            f"[arm_executor] prefetch submitted "
            f"'{leg.step_id}'"
        )

        return future

    # ------------------------------------------------------------------
    def _consume_prefetched_plan(
        self,
        future: Future,
        expected_step_id: str,
    ) -> PlannedTrajectory:
        """
        Wait for a prefetched plan.

        This function deliberately does not use asyncio.
        """

        submit_time = getattr(
            future,
            '_arm_submit_time',
            None,
        )

        while not future.done():

            # Keep ROS callbacks responsive because this callback is
            # executing inside a MultiThreadedExecutor.
            time.sleep(self.FUTURE_POLL_SEC)

        elapsed = (
            time.monotonic() - submit_time
            if submit_time is not None
            else 0.0
        )

        try:
            planned = future.result()

        except PlanningError:
            raise

        except Exception as exc:
            self.get_logger().error(
                f"[arm_executor] prefetched plan "
                f"'{expected_step_id}' raised an exception: {exc}"
            )
            raise

        self.get_logger().debug(
            f"[arm_executor] prefetch ready "
            f"'{expected_step_id}' ({elapsed:.3f}s)"
        )

        return planned

    # ==================================================================
    # JTC message conversion
    # ==================================================================

    def _to_jtc_trajectory(
        self,
        planned: PlannedTrajectory,
    ) -> JointTrajectory:

        msg = JointTrajectory()

        msg.joint_names = self._kin.joint_names

        dt_default = self._config.dt

        for i, pt in enumerate(planned.points):

            jtp = JointTrajectoryPoint()

            if hasattr(pt, 'q') and hasattr(pt, 't'):

                jtp.positions = np.asarray(
                    pt.q,
                    dtype=float,
                ).tolist()

                if getattr(pt, 'qd', None) is not None:
                    jtp.velocities = np.asarray(
                        pt.qd,
                        dtype=float,
                    ).tolist()
                else:
                    jtp.velocities = []

                if getattr(pt, 'qdd', None) is not None:
                    jtp.accelerations = np.asarray(
                        pt.qdd,
                        dtype=float,
                    ).tolist()
                else:
                    jtp.accelerations = []

                t_sec = float(pt.t)

            else:

                jtp.positions = np.asarray(
                    pt,
                    dtype=float,
                ).tolist()

                jtp.velocities = []
                jtp.accelerations = []

                t_sec = i * dt_default

            sec = int(t_sec)

            nanosec = int(
                round((t_sec - sec) * 1e9)
            )

            # Protect against floating point rounding producing
            # 1e9 nanoseconds.
            if nanosec >= 1_000_000_000:
                sec += 1
                nanosec -= 1_000_000_000

            jtp.time_from_start = Duration(
                sec=sec,
                nanosec=nanosec,
            )

            msg.points.append(jtp)

        return msg

    # ==================================================================
    # JTC helpers
    # ==================================================================

    def _wait_for_future(
        self,
        future,
        timeout_sec: float,
        description: str,
    ):
        """
        Wait for an rclpy Future without asyncio.

        The ROS MultiThreadedExecutor continues servicing callbacks
        because this thread only sleeps between checks.
        """

        deadline = time.monotonic() + timeout_sec

        while not future.done():

            if time.monotonic() >= deadline:

                self.get_logger().error(
                    f'[arm_executor] timeout waiting for {description} '
                    f'after {timeout_sec:.1f}s'
                )

                return None

            time.sleep(self.FUTURE_POLL_SEC)

        try:
            return future.result()

        except Exception as exc:

            self.get_logger().error(
                f'[arm_executor] exception waiting for '
                f'{description}: {exc}'
            )

            return None

    # ==================================================================
    # Execute one planned trajectory on JTC
    # ==================================================================

    def _run_on_jtc(
        self,
        planned: PlannedTrajectory,
        goal_handle=None,
    ) -> bool:

        # --------------------------------------------------------------
        # Per-leg feedback bookkeeping.
        #
        # This JTC goal now spans the WHOLE (possibly multi-leg)
        # planned trajectory, not a single leg — see
        # _execute_move_step_cb's docstring note. Individual legs
        # finish midway through ONE continuous goal, with no per-leg
        # action event of their own, so report each leg's completion
        # as elapsed execution time crosses its cumulative end time in
        # planned.leg_time_ranges — downstream DAG dependencies
        # (steps.py's ('progress', step_id, threshold)) rely on this
        # arriving per-leg, in real time, not batched at the very end.
        # --------------------------------------------------------------

        leg_ranges = planned.leg_time_ranges
        reported = 0

        def _publish_leg_feedback(step_id):
            if goal_handle is not None:
                goal_handle.publish_feedback(
                    ExecuteMoveStep.Feedback(
                        current_step_id=step_id,
                        percent_complete=1.0,
                    )
                )
            self.get_logger().info(
                f"[arm_executor] completed leg '{step_id}'"
            )

        def _flush_remaining_leg_feedback():
            nonlocal reported
            while reported < len(leg_ranges):
                _publish_leg_feedback(leg_ranges[reported][0])
                reported += 1

        # --------------------------------------------------------------
        # Wait for JTC
        # --------------------------------------------------------------

        if not self._jtc_client.wait_for_server(
            timeout_sec=self.JTC_SERVER_TIMEOUT_SEC
        ):

            self.get_logger().error(
                '[arm_executor] JTC unavailable'
            )

            return False

        # --------------------------------------------------------------
        # Reset execution monitor using predicted target
        # --------------------------------------------------------------

        self._exec_mon.reset(
            planned.predicted_q
        )

        # --------------------------------------------------------------
        # Build JTC goal
        # --------------------------------------------------------------

        goal = FollowJointTrajectory.Goal()

        goal.trajectory = self._to_jtc_trajectory(
            planned
        )

        # --------------------------------------------------------------
        # Send goal
        # --------------------------------------------------------------

        send_start = time.monotonic()

        try:

            send_future = self._jtc_client.send_goal_async(
                goal
            )

        except Exception as exc:

            self.get_logger().error(
                f'[arm_executor] JTC send_goal_async failed: {exc}'
            )

            return False

        jtc_handle = self._wait_for_future(
            send_future,
            self.JTC_GOAL_SEND_TIMEOUT_SEC,
            'JTC goal response',
        )

        if jtc_handle is None:

            self.get_logger().error(
                '[arm_executor] JTC goal send failed'
            )

            return False

        send_elapsed = (
            time.monotonic() - send_start
        )

        if not jtc_handle.accepted:

            self.get_logger().error(
                '[arm_executor] JTC goal rejected'
            )

            return False

        self.get_logger().debug(
            f'[arm_executor] JTC goal accepted '
            f'({send_elapsed:.3f}s)'
        )

        # --------------------------------------------------------------
        # Get JTC result future
        # --------------------------------------------------------------

        try:

            result_future = (
                jtc_handle.get_result_async()
            )

        except Exception as exc:

            self.get_logger().error(
                f'[arm_executor] failed to request JTC result: {exc}'
            )

            return False

        # --------------------------------------------------------------
        # Monitor execution
        # --------------------------------------------------------------

        start_time = time.monotonic()

        while True:

            elapsed = (
                time.monotonic() - start_time
            )

            # ----------------------------------------------------------
            # Per-leg progress feedback — fires as elapsed execution
            # time crosses each leg's cumulative end time within this
            # (possibly multi-leg) trajectory.
            # ----------------------------------------------------------

            while (
                reported < len(leg_ranges)
                and elapsed >= leg_ranges[reported][2]
            ):
                _publish_leg_feedback(leg_ranges[reported][0])
                reported += 1

            # ----------------------------------------------------------
            # JTC result arrived
            # ----------------------------------------------------------

            if result_future.done():

                try:

                    result_wrapper = result_future.result()
                    result = result_wrapper.result

                    error_code = getattr(
                        result,
                        'error_code',
                        0,
                    )

                    if error_code == 0:

                        _flush_remaining_leg_feedback()

                        return True

                    self.get_logger().error(
                        '[arm_executor] JTC reported failure '
                        f'error_code={error_code}'
                    )

                    return False

                except Exception as exc:

                    self.get_logger().error(
                        f'[arm_executor] JTC result exception: {exc}'
                    )

                    return False

            # ----------------------------------------------------------
            # Ground-truth target confirmation
            #
            # Gated on elapsed >= planned.total_duration -
            # EARLY_CANCEL_MARGIN_SEC — is_at_target() has no notion of
            # elapsed path, only current-position-vs-target, so an
            # ungated check can false-positive instantly whenever the
            # run's final target happens to equal (or nearly equal)
            # its own starting pose, e.g. any home->...->home recipe.
            # ----------------------------------------------------------

            near_planned_end = (
                elapsed >= planned.total_duration - self.EARLY_CANCEL_MARGIN_SEC
            )

            if near_planned_end and self._exec_mon.is_at_target():

                self.get_logger().info(
                    '[arm_executor] arm reached target via encoder; '
                    'cancelling remaining JTC trajectory'
                )

                try:

                    cancel_future = (
                        jtc_handle.cancel_goal_async()
                    )

                    cancel_result = self._wait_for_future(
                        cancel_future,
                        self.JTC_CANCEL_TIMEOUT_SEC,
                        'JTC goal cancellation',
                    )

                    if cancel_result is None:

                        self.get_logger().warn(
                            '[arm_executor] JTC cancellation '
                            'did not complete within timeout'
                        )

                except Exception as exc:

                    self.get_logger().warn(
                        f'[arm_executor] JTC cancel failed: {exc}'
                    )

                _flush_remaining_leg_feedback()

                return True

            # ----------------------------------------------------------
            # Overall execution timeout
            # ----------------------------------------------------------

            if elapsed >= self.JTC_RESULT_TIMEOUT_SEC:

                self.get_logger().error(
                    '[arm_executor] motion result timeout; '
                    'arm did not reach target'
                )

                try:

                    cancel_future = (
                        jtc_handle.cancel_goal_async()
                    )

                    self._wait_for_future(
                        cancel_future,
                        self.JTC_CANCEL_TIMEOUT_SEC,
                        'JTC timeout cancellation',
                    )

                except Exception as exc:

                    self.get_logger().warn(
                        f'[arm_executor] timeout cancellation failed: {exc}'
                    )

                return False

            time.sleep(
                self.EXECUTION_CHECK_SEC
            )

    # ==================================================================
    # Clear look-ahead state
    # ==================================================================

    def _clear_prefetch(self):
        """
        Clear the one-slot look-ahead state.

        We do not forcibly cancel a running planner thread because the
        ThreadPoolExecutor worker may already be executing.

        The important thing is that the completed result can no longer
        accidentally be consumed by a later ExecuteMoveStep goal.
        """

        self._next_plan = None
        self._next_plan_step_id = None

    # ==================================================================
    # Action handler
    # ==================================================================

    def _execute_move_step_cb(
        self,
        goal_handle,
    ):
        """
        Plan the ENTIRE run in one call, dispatch it as ONE JTC goal.

        plan_trajectory groups consecutive legs by (traj_method,
        traj_type) internally and produces ONE continuous multi-
        waypoint trajectory — real interior blending (blend_radius /
        n_blend) within each same-method stretch, a hard stop only at
        genuine method changes. This matches how MoveIt's own
        TrajectoryExecutionManager handles a single planned
        RobotTrajectory: pushed to the controller as one execution
        unit (split only by controller/joint-group, never chunked
        into a sequence of goals for one controller), and when
        multiple trajectories genuinely ARE pushed separately, they
        execute strictly in sequence with no attempt at cross-goal
        blending. ros2_control's JointTrajectoryController has no
        "coast into the next goal" — once a trajectory ends and no new
        one has been accepted, it holds the setpoint at zero velocity
        — so real continuity is only achievable WITHIN one goal's
        trajectory message, never across separately dispatched ones.

        Boundary velocity/acceleration threading between separate
        goals (planner_core.estimate_exit_boundary, qd_seed/
        qd_exit_hint) is NOT used on this path — with the whole run in
        one goal there is no cross-goal seam left to bridge. That
        machinery stays in planner_core.py, dormant, as a building
        block for a possible future genuine receding-horizon /
        streaming-replan design — NOT reachable from here. Likewise
        _plan_leg_sync/_submit_next_plan (the old per-leg prefetch
        pair) are unused by this callback now; kept for the same
        reason, not because anything here still calls them.
        """

        result = ExecuteMoveStep.Result()

        self.get_logger().info(
            '[arm_executor] ExecuteMoveStep started'
        )

        try:

            # ==========================================================
            # Parse legs
            # ==========================================================

            legs = self._legs_from_goal(
                goal_handle.request
            )

            if not legs:

                self.get_logger().error(
                    '[arm_executor] ExecuteMoveStep contains no legs'
                )

                goal_handle.abort()

                result.success = False
                result.error_code = 1

                return result

            self.get_logger().info(
                '[arm_executor] executing '
                f'{len(legs)} leg(s): '
                f'{[leg.step_id for leg in legs]}'
            )

            # ==========================================================
            # Resolve trajectory configuration
            # ==========================================================

            config = self._resolve_config(
                goal_handle.request
            )

            # ==========================================================
            # We need live state to seed planning
            # ==========================================================

            if self._q_current is None:

                topic = self.resolve_topic_name(
                    'current_joint_state'
                )

                self.get_logger().error(
                    '[arm_executor] no joint state received yet on '
                    f"'{topic}' — aborting goal"
                )

                goal_handle.abort()

                result.success = False
                result.error_code = 1

                return result

            q_seed = self._kin.normalize_joints(
                self._q_current.copy(),
                self._kin.get_active_joints(),
            )

            # ==========================================================
            # Ensure stale prefetch state cannot leak between action
            # goals (the fields themselves are unused by this
            # callback's own logic now, but destroy_node/other paths
            # may still check them).
            # ==========================================================

            self._clear_prefetch()

            # ==========================================================
            # Plan the WHOLE run in ONE call, off the DDS event-loop
            # thread.
            # ==========================================================

            plan_start = time.monotonic()

            # TEMP PROFILING — isolate this plan's stats from any prior
            # one. Remove once done.
            reset_stats()

            try:

                future = self._plan_pool.submit(
                    plan_trajectory,
                    legs,
                    q_seed.copy(),
                    config,
                    self._kin,
                )

                planned = self._consume_prefetched_plan(
                    future,
                    legs[0].step_id,
                )

            except PlanningError as exc:

                self.get_logger().error(
                    f"[arm_executor] planning failed for "
                    f"'{exc.step_id}': {exc}"
                )

                goal_handle.abort()

                result.success = False
                result.error_code = exc.error_code

                return result

            except Exception as exc:

                self.get_logger().error(
                    f"[arm_executor] planning exception: {exc}"
                )

                goal_handle.abort()

                result.success = False
                result.error_code = 3

                return result

            plan_elapsed = (
                time.monotonic() - plan_start
            )

            self.get_logger().info(
                f"[arm_executor] plan ready for {len(legs)} leg(s) "
                f"({plan_elapsed:.3f}s)"
            )

            # TEMP PROFILING — prints the per-call-site timing breakdown
            # for this plan_trajectory call via the ROS logger, so it
            # shows up wherever you already view [arm_executor] logs.
            # Remove once done.
            report(plan_elapsed, logger=self.get_logger())

            if planned is None or not planned.points:

                self.get_logger().error(
                    '[arm_executor] no trajectory produced'
                )

                goal_handle.abort()

                result.success = False
                result.error_code = 3

                return result

            # ==========================================================
            # Check cancellation before dispatch
            # ==========================================================

            if goal_handle.is_cancel_requested:

                self.get_logger().warn(
                    '[arm_executor] goal cancelled before dispatch'
                )

                goal_handle.canceled()

                result.success = False
                result.error_code = 5

                return result

            # ==========================================================
            # Execute the WHOLE run as ONE JTC goal. Per-leg feedback
            # is published inside _run_on_jtc as elapsed execution
            # time crosses each leg's cumulative end time
            # (planned.leg_time_ranges).
            # ==========================================================

            ok = self._run_on_jtc(
                planned,
                goal_handle=goal_handle,
            )

            if not ok:

                self.get_logger().error(
                    '[arm_executor] execution failed'
                )

                goal_handle.abort()

                result.success = False
                result.error_code = 4

                return result

            q_seed = np.asarray(
                planned.predicted_q,
                dtype=float,
            ).copy()

            # ==========================================================
            # Entire ExecuteMoveStep succeeded
            # ==========================================================

            self._clear_prefetch()

            goal_handle.succeed()

            result.success = True
            result.error_code = 0
            result.final_state = q_seed.tolist()

            self.get_logger().info(
                '[arm_executor] ExecuteMoveStep completed successfully'
            )

            return result

        # ==============================================================
        # Unexpected exception
        # ==============================================================

        except Exception as exc:

            self.get_logger().error(
                '[arm_executor] unexpected error: '
                f'{exc}\n{traceback.format_exc()}'
            )

            self._clear_prefetch()

            if goal_handle.is_active:

                goal_handle.abort()

            result.success = False
            result.error_code = 3

            return result

    def destroy_node(self):

        self.get_logger().info(
            '[arm_executor] shutting down planning worker'
        )

        try:

            self._plan_pool.shutdown(
                wait=False,
                cancel_futures=True,
            )

        except TypeError:

            # Python versions without cancel_futures.
            self._plan_pool.shutdown(
                wait=False
            )

        super().destroy_node()


# ======================================================================
# Main
# ======================================================================

def main(args=None):

    rclpy.init(args=args)

    node = ArmExecutorNode()

    executor = MultiThreadedExecutor(
        num_threads=6
    )

    executor.add_node(node)

    try:

        executor.spin()

    except KeyboardInterrupt:

        pass

    finally:

        executor.shutdown()

        node.destroy_node()

        rclpy.shutdown()


if __name__ == '__main__':
    main()