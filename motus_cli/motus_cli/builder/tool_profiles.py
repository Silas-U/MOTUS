"""
tool_profiles.py

Known manufacturer tool profiles for `motus tool add --profile <key>`.

A profile never REPLACES what the description says (joint names, limits,
TCP geometry are always read from the real URDF by tool_add.py). It only
supplies things a URDF cannot express: which macro to use from a bundled
source, the operating targets and controller tuning that were proven in
simulation, and -- importantly -- an empirical grasp calibration that is
only valid for ONE specific TCP definition (see reference_tcp_offset).

Values here were taken from the configs already proven in Motus's own sim
(robokpy_controller/config/tools.yaml, ur5e_robotiq_85_gripper_controllers.yaml,
objects.yaml). Adding a new manufacturer tool means adding one entry.
"""

from __future__ import annotations

from dataclasses import dataclass, field


@dataclass(frozen=True)
class ToolProfile:
    key: str
    display_name: str
    kind: str                       # 'parallel_gripper' (only kind implemented so far)
    # Where to find the description when --from is not given: searched under
    # <parent_workspace_root>/src/*/ using these relative globs.
    macro_relpath_hint: str
    mesh_root_hint: str
    macro_name: str
    # Operating targets proven in sim for THIS description (joint units).
    open_position: float
    closed_position: float
    max_effort: float
    # GripperActionController params (parallel_gripper_action_controller).
    controller: dict = field(default_factory=dict)
    # Empirical grasp offset (m) measured with reference_tcp_offset; only
    # applied when the imported TCP matches that reference within tolerance.
    approach_offset: float = 0.0
    reference_tcp_offset: tuple[float, float, float] | None = None
    notes: str = ""


_CONTROLLER_DEFAULTS = {
    "action_monitor_rate": 20.0,
    "goal_tolerance": 0.01,
    "allow_stalling": True,
    "stall_velocity_threshold": 0.001,
    "stall_timeout": 0.3,
}

PROFILES: dict[str, ToolProfile] = {
    "robotiq_2f_85": ToolProfile(
        key="robotiq_2f_85",
        display_name="Robotiq 2F-85",
        kind="parallel_gripper",
        macro_relpath_hint="urdf/macros/robotiq_85_macro.xacro",
        mesh_root_hint="",
        macro_name="robotiq_85_gripper",
        # robokpy_controller/config/tools.yaml gripper_1 (proven in sim).
        # NOTE: the joint's physical upper limit is 0.804 rad; 0.154 is the
        # closing target that gives a firm grasp on the catalog cubes.
        open_position=0.001,
        closed_position=0.154,
        max_effort=5.0,
        controller={**_CONTROLLER_DEFAULTS, "max_effort": 5.0},
        approach_offset=0.0507,
        reference_tcp_offset=(0.0, 0.0, 0.104),
        notes=(
            "Targets, effort and approach_offset were measured with Motus's "
            "bundled robotiq_85_macro.xacro (TCP 0.104 m from the flange). "
            "approach_offset is only applied when the imported TCP matches."
        ),
    ),
}


def get_profile(key: str | None) -> ToolProfile | None:
    if not key:
        return None
    try:
        return PROFILES[key]
    except KeyError:
        raise ValueError(
            f"unknown tool profile '{key}'. Known profiles: {', '.join(sorted(PROFILES))}"
        ) from None


def generic_controller_params(max_effort: float) -> dict:
    return {**_CONTROLLER_DEFAULTS, "max_effort": max_effort}
