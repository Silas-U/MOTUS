"""Offline tests for project-owned world/recipes (`motus world ...` + doctor)."""
import json
from pathlib import Path

import pytest

pytest.importorskip("xacro")

from motus_cli.builder import package_generator, project_assets as pa
from motus_cli.builder.doctor import run_doctor
from motus_cli.builder.robot_add import robot_add
from motus_cli.builder.project_assets import ProjectAssetsError

SDF = '<?xml version="1.0"?><sdf version="1.9"><world name="w"><!-- {n} --></world></sdf>'
ARM = """<?xml version="1.0"?>
<robot xmlns:xacro="http://ros.org/wiki/xacro" name="toy">
  <link name="base_link"/><link name="l1"/><link name="tool0"/>
  <joint name="j1" type="revolute"><parent link="base_link"/><child link="l1"/>
    <axis xyz="0 0 1"/><limit lower="-3" upper="3" velocity="1" effort="50"/></joint>
  <joint name="flange" type="fixed"><parent link="l1"/><child link="tool0"/><origin xyz="0 0 0.2"/></joint>
</robot>
"""
CORE_LAUNCH = "# fake core\nworld_file recipes_dir\n"


@pytest.fixture()
def env(tmp_path):
    ws = tmp_path / "ws"
    core = ws / "src" / "robokpy_controller"
    (core / "worlds").mkdir(parents=True)
    (core / "launch").mkdir()
    (core / "worlds" / "motus_world.sdf").write_text(SDF.format(n=1))
    (core / "launch" / "cell.launch.py").write_text(CORE_LAUNCH)
    src = tmp_path / "desc"
    src.mkdir()
    (src / "arm.urdf.xacro").write_text(ARM)
    paths = package_generator.create_project("toy_cell", dest=str(tmp_path))
    robot_add(paths.workspace_root, str(src / "arm.urdf.xacro"))
    mp = Path(paths.workspace_root, "motus.json")
    m = json.loads(mp.read_text())
    m["parent_workspace_root"] = str(ws)
    mp.write_text(json.dumps(m))
    root = Path(paths.workspace_root)
    return root, root / "src" / paths.pkg_name, core / "worlds" / "motus_world.sdf"


def test_world_with_double_dash_comment_is_accepted(env):
    root, pkg, core_world = env
    core_world.write_text('<?xml version="1.0"?><!-- gz service --reqtype X --timeout 3 -->'
                          '<sdf version="1.9"><world name="w"/></sdf>')
    pa.init_assets(root)
    assert pa.check_world_xml(pkg / "worlds" / "motus_world.sdf") is None


def names(root, level=None):
    return {c.name: c for c in run_doctor(root) if not c.ok and (level is None or c.level == level)}


def test_init_copies_world_creates_recipes_and_wires_launch(env):
    root, pkg, core_world = env
    launch = pkg / "launch" / "toy_cell.launch.py"
    assert "world_file" in launch.read_text()          # new wrapper template already has it
    written = pa.init_assets(root)
    assert "worlds/motus_world.sdf" in written and (pkg / "recipes" / "README.md").is_file()
    assert (pkg / "worlds" / "motus_world.sdf").read_text() == core_world.read_text()
    m = json.loads((root / "motus.json").read_text())
    assert m["world"]["core_sha256"] == m["world"]["copy_sha256"]


def test_old_wrapper_is_regenerated_and_overwrite_needs_force(env):
    root, pkg, _ = env
    launch = pkg / "launch" / "toy_cell.launch.py"
    launch.write_text(launch.read_text().replace("world_file", "wf").replace("recipes_dir", "rd"))
    written = pa.init_assets(root)
    assert "launch/toy_cell.launch.py" in written and "world_file" in launch.read_text()
    with pytest.raises(ProjectAssetsError, match="--force"):
        pa.init_assets(root)
    (pkg / "worlds" / "motus_world.sdf").write_text(SDF.format(n="mine"))
    pa.init_assets(root, force=True)
    assert (pkg / "worlds" / "motus_world.sdf.bak").read_text() == SDF.format(n="mine")


