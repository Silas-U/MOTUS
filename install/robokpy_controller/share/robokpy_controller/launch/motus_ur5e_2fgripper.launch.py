from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    RegisterEventHandler,
    IncludeLaunchDescription,
)
from launch.conditions import IfCondition, UnlessCondition
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

import os
import json
import tempfile
import yaml


def generate_launch_description():

    # =========================================================
    # Launch Arguments
    # =========================================================

    use_sim_arg = DeclareLaunchArgument(
        'use_sim',
        default_value='false',
        description='Use Gazebo simulation instead of real hardware'
    )

    launch_rviz_arg = DeclareLaunchArgument(
        'launch_rviz',
        default_value='true',
        description='Launch RViz2'
    )

    use_sim     = LaunchConfiguration('use_sim')
    launch_rviz = LaunchConfiguration('launch_rviz')

    # =========================================================
    # Package Paths
    # =========================================================

    pkg = FindPackageShare('robokpy_controller').find('robokpy_controller')

    controllers_yaml_path = os.path.join(pkg, 'config', 'ur5e_2fgripper_controllers.yaml')
    rviz_config           = os.path.join(pkg, 'config',  'config.rviz')
    robokpy_config_yaml_path = os.path.join(pkg, 'config', 'robokpy_configs.yaml')
    tool_config_path = os.path.join(pkg, 'config', 'tools.yaml')

    # =========================================================
    # URDF Loading
    # =========================================================

    urdf_real_file = os.path.join(pkg, 'urdf', 'ur5e_virtual_2fgripper.urdf')
    urdf_sim_file  = os.path.join(pkg, 'urdf', 'ur5e_sim_2fgripper.urdf')
    meshes_path    = os.path.join(pkg, 'meshes')

    with open(urdf_real_file, 'r') as f:
        robot_description_real = f.read()

    with open(urdf_sim_file, 'r') as f:
        robot_description_sim_rviz = f.read()

    robot_description_sim_gz = robot_description_sim_rviz.replace(
        'package://robokpy_controller/meshes', meshes_path
    ).replace(
        'CONTROLLERS_YAML_PATH', controllers_yaml_path
    )

    gz_urdf_file = os.path.join(tempfile.gettempdir(), 'ur5e_sim_gz.urdf')
    with open(gz_urdf_file, 'w') as f:
        f.write(robot_description_sim_gz)

    world_frame = 'world'  # only needed here for the static TF publisher below

    # =========================================================
    # tool_manager exception
    # -------------------------------------------------
    # 'tools' isn't a set of typed ROS2 parameters — it's an
    # arbitrary per-tool JSON blob consumed as a single string
    # param. Native ros__parameters files can't express that
    # shape, so configs/tools.yaml stays a plain YAML dict,
    # parsed here and passed as one JSON string param.
    # =========================================================

    with open(tool_config_path, 'r') as f:
        tools_config = json.dumps(yaml.safe_load(f))

    # =========================================================
    # Gazebo Nodes (sim-only)
    # =========================================================

    world_file = os.path.join(pkg, 'worlds', 'motus_world.sdf')

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'), 'launch', 'gz_sim.launch.py'
            ])
        ),
        launch_arguments={'gz_args': f' -r {world_file}'}.items(),
        condition=IfCondition(use_sim)
    )

    gz_clock_bridge = Node(
        package    = 'ros_gz_bridge',
        executable = 'parameter_bridge',
        name       = 'gz_clock_bridge',
        output     = 'screen',
        arguments  = ['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
        condition  = IfCondition(use_sim)
    )

    gz_robot_state_publisher = Node(
        package    = 'robot_state_publisher',
        executable = 'robot_state_publisher',
        name       = 'gz_robot_state_publisher',
        parameters = [
            {'robot_description': robot_description_sim_gz},
            {'use_sim_time': True},
        ],
        remappings = [('/robot_description', '/gz_robot_description')],
        condition  = IfCondition(use_sim)
    )

    spawn_entity = Node(
        package    = 'ros_gz_sim',
        executable = 'create',
        name       = 'spawn_robot',
        output     = 'screen',
        arguments  = [
            '-name',  'ur_robot',
            '-topic', 'gz_robot_description',
            '-x', '0.0', '-y', '0.0', '-z', '0.0',
        ],
        condition  = IfCondition(use_sim)
    )

    rviz_gz_robot_state_publisher = Node(
        package    = 'robot_state_publisher',
        executable = 'robot_state_publisher',
        name       = 'rviz_gz_robot_state_publisher',
        parameters = [
            {'robot_description': robot_description_sim_rviz},
            {'use_sim_time': True},
        ],
        condition  = IfCondition(use_sim)
    )

    joint_state_broadcaster_spawner = Node(
        package    = 'controller_manager',
        executable = 'spawner',
        name       = 'joint_state_broadcaster_spawner',
        output     = 'screen',
        arguments  = [
            'joint_state_broadcaster',
            '--controller-manager', '/controller_manager',
            '--controller-manager-timeout', '30',
        ],
        condition  = IfCondition(use_sim)
    )

    arm_controller_spawner = Node(
        package    = 'controller_manager',
        executable = 'spawner',
        name       = 'arm_controller_spawner',
        output     = 'screen',
        arguments  = [
            'arm_controller',
            '--controller-manager', '/controller_manager',
            '--controller-manager-timeout', '30',
        ],
        condition  = IfCondition(use_sim)
    )

    # Gripper — spawned after arm_controller so both real ros2_control
    # command interfaces (arm position/velocity, gripper position) are
    # registered on the resource manager before either controller
    # claims them.
    gripper_action_controller_spawner = Node(
        package    = 'controller_manager',
        executable = 'spawner',
        output     = 'screen',
        name       = 'gripper_action_controller_spawner',
        arguments  = ['gripper_action_controller', '--controller-manager', '/controller_manager',
                  '--controller-manager-timeout', '30'],
        condition  = IfCondition(use_sim)
    )

    # =========================================================
    # Launch Description
    # =========================================================

    return LaunchDescription([

        use_sim_arg,
        launch_rviz_arg,

        Node(
            package    = 'robot_state_publisher',
            executable = 'robot_state_publisher',
            name       = 'virtual_robot_state_publisher',
            parameters = [{
                'robot_description': robot_description_real,
                'frame_prefix':      'virtual/',
            }],
            remappings = [
                ('/joint_states',      '/virtual_joint_states'),
                ('/robot_description', '/virtual_robot_description'),
            ]
        ),

        Node(
            package    = 'tf2_ros',
            executable = 'static_transform_publisher',
            name       = 'virtual_world_bridge',
            arguments  = ['0', '0', '0', '0', '0', '0',
                          world_frame, 'virtual/world']
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'robot_state_interface_virtual',
            name       = 'robot_state_interface_virtual',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'robot_command_server',
            name       = 'robot_command_server',
            output     = 'screen',
            parameters  =  [robokpy_config_yaml_path]  
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'robot_state_manager',
            name       = 'robot_state_manager',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'pose_target_interface',
            name       = 'pose_target_interface',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'kinematic_solver',
            name       = 'kinematic_solver',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'motion_planner',
            name       = 'motion_planner',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'motion_controller',
            name       = 'motion_controller',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
                {'use_sim_time': use_sim},   # LaunchConfiguration, resolves True/False
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'trajectory_plotter',
            name       = 'trajectory_plotter',
            output     = 'screen',
            parameters = [
                robokpy_config_yaml_path,
                {'robot_description': robot_description_real},
            ]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'tool_manager',
            name       = 'tool_manager',
            output     = 'screen',
            parameters = [{'tools': tools_config}]
        ),

        gz_robot_state_publisher,
        rviz_gz_robot_state_publisher,

        Node(
            package    = 'rviz2',
            executable = 'rviz2',
            name       = 'rviz2',
            output     = 'screen',
            arguments  = ['-d', rviz_config],
            condition  = IfCondition(launch_rviz)
        ),

        Node(
            package = 'robokpy_controller',
            executable = 'kinematics_server',
            name = 'kinematics_services',
            parameters = [robokpy_config_yaml_path,
                {'robot_description': robot_description_real}
            ]
        ),

        gazebo,
        gz_clock_bridge,
        spawn_entity,

        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[joint_state_broadcaster_spawner],
            )
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=joint_state_broadcaster_spawner,
                on_exit=[arm_controller_spawner],
            )
        ),
        RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=arm_controller_spawner,
                on_exit=[gripper_action_controller_spawner],
            )
        ),
    ])