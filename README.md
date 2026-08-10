# Motus v1.0

**A ROS2-native motion planning and execution framework for robotic manipulation.**

Motus bridges high-level task recipes to low-level joint control through a modular, multi-backend pipeline. It supports simulation (Gazebo) and real hardware, multiple robot arms, and pluggable inverse kinematics solvers — all selectable at runtime without code changes.

---

## Features

- **Recipe-driven execution** — YAML-based task recipes with dependency graphs
- **Multi-robot support** — One launch command switches between UR5e, myCobot 280, mechArm, or your custom arm
- **Pluggable IK backends** — RoboKpy (default), Pinocchio, or Trac-IK — selectable per robot
- **Spawned-target workflows** — No camera required; objects are spawned and tracked in simulation
- **Auto-orient gripper picking** — `use_spawn_orientation` composes object yaw with gripper-down
- **Virtual robot preview** — Full TF tree in RViz for PLANNER mode before committing to real hardware
- **Arduino prototyping ready** — Serial bridge architecture for hobby servo arms

---

## Architecture

```
┌─────────────────────────────────────────────────────────────┐
│  Recipe (YAML)                                              │
│  spawn → move → pick → place → despawn                      │
└────────────────────┬────────────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────────────┐
│  Orchestrator                                               │
│  DAG scheduler, handles retries, recovery                   │
└────────────────────┬────────────────────────────────────────┘
                     │ ExecuteMotion action
┌────────────────────▼────────────────────────────────────────┐
│  Motion Planner                                             │
│  Trajectory generation (LSPB, blend), JTC dispatch          │
└────────────────────┬────────────────────────────────────────┘
                     │ /solve_ik service
┌────────────────────▼────────────────────────────────────────┐
│  Kinematic Solver (pluggable backend)                       │
│  RoboKpy (default) │ Pinocchio │ Trac-IK                   │
└────────────────────┬────────────────────────────────────────┘
                     │ /joint_target_raw
┌────────────────────▼────────────────────────────────────────┐
│  Robot State Manager / Virtual Interface                    │
│  Joint state fusion, mode switching (PLANNER / ACTIVE)      │
└────────────────────┬────────────────────────────────────────┘
                     │
┌────────────────────▼────────────────────────────────────────┐
│  Hardware / Gazebo                                          │
│  ros2_control → JTC → real arm / sim arm                    │
└─────────────────────────────────────────────────────────────┘
```

---

## Installation

### Prerequisites

- Ubuntu 24.04
- ROS 2 Jazzy
- Python 3.12
- `colcon` build tools

### Clone and build

```bash
cd ~/ros2_ws/src
git clone <your-robokpy-repo>
git clone <your-robokpy-interfaces-repo>
git clone <your-robokpy-controller-repo>

cd ~/ros2_ws
colcon build --packages-select robokpy robokpy_interfaces robokpy_controller
source install/setup.bash
```

### Optional: Pinocchio IK backend

```bash
pip install pin --break-system-packages
```

### Optional: Trac-IK backend (Jazzy requires source build)

```bash
sudo apt install build-essential cmake libeigen3-dev liborocos-kdl-dev liburdfdom-dev pybind11-dev
cd ~/ros2_ws/src
git clone https://github.com/apmorton/trac-ik-python.git
cd trac-ik-python
git submodule update --init --recursive
pip install . --break-system-packages
```

---

## Configuration

### Base config (`config/robokpy_base.yaml`)

Solver-generic defaults. **Never edit this for a specific robot.**

```yaml
/**:
  ros__parameters:
    world_frame: world

motion_planner:
  ros__parameters:
    default_traj_type: lspb
    default_traj_method: js
    default_speed_factor: 1.0
    default_dt: 0.04
    default_blend_radius: 0.0
    enable_limit_check: True
    mask: [1, 1, 1, 1, 1, 1]
```

### Robot config (`config/robots/<arm_type>.yaml`)

Everything robot-specific lives here.

```yaml
# config/robots/mycobot_280.yaml
/**:
  ros__parameters:
    home_pose: [0.00348, 0.4913, -1.9857, -0.0808, 0.0631, -0.00349]
    marker_scale: 0.1
    tool_type: mycobot_gripper
    planning_base_link: world
    planning_tip_link: tool0

motion_planner:
  ros__parameters:
    vel_limits: [3.14, 3.14, 3.14, 3.14, 3.14, 3.14]
    acc_limits: [1.57, 1.57, 1.57, 1.57, 1.57, 1.57]
    pos_limits_lo: [-6.28, -6.28, -3.14, -6.28, -6.28, -6.28]
    pos_limits_hi: [ 6.28,  6.28,  3.14,  6.28,  6.28,  6.28]

kinematic_solver:
  ros__parameters:
    kinematic_solver_backend: pinocchio
```

