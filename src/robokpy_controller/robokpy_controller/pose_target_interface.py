import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Pose, Point
from visualization_msgs.msg import InteractiveMarker
from visualization_msgs.msg import InteractiveMarkerControl
from visualization_msgs.msg import InteractiveMarkerFeedback
from interactive_markers.interactive_marker_server import InteractiveMarkerServer
from interactive_markers.menu_handler import MenuHandler
from std_msgs.msg import Float64MultiArray, String
from robokpy_interfaces.msg import CellState as CellStateMsg
from rclpy.qos import QoSProfile
from rclpy.qos import DurabilityPolicy

from rcl_interfaces.msg import SetParametersResult
import os
import yaml
import numpy as np
from robokpy_controller.ik_factory import build_model

class PoseTargetInterface(Node):

    def __init__(self):
        super().__init__('pose_target_interface')

        self.declare_parameter('robot_description', "")
        robot_description = self.get_parameter('robot_description').value

        self.declare_parameter('world_frame','world')
        self.world_frame = self.get_parameter('world_frame').value

        self.declare_parameter('planning_base_link', 'world')
        self.declare_parameter('planning_tip_link',  'tcp')
        self.base_link = self.get_parameter('planning_base_link').value
        self.tip_link  = self.get_parameter('planning_tip_link').value

        # Waypoints captured via the marker's right-click menu, kept
        # per-recipe. Effective recipe context is:
        #   teach_session_override (if set)  ->  else /cell_state's
        #   active_recipe_id (auto-tracked). This lets you teach
        #   waypoints for a brand-new recipe that doesn't exist as a
        #   loaded YAML yet (set the override, name the session
        #   yourself), while still auto-following whatever's loaded
        #   the rest of the time with zero extra steps.
        self.declare_parameter('waypoint_output_dir', '')
        self.waypoint_output_dir = self.get_parameter('waypoint_output_dir').value
        self.declare_parameter('teach_session_override', '')
        self._teach_override = self.get_parameter('teach_session_override').value
        self._captured_waypoints = []
        self._active_recipe_id = ''      # auto-tracked from /cell_state
        self._last_effective_id = ''     # last id captures were cleared against
        self.add_on_set_parameters_callback(self._on_param_change)

        self.declare_parameter('kinematic_solver_backend', 'robokpy')
        backend = self.get_parameter('kinematic_solver_backend').value
        self.model = build_model(
            robot_description,
            base_link=self.base_link,
            tip_link=self.tip_link,
            backend=backend,
        )
        self.fk = self.model.fk

        num_joints = self.model.model.get_num_act_joints_in_chain(self.base_link, self.tip_link)

        self.declare_parameter('home_pose', [0.0]*num_joints)
        self.home_q = np.array(self.get_parameter('home_pose').value)

        self.fk.compute_chain(self.home_q, self.base_link, self.tip_link)
        self.home_pose = self.fk.get_pose_quart()

        self.declare_parameter('marker_scale', 0.2)
        self.marker_scale = float(self.get_parameter('marker_scale').value)

        self.get_logger().info(f"home_pose={self.home_pose}")   # print AFTER compute_chain instead

        self.marker_visible = True

        self.sys_mode = None
        self.target_pose = None
        self.q_current = None

        # -----------------------------
        # Subscriptions
        # -----------------------------
        # TRANSIENT_LOCAL to match robot_state_manager's publisher —
        # without this, a late-starting interface misses the single initial
        # publish and stays deaf forever.
        mode_qos = QoSProfile(depth=1)
        mode_qos.durability = DurabilityPolicy.TRANSIENT_LOCAL

        self.create_subscription(String, 'execution_state', self.exec_state_cb, mode_qos)
        self.create_subscription(String, 'system_mode', self.sys_mode_cb, mode_qos)
        self.create_subscription(CellStateMsg, 'cell_state', self.cell_state_cb, 10)
        self.create_subscription(Pose, 'active_target_pose', self.active_pose_callback, 10)

        qos = QoSProfile(depth=1)
        qos.durability = DurabilityPolicy.TRANSIENT_LOCAL  # late joiners get last value, like sys_mode
        self.create_subscription(String, 'planning_tip_link', self.tip_link_cb, qos)

        self.create_subscription(Float64MultiArray, 'current_joint_state', self.joint_state_cb, 10)
        
        # -----------------------------
        # Publisher
        # -----------------------------
        self.pose_pub = self.create_publisher(Pose, 'target_pose', 10)

        # -----------------------------
        # Marker Server
        # -----------------------------
        self.server = InteractiveMarkerServer(self, "ik_marker_server")

        self.menu_handler = MenuHandler()
        self._menu_capture_id = self.menu_handler.insert(
            "Capture Waypoint", callback=self.process_feedback)
        self._menu_write_id = self.menu_handler.insert(
            "Write captured waypoints to file", callback=self.process_feedback)
        self._menu_home_id = self.menu_handler.insert(
            "Jog to Home", callback=self.process_feedback)
        self._menu_revert_id = self.menu_handler.insert(
            "Revert to Last Captured Waypoint", callback=self.process_feedback)

        self.marker = self.create_marker(self.home_pose)

        self.server.insert(self.marker)
        self.server.setCallback(self.marker.name, self.process_feedback)
        self.menu_handler.apply(self.server, self.marker.name)
        self.server.applyChanges()

        self.get_logger().info("Interactive Marker Node started")

    # =========================================================
    # MARKER CREATION
    # =========================================================
   
    def joint_state_cb(self, msg):
        self.q_current = np.array(msg.data)
        

    def _move_marker_to(self, pose_arr):
        """Snap the marker — and, via target_pose, the virtual robot —
        to an explicit [x,y,z,qx,qy,qz,qw] pose. Shared by tip_link_cb
        and the Jog to Home / Revert menu actions below; all three need
        the identical erase/insert/re-apply-menu/publish sequence."""
        self.server.erase(self.marker.name)
        self.server.applyChanges()

        self.marker = self.create_marker(pose_arr)
        self.server.insert(self.marker)
        self.server.setCallback(self.marker.name, self.process_feedback)
        self.menu_handler.apply(self.server, self.marker.name)
        self.server.applyChanges()

        pose_msg = Pose()
        pose_msg.position.x, pose_msg.position.y, pose_msg.position.z = pose_arr[:3]
        (pose_msg.orientation.x, pose_msg.orientation.y,
         pose_msg.orientation.z, pose_msg.orientation.w) = pose_arr[3:]
        self.pose_pub.publish(pose_msg)

    def tip_link_cb(self, msg):
        self.tip_link = msg.data
        self.model.ik.tip_link = msg.data

        q_ref = self.q_current if self.q_current is not None else self.home_q
        self.fk.compute_chain(q_ref, self.base_link, self.tip_link)
        new_pose = self.fk.get_pose_quart()

        # Push the corrected pose into the actual target pipeline so
        # kinematic_solver stops solving against the OLD tip_link's
        # stale numeric target — this is what was pulling the arm down.
        self._move_marker_to(new_pose)

        self.get_logger().info(f'planning_tip_link updated -> {msg.data}')


    def _effective_recipe_id(self) -> str:
        return self._teach_override if self._teach_override else self._active_recipe_id

    def _update_context(self):
        """Clear captures when the effective teach context changes —
        whether that's because /cell_state loaded a different recipe,
        or because teach_session_override was set/changed/cleared."""
        effective = self._effective_recipe_id()
        if effective != self._last_effective_id:
            if self._captured_waypoints:
                self.get_logger().warn(
                    f'Teach context changed ({self._last_effective_id or "none"} -> '
                    f'{effective or "none"}) — clearing {len(self._captured_waypoints)} '
                    f'unsaved waypoint(s). Write them out before switching if needed.')
            self._captured_waypoints = []
            self._last_effective_id = effective

    def _on_param_change(self, params):
        for p in params:
            if p.name == 'teach_session_override':
                self._teach_override = p.value
                self.get_logger().info(
                    f'teach_session_override -> "{p.value}"' if p.value
                    else 'teach_session_override cleared — following /cell_state again')
                self._update_context()
        return SetParametersResult(successful=True)

    def cell_state_cb(self, msg: CellStateMsg):
        self._active_recipe_id = msg.active_recipe_id
        self._update_context()

    def sys_mode_cb(self, msg):
        if self.sys_mode != msg.data:
            self.get_logger().info(f'pose_target_interface: system_mode -> {msg.data}')
        self.sys_mode = msg.data

        if self.sys_mode == "PLANNER":
            self.show_marker_at_current_pose()
        elif self.sys_mode == "ACTIVE":
            self.hide_marker()

    
    def exec_state_cb(self, msg):
        exec_state = msg.data
        if not hasattr(self, '_last_exec_state') or self._last_exec_state != exec_state:
            self._last_exec_state = exec_state
            self.get_logger().info(f'pose_target_interface: execution_state -> {exec_state}')

        if exec_state == "EXECUTING":
            self.hide_marker()
        elif exec_state == "SERVO" and self.sys_mode == "PLANNER":
            self.show_marker_at_current_pose()


    def hide_marker(self):
        if not self.marker_visible:
            return
        
        self.server.clear()   # removes all markers
        self.server.applyChanges()
        self.marker_visible = False

    def active_pose_callback(self, msg):
        
        pose = np.array([
            msg.position.x,
            msg.position.y,
            msg.position.z,
            msg.orientation.x,
            msg.orientation.y,
            msg.orientation.z,
            msg.orientation.w
        ])

        self.target_pose = pose
        
    def create_marker(self, marker_pose):

        int_marker = InteractiveMarker()
        int_marker.header.frame_id = self.world_frame
        int_marker.name = "ik_target"
        int_marker.description = "[Motus]"
        int_marker.scale = self.marker_scale

        x_0, y_0, z_0, roll_0, pitch_0, yaw_0, w_0 =  marker_pose

        # Initial pose
        int_marker.pose.position.x = x_0
        int_marker.pose.position.y = y_0
        int_marker.pose.position.z = z_0
        int_marker.pose.orientation.x = roll_0
        int_marker.pose.orientation.y = pitch_0
        int_marker.pose.orientation.z = yaw_0
        int_marker.pose.orientation.w = w_0

        # ---- X axis ----
        control_x = InteractiveMarkerControl()
        control_x.orientation.w = 1.0
        control_x.orientation.x = 1.0
        control_x.orientation.y = 0.0
        control_x.orientation.z = 0.0
        control_x.name = "move_x"
        control_x.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        int_marker.controls.append(control_x)

        # ---- Y axis ----
        control_y = InteractiveMarkerControl()
        control_y.orientation.w = 1.0
        control_y.orientation.x = 0.0
        control_y.orientation.y = 1.0
        control_y.orientation.z = 0.0
        control_y.name = "move_y"
        control_y.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        int_marker.controls.append(control_y)

        # ---- Z axis ----
        control_z = InteractiveMarkerControl()
        control_z.orientation.w = 1.0
        control_z.orientation.x = 0.0
        control_z.orientation.y = 0.0
        control_z.orientation.z = 1.0
        control_z.name = "move_z"
        control_z.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        int_marker.controls.append(control_z)

        # Rotate X
        control_rx = InteractiveMarkerControl()
        control_rx.orientation.w = 1.0
        control_rx.orientation.x = 1.0
        control_rx.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        int_marker.controls.append(control_rx)

        # Rotate Y
        control_ry = InteractiveMarkerControl()
        control_ry.orientation.w = 1.0
        control_ry.orientation.y = 1.0
        control_ry.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        int_marker.controls.append(control_ry)

        # Rotate Z
        control_rz = InteractiveMarkerControl()
        control_rz.orientation.w = 1.0
        control_rz.orientation.z = 1.0
        control_rz.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        int_marker.controls.append(control_rz)

        # Menu (right-click) — waypoint capture actions
        control_menu = InteractiveMarkerControl()
        control_menu.interaction_mode = InteractiveMarkerControl.MENU
        control_menu.name = "menu"
        control_menu.always_visible = True
        int_marker.controls.append(control_menu)

        return int_marker

    def show_marker_at_current_pose(self):
        if self.marker_visible:
            return

        if self.target_pose is not None:
            pose = self.target_pose
        elif self.q_current is not None:
            # Fallback: compute directly instead of waiting on the
            # /updated_target_pose -> /active_target_pose round trip,
            # which races against the SERVO transition after go_home.
            self.fk.compute_chain(self.q_current, self.base_link, self.tip_link)
            pose = self.fk.get_pose_quart()
        else:
            self.get_logger().warn("No robot pose available")
            return

        self.marker = self.create_marker(pose)
        self.server.insert(self.marker)
        self.server.setCallback(self.marker.name, self.process_feedback)
        self.menu_handler.apply(self.server, self.marker.name)
        self.server.applyChanges()
        self.marker_visible = True

    # =========================================================
    # CALLBACK
    # =========================================================

    def process_feedback(self, feedback):

        # Defense-in-depth: pose_target_interface already hides the
        # marker outside PLANNER (see sys_mode_cb/exec_state_cb), so
        # this should be unreachable in ACTIVE — but guard here too so
        # a stray/queued feedback message can't leak a pose or capture
        # while the real robot is running.
        if self.sys_mode != "PLANNER":
            return

        if feedback.event_type == InteractiveMarkerFeedback.MENU_SELECT:
            if feedback.menu_entry_id == self._menu_capture_id:
                self._capture_waypoint(feedback.pose)
            elif feedback.menu_entry_id == self._menu_write_id:
                self._write_captured_waypoints()
            elif feedback.menu_entry_id == self._menu_home_id:
                self._jog_to_home()
            elif feedback.menu_entry_id == self._menu_revert_id:
                self._jog_to_last_captured()
            return

        pose = Pose()
        pose.position = feedback.pose.position
        pose.orientation = feedback.pose.orientation

        self.pose_pub.publish(pose)

    def _jog_to_home(self):
        """Snap the marker + virtual robot to home_pose (the FK of the
        home_pose param — same joint values used as the IK fallback
        seed in arm_executor). Right-click 'Capture Waypoint'
        afterward to get this exact, guaranteed-reachable pose into
        the recipe as an explicit leg 0 — safer than relying on
        wherever the arm happened to already be."""
        self.get_logger().info('Jogging virtual robot to home_pose')
        self._move_marker_to(self.home_pose)

    def _jog_to_last_captured(self):
        """Undo an accidental drag: snap back to the last waypoint
        that was actually captured this session (not just wherever
        the marker was last moved to)."""
        if not self._captured_waypoints:
            self.get_logger().warn(
                'No captured waypoints yet this session — nothing to revert to')
            return

        wp = self._captured_waypoints[-1]
        pose_arr = np.array([
            wp['x'], wp['y'], wp['z'],
            wp['qx'], wp['qy'], wp['qz'], wp['qw'],
        ])

        self.get_logger().info(
            f'Reverting to last captured waypoint (#{len(self._captured_waypoints)}): '
            f'{{x: {wp["x"]:.4f}, y: {wp["y"]:.4f}, z: {wp["z"]:.4f}, '
            f'qx: {wp["qx"]:.4f}, qy: {wp["qy"]:.4f}, qz: {wp["qz"]:.4f}, qw: {wp["qw"]:.4f}}}'
        )
        self._move_marker_to(pose_arr)

    def _capture_waypoint(self, pose: Pose):
        entry = {
            'x': pose.position.x, 'y': pose.position.y, 'z': pose.position.z,
            'qx': pose.orientation.x, 'qy': pose.orientation.y,
            'qz': pose.orientation.z, 'qw': pose.orientation.w,
        }
        self._captured_waypoints.append(entry)
        self.get_logger().info(
            f'Captured waypoint #{len(self._captured_waypoints)}: '
            f'target_pose: {{x: {entry["x"]:.4f}, y: {entry["y"]:.4f}, z: {entry["z"]:.4f}, '
            f'qx: {entry["qx"]:.4f}, qy: {entry["qy"]:.4f}, qz: {entry["qz"]:.4f}, qw: {entry["qw"]:.4f}}}'
        )

    def _write_captured_waypoints(self):
        if not self._captured_waypoints:
            self.get_logger().warn('No waypoints captured yet — nothing to write')
            return
        if not self.waypoint_output_dir:
            self.get_logger().warn(
                'waypoint_output_dir parameter not set — logging waypoints instead')
            for i, wp in enumerate(self._captured_waypoints):
                self.get_logger().info(f'waypoint[{i}]: {wp}')
            return
        recipe_id = self._effective_recipe_id() or 'untitled'
        out_path = os.path.join(self.waypoint_output_dir, f'{recipe_id}_waypoints.yaml')
        with open(out_path, 'w') as f:
            yaml.safe_dump({'recipe_id': recipe_id, 'waypoints': self._captured_waypoints},
                            f, sort_keys=False)
        self.get_logger().info(
            f'Wrote {len(self._captured_waypoints)} waypoint(s) for recipe '
            f'"{recipe_id}" -> {out_path}')


# =========================================================
# MAIN
# =========================================================

def main(args=None):
    rclpy.init(args=args)
    node = PoseTargetInterface()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()