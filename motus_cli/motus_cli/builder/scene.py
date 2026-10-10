"""
scene.py

`motus world table`: put the robot and its objects on a workbench.

DESIGN -- the tabletop IS the z = 0 plane. The robot spawns at the world
origin, objects are spawned at z = their half-height, recipes and the builder's
floor-clearance logic all treat z = 0 as the work surface. So the table is
built with its top face exactly at z = 0 and its legs reaching DOWN to a floor
that is lowered by the table height. Nothing else moves: robot spawn pose,
object spawn poses, recipes, IK clearance checks and the ready pose all stay
valid, and a recipe written for the bare ground plane works unchanged on the
table.

The scene is written into the PROJECT's own worlds/motus_world.sdf between
marker comments, so it is idempotent (re-running replaces it) and removable
(`motus world table --remove`). Everything outside the markers is yours.
"""
from __future__ import annotations

import math
import random
import re
import xml.etree.ElementTree as ET

BEGIN = "<!-- MOTUS-TABLE-BEGIN (managed by `motus world table`; edit outside this block) -->"
END = "<!-- MOTUS-TABLE-END -->"
FLOOR_MARK = "<!-- MOTUS-TABLE-FLOOR -->"

DEFAULT_HEIGHT = 0.75        # m, tabletop above the floor
DEFAULT_TOP_THICKNESS = 0.04
LEG_SIZE = 0.06
RAIL_HEIGHT = 0.08
RAIL_THICKNESS = 0.03

_BLOCK_RE = re.compile(r"[ \t]*" + re.escape("<!-- MOTUS-TABLE-BEGIN") + r".*?" + re.escape(END) + r"\n?", re.S)
_FLOOR_RE = re.compile(r"[ \t]*<pose>[^<]*</pose>[ \t]*" + re.escape(FLOOR_MARK) + r"[ \t]*\n?")
_GROUND_RE = re.compile(r'(<model\s+name="ground_plane"\s*>\s*<static>\s*true\s*</static>[ \t]*\n?)', re.S)


class SceneError(ValueError):
    pass


def _g(v: float) -> str:
    return f"{v:.4f}".rstrip("0").rstrip(".") if "." in f"{v:.4f}" else f"{v:.4f}"


def _box(name, size, pose, color, mu=None):
    sx, sy, sz = size
    px, py, pz = pose
    surface = ""
    if mu is not None:
        surface = (f"\n          <surface><friction><ode><mu>{mu}</mu><mu2>{mu}</mu2></ode></friction></surface>")
    return f"""      <collision name="{name}_collision">
        <pose>{_g(px)} {_g(py)} {_g(pz)} 0 0 0</pose>
        <geometry><box><size>{_g(sx)} {_g(sy)} {_g(sz)}</size></box></geometry>{surface}
      </collision>
      <visual name="{name}_visual">
        <pose>{_g(px)} {_g(py)} {_g(pz)} 0 0 0</pose>
        <geometry><box><size>{_g(sx)} {_g(sy)} {_g(sz)}</size></box></geometry>
        <material>
          <ambient>{color}</ambient>
          <diffuse>{color}</diffuse>
          <specular>0.1 0.1 0.1 1</specular>
        </material>
      </visual>
"""


def table_model(length, width, height, center, top_thickness=DEFAULT_TOP_THICKNESS) -> str:
    """Static table model whose TOP FACE is at z = 0, x-length by y-width, centred at
    `center` = (cx, cy), legs down to z = -height."""
    cx, cy = center
    t = top_thickness
    leg_h = height - t
    ix = length / 2 - LEG_SIZE / 2 - 0.04      # leg centres, inset from the edge
    iy = width / 2 - LEG_SIZE / 2 - 0.04
    wood, steel = "0.62 0.45 0.28 1", "0.22 0.23 0.26 1"
    parts = [_box("top", (length, width, t), (0, 0, -t / 2), wood, mu=1.0)]
    for i, (sx, sy) in enumerate(((1, 1), (1, -1), (-1, 1), (-1, -1))):
        parts.append(_box(f"leg{i + 1}", (LEG_SIZE, LEG_SIZE, leg_h),
                          (sx * ix, sy * iy, -t - leg_h / 2), steel))
    rz = -t - RAIL_HEIGHT / 2
    parts.append(_box("rail_front", (2 * ix, RAIL_THICKNESS, RAIL_HEIGHT), (0, iy, rz), steel))
    parts.append(_box("rail_back", (2 * ix, RAIL_THICKNESS, RAIL_HEIGHT), (0, -iy, rz), steel))
    parts.append(_box("rail_left", (RAIL_THICKNESS, 2 * iy, RAIL_HEIGHT), (ix, 0, rz), steel))
    parts.append(_box("rail_right", (RAIL_THICKNESS, 2 * iy, RAIL_HEIGHT), (-ix, 0, rz), steel))
    return (f'    <model name="motus_table">\n'
            f'      <static>true</static>\n'
            f'      <pose>{_g(cx)} {_g(cy)} 0 0 0 0</pose>\n'
            f'      <link name="link">\n' + "".join(parts) +
            f'      </link>\n    </model>\n')


