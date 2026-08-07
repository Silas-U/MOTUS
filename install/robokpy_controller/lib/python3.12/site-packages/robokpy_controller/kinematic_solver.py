import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose
from std_msgs.msg import Float64MultiArray, String
from typing import Optional
import numpy as np
from robokpy import Init_Model
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

        robot_description = self.get_parameter('robot_description').value
        self.mask = list(self.get_parameter('mask').value)

        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link',  'tcp')
        self.base_link = self.get_parameter('planning_base_link').value
        self.tip_link  = self.get_parameter('planning_tip_link').value

        # -----------------------------
        # Model
        # -----------------------------
        self.model = Init_Model(robot_description, base_link=self.base_link, tip_link=self.tip_link)
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

        # TRANSIENT_LOCAL to match robot_state_manager's publisher —
        # without this, a late-starting solver misses the single initial
        # publish and stays deaf forever (robot_state_manager only
        # republishes on service call, not periodically).
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
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL  # late joiners get last value, like sys_mode
        self.create_subscription(String, '/planning_tip_link', self.tip_link_cb, qos)  # same TRANSIENT_LOCAL qos
        
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

        self.get_logger().info("Kinematic Solver (Pure IK + Smoothed) Started")

    # =========================================================
    # CALLBACKS
    # =========================================================
    def tip_link_cb(self, msg):
        self.tip_link = msg.data
        self.model.ik.tip_link = msg.data
        # joint limits / preferred posture are keyed to the chain — refresh
        # both in case the new tip_link resolves through a different chain
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
        """
        Track the most recent ik output as the warm start, this is the last solution
        the solver produced regardless of which robot (Active or Planner) is being driven.
        """

        self.q_warm = np.array(msg.data)

    
    def pose_callback(self, msg):

        now = self.get_clock().now()

        # -----------------------------
        # RATE LIMITING (prevents jitter)
        # -----------------------------
        if (now - self.last_pose_time).nanoseconds < self.pose_update_period_ns:
            return

        self.last_pose_time = now

        raw_pose = np.array([
            msg.position.x,
            msg.position.y,
            msg.position.z,
            msg.orientation.x,
            msg.orientation.y,
            msg.orientation.z,
            msg.orientation.w
        ])

        self.target_pose_raw = raw_pose

    # =========================================================
    # CONTROL LOOP (PURE IK)
    # =========================================================

    def control_loop(self):

        # Only solve/publish while in PLANNER+SERVO — this is what keeps
        # marker-driven pose targets confined to virtual preview. Without
        # this, control_loop also overwrote self.q_current with the IK
        # output every cycle regardless of mode, silently drifting the
        # solver's seed away from the real hardware joint state reported
        # via /current_joint_state whenever in ACTIVE.
        if self.sys_mode != "PLANNER" or self.exe_state != "SERVO":
            # Throttled log so we can see when the solver is being gated
            # (helps debug missing mode/state messages at startup).
            if not hasattr(self, '_guard_skip_count'):
                self._guard_skip_count = 0
            self._guard_skip_count += 1
            # if self._guard_skip_count % 250 == 1:  # ~5s at 50Hz
            #     self.get_logger().warn(
            #         f'IK solver gated: sys_mode={self.sys_mode} '
            #         f'exe_state={self.exe_state} (waiting for PLANNER+SERVO)')
            return

        if self.q_current is None:
            return
        
        if self.target_pose_raw is None:
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

    
# =========================================================
# MAIN
# =========================================================

def main(args=None):
    rclpy.init(args=args)
    node = KinematicSolver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()