#!/usr/bin/env python3
"""
run_recipe.py

Merges the two existing cell_orchestrator services — load_recipe and
start_recipe — into one command, replacing calling them separately by
hand.

    ros2 run robokpy_controller run_recipe /path/to/recipe.yaml

Deliberately does NOT run preflight_recipe first — that plans every run
in full, and chaining it in here would mean paying for trajectory
generation twice on every single dispatch (preflight's plan, then
arm_executor's own real plan at execution time). Run
`ros2 run robokpy_controller preflight_recipe ...` separately, on your
own schedule (e.g. after editing a recipe), when you want that check.
"""

import argparse
import sys

import rclpy
from rclpy.node import Node
from std_srvs.srv import Trigger

from robokpy_interfaces.srv import LoadRecipe


class _RecipeRunner(Node):
    def __init__(self):
        super().__init__('run_recipe_client')
        self._load_client = self.create_client(LoadRecipe, 'load_recipe')
        self._start_client = self.create_client(Trigger, 'start_recipe')

    def load_and_start(self, recipe_path: str) -> bool:
        if not self._load_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error(
                "[run_recipe] 'load_recipe' service not available — "
                "is cell_orchestrator running?")
            return False

        req = LoadRecipe.Request()
        req.recipe_path = recipe_path
        future = self._load_client.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=15.0)

        if future.result() is None:
            self.get_logger().error('[run_recipe] load_recipe call timed out')
            return False
        if not future.result().success:
            self.get_logger().error(
                f'[run_recipe] load_recipe rejected: {future.result().message}')
            return False

        self.get_logger().info(f'[run_recipe] {future.result().message}')

        if not self._start_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().error("[run_recipe] 'start_recipe' service not available")
            return False

        start_future = self._start_client.call_async(Trigger.Request())
        rclpy.spin_until_future_complete(self, start_future, timeout_sec=15.0)

        if start_future.result() is None:
            self.get_logger().error('[run_recipe] start_recipe call timed out')
            return False
        if not start_future.result().success:
            self.get_logger().error(
                f'[run_recipe] start_recipe rejected: {start_future.result().message}')
            return False

        self.get_logger().info(f'[run_recipe] {start_future.result().message}')
        return True


def main():
    parser = argparse.ArgumentParser(
        description='Load and start a recipe in one command.')
    parser.add_argument('recipe_path')
    args = parser.parse_args()

    rclpy.init()
    node = _RecipeRunner()
    ok = node.load_and_start(args.recipe_path)
    node.destroy_node()
    rclpy.shutdown()
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()