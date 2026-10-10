"""Offline tests for `motus cell` (cell_arms.py): a multi-arm cell is defined
entirely inside the project, never in robokpy_controller."""
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


def test_add_arm_writes_project_files_only(project):
    root, pkg = project
    report = cell_arms.add_arm(root, "arm2", 1.2)
    arms = yaml.safe_load((pkg / cell_arms.ARMS_REL).read_text())["arms"]
    assert [a["namespace"] for a in arms] == ["arm1", "arm2"]
    assert arms[1]["spawn_x"] == 1.2 and arms[0]["spawn_x"] == 0.0
    assert (pkg / "recipes" / cell_arms.EXAMPLE_RECIPE).is_file()
    assert "arms_config" in (pkg / "launch" / "demo.launch.py").read_text()
    assert any("arm2" in n for n in report.notes)


def test_arm2_tools_are_arm1s_retargeted_and_the_rest_is_untouched(project):
    root, pkg = project
    cell_arms.add_arm(root, "arm2", 1.2)
    text = _tools(pkg)
    doc = yaml.safe_load(text)
    assert doc["gripper_2"]["action_name"] == "arm2/gripper_action_controller/gripper_cmd"
    assert doc["grasp_attach_2"]["action_name"].startswith("arm2/")
    assert doc["grasp_attach_2"]["parent_model"] == "arm2_robot"
    assert doc["gripper_1"]["action_name"].startswith("arm1/")        # arm1 unchanged
    assert doc["my_note"] == "keep me"
    assert text.count("MOTUS-TOOL-BEGIN") == 1                        # tool commands don't see arm2


def test_add_is_repeatable_and_sync_follows_arm1_changes(project):
    root, pkg = project
    cell_arms.add_arm(root, "arm2", 1.2)
    cell_arms.add_arm(root, "arm3", -1.2)
    text = _tools(pkg)
    assert text.count("MOTUS-ARM-BEGIN") == 2
    assert {"gripper_2", "gripper_3", "grasp_attach_3"} <= set(yaml.safe_load(text))
    # arm1's tool changes (as `motus tool add --replace` would) -> sync rebuilds the copies
    (pkg / "config" / "tools.yaml").write_text(text.replace("max_effort: 5.0", "max_effort: 9.0"))
    cell_arms.sync_tools(root)
    doc = yaml.safe_load(_tools(pkg))
    assert doc["gripper_2"]["max_effort"] == 9.0 and doc["gripper_3"]["max_effort"] == 9.0
    assert _tools(pkg).count("MOTUS-ARM-BEGIN") == 2                  # not duplicated


def test_remove_arm_drops_its_tools_and_last_removal_restores_single_arm(project):
    root, pkg = project
    cell_arms.add_arm(root, "arm2", 1.2)
    cell_arms.remove_arm(root, "arm2")
    assert not (pkg / cell_arms.ARMS_REL).exists()
    assert "gripper_2" not in yaml.safe_load(_tools(pkg))
    assert "MOTUS-ARM" not in _tools(pkg)
    assert yaml.safe_load(_tools(pkg))["my_note"] == "keep me"


@pytest.mark.parametrize("name", ["arm1", "robot2", "arm0", "arm", "Arm2"])
def test_bad_names_are_rejected(project, name):
    with pytest.raises(CellArmsError):
        cell_arms.add_arm(project[0], name, 1.2)


def test_overlapping_bases_and_duplicates_are_rejected(project):
    root, _ = project
    with pytest.raises(CellArmsError, match="overlap"):
        cell_arms.add_arm(root, "arm2", 0.1)
    cell_arms.add_arm(root, "arm2", 1.2)
    with pytest.raises(CellArmsError, match="already"):
        cell_arms.add_arm(root, "arm2", 2.4)


def test_example_recipe_has_a_lock_and_every_arm(project):
    root, pkg = project
    cell_arms.add_arm(root, "arm2", 1.2)
    rec = yaml.safe_load((pkg / "recipes" / cell_arms.EXAMPLE_RECIPE).read_text())
    ids = {s["id"] for s in rec["steps"]}
    assert {"home_arm1", "reach_arm2", "return_arm2"} <= ids
    for s in rec["steps"]:
        assert all(d in ids for d in s["depends_on"])
    assert [s for s in rec["steps"] if s.get("resources") == ["shared_zone"]]
    assert {s["arm_id"] for s in rec["steps"] if s["type"] == "move"} == {"arm1", "arm2"}


def test_existing_recipe_is_never_overwritten(project):
    root, pkg = project
    mine = pkg / "recipes" / cell_arms.EXAMPLE_RECIPE
    mine.write_text("recipe_id: mine\n")
    cell_arms.add_arm(root, "arm2", 1.2)
    assert mine.read_text() == "recipe_id: mine\n"


def test_project_without_tools_still_gets_arms_and_a_warning(project):
    root, pkg = project
    m = json.loads((root / "motus.json").read_text())
    m["tools"] = {}
    (root / "motus.json").write_text(json.dumps(m))
    report = cell_arms.add_arm(root, "arm2", 1.2)
    assert any("no tools" in w for w in report.warnings)
    assert (pkg / cell_arms.ARMS_REL).is_file()


def test_arm_tool_id_naming():
    assert cell_arms.arm_tool_id("gripper_1", "arm3") == "gripper_3"
    assert cell_arms.arm_tool_id("claw", "arm2") == "claw_arm2"


def test_default_table_spans_every_arm(project, monkeypatch):
    from motus_cli.builder import scene
    root, pkg = project
    cell_arms.add_arm(root, "arm2", 1.2)
    (pkg / "worlds").mkdir()
    core = Path(__file__).resolve().parents[2] / "src" / "robokpy_controller" / "worlds" / "motus_world.sdf"
    (pkg / "worlds" / "motus_world.sdf").write_text(core.read_text(encoding="utf-8"))
    monkeypatch.setattr(scene, "project_reach", lambda _r: 0.85)
    two = scene.table_in_project(root)
    cell_arms.remove_arm(root, "arm2")
    one = scene.table_in_project(root)
    assert two["length"] >= one["length"] + 1.2 - 1e-6
    assert two["center"][0] > one["center"][0]
    # both bases (x = 0 and x = 1.2) lie within the table's x-extent
    lo = two["center"][0] - two["length"] / 2
    hi = two["center"][0] + two["length"] / 2
    assert lo < 0.0 and hi > 1.2
