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
- [Motus CLI: robot projects](#motus-cli-robot-projects)
- [Robot models](#robot-models)
- [Motion planning](#motion-planning)
- [Safe start and elbow-up posture](#safe-start-and-elbow-up-posture)
- [Tools and objects](#tools-and-objects)
- [ROS2 architecture](#ros2-architecture)
- [Recipes](#recipes)
- [Simulation](#simulation)
- [Multi-arm cells](#multi-arm-cells)
- [Safety and manual control](#safety-and-manual-control)
- [Requirements](#requirements)
- [Known issues](#known-issues)
- [Contributing](#contributing)

## Synopsis

Motus provides ROS2 components for:

- Serial robot arm configuration
- A CLI (`motus`) that turns a manufacturer robot description into a ready-to-launch project
- Forward and inverse kinematics (RoboKpy or Pinocchio backends)
- Cartesian and joint-space motion planning
- MoveJ and MoveL motion
- Trajectory generation and waypoint blending
- Singularity-aware safe start and a consistent elbow-up posture
- Robot state and execution management
- Tool and I/O actions, including gripper attachment from a manufacturer description
- Object spawning and attachment in simulation
- Recipe-based task execution with offline validation
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

## Motus CLI: robot projects

The `motus` command builds a project around a robot you already have a description for, without copying Motus itself. A project is a thin ROS2 package (URDF/xacro, meshes, `robot.yaml`, `controllers.yaml`, `tools.yaml`, launch wrapper, RViz config) that consumes the core Motus packages, so core improvements reach existing projects.

```bash
motus create project my_cell
cd my_cell

# import a robot description (any serial arm; --arg is forwarded to xacro)
motus robot add /path/to/Universal_Robots_ROS2_Description \
  --arg name=ur15 --arg ur_type=ur15 \
  --arg joint_limit_params=/path/to/config/ur15/joint_limits.yaml \
  --arg kinematics_params=/path/to/config/ur15/default_kinematics.yaml \
  --arg physical_params=/path/to/config/ur15/physical_parameters.yaml \
  --arg visual_params=/path/to/config/ur15/visual_parameters.yaml

# attach a gripper from its manufacturer description
motus tool add /path/to/robotiq_description --profile robotiq_2f_85 \
  --replace --align-approach --tcp-offset 0 0 0.145

motus doctor          # validate what is on disk, without changing anything
motus build           # doctor-gated colcon build of the project package
motus launch --sim    # or --real
```

| Command | What it does |
|---|---|
| `motus create project <name>` | Scaffold a project; `--from <path>` imports a robot in the same step |
| `motus robot add <path>` | Import or replace the robot description: parse, resolve resources, copy meshes, generate `robot.yaml` and `controllers.yaml`, and inject the `ros2_control` / Gazebo blocks the vendor URDF lacks |
| `motus tool add / list / remove` | Manage end-effectors. Tool config lives between `MOTUS-TOOL-BEGIN/END` markers; anything outside is yours |
| `motus world init / status / diff` | Give the project its own Gazebo world and `recipes/` folder, and compare it with the core world |
| `motus doctor [--verbose]` | Check package layout, URDF parsing, mesh resources, link/joint names, config files and their types, and controller joint names |
| `motus build` | Run `doctor`, then `colcon build` the project (no `--symlink-install`) |
| `motus launch --sim / --real` | Source the parent workspace, then the project overlay, and launch the cell |

What the importer handles for you:

- **Any serial arm.** Joint chain, limits, and the TCP are derived from the description.
- **xacro arguments** are stored in `motus.json` and reused by `doctor`, `build`, and `launch`.
- **Mesh and YAML package references** are rewritten for the new package, including mesh paths embedded in vendor YAML files.
- **Missing pieces** are repaired: `ros2_control` and Gazebo plugin blocks are injected, and a massless root link gets a safe default only where Gazebo needs it.
- **Upright spawn pose.** The robot spawns upright and straight, clear of the floor, and `home_pose` in `robot.yaml` stays editable.
- **Ready pose.** A bent, well-conditioned `ready_pose` is written next to `home_pose` (see [Safe start](#safe-start-and-elbow-up-posture)).
- **Tool profiles.** `--profile robotiq_2f_85` supplies known gripper settings. They never override what the description itself says.

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
- Pluggable IK backends: `robokpy` and `pinocchio` (`kinematic_solver_backend` / `ik_backend`)
- Automatic IK retry from fallback seeds when the primary seed fails
- Preferred-posture bias and joint-limit clamping for recipe planning

Motion segments can carry boundary velocity and acceleration information so that consecutive segments can be joined without unnecessarily stopping the robot at every waypoint.

The ROS2 layer receives the resulting trajectory and handles execution through the configured robot controller.

## Safe start and elbow-up posture

Robots spawn upright and fully stretched, which is a kinematic singularity. Seeding IK from a singular pose picks an arbitrary elbow/wrist branch, which shows up as sudden sweeps and elbow up/down flips. Motus avoids this in three layers:

1. **Singularity check.** `KinematicsFacade.min_singular_value()` is the smallest singular value of the length-scaled Jacobian, so one threshold (`singular_sigma_min`, default `0.05`) works for a 0.3 m desktop arm and a 1.3 m UR15 alike.
2. **Ready pose.** If a plan starts from a singular pose, the planner first adds a joint-space S-curve to a `ready_pose` (a bent, non-singular posture) and plans every leg from there. The ready pose is also the IK seed and posture bias while the home pose is singular.
3. **Elbow-up branch.** A ready pose must be elbow-up and reach in front of the base, because planning from an elbow-down pose collides with the base and table. `arm_executor` rejects a configured `ready_pose` on the wrong branch, warns, and derives a replacement.

Where the ready pose comes from:

- **The builder** writes `ready_pose` into `robot.yaml` for every robot it generates (`motus_cli/builder/safe_pose.py`).
- **The runtime** derives one at startup when `robot.yaml` has none and `home_pose` is singular (`robokpy_controller/ready_pose.py`). It logs the pose, its elbow height, forward reach, and `sigma_min`, so you can pin it in `robot.yaml`.
- The two searches share one design; keep them in sync when changing either.

A healthy, user-chosen `home_pose` keeps working exactly as before. The ready pose only takes over when `home_pose` is singular.

Related executor behaviour:

- A leading leg the arm is already at (for example `move_home` when re-running a recipe with the arm parked at home) is skipped instead of failing the run.
- Duplicate poses between recipe legs still abort, because they would collapse to zero-length segments and corrupt blending.

The checks are kinematic only (joint frames and tool above the floor). They do not check for collisions with your cell, so verify the ready pose before running on hardware.

## Tools and objects

### Tools

`tool_action_server` loads the tools in `tools.yaml` and exposes them to recipe `tool` steps. Backends:

| Backend | Use |
|---|---|
| `gripper_action` | Gripper via the ros2_control gripper action controller (mimic joints handled by the controller) |
| `gripper_position` / `gripper_effort` | Position- or effort-driven gripper joints |
| `digital_io` | GPIO outputs (pneumatic tools, relays) |
| `modbus` | Modbus TCP register writes (needs `pymodbus`) |
| `ros_topic` | Publishes to a hardware driver topic |
| `mock` | Stand-in when there is no hardware |
| `grasp_attach` | Simulation grasp: closes the gripper and welds the object to the gripper link |

`grasp_attach` supports two mechanisms: `parallel_jaw` (closes to a width scaled to the object's size) and `suction`. Engage and disengage run in the background so the arm does not pause at each pick and place.

Gripper settings in `tools.yaml` use plain keys (`action_name`, `joint_name`, `open_position`, `closed_position`, `max_effort`, `action_timeout`, `min_close_ratio`). The older `gripper_`-prefixed spellings are still accepted.

### Objects

Objects are a catalog (`objects.yaml`) of types and instances. The pipeline is:

```text
objects.yaml + object_catalog
        │
        ▼
object_spawner  (Gazebo spawn / despawn, DetachableJoint handshake)
        │
        ▼
grasp_attach_bridge  ──►  object_pose_resolver
        │
        ▼
tool_action_server (grasp_attach)
```

Recipes can reference a spawned object's pose with `from_spawn_step`, optionally with `use_spawn_orientation`, so grasp poses follow where an object was actually spawned. The grasp approach offset comes from the catalog.

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
- Object management (spawner, pose resolver, grasp-attach bridge)
- Tool action server
- Safety bridge
- Named resource locks for cross-arm contention
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
joint_jog_server
```

and the required controller interfaces. `arm_executor` plans a whole motion run in one call and sends it to the controller as a single trajectory goal, and `execution_monitor` confirms arrival from encoder state rather than relying on action results alone.

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

The recipe is parsed and validated before execution. `preflight_recipe` runs the same compile, grouping, and pose-resolution steps without moving the robot, so structural mistakes and unreachable or duplicate poses are caught beforehand.

Motion steps are pose-only by design: there is no joint-target step, so continuity between legs is never broken by arbitrary joint configurations. Manual joint control lives in `joint_jog_server`, deliberately unreachable from recipes.

`Docs/motus_recipe_authoring_guid.MD` explains the step types, `js` vs `ts` trajectory methods, blending, and how to write a recipe that behaves as expected on the first try.

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

A recipe can be run again straight away; legs the arm is already at are skipped.

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

## Safety and manual control

- **`safety_bridge`** republishes the cell's safety signal as `/safety_state` for the orchestrator. It is read-only with respect to safety and currently uses a **placeholder** hardware read; wire it to real safety I/O before using real hardware.
- **`joint_jog_server`** provides direct manual joint control (calibration, teaching, override), outside the recipe DAG.
- **`resource_lock`** is a plain named mutex for shared zones or tools between arms.
- **Vision** steps are a foundation only; there is no production vision backend yet.

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
| Pinocchio (`pin`) | Optional | Alternative IK backend |
| `colcon`, `just` | Optional | `motus build` uses `colcon`; `just` runs common launch commands |

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