# Motus — run commands
# Install `just`: https://github.com/casey/just
# Usage: just <recipe>

pkg := "robokpy_controller"

# --- Single-arm (reproduces old motus_launch.py behavior) ---

# Single arm, Gazebo sim, default UR5e + gripper controllers, RViz on
single-arm-sim:
    ros2 launch {{pkg}} cell.launch.py use_sim:=true

# Single arm, real hardware
single-arm-real:
    ros2 launch {{pkg}} cell.launch.py use_sim:=false

# Single arm, sim, no RViz (headless / CI-style run)
single-arm-sim-headless:
    ros2 launch {{pkg}} cell.launch.py use_sim:=true launch_rviz:=false

# Single arm, sim, non-default arm type / controllers yaml
single-arm-sim-custom arm_type controllers_yaml:
    ros2 launch {{pkg}} cell.launch.py use_sim:=true arm_type:={{arm_type}} controllers_yaml:={{controllers_yaml}}

# --- Multi-arm cell ---

# Multi-arm cell, sim, arms defined in config/cell_arms.yaml
cell-sim:
    ros2 launch {{pkg}} cell.launch.py use_sim:=true arms_config:=config/cell_arms.yaml

# Multi-arm cell, real hardware
cell-real:
    ros2 launch {{pkg}} cell.launch.py use_sim:=false arms_config:=config/cell_arms.yaml

# Multi-arm cell, sim, custom arms config path
cell-sim-custom arms_config:
    ros2 launch {{pkg}} cell.launch.py use_sim:=true arms_config:={{arms_config}}

# --- Individual arm include (debugging one arm in isolation — not normally run directly) ---

# NOTE: arm.launch.py assumes it's included by cell.launch.py (no Gazebo world,
# no shared cell services). Running it alone in sim will spawn into whatever
# world is already up, or fail if none is running.
arm-only-debug namespace="arm1" arm_type="ur5e":
    ros2 launch {{pkg}} arm.launch.py namespace:={{namespace}} arm_type:={{arm_type}} use_sim:=true

# --- Recipes (pick-and-place YAML scripts run through the orchestrator) ---

# Set an arm's system mode to ACTIVE (required before running any recipe)
activate namespace="arm1":
    ros2 service call {{namespace}}/set_system_mode robokpy_interfaces/srv/SystemMode "{new_mode: 'ACTIVE'}"

# Run a recipe YAML. Activates the arm first, then dispatches the recipe.
run-recipe recipe namespace="arm1":
    just activate {{namespace}}
    ros2 run {{pkg}} run_recipe {{recipe}}

# --- Utility ---

# Tail all node logs for the most recent launch
logs:
    ros2 launch --show-args {{pkg}} cell.launch.py 2>&1 | tee /tmp/motus_last_launch.log

# List active nodes (sanity check after launch)
ps:
    ros2 node list

# List active TF frames (sanity check for the TF issue class)
tf-frames:
    ros2 run tf2_tools view_frames
