"""
arm.launch.py

Everything that exists once PER ARM: URDF/xacro processing for that arm,
its controller spawners, its robokpy_controller node stack (kinematic
solver, state interface, command server, arm_executor), all pushed into
`namespace`. Adding a second arm to a cell is: include this file again
with a different namespace/arm_type/spawn pose — nothing in here changes.

Everything that must exist ONCE PER CELL regardless of arm count (the
Gazebo world itself, the shared object catalog nodes, tool_action_server,
safety_bridge, cell_orchestrator, rviz) lives in cell.launch.py instead.

ASSUMPTION TO CONFIRM: robokpy_controller nodes (kinematic_solver,
robot_command_server, robot_state_manager, pose_target_interface,
robot_state_interface_virtual, virtual_jog_relay, joint_jog_server) are
assumed to use relative (non-leading-slash) topic/service/action names
internally, so that setting `namespace=` on the Node() actions below is
enough to fully isolate two instances. If any of them hardcodes an
absolute name, that node will NOT be correctly namespaced and two arms
will collide on it — worth a grep for leading-slash topic names in those
node sources before running two arms together.
"""

from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument, RegisterEventHandler, OpaqueFunction,
)
from launch.conditions import IfCondition, UnlessCondition
from launch.event_handlers import OnProcessExit
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

import os
import tempfile
import yaml
import xacro

from robokpy_controller.object_catalog import ObjectCatalog


