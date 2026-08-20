"""
arm_registry.py

Maps a MoveStep's arm_id to the namespaced ExecuteMoveStep action client
for that arm. Built once at node init from the arm_namespaces parameter.
Adding a second arm is a launch-file/param change only — nothing here
or in the orchestrator's dispatch logic changes.
"""

from typing import Dict, List

from rclpy.action import ActionClient
from robokpy_interfaces.action import ExecuteMoveStep


class ArmRegistry:
    def __init__(self, node, arm_namespaces: List[str], callback_group):
        self._clients: Dict[str, ActionClient] = {}
        for ns in arm_namespaces:
            self._clients[ns] = ActionClient(
                node, ExecuteMoveStep, f'/{ns}/execute_move_step',
                callback_group=callback_group)

    def known_arms(self):
        return set(self._clients.keys())

    def client_for(self, arm_id: str) -> ActionClient:
        return self._clients[arm_id]