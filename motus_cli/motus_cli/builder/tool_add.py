"""
tool_add.py

`motus tool add` -- attach an end-effector tool (parallel gripper first) to
an already-imported Motus project.

Pipeline (everything is computed in memory / a temp dir first; project
files are only written in the final commit phase, so a failure never
leaves a half-edited project):

  locate the tool's xacro macro (--from path, or a --profile's bundled one)
  -> instantiate it on the arm's mount link in a PROBE copy of the entry
     xacro and xacro-expand baseline + probe
  -> diff the two expansions: the tool is exactly the new links/joints
     (no name heuristics for "which links are the gripper")
  -> classify joints (the one joint other joints mimic = the driver; every
     other movable tool joint is state-only in ros2_control), find the TCP
     frame and its offset from the mount link
  -> resolve + copy the macro file(s) and meshes into the project package
     (basename-collision safe: never overwrites an arm mesh)
  -> managed blocks (marked MOTUS-TOOL-BEGIN/END <id>) are inserted into the
     entry xacro (include + instantiation + ros2_control joints),
     controllers.yaml (gripper_action_controller), tools.yaml (the
     gripper_action tool + its grasp_attach sim sidekick), robot.yaml
     (planning_tip_link -> TCP) and objects.yaml (approach_offset)
  -> record inputs + derived descriptor in motus.json so `motus robot add`
     can re-apply the tool after a re-import.

Managed blocks make every edit idempotent and removable
(`motus tool add --replace`, `motus tool remove`) without touching
anything a user hand-edited outside the markers.

Scope, stated plainly:
  * kind 'parallel_gripper' only. Suction / io_only are planned, not built.
  * One gripper per arm: arm.launch.py spawns the controller by the fixed
    name 'gripper_action_controller'.
  * The entry xacro must contain the <ros2_control> block Motus injected at
    import time (ros2_control_injector.py). A source description that ships
    its own hardware block is not extended here (Motus never merges two
    hardware declarations for one robot).
  * Sim only, like the injector: the real-hardware plugin/driver for a tool
    is a separate piece of work.
"""

from __future__ import annotations

import hashlib
import json
import os
import re
import shutil
import tempfile
import xml.etree.ElementTree as ET
from dataclasses import dataclass, field, asdict
from pathlib import Path
from xml.sax.saxutils import quoteattr

import yaml

from . import dependency_resolver as _deps
from . import templates
from .kinematic_analyzer import analyze
from .resource_resolver import rewrite_mesh_uris
from .safe_pose import _mat_mul, _origin_matrix
from .tool_profiles import get_profile, generic_controller_params
from .urdf_parser import UrdfParseError
from .xacro_support import parse_description_file_with_includes

SUPPORTED_KINDS = ("parallel_gripper",)
_PREFIX_PARAMS = ("prefix", "tf_prefix")
_PARENT_PARAMS = ("parent", "parent_link", "connection_link", "attach_to", "parent_frame")
_MOVABLE = ("revolute", "continuous", "prismatic")
_CONTROLLER_NAME = "gripper_action_controller"
_MIN_SANE_EFFORT = 1.0   # N*m; the vendor-URDF bug seen in Motus capped followers at 0.1


class ToolAddError(ValueError):
    pass


# ---------------------------------------------------------------- data

@dataclass
class ToolDescriptor:
    id: str
    kind: str
    profile: str | None
    macro: str
    macro_file: str                 # basename, copied flat into <pkg>/urdf/
    macro_args: dict
    mount_link: str
    tcp_link: str
    tcp_offset: list                # xyz of the TCP in the mount link's frame (m)
    primary_joint: str
    state_only_joints: list
    joint_lower: float
    joint_upper: float
    open_position: float
    closed_position: float
    max_effort: float
    controller: dict
    approach_offset: float
    grasp_tool_id: str
    notes: list = field(default_factory=list)


@dataclass
class ToolAddReport:
    descriptor: ToolDescriptor
    files_written: list = field(default_factory=list)
    meshes_copied: int = 0
    warnings: list = field(default_factory=list)

    def print_summary(self) -> None:
        d = self.descriptor
        print(f"Added tool '{d.id}' ({d.kind}{', ' + d.profile if d.profile else ''}) "
              f"on {d.mount_link}")
        print(f"  macro={d.macro}  tcp={d.tcp_link} @ {[round(v, 4) for v in d.tcp_offset]} m "
              f"from {d.mount_link}")
        print(f"  driver joint={d.primary_joint}  ({len(d.state_only_joints)} state-only joints)")
        print(f"  open={d.open_position}  closed={d.closed_position}  "
              f"max_effort={d.max_effort}  approach_offset={d.approach_offset}")
        print(f"  tools.yaml ids: {d.id}, {d.grasp_tool_id}   meshes copied: {self.meshes_copied}")
        for w in self.warnings:
            print(f"  ! {w}")
        print("  Run `motus doctor`, then `motus build`.")


# ------------------------------------------------------------ text util

def _fmt(v: float) -> str:
    s = f"{float(v):.6g}"
    return s if ("." in s or "e" in s or "E" in s) else s + ".0"


_XML_BLOCK_RE = re.compile(
    r"[ \t]*<!-- MOTUS-TOOL-(?:JOINTS-)?BEGIN (?P<id>\S+) -->.*?"
    r"<!-- MOTUS-TOOL-(?:JOINTS-)?END (?P=id) -->[ \t]*\n?", re.S)


