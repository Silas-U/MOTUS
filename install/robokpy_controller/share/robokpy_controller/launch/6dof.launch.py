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
import math
import json
import tempfile
import re


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

    controllers_yaml_path = os.path.join(pkg, 'config', '6dof_controllers.yaml')
    rviz_config           = os.path.join(pkg, 'config',  'config.rviz')

    # =========================================================
    # URDF Loading
    # =========================================================

    urdf_real_file = os.path.join(pkg, 'urdf', '6dof.urdf')
    urdf_sim_file  = os.path.join(pkg, 'urdf', '6dof_sim.urdf')
    meshes_path    = os.path.join(pkg, 'meshes')

    # Real URDF — package:// URIs intact, used by:
    #   • virtual RSP  (RViz planning robot)
    #   • all Motus nodes  (kinematics, planner, controller, etc.)
    with open(urdf_real_file, 'r') as f:
        robot_description_real = f.read()

    # Sim URDF with package:// URIs — used by:
    #   • rviz_gz_robot_state_publisher  (Gazebo robot display in RViz)
    with open(urdf_sim_file, 'r') as f:
        robot_description_sim_rviz = f.read()

    robot_description_sim_gz = re.sub(
    ) 

    gz_urdf_file = os.path.join(tempfile.gettempdir(), '6dof_sim_gz.urdf')
    with open(gz_urdf_file, 'w') as f:
        f.write(robot_description_sim_gz)

    # =========================================================
    # Shared Motion Constants
    # =========================================================

    world_frame = 'world'

    home_pose = [
        math.pi / 2,
        -math.pi / 2,
        math.pi / 2,
        -math.pi / 2,
        -math.pi / 2,
        0.0
    ]

    mask = [1, 1, 1, 1, 1, 1]

    vel_limits    = [3.14, 3.14, 3.14, 3.14, 3.14, 3.14]
    acc_limits    = [1.57, 1.57, 1.57, 1.57, 1.57, 1.57]
    pos_limits_lo = [-6.28, -6.28, -3.14, -6.28, -6.28, -6.28]
    pos_limits_hi = [ 6.28,  6.28,  3.14,  6.28,  6.28,  6.28]

    # =========================================================
    # Parameter Groups
    # =========================================================

    # All Motus nodes use the real URDF for kinematics
    base_params = {'robot_description': robot_description_real}

    motion_params = {
        **base_params,
        'home_pose':   home_pose,
        'world_frame': world_frame,
    }

    planner_params = {
        **motion_params,
        'vel_limits':                   vel_limits,
        'acc_limits':                   acc_limits,
        'pos_limits_lo':                pos_limits_lo,
        'pos_limits_hi':                pos_limits_hi,
        'default_traj_type':            'lspb',
        'default_traj_method':          'js',
        'default_speed_factor':         1.0,
        'default_duration_per_segment': 3.0,
        'default_dt':                   0.02,
        'default_blend_radius':         0.0,
        'default_n_samples':            100,
        'default_n_blend':              0,
        'enable_limit_check':           True,
        'enable_continuity_check':      True,
        'abort_on_limit_violation':     False,
    }

    solver_params = {
        **motion_params,
        'mask':               mask,
        'control_rate_hz':    50.0,
        'pose_rate_limit_hz': 50.0,
    }

    controller_params = {
        **motion_params,
        'loop_rate_hz':  50.0,
        'servo_delay_s':  0.5,
    }

    state_manager_params = {
        **base_params,
        'home_pose':       home_pose,
        'publish_rate_hz': 50.0,
        'state_timeout_s':  1.0,
    }

    virtual_interface_params = {
        **base_params,
        'publish_rate_hz': 50.0,
    }

    tools_config = json.dumps({
        "gripper_1":   {"backend": "mock",       "open_delay": 0.3,  "close_delay": 3.0},
        "vacuum_1":    {"backend": "mock",       "open_delay": 0.3,  "close_delay": 0.5},
        "pneumatic_1": {"backend": "digital_io", "pin_open": 17,     "pin_close": 27,
                        "feedback_pin": 22, "open_state": "high",    "pulse_ms": 100},
        "robotiq_85":  {"backend": "modbus",     "host": "192.168.1.11", "port": 502,
                        "register_cmd": 0, "value_open": 0,          "value_close": 255},
        "vacuum_2":    {"backend": "ros_topic",  "topic": "/vacuum_controller/cmd",
                        "on_value": "on", "off_value": "off"},
    })

    # =========================================================
    # Gazebo Nodes (sim-only)
    # =========================================================

    gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare('ros_gz_sim'), 'launch', 'gz_sim.launch.py'
            ])
        ),
        launch_arguments={'gz_args': '-r empty.sdf'}.items(),
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

    # Publishes /gz_robot_description (absolute paths) for Gazebo
    # spawner and gz_ros2_control plugin.
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

    # Publishes /robot_description (package:// URIs) so RViz displays
    # the Gazebo robot model with correct meshes.
    # Driven by /joint_states from joint_state_broadcaster.
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

    # =========================================================
    # Launch Description
    # =========================================================

    return LaunchDescription([

        use_sim_arg,
        launch_rviz_arg,

        # =================================================
        # ROBOT 1 — VIRTUAL (RViz planning robot)
        # -------------------------------------------------
        # Publishes /virtual_robot_description and
        # virtual/... TF frames.
        # Driven by robot_state_interface_virtual via
        # /virtual_joint_states.
        # Used by: IK solver, planner, interactive markers,
        #          trajectory visualization.
        # =================================================
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
            parameters = [virtual_interface_params]
        ),

        # =================================================
        # MOTUS PIPELINE
        # -------------------------------------------------
        # All nodes use robot_description_real for
        # kinematics. They operate on the virtual robot
        # and forward validated trajectories to Gazebo
        # via jtc_test_bridge (sim) or robot_state_interface
        # (real hardware, to be added back when needed).
        # =================================================

        Node(
            package    = 'robokpy_controller',
            executable = 'robot_command_server',
            name       = 'robot_command_server',
            output     = 'screen'
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'robot_state_manager',
            name       = 'robot_state_manager',
            output     = 'screen',
            parameters = [state_manager_params]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'pose_target_interface',
            name       = 'pose_target_interface',
            output     = 'screen',
            parameters = [motion_params]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'kinematic_solver',
            name       = 'kinematic_solver',
            output     = 'screen',
            parameters = [solver_params]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'motion_planner',
            name       = 'motion_planner',
            output     = 'screen',
            parameters = [planner_params]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'motion_controller',
            name       = 'motion_controller',
            output     = 'screen',
            parameters = [controller_params]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'trajectory_plotter',
            name       = 'trajectory_plotter',
            output     = 'screen',
            parameters = [{
                'robot_description': robot_description_real,
                'plot_fk_path':      True,
                'dt_fallback':       0.02,
                'port':              8765,
                'history_size':      20,
            }]
        ),

        Node(
            package    = 'robokpy_controller',
            executable = 'tool_manager',
            name       = 'tool_manager',
            output     = 'screen',
            parameters = [{'tools': tools_config}]
        ),

        # =================================================
        # ROBOT 2 — GAZEBO (physics simulation)
        # -------------------------------------------------
        # gz_robot_state_publisher  → /gz_robot_description
        #   (absolute paths, for Gazebo spawn + gz_ros2_control)
        # rviz_gz_robot_state_publisher → /robot_description
        #   (package:// URIs, for RViz Gazebo robot display)
        # /joint_states from joint_state_broadcaster drives
        # rviz_gz_robot_state_publisher TF.
        # =================================================
        gz_robot_state_publisher,
        rviz_gz_robot_state_publisher,

        # =================================================
        # BRIDGE: Motus pipeline → Gazebo
        # -------------------------------------------------
        # Forwards /joint_trajectory from motion_planner
        # to arm_controller via FollowJointTrajectory action.
        # To be replaced by motion_controller integration.
        # =================================================
        Node(
            package    = 'robokpy_controller',
            executable = 'jtc_test_bridge',
            name       = 'jtc_test_bridge',
            output     = 'screen',
            condition  = IfCondition(use_sim)
        ),

        # =================================================
        # RVIZ2
        # -------------------------------------------------
        # config.rviz should have two RobotModel displays:
        #   1. Topic: /virtual_robot_description
        #      TF Prefix: virtual/
        #      Alpha: 0.5  (semi-transparent planning robot)
        #   2. Topic: /robot_description
        #      TF Prefix: (none)
        #      Alpha: 1.0  (solid Gazebo robot)
        # =================================================
        Node(
            package    = 'rviz2',
            executable = 'rviz2',
            name       = 'rviz2',
            output     = 'screen',
            arguments  = ['-d', rviz_config],
            condition  = IfCondition(launch_rviz)
        ),

        # =================================================
        # GAZEBO (sim-only)
        # =================================================
        gazebo,
        gz_clock_bridge,
        spawn_entity,

        # Spawner chain:
        #   entity spawned → JSB → arm_controller
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
    ])