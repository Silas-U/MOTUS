from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    RegisterEventHandler,
    IncludeLaunchDescription,
    TimerAction,
    OpaqueFunction,
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
import xacro

from launch.actions import SetEnvironmentVariable
from ament_index_python.packages import get_package_prefix
from robokpy_controller.object_catalog import ObjectCatalog


def generate_launch_description():

    # =========================================================
    # Environment & Arguments
    # =========================================================

    rmw_env = SetEnvironmentVariable('RMW_IMPLEMENTATION', 'rmw_cyclonedds_cpp')

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

    arm_type_arg = DeclareLaunchArgument(
        'arm_type',
        default_value='ur5e',
        description='Robot arm type (e.g., ur5e, mycobot_280, mecharm)'
    )

    controllers_yaml_arg = DeclareLaunchArgument(
        'controllers_yaml',
        default_value='ur5e_robotiq_85_gripper_controllers.yaml',
        description='Controller configuration YAML filename inside config/'
    )

    use_sim     = LaunchConfiguration('use_sim')
    launch_rviz = LaunchConfiguration('launch_rviz')
    arm_type    = LaunchConfiguration('arm_type')
    controllers_yaml = LaunchConfiguration('controllers_yaml')

    # =========================================================
    # Package Paths (static)
    # =========================================================

    pkg = FindPackageShare('robokpy_controller').find('robokpy_controller')

    rviz_config           = os.path.join(pkg, 'config',  'config.rviz')
    robokpy_base_yaml     = os.path.join(pkg, 'config', 'robokpy_base.yaml')
    tool_config_path      = os.path.join(pkg, 'config', 'tools.yaml')
    objects_config_path   = os.path.join(pkg, 'config', 'objects.yaml')

    catalog = ObjectCatalog(objects_config_path)

    robot_xacro_file = os.path.join(pkg, 'urdf', 'robokpy_robot.urdf.xacro')
    meshes_path = os.path.join(pkg, 'meshes')

    prefix = ''
    world_frame = 'world'

    with open(tool_config_path, 'r') as f:
        tools_dict = yaml.safe_load(f)

    for tool_id, cfg in tools_dict.items():
        if cfg.get('backend') == 'grasp_attach':
            cfg.setdefault('parent_model', catalog.parent_model)
            cfg.setdefault('parent_link', catalog.parent_link)
            cfg.setdefault('objects_catalog_path', objects_config_path)

    tools_config = json.dumps(tools_dict)

    world_file = os.path.join(pkg, 'worlds', 'motus_world.sdf')

    # =========================================================
    # OpaqueFunction: resolves launch args, builds descriptions
    # =========================================================

    def configure(context):
        arm_type_str     = arm_type.perform(context)
        controllers_yaml_str = controllers_yaml.perform(context)

        controllers_yaml_path = os.path.join(pkg, 'config', controllers_yaml_str)
        robot_config_yaml     = os.path.join(pkg, 'config', 'robots', f'{arm_type_str}.yaml')

        # --- Resolve tool_type and ik_backend from robot YAML ---
        tool_type_str = 'none'
        backend_str = 'robokpy'
        if os.path.isfile(robot_config_yaml):
            with open(robot_config_yaml, 'r') as f:
                robot_cfg = yaml.safe_load(f)
            if robot_cfg:
                root_params = robot_cfg.get('/**', {}).get('ros__parameters', {})
                tool_type_str = root_params.get('tool_type', 'none')
                ks_params = robot_cfg.get('kinematic_solver', {}).get('ros__parameters', {})
                backend_str = ks_params.get('kinematic_solver_backend', 'robokpy')

        import launch.logging
        logger = launch.logging.get_logger('motus.launch')
        logger.info(
            f'[Motus] arm_type={arm_type_str}, tool_type={tool_type_str}, '
            f'ik_backend={backend_str}'
        )

        # --- Helper to build parameter list for robokpy nodes ---
        def _robokpy_params(extra=None):
            params = [
                robokpy_base_yaml,
                robot_config_yaml,
            ]
            if extra is not None:
                params.append(extra)
            params.append({'kinematic_solver_backend': backend_str})
            return params

        # --- URDF Loading ---
        # xacro expects 'gripper_type' internally; map tool_type to it
        robot_description_sim_rviz = xacro.process_file(
            robot_xacro_file,
            mappings={
                'prefix': prefix,
                'arm_type': arm_type_str,
                'gripper_type': tool_type_str,
                'sim': 'true',
                'position_proportional_gain': '0.1',
                'controllers_yaml_path': controllers_yaml_path,
            },
        ).toxml()

        robot_description_sim_gz = robot_description_sim_rviz.replace(
            'package://robokpy_controller/meshes', meshes_path
        )

        robot_description_sim_gz = robot_description_sim_gz.replace(
            '</robot>', catalog.to_gazebo_plugin_sdf() + '\n</robot>'
        )

        gz_urdf_file = os.path.join(tempfile.gettempdir(), 'robot_sim_gz.urdf')
        with open(gz_urdf_file, 'w') as f:
            f.write(robot_description_sim_gz)

        robot_description_real = xacro.process_file(
            robot_xacro_file,
            mappings={
                'prefix': prefix,
                'arm_type': arm_type_str,
                'gripper_type': tool_type_str,
                'sim': 'true',
                'position_proportional_gain': '0.5',
                'controllers_yaml_path': controllers_yaml_path,
            },
        ).toxml()

        # --- Gazebo Nodes (sim-only) ---
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

        grasp_attach_gz_bridge = Node(
            package    = 'ros_gz_bridge',
            executable = 'parameter_bridge',
            name       = 'grasp_attach_gz_bridge',
            output     = 'screen',
            arguments  = catalog.to_ros_gz_bridge_args(),
            condition  = IfCondition(use_sim)
        )

        grasp_attach_bridge_node = Node(
            package    = 'robokpy_controller',
            executable = 'grasp_attach_bridge',
            name       = 'grasp_attach_bridge',
            output     = 'screen',
            parameters = [{'objects_config_path': objects_config_path}],
            condition  = IfCondition(use_sim)
        )

        entity_management_gz_bridge = Node(
            package    = 'ros_gz_bridge',
            executable = 'parameter_bridge',
            name       = 'entity_management_gz_bridge',
            output     = 'screen',
            arguments  = [
                '/world/motus_world/create@ros_gz_interfaces/srv/SpawnEntity',
                '/world/motus_world/remove@ros_gz_interfaces/srv/DeleteEntity',
            ],
            condition  = IfCondition(use_sim)
        )

        object_spawner_node = Node(
            package    = 'robokpy_controller',
            executable = 'object_spawner',
            name       = 'object_spawner',
            output     = 'screen',
            parameters = [{
                'objects_config_path': objects_config_path,
                'world_name': 'motus_world',
            }],
            condition  = IfCondition(use_sim)
        )

        object_pose_gz_bridge = Node(
            package    = 'ros_gz_bridge',
            executable = 'parameter_bridge',
            name       = 'object_pose_gz_bridge',
            output     = 'screen',
            arguments  = [
                '/world/motus_world/dynamic_pose/info@tf2_msgs/msg/TFMessage[gz.msgs.Pose_V',
            ],
            condition  = IfCondition(use_sim)
        )

        object_pose_resolver_node = Node(
            package    = 'robokpy_controller',
            executable = 'object_pose_resolver',
            name       = 'object_pose_resolver',
            output     = 'screen',
            parameters = [{'objects_config_path': objects_config_path}],
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

        gripper_action_controller_spawner = Node(
            package    = 'controller_manager',
            executable = 'spawner',
            output     = 'screen',
            name       = 'gripper_action_controller_spawner',
            arguments  = ['gripper_action_controller', '--controller-manager', '/controller_manager',
                      '--controller-manager-timeout', '30'],
            condition  = IfCondition(use_sim)
        )

        # --- Core Nodes ---
        virtual_robot_state_publisher = Node(
            package    = 'robot_state_publisher',
            executable = 'robot_state_publisher',
            name       = 'virtual_robot_state_publisher',
            parameters = [{
                'robot_description': robot_description_real,
                'frame_prefix':      'virtual/',
                'use_sim_time':      use_sim,
            }],
            remappings = [
                ('/joint_states',      '/virtual_joint_states'),
                ('/robot_description', '/virtual_robot_description'),
            ]
        )

        virtual_world_bridge = Node(
            package    = 'tf2_ros',
            executable = 'static_transform_publisher',
            name       = 'virtual_world_bridge',
            arguments  = ['0', '0', '0', '0', '0', '0',
                          world_frame, 'virtual/world']
        )

        robot_state_interface_virtual = Node(
            package    = 'robokpy_controller',
            executable = 'robot_state_interface_virtual',
            name       = 'robot_state_interface_virtual',
            output     = 'screen',
            parameters = _robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        robot_command_server = Node(
            package    = 'robokpy_controller',
            executable = 'robot_command_server',
            name       = 'robot_command_server',
            output     = 'screen',
            parameters = _robokpy_params({'use_sim_time': use_sim}),
        )

        robot_state_manager = Node(
            package    = 'robokpy_controller',
            executable = 'robot_state_manager',
            name       = 'robot_state_manager',
            output     = 'screen',
            parameters = _robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        pose_target_interface = Node(
            package    = 'robokpy_controller',
            executable = 'pose_target_interface',
            name       = 'pose_target_interface',
            output     = 'screen',
            parameters = _robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        kinematic_solver = Node(
            package    = 'robokpy_controller',
            executable = 'kinematic_solver',
            name       = 'kinematic_solver',
            output     = 'screen',
            parameters = _robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        motion_planner = Node(
            package    = 'robokpy_controller',
            executable = 'motion_planner',
            name       = 'motion_planner',
            output     = 'screen',
            parameters = _robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        virtual_jog_relay = Node(
            package    = 'robokpy_controller',
            executable = 'virtual_jog_relay',
            name       = 'virtual_jog_relay',
            output     = 'screen',
            parameters = [{'use_sim_time': use_sim}],
        )

        orchestrator_real = Node(
            package    = 'robokpy_controller',
            executable = 'orchestrator',
            name       = 'orchestrator',
            output     = 'screen',
            parameters = _robokpy_params({'objects_config_path': objects_config_path}),
            condition  = UnlessCondition(use_sim)
        )

        orchestrator_sim = TimerAction(
            period=20.0,
            actions=[Node(
                package    = 'robokpy_controller',
                executable = 'orchestrator',
                name       = 'orchestrator',
                output     = 'screen',
                parameters = _robokpy_params({'objects_config_path': objects_config_path}),
            )],
            condition=IfCondition(use_sim)
        )

        safety_bridge = Node(
            package    = 'robokpy_controller',
            executable = 'safety_bridge',
            name       = 'safety_bridge',
            output     = 'screen',
            parameters = [{'use_sim_time': use_sim}],
        )

        joint_jog_server = Node(
            package    = 'robokpy_controller',
            executable = 'joint_jog_server',
            name       = 'joint_jog_server',
            output     = 'screen',
            parameters = [{'use_sim_time': use_sim}],
        )

        tool_action_server = Node(
            package    = 'robokpy_controller',
            executable = 'tool_action_server',
            name       = 'tool_action_server',
            output     = 'screen',
            parameters = [{'tools': tools_config}]
        )

        rviz2_node = Node(
            package    = 'rviz2',
            executable = 'rviz2',
            name       = 'rviz2',
            output     = 'screen',
            arguments  = ['-d', rviz_config],
            condition  = IfCondition(launch_rviz)
        )

        jsb_handler = RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity,
                on_exit=[joint_state_broadcaster_spawner],
            )
        )

        arm_handler = RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=joint_state_broadcaster_spawner,
                on_exit=[arm_controller_spawner],
            )
        )

        gripper_handler = RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=arm_controller_spawner,
                on_exit=[gripper_action_controller_spawner],
            )
        )

        return [
            gz_plugin_path_env,
            gazebo,
            gz_clock_bridge,
            gz_robot_state_publisher,
            spawn_entity,
            grasp_attach_gz_bridge,
            grasp_attach_bridge_node,
            entity_management_gz_bridge,
            object_spawner_node,
            object_pose_gz_bridge,
            object_pose_resolver_node,
            rviz_gz_robot_state_publisher,
            virtual_robot_state_publisher,
            virtual_world_bridge,
            robot_state_interface_virtual,
            robot_command_server,
            robot_state_manager,
            pose_target_interface,
            kinematic_solver,
            motion_planner,
            virtual_jog_relay,
            orchestrator_real,
            orchestrator_sim,
            safety_bridge,
            joint_jog_server,
            tool_action_server,
            rviz2_node,
            jsb_handler,
            arm_handler,
            gripper_handler,
        ]

    return LaunchDescription([
        rmw_env,
        use_sim_arg,
        launch_rviz_arg,
        arm_type_arg,
        controllers_yaml_arg,
        OpaqueFunction(function=configure),
    ])
