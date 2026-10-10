"""Multi-arm grasp wiring: per-arm catalog topics/plugins, bridge arm routing,
cross-arm conflict. Runs without ROS (rclpy etc. are stubbed)."""
import sys
import types
from unittest.mock import MagicMock

import pytest

OBJECTS = """
gripper: {parent_model: ur_robot, parent_link: wrist_3_link}
object_types:
  cube_small: {child_link: link, geometry: {shape: box, size: [0.03, 0.03, 0.03]}, max_instances: 2}
"""


_PRESET = {}


def _stub_ros():
    class _Node:
        def __init__(self, *a, **k):
            self._params = dict(_PRESET)

        def declare_parameter(self, name, default=None):
            self._params.setdefault(name, default)

        def get_parameter(self, name):
            return types.SimpleNamespace(value=self._params[name])

        def create_publisher(self, _t, topic, _q):
            m = MagicMock()
            m.topic = topic
            return m

        def create_service(self, *a, **k):
            return MagicMock()

        def get_logger(self):
            return MagicMock()
    for n in ["rclpy", "std_msgs", "std_msgs.msg", "robokpy_interfaces",
              "robokpy_interfaces.srv", "ament_index_python", "ament_index_python.packages"]:
        sys.modules.setdefault(n, MagicMock(name=n))
    sys.modules["rclpy.node"] = types.SimpleNamespace(Node=_Node)


@pytest.fixture()
def catalog(tmp_path):
    _stub_ros()
    from robokpy_controller.object_catalog import ObjectCatalog
    p = tmp_path / "objects.yaml"
    p.write_text(OBJECTS)
    return ObjectCatalog(str(p)), str(p)


def test_single_arm_names_are_unchanged(catalog):
    c, _ = catalog
    assert c.attach_topic("cube_small_1") == "/grasp_attach/cube_small_1/attach"
    assert c.state_topic("cube_small_1") == "/model/cube_small_1/detachable_joint/state"
    assert "output_topic" not in c.to_gazebo_plugin_sdf()
    assert len(c.to_ros_gz_bridge_args()) == 6


def test_per_arm_topics_are_unique_and_plugin_sets_output_topic(catalog):
    c, _ = catalog
    assert c.attach_topic("cube_small_1", "arm2") == "/grasp_attach/arm2/cube_small_1/attach"
    sdf1, sdf2 = c.to_gazebo_plugin_sdf("arm1"), c.to_gazebo_plugin_sdf("arm2")
    assert "<output_topic>/grasp_attach/arm2/cube_small_1/state</output_topic>" in sdf2
    assert "/grasp_attach/arm2/" not in sdf1
    args = c.to_ros_gz_bridge_args(["arm1", "arm2"])
    assert len(args) == len(set(args)) == 12


@pytest.fixture()
def bridge(catalog):
    c, path = catalog
    from robokpy_controller.grasp_attach_bridge import GraspAttachBridge
    _PRESET.clear()
    _PRESET.update({"objects_config_path": path, "arms": ["arm1", "arm2"]})
    return GraspAttachBridge()


def _req(parent, child="cube_small_1", attach=True, joint_id=0):
    return types.SimpleNamespace(parent_model=parent, child_model=child, child_link="link",
                                 attach=attach, joint_id=joint_id)


def _resp():
    return types.SimpleNamespace(success=None, message="", joint_id=None)


def test_attach_goes_to_the_requesting_arms_topic(bridge):
    r = bridge._handle_request(_req("arm2_robot"), _resp())
    assert r.success
    bridge._attach_pubs[("arm2", "cube_small_1")].publish.assert_called_once()
    bridge._attach_pubs[("arm1", "cube_small_1")].publish.assert_not_called()


def test_other_arm_cannot_grab_a_held_object_until_released(bridge):
    first = bridge._handle_request(_req("arm1_robot"), _resp())
    clash = bridge._handle_request(_req("arm2_robot"), _resp())
    assert first.success and not clash.success and "already held by arm" in clash.message
    bridge._handle_request(_req("arm1_robot", attach=False, joint_id=first.joint_id), _resp())
    bridge._detach_pubs[("arm1", "cube_small_1")].publish.assert_called_once()
    assert bridge._handle_request(_req("arm2_robot"), _resp()).success      # handoff now works


def test_same_arm_retry_is_idempotent(bridge):
    a = bridge._handle_request(_req("arm1_robot"), _resp())
    b = bridge._handle_request(_req("arm1_robot"), _resp())
    assert b.success and b.joint_id == a.joint_id
    assert bridge._attach_pubs[("arm1", "cube_small_1")].publish.call_count == 1