| Key | Description |
|---|---|
| `home_pose` | Joint angles at startup (rad) |
| `tool_type` | End-effector type for URDF xacro |
| `planning_base_link` / `planning_tip_link` | Kinematic chain endpoints |
| `kinematic_solver_backend` | IK solver: `robokpy`, `pinocchio`, or `trac_ik` |

**Adding a new robot:** Create `config/robots/<your_arm>.yaml` with the above structure. No launch file changes needed.

---

## Launch

### Simulation

```bash
# Default (UR5e)
ros2 launch robokpy_controller motus.launch.py use_sim:=true

# myCobot 280 with Pinocchio
ros2 launch robokpy_controller motus.launch.py use_sim:=true arm_type:=mycobot_280

# Custom arm
ros2 launch robokpy_controller motus.launch.py use_sim:=true arm_type:=my_custom_arm
```

### Real hardware

```bash
ros2 launch robokpy_controller motus.launch.py use_sim:=false
```

### Startup log

```
[INFO] [motus.launch]: [Motus] arm_type=mycobot_280, tool_type=mycobot_gripper, ik_backend=pinocchio
```

---

## Recipes

Recipes are YAML task definitions consumed by the orchestrator.

```yaml
recipe_id: scattered_four_cube_stack_auto_orient_v3

steps:
  - id: spawn_target_1
    type: spawn
    type_id: cube_small
    x: 0.40
    y: 0.12
    z: 0.015
    color: red
    depends_on: []

  - id: move_home
    type: move
    traj_method: js
    target_pose: {x: 0.45, y: 0.00, z: 0.45, qx: 0.0, qy: 1.0, qz: 0.0, qw: 0.0}
    depends_on: [spawn_target_1]

  - id: pick_cube_1
    type: move
    traj_method: ts
    from_spawn_step: spawn_target_1
    use_spawn_orientation: true
    depends_on: [move_home]

  - id: grip_close
    type: tool
    tool_id: grasp_attach_1
    command: "attach:cube_small_1"
    depends_on: [pick_cube_1]
```

### Key recipe features

- **`use_spawn_orientation: true`** — Composes the object's spawn yaw with a gripper-down approach. The robot picks at the object's natural angle.
- **`blend_radius`** — Smooth corner blending between trajectory segments. Set to `0.0` for sharp corners (recommended when reaching over tall stacks).
- **`depends_on`** — DAG dependencies for parallel-safe execution.

---

## IK Backends

| Backend | Install | Best for |
|---|---|---|
| **RoboKpy** | Built-in | Default, fast, reliable for 6-DOF |
| **Pinocchio** | `pip install pin` | Analytical Jacobians, joint-limit-aware |
| **Trac-IK** | Source build (Jazzy) | Speed-focused, redundant arms |

**Backend selection** is set per-robot in `config/robots/<arm>.yaml` under `kinematic_solver.ros__parameters.kinematic_solver_backend`. If the backend is missing at runtime, Motus gracefully falls back to RoboKpy with a warning.

---

## Arduino Prototyping

Motus supports Arduino as a **motor driver layer** via serial bridge.

```
PC (Motus) → serial joint targets → Arduino → PWM servos
PC (Motus) ← serial joint feedback ← Arduino ← encoders/pots
```

**What Arduino handles:** Servo PWM, joint state feedback, gripper I/O, limit switches.
**What PC handles:** IK, trajectory planning, recipe execution, RViz visualization.

See `examples/arduino_serial_bridge/` for a sample ESP32/Arduino sketch and ROS2 bridge node.

---

## Nodes

| Node | Role |
|---|---|
| `orchestrator` | Recipe DAG execution, step dispatch |
| `motion_planner` | Trajectory generation, JTC action client |
| `kinematic_solver` | IK computation (pluggable backend) |
| `robot_state_manager` | Joint state fusion, mode/state services |
| `robot_state_interface_virtual` | Virtual robot TF publisher for PLANNER preview |
| `pose_target_interface` | Interactive marker for teach/waypoint capture |
| `safety_bridge` | E-stop, fault monitoring |
| `tool_action_server` | Gripper / grasp attach control |

---

## Troubleshooting

### `ModuleNotFoundError: No module named 'pinocchio'`
Install Pinocchio: `pip install pin --break-system-packages`. The launch will fall back to RoboKpy automatically.

### `ValueError: planning link 'tcp' not found`
Your robot YAML is missing `planning_tip_link`. Set it to the actual end-effector frame in your URDF (e.g., `tool0`).

### TF tree broken for virtual robot
`robot_state_interface_virtual` must publish **all** URDF joints, not just the active chain. The default implementation handles this automatically.

### Recipe step "delay" at high stack placements
Set `blend_radius: 0.0` on the traverse waypoint before the place descent. Blended corners struggle when reaching over existing stacks.

---

## License

Apache 2.0

## Authors

Silas Udofia and contributors.
