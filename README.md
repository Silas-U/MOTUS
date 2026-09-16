# Motus

*Motion planning, without the babysitting.*
**ROS2 motion planning and control for UR-series robot arms — single-arm or multi-arm cells, sim or real hardware.**

[![ROS2](https://img.shields.io/badge/ROS2-Jazzy-blue)](https://docs.ros.org/en/jazzy/) [![Python](https://img.shields.io/badge/python-3.12-blue)](https://www.python.org/) [![Gazebo](https://img.shields.io/badge/Gazebo%20Sim-8.x-orange)](https://gazebosim.org/) [![Status](https://img.shields.io/badge/status-active--development-yellow)]()

Motus is built on **RoboKpy**, a kinematics library handling IK/FK, trajectory generation (TOPP + general S-curve), and multi-arm cell orchestration. It targets pick-and-place workflows in Gazebo simulation and on real UR-series hardware, with the same recipe YAML running on both.

---

## Contents

- [Synopsis](#synopsis)
- [Requirements](#requirements)
- [Getting going](#getting-going)
- [Quick example](#quick-example)
- [Architecture](#architecture)
- [Running recipes](#running-recipes)
- [Known issues](#known-issues)
- [Contributing](#contributing)

## Synopsis

Motus provides:

- A **layered orchestration architecture** — a cell orchestrator handling DAG dispatch, arm registry, and resource locks, talking to one namespaced **arm executor** per arm (plan → execute → confirm), so adding a second arm to a cell is a config change, not a code change.
- **Full object pipeline** for pick-and-place: spawn/attach/detach via Gazebo, grasp-pose composition from a bounded object catalog, tool backends (pneumatic, digital I/O, Modbus, ROS topic, grasp-attach).
- **Trajectory generation** with real boundary-velocity continuity through waypoints (TOPP for Cartesian, general asymmetric S-curve for joint-space) — motion doesn't stop dead at every intermediate point.
- **Recipes as YAML** — pick-and-place sequences (MoveStep, ToolStep, IOStep, WaitStep, VisionStep, SpawnStep) compiled and validated, then dispatched by the orchestrator. Consecutive move steps are automatically blended into one merged motion.
- Both a **virtual planning robot** (RViz2) and a **physics robot** (Gazebo / real hardware), kept in sync.

Motus favors code that's straightforward to read and extend over micro-optimized cleverness — if you're debugging a motion issue at 2am, you should be able to follow the flow, not decode it. See [`RUNBOOK.md`](RUNBOOK.md) for the operational side of that philosophy.

## Requirements

| Dependency | Version | Notes |
|---|---|---|
| ROS2 | Jazzy | Developed and tested against this distro |
| Python | 3.12 | Matches Jazzy's bundled interpreter |
| Gazebo Sim | 8.x | Only required for `use_sim:=true` |
| `xacro` | ROS2-provided | URDF processing |
| `ros_gz_sim`, `ros_gz_bridge` | ROS2-provided | Sim-only; spawning, clock, topic bridging |
| `ros2_control`, `controller_manager` | ROS2-provided | Controller spawning (joint state broadcaster, arm controller, gripper) |
| `tf2_ros` | ROS2-provided | Virtual-world static transform |
| RoboKpy | bundled | Proprietary kinematics backend — ships with `robokpy_controller` |

Real-hardware runs (`use_sim:=false`) don't need Gazebo or `ros_gz_*` at all — those nodes are gated behind `IfCondition(use_sim)` in `arm.launch.py`/`cell.launch.py`.

## Getting going

```bash
git clone <this repo>
cd motus
# build as a standard ROS2 workspace
colcon build
source install/setup.bash
```

### Using `just`

Named launch recipes live in the [`justfile`](justfile) — install [`just`](https://github.com/casey/just) once, then:

```bash
just single-arm-sim     # one arm, Gazebo + RViz — the default dev loop
just cell-sim           # multi-arm cell, from config/cell_arms.yaml
just ps                 # sanity-check nodes after launch
```

Run `just --list` for the full set.

## Quick example

Launch a single arm in simulation:

```bash
ros2 launch robokpy_controller cell.launch.py use_sim:=true
```

This brings up the Gazebo world, spawns the arm (default: UR5e + Robotiq gripper), starts the full node stack under the `arm1` namespace, and opens RViz. Check it came up clean:

```bash
ros2 node list
ros2 run tf2_tools view_frames
```

Once it's up, activate the arm and run a recipe (see [Running recipes](#running-recipes) below).

## Architecture

Two launch files, each with one job:

| File | Scope | Responsibility |
|---|---|---|
| `cell.launch.py` | Once per cell | Gazebo world, shared object pipeline, `safety_bridge`, `tool_action_server`, RViz, `cell_orchestrator`. **This is the file you run.** |
| `arm.launch.py` | Once per arm | URDF/xacro, controller spawners, that arm's full RoboKpy node stack (`kinematic_solver`, `robot_state_manager`, `pose_target_interface`, `arm_executor`, etc.), all under `namespace=`. Included by `cell.launch.py` — not normally run directly. |

Arms are declared in a YAML file (`arms_config`, see `config/cell_arms.yaml`) listing each arm's namespace, type, and spawn pose. An empty `arms_config` launches exactly one arm — today's single-arm commands keep working unchanged as the cell grows.

## Running recipes

A recipe is a YAML pick-and-place sequence. Before running one, the target arm's system mode must be set to `ACTIVE`:

```bash
ros2 service call arm1/set_system_mode robokpy_interfaces/srv/SystemMode "{new_mode: 'ACTIVE'}"
ros2 run robokpy_controller run_recipe test0.yaml
```

Or in one step:

```bash
just run-recipe test0.yaml
```

## Known issues

Operational gotchas (namespace collisions, TF anchoring, DDS retry behavior, and current open questions) are tracked in [`RUNBOOK.md`](RUNBOOK.md), not here — that file is kept current as issues are found and fixed, so it's the source of truth rather than this README.

## Contributing

Motus is under active development; the orchestration layer in particular is mid-rebuild. If you're picking this up:

1. Read `RUNBOOK.md` first — it lists what's considered stable vs. actively in flux.
2. Run `just single-arm-sim` and confirm `pick_place_v1.yaml` executes cleanly before touching orchestration code.
3. Open an issue or PR describing the change before a large rewrite — several subsystems here have already been rebuilt once after over-engineering; smaller, reviewable changes are preferred going forward.

---

*Motus is an independent project. RoboKpy is a proprietary kinematics library developed alongside it; this repository (`robokpy_controller`) is the open-source ROS2 integration layer around it.*
