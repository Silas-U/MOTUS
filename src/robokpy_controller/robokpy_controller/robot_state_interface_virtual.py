import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray
from robokpy import Init_Model
from std_msgs.msg import String
from rclpy.qos import QoSProfile, DurabilityPolicy


class RobotStateInterfaceVirtual(Node):
    def __init__(self):
        super().__init__('robot_state_interface_virtual')
        self.declare_parameter("robot_description", "")
        self.robot_description = self.get_parameter('robot_description').value

        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link',  'tcp')
        base_link = self.get_parameter('planning_base_link').value
        tip_link  = self.get_parameter('planning_tip_link').value

        self.model = Init_Model(self.robot_description, base_link=base_link, tip_link=tip_link)
        self.joint_names = self.model.model.get_joint_names_in_chain(base_link, tip_link)

        self.declare_parameter("home_pose", [0.0] * len(self.joint_names))
        home_q = list(self.get_parameter('home_pose').value)

        # Registry covers every actuated joint in the URDF automatically —
        # works whether the model has a gripper, a different tool, or none.
        # Joints outside the active planning chain just hold their default (0.0)
        # until an actual value comes in via /virtual_joint_target_echo.
        self.joint_registry = {name: 0.0 for name in self.model.all_joint_names}
        self.joint_registry.update(zip(self.joint_names, home_q))

        self.publisher = self.create_publisher(JointState, '/virtual_joint_states', 10)

        self.subscription = self.create_subscription(
            Float64MultiArray, '/virtual_joint_target_echo',
            self.update_joint_target, 10
        )

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL
        self.create_subscription(String, '/planning_tip_link', self.tip_link_cb, qos)

        self.timer = self.create_timer(0.05, self.publish_joint_states)

    def tip_link_cb(self, msg):
        self.model.ik.tip_link = msg.data
        self.joint_names = self.model.model.get_joint_names_in_chain(
            self.model.base_link, msg.data
        )

    def update_joint_target(self, msg):
        if len(msg.data) != len(self.joint_names):
            self.get_logger().warn(
                f"Expected {len(self.joint_names)} joints, got {len(msg.data)}"
            )
            return
        for name, val in zip(self.joint_names, msg.data):
            self.joint_registry[name] = val

    def publish_joint_states(self):
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = list(self.joint_registry.keys())
        msg.position = list(self.joint_registry.values())
        msg.velocity = []
        msg.effort = []
        self.publisher.publish(msg)

def main():
    rclpy.init()
    node = RobotStateInterfaceVirtual()
    rclpy.spin(node)
    rclpy.shutdown()