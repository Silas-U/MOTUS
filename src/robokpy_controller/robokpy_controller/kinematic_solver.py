import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from std_msgs.msg import Float64MultiArray, String
from typing import Optional
import numpy as np
from robokpy_controller.ik_factory import build_model
from rclpy.qos import QoSProfile
from rclpy.qos import DurabilityPolicy


class KinematicSolver(Node):

    def __init__(self):
        super().__init__('kinematic_solver')

        # -----------------------------
        # Parameters
        # -----------------------------
        self.declare_parameter('robot_description', "")
        self.declare_parameter('mask', [0]*6)
        self.declare_parameter('kinematic_solver_backend', 'robokpy')

        robot_description = self.get_parameter('robot_description').value
        self.mask = list(self.get_parameter('mask').value)
        backend = self.get_parameter('kinematic_solver_backend').value

        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link',  'tcp')
        self.base_link = self.get_parameter('planning_base_link').value
        self.tip_link  = self.get_parameter('planning_tip_link').value

        # -----------------------------
        # Model (factory-injected backend)
        # -----------------------------
        self.model = build_model(
            robot_description,
            base_link=self.base_link,
            tip_link=self.tip_link,
            backend=backend,
        )
        self.ik = self.model.ik

        q_min, q_max = self.model.model.get_joint_limits_in_chain(self.base_link, self.tip_link)
        self.ik.set_joint_limits(q_min, q_max)

        num_joints = self.model.model.get_num_act_joints_in_chain(self.base_link, self.tip_link)

        self.declare_parameter('home_pose', [0.0]*num_joints)
        home_q = np.array(self.get_parameter('home_pose').value)

        self.ik.set_preferred_posture(home_q)

        # -----------------------------
        # State (READ ONLY from State Manager)
        # -----------------------------
        self.q_current: Optional[np.ndarray] = None
        self.q_warm: Optional[np.ndarray] = None
        self.target_pose_raw: Optional[np.ndarray] = None

        # -----------------------------
        # Rate Control
        # -----------------------------
        self.last_pose_time = self.get_clock().now()
        self.pose_update_period_ns = int(2e7)  # 20ms → 50Hz

        self.sys_mode = None
        self.exe_state = None

        # -----------------------------
        # Subscribers (FROM STATE MANAGER)
        # -----------------------------
        self.create_subscription(
            Float64MultiArray,
            '/current_joint_state',
            self.joint_callback,
            10
        )

        self.create_subscription(
            Pose,
            '/active_target_pose',
            self.pose_callback,
            10
        )

        mode_qos = QoSProfile(depth=1)
        mode_qos.durability = DurabilityPolicy.TRANSIENT_LOCAL

        self.create_subscription(
            String,
            '/system_mode',
            self.sys_mode_cb,
            mode_qos
        )

        self.create_subscription(
            String,
            '/execution_state',
            self.exe_state_cb,
            mode_qos
        )

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL
        self.create_subscription(String, '/planning_tip_link', self.tip_link_cb, qos)

        # -----------------------------
        # Publisher (TO CONTROL PIPELINE)
        # -----------------------------
        self.joint_pub = self.create_publisher(
            Float64MultiArray,
            '/joint_target_raw',
            10
        )

        # -----------------------------
        # Timer (stateless compute loop)
        # -----------------------------
        self.timer = self.create_timer(0.02, self.control_loop)

        self.get_logger().info(f"Kinematic Solver Started (backend={backend})")

    # =========================================================
    # CALLBACKS
    # =========================================================
    def tip_link_cb(self, msg):
        self.tip_link = msg.data
        self.model.ik.tip_link = msg.data
        q_min, q_max = self.model.model.get_joint_limits_in_chain(self.base_link, self.tip_link)
        self.ik.set_joint_limits(q_min, q_max)
        self.get_logger().info(f'planning_tip_link updated -> {msg.data}')

    def sys_mode_cb(self, msg):
        self.sys_mode = msg.data

    def exe_state_cb(self, msg: String):
        self.exe_state = msg.data

    def joint_callback(self, msg: Float64MultiArray):
        self.q_current = np.array(msg.data)

    def raw_callback(self, msg: Float64MultiArray):
        self.q_warm = np.array(msg.data)

    def pose_callback(self, msg):
        now = self.get_clock().now()
        if (now - self.last_pose_time).nanoseconds < self.pose_update_period_ns:
            return
        self.last_pose_time = now

        self.target_pose_raw = np.array([
            msg.position.x, msg.position.y, msg.position.z,
            msg.orientation.x, msg.orientation.y,
            msg.orientation.z, msg.orientation.w
        ])

    # =========================================================
    # CONTROL LOOP (PURE IK)
    # =========================================================
    def control_loop(self):
        if self.sys_mode != "PLANNER" or self.exe_state != "SERVO":
            if not hasattr(self, '_guard_skip_count'):
                self._guard_skip_count = 0
            self._guard_skip_count += 1
            return

        if self.q_current is None or self.target_pose_raw is None:
            return

        q_seed = self.q_current

        q_target = self.ik.solve(
            self.target_pose_raw,
            q0=q_seed,
            mask=self.mask
        )

        if not self.ik.success:
            if not hasattr(self, '_ik_fail_logged'):
                self.get_logger().warn(
                    f'IK solver: solve failed from seed {q_seed.round(3)} '
                    f'to target {self.target_pose_raw.round(3)}')
                self._ik_fail_logged = True
            return
        self._ik_fail_logged = False

        self.q_current = q_target.copy()

        msg = Float64MultiArray()
        msg.data = q_target.tolist()
        self.joint_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = KinematicSolver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
