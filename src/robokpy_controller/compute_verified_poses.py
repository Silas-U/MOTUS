#!/usr/bin/env python3
"""
compute_verified_poses.py

Prints TCP poses for a set of REAL, field-tested UR5e joint
configurations, computed via forward kinematics against YOUR OWN
robot_description — the exact same xacro processing arm.launch.py does,
and the exact same build_model()/FK path kinematic_solver.py,
robot_state_manager.py, and robot_state_interface_virtual.py already
use at runtime.

WHY THIS EXISTS: the previous orientation_verification_ur5e.yaml used
hand-derived quaternions that were never actually round-tripped through
IK — several turned out unreachable ("IK failure along blended path").
Every pose printed by this script comes FROM forward kinematics of a
known-valid joint configuration, so it is reachable by construction —
there is no guessing involved.

The joint configurations themselves are not invented either — they're
taken from a published, working UR5e + Robotiq gripper control project
(same kinematic structure as your ur5e.yaml; your gripper's actual TCP
offset is what the FK below is computed against, not theirs):
  https://github.com/IAC-Robotics-and-Sensors/UR5e_with_robotiq_gripper_control

Run from a sourced workspace:
    source install/setup.bash
    python3 compute_verified_poses.py [--arm-type ur5e]

Paste the printed YAML blocks straight into a recipe's target_pose
fields. Each one is guaranteed IK-reachable because it's the FK of a
real joint configuration for YOUR robot_description.
"""

import argparse
import os

import yaml
import xacro
from ament_index_python.packages import get_package_share_directory

from robokpy_controller.ik_factory import build_model


# Real, documented UR5e(+Robotiq) joint configurations, radians:
# [shoulder_pan, shoulder_lift, elbow, wrist_1, wrist_2, wrist_3]
#
# Deliberately diverse in wrist_2/wrist_3 (sign flips, different
# magnitudes) so the resulting TCP orientations actually differ from
# each other, not just the TCP position.
JOINT_CONFIGS = {
    'home':       (-1.571, -1.396, -2.531,  0.785,  1.571, 4.712),
    'waypoint_1': (-1.396, -2.217, -0.785, -1.658,  1.571, 3.316),
    'waypoint_2': (-3.153, -3.123, -1.074, -1.990, -1.571, 4.719),
    'waypoint_3': (-3.153, -2.628, -1.340,  0.801,  1.686, 4.633),
}


def build_robot_description(pkg: str, arm_type: str, namespace: str) -> str:
    """Mirrors arm.launch.py's configure() exactly — same xacro file,
    same mappings, same tool_type resolution from config/robots/<arm_type>.yaml
    — so the URDF this script computes FK against matches what actually
    gets deployed for this arm_type."""

    robot_xacro_file = os.path.join(pkg, 'urdf', 'robokpy_robot.urdf.xacro')
    robot_config_yaml = os.path.join(pkg, 'config', 'robots', f'{arm_type}.yaml')
    controllers_yaml_path = os.path.join(
        pkg, 'config', 'ur5e_robotiq_85_gripper_controllers.yaml')

    tool_type_str = 'none'
    if os.path.isfile(robot_config_yaml):
        with open(robot_config_yaml, 'r') as f:
            robot_cfg = yaml.safe_load(f)
        if robot_cfg:
            root_params = robot_cfg.get('/**', {}).get('ros__parameters', {})
            tool_type_str = root_params.get('tool_type', 'none')

    return xacro.process_file(
        robot_xacro_file,
        mappings={
            'prefix': '', 'arm_type': arm_type, 'gripper_type': tool_type_str,
            'sim': 'true', 'position_proportional_gain': '0.5',
            'controllers_yaml_path': controllers_yaml_path,
            'namespace': namespace,
        },
    ).toxml()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--arm-type', default='ur5e')
    parser.add_argument('--namespace', default='arm1')
    parser.add_argument('--base-link', default='world')
    parser.add_argument('--tip-link', default='tcp')
    parser.add_argument('--backend', default='robokpy')
    args = parser.parse_args()

    pkg = get_package_share_directory('robokpy_controller')
    robot_description = build_robot_description(pkg, args.arm_type, args.namespace)

    model = build_model(
        robot_description,
        base_link=args.base_link,
        tip_link=args.tip_link,
        backend=args.backend,
    )
    fk = model.fk

    print(f'# base_link={args.base_link}  tip_link={args.tip_link}  '
          f'arm_type={args.arm_type}\n')

    for name, q in JOINT_CONFIGS.items():
        fk.compute_chain(list(q), args.base_link, args.tip_link)
        pose = fk.get_pose_quart()  # [x, y, z, qx, qy, qz, qw]
        x, y, z, qx, qy, qz, qw = pose

        print(f'# {name}  (q = {list(q)})')
        print(f'{{x: {x:.4f}, y: {y:.4f}, z: {z:.4f}, '
              f'qx: {qx:.4f}, qy: {qy:.4f}, qz: {qz:.4f}, qw: {qw:.4f}}}')
        print()


if __name__ == '__main__':
    main()