"""
cell_arms.py

`motus cell ...` -- turn a Motus project into a multi-arm cell WITHOUT touching
robokpy_controller. Everything lives in the project:

  config/cell_arms.yaml   the arms (namespace + spawn pose); passed to
                          cell.launch.py as `arms_config` by the project's
                          launch wrapper. Every arm is the project's own robot.
  config/tools.yaml       per-arm copies of the project's tool blocks
                          (gripper_2 / grasp_attach_2, ...), generated from
                          arm1's blocks between `# MOTUS-ARM-BEGIN armN` /
                          `# MOTUS-ARM-END armN`. Anything outside the markers
                          is never touched.
  recipes/multi_arm_example.yaml   a motion-only starting recipe (created once,
                          never overwritten).

arm1 is always the project's first arm at the origin. Further arms are named
arm2, arm3, ... (the trailing number decides the tool names, e.g. gripper_2).

Pure Python + PyYAML, no ROS, so it is unit-testable offline.
"""

from __future__ import annotations

import json
import math
import re
from dataclasses import dataclass, field
from pathlib import Path

import yaml

from . import project_assets, scene

ARMS_REL = "config/cell_arms.yaml"
EXAMPLE_RECIPE = "multi_arm_example.yaml"
_NS_RE = re.compile(r"^arm([1-9]\d*)$")
_TOOL_BLOCK_RE = r"# MOTUS-TOOL-BEGIN {id}\n.*?# MOTUS-TOOL-END {id}\n?"
_ARM_BLOCK_RE = r"\n*# MOTUS-ARM-BEGIN {ns}\n.*?# MOTUS-ARM-END {ns}\n?"
MIN_BASE_SPACING = 0.35   # m; closer than this the two robot bases would overlap

_HEADER = (
    "# cell_arms.yaml -- the arms of this project's cell. Managed by `motus cell`\n"
    "# (add-arm / remove-arm); every arm is this project's own robot. Positions are\n"
    "# the arm base in the WORLD frame, metres. Hand edits to spawn_* are kept.\n")


class CellArmsError(ValueError):
    pass


@dataclass
class CellReport:
    notes: list = field(default_factory=list)
    warnings: list = field(default_factory=list)

    def print_summary(self) -> None:
        for n in self.notes:
            print(f"  {n}")
        for w in self.warnings:
            print(f"  warning: {w}")


# ---------------------------------------------------------------- helpers

def _index(ns: str) -> int:
    m = _NS_RE.match(ns)
    if not m:
        raise CellArmsError(
            f"arm name '{ns}' must look like arm1, arm2, arm3 ... (the number names its tools)")
    return int(m.group(1))


def arm_tool_id(tool_id: str, ns: str) -> str:
    """gripper_1 -> gripper_2 for arm2; ids not ending in _1 get the arm appended."""
    n = _index(ns)
    return re.sub(r"_1$", f"_{n}", tool_id) if tool_id.endswith("_1") else f"{tool_id}_{ns}"


def _arms_path(pkg_dir: Path) -> Path:
    return pkg_dir / ARMS_REL


def _read_arms(pkg_dir: Path) -> list[dict]:
    p = _arms_path(pkg_dir)
    if not p.is_file():
        return []
    try:
        doc = yaml.safe_load(p.read_text(encoding="utf-8")) or {}
    except yaml.YAMLError as e:
        raise CellArmsError(f"{ARMS_REL} is not valid YAML: {e}") from e
    arms = doc.get("arms")
    if not isinstance(arms, list) or not all(isinstance(a, dict) and "namespace" in a for a in arms):
        raise CellArmsError(f"{ARMS_REL} must contain an `arms:` list of entries with a namespace.")
    return arms


def _write_arms(pkg_dir: Path, arms: list[dict]) -> None:
    p = _arms_path(pkg_dir)
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(_HEADER + yaml.safe_dump({"arms": arms}, sort_keys=False), encoding="utf-8")


