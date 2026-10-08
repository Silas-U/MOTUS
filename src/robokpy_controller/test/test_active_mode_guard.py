"""arm_executor must force ACTIVE mode before a run (PLANNER publishes a
virtual joint state, which let the execution monitor 'confirm' targets the
arm never reached). Runs without ROS: rclpy etc. are stubbed."""
import sys
import types
from unittest.mock import MagicMock

import importlib.abc
import importlib.machinery

_ROS_TOPLEVEL = {"rclpy", "rcl_interfaces", "std_msgs", "trajectory_msgs", "builtin_interfaces",
                 "control_msgs", "robokpy_interfaces", "ament_index_python", "geometry_msgs",
                 "sensor_msgs", "visualization_msgs", "std_srvs", "tf2_ros", "action_msgs",
                 "launch", "launch_ros"}


class _Stub(importlib.abc.MetaPathFinder, importlib.abc.Loader):
    def find_spec(self, name, path=None, target=None):
        if name.split(".")[0] in _ROS_TOPLEVEL:
            return importlib.machinery.ModuleSpec(name, self, is_package=True)

    def create_module(self, spec):
        m = MagicMock(name=spec.name)
        m.__path__ = []
        m.__spec__ = spec
        return m

    def exec_module(self, module):
        pass


sys.meta_path.insert(0, _Stub())
sys.modules.pop("rclpy.node", None)
import rclpy.node
rclpy.node.Node = type("Node", (), {})

import pytest

try:
    from robokpy_controller import arm_executor_node as ae
except Exception as exc:  # heavy deps (pinocchio/numpy stacks) not importable here
    pytest.skip(f"arm_executor_node not importable: {exc}", allow_module_level=True)


class _Fut:
    def __init__(self, v): self._v = v
    def done(self): return True
    def result(self): return self._v


_BOX = {}


@pytest.fixture(autouse=True)
def _live_samples(monkeypatch):
    monkeypatch.setattr(ae.time, 'sleep', lambda _s: _BOX['n']._tick())


def _node(mode, service_ok=True, success=True):
    n = object.__new__(ae.ArmExecutorNode)
    n._system_mode = mode
    n._joint_msg_count = 0
    n.FUTURE_POLL_SEC = 0.001
    n.get_logger = lambda: MagicMock()
    calls = []
    client = MagicMock()
    client.wait_for_service.return_value = service_ok
    def call_async(req):
        calls.append(req.new_mode)
        return _Fut(types.SimpleNamespace(success=success, message="m"))
    client.call_async.side_effect = call_async
    n._mode_client = client
    # live samples flow in while the guard waits for a fresh one
    n._tick = lambda: setattr(n, '_joint_msg_count', n._joint_msg_count + 1)
    n._wait_for_future = lambda f, t, d: f.result()
    _BOX['n'] = n
    return n, calls


def test_already_active_makes_no_call():
    n, calls = _node("ACTIVE")
    assert n._ensure_active_mode() is True and calls == []


@pytest.mark.parametrize("mode", ["PLANNER", None])
def test_planner_or_unknown_is_switched_to_active(mode):
    n, calls = _node(mode)
    assert n._ensure_active_mode() is True
    assert calls == ["ACTIVE"] and n._system_mode == "ACTIVE"


def test_service_missing_or_rejected_fails():
    assert _node("PLANNER", service_ok=False)[0]._ensure_active_mode() is False
    assert _node("PLANNER", success=False)[0]._ensure_active_mode() is False
