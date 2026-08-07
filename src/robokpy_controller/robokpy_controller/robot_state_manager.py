import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.qos import DurabilityPolicy
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray, String
from geometry_msgs.msg import Pose
import numpy as np
from robokpy import Init_Model
from robokpy_interfaces.srv import ExecutionState, SystemMode
from robokpy_interfaces.srv import SetPlanningTipLink


# =========================================================
# FSM ENUMS
# =========================================================

class RobotStateManager(Node):

    def __init__(self):
        super().__init__('robot_state_manager')

        # -----------------------------
        # PARAMETERS
        # -----------------------------
        self.declare_parameter('robot_description', "")
        self.robot_description = self.get_parameter('robot_description').value

        # -----------------------------
        # MODEL (for FK)
        # -----------------------------

        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link',  'tcp')
        self.base_link = self.get_parameter('planning_base_link').value
        self.tip_link  = self.get_parameter('planning_tip_link').value

        self.model = Init_Model(self.robot_description, base_link=self.base_link, tip_link=self.tip_link)
        self.fk = self.model.fk

        self.joint_names = self.model.model.get_joint_names_in_chain(self.base_link, self.tip_link)
        
        self.get_logger().info(f"joint names ={self.joint_names}")
        
        num_joints  = self.model.model.get_num_act_joints_in_chain(self.base_link, self.tip_link)

        self.declare_parameter('home_pose', [0.0]*num_joints)
        home_pose = self.get_parameter('home_pose').value

        self.home_pose = np.array(home_pose) if home_pose else None

        # -----------------------------
        # CENTRAL STATE (single source of truth)
        # -----------------------------
        self.q_current = np.array(self.home_pose) if self.home_pose is not None else None
        self.q_collision = np.array(self.home_pose) if self.home_pose is not None else None

        self.target_pose = None
        self.updated_target_pose = None
        self.execution_state = "SERVO"
        self.system_mode = "PLANNER"
        self.initialized = False

        self.last_update_time = self.get_clock().now()

        # -----------------------------
        # INITIAL TARGET (FK from home)
        # -----------------------------
        if self.q_current is not None:
            self.fk.compute_chain(self.q_current, self.base_link, self.tip_link)
            pose = self.fk.get_pose_quart()

            self.target_pose = Pose()
            self.target_pose.position.x = pose[0]
            self.target_pose.position.y = pose[1]
            self.target_pose.position.z = pose[2]
            self.target_pose.orientation.x = pose[3]
            self.target_pose.orientation.y = pose[4]
            self.target_pose.orientation.z = pose[5]
            self.target_pose.orientation.w = pose[6]

        # -----------------------------
        # SUBSCRIBERS
        # -----------------------------
    
        self.create_subscription(JointState, '/joint_states', self.joint_callback, 10)
        self.create_subscription(JointState, '/virtual_joint_states', self.collision_joint_callback, 10)
        self.create_subscription(Pose, '/target_pose', self.target_callback, 10)
        self.create_subscription(Pose, '/updated_target_pose', self.updated_target_callback, 10)
        
        
        # -----------------------------
        # PUBLISHERS
        # -----------------------------

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL

        self.q_pub = self.create_publisher(Float64MultiArray, '/current_joint_state', 10)
        self.pose_pub = self.create_publisher(Pose, '/active_target_pose', 10)
        self.sys_mode_pub = self.create_publisher(String, '/system_mode', qos)
        self.exec_state_pub = self.create_publisher(String, '/execution_state', qos)


        # -----------------------------
        # SYSTEM MODE SERVICE
        # -----------------------------
        self.system_mode_service = self.create_service(
            SystemMode, '/set_system_mode',
            self.handle_system_mode
        )

        self.execution_state_service = self.create_service(
            ExecutionState, '/set_execution_state',
            self.handle_execution_state
        )


        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL  # late joiners get last value, like sys_mode

        self.tip_link_pub = self.create_publisher(String, '/planning_tip_link', qos)

        self.tip_link_service = self.create_service(
            SetPlanningTipLink, '/set_planning_tip_link', self.handle_set_tip_link
        )


        # -----------------------------
        # TIMER
        # -----------------------------
        self.state_timer = self.create_timer(0.02, self.publish_state)

        self.get_logger().info("Robot State Manager started")

    # =========================================================
    # CALLBACKS
    # =========================================================

    def handle_set_tip_link(self, request, response):
        if request.tip_link not in self.model.model.get_link_names():
            response.success = False
            response.message = f"'{request.tip_link}' not in URDF"
            return response

        try:
            new_chain = self.model.model.build_chain(self.base_link, request.tip_link)
        except (RuntimeError, ValueError) as e:
            response.success = False
            response.message = f"'{request.tip_link}' not reachable from '{self.base_link}': {e}"
            return response

        new_active_count = len(self.model.model.get_active_joints_in_chain(self.base_link, request.tip_link))
        current_active_count = len(self.model.model.get_active_joints_in_chain(self.base_link, self.tip_link))

        if new_active_count != current_active_count:
            response.success = False
            response.message = (
                f"'{request.tip_link}' changes active DOF ({new_active_count} vs "
                f"{current_active_count}) — tip_link must be a tool frame past the "
                f"full arm chain, not an intermediate arm link"
            )
            return response

        self.tip_link = request.tip_link
        self.model.ik.tip_link = request.tip_link
        self.joint_names = self.model.model.get_joint_names_in_chain(self.base_link, self.tip_link)

        msg = String()
        msg.data = self.tip_link
        self.tip_link_pub.publish(msg)

        response.success = True
        response.message = f"tip_link set to {self.tip_link}"
        return response

    def handle_system_mode(self, request, response):
        new_mode = request.new_mode

        self.get_logger().info(f"Recieved state request: {new_mode}")

        allowed_mode = [
            "PLANNER",
            "ACTIVE"
        ]

        if new_mode not in allowed_mode:
            response.success = False
            response.message = "Invalid system mode"
            return response
        
        self.system_mode = new_mode

        msg = String()
        msg.data = self.system_mode
        self.sys_mode_pub.publish(msg)

        self.get_logger().info(f"System mode updated -> {self.system_mode}")

        response.success = True
        response.message = "Mode updated successfully"

        return response
    
    def handle_execution_state(self, request, response):
        new_state = request.new_state

        self.get_logger().info(f"Recieved state request: {new_state}")

        allowed_state = [
            "SERVO",
            "EXECUTING",
            "STOPPED"
        ]

        if new_state not in allowed_state:
            response.success = False
            response.message = "Invalid execution state"
            return response
        
        self.execution_state = new_state

        msg = String()
        msg.data = self.execution_state
        self.exec_state_pub.publish(msg)

        self.get_logger().info(f"Execution state updated -> {self.execution_state}")

        response.success = True
        response.message = "State updated successfully"

        return response
    
