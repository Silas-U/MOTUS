from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'robokpy_controller'

setup(
name=package_name,
version='0.0.0',
packages=find_packages(exclude=['test']),
data_files=[
    ('share/ament_index/resource_index/packages',
        ['resource/' + package_name]),

    ('share/' + package_name,
        ['package.xml']),

    (os.path.join('share', package_name, 'launch'),
glob('launch/*.launch.py')),

    (os.path.join('share', package_name, 'config'),
glob('config/*.rviz') + glob('config/*.yaml')),

    (os.path.join('share', package_name, 'data_files'),
glob('data_files/*.rviz') + glob('data_files/*.yaml')),

    (os.path.join('share', package_name, 'urdf'),
glob('urdf/*.urdf')),

    (os.path.join('share', package_name, 'worlds'),
glob('worlds/*.sdf')),

    (os.path.join('share', package_name, 'recipes'),
glob('robokpy_controller/recipes/*.yaml')),

    (os.path.join('share', package_name, 'meshes', 'ur5e', 'visual'),
glob('meshes/ur5e/visual/*')),

    (os.path.join('share', package_name, 'meshes', 'ur5e', 'collision'),
glob('meshes/ur5e/collision/*')),

    (os.path.join('share', package_name, 'meshes', 'robotiq_85_gripper_meshes', 'visual'),
glob('meshes/robotiq_85_gripper_meshes/visual/*')),

    (os.path.join('share', package_name, 'meshes', 'robotiq_85_gripper_meshes', 'collision'),
glob('meshes/robotiq_85_gripper_meshes/collision/*')),
    
(os.path.join('share', package_name, 'meshes', 'mycobot_280_m5', 'visual'),
glob('meshes/mycobot_280_m5/visual/*')),

    (os.path.join('share', package_name, 'meshes', 'mycobot_280_m5', 'collision'),
glob('meshes/mycobot_280_m5/collision/*')),

(os.path.join('share', package_name, 'meshes', 'mecharm_270_pi', 'visual'),
glob('meshes/mecharm_270_pi/visual/*')),

    (os.path.join('share', package_name, 'meshes', 'mecharm_270_pi', 'collision'),
glob('meshes/mecharm_270_pi/collision/*')),


],


install_requires=['setuptools'],
zip_safe=True,
maintainer='meta',
maintainer_email='silasudofia469@gmail.com',
description='TODO: Package description',
license='TODO: License declaration',
tests_require=['pytest'],
entry_points={
'console_scripts': [
'pose_target_interface = robokpy_controller.pose_target_interface:main',
'kinematic_solver = robokpy_controller.kinematic_solver:main',
'robot_command_server = robokpy_controller.robot_command_server:main',
'motion_planner = robokpy_controller.motion_planner:main',
'robot_state_interface_virtual = robokpy_controller.robot_state_interface_virtual:main',
'robot_state_manager = robokpy_controller.robot_state_manager:main',
'robot_description_viewer = robokpy_controller.robot_description_viewer:main',
'trajectory_plotter = robokpy_controller.trajectory_plotter:main',
'kinematics_server = robokpy_controller.kinematics_server:main',
# --- new for the event-driven architecture ---
'tool_action_server = robokpy_controller.tool_action_server:main',
'orchestrator = robokpy_controller.orchestrator:main',
'virtual_jog_relay = robokpy_controller.virtual_jog_relay:main',
'safety_bridge = robokpy_controller.safety_bridge:main',
'joint_jog_server = robokpy_controller.joint_jog_server:main',
'grasp_attach_bridge = robokpy_controller.grasp_attach_bridge:main',
'object_spawner = robokpy_controller.object_spawner:main',
'object_pose_resolver = robokpy_controller.object_pose_resolver:main',
        ],
    },
)