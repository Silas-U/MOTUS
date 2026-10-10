"""Logic test for CellOrchestrator.cancel() -- runs without ROS (rclpy etc. are stubbed)."""
import sys
import threading
import types
from unittest.mock import MagicMock

import pytest


def _stub_ros():
    class _Node:                      # minimal stand-in for rclpy.node.Node
        def get_logger(self):
            return MagicMock()
    names = ["rclpy", "rclpy.node", "rclpy.action", "rclpy.callback_groups", "rclpy.executors", "rclpy.task",
             "std_msgs", "std_msgs.msg", "control_msgs", "control_msgs.action", "sensor_msgs", "sensor_msgs.msg", "std_srvs", "std_srvs.srv", "geometry_msgs",
             "geometry_msgs.msg", "ament_index_python", "ament_index_python.packages",
             "robokpy_interfaces", "robokpy_interfaces.action", "robokpy_interfaces.msg",
             "robokpy_interfaces.srv"]
    for n in names:
        sys.modules.setdefault(n, MagicMock(name=n))
    sys.modules["rclpy.node"] = types.SimpleNamespace(Node=_Node)


@pytest.fixture()
def orch():
    _stub_ros()
    try:
        from robokpy_controller.cell_orchestrator_node import CellOrchestrator, CellState
    except Exception as exc:                       # missing non-ROS dependency
        pytest.skip(f"cannot import orchestrator without ROS: {exc}")
    o = object.__new__(CellOrchestrator)
    o._lock = threading.RLock()
    o._resource_lock = MagicMock()
    o._publish_cell_state = MagicMock()
    o._steps = {"a": object(), "b": object()}
    o._dependents, o._in_degree = {"a": ["b"], "b": []}, {"a": 0, "b": 1}
    o._progress_watchers, o._progress_fired = {}, set()
    o._completed, o._results, o._run_of = {"a"}, {"a": 1}, {}
    o._goal_epoch = {"a": 3, "b": 1}
    o._watchdogs = {"a": MagicMock()}
    o._active_resources = {"a": ["arm1"]}
    o._held_step_id, o._active_recipe_id, o._active_content_hash = None, "r1", "h"
    o._spawned = {"cube_small_1", "cube_large_2"}
    o._restore_planner = True
    o._mode_clients = {}
    o.get_logger = lambda: MagicMock()
    h = MagicMock()
    o._goal_handles = {"a": h, "b": h}              # one batched run shares one handle
    o.state = CellState.EXECUTING
    o._cs, o._handle = CellState, h
    return o


def test_cancel_returns_to_idle_stops_goals_and_invalidates_late_results(orch):
    watchdog = orch._watchdogs["a"]
    ok, msg = orch.cancel()
    assert ok and orch.state == orch._cs.IDLE and "r1" in msg
    orch._handle.cancel_goal_async.assert_called_once()            # shared handle cancelled once
    watchdog.cancel.assert_called_once()
    orch._resource_lock.release.assert_called_once_with(["arm1"], "a")
    assert orch._steps == {} and orch._completed == set() and orch._goal_handles == {}
    assert orch._is_current("a", 3) is False                       # in-flight result is stale
    assert orch._goal_epoch["a"] == 4                              # epoch advanced past 3


def test_cancel_when_idle_is_a_noop(orch):
    orch._spawned = set()
    orch.cancel()
    ok, msg = orch.cancel()
    assert ok and "Nothing to cancel" in msg


def test_cancel_refused_during_estop(orch):
    orch.state = orch._cs.ESTOP
    ok, _ = orch.cancel()
    assert not ok and orch.state == orch._cs.ESTOP


class _Fut:
    """Already-completed future that can be awaited."""
    def __init__(self, result):
        self._r = result

    def done(self):
        return True

    def __await__(self):
        if False:
            yield
        return self._r


def _run(coro):
    try:
        coro.send(None)
    except StopIteration as stop:
        return stop.value
    raise AssertionError("coroutine suspended")


def _client(ready=True, success=True, message="ok", log=None):
    c = MagicMock()
    c.service_is_ready.return_value = ready

    def call_async(req):
        if log is not None:
            log.append(req)
        return _Fut(types.SimpleNamespace(success=success, message=message))
    c.call_async.side_effect = call_async
    return c


def test_cancel_service_releases_tools_then_despawns_every_spawned_object(orch):
    despawned = []
    orch._despawn_request = lambda m: types.SimpleNamespace(child_model=m)
    orch._release_client = _client(message="released ['grasp']")
    orch._despawn_client = _client(log=despawned)
    resp = types.SimpleNamespace(success=None, message=None)
    resp = _run(orch._cancel_recipe_cb(None, resp))
    assert resp.success, resp.message
    assert sorted(r.child_model for r in despawned) == ["cube_large_2", "cube_small_1"]
    assert orch._spawned == set()
    assert "released" in resp.message and "despawned" in resp.message
    orch._release_client.call_async.assert_called_once()


