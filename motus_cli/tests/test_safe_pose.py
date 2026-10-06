"""Offline tests for the builder's ready_pose (singularity-safe IK seed / pre-move target)."""
import re
from pathlib import Path

import pytest

np = pytest.importorskip("numpy")
pytest.importorskip("xacro")

from motus_cli.builder import package_generator, safe_pose
from motus_cli.builder.robot_add import robot_add

# A UR-style 6R arm: all-zero joints = fully stretched upright "candle" = singular.
ARM6 = """<?xml version="1.0"?>
<robot xmlns:xacro="http://ros.org/wiki/xacro" name="six">
  <link name="base_link"/>
  <link name="l1"/><link name="l2"/><link name="l3"/><link name="l4"/><link name="l5"/><link name="l6"/><link name="tool0"/>
  <joint name="j1" type="revolute"><parent link="base_link"/><child link="l1"/><origin xyz="0 0 0.15"/>
    <axis xyz="0 0 1"/><limit lower="-6.28" upper="6.28" velocity="2" effort="50"/></joint>
  <joint name="j2" type="revolute"><parent link="l1"/><child link="l2"/><origin xyz="0 0.1 0"/>
    <axis xyz="0 1 0"/><limit lower="-6.28" upper="6.28" velocity="2" effort="50"/></joint>
  <joint name="j3" type="revolute"><parent link="l2"/><child link="l3"/><origin xyz="0 0 0.45"/>
    <axis xyz="0 1 0"/><limit lower="-3.14" upper="3.14" velocity="2" effort="50"/></joint>
  <joint name="j4" type="revolute"><parent link="l3"/><child link="l4"/><origin xyz="0 0 0.4"/>
    <axis xyz="0 1 0"/><limit lower="-6.28" upper="6.28" velocity="2" effort="50"/></joint>
  <joint name="j5" type="revolute"><parent link="l4"/><child link="l5"/><origin xyz="0 0.1 0"/>
    <axis xyz="0 0 1"/><limit lower="-6.28" upper="6.28" velocity="2" effort="50"/></joint>
  <joint name="j6" type="revolute"><parent link="l5"/><child link="l6"/><origin xyz="0 0 0.1"/>
    <axis xyz="0 1 0"/><limit lower="-6.28" upper="6.28" velocity="2" effort="50"/></joint>
  <joint name="flange" type="fixed"><parent link="l6"/><child link="tool0"/><origin xyz="0 0 0.1"/></joint>
</robot>
"""
JOINTS = ["j1", "j2", "j3", "j4", "j5", "j6"]


def _sigma(chain, q):
    _lowest, _tip, _z, J, length, _elbow = safe_pose._chain_jacobian(chain, dict(zip(JOINTS, q)))
    scale = np.array([1.0 / length] * 3 + [1.0] * 3)
    return float(np.linalg.svd(scale[:, None] * J, compute_uv=False)[-1])


def test_ready_pose_is_bent_and_well_conditioned_while_home_is_singular():
    home, _ = safe_pose.choose_home_pose(ARM6, "base_link", "tool0", JOINTS)
    ready, note = safe_pose.choose_ready_pose(ARM6, "base_link", "tool0", JOINTS, home)
    assert ready is not None and len(ready) == 6, note
    chain = safe_pose._parse_chain(ARM6, "base_link", "tool0")
    assert _sigma(chain, home) < 1e-3                       # the spawn pose is a singularity
    assert _sigma(chain, ready) >= safe_pose.READY_SIGMA_MIN  # the ready pose is not
    assert max(abs(v) for v in ready) <= 6.28


def test_ready_pose_is_deterministic():
    a, _ = safe_pose.choose_ready_pose(ARM6, "base_link", "tool0", JOINTS, [0.0] * 6)
    b, _ = safe_pose.choose_ready_pose(ARM6, "base_link", "tool0", JOINTS, [0.0] * 6)
    assert a == b


def test_bad_chain_returns_none_with_note():
    ready, note = safe_pose.choose_ready_pose(ARM6, "base_link", "nope", JOINTS, None)
    assert ready is None and "ready_pose" in note


def test_robot_add_writes_ready_pose_to_robot_yaml(tmp_path):
    src = tmp_path / "arm.urdf.xacro"
    src.write_text(ARM6)
    paths = package_generator.create_project("six_cell", dest=str(tmp_path))
    robot_add(paths.workspace_root, str(src))
    yaml_text = (Path(paths.workspace_root) / "src" / "six_cell_motus" / "config" / "robot.yaml").read_text()
    m = re.search(r"^\s+ready_pose: \[(.*)\]$", yaml_text, re.M)
    assert m, yaml_text
    vals = [float(v) for v in m.group(1).split(",")]
    assert len(vals) == 6 and any(abs(v) > 1e-6 for v in vals)
    # every entry must stay a float literal: rclpy rejects int arrays for DOUBLE_ARRAY params
    assert all("." in v or "e" in v.lower() for v in m.group(1).split(","))


def test_ready_pose_is_on_the_elbow_up_working_side():
    """Elbow-down (or reaching behind the base) is the branch that collides
    with the base/table in a pick-and-place cell."""
    home, _ = safe_pose.choose_home_pose(ARM6, "base_link", "tool0", JOINTS)
    ready, _ = safe_pose.choose_ready_pose(ARM6, "base_link", "tool0", JOINTS, home)
    chain = safe_pose._parse_chain(ARM6, "base_link", "tool0")
    q = dict(zip(JOINTS, ready))
    *_, length, elbow_h = safe_pose._chain_jacobian(chain, q)
    assert elbow_h >= safe_pose.READY_ELBOW_UP_FRAC * length
    assert safe_pose._forward_reach(chain, JOINTS, ready) >= safe_pose.READY_FORWARD_FRAC * length
