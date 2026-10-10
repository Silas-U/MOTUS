"""
project_assets.py

Project-owned Gazebo world and recipes for a Motus project.

robokpy_controller is the engine; a project carries its own
`worlds/motus_world.sdf` (a full COPY of the core world, so the project owns
its scene and a core upgrade can never change a running project) and
`recipes/`. The copy is recorded in motus.json so that `motus doctor` can tell
the difference between

  * the core world changed since the copy was made  (worth knowing -> warning)
  * the project world was edited by the user         (fine, never overwritten)

Nothing here is required: a project without a `worlds/` folder keeps using the
core world, exactly as before.
"""

from __future__ import annotations

import difflib
import hashlib
import json
import re
import shutil
import xml.etree.ElementTree as ET
from pathlib import Path

from . import templates

WORLD_NAME = "motus_world.sdf"
WORLD_REL = f"worlds/{WORLD_NAME}"

RECIPES_README = """# Recipes

Project recipes (YAML). They are installed with this package and found by the
orchestrator before robokpy_controller's own examples:

    ros2 run robokpy_controller run_recipe my_recipe.yaml

Recipe poses encode THIS robot's reach and TCP, so keep them here rather than
in robokpy_controller. See robokpy_controller's recipe authoring guide for the
step format.
"""


class ProjectAssetsError(ValueError):
    pass


def sha256_file(path: Path) -> str:
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def core_world_path(manifest: dict) -> Path | None:
    ws = manifest.get("parent_workspace_root")
    if not ws:
        return None
    p = Path(ws, "src", "robokpy_controller", "worlds", WORLD_NAME)
    return p if p.is_file() else None


def _load(project_root):
    project_root = Path(project_root).resolve()
    mp = project_root / "motus.json"
    if not mp.is_file():
        raise ProjectAssetsError(f"'{project_root}' doesn't look like a Motus project (no motus.json).")
    manifest = json.loads(mp.read_text(encoding="utf-8"))
    pkg_dir = project_root / "src" / manifest["package_name"]
    return project_root, mp, manifest, pkg_dir


def check_world_xml(path: Path) -> str | None:
    """None when `path` is a readable SDF world, else a one-line problem."""
    try:
        # Gazebo tolerates '--' inside comments (the stock motus_world.sdf header
        # has gz CLI flags there); strict XML does not. Drop comments first.
        text = re.sub(r"<!--.*?-->", "", Path(path).read_text(encoding="utf-8"), flags=re.DOTALL)
        root = ET.fromstring(text)
    except (ET.ParseError, OSError) as e:
        return f"not valid XML: {e}"
    if root.tag != "sdf" or root.find("world") is None:
        return "not an SDF world (expected <sdf><world>...)"
    return None


def _rewrite_launch_wrapper(project_root: Path, manifest: dict, pkg_dir: Path) -> str | None:
    """Regenerate the launch wrapper when it predates world_file/recipes_dir/arms_config, or when it
    points at the wrong entry xacro (self-heals a previously mis-generated file).
    The entry xacro is always `<project_name>.urdf.xacro` (see robot_add.py) -- never guess
    from a directory listing: urdf/ also holds copied tool macros."""
    name = manifest["project_name"]
    launch_path = pkg_dir / "launch" / f"{name}.launch.py"
    if not launch_path.is_file():
        return None
    entry_name = f"{name}.urdf.xacro"
    text = launch_path.read_text(encoding="utf-8")
    if "world_file" in text and "arms_config" in text and f"'{entry_name}'" in text:
        return None
    if not (pkg_dir / "urdf" / entry_name).is_file():
        raise ProjectAssetsError(f"urdf/{entry_name} not found -- run `motus robot add <path>` first.")
    launch_path.write_text(templates.LAUNCH_WRAPPER.format(
        launch_name=launch_path.name, robot_name=name, pkg_name=manifest["package_name"],
        urdf_filename=entry_name,
        external_xacro_args_json=repr(json.dumps(manifest.get("xacro_args") or {}))),
        encoding="utf-8")
    return f"launch/{launch_path.name}"