def _strip_xml_blocks(text: str, tool_id: str | None = None) -> str:
    def _sub(m):
        return "" if tool_id is None or m.group("id") == tool_id else m.group(0)
    return _XML_BLOCK_RE.sub(_sub, text)


def _strip_yaml_block(text: str, tool_id: str) -> str:
    b, e = re.escape(f"# MOTUS-TOOL-BEGIN {tool_id}"), re.escape(f"# MOTUS-TOOL-END {tool_id}")
    # also swallow the single blank separator line that precedes an appended block
    return re.sub(rf"(?:(?<=\n)\n)?[ \t]*{b}[ \t]*\n.*?[ \t]*{e}[ \t]*\n?", "", text, flags=re.S)


def _file_hash(p: Path) -> str:
    return hashlib.sha256(p.read_bytes()).hexdigest()


# ------------------------------------------------------- macro discovery

_MACRO_RE = re.compile(
    r'<xacro:macro\s+name\s*=\s*"([^"]+)"\s+params\s*=\s*"([^"]*)"', re.S)


def _macros_in(path: Path) -> dict[str, list[str]]:
    try:
        text = path.read_text(encoding="utf-8")
    except (OSError, UnicodeDecodeError):
        return {}
    return {n: p.split() for n, p in _MACRO_RE.findall(text)}


def _package_root(path: Path) -> Path:
    for parent in [path.parent, *path.parent.parents]:
        if (parent / "package.xml").is_file():
            return parent
    return path.parent


def _locate_macro(source_path, macro, profile, manifest) -> tuple[Path, str, list, Path]:
    """Returns (macro_file, macro_name, macro_params, source_root)."""
    want = macro or (profile.macro_name if profile else None)
    root: Path | None = None
    search: list[Path] = []

    if source_path:
        sp = Path(source_path).expanduser().resolve()
        if sp.is_file():
            search, root = [sp], _package_root(sp)
        elif sp.is_dir():
            root = sp
            search = sorted(p for p in sp.rglob("*") if p.is_file() and p.name.endswith(".xacro"))
        else:
            raise ToolAddError(f"'{source_path}' does not exist.")
    elif profile:
        ws = manifest.get("parent_workspace_root")
        if ws:
            for hit in Path(ws, "src").glob(f"*/{profile.macro_relpath_hint}"):
                search, root = [hit], _package_root(hit)
                break
        if not search:
            raise ToolAddError(
                f"profile '{profile.key}' needs its description source but none was found "
                f"under the parent workspace ({ws}). Pass the description with "
                f"`motus tool add <path> --profile {profile.key}`."
            )
    else:
        raise ToolAddError("give a description path, or --profile <key> "
                           "(known profiles: robotiq_2f_85).")

    found: list[tuple[Path, str, list]] = []
    for f in search:
        for name, params in _macros_in(f).items():
            if want and name != want:
                continue
            has_parent = any(p.split(":=")[0] in _PARENT_PARAMS for p in params)
            if want or has_parent:
                found.append((f, name, params))
    if not found:
        raise ToolAddError(
            f"no xacro macro{' named ' + repr(want) if want else ' with a parent/mount parameter'} "
            f"found in {source_path or 'the profile source'}. Pass --macro NAME if the "
            f"macro takes its mount link under an unusual parameter name.")
    if len(found) > 1:
        names = ", ".join(f"{n} ({f.name})" for f, n, _ in found[:6])
        raise ToolAddError(f"several candidate macros found: {names}. Choose one with --macro NAME.")
    f, name, params = found[0]
    return f, name, params, Path(root or f.parent)


def _macro_call(name: str, params: list, prefix: str, mount: str, extra: dict) -> str:
    attrs, block = {}, ""
    missing = []
    for raw in params:
        if raw.startswith("*"):
            if raw == "*origin":
                block = '<origin xyz="0 0 0" rpy="0 0 0"/>'
            else:
                raise ToolAddError(f"macro '{name}' needs a block parameter '{raw}', which "
                                   f"`motus tool add` can't fill. Wrap it in a small macro.")
            continue
        pname = raw.split(":=")[0]
        has_default = ":=" in raw
        if pname in extra:
            attrs[pname] = extra[pname]
        elif pname in _PARENT_PARAMS:
            attrs[pname] = mount
        elif pname in _PREFIX_PARAMS:
            attrs[pname] = prefix
        elif not has_default:
            missing.append(pname)
    if missing:
        raise ToolAddError(
            f"macro '{name}' has required parameter(s) with no default: {', '.join(missing)}. "
            f"Pass them with --arg NAME=VALUE.")
    inner = "".join(f" {k}={quoteattr(str(v))}" for k, v in attrs.items())
    return f"<xacro:{name}{inner}>{block}</xacro:{name}>" if block else f"<xacro:{name}{inner}/>"


# -------------------------------------------------------- xml analysis

@dataclass
class _J:
    name: str
    type: str
    parent: str
    child: str
    xyz: tuple
    rpy: tuple
    lower: float | None
    upper: float | None
    effort: float | None
    mimic: str | None


def _floats3(text, default=(0.0, 0.0, 0.0)):
    try:
        v = tuple(float(t) for t in (text or "").split())
        return v if len(v) == 3 else default
    except ValueError:
        return default


def _num(v):
    try:
        return float(v) if v is not None else None
    except ValueError:
        return None