def test_status_states_and_diff(env):
    root, pkg, core_world = env
    assert pa.world_status(root)["state"] == "none"
    pa.init_assets(root)
    assert pa.world_status(root)["state"] == "current"
    (pkg / "worlds" / "motus_world.sdf").write_text(SDF.format(n="mine"))
    assert pa.world_status(root)["state"] == "customised"
    core_world.write_text(SDF.format(n=2))
    assert pa.world_status(root)["state"] == "core-newer-customised"
    assert "mine" in pa.world_diff(root)
    pa.init_assets(root, force=True)
    core_world.write_text(SDF.format(n=3))
    assert pa.world_status(root)["state"] == "core-newer"


def test_doctor_world_checks(env):
    root, pkg, core_world = env
    assert "Project world" in names(root, "warning")          # none yet: nudge, not an error
    pa.init_assets(root)
    assert not [n for n in names(root) if n.startswith("Project world")]
    core_world.write_text(SDF.format(n=2))
    assert "Project world vs core" in names(root, "warning")
    (pkg / "worlds" / "motus_world.sdf").write_text("<sdf")
    assert "Project world parses" in names(root, "error")
    pa.init_assets(root, force=True)
    # launch wrapper that would ignore the world is an error
    launch = pkg / "launch" / "toy_cell.launch.py"
    launch.write_text(launch.read_text().replace("world_file", "wf"))
    assert "Project world is launched" in names(root, "error")


def test_doctor_flags_stale_install_and_old_core(env):
    root, pkg, core_world = env
    pa.init_assets(root)
    share = root / "install" / pkg.name / "share" / pkg.name
    (share / "worlds").mkdir(parents=True)
    assert "Project world installed" in names(root, "warning")            # not installed
    (share / "worlds" / "motus_world.sdf").write_text(SDF.format(n="old"))
    assert "Project world installed" in names(root, "warning")            # stale copy
    (share / "worlds" / "motus_world.sdf").write_text((pkg / "worlds" / "motus_world.sdf").read_text())
    assert "Project world installed" not in names(root)
    (core_world.parent.parent / "launch" / "cell.launch.py").write_text("# old core\n")
    assert "Core supports project worlds" in names(root, "error")


def test_doctor_recipe_checks(env):
    root, pkg, _ = env
    pa.init_assets(root)
    (pkg / "recipes" / "ok.yaml").write_text(
        "steps:\n- {id: a, type: move, depends_on: []}\n- {id: b, type: move, depends_on: [a]}\n")
    (pkg / "recipes" / "bad.yaml").write_text(
        "steps:\n- {id: a, depends_on: []}\n- {id: a, depends_on: [zzz]}\n")
    (pkg / "recipes" / "broken.yaml").write_text("not: [a recipe")
    n = names(root, "error")
    assert "Recipe ok.yaml" not in n
    assert "duplicate" in n["Recipe bad.yaml"].detail and "zzz" in n["Recipe bad.yaml"].detail
    assert "Recipe broken.yaml" in n


def test_wrapper_uses_manifest_entry_not_first_xacro_alphabetically(env):
    """Regression: urdf/ also holds copied tool macros (e.g. robotiq_*.urdf.xacro) that
    sort before the robot's own entry file."""
    root, pkg, _ = env
    (pkg / "urdf" / "a_tool_macro.urdf.xacro").write_text("<robot/>")
    launch = pkg / "launch" / "toy_cell.launch.py"
    launch.write_text(launch.read_text().replace("world_file", "wf"))   # old-style wrapper
    pa.init_assets(root)
    txt = launch.read_text()
    assert "'toy_cell.urdf.xacro'" in txt and "a_tool_macro" not in txt


def test_init_repairs_wrapper_pointing_at_wrong_xacro_and_doctor_flags_it(env):
    root, pkg, _ = env
    pa.init_assets(root)
    launch = pkg / "launch" / "toy_cell.launch.py"
    launch.write_text(launch.read_text().replace("toy_cell.urdf.xacro", "a_tool_macro.urdf.xacro"))
    assert "Launch file uses the robot entry xacro" in names(root, "error")
    pa.init_assets(root, force=True)
    assert "toy_cell.urdf.xacro" in launch.read_text()
    assert "Launch file uses the robot entry xacro" not in names(root)