def generate_launch_description():

    namespace_arg = DeclareLaunchArgument('namespace', default_value='arm1')
    arm_type_arg = DeclareLaunchArgument('arm_type', default_value='ur5e')
    controllers_yaml_arg = DeclareLaunchArgument(
        'controllers_yaml', default_value='ur5e_robotiq_85_gripper_controllers.yaml')
    use_sim_arg = DeclareLaunchArgument('use_sim', default_value='false')
    spawn_x_arg = DeclareLaunchArgument('spawn_x', default_value='0.0')
    spawn_y_arg = DeclareLaunchArgument('spawn_y', default_value='0.0')
    spawn_z_arg = DeclareLaunchArgument('spawn_z', default_value='0.0')
    objects_config_path_arg = DeclareLaunchArgument('objects_config_path', default_value='')
    # True only for the arm whose URDF should carry the shared object-
    # catalog Gazebo plugin. See note in cell.launch.py — this plugin is
    # currently assumed single-instance-per-world, not per-arm.
    embed_object_catalog_plugin_arg = DeclareLaunchArgument(
        'embed_object_catalog_plugin', default_value='true')

    namespace = LaunchConfiguration('namespace')
    arm_type = LaunchConfiguration('arm_type')
    controllers_yaml = LaunchConfiguration('controllers_yaml')
    use_sim = LaunchConfiguration('use_sim')
    spawn_x = LaunchConfiguration('spawn_x')
    spawn_y = LaunchConfiguration('spawn_y')
    spawn_z = LaunchConfiguration('spawn_z')
    objects_config_path_launch = LaunchConfiguration('objects_config_path')
    embed_object_catalog_plugin = LaunchConfiguration('embed_object_catalog_plugin')

    pkg = FindPackageShare('robokpy_controller').find('robokpy_controller')
    robot_xacro_file = os.path.join(pkg, 'urdf', 'robokpy_robot.urdf.xacro')
    meshes_path = os.path.join(pkg, 'meshes')
    default_objects_config_path = os.path.join(pkg, 'config', 'objects.yaml')
    prefix = ''
    world_frame = 'world'

    def configure(context):
        ns = namespace.perform(context)
        arm_type_str = arm_type.perform(context)
        controllers_yaml_str = controllers_yaml.perform(context)
        objects_config_path = objects_config_path_launch.perform(context) or default_objects_config_path
        embed_plugin = embed_object_catalog_plugin.perform(context).lower() == 'true'
        sx = spawn_x.perform(context)
        sy = spawn_y.perform(context)
        sz = spawn_z.perform(context)

        catalog = ObjectCatalog(objects_config_path)
        controllers_yaml_path = os.path.join(pkg, 'config', controllers_yaml_str)
        robot_config_yaml = os.path.join(pkg, 'config', 'robots', f'{arm_type_str}.yaml')

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
        logger = launch.logging.get_logger(f'arm.launch.{ns}')
        logger.info(
            f'[{ns}] arm_type={arm_type_str}, tool_type={tool_type_str}, '
            f'ik_backend={backend_str}, embed_object_catalog_plugin={embed_plugin}'
        )

        robokpy_base_yaml = os.path.join(pkg, 'config', 'robokpy_base.yaml')

        def _robokpy_params(extra=None):
            params = [robokpy_base_yaml, robot_config_yaml]
            if extra is not None:
                params.append(extra)
            params.append({'kinematic_solver_backend': backend_str})
            return params

        robot_description_sim_rviz = xacro.process_file(
            robot_xacro_file,
            mappings={
                'prefix': prefix, 'arm_type': arm_type_str, 'gripper_type': tool_type_str,
                'sim': 'true', 'position_proportional_gain': '0.5',
                'controllers_yaml_path': controllers_yaml_path,
                'namespace': ns,
            },
        ).toxml()

        robot_description_sim_gz = robot_description_sim_rviz.replace(
            'package://robokpy_controller/meshes', meshes_path)
        if embed_plugin:
            robot_description_sim_gz = robot_description_sim_gz.replace(
                '</robot>', catalog.to_gazebo_plugin_sdf() + '\n</robot>')

        gz_urdf_file = os.path.join(tempfile.gettempdir(), f'robot_sim_gz_{ns}.urdf')
        with open(gz_urdf_file, 'w') as f:
            f.write(robot_description_sim_gz)

        robot_description_real = xacro.process_file(
            robot_xacro_file,
            mappings={
                'prefix': prefix, 'arm_type': arm_type_str, 'gripper_type': tool_type_str,
                'sim': 'true', 'position_proportional_gain': '0.5',
                'controllers_yaml_path': controllers_yaml_path,
                'namespace': ns,
            },
        ).toxml()

        # --- Gazebo, this arm's model only (world itself is launched once in cell.launch.py) ---
        gz_robot_state_publisher = Node(
            package='robot_state_publisher', executable='robot_state_publisher',
            name='gz_robot_state_publisher', namespace=ns,
            parameters=[{'robot_description': robot_description_sim_gz}, {'use_sim_time': True}],
            remappings=[('robot_description', 'gz_robot_description')],
            condition=IfCondition(use_sim),
        )

        spawn_entity = Node(
            package='ros_gz_sim', executable='create', name='spawn_robot', namespace=ns,
            output='screen',
            arguments=[
                '-name', f'{ns}_robot', '-topic', f'/{ns}/gz_robot_description',
                '-x', sx, '-y', sy, '-z', sz,
            ],
            condition=IfCondition(use_sim),
        )

        rviz_gz_robot_state_publisher = Node(
            package='robot_state_publisher', executable='robot_state_publisher',
            name='rviz_gz_robot_state_publisher', namespace=ns,
            parameters=[{'robot_description': robot_description_sim_rviz}, {'use_sim_time': True}],
            condition=IfCondition(use_sim),
        )

        joint_state_broadcaster_spawner = Node(
            package='controller_manager', executable='spawner',
            name='joint_state_broadcaster_spawner', namespace=ns, output='screen',
            arguments=['joint_state_broadcaster',
                       '--controller-manager', f'/{ns}/controller_manager',
                       '--controller-manager-timeout', '30'],
            condition=IfCondition(use_sim),
        )

        arm_controller_spawner = Node(
            package='controller_manager', executable='spawner',
            name='arm_controller_spawner', namespace=ns, output='screen',
            arguments=['arm_controller',
                       '--controller-manager', f'/{ns}/controller_manager',
                       '--controller-manager-timeout', '30'],
            condition=IfCondition(use_sim),
        )

        gripper_action_controller_spawner = Node(
            package='controller_manager', executable='spawner',
            name='gripper_action_controller_spawner', namespace=ns, output='screen',
            arguments=['gripper_action_controller',
                       '--controller-manager', f'/{ns}/controller_manager',
                       '--controller-manager-timeout', '30'],
            condition=IfCondition(use_sim),
        )

        # --- This arm's virtual twin + robokpy_controller node stack ---
        virtual_robot_state_publisher = Node(
            package='robot_state_publisher', executable='robot_state_publisher',
            name='virtual_robot_state_publisher', namespace=ns,
            parameters=[{
                'robot_description': robot_description_real,
                'frame_prefix': f'{ns}/virtual/', 'use_sim_time': use_sim,
            }],
            remappings=[
                ('joint_states', 'virtual_joint_states'),
                ('robot_description', 'virtual_robot_description'),
            ],
        )

        virtual_world_bridge = Node(
            package='tf2_ros', executable='static_transform_publisher',
            name='virtual_world_bridge', namespace=ns,
            arguments=['0', '0', '0', '0', '0', '0', world_frame, f'{ns}/virtual/world'],
        )

        robot_state_interface_virtual = Node(
            package='robokpy_controller', executable='robot_state_interface_virtual',
            name='robot_state_interface_virtual', namespace=ns, output='screen',
            parameters=_robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        robot_command_server = Node(
            package='robokpy_controller', executable='robot_command_server',
            name='robot_command_server', namespace=ns, output='screen',
            parameters=_robokpy_params({'use_sim_time': use_sim}),
        )

        robot_state_manager = Node(
            package='robokpy_controller', executable='robot_state_manager',
            name='robot_state_manager', namespace=ns, output='screen',
            parameters=_robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        pose_target_interface = Node(
            package='robokpy_controller', executable='pose_target_interface',
            name='pose_target_interface', namespace=ns, output='screen',
            parameters=_robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        kinematic_solver = Node(
            package='robokpy_controller', executable='kinematic_solver',
            name='kinematic_solver', namespace=ns, output='screen',
            parameters=_robokpy_params({'robot_description': robot_description_real, 'use_sim_time': use_sim}),
        )

        # --- arm_executor: replaces trajectory_generator. Owns plan -> execute
        # -> confirm for this arm, exposes execute_move_step for the cell
        # orchestrator to call. jtc_action_name is relative, so it resolves
        # to /<namespace>/arm_controller/follow_joint_trajectory.
        arm_executor = Node(
            package='robokpy_controller', executable='arm_executor',
            name='arm_executor', namespace=ns, output='screen',
            parameters=_robokpy_params({
                'robot_description': robot_description_real,
                'use_sim_time': use_sim,
                'jtc_action_name': 'arm_controller/follow_joint_trajectory',
            }),
        )

        virtual_jog_relay = Node(
            package='robokpy_controller', executable='virtual_jog_relay',
            name='virtual_jog_relay', namespace=ns, output='screen',
            parameters=[{'use_sim_time': use_sim}],
        )

        joint_jog_server = Node(
            package='robokpy_controller', executable='joint_jog_server',
            name='joint_jog_server', namespace=ns, output='screen',
            parameters=[{'use_sim_time': use_sim}],
        )

        jsb_handler = RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=spawn_entity, on_exit=[joint_state_broadcaster_spawner]))
        arm_handler = RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=joint_state_broadcaster_spawner, on_exit=[arm_controller_spawner]))
        gripper_handler = RegisterEventHandler(
            event_handler=OnProcessExit(
                target_action=arm_controller_spawner, on_exit=[gripper_action_controller_spawner]))

        return [
            gz_robot_state_publisher,
            spawn_entity,
            rviz_gz_robot_state_publisher,
            virtual_robot_state_publisher,
            virtual_world_bridge,
            robot_state_interface_virtual,
            robot_command_server,
            robot_state_manager,
            pose_target_interface,
            kinematic_solver,
            arm_executor,
            virtual_jog_relay,
            joint_jog_server,
            jsb_handler,
            arm_handler,
            gripper_handler,
        ]

    return LaunchDescription([
        namespace_arg, arm_type_arg, controllers_yaml_arg, use_sim_arg,
        spawn_x_arg, spawn_y_arg, spawn_z_arg,
        objects_config_path_arg, embed_object_catalog_plugin_arg,
        OpaqueFunction(function=configure),
    ])