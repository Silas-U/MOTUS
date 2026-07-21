# Motus

An open-source, industrial-grade ROS2 motion planning and control pipeline for UR-series robot arms, built around a custom Python kinematics library, **RoboKpy**.

Motus separates *planning* from *execution*: a virtual planning robot (RViz2) lets you teach and validate trajectories with zero risk, while a physically simulated robot (Gazebo) executes only what's been explicitly approved — a workflow modeled on how real industrial cells protect expensive hardware from invalid motion.

---

## Features

- **Two-robot architecture** — a virtual planning robot (`virtual/` TF prefix, RViz2 only) and a physics-simulated robot (Gazebo, via `gz_ros2_control`), kept deliberately isolated by a `PLANNER` / `ACTIVE` system-mode gate.
- **Custom kinematics engine (RoboKpy)** — Rodrigues'-formula FK, damped pseudoinverse IK with warm-start self-seeding, joint normalization, and a full trajectory layer (LSPB trapezoidal profiles, corner blending, continuity/limit validation).
- **Segment-based trajectory execution** — trajectories are split at tool-action waypoints and sent to the real controller as individual `FollowJointTrajectory` goals via `ros2_control`'s `JointTrajectoryController`, so the arm cleanly stops for tool actions and resumes without re-planning.
- **Tool action framework** — a `ToolManager` node supporting `mock`, `digital_io` (GPIO), `ros_topic`, and `modbus` backends, with per-waypoint tool actions (open/close/on/off) and configurable wait conditions (`time`, `topic`, `none`).
- **Human-in-the-loop teaching** — record waypoints live via an interactive marker on the virtual robot, attach tool actions, and build multi-step sequences through a JSON `/command_sequence` interface (with a CLI helper, `sequence_pub`).
- **Kinematics REST API + dashboard** — a FastAPI service (`/kinematics/fk`, `/ik`, `/jacobian`, `/reachable`, `/chain_fk`) and a live trajectory-inspection dashboard (Plotly.js + Cytoscape.js).
- **Velocity-controlled trajectory tracking** — position + velocity feedforward on the `JointTrajectoryController`, matching production UR driver behavior.

---

## Architecture

```
Interactive Marker (RViz2)
        │
        ▼
pose_target_interface ──► kinematic_solver ──► motion_planner
                                                     │
                                     ┌───────────────┴───────────────┐
                                     ▼                                ▼
                          /joint_trajectory                 /trajectory_tool_actions
                                     │                                │
                                     ▼                                │
                            motion_controller ◄───────────────────────┘
                                     │
                        ┌────────────┴─────────────┐
                        ▼                            ▼
              PLANNER mode                    ACTIVE mode
        (local virtual interpolation)   (FollowJointTrajectory → JTC → Gazebo)
                        │                            │
                        ▼                            ▼
            robot_state_interface_virtual      gz_ros2_control / joint_state_broadcaster
                        │                            │
                        └──────────┬─────────────────┘
                                   ▼
                          robot_state_manager
                    (single source of truth, gated by system_mode)
```

**Key safety principle:** `motion_controller` only ever sends a real `FollowJointTrajectory` goal to Gazebo/hardware in `ACTIVE` mode. In `PLANNER` mode it drives the virtual robot through the exact same trajectory timing locally — trajectories can be fully taught and validated with the real robot never moving.

---

## Requirements

- ROS2 Jazzy
- Gazebo Harmonic (`ros-jazzy-ros-gz-sim`)
- Python 3.12
- RoboKpy (bundled kinematics/trajectory library)
- `gpiozero` (optional, only required for `digital_io` tool backend)
- `pymodbus` (optional, only required for `modbus` tool backend)

---

## Quick Start

```bash
colcon build --packages-select robokpy_controller
source install/setup.bash

# Launch full pipeline (virtual + Gazebo)
ros2 launch robokpy_controller motus.launch.py use_sim:=True
```

By default the system boots in `PLANNER` mode — the virtual robot is fully interactive, Gazebo is untouched.

### Basic teaching workflow

```bash
# 1. Drag the interactive marker in RViz2 to a target pose, then record it:
ros2 run robokpy_controller sequence_pub --record

# 2. Repeat for each waypoint. Attach a tool action to the last recorded waypoint:
ros2 run robokpy_controller sequence_pub --record-tool gripper_1 close time 0.5

# 3. Move to the drop pose, then release:
ros2 run robokpy_controller sequence_pub --record-tool gripper_1 open time 0.5

# 4. Preview the trajectory on the virtual robot only (safe, no hardware risk):
ros2 run robokpy_controller sequence_pub --execute

# 5. When satisfied, switch to the real Gazebo robot and execute for real:
ros2 run robokpy_controller sequence_pub --active-mode
ros2 run robokpy_controller sequence_pub --execute
```

See `sequence_pub.py --help` for the full list of shortcuts (`--go-home`, `--movel`, `--movej`, `--speed-full/half/quarter`, `--set-approach`, `--goto-approach`, etc.), or pass a full JSON step array via `--json`/`--file` for scripted/repeatable sequences.

---

## Known Limitations (Initial Release)

- Velocity control is feedforward-only (trajectory tracking), not yet a direct jogging/teleop mode.
- `digital_io` and `modbus` tool backends require hardware not present in this sim-only release; they fail gracefully to a warning at boot if unreachable.
- Collision geometry in the demo arm uses primitive shapes, not full UR mesh geometry — visually simplified for simulation performance.
- No BehaviorTree.CPP integration yet; sequencing is JSON-step based (`/command_sequence`), intended as a stepping stone toward a future BT layer.

---

## License

TBD.
