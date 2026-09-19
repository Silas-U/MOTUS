"""
cell.launch.py

Everything that exists ONCE PER CELL: the Gazebo world, the shared
object-catalog nodes, tool_action_server, safety_bridge, rviz, and
cell_orchestrator (DAG dispatch + arm registry + resource locks — no
JTC/trajectory knowledge, see cell_orchestrator_node.py).

Arms are declared via `arms_config` (path to a YAML file listing each
arm's namespace/arm_type/controllers_yaml/spawn pose — see
config/cell_arms.yaml for the two-arm example). If `arms_config` is
left empty, this launches exactly one arm built from the arm_type /
controllers_yaml arguments — i.e. running this with no new arguments
reproduces the old single-arm motus_launch.py behavior exactly, so
today's launch commands and test recipes still work unchanged.

Adding a second arm is: add an entry to cell_arms.yaml. Nothing in this
file or in arm.launch.py needs to change.

OPEN QUESTION, not resolved here: the object-catalog Gazebo plugin
(`catalog.to_gazebo_plugin_sdf()`) is embedded into exactly one arm's
URDF (the first one in `arms_config`) on the assumption that it's a
world-level concern and shouldn't be duplicated per-arm. Confirm that's
actually how grasp_attach_bridge/object_spawner expect it before running
a real two-arm test — if the plugin needs to be per-robot, this needs to
flip to embedding it in every arm instead.
"""

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument, IncludeLaunchDescription, TimerAction, OpaqueFunction,
    SetEnvironmentVariable,
)
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

import os
import json
import yaml

from ament_index_python.packages import get_package_prefix
from robokpy_controller.object_catalog import ObjectCatalog