def _joints_from_xml(xml_text: str) -> tuple[dict[str, _J], list[str]]:
    try:
        root = ET.fromstring(xml_text)
    except ET.ParseError as e:
        raise ToolAddError(f"expanded description is not valid XML: {e}") from e
    joints, link_names = {}, [l.get("name") for l in root.findall("link")]
    for j in root.findall("joint"):
        origin, limit, mimic = j.find("origin"), j.find("limit"), j.find("mimic")
        joints[j.get("name")] = _J(
            name=j.get("name"), type=j.get("type", "fixed"),
            parent=j.find("parent").get("link"), child=j.find("child").get("link"),
            xyz=_floats3(origin.get("xyz") if origin is not None else None),
            rpy=_floats3(origin.get("rpy") if origin is not None else None),
            lower=_num(limit.get("lower")) if limit is not None else None,
            upper=_num(limit.get("upper")) if limit is not None else None,
            effort=_num(limit.get("effort")) if limit is not None else None,
            mimic=mimic.get("joint") if mimic is not None else None,
        )
    return joints, link_names


def _pick_tcp(new_links, joints: dict[str, _J], explicit: str | None, root_link: str):
    if explicit:
        if explicit not in new_links:
            raise ToolAddError(f"--tcp '{explicit}' is not a link the tool adds "
                               f"(tool links: {', '.join(sorted(new_links)[:8])}...).")
        return explicit, None
    names = sorted(new_links)
    tcp = [l for l in names if re.search(r"(^|_)tcp($|_)", l.lower())]
    if len(tcp) == 1:
        return tcp[0], None
    has_child = {j.parent for j in joints.values()}
    if len(tcp) > 1:
        leaves = [l for l in tcp if l not in has_child]
        if len(leaves) == 1:
            return leaves[0], None
    parent_of = {j.child: j.parent for j in joints.values()}

    def depth(l):
        d = 0
        while l in parent_of and l in new_links:
            l, d = parent_of[l], d + 1
        return d
    fixed_leaves = [l for l in names if l not in has_child
                    and joints.get(next((j.name for j in joints.values() if j.child == l), ""), None)
                    and joints[next(j.name for j in joints.values() if j.child == l)].type == "fixed"]
    if fixed_leaves:
        best = max(fixed_leaves, key=lambda l: (depth(l), l))
        return best, (f"no link named like a TCP in the tool; using deepest fixed leaf '{best}'. "
                      f"Pass --tcp LINK if that is wrong.")
    return root_link, (f"no TCP frame found; using the tool root link '{root_link}'. "
                       f"Pass --tcp LINK, or grasp poses will be off.")


def _tcp_offset(joints: dict[str, _J], tcp: str, mount: str) -> list[float]:
    chain, cur, guard = [], tcp, 0
    by_child = {j.child: j for j in joints.values()}
    while cur != mount:
        j = by_child.get(cur)
        guard += 1
        if j is None or guard > 64:
            raise ToolAddError(f"cannot trace '{tcp}' back to the mount link '{mount}'.")
        chain.append(j)
        cur = j.parent
    m = [[1.0 if i == k else 0.0 for k in range(4)] for i in range(4)]
    for j in reversed(chain):
        m = _mat_mul(m, _origin_matrix(j.xyz, j.rpy))
    return [m[0][3], m[1][3], m[2][3]]


def _classify(new_joints: dict[str, _J], explicit_primary: str | None):
    movable = {n: j for n, j in new_joints.items() if j.type in _MOVABLE}
    if not movable:
        raise ToolAddError("the tool adds no movable joints; a parallel_gripper needs at least one.")
    if explicit_primary:
        if explicit_primary not in movable:
            raise ToolAddError(f"--primary-joint '{explicit_primary}' is not a movable tool joint "
                               f"({', '.join(sorted(movable))}).")
        primary = explicit_primary
    else:
        targets = {j.mimic for j in movable.values() if j.mimic}
        drivers = [n for n, j in movable.items() if not j.mimic and n in targets]
        if len(drivers) == 1:
            primary = drivers[0]
        elif not drivers:
            bounded = [n for n, j in movable.items()
                       if not j.mimic and j.type in ("revolute", "prismatic")]
            if len(bounded) != 1:
                raise ToolAddError(
                    f"cannot tell which joint drives the gripper (candidates: "
                    f"{', '.join(sorted(movable))}). Pass --primary-joint NAME.")
            primary = bounded[0]
        else:
            raise ToolAddError(f"several joints are mimicked ({', '.join(sorted(drivers))}); "
                               f"pass --primary-joint NAME.")
    return primary, sorted(n for n in movable if n != primary)


# ------------------------------------------------------------ expansion

def _expand(urdf_dir: Path, text: str, probe_name: str, xacro_args):
    probe = urdf_dir / probe_name
    probe.write_text(text, encoding="utf-8")
    try:
        return parse_description_file_with_includes(str(probe), xacro_args=xacro_args)
    except UrdfParseError as e:
        raise ToolAddError(str(e)) from e
    finally:
        probe.unlink(missing_ok=True)


def _insert_before_ros2_control(text: str, block: str) -> str:
    i = text.find("<ros2_control")
    if i == -1:
        j = text.rfind("</robot>")
        if j == -1:
            raise ToolAddError("entry xacro has no </robot>.")
        return text[:j] + block + text[j:]
    line_start = text.rfind("\n", 0, i) + 1
    return text[:line_start] + block + text[line_start:]


