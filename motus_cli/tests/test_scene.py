"""Offline tests for `motus world table` (scene.py)."""
import json
import re
import xml.etree.ElementTree as ET
from pathlib import Path

import pytest

from motus_cli.builder import scene

CORE_WORLD = Path(__file__).resolve().parents[2] / "src" / "robokpy_controller" / "worlds" / "motus_world.sdf"
WORLD = CORE_WORLD.read_text(encoding="utf-8")


def _parse(text):
    return ET.fromstring(re.sub(r"<!--.*?-->", "", text, flags=re.S))


def _table(root):
    return next(m for m in root.iter("model") if m.get("name") == "motus_table")


def test_table_top_is_at_z0_and_legs_reach_the_lowered_floor():
    out = scene.apply_table(WORLD, 1.6, 1.2, height=0.75)
    root = _parse(out)
    link = _table(root).find("link")
    boxes = {c.get("name"): c for c in link.findall("collision")}
    top = boxes["top_collision"]
    tz = float(top.find("pose").text.split()[2])
    tsz = float(top.find("geometry/box/size").text.split()[2])
    assert tz + tsz / 2 == pytest.approx(0.0)                       # top face IS z = 0
    leg = boxes["leg1_collision"]
    lz = float(leg.find("pose").text.split()[2])
    lsz = float(leg.find("geometry/box/size").text.split()[2])
    assert lz - lsz / 2 == pytest.approx(-0.75, abs=1e-3)           # legs reach the floor
    ground = next(m for m in root.iter("model") if m.get("name") == "ground_plane")
    assert [float(v) for v in ground.find("pose").text.split()][2] == pytest.approx(-0.75)


def test_apply_is_idempotent_and_replaces_rather_than_stacks():
    once = scene.apply_table(WORLD, 1.6, 1.2)
    twice = scene.apply_table(once, 1.6, 1.2)
    assert once == twice
    resized = scene.apply_table(once, 2.0, 1.4, height=0.9)
    root = _parse(resized)
    assert sum(1 for m in root.iter("model") if m.get("name") == "motus_table") == 1
    assert resized.count(scene.FLOOR_MARK) == 1 and "-0.9" in resized


def test_remove_restores_the_original_world_exactly():
    assert scene.remove_table(scene.apply_table(WORLD, 1.6, 1.2)) == WORLD
    assert scene.remove_table(WORLD) == WORLD                      # no table: no-op


def test_table_is_static_and_user_edits_outside_the_block_survive():
    edited = WORLD.replace("<scene>", "<!-- mine --><scene>")
    out = scene.apply_table(edited, 1.6, 1.2)
    assert "<!-- mine -->" in out and "<static>true</static>" in out
    assert "<!-- mine -->" in scene.remove_table(out)
    assert scene.has_table(out) and not scene.has_table(WORLD)


def test_bad_inputs_are_rejected():
    for kw in ({"length": 0, "width": 1}, {"length": 1, "width": -1}, {"length": 1, "width": 1, "height": 0}):
        with pytest.raises(scene.SceneError):
            scene.apply_table(WORLD, **kw)
    with pytest.raises(scene.SceneError):
        scene.apply_table(WORLD, 1, 1, height=0.75, top_thickness=0.8)
    with pytest.raises(scene.SceneError):
        scene.apply_table("<sdf><world name='w'/></sdf>", 1, 1)       # no ground plane to lower


ARM2 = """<?xml version="1.0"?>
<robot name="planar">
  <link name="base_link"/><link name="l1"/><link name="l2"/><link name="tool0"/>
  <joint name="j1" type="revolute"><parent link="base_link"/><child link="l1"/>
    <axis xyz="0 0 1"/><limit lower="-3.14" upper="3.14" velocity="1" effort="5"/></joint>
  <joint name="j2" type="revolute"><parent link="l1"/><child link="l2"/><origin xyz="0.5 0 0"/>
    <axis xyz="0 0 1"/><limit lower="-3.14" upper="3.14" velocity="1" effort="5"/></joint>
  <joint name="flange" type="fixed"><parent link="l2"/><child link="tool0"/><origin xyz="0.3 0 0"/></joint>
</robot>
"""


def test_reach_estimate_and_default_size():
    reach = scene.estimate_reach(ARM2, "base_link", "tool0", n_samples=3000)
    assert reach == pytest.approx(0.8, abs=0.02)                    # 0.5 + 0.3, fully stretched
    length, width = scene.default_size(reach)
    assert length > reach and width > reach                          # robot fits with margin
    assert scene.default_size(None)[0] > 0.0


def test_project_entry_point_creates_world_adds_and_removes_table(tmp_path):
    pytest.importorskip("xacro")
    from motus_cli.builder import package_generator
    from motus_cli.builder.robot_add import robot_add

    ws = tmp_path / "ws"
    (ws / "src" / "robokpy_controller" / "worlds").mkdir(parents=True)
    (ws / "src" / "robokpy_controller" / "launch").mkdir()
    (ws / "src" / "robokpy_controller" / "worlds" / "motus_world.sdf").write_text(WORLD)
    (ws / "src" / "robokpy_controller" / "launch" / "cell.launch.py").write_text("world_file recipes_dir\n")
    src = tmp_path / "desc"
    src.mkdir()
    (src / "arm.urdf.xacro").write_text(ARM2)
    paths = package_generator.create_project("toy_cell", dest=str(tmp_path))
    robot_add(paths.workspace_root, str(src / "arm.urdf.xacro"))
    mp = Path(paths.workspace_root, "motus.json")
    m = json.loads(mp.read_text())
    m["parent_workspace_root"] = str(ws)
    mp.write_text(json.dumps(m))

    r = scene.table_in_project(paths.workspace_root)
    assert r["created_world"] and r["action"] == "added"
    assert r["reach"] == pytest.approx(0.8, abs=0.05)
    world = Path(r["path"])
    assert scene.has_table(world.read_text())
    assert scene.table_in_project(paths.workspace_root, length=2.0, width=1.5)["action"] == "replaced"
    scene.table_in_project(paths.workspace_root, remove=True)
    assert world.read_text() == WORLD
