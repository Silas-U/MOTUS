"""
mp_jtc.py  —  JtcExecutor

All async FollowJointTrajectory action client logic in one place:
  • send_goal with response timeout
  • get_result with trajectory-duration-aware timeout
  • cancel with timeout
  • fallback position polling when DDS drops the result

No trajectory generation, no waypoint logic — pure JTC I/O.
"""

import time
import numpy as np
from typing import Callable, Optional, List

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.task import Future
from control_msgs.action import FollowJointTrajectory

from .mp_types import JtcResult


def _future_with_timeout(node: Node, future: Future, timeout_sec: float) -> Future:
    """Wrap a future so it raises TimeoutError if not done within timeout_sec."""
    if future.done():
        return future
    state = {'cleaned': False}
    timer = [None]

    def _cleanup():
        if state['cleaned']:
            return
        state['cleaned'] = True
        if timer[0] is not None:
            timer[0].cancel()
            timer[0].destroy()
            timer[0] = None

    def _on_timeout():
        if not future.done():
            future.set_exception(TimeoutError())
        _cleanup()

    def _on_done(_):
        _cleanup()

    timer[0] = node.create_timer(timeout_sec, _on_timeout)
    future.add_done_callback(_on_done)
    return future


class JtcExecutor:
    def __init__(self,
                 node: Node,
                 client: ActionClient,
                 logger,
                 goal_response_timeout: float = 2.0,
                 result_timeout_margin: float = 10.0,
                 cancel_timeout: float = 5.0,
                 cooldown_sec: float = 0.0,
                 poll_tolerance: float = 0.05):
        self._node = node
        self._client = client
        self._logger = logger
        self._goal_response_timeout = goal_response_timeout
        self._result_timeout_margin = result_timeout_margin
        self._cancel_timeout = cancel_timeout
        self._cooldown_sec = cooldown_sec
        self._poll_tolerance = poll_tolerance
        self._last_send_time = 0.0
        self._server_known_available = False

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------
    async def execute(self,
                      jtc_goal: FollowJointTrajectory.Goal,
                      feedback_callback: Callable,
                      trajectory_duration_sec: float,
                      step_id_for_log: str,
                      q_current_fn: Callable[[], Optional[np.ndarray]]) -> JtcResult:
        """Send a trajectory to the JTC and wait for completion.

        Returns JtcResult with success, error_code, and actual_positions.
        Handles timeouts, dropped DDS responses, and position polling fallback.
        """
        await self._respect_cooldown(step_id_for_log)

        # --- Send goal ---
        if not self._server_known_available:
            if not self._client.wait_for_server(timeout_sec=2.0):
                self._logger.error(f'{step_id_for_log}: JTC server not available')
                return JtcResult(success=False, error_code=6)
            self._server_known_available = True

        send_future = self._client.send_goal_async(
            jtc_goal, feedback_callback=feedback_callback)
        try:
            goal_handle = await _future_with_timeout(
                self._node, send_future, self._goal_response_timeout)
        except TimeoutError:
            self._logger.error(
                f'{step_id_for_log}: no goal-response from JTC within '
                f'{self._goal_response_timeout:.1f}s')
            # Fallback: poll position
            return await self._poll_fallback(
                jtc_goal, trajectory_duration_sec, q_current_fn, step_id_for_log)

        if not goal_handle.accepted:
            self._logger.error(f'{step_id_for_log}: JTC rejected the goal')
            return JtcResult(success=False, error_code=6)

        # --- Wait for result ---
        result_timeout = trajectory_duration_sec + self._result_timeout_margin
        result_wrapper = Future()
        result_timer = [None]

        def _cleanup_result_timer():
            t = result_timer[0]
            if t is not None:
                result_timer[0] = None
                try:
                    t.cancel()
                except Exception:
                    pass
                try:
                    t.destroy()
                except Exception:
                    pass

        def _on_result_done(f):
            _cleanup_result_timer()
            if result_wrapper.done():
                return
            try:
                result_wrapper.set_result(('ok', f.result()))
            except Exception as e:
                result_wrapper.set_result(('error', e))

        def _on_result_timeout():
            _cleanup_result_timer()
            if not result_wrapper.done():
                result_wrapper.set_result(('timeout', None))

        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(_on_result_done)
        result_timer[0] = self._node.create_timer(result_timeout, _on_result_timeout)
        res_status, res_value = await result_wrapper

        if res_status == 'timeout':
            self._logger.error(f'{step_id_for_log}: JTC result timeout — cancelling')
            await self._cancel_goal(goal_handle)
            return JtcResult(success=False, error_code=11, timed_out=True)

        if res_status == 'error':
            return JtcResult(success=False, error_code=11)

        # --- Map result ---
        jtc_result = res_value
        success = jtc_result.result.error_code == FollowJointTrajectory.Result.SUCCESSFUL
        actual = None
        if hasattr(jtc_result.result, 'actual'):
            actual = list(jtc_result.result.actual.positions)
        if not success:
            self._logger.error(
                f'{step_id_for_log}: JTC execution failed, '
                f'error_code={jtc_result.result.error_code}')
            return JtcResult(success=False, error_code=9, actual_positions=actual)
        return JtcResult(success=True, error_code=0, actual_positions=actual)

    async def cancel(self, goal_handle) -> bool:
        """Cancel an active goal. Returns True if cancel was acknowledged."""
        try:
            cancel_future = goal_handle.cancel_goal_async()
            wrapper = Future()
            timer = [None]

            def _cleanup():
                if timer[0] is not None:
                    try:
                        timer[0].cancel()
                    except Exception:
                        pass
                    try:
                        timer[0].destroy()
                    except Exception:
                        pass
                    timer[0] = None

            def _on_done(f):
                _cleanup()
                if not wrapper.done():
                    try:
                        wrapper.set_result(f.result())
                    except Exception as e:
                        wrapper.set_result(e)

            def _on_timeout():
                _cleanup()
                if not wrapper.done():
                    wrapper.set_result(None)

            cancel_future.add_done_callback(_on_done)
            timer[0] = self._node.create_timer(self._cancel_timeout, _on_timeout)
            await wrapper
            return True
        except Exception as e:
            self._logger.warn(f'Cancel failed: {e}')
            return False

    # ------------------------------------------------------------------
    # Internal
    # ------------------------------------------------------------------
    async def _respect_cooldown(self, step_id_for_log: str):
        now = self._node.get_clock().now().nanoseconds / 1e9
        elapsed = now - self._last_send_time
        if elapsed < self._cooldown_sec:
            cooldown = self._cooldown_sec - elapsed
            self._logger.debug(f'{step_id_for_log}: JTC cooldown {cooldown:.3f}s')
            await self._sleep_async(cooldown)
        self._last_send_time = self._node.get_clock().now().nanoseconds / 1e9

    async def _poll_fallback(self,
                             jtc_goal: FollowJointTrajectory.Goal,
                             trajectory_duration_sec: float,
                             q_current_fn: Callable[[], Optional[np.ndarray]],
                             step_id_for_log: str) -> JtcResult:
        """When DDS drops the goal response, poll joint state until we reach target."""
        final_positions = np.array(jtc_goal.trajectory.points[-1].positions)
        deadline = time.monotonic() + trajectory_duration_sec + 5.0
        while time.monotonic() < deadline:
            q = q_current_fn()
            if q is not None:
                err = float(np.max(np.abs(q - final_positions)))
                if err < self._poll_tolerance:
                    self._logger.warn(
                        f'{step_id_for_log}: reached target despite lost goal response')
                    return JtcResult(success=True, error_code=0)
            await self._sleep_async(0.2)
        return JtcResult(success=False, error_code=10, timed_out=True)

    async def _cancel_goal(self, goal_handle):
        try:
            await self.cancel(goal_handle)
        except Exception:
            pass

    async def _sleep_async(self, duration_sec: float):
        if duration_sec <= 0.0:
            return
        future = Future()
        timer = [None]

        def _cb():
            if timer[0] is not None:
                timer[0].cancel()
                timer[0].destroy()
                timer[0] = None
            if not future.done():
                future.set_result(None)

        timer[0] = self._node.create_timer(duration_sec, _cb)
        await future