def init_assets(project_root, force: bool = False) -> list[str]:
    """Copy the core world into the project and create recipes/. Never silently
    overwrites: an existing world needs force=True (and is backed up first)."""
    project_root, mp, manifest, pkg_dir = _load(project_root)
    core = core_world_path(manifest)
    if core is None:
        raise ProjectAssetsError(
            "can't find robokpy_controller's worlds/motus_world.sdf in the parent workspace "
            f"({manifest.get('parent_workspace_root')}). Run this from the Motus workspace that "
            "created the project, or fix parent_workspace_root in motus.json.")
    problem = check_world_xml(core)
    if problem:
        raise ProjectAssetsError(f"core world {core} is {problem}; refusing to copy it.")

    written: list[str] = []
    dest = pkg_dir / WORLD_REL
    if dest.exists() and not force:
        raise ProjectAssetsError(
            f"{WORLD_REL} already exists; use --force to replace it (a .bak is kept).")
    dest.parent.mkdir(parents=True, exist_ok=True)
    if dest.exists():
        shutil.copy2(dest, dest.with_suffix(".sdf.bak"))
    shutil.copy2(core, dest)
    written.append(WORLD_REL)

    rec = pkg_dir / "recipes"
    rec.mkdir(parents=True, exist_ok=True)
    if not any(rec.iterdir()):
        (rec / "README.md").write_text(RECIPES_README, encoding="utf-8")
        written.append("recipes/README.md")

    wrapper = _rewrite_launch_wrapper(project_root, manifest, pkg_dir)
    if wrapper:
        written.append(wrapper)

    digest = sha256_file(core)
    manifest["world"] = {"file": WORLD_REL, "core_sha256": digest, "copy_sha256": digest}
    manifest["last_build_fingerprint"] = None
    mp.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    return written


def world_status(project_root) -> dict:
    """state: 'none' | 'current' | 'customised' | 'core-newer' | 'core-newer-customised' | 'unknown-core'"""
    project_root, mp, manifest, pkg_dir = _load(project_root)
    path = pkg_dir / WORLD_REL
    if not path.is_file():
        return {"state": "none", "path": path}
    rec = manifest.get("world") or {}
    core = core_world_path(manifest)
    now_proj = sha256_file(path)
    customised = bool(rec.get("copy_sha256")) and now_proj != rec["copy_sha256"]
    if core is None or not rec.get("core_sha256"):
        return {"state": "unknown-core", "path": path, "customised": customised}
    core_changed = sha256_file(core) != rec["core_sha256"]
    state = ("core-newer-customised" if core_changed and customised else
             "core-newer" if core_changed else
             "customised" if customised else "current")
    return {"state": state, "path": path, "core": core, "customised": customised}


def world_diff(project_root) -> str:
    project_root, mp, manifest, pkg_dir = _load(project_root)
    path = pkg_dir / WORLD_REL
    core = core_world_path(manifest)
    if not path.is_file() or core is None:
        raise ProjectAssetsError("need both a project world and the core world to diff.")
    a = core.read_text(encoding="utf-8").splitlines(keepends=True)
    b = path.read_text(encoding="utf-8").splitlines(keepends=True)
    return "".join(difflib.unified_diff(a, b, "core/" + WORLD_NAME, "project/" + WORLD_NAME))