def remove_table(world_text: str) -> str:
    """World text with the managed table block and the lowered floor removed."""
    text = _BLOCK_RE.sub("", world_text)
    return _FLOOR_RE.sub("", text)


def apply_table(world_text: str, length: float, width: float, height: float = DEFAULT_HEIGHT,
                center: tuple[float, float] | None = None,
                top_thickness: float = DEFAULT_TOP_THICKNESS) -> str:
    """World text with a table added (or replaced) and the floor lowered by `height`."""
    for name, v in (("length", length), ("width", width), ("height", height)):
        if not (v > 0 and math.isfinite(v)):
            raise SceneError(f"table {name} must be a positive number (got {v}).")
    if top_thickness <= 0 or top_thickness >= height:
        raise SceneError(f"table top thickness must be between 0 and the height ({height} m).")
    if center is None:
        center = (0.25 * length, 0.0)       # base sits 25% of the length in from the back edge

    text = remove_table(world_text)
    m = _GROUND_RE.search(text)
    if m is None:
        raise SceneError('this world has no <model name="ground_plane"> with <static>true</static> '
                         "to lower; add the table by hand or run `motus world init --force` first.")
    floor_pose = f"      <pose>0 0 {_g(-height)} 0 0 0</pose> {FLOOR_MARK}\n"
    text = text[:m.end()] + floor_pose + text[m.end():]

    idx = text.rfind("</world>")
    if idx < 0:
        raise SceneError("not an SDF world (no </world>).")
    idx = text.rfind("\n", 0, idx) + 1          # insert at the start of the </world> line
    block = f"    {BEGIN}\n{table_model(length, width, height, center, top_thickness)}    {END}\n"
    return text[:idx] + block + text[idx:]


def has_table(world_text: str) -> bool:
    return BEGIN[:24] in world_text


def check_scene_xml(world_text: str) -> str | None:
    """None when the world still parses, else a one-line problem."""
    try:
        ET.fromstring(re.sub(r"<!--.*?-->", "", world_text, flags=re.S))
    except ET.ParseError as e:
        return f"world no longer parses: {e}"
    return None


# --------------------------------------------------------------------------
# Sizing from the robot
# --------------------------------------------------------------------------

def estimate_reach(expanded_xml: str, base_link: str, tip_link: str, n_samples: int = 2000,
                   seed: int = 0) -> float | None:
    """Largest horizontal distance (m) the arm's tip reaches from the base axis, over
    random poses inside the joint limits. None if it can't be evaluated."""
    from .safe_pose import _parse_chain, _tip_xy   # numpy is imported lazily there
    try:
        chain = _parse_chain(expanded_xml, base_link, tip_link)
    except ET.ParseError:
        return None
    movable = [j for j in (chain or []) if j["type"] in ("revolute", "continuous", "prismatic")]
    if not movable:
        return None
    rng = random.Random(seed)
    best = 0.0
    for _ in range(n_samples):
        q = {}
        for j in movable:
            lo = j["lo"] if j["lo"] is not None else -math.pi
            hi = j["hi"] if j["hi"] is not None else math.pi
            if j["type"] == "continuous" or hi - lo > 2 * math.pi:
                lo, hi = -math.pi, math.pi
            q[j["name"]] = rng.uniform(lo, hi)
        try:
            xy = _tip_xy(chain, q)
        except Exception:
            return None
        best = max(best, float(math.hypot(xy[0], xy[1])))
    return best or None


def _round_up(v: float, step: float = 0.05) -> float:
    return math.ceil(v / step - 1e-9) * step