def _distance(a: dict, b: dict) -> float:
    return math.dist(
        (float(a.get("spawn_x", 0)), float(a.get("spawn_y", 0)), float(a.get("spawn_z", 0))),
        (float(b.get("spawn_x", 0)), float(b.get("spawn_y", 0)), float(b.get("spawn_z", 0))))


def _tool_descriptors(manifest: dict) -> list[dict]:
    return [rec["descriptor"] for rec in (manifest.get("tools") or {}).values()
            if rec.get("descriptor")]


def _arm_block(tools_text: str, descriptor: dict, ns: str) -> str | None:
    """arm1's block for this tool, rewritten for `ns`. None if arm1 has no block."""
    tid = descriptor["id"]
    m = re.search(_TOOL_BLOCK_RE.format(id=re.escape(tid)), tools_text, re.S)
    if not m:
        return None
    body = m.group(0)
    body = re.sub(r"# MOTUS-TOOL-(BEGIN|END) .*\n", "", body)
    renames = {tid: arm_tool_id(tid, ns)}
    grasp = descriptor.get("grasp_tool_id")
    if grasp:
        renames[grasp] = arm_tool_id(grasp, ns)
    # longest first so a short id can't clobber part of a longer one
    for old in sorted(renames, key=len, reverse=True):
        body = re.sub(rf"(?m)^{re.escape(old)}:", f"{renames[old]}:", body)
    body = body.replace("arm1/", f"{ns}/")
    # A grasp tool must name ITS arm's model, otherwise the bridge sends the weld to
    # whichever arm objects.yaml names (arm1) and the cube sticks to the wrong gripper.
    # arm1's block now carries `parent_model: arm1_robot`; re-point it at this arm.
    if re.search(r"(?m)^\s*parent_model:", body):
        body = re.sub(r"(?m)^(\s*parent_model:).*$", lambda mm: f"{mm.group(1)} {ns}_robot", body)
    else:
        body = re.sub(r"(?m)^(\s*)backend: grasp_attach\n",
                      lambda mm: f"{mm.group(0)}{mm.group(1)}parent_model: {ns}_robot\n", body)
    return body.rstrip("\n") + "\n"


def _strip_arm_block(text: str, ns: str) -> str:
    return re.sub(_ARM_BLOCK_RE.format(ns=re.escape(ns)), "\n", text, flags=re.S)


def _sync_tools(pkg_dir: Path, manifest: dict, namespaces: list[str], report: CellReport) -> None:
    """Regenerate every non-arm1 arm's tool blocks from arm1's current blocks."""
    path = pkg_dir / "config" / "tools.yaml"
    descs = _tool_descriptors(manifest)
    if not descs:
        report.warnings.append("this project has no tools (`motus tool add`), so the extra arms "
                               "get no gripper/grasp tools.")
        return
    if not path.is_file():
        report.warnings.append("config/tools.yaml is missing; no per-arm tools written.")
        return
    text = path.read_text(encoding="utf-8")
    # drop every arm block (also those of arms that no longer exist), then re-add
    for stale in set(re.findall(r"# MOTUS-ARM-BEGIN (\S+)", text)):
        text = _strip_arm_block(text, stale)
    for ns in namespaces:
        if ns == "arm1":
            continue
        blocks = [b for b in (_arm_block(text, d, ns) for d in descs) if b]
        if not blocks:
            report.warnings.append(f"no tool blocks found for arm1 in tools.yaml; {ns} gets none.")
            continue
        text = (text.rstrip("\n") + f"\n\n# MOTUS-ARM-BEGIN {ns}\n"
                + "\n".join(blocks) + f"# MOTUS-ARM-END {ns}\n")
        ids = [arm_tool_id(d["id"], ns) for d in descs]
        report.notes.append(f"{ns} tools: " + ", ".join(ids))
    path.write_text(text, encoding="utf-8")


