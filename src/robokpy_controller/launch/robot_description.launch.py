from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
   # ---------------------------------
    # Robot description (URDF/Xacro)
    # ---------------------------------
    pkg = FindPackageShare('robokpy_controller').find('robokpy_controller')
    
    urdf_real_file = os.path.join(pkg, 'urdf', '6dof.urdf')
    
    with open(urdf_real_file, 'r') as f:
        robot_description_real = f.read()

    return LaunchDescription([

        Node(
            package='robokpy_controller',
            executable='robot_description_viewer',
            name='robot_description_viewer',
            output='screen',
            parameters=[{'robot_description': robot_description_real}],
        )
    ])