def run_asset_checks(project_root: Path, manifest: dict, pkg_dir: Path) -> list[tuple]:
    """(name, ok, level, detail) rows for `motus doctor`."""
    import yaml
    out: list[tuple] = []
    ws = manifest.get("parent_workspace_root")
    core_launch = Path(ws, "src", "robokpy_controller", "launch", "cell.launch.py") if ws else None
    core_text = core_launch.read_text(encoding="utf-8") if core_launch and core_launch.is_file() else None
    install_share = Path(project_root, "install", manifest["package_name"], "share", manifest["package_name"])

    launch_file = pkg_dir / "launch" / f"{manifest['project_name']}.launch.py"
    entry_name = f"{manifest['project_name']}.urdf.xacro"
    if launch_file.is_file():
        ltxt = launch_file.read_text(encoding="utf-8")
        m = re.search(r"'urdf',\s*'([^']+)'", ltxt)
        pointed = m.group(1) if m else None
        out.append(("Launch file uses the robot entry xacro", pointed == entry_name, "error",
                    f"the launch file loads urdf/{pointed}, not urdf/{entry_name}; the sim would "
                    f"start with the wrong description. Run `motus world init --force` to regenerate it."))

    world_path = pkg_dir / WORLD_REL
    if not world_path.is_file():
        out.append(("Project world", False, "warning",
                    "no project-owned world; the core motus_world.sdf is used. "
                    "Run `motus world init` so this project owns its scene."))
    else:
        problem = check_world_xml(world_path)
        out.append(("Project world parses", problem is None, "error",
                    f"{WORLD_REL} is {problem}" if problem else ""))
        launch_path = pkg_dir / "launch" / f"{manifest['project_name']}.launch.py"
        wired = launch_path.is_file() and "world_file" in launch_path.read_text(encoding="utf-8")
        out.append(("Project world is launched", wired, "error",
                    "the launch file doesn't pass world_file, so the project world would be ignored. "
                    "Run `motus world init --force` to regenerate it."))
        if core_text is not None:
            out.append(("Core supports project worlds", "world_file" in core_text, "error",
                        "robokpy_controller/launch/cell.launch.py has no world_file argument; "
                        "update robokpy_controller."))
        if install_share.is_dir():
            inst = install_share / WORLD_REL
            if not inst.is_file():
                out.append(("Project world installed", False, "warning",
                            "built package has no worlds/motus_world.sdf; run `motus build`."))
            elif sha256_file(inst) != sha256_file(world_path):
                out.append(("Project world installed", False, "warning",
                            "the installed world differs from the source; run `motus build` "
                            "so the sim uses your latest edits."))
        st = world_status(project_root)["state"]
        if st == "core-newer":
            out.append(("Project world vs core", False, "warning",
                        "robokpy_controller's motus_world.sdf changed since this copy was made and "
                        "the project copy is untouched; refresh with `motus world init --force`."))
        elif st == "core-newer-customised":
            out.append(("Project world vs core", False, "warning",
                        "robokpy_controller's motus_world.sdf changed since this copy was made and "
                        "the project copy has your edits; review `motus world diff` and merge by hand."))

    rec_dir = pkg_dir / "recipes"
    recipes = sorted(rec_dir.glob("*.yaml")) if rec_dir.is_dir() else []
    if recipes:
        if core_text is not None:
            out.append(("Core supports project recipes", "recipes_dir" in core_text, "error",
                        "robokpy_controller's cell.launch.py has no recipes_dir argument; "
                        "update robokpy_controller."))
        for f in recipes:
            label = f"Recipe {f.name}"
            try:
                data = yaml.safe_load(f.read_text(encoding="utf-8"))
                steps = data["steps"]
                ids = [s["id"] for s in steps]
            except Exception as e:  # noqa: BLE001 - any parse/shape problem is the same finding
                out.append((label, False, "error", f"unreadable or missing steps/ids: {e}"))
                continue
            dup = sorted({i for i in ids if ids.count(i) > 1})
            unknown = sorted({d for s in steps for d in (s.get("depends_on") or []) if d not in ids})
            problems = ([f"duplicate step ids: {', '.join(dup)}"] if dup else []) + \
                       ([f"depends_on unknown steps: {', '.join(unknown)}"] if unknown else [])
            out.append((label, not problems, "error", "; ".join(problems)))
            if install_share.is_dir() and not (install_share / "recipes" / f.name).is_file():
                out.append((f"{label} installed", False, "warning",
                            "not in the built package; run `motus build`."))
    return out