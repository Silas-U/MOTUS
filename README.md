# Motus

**ROS2 framework for motion planning and control of serial robotic arms**

[![ROS2](https://img.shields.io/badge/ROS2-Jazzy-blue)](https://docs.ros.org/en/jazzy/) [![Python](https://img.shields.io/badge/python-3.12-blue)](https://www.python.org/) [![Gazebo](https://img.shields.io/badge/Gazebo%20Sim-8.x-orange)](https://gazebosim.org/) [![Status](https://img.shields.io/badge/status-active--development-yellow)]()

Motus is a ROS2 framework for planning, simulating, and executing motion for serial robotic arms.

It is built on top of **RoboKpy**, which provides the underlying kinematics and trajectory generation.

The system is designed to work with different serial robot configurations rather than being tied to a particular robot manufacturer. Robot descriptions, joint configuration, controllers, and hardware interfaces are handled separately from the motion planning and orchestration layers.

Motus can be used with Gazebo simulation or real hardware, using the same planning and recipe interfaces in both cases.

---

## Contents

- [Synopsis](#synopsis)
- [Getting going](#getting-going)
- [Robot models](#robot-models)
- [Motion planning](#motion-planning)
- [ROS2 architecture](#ros2-architecture)
- [Recipes](#recipes)
- [Simulation](#simulation)
- [Multi-arm cells](#multi-arm-cells)
- [Requirements](#requirements)
- [Known issues](#known-issues)
- [Contributing](#contributing)

## Synopsis

Motus provides ROS2 components for:

- Serial robot arm configuration
- Forward and inverse kinematics
- Cartesian and joint-space motion planning
- MoveJ and MoveL motion
- Trajectory generation and waypoint blending
- Robot state and execution management
- Tool and I/O actions
- Object spawning and attachment in simulation
- Recipe-based task execution
- Single-arm and multi-arm operation
- Gazebo simulation and real hardware execution

The motion planning layer is provided by RoboKpy. Motus handles the ROS2 side of the system: nodes, interfaces, execution, controllers, tools, simulation, and coordination between multiple components.

The intention is to keep the robot model independent from the rest of the system. A serial arm can be introduced by providing the required robot description, joint configuration, controller interface, and planning parameters.

## Getting going

Motus is developed and tested with ROS2 Jazzy.

Clone the repository and build it as a normal ROS2 workspace:

```bash
git clone <this repo>

cd motus

colcon build

source install/setup.bash
```

### Using `just`

Common development and launch commands are provided through the `justfile`.

```bash
just single-arm-sim
just cell-sim
just ps
```

Run:

```bash
just --list
```

to see the available commands.

## Robot models

Motus is not limited to UR-series robots.

The planning stack works with **serial robotic arms** described through the interfaces expected by RoboKpy and the ROS2 control stack.

A robot configuration generally consists of:

- Robot description / URDF
- Joint names and ordering
- Joint limits
- Kinematic parameters
- Controller configuration
- Spawn configuration for simulation
- Hardware interface for real operation

The robot-specific configuration is kept separate from the cell orchestration and recipe layers.

This makes it possible to use the same motion and execution infrastructure with different robot arms.

## Motion planning

RoboKpy provides the kinematic and trajectory-generation backend used by Motus.

Current motion functionality includes:

- Forward kinematics
- Inverse kinematics
- Jacobian calculation
- Joint-space trajectory generation
- Cartesian trajectory generation
- MoveJ
- MoveL
- LSPB trajectories
- Quintic trajectories
- S-curve trajectories
- TOPP-based Cartesian trajectories
- Joint and Cartesian limits
- Waypoint blending

Motion segments can carry boundary velocity and acceleration information so that consecutive segments can be joined without unnecessarily stopping the robot at every waypoint.

The ROS2 layer receives the resulting trajectory and handles execution through the configured robot controller.

## ROS2 architecture

Motus is split into cell-level and arm-level components.

### Cell

The cell layer contains components that are shared by the complete robot cell.

The main entry point is:

```text
cell.launch.py
```

It is responsible for components such as:

- Cell orchestrator
- Object management
- Tool action server
- Safety bridge
- RViz
- Gazebo integration when simulation is enabled

### Arm

Each robot arm runs its own set of nodes under a ROS2 namespace.

The arm is configured through:

```text
arm.launch.py
```

The arm stack includes nodes such as:

```text
kinematic_solver
robot_state_manager
pose_target_interface
arm_executor
```

and the required controller interfaces.

For a two-arm cell, the resulting ROS2 graph can be organized as:

```text
/arm1/...
/arm2/...
```

This keeps state, motion commands, controllers, and execution state isolated between arms.

### Launch configuration

The arms in a cell are defined in YAML.

The current example configuration is:

```text
config/cell_arms.yaml
```

An arm entry contains information such as its namespace, robot type, and spawn position.

The cell launch file uses this configuration to create the required arm instances.

## Recipes

Motus provides a YAML-based recipe interface for describing robot tasks.

A recipe can contain operations such as:

```text
MoveStep
ToolStep
IOStep
WaitStep
VisionStep
SpawnStep
```

For example:

```yaml
steps:
  - MoveStep
  - ToolStep
  - MoveStep
  - SpawnStep
  - MoveStep
```

The recipe is parsed and validated before execution.

Motion steps are passed to the motion planning layer, while tool, I/O, and object operations are handled by their respective interfaces.

Consecutive motion steps can be blended into a continuous trajectory where the motion constraints allow it.

To execute a recipe, first set the target arm to `ACTIVE`:

```bash
ros2 service call \
  arm1/set_system_mode \
  robokpy_interfaces/srv/SystemMode \
  "{new_mode: 'ACTIVE'}"
```

Then:

```bash
ros2 run robokpy_controller run_recipe test0.yaml
```

or:

```bash
just run-recipe test0.yaml
```

## Simulation

Gazebo is used for physics simulation and hardware-independent development.

Start the default single-arm simulation with:

```bash
ros2 launch robokpy_controller cell.launch.py use_sim:=true
```

The simulation launch starts the configured robot, controllers, Gazebo world, Motus nodes, and RViz.

The same planning and recipe interfaces are used when running against real hardware. Simulation-specific nodes are enabled only when:

```text
use_sim:=true
```

is set.

This keeps the motion planning and task-level code independent from the simulation backend.

## Multi-arm cells

Motus supports multiple serial arms in the same ROS2 cell.

Each arm has its own namespace and execution stack, while the cell orchestrator handles tasks that involve shared resources.

For example:

```text
Cell
├── arm1
│   ├── kinematic_solver
│   ├── robot_state_manager
│   ├── pose_target_interface
│   └── arm_executor
│
├── arm2
│   ├── kinematic_solver
│   ├── robot_state_manager
│   ├── pose_target_interface
│   └── arm_executor
│
├── cell_orchestrator
├── tool_action_server
└── object_manager
```

The goal is to keep the arm implementation reusable while allowing the cell layer to coordinate multiple robots.

## Requirements

| Dependency | Version | Notes |
|---|---|---|
| ROS2 | Jazzy | Development and test platform |
| Python | 3.12 | Required runtime |
| Gazebo Sim | 8.x | Required for simulation |
| `xacro` | ROS2-provided | Robot description processing |
| `ros_gz_sim` | ROS2-provided | Gazebo integration |
| `ros_gz_bridge` | ROS2-provided | ROS2/Gazebo communication |
| `ros2_control` | ROS2-provided | Robot control interface |
| `controller_manager` | ROS2-provided | Controller management |
| `tf2_ros` | ROS2-provided | Transform handling |
| RoboKpy | Bundled | Kinematics and trajectory generation |

Gazebo and the `ros_gz_*` packages are not required when running against real hardware.

## Example workflow

A typical development workflow is:

```text
Robot description
       │
       ▼
Robot configuration
       │
       ▼
RoboKpy
(Kinematics + Planning)
       │
       ▼
Motus ROS2 interfaces
       │
       ▼
Arm Executor
       │
       ▼
ros2_control
       │
       ▼
Robot
```

For a complete cell:

```text
                 ┌─── Arm 1 ───► Controller ───► Robot
                 │
Recipe ─► Cell ──┼─── Arm 2 ───► Controller ───► Robot
                 │
                 ├─── Tools
                 └─── Objects
```

## Known issues

Current implementation notes and operational issues are maintained in:

```text
RUNBOOK.md
```

This includes information about:

- ROS2 namespaces
- TF configuration
- Controller behaviour
- DDS communication
- Gazebo issues
- Hardware integration
- Current development work

The RUNBOOK is intended to be the operational reference for the project.

## Contributing

Motus is under active development.

If you are working on the project, start with:

```bash
just single-arm-sim
```

and verify the basic simulation before changing the planning or orchestration layers.

For larger changes, open an issue or pull request so the proposed change can be discussed before restructuring an existing subsystem.

---

## Related projects

**RoboKpy**

RoboKpy is the kinematics and trajectory-generation library used by Motus.

Motus provides the ROS2 integration and execution layer around it.

## License

Motus is an independent project.

RoboKpy is a proprietary kinematics library developed alongside Motus. This repository contains the ROS2 integration layer and associated tools for robot configuration, motion execution, simulation, and cell orchestration.