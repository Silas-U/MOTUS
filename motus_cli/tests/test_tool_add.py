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


EMBEDDED = GRIPPER.replace('width:=0.04"', 'width:=0.04 include_ros2_control:=true"').replace(
    '<link name="${prefix}gbase"/>',
    '<xacro:if value="${include_ros2_control}"><ros2_control name="g" type="system">'
    '<hardware><plugin>x</plugin></hardware></ros2_control></xacro:if>'
    '<link name="${prefix}gbase"/>', 1)


def test_embedded_ros2_control_is_rejected_unless_disabled(project):
    root, g = project
    g.write_text(EMBEDDED)
    with pytest.raises(ToolAddError, match="embeds its own <ros2_control>"):
        tool_add(root, source_path=str(g))
    tool_add(root, source_path=str(g), macro_args={"include_ros2_control": "false"})


def test_unbuilt_vendor_package_with_find_is_resolved(project, tmp_path):
    """Vendor repos use $(find <pkg>) but are not colcon-built: tool add must still work."""
    root, g = project
    vend = tmp_path / "vendor_dir" / "vendor_grip"
    (vend / "urdf").mkdir(parents=True)
    (vend / "package.xml").write_text("<package><name>vendor_grip</name></package>")
    (vend / "urdf" / "helper.xacro").write_text(
        '<?xml version="1.0"?><robot xmlns:xacro="http://ros.org/wiki/xacro"/>')
    (vend / "urdf" / "inner.xacro").write_text(g.read_text().replace(
        "<xacro:macro", '<xacro:include filename="$(find vendor_grip)/urdf/helper.xacro"/>\n'
        '  <xacro:macro', 1))
    rep = tool_add(root, source_path=str(tmp_path / "vendor_dir"), macro="toy_gripper")
    assert rep.descriptor.primary_joint == "drv"


def test_tcp_offset_creates_virtual_tcp_frame(project):
    root, g = project
    # drop the vendor-style tcp frame so the description has none
    txt = g.read_text().replace("tcp", "pad")
    g.write_text(txt)
    rep = tool_add(root, source_path=str(g), tcp_offset=[0.0, 0.0, 0.15])
    d = rep.descriptor
    assert d.tcp_link.endswith("gripper_1_tcp")
    assert d.tcp_offset == pytest.approx([0, 0, 0.15])
    # survives a replace/reapply (offset is recorded in the manifest inputs)
    assert tool_add(root, source_path=str(g), tcp_offset=[0, 0, 0.15], replace=True).descriptor.tcp_offset == pytest.approx([0, 0, 0.15])


def test_invalid_inertia_is_flagged(project):
    root, g = project
    g.write_text(g.read_text().replace(
        '<link name="${prefix}fl"/>',
        '<link name="${prefix}fl"><inertial><mass value="0.1"/>'
        '<inertia ixx="0" iyy="0" izz="0" ixy="0" ixz="0" iyz="0"/></inertial></link>'))
    rep = tool_add(root, source_path=str(g))
    assert any("invalid inertia" in w and "fl" in w for w in rep.warnings)


SIDEWAYS = """<?xml version="1.0"?>
<robot xmlns:xacro="http://ros.org/wiki/xacro">
  <xacro:macro name="side_gripper" params="prefix parent *origin">
    <joint name="${prefix}mount" type="fixed"><parent link="${parent}"/><child link="${prefix}gbase"/>
      <xacro:insert_block name="origin"/></joint>
    <link name="${prefix}gbase"/><link name="${prefix}fl"/><link name="${prefix}fr"/>
    <joint name="${prefix}drv" type="prismatic"><parent link="${prefix}gbase"/><child link="${prefix}fl"/>
      <origin xyz="0.1 0.02 0"/><axis xyz="0 1 0"/><limit lower="0" upper="0.02" velocity="1" effort="20"/></joint>
    <joint name="${prefix}fol" type="prismatic"><parent link="${prefix}gbase"/><child link="${prefix}fr"/>
      <origin xyz="0.1 -0.02 0"/><axis xyz="0 -1 0"/><limit lower="0" upper="0.02" velocity="1" effort="20"/>
      <mimic joint="${prefix}drv"/></joint>
  </xacro:macro>
</robot>
"""


def test_align_approach_rotates_x_forward_gripper_to_z(project):
    root, g = project
    g.write_text(SIDEWAYS)
    rep = tool_add(root, source_path=str(g), align_approach=True, tcp_offset=[0, 0, 0.1])
    import re as _re
    entry = next((root / "src").rglob("*.urdf.xacro")).read_text()
    m = _re.search(r'<origin xyz="0 0 0" rpy="([^"]+)"', entry)
    assert m, entry
    r, p, y = (float(v) for v in m.group(1).split())
    assert abs(p + 1.5708) < 1e-3          # x-forward -> z-forward is a -90 deg pitch
    assert rep.descriptor.tcp_offset == pytest.approx([0, 0, 0.1])
    with pytest.raises(ToolAddError, match="no \\*origin"):
        g.write_text(GRIPPER)
        tool_add(root, source_path=str(g), mount_rpy=[0, 1.0, 0], replace=True)