def _joints_block(tool_id: str, d_primary: str, followers: list, open_pos: float) -> str:
    def state_only(n):
        return (f'      <joint name="{n}">\n        <state_interface name="position"/>\n'
                f'        <state_interface name="velocity"/>\n'
                f'        <state_interface name="effort"/>\n      </joint>\n')
    return (
        f"    <!-- MOTUS-TOOL-JOINTS-BEGIN {tool_id} -->\n"
        f'      <joint name="{d_primary}">\n'
        f'        <command_interface name="position"/>\n'
        f'        <command_interface name="velocity"/>\n'
        f'        <state_interface name="position"><param name="initial_value">{_fmt(open_pos)}</param></state_interface>\n'
        f'        <state_interface name="velocity"><param name="initial_value">0.0</param></state_interface>\n'
        f'        <state_interface name="effort"><param name="initial_value">0.0</param></state_interface>\n'
        f"      </joint>\n"
        + "".join(state_only(n) for n in followers)
        + f"    <!-- MOTUS-TOOL-JOINTS-END {tool_id} -->\n")


def _edit_entry_xacro(text, pkg_name, d: ToolDescriptor, include_ref: str, call: str) -> str:
    text = _strip_xml_blocks(text, d.id)
    block = (f"  <!-- MOTUS-TOOL-BEGIN {d.id} -->\n"
             f'  <xacro:include filename="{include_ref}"/>\n  {call}\n'
             f"  <!-- MOTUS-TOOL-END {d.id} -->\n")
    text = _insert_before_ros2_control(text, block)
    m = re.search(rf'<ros2_control\s+name="{re.escape(pkg_name)}_GazeboSystem"', text)
    if not m:
        raise ToolAddError(
            "the entry xacro has no Motus-injected <ros2_control> block "
            f"('{pkg_name}_GazeboSystem'); tool add only extends a hardware block Motus "
            "created (a source that ships its own is not merged).")
    end = text.find("</ros2_control>", m.end())
    line_start = text.rfind("\n", 0, end) + 1
    return text[:line_start] + _joints_block(
        d.id, d.primary_joint, d.state_only_joints, d.open_position) + text[line_start:]


def _edit_controllers(text: str, d: ToolDescriptor) -> str:
    text = _strip_yaml_block(text, d.id)
    if re.search(rf"^\s*{_CONTROLLER_NAME}:", text, re.M) or f"/**/{_CONTROLLER_NAME}" in text:
        raise ToolAddError(f"controllers.yaml already defines '{_CONTROLLER_NAME}' outside a "
                           f"Motus-managed block; remove it or edit by hand.")
    m = re.search(r"^    arm_controller:\n      type: [^\n]+\n", text, re.M)
    if not m:
        raise ToolAddError("controllers.yaml has no 'arm_controller' type entry under "
                           "/**/controller_manager to anchor the gripper controller on.")
    decl = (f"    # MOTUS-TOOL-BEGIN {d.id}\n    {_CONTROLLER_NAME}:\n"
            f"      type: parallel_gripper_action_controller/GripperActionController\n"
            f"    # MOTUS-TOOL-END {d.id}\n")
    text = text[:m.end()] + decl + text[m.end():]
    c = d.controller
    body = (
        f"\n# MOTUS-TOOL-BEGIN {d.id}\n"
        f"# {d.id}: native-mimic gripper -- only the driver joint is commanded; the other\n"
        f"# tool joints follow via the URDF <mimic> tags (gz_ros2_control mimic support).\n"
        f"/**/{_CONTROLLER_NAME}:\n  ros__parameters:\n"
        f"    joint: {d.primary_joint}\n"
        f"    action_monitor_rate: {_fmt(c['action_monitor_rate'])}\n"
        f"    goal_tolerance: {_fmt(c['goal_tolerance'])}\n"
        f"    allow_stalling: {'true' if c['allow_stalling'] else 'false'}\n"
        f"    stall_velocity_threshold: {_fmt(c['stall_velocity_threshold'])}\n"
        f"    stall_timeout: {_fmt(c['stall_timeout'])}\n"
        f"    max_effort: {_fmt(c['max_effort'])}\n"
        f"# MOTUS-TOOL-END {d.id}\n")
    return text.rstrip("\n") + "\n" + body


def _tools_block(d: ToolDescriptor) -> str:
    action = f"arm1/{_CONTROLLER_NAME}/gripper_cmd"
    return (
        f"# MOTUS-TOOL-BEGIN {d.id}\n"
        f"{d.id}:\n  backend: gripper_action\n  action_name: {action}\n"
        f"  joint_name: {d.primary_joint}\n  open_position: {_fmt(d.open_position)}\n"
        f"  closed_position: {_fmt(d.closed_position)}\n  max_effort: {_fmt(d.max_effort)}\n"
        f"  action_timeout: 5.0\n\n"
        f"{d.grasp_tool_id}:\n  backend: grasp_attach\n  service_name: /grasp_attach\n"
        f"  service_timeout: 5.0\n"
        f"  # parent_model / parent_link / objects_catalog_path are injected at launch\n"
        f"  # from objects.yaml (cell.launch.py).\n"
        f"  gripper_mechanism: parallel_jaw\n  action_name: {action}\n"
        f"  joint_name: {d.primary_joint}\n  open_position: {_fmt(d.open_position)}\n"
        f"  closed_position: {_fmt(d.closed_position)}\n  max_effort: 50.0\n"
        f"  action_timeout: 5.0\n  min_close_ratio: 0.3\n"
        f"# MOTUS-TOOL-END {d.id}\n")


