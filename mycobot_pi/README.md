# mycobot_pi

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
- `launch/mycobot_pi.launch.py` -- thin wrapper around robokpy_controller's
  `arm.launch.py`
- `rviz/` -- optional default RViz config

## Build & run

```
colcon build --packages-select mycobot_pi_motus
source install/setup.bash
ros2 launch mycobot_pi_motus mycobot_pi.launch.py use_sim:=true
```

Run `motus doctor` from the workspace root first if this is a fresh or
hand-edited project.
