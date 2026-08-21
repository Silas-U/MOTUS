import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from std_srvs.srv import Trigger
from robokpy_interfaces.srv import ExecutionState, SystemMode

import json


class RobotCommandServer(Node):

    def __init__(self):

        super().__init__('robot_command_server')

        self.declare_parameter('default_gripper_tool_id', 'gripper_1')
        self.default_gripper_tool_id = self.get_parameter('default_gripper_tool_id').value

        # =====================================================
        # Publishers
        # =====================================================

        self.command_pub = self.create_publisher(
            String, 'motion_command', 10)
        
        self.tool_cmd_pub = self.create_publisher(String, 'tool_command', 10)

        # =====================================================
        # Sequence Planning
        # -----------------------------------------------------
        # Post a JSON array of steps to /command_sequence to
        # build a full move + tool-action plan in one shot,
        # instead of calling services one at a time.
        #
        # Each step is one of:
        #   {"type": "record_waypoint"}
        #   {"type": "set_tool", "tool_id": "gripper_1",
        #    "command": "close", "wait_mode": "time",
        #    "wait_value": 0.5}
        #   {"type": "set_tool", "tool_id": "gripper_1",
        #    "command": "open", "wait_mode": "topic",
        #    "wait_message": "gripper_1:opened"}
        #   {"type": "set_tool_action"}   # attaches last set_tool
        #                                  # to the last waypoint
        #   {"type": "movel"} / {"type": "movej"}
        #   {"type": "set_speed", "value": 0.5}
        #   {"type": "set_blend", "value": 0.1}
        #   {"type": "execute"}
        #   {"type": "go_home"}
        #   {"type": "clear_waypoints"}
        #   {"type": "raw", "cmd": "set_traj_type:lspb"}  # escape hatch
        #
        # Example:
        #   ros2 topic pub /command_sequence std_msgs/msg/String \
        #     "data: '[{\"type\":\"record_waypoint\"},
        #               {\"type\":\"set_tool\",\"tool_id\":\"gripper_1\",
        #                \"command\":\"close\",\"wait_mode\":\"time\",
        #                \"wait_value\":0.5},
        #               {\"type\":\"set_tool_action\"},
        #               {\"type\":\"record_waypoint\"},
        #               {\"type\":\"execute\"}]'" --once
        #
        # NOTE: steps are published back-to-back with no
        # completion wait — planner-side commands (record_waypoint,
        # set_tool, set_tool_action, clear_waypoints, config setters)
        # are synchronous and safe to fire rapidly. 'execute' should
        # be the LAST step in a sequence; motion/tool execution then
        # proceeds on its own via motion_planner/motion_controller.
        # =====================================================

        self.create_subscription(
            String, 'command_sequence',
            self.sequence_cb, 10)

        # =====================================================
        # Services — Waypoint Management
        # =====================================================

        self.create_service(
            Trigger, 'record_target',
            self.record_waypoint_callback)

        self.create_service(
            Trigger, 'exec_traj',
            self.execute_callback)

        self.create_service(
            Trigger, 'clear_target',
            self.clear_callback)

        self.create_service(
            Trigger, 'list_waypoints',
            self.list_waypoints_callback)

        # =====================================================
        # Services — Approach
        # =====================================================

        self.create_service(
            Trigger, 'set_as_approach',
            self.set_as_approach_callback)

        self.create_service(
            Trigger, 'goto_approach',
            self.goto_approach_callback)

        self.create_service(
            Trigger, 'clear_approach',
            self.clear_approach_callback)

        # =====================================================
        # Services — Motion
        # =====================================================

        self.create_service(
            Trigger, 'go_home',
            self.go_home_callback)

        self.create_service(
            Trigger, 'stop',
            self.stop_callback)

        # =====================================================
        # Services — System Mode
        # =====================================================

        self.create_service(
            Trigger, 'planner_mode',
            self.planner_mode_callback)

        self.create_service(
            Trigger, 'active_mode',
            self.active_mode_callback)

        # =====================================================
        # Services — Trajectory Type
        # =====================================================

        self.create_service(
            Trigger, 'movel',
            self.movel_callback)

        self.create_service(
            Trigger, 'movej',
            self.movej_callback)

        # =====================================================
        # Services — New segment config commands
        # (all use StringCommand pattern via /motion_command)
        # =====================================================

        self.create_service(
            Trigger, 'traj_type_lspb',
            self.traj_type_lspb_callback)

        self.create_service(
            Trigger, 'traj_type_blend_js',
            self.traj_type_blend_js_callback)

        self.create_service(
            Trigger, 'traj_type_blend_ts',
            self.traj_type_blend_ts_callback)

        self.create_service(
            Trigger, 'traj_type_quintic',
            self.traj_type_quintic_callback)

        
        # Parameterised commands — accept a value string
        # e.g. ros2 service call /set_speed std_srvs/srv/Trigger
        # is insufficient for values; these use a String service instead
        self._create_string_services()

        # -----------------------------
        # SYSTEM MODE CLIENT
        # -----------------------------
        self.sys_mode_client = self.create_client(
            SystemMode,
            'set_system_mode'
        )

        while not self.sys_mode_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("Checking for control services...")

        self.get_logger().info("Service available")

        self.request_system_mode("PLANNER")

        self.get_logger().info('Command Server Ready')

    # =========================================================
    # SEQUENCE PLANNING
    # =========================================================

    def sequence_cb(self, msg: String):
        try:
            steps = json.loads(msg.data)
        except Exception as e:
            self.get_logger().error(f'Invalid sequence JSON: {e}')
            return

        if not isinstance(steps, list):
            self.get_logger().error('Sequence must be a JSON array of steps')
            return

        self.get_logger().info(f'Running sequence: {len(steps)} step(s)')

        for i, step in enumerate(steps):
            try:
                self._run_step(step)
            except Exception as e:
                self.get_logger().error(
                    f'Sequence step {i} failed ({step}): {e}')
                return

    def _run_step(self, step: dict):
        step_type = step.get('type', '').strip().lower()

        if step_type == 'set_tool':
            tool_id   = step.get('tool_id') or self.default_gripper_tool_id
            command   = step['command']
            wait_mode = step.get('wait_mode', 'time').lower()

            if wait_mode == 'topic':
                value = step.get('wait_message', '')
            elif wait_mode == 'none':
                value = 0
            else:
                value = step.get('wait_value', 0.5)

            self.publish_command(f'set_tool:{tool_id}:{command}:{wait_mode}:{value}')

        elif step_type == 'set_speed':
            self.publish_command(f'set_speed:{step["value"]}')

        elif step_type == 'set_blend':
            self.publish_command(f'set_blend:{step["value"]}')

        elif step_type == 'set_duration':
            self.publish_command(f'set_duration:{step["value"]}')

        elif step_type == 'set_traj_type':
            self.publish_command(f'set_traj_type:{step["value"]}')

        elif step_type == 'set_traj_method':
            self.publish_command(f'set_traj_method:{step["value"]}')

        elif step_type == 'delete_waypoint':
            self.publish_command(f'delete_waypoint:{step["waypoint_id"]}')

        elif step_type == 'clear_tool_action':
            self.publish_command(f'clear_tool_action:{step["waypoint_id"]}')

        elif step_type == 'raw':
            self.publish_command(step['cmd'])

        elif step_type == 'planner_mode':
            self.request_system_mode('PLANNER')

        elif step_type == 'active_mode':
            self.request_system_mode('ACTIVE')

        elif step_type == 'speed_full':
            self.publish_command('set_speed:1.0')

        elif step_type == 'speed_half':
            self.publish_command('set_speed:0.5')

        elif step_type == 'speed_quarter':
            self.publish_command('set_speed:0.25')

        elif step_type == 'gripper':
            tool_id = step.get('tool_id')  # may be None — let server decide
            command = step['command']
            self.publish_gripper_command(tool_id, command)

        elif step_type in (
            'record_waypoint', 'set_tool_action', 'execute',
            'go_home', 'goto_approach', 'set_approach', 'clear_approach',
            'clear_waypoints', 'clear_all_tool_actions', 'list_waypoints',
            'list_tool_actions', 'movel', 'movej',
        ):
            self.publish_command(step_type)

        else:
            self.get_logger().warn(f'Unknown sequence step type: "{step_type}"')

    # =========================================================
    # STRING-VALUE SERVICES
    # =========================================================

    def request_system_mode(self, mode):
        request = SystemMode.Request()
        request.new_mode = mode

        future = self.sys_mode_client.call_async(request)

        future.add_done_callback(
            self.handle_response
        )

    def handle_response(self, future):
        try:
            response = future.result()

            self.get_logger().info(f"Success: {response.success}")
            self.get_logger().info(f"Message: {response.message}")
        except Exception as e:
            self.get_logger().info(f"Service call failed: {e}")

    def _create_string_services(self):
        """
        Services that carry a float value are exposed via a
        dedicated topic-style approach: the client publishes a
        command string directly to /motion_command.

        Convenience Trigger wrappers are provided for fixed
        presets below. For arbitrary values, publish directly:
          ros2 topic pub /motion_command std_msgs/msg/String
            "data: 'set_speed:0.5'"
        """
        # Preset speed services
        self.create_service(
            Trigger, 'speed_full',
            lambda req, res: self._cmd_response(req, res, 'set_speed:1.0',
                                                'Speed set to 100%'))
        self.create_service(
            Trigger, 'speed_half',
            lambda req, res: self._cmd_response(req, res, 'set_speed:0.5',
                                                'Speed set to 50%'))
        self.create_service(
            Trigger, 'speed_quarter',
            lambda req, res: self._cmd_response(req, res, 'set_speed:0.25',
                                                'Speed set to 25%'))

        # Preset blend radius services
        self.create_service(
            Trigger, 'blend_off',
            lambda req, res: self._cmd_response(req, res, 'set_blend:0.0',
                                                'Blend radius off'))
        self.create_service(
            Trigger, 'blend_small',
            lambda req, res: self._cmd_response(req, res, 'set_blend:0.1',
                                                'Blend radius 10%'))
        self.create_service(
            Trigger, 'blend_medium',
            lambda req, res: self._cmd_response(req, res, 'set_blend:0.2',
                                                'Blend radius 20%'))
        self.create_service(
            Trigger, 'blend_large',
            lambda req, res: self._cmd_response(req, res, 'set_blend:0.3',
                                                'Blend radius 30%'))

        
        self.create_service(
            Trigger, 'open_gripper',
            lambda req, res: self._gripper_response(req, res, None, 'open'))
        self.create_service(
            Trigger, 'close_gripper',
            lambda req, res: self._gripper_response(req, res, None, 'close'))


    def publish_gripper_command(self, tool_id, command: str):
        tid = tool_id if tool_id else self.default_gripper_tool_id
        msg = String()
        msg.data = f'{tid}:{command}'
        self.tool_cmd_pub.publish(msg)

    # =========================================================
    # HELPERS
    # =========================================================

    def _gripper_response(self, request, response, tool_id, command):
        self.publish_gripper_command(tool_id, command)
        response.success = True
        response.message = f'{tool_id}:{command} sent'
        return response


    def publish_command(self, cmd: str):
        msg      = String()
        msg.data = cmd
        self.command_pub.publish(msg)

    def _cmd_response(self, request, response, cmd: str, message: str):
        """Generic handler: publish cmd and return success response."""
        self.publish_command(cmd)
        response.success = True
        response.message = message
        return response

    # =========================================================
    # WAYPOINT MANAGEMENT
    # =========================================================

    def record_waypoint_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'record_waypoint', 'Record waypoint command sent')

    def execute_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'execute', 'Execute command sent')

    def clear_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'clear_waypoints', 'Clear waypoints command sent')

    def list_waypoints_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'list_waypoints', 'List waypoints command sent')

    # =========================================================
    # APPROACH
    # =========================================================

    def set_as_approach_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'set_approach', 'Set approach command sent')

    def goto_approach_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'goto_approach', 'Go to approach command sent')

    def clear_approach_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'clear_approach', 'Clear approach command sent')

    # =========================================================
    # MOTION
    # =========================================================

    def go_home_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'go_home', 'Go home command sent')

    def stop_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'stop', 'Stop command sent')

    # =========================================================
    # SYSTEM MODE
    # =========================================================

    def planner_mode_callback(self, request, response):
        self.request_system_mode("PLANNER")
        response.success = True
        return response


    def active_mode_callback(self, request, response):
        self.request_system_mode("ACTIVE")
        response.success = True
        return response

    # =========================================================
    # TRAJECTORY TYPE
    # =========================================================

    def movel_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'movel', 'MoveL (Cartesian blend) command sent')

    def movej_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'movej', 'MoveJ (joint LSPB) command sent')

    def traj_type_lspb_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'set_traj_type:lspb', 'Traj type set to LSPB')

    def traj_type_blend_js_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'set_traj_method:js\nset_traj_type:blend', 'Traj set to JS blend')

    def traj_type_blend_ts_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'set_traj_method:ts\nset_traj_type:blend',
            'Traj set to Cartesian blend')

    def traj_type_quintic_callback(self, request, response):
        return self._cmd_response(
            request, response,
            'set_traj_type:tqu', 'Traj type set to timed quintic')


# =========================================================
# MAIN
# =========================================================

def main(args=None):
    rclpy.init(args=args)
    node = RobotCommandServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()