def _edit_tools_yaml(text: str | None, d: ToolDescriptor) -> str:
    header = ("# tools.yaml -- tool_action_server backend config.\n"
              "# Blocks between MOTUS-TOOL-BEGIN/END are owned by `motus tool add`; anything\n"
              "# outside them is yours and is never touched.\n"
              "# Needs the canonical gripper config keys (action_name/joint_name/...) -- i.e. a\n"
              "# tool_action_server.py with the normalized schema.\n\n")
    text = _strip_yaml_block(text, d.id) if text else header
    return text.rstrip("\n") + "\n\n" + _tools_block(d)


def _edit_robot_yaml(text: str, tip: str) -> str:
    new, n = re.subn(r"(planning_tip_link:\s*)\S+", rf"\g<1>{tip}", text, count=1)
    if n == 0:
        raise ToolAddError("robot.yaml has no planning_tip_link to retarget at the TCP.")
    return new


_APPROACH_RE = re.compile(r"^  approach_offset:[^\n]*\n(?:[ \t]+#[^\n]*\n)*", re.M)


def _edit_objects_yaml(text: str, value: float, why: str) -> str:
    if not _APPROACH_RE.search(text):
        return text
    line = f"  approach_offset: {_fmt(value)}   # {why}\n"
    return _APPROACH_RE.sub(line, text, count=1)


def _grasp_id(tool_id: str) -> str:
    return ("grasp_attach_" + tool_id[len("gripper_"):]) if tool_id.startswith("gripper_") \
        else f"grasp_attach_{tool_id}"


# ----------------------------------------------------------- main entry

def _load(project_root: Path):
    mp = project_root / "motus.json"
    if not mp.is_file():
        raise ToolAddError(f"'{project_root}' doesn't look like a Motus project (no motus.json).")
    manifest = json.loads(mp.read_text(encoding="utf-8"))
    pkg_dir = project_root / "src" / manifest["package_name"]
    entry = pkg_dir / "urdf" / f"{manifest['project_name']}.urdf.xacro"
    if not entry.is_file():
        raise ToolAddError(f"{entry} not found -- run `motus robot add <path>` first.")
    return mp, manifest, pkg_dir, entry


