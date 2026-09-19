"""
ros2_control_injector.py

Discovered the hard way, against a real launch: an imported robot with
no <ros2_control> block in its URDF spawns into Gazebo fine, but no
controller_manager ever comes up for it -- Gazebo only instantiates one
via the gz_ros2_control plugin, which requires the URDF to declare both
a <ros2_control> hardware block AND a <gazebo><plugin> block pointing at
it. Motus's own ur5e_robotiq_85_ros2_control_gz macro
(urdf/macros/ros2_control_macros.xacro) does exactly this for UR5e --
and notably, Motus's own built-in mycobot_280 macro is an explicit,
documented stub for the same reason ("ros2_control support is not yet
implemented for this arm"). This module generalizes that pattern to any
imported robot's DOF-bearing chain rather than writing a
robot-specific macro by hand.

Mirrors Motus's own approach exactly, including its substitution
mechanism: `$(arg controllers_yaml_path)` / `$(arg namespace)` inside
the injected <parameters>/<namespace> tags, resolved via
xacro.process_file(..., mappings={...}) at launch time -- confirmed
this resolves correctly with `$(arg name)` + a matching `<xacro:arg>`
declaration, same as arm.launch.py already passes for built-in robots.
This is WHY every imported robot is now written out as .urdf.xacro
regardless of the source file's original extension (see robot_add.py):
a plain .urdf has no substitution mechanism at all, so `$(arg ...)`
would just sit there as literal dead text forever.

Sim-only, by design and stated plainly here rather than left implicit:
<hardware><plugin>gz_ros2_control/GazeboSimSystem</plugin></hardware> is
Gazebo's own mock/sim hardware interface. A real (non-simulated) version
of an imported robot needs its OWN hardware plugin (a real driver) swapped
in -- exactly the same real-hardware gap Motus's own UR5e macro documents
for itself, not something specific to imported robots.
"""

from __future__ import annotations

from .kinematic_analyzer import KinematicAnalysis
from .urdf_parser import RobotDescription

_XACRO_NS_ATTR = 'xmlns:xacro="http://ros.org/wiki/xacro"'


def _ensure_xacro_namespace(urdf_text: str) -> str:
    """A plain vendor URDF's <robot ...> tag has no xacro namespace
    declared -- needed for the <xacro:arg> elements this module adds to
    be valid. Idempotent: does nothing if already present (e.g. the
    source was already a Motus-authored xacro file)."""
    if "xmlns:xacro=" in urdf_text:
        return urdf_text
    idx = urdf_text.find("<robot")
    if idx == -1:
        return urdf_text  # malformed input; urdf_parser will catch this separately
    tag_end = urdf_text.find(">", idx)
    if tag_end == -1:
        return urdf_text
    # Self-closing <robot .../> is not valid for a real description (it
    # always has children) but guard anyway rather than mis-insert.
    insert_at = tag_end - 1 if urdf_text[tag_end - 1] == "/" else tag_end
    return urdf_text[:insert_at] + f" {_XACRO_NS_ATTR}" + urdf_text[insert_at:]


def build_ros2_control_block(analysis: KinematicAnalysis, pkg_name: str) -> str:
    joints_xml = "\n".join(
        f"""      <joint name="{j.name}">
        <command_interface name="position"/>
        <state_interface name="position"/>
        <state_interface name="velocity"/>
      </joint>"""
        for j in analysis.chain_joints
    )
    return f"""\
  <xacro:arg name="controllers_yaml_path" default=""/>
  <xacro:arg name="namespace" default=""/>

  <ros2_control name="{pkg_name}_GazeboSystem" type="system">
    <hardware>
      <plugin>gz_ros2_control/GazeboSimSystem</plugin>
    </hardware>
{joints_xml}
  </ros2_control>

  <gazebo>
    <plugin filename="gz_ros2_control-system"
            name="gz_ros2_control::GazeboSimROS2ControlPlugin">
      <parameters>$(arg controllers_yaml_path)</parameters>
      <ros>
        <namespace>$(arg namespace)</namespace>
      </ros>
    </plugin>
  </gazebo>
"""


def inject_ros2_control(urdf_text: str, analysis: KinematicAnalysis, pkg_name: str) -> str:
    if analysis.dof == 0:
        return urdf_text  # nothing to control; leave the placeholder URDF alone

    urdf_text = _ensure_xacro_namespace(urdf_text)

    close_idx = urdf_text.rfind("</robot>")
    if close_idx == -1:
        return urdf_text  # malformed; let urdf_parser surface the real error later

    block = build_ros2_control_block(analysis, pkg_name)
    # <xacro:arg> elements must not be nested inside anything else for
    # xacro to register them reliably -- insert right after the opening
    # <robot ...> tag (top-level, alongside every other top-level
    # element) rather than jammed in next to </robot> with everything else.
    robot_tag_end = urdf_text.find(">", urdf_text.find("<robot")) + 1
    args_only = "\n".join(block.splitlines()[0:3])  # the two xacro:arg lines + blank
    rest = "\n".join(block.splitlines()[3:])

    urdf_text = urdf_text[:robot_tag_end] + "\n" + args_only + urdf_text[robot_tag_end:]
    close_idx = urdf_text.rfind("</robot>")  # recompute: string shifted
    return urdf_text[:close_idx] + rest + "\n" + urdf_text[close_idx:]


_DUMMY_INERTIAL = """<inertial>
      <mass value="0.001"/>
      <origin xyz="0 0 0" rpy="0 0 0"/>
      <inertia ixx="0.0001" iyy="0.0001" izz="0.0001" ixy="0" ixz="0" iyz="0"/>
    </inertial>"""


def ensure_base_link_inertial(urdf_text: str, desc: RobotDescription, base_link: str) -> str:
    """Found the hard way against a real launch: Gazebo's urdf2sdf
    conversion tries to lump a massless link into its neighbor via fixed
    joint reduction, but for the ROOT link specifically there's nothing
    upstream to lump into -- it just gets silently dropped entirely
    ("link[g_base] is not modeled in sdf"), which then breaks the whole
    frame graph downstream (every joint attached to it reports as
    disconnected) and, as far as I can tell from that failure signature,
    is why gz_ros2_control never finished initializing either (spawners
    still couldn't reach /controller_manager). A massless root link with
    only fixed children is common in real vendor URDFs that were only
    ever meant for RViz/MoveIt display, not physics sim -- so give it a
    negligible-but-nonzero dummy inertial rather than assume every
    imported description already has one. Only touches base_link, and
    only if it genuinely has none -- every other link keeps whatever the
    source description gave it."""
    link = desc.links.get(base_link)
    if link is None or link.has_inertial:
        return urdf_text

    open_tag_prefix = f'<link name="{base_link}"'
    idx = urdf_text.find(open_tag_prefix)
    if idx == -1:
        return urdf_text  # shouldn't happen if desc was parsed from this same text
    tag_close = urdf_text.find(">", idx)
    if tag_close == -1:
        return urdf_text

    if urdf_text[tag_close - 1] == "/":
        # Self-closing <link name="base"/> -- expand it to hold the inertial.
        return (
            urdf_text[:tag_close - 1] + f">\n    {_DUMMY_INERTIAL}\n  </link>"
            + urdf_text[tag_close + 1:]
        )
    return urdf_text[:tag_close + 1] + f"\n    {_DUMMY_INERTIAL}" + urdf_text[tag_close + 1:]