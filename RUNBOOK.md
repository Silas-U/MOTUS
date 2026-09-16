# Motus Runbook

Living doc, not a README. This is for you, mid-debug, at 11pm. Update it
whenever you fix something you'd otherwise re-debug from scratch next time.

## Quick start

```
just single-arm-sim     # one arm, Gazebo, RViz — the default dev loop
just cell-sim           # multi-arm, from config/cell_arms.yaml
just ps                 # sanity-check nodes after launch
just tf-frames          # sanity-check TF tree
```

Full recipe list: `justfile` at repo root, or `just --list`.

## Launch file map

- `cell.launch.py` — the entry point you actually run. Once-per-cell: Gazebo
  world, object pipeline, `safety_bridge`, `tool_action_server`, `rviz2`,
  `cell_orchestrator`. Includes `arm.launch.py` once per arm in `arms_config`
  (empty `arms_config` = single-arm mode, reproduces the old
  `motus_launch.py` exactly).
- `arm.launch.py` — never launched directly in normal use. Once-per-arm:
  URDF/xacro, controller spawners, full robokpy_controller node stack
  (`kinematic_solver`, `robot_state_manager`, `pose_target_interface`,
  `robot_state_interface_virtual`, `robot_command_server`, `arm_executor`,
  `virtual_jog_relay`, `joint_jog_server`), all under `namespace=`.

## Subsystem status (update as things move)

**Considered solid — don't touch without strong reason:**
- IK solvers / kinematic_solver
- trajectory generators (industrial_trajectory.py — TOPP + general S-curve,
  boundary-velocity support)
- object catalogue pipeline (spawn/attach/detach)

**Actively in flux:**
- Orchestration layer — mid-rebuild, moved from single-arm
  orchestrator_v2.py design to layered cell_orchestrator + per-arm
  arm_executor. Migration plan: single-arm parity via existing test
  recipes first, then second-arm namespace + resource-lock contention test.
- Trajectory look-ahead — step 4 (real one-step lookahead) done; step 5
  (PLANNED/COMMITTED/EXECUTED states + replanning) not started.
- Gripper integration — Robotiq 2F-85 on UR5e, PD-control approach settled,
  YAML config migration to per-node files under `configs/` in progress.

## Running a recipe

System mode must be set to `ACTIVE` before running any recipe — the
orchestrator won't dispatch otherwise:

```
ros2 service call arm1/set_system_mode robokpy_interfaces/srv/SystemMode "{new_mode: 'ACTIVE'}"
ros2 run robokpy_controller run_recipe test0.yaml
```

Or via `just run-recipe test0.yaml` (does both steps in order).

## Known gotchas (already root-caused — don't re-debug these)

- **Namespace leaks via leading-slash names**: `tool_action_server.py` and
  `grasp_attach_bridge.py` run unnamespaced at cell level. Any hardcoded
  leading-slash topic/service/action name in them (or in the
  robokpy_controller nodes inside `arm.launch.py` — unconfirmed, worth a
  grep) will collide across arms. Fixed pattern: keep names relative,
  explicitly prefix only genuinely per-arm targets in `tools.yaml`
  (e.g. `arm1/gripper_action_controller/gripper_cmd`).
- **Object-catalog Gazebo plugin**: embedded in only the *first* arm's URDF
  in `arms_config` (`embed_object_catalog_plugin`), on the unconfirmed
  assumption it's world-level. Flip to per-arm if `grasp_attach_bridge`/
  `object_spawner` turn out to expect otherwise.
- **TF errors on launch that vanish on relaunch**: usually a stale
  half-started process from a previous run, not a real wiring bug — kill
  and relaunch Gazebo/RViz before deep-diving TF trees.
- **Sim tree has no `world` anchor for the rviz/sim robot_description**
  (as opposed to the virtual stack, which has an explicit
  `virtual_world_bridge` static transform). If `robokpy_robot.urdf.xacro`
  doesn't define a `world` root link/joint, RViz will show a real missing
  transform for `/arm1/robot_description` — add a
  `static_transform_publisher` for that tree too, don't touch the URDF's
  virtual side.
- **DDS goal-response loss**: motion goals hard-serialized per-arm now
  (motion_planner rejects concurrent goals) after several
  "Ignoring unexpected goal response" incidents.
- **`spin_until_future_complete` re-entrancy**: never call it from inside a
  callback (regardless of executor) — caused the despawn_target deadlock.
  Poll-based `_wait_for_future` is the fix pattern already in use.

## Open questions (not yet resolved, don't assume either way)

1. Do all robokpy_controller nodes use fully relative internal names? Needs
   a grep across node sources for leading-slash topic/service/action names
   before trusting `namespace=` to fully isolate two arms.
2. Should the object-catalog plugin be per-arm instead of first-arm-only?

## TODO for this runbook

- Add per-directory one-paragraph notes for `config/robots/`, orchestrator
  layer, trajectory generators once the current rebuild settles.