def tool_add(
    project_root, *, source_path: str | None = None, tool_id: str = "gripper_1",
    kind: str = "parallel_gripper", profile: str | None = None, macro: str | None = None,
    macro_args: dict | None = None, mount_link: str | None = None, tcp_link: str | None = None,
    primary_joint: str | None = None, open_position: float | None = None,
    closed_position: float | None = None, max_effort: float | None = None,
    replace: bool = False,
) -> ToolAddReport:
    if kind not in SUPPORTED_KINDS:
        raise ToolAddError(f"tool kind '{kind}' is not implemented yet "
                           f"(supported: {', '.join(SUPPORTED_KINDS)}).")
    prof = get_profile(profile)
    if prof and prof.kind != kind:
        raise ToolAddError(f"profile '{prof.key}' is a {prof.kind}, not a {kind}.")

    project_root = Path(project_root).resolve()
    manifest_path, manifest, pkg_dir, entry = _load(project_root)
    pkg_name = manifest["package_name"]
    tools = manifest.setdefault("tools", {})
    if tool_id in tools and not replace:
        raise ToolAddError(f"tool '{tool_id}' already exists; use --replace to redo it.")
    for other_id, rec in tools.items():
        if other_id != tool_id and rec["descriptor"]["kind"] == "parallel_gripper":
            raise ToolAddError(
                f"'{other_id}' is already this arm's gripper; arm.launch.py spawns a single "
                f"'{_CONTROLLER_NAME}'. Remove it first (`motus tool remove {other_id}`).")

    macro_args = dict(macro_args or {})
    xacro_args = manifest.get("xacro_args") or {}
    prefix = xacro_args.get("tf_prefix", "")
    urdf_dir = pkg_dir / "urdf"
    warnings: list[str] = []

    macro_file, macro_name, macro_params, source_root = _locate_macro(
        source_path, macro, prof, manifest)

    # ---- baseline (entry minus any managed tool blocks) vs probe (with this tool)
    base_text = _strip_xml_blocks(entry.read_text(encoding="utf-8"))
    desc_b, inc_b, xml_b = _expand(urdf_dir, base_text, "_motus_probe_base.urdf.xacro", xacro_args)
    analysis_b = analyze(desc_b)
    mount = mount_link or analysis_b.tip_link
    if mount not in desc_b.links:
        raise ToolAddError(f"mount link '{mount}' does not exist in the robot "
                           f"(arm tip is '{analysis_b.tip_link}').")

    call = _macro_call(macro_name, macro_params, prefix, mount, macro_args)
    probe_block = (f'  <xacro:include filename="{macro_file}"/>\n  {call}\n')
    probe_text = _insert_before_ros2_control(base_text, probe_block)
    desc_t, inc_t, xml_t = _expand(urdf_dir, probe_text, "_motus_probe_tool.urdf.xacro", xacro_args)

    joints_t, link_names_t = _joints_from_xml(xml_t)
    dup = sorted({n for n in link_names_t if link_names_t.count(n) > 1})
    if dup:
        raise ToolAddError(f"the tool reuses link names already in the robot ({', '.join(dup[:5])}); "
                           f"give it a prefix (--arg prefix=tool_).")
    new_links = set(desc_t.links) - set(desc_b.links)
    new_joints = {n: j for n, j in joints_t.items() if n in set(desc_t.joints) - set(desc_b.joints)}
    if not new_links:
        raise ToolAddError("instantiating the macro added no links.")

    roots = [j for j in new_joints.values() if j.parent in desc_b.links]
    if not roots:
        raise ToolAddError("the tool is not attached to the robot (no joint connects it).")
    root_joint = roots[0]
    if root_joint.parent != mount:
        warnings.append(f"the macro attached to '{root_joint.parent}', not the requested '{mount}'.")
    mount_actual = root_joint.parent

    primary, followers = _classify(new_joints, primary_joint)
    pj = new_joints[primary]
    tcp, tcp_note = _pick_tcp(new_links, joints_t, tcp_link, root_joint.child)
    if tcp_note:
        warnings.append(tcp_note)
    offset = _tcp_offset(joints_t, tcp, mount_actual)

    # ---- targets: CLI > profile > generic
    if prof:
        o, c, eff = prof.open_position, prof.closed_position, prof.max_effort
        ctrl = dict(prof.controller)
    else:
        if pj.lower is None or pj.upper is None:
            if open_position is None or closed_position is None:
                raise ToolAddError(f"driver joint '{primary}' has no position limits; pass "
                                   f"--open and --closed.")
            lo, hi = min(open_position, closed_position), max(open_position, closed_position)
        else:
            lo, hi = pj.lower, pj.upper
        o, c, eff = lo, lo + 0.95 * (hi - lo), 5.0
        ctrl = generic_controller_params(eff)
        warnings.append("targets are generic: closing is assumed to be the +direction "
                        f"(open={_fmt(o)}, closed={_fmt(c)}) and max_effort {eff} is a default. "
                        "Override with --open/--closed/--max-effort if wrong.")
    o = o if open_position is None else open_position
    c = c if closed_position is None else closed_position
    if max_effort is not None:
        eff, ctrl["max_effort"] = max_effort, max_effort
    if pj.lower is not None and pj.upper is not None:
        for label, v in (("open", o), ("closed", c)):
            if not (pj.lower - 1e-9 <= v <= pj.upper + 1e-9):
                raise ToolAddError(f"{label} position {v} is outside the driver joint's limits "
                                   f"[{pj.lower}, {pj.upper}] -- it would jam or saturate.")

    approach, why = 0.0, "NOT calibrated for this tool; measure it (see robokpy_controller objects.yaml)"
    if prof and prof.reference_tcp_offset:
        dist = max(abs(a - b) for a, b in zip(offset, prof.reference_tcp_offset))
        if dist <= 0.002:
            approach, why = prof.approach_offset, f"calibrated for {prof.display_name} (profile {prof.key})"
        else:
            warnings.append(f"profile {prof.key}'s approach_offset was measured for a TCP at "
                            f"{list(prof.reference_tcp_offset)}, this one is at "
                            f"{[round(v, 4) for v in offset]} -- using 0.0.")

    desc = ToolDescriptor(
        id=tool_id, kind=kind, profile=profile, macro=macro_name, macro_file=macro_file.name,
        macro_args=macro_args, mount_link=mount_actual, tcp_link=tcp,
        tcp_offset=[round(v, 6) for v in offset], primary_joint=primary,
        state_only_joints=followers, joint_lower=pj.lower if pj.lower is not None else o,
        joint_upper=pj.upper if pj.upper is not None else c, open_position=o, closed_position=c,
        max_effort=eff, controller=ctrl, approach_offset=approach,
        grasp_tool_id=_grasp_id(tool_id),
        notes=[prof.notes] if prof and prof.notes else [])

    low_effort = sorted(n for n, j in new_joints.items()
                        if j.type in _MOVABLE and j.effort is not None and j.effort < _MIN_SANE_EFFORT)
    if low_effort:
        warnings.append(f"joint effort limit below {_MIN_SANE_EFFORT} N*m on: "
                        f"{', '.join(low_effort[:4])} -- followers this weak stall the gripper in sim "
                        f"(seen in a vendor URDF at 0.1). Fix in the source description.")

    # ---- resolve the macro file(s) + meshes into temp dirs
    tool_includes = [p for p in inc_t if p not in set(inc_b) and not p.startswith(str(urdf_dir))]
    if str(macro_file) not in tool_includes:
        tool_includes.insert(0, str(macro_file))
    mesh_uris = sorted({u for l in new_links for u in desc_t.links[l].mesh_uris})
    tmp = Path(tempfile.mkdtemp(prefix="motus_tool_"))
    try:
        dep = _deps.resolve_all(
            urdf_file_path=str(macro_file), mesh_uris=mesh_uris, include_paths=tool_includes,
            dest_urdf_dir=str(tmp / "urdf"), dest_meshes_dir=str(tmp / "meshes"),
            source_root=str(source_root))
        res = dep.mesh_result
        if res.unresolved:
            raise ToolAddError(
                f"{len(res.unresolved)} tool mesh(es) could not be located under {source_root}: "
                + ", ".join(res.unresolved[:4]) + (" ..." if len(res.unresolved) > 4 else "")
                + ". Point `motus tool add` at the description's package root.")

        # never overwrite an existing (arm) mesh with a different file of the same name
        meshes_dir = pkg_dir / "meshes"
        renamed = 0
        for r in res.resolved:
            existing = meshes_dir / r.dest_relative_path
            src_tmp = tmp / "meshes" / os.path.basename(r.source_path)
            if existing.is_file() and src_tmp.is_file() and _file_hash(existing) != _file_hash(src_tmp):
                r.dest_relative_path = f"{tool_id}__{r.dest_relative_path}"
                renamed += 1
        if renamed:
            warnings.append(f"{renamed} tool mesh name(s) clashed with existing meshes; "
                            f"prefixed with '{tool_id}__'.")

        # rewritten copies of the macro file(s) (include + mesh URIs)
        rewritten = {}
        for base in dep.copied_includes:
            t = (tmp / "urdf" / base).read_text(encoding="utf-8")
            t = _deps.rewrite_include_uris(t, dep.copied_includes)
            rewritten[base] = rewrite_mesh_uris(t, res, pkg_name)

        # ---- compute every new text BEFORE writing anything
        entry_new = _edit_entry_xacro(
            entry.read_text(encoding="utf-8"), pkg_name, desc, macro_file.name, call)
        ctrl_path, robot_path = pkg_dir / "config" / "controllers.yaml", pkg_dir / "config" / "robot.yaml"
        tools_path, obj_path = pkg_dir / "config" / "tools.yaml", pkg_dir / "config" / "objects.yaml"
        ctrl_new = _edit_controllers(ctrl_path.read_text(encoding="utf-8"), desc)
        robot_new = _edit_robot_yaml(robot_path.read_text(encoding="utf-8"), tcp)
        tools_new = _edit_tools_yaml(
            tools_path.read_text(encoding="utf-8") if tools_path.is_file() else None, desc)
        obj_new = (_edit_objects_yaml(obj_path.read_text(encoding="utf-8"), approach, why)
                   if obj_path.is_file() else None)
        for name, text in (("controllers.yaml", ctrl_new), ("tools.yaml", tools_new)):
            try:
                yaml.safe_load(text)
            except yaml.YAMLError as e:   # fail before touching disk
                raise ToolAddError(f"generated {name} is not valid YAML: {e}") from e

        # ---- commit
        report = ToolAddReport(descriptor=desc, warnings=warnings)
        urdf_dir.mkdir(parents=True, exist_ok=True)
        meshes_dir.mkdir(parents=True, exist_ok=True)
        for base, text in rewritten.items():
            (urdf_dir / base).write_text(text, encoding="utf-8")
            report.files_written.append(f"urdf/{base}")
        for r in res.resolved:
            shutil.copy2(tmp / "meshes" / os.path.basename(r.source_path),
                         meshes_dir / r.dest_relative_path)
            report.meshes_copied += 1
        for dep_name in res.dependencies:
            s, t = tmp / "meshes" / dep_name, meshes_dir / dep_name
            if s.is_file() and (not t.exists() or _file_hash(s) == _file_hash(t)):
                shutil.copy2(s, t)
            elif s.is_file():
                warnings.append(f"texture '{dep_name}' already exists with different content; kept the existing one.")
    finally:
        shutil.rmtree(tmp, ignore_errors=True)

    entry.write_text(entry_new, encoding="utf-8")
    ctrl_path.write_text(ctrl_new, encoding="utf-8")
    robot_path.write_text(robot_new, encoding="utf-8")
    tools_path.write_text(tools_new, encoding="utf-8")
    if obj_new is not None:
        obj_path.write_text(obj_new, encoding="utf-8")
    report.files_written += ["urdf/" + entry.name, "config/controllers.yaml", "config/robot.yaml",
                             "config/tools.yaml"] + (["config/objects.yaml"] if obj_new else [])

    launch_path = pkg_dir / "launch" / f"{manifest['project_name']}.launch.py"
    if launch_path.is_file() and "tools_config_path" not in launch_path.read_text(encoding="utf-8"):
        launch_path.write_text(templates.LAUNCH_WRAPPER.format(
            launch_name=launch_path.name, robot_name=manifest["project_name"], pkg_name=pkg_name,
            urdf_filename=entry.name,
            external_xacro_args_json=repr(json.dumps(manifest.get("xacro_args") or {}))),
            encoding="utf-8")
        report.files_written.append(f"launch/{launch_path.name}")

    manifest.setdefault("arm_tip_link", analysis_b.tip_link)
    tools[tool_id] = {
        "inputs": {
            "source_path": str(Path(source_path).resolve()) if source_path else None,
            "tool_id": tool_id, "kind": kind, "profile": profile, "macro": macro,
            "macro_args": macro_args, "mount_link": mount_link, "tcp_link": tcp_link,
            "primary_joint": primary_joint, "open_position": open_position,
            "closed_position": closed_position, "max_effort": max_effort,
        },
        "descriptor": asdict(desc),
    }
    manifest["last_build_fingerprint"] = None
    manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    return report