def test_failed_despawn_is_reported_and_kept_for_the_next_cancel(orch):
    orch._release_client = _client()
    orch._despawn_client = _client(success=False)
    resp = _run(orch._cancel_recipe_cb(None, types.SimpleNamespace(success=None, message=None)))
    assert not resp.success and "FAILED" in resp.message
    assert orch._spawned == {"cube_small_1", "cube_large_2"}


def test_missing_tool_server_is_reported_but_objects_are_still_despawned(orch):
    orch._release_client = _client(ready=False)
    orch._despawn_client = _client()
    resp = _run(orch._cancel_recipe_cb(None, types.SimpleNamespace(success=None, message=None)))
    assert not resp.success and "release_all unavailable" in resp.message
    assert orch._spawned == set()


def test_spawn_results_are_tracked_and_a_late_one_after_cancel_is_despawned(orch):
    orch._spawned = set()
    orch._despawn_orphan = MagicMock()
    ok = types.SimpleNamespace(result=lambda: types.SimpleNamespace(success=True, child_model="cube_small_3"))
    orch._goal_epoch["s"] = 2
    orch._on_spawn_result("s", ok, 2, "spawn", "")            # current -> tracked, then continues
    assert orch._spawned == {"cube_small_3"}
    orch._despawn_orphan.assert_not_called()
    orch._spawned = set()
    orch._on_spawn_result("s", ok, 1, "spawn", "")            # stale epoch (cancelled run)
    orch._despawn_orphan.assert_called_once_with("cube_small_3")
    orch._spawned = {"cube_small_3"}
    gone = types.SimpleNamespace(result=lambda: types.SimpleNamespace(success=True, child_model=""))
    orch._on_spawn_result("d", gone, 0, "despawn", "cube_small_3")
    assert orch._spawned == set()


def _backend(held):
    _stub_ros()
    try:
        from robokpy_controller.tool_action_server import GraspAttachBackend
    except Exception as exc:
        pytest.skip(f"cannot import tool_action_server without ROS: {exc}")
    b = object.__new__(GraspAttachBackend)
    b.tool_id, b.logger = "grasp", MagicMock()
    b._held_joint_id, b._held_child_desc = held, ("cube_small_2" if held else None)
    calls = []

    async def _call(attach, child_model, child_link):
        calls.append(("call", attach))
        b._held_joint_id = None
        return "opened"

    async def _disengage():
        calls.append(("disengage",))

    b._call = _call
    b._actuator = types.SimpleNamespace(disengage=_disengage)
    return b, calls


def test_release_all_detaches_a_held_object():
    b, calls = _backend(held=8)
    _run(b.release_all())
    assert calls == [("call", False)]            # unweld (its own path also opens the gripper)
    assert b._held_joint_id is None


def test_release_all_still_opens_the_gripper_when_nothing_is_held():
    b, calls = _backend(held=None)
    _run(b.release_all())
    assert calls == [("disengage",)]


def test_release_all_recovers_when_the_bridge_forgot_the_joint():
    b, calls = _backend(held=8)

    async def _failing(attach, child_model, child_link):
        calls.append(("call", attach))
        return "error_service_failed"
    b._call = _failing
    _run(b.release_all())
    assert calls == [("call", False), ("disengage",)] and b._held_joint_id is None


def _mode_clients(*ready):
    clients = {}
    for i, r in enumerate(ready, 1):
        c = MagicMock()
        c.service_is_ready.return_value = r
        clients[f"arm{i}"] = c
    return clients


def test_cancel_puts_every_ready_arm_back_in_planner_mode(orch):
    orch._mode_clients = _mode_clients(True, True)
    orch.cancel()
    for c in orch._mode_clients.values():
        c.call_async.assert_called_once()
        assert c.call_async.call_args[0][0].new_mode == "PLANNER"


def test_unreachable_arm_is_skipped_not_fatal(orch):
    orch._mode_clients = _mode_clients(True, False)
    ok, _ = orch.cancel()
    assert ok
    orch._mode_clients["arm1"].call_async.assert_called_once()
    orch._mode_clients["arm2"].call_async.assert_not_called()


def test_restore_can_be_disabled(orch):
    orch._restore_planner = False
    orch._mode_clients = _mode_clients(True)
    orch.cancel()
    orch._mode_clients["arm1"].call_async.assert_not_called()


def test_recipe_completion_restores_planner_only_when_all_steps_done(orch):
    orch._mode_clients = _mode_clients(True)
    orch._dispatch = MagicMock()
    orch._resolve_pending_progress = MagicMock(return_value=[])
    orch._steps = {"a": object(), "b": object()}
    orch._completed = set()
    orch._dependents, orch._in_degree = {"a": ["b"], "b": []}, {"a": 0, "b": 1}
    orch._on_step_completed("a")
    orch._mode_clients["arm1"].call_async.assert_not_called()      # b still pending
    orch._on_step_completed("b")
    orch._mode_clients["arm1"].call_async.assert_called_once()
    assert orch.state == orch._cs.IDLE
