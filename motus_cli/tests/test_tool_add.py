"""Offline tests for `motus tool add` (synthetic arm + gripper, no network, no ROS)."""
import json
import sys
from pathlib import Path

import pytest

pytest.importorskip("xacro")

from motus_cli.builder import package_generator
from motus_cli.builder.robot_add import robot_add
from motus_cli.builder.tool_add import ToolAddError, tool_add, tool_remove

ARM = """<?xml version="1.0"?>
<robot xmlns:xacro="http://ros.org/wiki/xacro" name="toy">
  <link name="base_link"/>
  <link name="l1"/><link name="l2"/><link name="tool0"/>
  <joint name="j1" type="revolute"><parent link="base_link"/><child link="l1"/>
    <axis xyz="0 0 1"/><limit lower="-3" upper="3" velocity="1" effort="50"/></joint>
  <joint name="j2" type="revolute"><parent link="l1"/><child link="l2"/>
    <origin xyz="0 0 0.3"/><axis xyz="0 1 0"/><limit lower="-3" upper="3" velocity="1" effort="50"/></joint>
  <joint name="flange" type="fixed"><parent link="l2"/><child link="tool0"/><origin xyz="0 0 0.2"/></joint>
</robot>
"""

GRIPPER = """<?xml version="1.0"?>
<robot xmlns:xacro="http://ros.org/wiki/xacro">
  <xacro:macro name="toy_gripper" params="prefix parent width:=0.04">
    <link name="${prefix}gbase"/><link name="${prefix}fl"/><link name="${prefix}fr"/><link name="${prefix}tcp"/>
    <joint name="${prefix}mount" type="fixed"><parent link="${parent}"/><child link="${prefix}gbase"/></joint>
    <joint name="${prefix}drv" type="prismatic"><parent link="${prefix}gbase"/><child link="${prefix}fl"/>
      <axis xyz="0 1 0"/><limit lower="0" upper="${width}" velocity="1" effort="20"/></joint>
    <joint name="${prefix}fol" type="prismatic"><parent link="${prefix}gbase"/><child link="${prefix}fr"/>
      <axis xyz="0 -1 0"/><limit lower="0" upper="${width}" velocity="1" effort="20"/>
      <mimic joint="${prefix}drv"/></joint>
    <joint name="${prefix}tcpj" type="fixed"><parent link="${prefix}gbase"/><child link="${prefix}tcp"/>
      <origin xyz="0 0 0.1"/></joint>
  </xacro:macro>
</robot>
"""


@pytest.fixture()
def project(tmp_path):
    src = tmp_path / "src_desc"
    src.mkdir()
    (src / "arm.urdf.xacro").write_text(ARM)
    (src / "gripper.xacro").write_text(GRIPPER)
    paths = package_generator.create_project("toy_cell", dest=str(tmp_path))
    robot_add(paths.workspace_root, str(src / "arm.urdf.xacro"))
    return Path(paths.workspace_root), src / "gripper.xacro"


def test_add_detects_driver_tcp_and_writes_everything(project):
    root, g = project
    rep = tool_add(root, source_path=str(g))
    d = rep.descriptor
    assert d.primary_joint == "drv" and d.state_only_joints == ["fol"]
    assert d.tcp_link == "tcp" and d.tcp_offset == pytest.approx([0, 0, 0.1])
    assert (d.open_position, d.closed_position) == (0.0, pytest.approx(0.038))
    pkg = root / "src" / "toy_cell_motus"
    assert "planning_tip_link: tcp" in (pkg / "config" / "robot.yaml").read_text()
    assert "gripper_action_controller" in (pkg / "config" / "controllers.yaml").read_text()
    assert "joint_name: drv" in (pkg / "config" / "tools.yaml").read_text()
    assert "tools_config_path" in (pkg / "launch" / "toy_cell.launch.py").read_text()


def test_replace_is_idempotent_and_remove_restores(project):
    root, g = project
    pkg = root / "src" / "toy_cell_motus"
    before = {p.name: p.read_text() for p in (pkg / "config").glob("*.yaml")}
    tool_add(root, source_path=str(g))
    snap = {p.name: p.read_text() for p in (pkg / "config").glob("*.yaml")}
    tool_add(root, source_path=str(g), replace=True)
    assert snap == {p.name: p.read_text() for p in (pkg / "config").glob("*.yaml")}
    tool_remove(root, "gripper_1")
    assert "MOTUS-TOOL" not in (pkg / "urdf" / "toy_cell.urdf.xacro").read_text()
    assert "planning_tip_link: tool0" in (pkg / "config" / "robot.yaml").read_text()
    assert (pkg / "config" / "controllers.yaml").read_text() == before["controllers.yaml"]


def test_macro_arg_and_limit_validation(project):
    root, g = project
    tool_add(root, source_path=str(g), macro_args={"width": "0.08"})
    tool_remove(root, "gripper_1")
    with pytest.raises(ToolAddError, match="outside the driver joint's limits"):
        tool_add(root, source_path=str(g), closed_position=0.5)


def test_unsupported_kind_and_second_gripper_rejected(project):
    root, g = project
    with pytest.raises(ToolAddError, match="not implemented"):
        tool_add(root, source_path=str(g), kind="suction")
    tool_add(root, source_path=str(g))
    with pytest.raises(ToolAddError, match="already this arm's gripper"):
        tool_add(root, source_path=str(g), tool_id="gripper_2")


def test_failed_add_leaves_project_untouched(project):
    root, g = project
    pkg = root / "src" / "toy_cell_motus"
    before = {p: p.read_text() for p in pkg.rglob("*") if p.is_file()}
    with pytest.raises(ToolAddError):
        tool_add(root, source_path=str(g), closed_position=9.0)
    assert before == {p: p.read_text() for p in pkg.rglob("*") if p.is_file()}
    assert "tools" not in json.loads((root / "motus.json").read_text())