def tool_remove(project_root, tool_id: str) -> None:
    project_root = Path(project_root).resolve()
    manifest_path, manifest, pkg_dir, entry = _load(project_root)
    tools = manifest.get("tools") or {}
    if tool_id not in tools:
        raise ToolAddError(f"no tool '{tool_id}' in this project (have: {', '.join(tools) or 'none'}).")
    for path in (entry, pkg_dir / "config" / "controllers.yaml", pkg_dir / "config" / "tools.yaml"):
        if path.is_file():
            t = path.read_text(encoding="utf-8")
            t = _strip_xml_blocks(t, tool_id) if path == entry else _strip_yaml_block(t, tool_id)
            path.write_text(t, encoding="utf-8")
    robot_path = pkg_dir / "config" / "robot.yaml"
    tip = manifest.get("arm_tip_link")
    if tip and robot_path.is_file():
        robot_path.write_text(_edit_robot_yaml(robot_path.read_text(encoding="utf-8"), tip), encoding="utf-8")
    obj_path = pkg_dir / "config" / "objects.yaml"
    if obj_path.is_file():
        obj_path.write_text(_edit_objects_yaml(
            obj_path.read_text(encoding="utf-8"), 0.0,
            "NOT calibrated for this tool; measure it (see robokpy_controller objects.yaml)"),
            encoding="utf-8")
    del tools[tool_id]
    manifest["last_build_fingerprint"] = None
    manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")


