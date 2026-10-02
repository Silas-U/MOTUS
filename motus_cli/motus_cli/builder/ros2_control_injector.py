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


def _initial_value_expr(i: int) -> str:
    """xacro expression for joint #i's initial position: the i-th entry of
    the comma-separated `home_pose` xacro arg, or 0.0 when the arg is
    unset/empty/too short (so a project launched without it behaves
    exactly as before)."""
    hp = "str(_motus_home_pose)"
    return (
        f"${{float({hp}.split(',')[{i}]) "
        f"if {hp}.strip() and len({hp}.split(',')) > {i} else 0.0}}"
    )


def build_ros2_control_block(analysis: KinematicAnalysis, pkg_name: str) -> str:
    # Each joint's POSITION state interface carries an initial_value taken
    # from the `home_pose` xacro arg (comma-separated, in chain order),
    # which the launch file fills from robot.yaml's home_pose. Without it
    # gz_ros2_control spawns every joint at 0.0, and for arms whose
    # all-zeros pose touches the floor (e.g. a UR5's wrist, ~5 cm below
    # the ground plane) dartsim has to solve constant ground contact.
    joints_xml = "\n".join(
        f"""      <joint name="{j.name}">
        <command_interface name="position"/>
        <state_interface name="position">
          <param name="initial_value">{_initial_value_expr(i)}</param>
        </state_interface>
        <state_interface name="velocity"/>
      </joint>"""
        for i, j in enumerate(analysis.chain_joints)
    )
    return f"""\
  <xacro:arg name="controllers_yaml_path" default=""/>
  <xacro:arg name="namespace" default=""/>
  <xacro:arg name="home_pose" default=""/>
  <xacro:property name="_motus_home_pose" value="$(arg home_pose)"/>

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


def inject_ros2_control(
    urdf_text: str, analysis: KinematicAnalysis, pkg_name: str,
    already_has_ros2_control: bool = False,
) -> str:
    if analysis.dof == 0:
        return urdf_text  # nothing to control; leave the placeholder URDF alone

    if already_has_ros2_control or "<ros2_control" in urdf_text:
        # The source description already declares its own hardware
        # block -- e.g. any robot built from Motus's own
        # ros2_control_macros.xacro pattern (see this module's docstring:
        # the block itself commonly lives inside a macro DEFINITION in a
        # separate xacro:include'd file, invoked from the entry file --
        # `already_has_ros2_control` is computed against the fully
        # xacro-EXPANDED robot by the caller for exactly that reason; the
        # raw-text check here is only a fallback for callers that don't
        # have that). Blindly adding a second one used to claim the same
        # joint names under a second hardware component name, which
        # corrupts ros2_control's resource manager at runtime (duplicate
        # state/command interface keys) and cascades into every
        # controller spawner failing with "'type' param was not defined"
        # -- confirmed against a real launch, not theoretical. An
        # existing block is trusted as-is; Motus does not try to
        # merge/reconcile two hardware declarations for one robot.
        return urdf_text

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
    split_at = block.index("  <ros2_control ")  # everything before it: xacro:arg/property lines
    args_only = block[:split_at].rstrip("\n") + "\n"
    rest = block[split_at:]

    urdf_text = urdf_text[:robot_tag_end] + "\n" + args_only + urdf_text[robot_tag_end:]
    close_idx = urdf_text.rfind("</robot>")  # recompute: string shifted
    return urdf_text[:close_idx] + rest + "\n" + urdf_text[close_idx:]