def _reach(project_root) -> float | None:
    try:
        return scene.project_reach(project_root)
    except Exception:          # sizing hint only; never block the command on it
        return None


def _example_recipe(namespaces: list[str], reach: float | None) -> str:
    r = reach or 0.85
    x, y, z = round(0.5 * r, 3), round(0.25 * r, 3), round(0.45 * r, 3)
    lines = [
        "recipe_id: multi_arm_example\n",
        "# Generated by `motus cell add-arm`. Every arm homes, reaches out and comes back;\n"
        "# the reach steps share the resource `shared_zone`, so the arms take turns there.\n"
        "# Poses are in EACH ARM'S OWN BASE FRAME (not the world frame) and are a starting\n"
        "# point sized from this robot's reach -- tune them to your robot, tool and scene.\n"
        "# `wait` steps keep each arm's moves in separate runs so the lock is held only\n"
        "# while an arm is actually in the shared zone.\n\n"
        "steps:\n\n",
    ]
    pose = lambda px, py, pz: ("{x: %s, y: %s, z: %s, qx: 1.0, qy: 0.0, qz: 0.0, qw: 0.0}"
                               % (px, py, pz))
    for i, ns in enumerate(namespaces):
        side = y if i % 2 == 0 else -y
        lines.append(f"""- id: home_{ns}
  type: move
  arm_id: {ns}
  traj_method: js
  traj_type: scurve
  target_pose: {pose(x, 0.0, z)}
  depends_on: []

- id: pause_{ns}
  type: wait
  duration_sec: 0.5
  depends_on: [home_{ns}]

- id: reach_{ns}
  type: move
  arm_id: {ns}
  traj_method: js
  traj_type: scurve
  resources: [shared_zone]
  target_pose: {pose(x, side, round(z * 0.7, 3))}
  depends_on: [pause_{ns}]

- id: pause2_{ns}
  type: wait
  duration_sec: 0.5
  depends_on: [reach_{ns}]

- id: return_{ns}
  type: move
  arm_id: {ns}
  traj_method: js
  traj_type: scurve
  target_pose: {pose(x, 0.0, z)}
  depends_on: [pause2_{ns}]

""")
    return "".join(lines)


def _write_example_recipe(project_root: Path, pkg_dir: Path, namespaces: list[str],
                          report: CellReport) -> None:
    path = pkg_dir / "recipes" / EXAMPLE_RECIPE
    if path.exists():
        report.notes.append(f"recipes/{EXAMPLE_RECIPE} exists; left as it is "
                            "(delete it to have it regenerated for the new arm set).")
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(_example_recipe(namespaces, _reach(project_root)),
                    encoding="utf-8")
    report.notes.append(f"recipes/{EXAMPLE_RECIPE}: starting recipe for {', '.join(namespaces)}")


def _wire_launch(project_root: Path, manifest: dict, pkg_dir: Path, report: CellReport) -> None:
    try:
        wrapper = project_assets._rewrite_launch_wrapper(project_root, manifest, pkg_dir)
    except project_assets.ProjectAssetsError as e:
        raise CellArmsError(str(e)) from e
    if wrapper:
        report.notes.append(f"{wrapper}: regenerated to pass config/cell_arms.yaml to the cell")


def _load(project_root):
    try:
        root, mp, manifest, pkg_dir = project_assets._load(project_root)
    except project_assets.ProjectAssetsError as e:
        raise CellArmsError(str(e)) from e
    entry = pkg_dir / "urdf" / f"{manifest['project_name']}.urdf.xacro"
    if not entry.is_file():
        raise CellArmsError(f"urdf/{entry.name} not found -- run `motus robot add <path>` first.")
    return root, mp, manifest, pkg_dir


def _touch_manifest(mp: Path, manifest: dict) -> None:
    manifest["last_build_fingerprint"] = None
    mp.write_text(json.dumps(manifest, indent=2), encoding="utf-8")


# -------------------------------------------------------------- public API

