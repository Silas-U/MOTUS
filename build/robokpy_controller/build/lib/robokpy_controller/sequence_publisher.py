#!/usr/bin/env python3
"""
Motus — Sequence Publisher
Publishes a JSON step list to /command_sequence for robot_command_server.

Usage:
  # Inline JSON
  ros2 run robokpy_controller sequence_pub --json \
    '[{"type":"record_waypoint"},{"type":"set_tool_action"}]'

  # From a saved plan file
  ros2 run robokpy_controller sequence_pub --file pick_place.json

  # Append one waypoint + tool action quickly while teaching
  # (uses server default tool_id unless --tool-id is given)
  ros2 run robokpy_controller sequence_pub --record-tool close time 0.5
  ros2 run robokpy_controller sequence_pub --record-tool close time 0.5 --tool-id gripper_2

  # Other one-shot shortcuts
  ros2 run robokpy_controller sequence_pub --go-home
  ros2 run robokpy_controller sequence_pub --set-approach
  ros2 run robokpy_controller sequence_pub --goto-approach
  ros2 run robokpy_controller sequence_pub --clear-approach
  ros2 run robokpy_controller sequence_pub --clear-waypoints
  ros2 run robokpy_controller sequence_pub --list-waypoints
  ros2 run robokpy_controller sequence_pub --delete-waypoint wp_003
  ros2 run robokpy_controller sequence_pub --stop
  ros2 run robokpy_controller sequence_pub --planner-mode
  ros2 run robokpy_controller sequence_pub --active-mode
  ros2 run robokpy_controller sequence_pub --movel
  ros2 run robokpy_controller sequence_pub --movej
  ros2 run robokpy_controller sequence_pub --speed-full
  ros2 run robokpy_controller sequence_pub --speed-half
  ros2 run robokpy_controller sequence_pub --speed-quarter
  ros2 run robokpy_controller sequence_pub --open-gripper [TOOL_ID]
  ros2 run robokpy_controller sequence_pub --close-gripper [TOOL_ID]
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

import argparse
import json
import sys
import time


class SequencePublisher(Node):

    def __init__(self):
        super().__init__('sequence_pub')
        self.pub = self.create_publisher(String, '/command_sequence', 10)

    def send(self, steps: list):
        msg = String()
        msg.data = json.dumps(steps)
        # give discovery a moment on cold start so the message isn't dropped
        time.sleep(0.3)
        self.pub.publish(msg)
        self.get_logger().info(f'Sequence sent: {len(steps)} step(s)')


def build_record_tool_steps(tool_id, command, wait_mode, wait_value):
    step = {
        'type':      'set_tool',
        'command':   command,
        'wait_mode': wait_mode,
    }
    if tool_id:
        step['tool_id'] = tool_id  # omitted -> server falls back to default_gripper_tool_id

    if wait_mode == 'topic':
        step['wait_message'] = wait_value
    else:
        step['wait_value'] = float(wait_value)

    return [
        {'type': 'record_waypoint'},
        step,
        {'type': 'set_tool_action'},
    ]


def main():
    parser = argparse.ArgumentParser(description='Publish a JSON step sequence to /command_sequence')
    group  = parser.add_mutually_exclusive_group(required=True)

    group.add_argument('--json', type=str,
                        help='Inline JSON array of steps')
    group.add_argument('--file', type=str,
                        help='Path to a JSON file containing an array of steps')
    group.add_argument('--record', action='store_true',
                        help='Shortcut: record_waypoint only (no tool action)')
    group.add_argument('--record-tool', nargs=3,
                        metavar=('COMMAND', 'WAIT_MODE', 'WAIT_VALUE'),
                        help='Shortcut: record_waypoint + set_tool + set_tool_action. '
                             'Use --tool-id to specify a tool; omit for server default.')
    group.add_argument('--execute', action='store_true',
                        help='Shortcut: execute only')
    group.add_argument('--go-home', action='store_true',
                        help='Shortcut: go_home only')
    group.add_argument('--stop', action='store_true',
                        help='Shortcut: stop only')
    group.add_argument('--set-approach', action='store_true',
                        help='Shortcut: mark current pose as approach')
    group.add_argument('--goto-approach', action='store_true',
                        help='Shortcut: move to saved approach pose')
    group.add_argument('--clear-approach', action='store_true',
                        help='Shortcut: clear saved approach pose')
    group.add_argument('--clear-waypoints', action='store_true',
                        help='Shortcut: clear all waypoints + segments + tool actions')
    group.add_argument('--list-waypoints', action='store_true',
                        help='Shortcut: log current waypoints/segments')
    group.add_argument('--delete-waypoint', type=str, metavar='WP_ID',
                        help='Shortcut: delete_waypoint:<WP_ID>')
    group.add_argument('--planner-mode', action='store_true',
                        help='Shortcut: switch to PLANNER mode (virtual only)')
    group.add_argument('--active-mode', action='store_true',
                        help='Shortcut: switch to ACTIVE mode (drives Gazebo)')
    group.add_argument('--movel', action='store_true',
                        help='Shortcut: movel (Cartesian blend)')
    group.add_argument('--movej', action='store_true',
                        help='Shortcut: movej (joint LSPB)')
    group.add_argument('--speed-full', action='store_true',
                        help='Shortcut: set_speed:1.0')
    group.add_argument('--speed-half', action='store_true',
                        help='Shortcut: set_speed:0.5')
    group.add_argument('--speed-quarter', action='store_true',
                        help='Shortcut: set_speed:0.25')
    group.add_argument('--open-gripper', nargs='?', const=None, metavar='TOOL_ID',
                    help='Shortcut: immediately open gripper (uses --tool-id or server default if omitted)')
    group.add_argument('--close-gripper', nargs='?', const=None, metavar='TOOL_ID',
                    help='Shortcut: immediately close gripper (uses --tool-id or server default if omitted)')

    # Not part of the mutually exclusive group — applies as an override to
    # --record-tool / --open-gripper / --close-gripper. Omit to fall back
    # to the server's default_gripper_tool_id.
    parser.add_argument('--tool-id', type=str, default=None,
                         help='Optional tool_id override for --record-tool, '
                              '--open-gripper, --close-gripper')

    args, _ = parser.parse_known_args()

    SIMPLE_FLAG_STEPS = {
        'go_home':        'go_home',
        'stop':            'stop',
        'set_approach':    'set_approach',
        'goto_approach':   'goto_approach',
        'clear_approach':  'clear_approach',
        'clear_waypoints': 'clear_waypoints',
        'list_waypoints':  'list_waypoints',
        'planner_mode':    'planner_mode',
        'active_mode':     'active_mode',
        'movel':           'movel',
        'movej':           'movej',
        'speed_full':      'speed_full',
        'speed_half':      'speed_half',
        'speed_quarter':   'speed_quarter',
    }

    if args.json:
        try:
            steps = json.loads(args.json)
        except json.JSONDecodeError as e:
            print(f'Invalid JSON: {e}')
            sys.exit(1)

    elif args.file:
        try:
            with open(args.file, 'r') as f:
                steps = json.load(f)
        except (OSError, json.JSONDecodeError) as e:
            print(f'Failed to read/parse {args.file}: {e}')
            sys.exit(1)

    elif args.record:
        steps = [{'type': 'record_waypoint'}]

    elif args.record_tool:
        command, wait_mode, wait_value = args.record_tool
        steps = build_record_tool_steps(args.tool_id, command, wait_mode, wait_value)

    elif args.execute:
        steps = [{'type': 'execute'}]

    elif args.delete_waypoint:
        steps = [{'type': 'delete_waypoint', 'waypoint_id': args.delete_waypoint}]

    elif args.open_gripper is not None or '--open-gripper' in sys.argv:
        steps = [{'type': 'gripper', 'command': 'open'}]
        tid = args.open_gripper or args.tool_id
        if tid:
            steps[0]['tool_id'] = tid

    elif args.close_gripper is not None or '--close-gripper' in sys.argv:
        steps = [{'type': 'gripper', 'command': 'close'}]
        tid = args.close_gripper or args.tool_id
        if tid:
            steps[0]['tool_id'] = tid

    else:
        # Simple no-argument shortcuts: --go-home, --stop, --set-approach,
        # --goto-approach, --clear-approach, --clear-waypoints, --list-waypoints
        matched = next(
            (name for name in SIMPLE_FLAG_STEPS
             if getattr(args, name)), None
        )
        if matched is None:
            print('No sequence specified')
            sys.exit(1)
        steps = [{'type': SIMPLE_FLAG_STEPS[matched]}]

    if not isinstance(steps, list):
        print('Sequence must be a JSON array of step objects')
        sys.exit(1)

    rclpy.init()
    node = SequencePublisher()
    node.send(steps)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()