def generate_launch_description():

    rmw_env = SetEnvironmentVariable('RMW_IMPLEMENTATION', 'rmw_cyclonedds_cpp')

    robokpy_interfaces_prefix = get_package_prefix('robokpy_interfaces')
    gz_plugin_lib_path = os.path.join(robokpy_interfaces_prefix, 'lib')
    gz_plugin_path_env = SetEnvironmentVariable(
        name='GZ_SIM_SYSTEM_PLUGIN_PATH',
        value=os.pathsep.join(filter(None, [
            os.environ.get('GZ_SIM_SYSTEM_PLUGIN_PATH', ''),
            gz_plugin_lib_path,
        ])),
    )

    use_sim_arg = DeclareLaunchArgument('use_sim', default_value='false',
                                         description='Use Gazebo simulation instead of real hardware')
    launch_rviz_arg = DeclareLaunchArgument('launch_rviz', default_value='true')
    arm_type_arg = DeclareLaunchArgument(
        'arm_type', default_value='ur5e',
        description='Used only when arms_config is not set (single-arm mode)')
    controllers_yaml_arg = DeclareLaunchArgument(
        'controllers_yaml', default_value='ur5e_robotiq_85_gripper_controllers.yaml',
        description='Used only when arms_config is not set (single-arm mode)')
    arms_config_arg = DeclareLaunchArgument(
        'arms_config', default_value='',
        description='Path to a YAML file listing arms for a multi-arm cell. '
                     'Empty = single arm built from arm_type/controllers_yaml.')

    # --- NEW: external robot-description override passthrough (Motus
    # Builder support, single-arm mode only -- see arm.launch.py for what
    # these do). cell.launch.py is what actually starts the Gazebo world
    # (motus_world.sdf) and RViz; a generated project's launch wrapper
    # needs to go through THIS file, not arm.launch.py directly, or no
    # simulation ever starts (ros_gz_sim's spawner then blocks forever
    # waiting for a world that was never launched). These four are simply
    # forwarded into the single-arm arm.launch.py include below -- they
    # have no effect when arms_config is set (multi-arm mode keeps using
    # each arm's own arm_type/controllers_yaml from that YAML file).
    robot_description_path_arg = DeclareLaunchArgument(
        'robot_description_path', default_value='')
    robot_config_path_arg = DeclareLaunchArgument(
        'robot_config_path', default_value='')
    controllers_yaml_full_path_arg = DeclareLaunchArgument(
        'controllers_yaml_full_path', default_value='')
    mesh_package_name_arg = DeclareLaunchArgument(
        'mesh_package_name', default_value='')

    use_sim = LaunchConfiguration('use_sim')
    launch_rviz = LaunchConfiguration('launch_rviz')
    arm_type = LaunchConfiguration('arm_type')
    controllers_yaml = LaunchConfiguration('controllers_yaml')
    arms_config = LaunchConfiguration('arms_config')
    robot_description_path_launch = LaunchConfiguration('robot_description_path')
    robot_config_path_launch = LaunchConfiguration('robot_config_path')
    controllers_yaml_full_path_launch = LaunchConfiguration('controllers_yaml_full_path')
    mesh_package_name_launch = LaunchConfiguration('mesh_package_name')

    pkg = FindPackageShare('robokpy_controller').find('robokpy_controller')
    rviz_config = os.path.join(pkg, 'config', 'config.rviz')
    tool_config_path = os.path.join(pkg, 'config', 'tools.yaml')
    objects_config_path = os.path.join(pkg, 'config', 'objects.yaml')
    world_file = os.path.join(pkg, 'worlds', 'motus_world.sdf')

    catalog = ObjectCatalog(objects_config_path)

    with open(tool_config_path, 'r') as f:
        tools_dict = yaml.safe_load(f)
    for tool_id, cfg in tools_dict.items():
        if cfg.get('backend') == 'grasp_attach':
            cfg.setdefault('parent_model', catalog.parent_model)
            cfg.setdefault('parent_link', catalog.parent_link)
            cfg.setdefault('objects_catalog_path', objects_config_path)
    tools_config = json.dumps(tools_dict)

    def configure(context):
        arms_config_path = arms_config.perform(context)
        if arms_config_path:
            with open(arms_config_path, 'r') as f:
                arms = yaml.safe_load(f)['arms']
        else:
            arms = [{
                'namespace': 'arm1',
                'arm_type': arm_type.perform(context),
                'controllers_yaml': controllers_yaml.perform(context),
                'spawn_x': 0.0, 'spawn_y': 0.0, 'spawn_z': 0.0,
            }]

        arm_namespaces = [a['namespace'] for a in arms]

        # NEW: only meaningful in single-arm mode (arms_config unset) --
        # a multi-arm cell_arms.yaml has no notion of an externally
        # imported description per entry yet.
        robot_description_path_str = robot_description_path_launch.perform(context)
        robot_config_path_str = robot_config_path_launch.perform(context)
        controllers_yaml_full_path_str = controllers_yaml_full_path_launch.perform(context)
        mesh_package_name_str = mesh_package_name_launch.perform(context)
        single_arm_mode = not arms_config_path

        import launch.logging
        logger = launch.logging.get_logger('cell.launch')
        logger.info(f'[Cell] arms={arm_namespaces}')
        if single_arm_mode and robot_description_path_str:
            logger.info(f'[Cell] single-arm mode using external robot description: {robot_description_path_str}')

        arm_includes = []
        for i, a in enumerate(arms):
            arm_launch_arguments = {
                'namespace': a['namespace'],
                'arm_type': a.get('arm_type', 'ur5e'),
                'controllers_yaml': a.get('controllers_yaml',
                                           'ur5e_robotiq_85_gripper_controllers.yaml'),
                'use_sim': use_sim,
                'spawn_x': str(a.get('spawn_x', 0.0)),
                'spawn_y': str(a.get('spawn_y', 0.0)),
                'spawn_z': str(a.get('spawn_z', 0.0)),
                'objects_config_path': objects_config_path,
                # See module docstring — first arm only, unconfirmed assumption.
                'embed_object_catalog_plugin': 'true' if i == 0 else 'false',
            }
            # NEW: forward the external-description override args through
            # to arm.launch.py, single-arm mode only (i == 0 and only one
            # arm exists in that mode anyway, but guard explicitly rather
            # than rely on that coincidence).
            if single_arm_mode:
                arm_launch_arguments.update({
                    'robot_description_path': robot_description_path_str,
                    'robot_config_path': robot_config_path_str,
                    'controllers_yaml_full_path': controllers_yaml_full_path_str,
                    'mesh_package_name': mesh_package_name_str,
                })
            arm_includes.append(IncludeLaunchDescription(
                PythonLaunchDescriptionSource(
                    PathJoinSubstitution([pkg, 'launch', 'arm.launch.py'])),
                launch_arguments=arm_launch_arguments.items(),
            ))

        # --- Gazebo world (once, regardless of arm count) ---
        gazebo = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(
                PathJoinSubstitution([FindPackageShare('ros_gz_sim'), 'launch', 'gz_sim.launch.py'])),
            launch_arguments={'gz_args': f' -r {world_file}'}.items(),
            condition=IfCondition(use_sim),
        )

        gz_clock_bridge = Node(
            package='ros_gz_bridge', executable='parameter_bridge', name='gz_clock_bridge',
            output='screen', arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'],
            condition=IfCondition(use_sim),
        )

        grasp_attach_gz_bridge = Node(
            package='ros_gz_bridge', executable='parameter_bridge', name='grasp_attach_gz_bridge',
            output='screen', arguments=catalog.to_ros_gz_bridge_args(),
            condition=IfCondition(use_sim),
        )

        grasp_attach_bridge_node = Node(
            package='robokpy_controller', executable='grasp_attach_bridge',
            name='grasp_attach_bridge', output='screen',
            parameters=[{'objects_config_path': objects_config_path}],
            condition=IfCondition(use_sim),
        )

        entity_management_gz_bridge = Node(
            package='ros_gz_bridge', executable='parameter_bridge',
            name='entity_management_gz_bridge', output='screen',
            arguments=[
                '/world/motus_world/create@ros_gz_interfaces/srv/SpawnEntity',
                '/world/motus_world/remove@ros_gz_interfaces/srv/DeleteEntity',
            ],
            condition=IfCondition(use_sim),
        )

        object_spawner_node = Node(
            package='robokpy_controller', executable='object_spawner', name='object_spawner',
            output='screen',
            parameters=[{'objects_config_path': objects_config_path, 'world_name': 'motus_world'}],
            condition=IfCondition(use_sim),
        )

        object_pose_gz_bridge = Node(
            package='ros_gz_bridge', executable='parameter_bridge', name='object_pose_gz_bridge',
            output='screen',
            arguments=['/world/motus_world/dynamic_pose/info@tf2_msgs/msg/TFMessage[gz.msgs.Pose_V'],
            condition=IfCondition(use_sim),
        )

        object_pose_resolver_node = Node(
            package='robokpy_controller', executable='object_pose_resolver',
            name='object_pose_resolver', output='screen',
            parameters=[{'objects_config_path': objects_config_path}],
            condition=IfCondition(use_sim),
        )

        # --- Cell-level shared services ---
        safety_bridge = Node(
            package='robokpy_controller', executable='safety_bridge', name='safety_bridge',
            output='screen', parameters=[{'use_sim_time': use_sim}],
        )

        tool_action_server = Node(
            package='robokpy_controller', executable='tool_action_server',
            name='tool_action_server', output='screen',
            parameters=[{'tools': tools_config}],
        )

        rviz2_node = Node(
            package='rviz2', executable='rviz2', name='rviz2', output='screen',
            arguments=['-d', rviz_config], condition=IfCondition(launch_rviz),
        )

        # --- cell_orchestrator: DAG dispatch only, no JTC/trajectory knowledge ---
        cell_orchestrator_real = Node(
            package='robokpy_controller', executable='cell_orchestrator', name='cell_orchestrator',
            output='screen',
            parameters=[{'objects_config_path': objects_config_path, 'arm_namespaces': arm_namespaces}],
            condition=UnlessCondition(use_sim),
        )

        cell_orchestrator_sim = TimerAction(
            period=20.0,
            actions=[Node(
                package='robokpy_controller', executable='cell_orchestrator', name='cell_orchestrator',
                output='screen',
                parameters=[{'objects_config_path': objects_config_path, 'arm_namespaces': arm_namespaces}],
            )],
            condition=IfCondition(use_sim),
        )

        return arm_includes + [
            gazebo,
            gz_clock_bridge,
            grasp_attach_gz_bridge,
            grasp_attach_bridge_node,
            entity_management_gz_bridge,
            object_spawner_node,
            object_pose_gz_bridge,
            object_pose_resolver_node,
            safety_bridge,
            tool_action_server,
            rviz2_node,
            cell_orchestrator_real,
            cell_orchestrator_sim,
        ]

    return LaunchDescription([
        rmw_env,
        gz_plugin_path_env,
        use_sim_arg,
        launch_rviz_arg,
        arm_type_arg,
        controllers_yaml_arg,
        arms_config_arg,
        robot_description_path_arg,
        robot_config_path_arg,
        controllers_yaml_full_path_arg,
        mesh_package_name_arg,
        OpaqueFunction(function=configure),
    ])