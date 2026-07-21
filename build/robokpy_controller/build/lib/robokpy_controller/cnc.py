#!/usr/bin/env python3
"""
Motus — CNC Machine Tending Scenario

Defines workspace geometries, joint vectors, and orchestrates the live 
manufacturing cycle. Imports the generalized MotusScriptExecutor node to 
leverage modern asyncio thread concurrency patterns.
"""

import asyncio
import threading
import rclpy
from rclpy.executors import SingleThreadedExecutor

# Import your generalized executor node definition from your local module
from robokpy_controller.script_executor import MotusScriptExecutor

# =============================================================================
# WORKSPACE GEOMETRY MAPPING — UR5e Joint Target Space Vectors (Radians)
# =============================================================================
JOINT_NAMES       = ['shoulder_pan_joint', 'shoulder_lift_joint', 'elbow_joint', 
                     'wrist_1_joint', 'wrist_2_joint', 'wrist_3_joint']

HOME_POSE         = [0.0, -1.57, 1.57, -1.57, -1.57, 0.0]
INFEED_PICK_POSE  = [0.5, -1.20, 1.80, -2.17, -1.57, 0.5]
CNC_LOAD_POSE     = [1.2, -1.00, 1.40, -1.97, -1.57, 1.2]
STANDBY_SAFE_POSE = [0.8, -1.57, 1.57, -1.57, -1.57, 0.8]


async def run_machine_tending_batch(executor: MotusScriptExecutor):
    """
    Executes a concurrent high-throughput machine tending manufacturing sequence.
    Pre-stages raw parts using background threads while the CNC machine cuts.
    """
    BATCH_SIZE = 3

    for cycle in range(BATCH_SIZE):
        executor.get_logger().info(f"=== Cycle {cycle + 1}/{BATCH_SIZE} ===")

        # ─── PHASE 1: PICK AND LOAD MATERIAL ───
        await executor.execute_trajectory_async("Approach Infeed", JOINT_NAMES, INFEED_PICK_POSE)
        await executor.execute_tool_async("gripper_1", "close", wait_duration=1.0)
        
        await executor.execute_trajectory_async("Load Into CNC Chuck", JOINT_NAMES, CNC_LOAD_POSE)
        await executor.execute_tool_async("gripper_1", "open", wait_duration=1.0)

        # ─── PHASE 2: RETREAT OUTSIDE COLLISION BOUNDARIES ───
        await executor.execute_trajectory_async("Retreat Clear of CNC Doors", JOINT_NAMES, STANDBY_SAFE_POSE)

        # ─── PHASE 3: CONCURRENT MASS PRODUCTION PIPELINE ───
        executor.get_logger().info("⚡ HIGH-THROUGHPUT MODE: Launching parallel CNC and Pre-pick loops!")
        
        # Instantiate concurrent asynchronous tasks to prevent single-queue thread starvation
        cnc_task = executor.execute_tool_async("cnc_machine", "on", wait_duration=15.0)
        robot_staging_task = executor.execute_trajectory_async("Pre-stage Next Part", JOINT_NAMES, INFEED_PICK_POSE)

        # Process both branches in parallel over the active event loop
        cnc_success, robot_success = await asyncio.gather(cnc_task, robot_staging_task)

        if cnc_success and robot_success:
            executor.get_logger().info("✅ Optimization complete: Next component staged safely while CNC was cutting.")
        else:
            executor.get_logger().error("❌ Structural failure detected during parallel execution slice!")
            break

        # ─── PHASE 4: CYCLE CLEANUP ───
        await executor.execute_trajectory_async("Deliver Finished Part to Pallet", JOINT_NAMES, HOME_POSE)
        executor.get_logger().info(f"Cycle {cycle + 1} complete.")

    executor.get_logger().info("🎉 Production batch finished processing successfully.")


def main(args=None):
    rclpy.init(args=args)
    executor_node = MotusScriptExecutor()

    # Isolate rclpy context spin loops on a separate worker thread to 
    # keep future complete signals responsive alongside asyncio loops
    ros_executor = SingleThreadedExecutor()
    ros_executor.add_node(executor_node)
    spin_thread = threading.Thread(target=ros_executor.spin, daemon=True)
    spin_thread.start()

    # Bind and trigger the main scenario loop inside Python's native event manager
    loop = asyncio.get_event_loop()
    try:
        loop.run_until_complete(run_machine_tending_batch(executor_node))
    except KeyboardInterrupt:
        pass
    finally:
        executor_node.destroy_node()
        rclpy.shutdown()
        if spin_thread.is_alive():
            spin_thread.join(timeout=1.0)

if __name__ == '__main__':
    main()