def reapply_tools(project_root) -> list[str]:
    """Called by robot_add after a (re-)import regenerates the entry xacro and
    configs: puts every recorded tool back. Returns human-readable notes."""
    project_root = Path(project_root).resolve()
    manifest = json.loads((project_root / "motus.json").read_text(encoding="utf-8"))
    notes = []
    for tool_id, rec in list((manifest.get("tools") or {}).items()):
        try:
            tool_add(project_root, replace=True, **rec["inputs"])
            notes.append(f"re-applied tool '{tool_id}'")
        except ToolAddError as e:
            notes.append(f"COULD NOT re-apply tool '{tool_id}': {e}")
    return notes


def list_tools(project_root) -> list[dict]:
    manifest = json.loads((Path(project_root) / "motus.json").read_text(encoding="utf-8"))
    return [rec["descriptor"] for rec in (manifest.get("tools") or {}).values()]


# --------------------------------------------------------------- doctor

def run_tool_checks(project_root, manifest: dict, pkg_dir: Path, desc) -> list[tuple]:
    """(name, ok, level, detail) tuples; doctor.py turns them into Checks."""
    out: list[tuple] = []
    tools = manifest.get("tools") or {}
    if not tools:
        return out
    entry = pkg_dir / "urdf" / f"{manifest['project_name']}.urdf.xacro"
    entry_text = entry.read_text(encoding="utf-8") if entry.is_file() else ""

    def load_yaml(p: Path):
        try:
            return yaml.safe_load(p.read_text(encoding="utf-8")) or {}
        except (OSError, yaml.YAMLError):
            return None

    ctrl = load_yaml(pkg_dir / "config" / "controllers.yaml") or {}
    robot = load_yaml(pkg_dir / "config" / "robot.yaml") or {}
    tools_yaml = load_yaml(pkg_dir / "config" / "tools.yaml")
    tip = ((robot.get("/**") or {}).get("ros__parameters") or {}).get("planning_tip_link")

    for tid, rec in tools.items():
        d = rec["descriptor"]
        label = f"Tool {tid}"
        need = [d["primary_joint"], *d["state_only_joints"]]
        missing = [j for j in need if j not in desc.joints]
        out.append((f"{label}: joints in URDF", not missing, "error",
                    f"missing from the expanded URDF: {', '.join(missing[:5])}"))
        out.append((f"{label}: TCP frame", d["tcp_link"] in desc.links and tip == d["tcp_link"], "error",
                    f"tcp link '{d['tcp_link']}' "
                    f"{'missing from URDF' if d['tcp_link'] not in desc.links else 'ok'}; "
                    f"robot.yaml planning_tip_link is '{tip}'"))
        out.append((f"{label}: ros2_control joints",
                    f"MOTUS-TOOL-JOINTS-BEGIN {tid}" in entry_text, "error",
                    "driver/state joints are not declared in the entry xacro's <ros2_control> block"))
        gc = ctrl.get("/**/" + _CONTROLLER_NAME) or ctrl.get(_CONTROLLER_NAME) or {}
        cm = (ctrl.get("/**/controller_manager") or {}).get("ros__parameters") or {}
        joint_ok = (gc.get("ros__parameters") or {}).get("joint") == d["primary_joint"]
        out.append((f"{label}: controller", _CONTROLLER_NAME in cm and joint_ok, "error",
                    f"controllers.yaml must declare {_CONTROLLER_NAME} on joint {d['primary_joint']}"))
        entries_ok = False
        if isinstance(tools_yaml, dict):
            g, s = tools_yaml.get(tid) or {}, tools_yaml.get(d["grasp_tool_id"]) or {}
            entries_ok = (g.get("joint_name") == d["primary_joint"]
                          and s.get("joint_name") == d["primary_joint"])
        out.append((f"{label}: tools.yaml", entries_ok, "error",
                    f"config/tools.yaml needs '{tid}' and '{d['grasp_tool_id']}' on joint {d['primary_joint']}"))
        lo, hi = d["joint_lower"], d["joint_upper"]
        in_range = all(lo - 1e-9 <= d[k] <= hi + 1e-9 for k in ("open_position", "closed_position"))
        out.append((f"{label}: open/closed targets", in_range, "error",
                    f"targets must lie inside the driver joint limits [{lo}, {hi}]"))
        weak = sorted(j for j in need if j in desc.joints and desc.joints[j].limit
                      and desc.joints[j].limit.effort is not None
                      and desc.joints[j].limit.effort < _MIN_SANE_EFFORT)
        out.append((f"{label}: joint effort limits", not weak, "warning",
                    f"below {_MIN_SANE_EFFORT} N*m on {', '.join(weak[:4])}"))

    ws = manifest.get("parent_workspace_root")
    cell = Path(ws, "src", "robokpy_controller", "launch", "cell.launch.py") if ws else None
    if cell and cell.is_file():
        out.append(("Core supports project tools.yaml",
                    "tools_config_path" in cell.read_text(encoding="utf-8"), "error",
                    "robokpy_controller/launch/cell.launch.py has no tools_config_path argument, "
                    "so this project's tools.yaml would be silently ignored. Update robokpy_controller."))
    return out
