"""grasp_attach tools carry an explicit parent_model per arm."""
import json
import re
from pathlib import Path

import pytest
import yaml

from motus_cli.builder import cell_arms
from motus_cli.builder.cell_arms import CellArmsError

TOOLS_YAML = """# tools.yaml header
# MOTUS-TOOL-BEGIN gripper_1
gripper_1:
  backend: gripper_action
  action_name: arm1/gripper_action_controller/gripper_cmd
  joint_name: robotiq_85_left_knuckle_joint
  open_position: 0.001
  closed_position: 0.154
  max_effort: 5.0
  action_timeout: 5.0

grasp_attach_1:
  backend: grasp_attach
  service_name: /grasp_attach
  parent_model: arm1_robot
  action_name: arm1/gripper_action_controller/gripper_cmd
  joint_name: robotiq_85_left_knuckle_joint
# MOTUS-TOOL-END gripper_1

my_note: keep me
"""


@pytest.fixture()
def project(tmp_path):
    root = tmp_path / "demo"
    pkg = root / "src" / "demo_motus"
    for d in ("urdf", "config", "launch", "recipes"):
        (pkg / d).mkdir(parents=True)
    (pkg / "urdf" / "demo.urdf.xacro").write_text("<robot name='demo'/>")
    (pkg / "config" / "tools.yaml").write_text(TOOLS_YAML)
    (pkg / "launch" / "demo.launch.py").write_text(
        "# old wrapper\n'world_file': x, 'recipes_dir': y, 'demo.urdf.xacro'\n")
    manifest = {
        "project_name": "demo", "package_name": "demo_motus", "xacro_args": {},
        "tools": {"gripper_1": {"descriptor": {"id": "gripper_1", "grasp_tool_id": "grasp_attach_1"}}},
    }
    (root / "motus.json").write_text(json.dumps(manifest))
    return root, pkg


def _tools(pkg):
    return (pkg / "config" / "tools.yaml").read_text()


def test_explicit_arm1_parent_model_is_repointed_per_arm(project):
    root, pkg = project
    cell_arms.add_arm(root, "arm2", 1.6)
    cell_arms.add_arm(root, "arm3", 3.2)
    doc = yaml.safe_load(_tools(pkg))
    assert doc["grasp_attach_1"]["parent_model"] == "arm1_robot"
    assert doc["grasp_attach_2"]["parent_model"] == "arm2_robot"
    assert doc["grasp_attach_3"]["parent_model"] == "arm3_robot"


def test_arm_without_explicit_parent_model_still_gets_one(project):
    root, pkg = project
    t = pkg / "config" / "tools.yaml"
    t.write_text(t.read_text().replace("  parent_model: arm1_robot\n", ""))
    cell_arms.add_arm(root, "arm2", 1.6)
    assert yaml.safe_load(_tools(pkg))["grasp_attach_2"]["parent_model"] == "arm2_robot"


def test_tool_add_block_names_its_arm_model():
    from motus_cli.builder import tool_add
    d = type("D", (), dict(id="gripper_1", grasp_tool_id="grasp_attach_1", primary_joint="j",
                           open_position=0.0, closed_position=0.1, max_effort=5.0))()
    assert yaml.safe_load(tool_add._tools_block(d))["grasp_attach_1"]["parent_model"] == "arm1_robot"
