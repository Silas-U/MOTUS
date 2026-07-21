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

from launch.actions import SetEnvironmentVariable
from ament_index_python.packages import get_package_prefix



def generate_launch_description():

    # =========================================================
    # Launch Arguments
    # =========================================================

    robokpy_interfaces_prefix = get_package_prefix('robokpy_interfaces')
    gz_plugin_lib_path = os.path.join(robokpy_interfaces_prefix, 'lib')

    gz_plugin_path_env = SetEnvironmentVariable(
        name='GZ_SIM_SYSTEM_PLUGIN_PATH',
        value=os.pathsep.join(filter(None, [
            os.environ.get('GZ_SIM_SYSTEM_PLUGIN_PATH', ''),
            gz_plugin_lib_path,
        ]))
    )

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

    controllers_yaml_path = os.path.join(pkg, 'config', 'ur5e_robotiq_85_gripper_controllers.yaml')
    rviz_config           = os.path.join(pkg, 'config',  'config.rviz')
    robokpy_config_yaml_path = os.path.join(pkg, 'config', 'robokpy_configs.yaml')
    tool_config_path = os.path.join(pkg, 'config', 'tools.yaml')

    # =========================================================
    # URDF Loading
    # =========================================================

    urdf_real_file = os.path.join(pkg, 'urdf', 'ur5e_virtual_robotiq_85_gripper.urdf')
    urdf_sim_file  = os.path.join(pkg, 'urdf', 'ur5e_sim_robotiq_85_gripper.urdf')
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

        # robot_command_server now acts as the operator-facing Trigger-
        # service adapter, compiling into orchestrator DAG steps rather
        # than firing directly at /motion_command — internal change only,
        # this entry is unchanged.
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
                {'use_sim_time': use_sim},   # motion_planner now drives JTC directly (ExecuteMotion)
            ]
        ),

        # motion_controller REMOVED — its JTC-driving role moved into
        # motion_planner's ExecuteMotion action server; its live-jog-relay
        # role moved into virtual_jog_relay below.

        Node(
            package    = 'robokpy_controller',
            executable = 'virtual_jog_relay',
            name       = 'virtual_jog_relay',
            output     = 'screen',
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'orchestrator',
            name       = 'orchestrator',
            output     = 'screen',
            parameters = [robokpy_config_yaml_path]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'safety_bridge',
            name       = 'safety_bridge',
            output     = 'screen',
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'joint_jog_server',
            name       = 'joint_jog_server',
            output     = 'screen',
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'tool_action_server',
            name       = 'tool_action_server',
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

        gz_plugin_path_env,
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