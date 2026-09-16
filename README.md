# Motus

*Motion planning, without the babysitting.*

**ROS2 motion planning and control for UR-series robot arms — single-arm or multi-arm, simulation or real hardware.**

[![ROS2](https://img.shields.io/badge/ROS2-Jazzy-blue)](https://docs.ros.org/en/jazzy/) [![Python](https://img.shields.io/badge/python-3.12-blue)](https://www.python.org/) [![Gazebo](https://img.shields.io/badge/Gazebo%20Sim-8.x-orange)](https://gazebosim.org/) [![Status](https://img.shields.io/badge/status-active--development-yellow)]()

Motus is a ROS2 robotics framework I'm building around **RoboKpy**, my kinematics and motion-planning library.

The idea is pretty simple: make it easier to go from designing a robot motion to actually running it, whether the robot is in Gazebo or connected to real hardware.

The same recipe can be used in simulation and on the real robot, which makes testing and development a lot easier.

---

## Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
- [Quick Example](#quick-example)
- [Architecture](#architecture)
- [Running Recipes](#running-recipes)
- [Known Issues](#known-issues)
- [Contributing](#contributing)

## Overview

Motus currently handles a few main things:

- **Multi-arm cell management** — a cell orchestrator handles task dispatch, arm registration, and resource locking. Each arm runs its own namespaced arm executor. Adding another arm should mostly be a configuration change rather than a rewrite of the system.

- **Pick-and-place workflows** — objects can be spawned, attached, and detached in Gazebo. Grasp poses are generated from a small object catalog, and tools can be controlled through different backends such as pneumatic tools, digital I/O, Modbus, ROS topics, or Gazebo grasp/attach.

- **Motion planning** — trajectories can be generated in Cartesian or joint space, including blended motion between waypoints. The goal is to keep the robot moving through a sequence instead of stopping at every point.

- **YAML recipes** — robot tasks are described as YAML files using steps such as `MoveStep`, `ToolStep`, `IOStep`, `WaitStep`, `VisionStep`, and `SpawnStep`. The recipe is validated and then executed by the cell orchestrator.

- **Planning and execution views** — Motus keeps a virtual planning robot in RViz2 alongside the actual physics robot in Gazebo, or the real robot when running on hardware.

I'm trying to keep the code relatively straightforward. There is a lot going on in a robotics system already, so I'd rather have code that is easy to follow and debug than something that is overly clever.

For the more practical details and current issues, see [`RUNBOOK.md`](RUNBOOK.md).

## Requirements

| Dependency | Version | Notes |
|---|---|---|
| ROS2 | Jazzy | Developed and tested against this distro |
| Python | 3.12 | Matches the Jazzy environment |
| Gazebo Sim | 8.x | Only required when `use_sim:=true` |
| `xacro` | ROS2-provided | URDF processing |
| `ros_gz_sim`, `ros_gz_bridge` | ROS2-provided | Simulation only |
| `ros2_control`, `controller_manager` | ROS2-provided | Controller management |
| `tf2_ros` | ROS2-provided | TF support |
| RoboKpy | bundled | Kinematics and motion-planning backend |

When running on real hardware with `use_sim:=false`, Gazebo and the `ros_gz_*` packages are not needed. The simulation-specific nodes are only started when simulation is enabled.

## Getting Started

Clone the repository and build it like a normal ROS2 workspace:

```bash
git clone <this repo>

cd motus

colcon build

source install/setup.bash
```

### Using `just`

I use [`just`](https://github.com/casey/just) for some of the common commands.

After installing it, you can run:

```bash
just single-arm-sim     # one arm, Gazebo + RViz
just cell-sim           # multi-arm cell
just ps                 # check running nodes
```

Run:

```bash
just --list
```

to see all available commands.

## Quick Example

To launch a single arm in simulation:

```bash
ros2 launch robokpy_controller cell.launch.py use_sim:=true
```

This starts the Gazebo world, spawns the robot, starts the controllers and Motus nodes, and opens RViz.

The default setup uses a UR5e with a Robotiq gripper.

You can check that the system is running with:

```bash
ros2 node list

ros2 run tf2_tools view_frames
```

Once everything is up, set the arm to `ACTIVE` and run a recipe.

## Architecture

Motus is split into a cell-level part and an arm-level part.

### `cell.launch.py`

This is the main launch file and is normally the one you run.

It handles things shared by the whole cell, including:

- Gazebo
- Object spawning and management
- `safety_bridge`
- `tool_action_server`
- RViz
- `cell_orchestrator`

### `arm.launch.py`

This is used once for each arm.

It handles that arm's:

- URDF/xacro
- Controllers
- Kinematic solver
- Robot state manager
- Pose target interface
- Arm executor
- Other RoboKpy nodes

Each arm runs inside its own namespace.

For example:

```text
/arm1/...
/arm2/...
```

The arms are defined in a YAML configuration file such as:

```text
config/cell_arms.yaml
```

Each entry specifies things like the arm namespace, robot type, and spawn position.

The goal is that going from one arm to multiple arms doesn't require changing the actual motion code.

## Running Recipes

A recipe is simply a YAML file describing what the robot should do.

Before running a recipe, the target arm needs to be in `ACTIVE` mode:

```bash
ros2 service call arm1/set_system_mode robokpy_interfaces/srv/SystemMode "{new_mode: 'ACTIVE'}"
```

Then run the recipe:

```bash
ros2 run robokpy_controller run_recipe test0.yaml
```

Or use the `just` command:

```bash
just run-recipe test0.yaml
```

A recipe can contain different types of steps, for example:

```yaml
MoveStep
ToolStep
IOStep
WaitStep
VisionStep
SpawnStep
```

Consecutive movement steps can also be blended together so the robot doesn't unnecessarily stop between every move.

## Known Issues

I'm keeping most of the current operational issues in [`RUNBOOK.md`](RUNBOOK.md) rather than filling this README with troubleshooting notes.

That includes things like:

- Namespace issues
- TF problems
- DDS/retry behaviour
- Simulation quirks
- Things that are currently being worked on

The RUNBOOK is intended to be the more up-to-date reference for these.

## Contributing

Motus is still under active development, and some parts of the orchestration system are currently being rebuilt.

If you're working on the project, I'd recommend:

1. Read `RUNBOOK.md` first so you know what is stable and what is still changing.

2. Run:

```bash
just single-arm-sim
```

and make sure the basic pick-and-place example works before changing the orchestration layer.

3. For larger changes, open an issue or PR first. A few parts of the system have already gone through major rewrites, so I'm trying to keep future changes smaller and easier to review.

---

*Motus is an independent project. RoboKpy is a proprietary kinematics library developed alongside it. This repository (`robokpy_controller`) is the ROS2 integration layer built around RoboKpy.*