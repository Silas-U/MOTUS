# ultraArm_P1

Generated Motus robot project. This package carries this robot's URDF,
meshes and configuration only -- all planning, kinematics and execution
logic comes from the `robokpy_controller` / `robokpy` packages in your
Motus workspace; this package depends on them rather than duplicating them.

## Layout

- `urdf/` -- this robot's URDF/xacro and meshes
- `config/robot.yaml` -- robot-specific parameters (joint limits, planning
  frames, IK backend) -- same shape as robokpy_controller's
  `config/robots/<arm_type>.yaml`
- `config/controllers.yaml` -- ros2_control controller configuration
- `launch/ultraArm_P1.launch.py` -- thin wrapper around robokpy_controller's
  `arm.launch.py`
- `rviz/` -- optional default RViz config

## Build & run

```
colcon build --packages-select ultraarm_p1_motus
source install/setup.bash
ros2 launch ultraarm_p1_motus ultraArm_P1.launch.py use_sim:=true
```

Run `motus doctor` from the workspace root first if this is a fresh or
hand-edited project.