# ============================================================
# PATCH for robot_state_manager.py
# ============================================================
#
# 1) In __init__, after self.model / self.fk are created, add:
#
#     self.joint_names = self.model.model.get_joint_names()
#
# 2) Replace joint_callback and collision_joint_callback with the
#    name-matched versions below. Root cause: sensor_msgs/JointState
#    carries msg.name specifically because publishers are not
#    guaranteed to order joints consistently — the original code
#    discarded msg.name and trusted msg.position's raw array order,
#    which silently scrambles any target that differs from whatever
#    was last commanded (closed-loop/repeated trajectories still
#    "work" because they're self-consistently wrong).
# ============================================================

    def joint_callback(self, msg):
        name_to_pos = dict(zip(msg.name, msg.position))
        try:
            ordered = [name_to_pos[j] for j in self.joint_names]
        except KeyError as e:
            self.get_logger().warn(
                f'/joint_states missing expected joint {e} — '
                f'got names: {list(msg.name)}, expected: {self.joint_names}'
            )
            return
        self.q_current = np.array(ordered)
        self.last_update_time = self.get_clock().now()
        if self.initialized:
            self._last_joint_states_time = self.get_clock().now()


    def collision_joint_callback(self, msg):
        name_to_pos = dict(zip(msg.name, msg.position))
        try:
            ordered = [name_to_pos[j] for j in self.joint_names]
        except KeyError as e:
            self.get_logger().warn(
                f'/virtual_joint_states missing expected joint {e} — '
                f'got names: {list(msg.name)}, expected: {self.joint_names}'
            )
            return
        self.q_collision = np.array(ordered)
        self.last_update_time = self.get_clock().now()
        if self.initialized:
            self._last_virtual_joint_states_time = self.get_clock().now()

    def target_callback(self, msg):
        # Prevent override during initialization
        if not self.initialized:
            return

        self.target_pose = msg
        self.last_update_time = self.get_clock().now()

    def updated_target_callback(self, msg):
        # Prevent override during initialization
        if not self.initialized:
            return

        self.updated_target_pose = msg
        self.target_pose = self.updated_target_pose

        self.last_update_time = self.get_clock().now()

    # =========================================================
    # STATE PUBLISH LOOP
    # =========================================================

    def publish_state(self):
        # ---------------------------------
        # INITIALIZATION PHASE
        # ---------------------------------
        if not self.initialized:

            if self.system_mode == 'ACTIVE':
                if self.q_current is None:
                    return
                
                # Publish initial joint state
                q_msg = Float64MultiArray()
                q_msg.data = self.q_current.tolist()
                self.q_pub.publish(q_msg)
            else:
                if self.q_collision is None:
                    return
                
                # Publish initial joint state
                q_msg = Float64MultiArray()
                q_msg.data = self.q_collision.tolist()
                self.q_pub.publish(q_msg)

            # Publish initial target pose
            if self.target_pose is not None:
                self.pose_pub.publish(self.target_pose)

            # Publish initial system_mode / execution_state. These were
            # previously only published inside handle_system_mode() /
            # handle_execution_state() — meaning on a fresh boot, every
            # downstream consumer gating on them (kinematic_solver,
            # pose_target_interface, virtual_jog_relay) never received a
            # value until someone called /set_system_mode or
            # /set_execution_state by hand at least once.
            mode_msg = String()
            mode_msg.data = self.system_mode
            self.sys_mode_pub.publish(mode_msg)

            state_msg = String()
            state_msg.data = self.execution_state
            self.exec_state_pub.publish(state_msg)

            self.get_logger().info("Robot initialized with home_pose + FK target")

            self.initialized = True
            return

        # ---------------------------------
        # NORMAL OPERATION
        # ---------------------------------

        if self.system_mode == 'ACTIVE':
            if self.q_current is None:
                return
            
            # publish joint state
            q_msg = Float64MultiArray()
            q_msg.data = self.q_current.tolist()
            self.q_pub.publish(q_msg)
        else:
            if self.q_collision is None:
                return
            
            # publish joint state
            q_msg = Float64MultiArray()
            q_msg.data = self.q_collision.tolist()
            self.q_pub.publish(q_msg)

        # publish target pose
        if self.target_pose is not None:
            self.pose_pub.publish(self.target_pose)


# =========================================================
# MAIN
# =========================================================

def main(args=None):
    rclpy.init(args=args)
    node = RobotStateManager()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()