def list_arms(project_root) -> list[dict]:
    root, mp, manifest, pkg_dir = _load(project_root)
    return _read_arms(pkg_dir) or [{"namespace": "arm1", "spawn_x": 0.0, "spawn_y": 0.0,
                                    "spawn_z": 0.0}]


def add_arm(project_root, namespace: str, x: float, y: float = 0.0, z: float = 0.0) -> CellReport:
    _index(namespace)
    if namespace == "arm1":
        raise CellArmsError("arm1 is the project's first arm (at the origin) and already exists.")
    root, mp, manifest, pkg_dir = _load(project_root)
    report = CellReport()
    arms = _read_arms(pkg_dir) or [{"namespace": "arm1", "spawn_x": 0.0, "spawn_y": 0.0,
                                    "spawn_z": 0.0}]
    if any(a["namespace"] == namespace for a in arms):
        raise CellArmsError(f"{namespace} is already in {ARMS_REL}; remove it first to move it.")
    new = {"namespace": namespace, "spawn_x": float(x), "spawn_y": float(y), "spawn_z": float(z)}
    for other in arms:
        d = _distance(new, other)
        if d < MIN_BASE_SPACING:
            raise CellArmsError(
                f"{namespace} would sit {d:.2f} m from {other['namespace']}; the robot bases "
                f"would overlap (minimum {MIN_BASE_SPACING} m).")
    reach = _reach(root)
    if reach:
        for other in arms:
            d = _distance(new, other)
            if d < 2 * reach:
                report.warnings.append(
                    f"{namespace} is {d:.2f} m from {other['namespace']}; with a {reach:.2f} m "
                    "reach the two workspaces overlap -- give recipes a shared `resources:` lock "
                    "for the common area (see recipes/multi_arm_example.yaml).")
    arms.append(new)
    _write_arms(pkg_dir, arms)
    report.notes.append(f"{ARMS_REL}: {', '.join(a['namespace'] for a in arms)}")
    namespaces = [a["namespace"] for a in arms]
    _sync_tools(pkg_dir, manifest, namespaces, report)
    _write_example_recipe(root, pkg_dir, namespaces, report)
    _wire_launch(root, manifest, pkg_dir, report)
    _touch_manifest(mp, manifest)
    report.notes.append("next: `motus build`, then `motus launch`.")
    return report


def remove_arm(project_root, namespace: str) -> CellReport:
    _index(namespace)
    if namespace == "arm1":
        raise CellArmsError("arm1 is the project's first arm and can't be removed.")
    root, mp, manifest, pkg_dir = _load(project_root)
    report = CellReport()
    arms = _read_arms(pkg_dir)
    if not any(a["namespace"] == namespace for a in arms):
        raise CellArmsError(f"{namespace} is not in {ARMS_REL}.")
    arms = [a for a in arms if a["namespace"] != namespace]
    if len(arms) <= 1:
        _arms_path(pkg_dir).unlink()
        report.notes.append(f"{ARMS_REL} removed: the project is a single-arm cell again.")
    else:
        _write_arms(pkg_dir, arms)
        report.notes.append(f"{ARMS_REL}: {', '.join(a['namespace'] for a in arms)}")
    _sync_tools(pkg_dir, manifest, [a["namespace"] for a in arms], report)
    _touch_manifest(mp, manifest)
    report.notes.append(f"recipes that use {namespace} will no longer validate; edit or delete them.")
    return report


def sync_tools(project_root) -> CellReport:
    """Rebuild the extra arms' tool blocks after `motus tool add --replace` changed arm1's."""
    root, mp, manifest, pkg_dir = _load(project_root)
    report = CellReport()
    arms = _read_arms(pkg_dir)
    if len(arms) < 2:
        raise CellArmsError("this project has no extra arms (use `motus cell add-arm`).")
    _sync_tools(pkg_dir, manifest, [a["namespace"] for a in arms], report)
    _touch_manifest(mp, manifest)
    return report