def default_size(reach: float | None) -> tuple[float, float]:
    """(length along x, width along y) for a table around an arm of this reach.
    No reach -> a table that suits UR5e/UR10-class arms."""
    r = reach if reach and reach > 0 else 1.0
    return _round_up(1.3 * r + 0.2), _round_up(1.0 * r + 0.2)


# --------------------------------------------------------------------------
# Project-level entry points (used by `motus world table`)
# --------------------------------------------------------------------------

def project_reach(project_root) -> float | None:
    """Horizontal reach (m) of the project's robot, or None if it can't be worked out
    (no xacro module, no description yet, ...). Sizing then falls back to a default."""
    import json
    from pathlib import Path
    from .kinematic_analyzer import analyze
    from .urdf_parser import UrdfParseError
    from .xacro_support import parse_description_file_with_includes

    root = Path(project_root)
    try:
        manifest = json.loads((root / "motus.json").read_text(encoding="utf-8"))
        urdf_dir = root / "src" / manifest["package_name"] / "urdf"
        matches = sorted(urdf_dir.glob(f"{manifest['project_name']}.urdf*"))
        if not matches:
            return None
        desc, _inc, expanded = parse_description_file_with_includes(
            str(matches[0]), xacro_args=manifest.get("xacro_args") or {})
        analysis = analyze(desc)
        return estimate_reach(expanded, analysis.base_link, analysis.tip_link)
    except (UrdfParseError, OSError, KeyError, ValueError):
        return None


def _arm_bases(pkg_dir) -> list:
    """[(x, y), ...] of the project's arms from config/cell_arms.yaml; [] for a single-arm cell."""
    import yaml
    from pathlib import Path
    p = Path(pkg_dir) / "config" / "cell_arms.yaml"
    try:
        arms = (yaml.safe_load(p.read_text(encoding="utf-8")) or {}).get("arms") or []
        return [(float(a.get("spawn_x", 0.0)), float(a.get("spawn_y", 0.0))) for a in arms]
    except (OSError, yaml.YAMLError, AttributeError, TypeError, ValueError):
        return []


def table_in_project(project_root, *, length=None, width=None, height=DEFAULT_HEIGHT,
                     center=None, top_thickness=DEFAULT_TOP_THICKNESS,
                     remove=False) -> dict:
    """Add/replace (or remove) the table in the project's own world, creating that world
    from the core one first if the project doesn't have one yet. Returns a summary dict:
    {path, action, length, width, height, center, reach}."""
    import json
    from pathlib import Path
    from . import project_assets as pa

    root, mp, manifest, pkg_dir = pa._load(project_root)
    world_path = pkg_dir / pa.WORLD_REL
    created = False
    if not world_path.is_file():
        if remove:
            raise SceneError("this project has no world of its own, so there is no table to remove.")
        pa.init_assets(root)
        created = True
        root, mp, manifest, pkg_dir = pa._load(project_root)
    text = world_path.read_text(encoding="utf-8")

    if remove:
        new = remove_table(text)
        summary = {"path": world_path, "action": "removed", "created_world": False}
    else:
        reach = project_reach(root) if (length is None or width is None) else None
        dl, dw = default_size(reach)
        # Multi-arm cell (`motus cell add-arm`): the default table spans every arm base.
        bases = _arm_bases(pkg_dir)
        if len(bases) > 1 and length is None and width is None and center is None:
            xs, ys = [b[0] for b in bases], [b[1] for b in bases]
            length = _round_up(dl + max(xs) - min(xs))
            width = _round_up(dw + max(ys) - min(ys))
            center = (min(xs) - 0.25 * dl + length / 2, (max(ys) + min(ys)) / 2)
        length = length if length is not None else dl
        width = width if width is not None else dw
        new = apply_table(text, length, width, height, center, top_thickness)
        cx, cy = center if center is not None else (0.25 * length, 0.0)
        summary = {"path": world_path, "action": "replaced" if has_table(text) else "added",
                   "length": length, "width": width, "height": height,
                   "center": (cx, cy), "reach": reach, "created_world": created}
    problem = check_scene_xml(new)
    if problem:
        raise SceneError(problem)
    world_path.write_text(new, encoding="utf-8")
    manifest["last_build_fingerprint"] = None
    mp.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    return summary
