"""
virtual_jog_relay

Relays kinematic_solver's continuous /joint_target_raw output to
robot_state_interface_virtual's /virtual_joint_target_echo, so dragging
the interactive marker (pose_target_interface) actually moves the
virtual robot in RViz.
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray, String
from rclpy.qos import QoSProfile, DurabilityPolicy


class VirtualJogRelay(Node):
    def __init__(self):
        super().__init__('virtual_jog_relay')

        self.system_mode = None
        self.execution_state = None

        # TRANSIENT_LOCAL to match robot_state_manager's publisher —
        # without this, a late-starting relay misses the single initial
        # publish and stays deaf forever.
        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL

        self.create_subscription(String, 'system_mode', self._sys_mode_cb, qos)
        self.create_subscription(String, 'execution_state', self._exec_state_cb, qos)
        self.create_subscription(
            Float64MultiArray, 'joint_target_raw', self._joint_target_cb, 10)

        self.echo_pub = self.create_publisher(
            Float64MultiArray, 'virtual_joint_target_echo', 10)

        self.get_logger().info('Virtual Jog Relay started')

    def _sys_mode_cb(self, msg: String):
        self.system_mode = msg.data

    def _exec_state_cb(self, msg: String):
        self.execution_state = msg.data

    def _joint_target_cb(self, msg: Float64MultiArray):
        if self.system_mode != 'PLANNER' or self.execution_state != 'SERVO':
            return
        self.echo_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = VirtualJogRelay()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
