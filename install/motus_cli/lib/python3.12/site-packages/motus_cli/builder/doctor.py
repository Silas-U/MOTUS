"""
doctor.py

`motus doctor` -- validates whatever is CURRENTLY on disk in a project,
not what robot_add.py last wrote. Deliberately separate from
robot_add's own warnings: a project can be doctor-checked long after
import, including after hand-edits to urdf/config/controllers files that
robot_add never saw. Re-parses and re-analyzes the live URDF rather than
trusting motus.json, so it catches drift (e.g. someone hand-edits
controllers.yaml's joint list and typos a name).
"""

from __future__ import annotations

from dataclasses import dataclass
import json
import os
from pathlib import Path

import yaml

from .urdf_parser import UrdfParseError
from .xacro_support import parse_description_file
from .kinematic_analyzer import analyze


@dataclass
class Check:
    name: str
    ok: bool
    level: str = "error"   # 'error' | 'warning', only meaningful when ok is False
    detail: str = ""


class DoctorFatalError(ValueError):
    """Raised for problems that stop the checks entirely (no project
    found, URDF doesn't even parse) -- everything else degrades to a
    per-check failure so one bad file doesn't hide every other result."""


def _find_urdf(urdf_dir: Path, robot_name: str) -> Path | None:
    matches = sorted(urdf_dir.glob(f"{robot_name}.urdf*"))
    return matches[0] if matches else None


def run_doctor(project_root: str | os.PathLike) -> list[Check]:
    project_root = Path(project_root)
    manifest_path = project_root / "motus.json"
    if not manifest_path.is_file():
        raise DoctorFatalError(
            f"'{project_root}' doesn't look like a Motus project (no motus.json)."
        )
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    pkg_name = manifest["package_name"]
    robot_name = manifest["project_name"]
    pkg_dir = project_root / "src" / pkg_name

    checks: list[Check] = []

    # --- package structure ---
    checks.append(Check("Package directory", pkg_dir.is_dir(),
                         detail=str(pkg_dir)))
    checks.append(Check("package.xml", (pkg_dir / "package.xml").is_file()))
    checks.append(Check("setup.py", (pkg_dir / "setup.py").is_file()))
    checks.append(Check("resource marker", (pkg_dir / "resource" / pkg_name).is_file()))

    urdf_dir = pkg_dir / "urdf"
    urdf_path = _find_urdf(urdf_dir, robot_name)
    checks.append(Check("URDF present", urdf_path is not None,
                         detail=f"expected {robot_name}.urdf(.xacro) under {urdf_dir}"))
    if urdf_path is None:
        return checks  # nothing further can be checked without a URDF

    # --- URDF parses ---
    try:
        desc = parse_description_file(str(urdf_path))
        checks.append(Check("URDF parses", True))
    except UrdfParseError as e:
        checks.append(Check("URDF parses", False, "error", str(e)))
        return checks  # can't analyze or check meshes on an unparseable file

    # --- mesh resources referenced actually exist on disk in THIS package ---
    all_mesh_uris = sorted({uri for link in desc.links.values() for uri in link.mesh_uris})
    missing_meshes = []
    for uri in all_mesh_uris:
        prefix = f"package://{pkg_name}/meshes/"
        if uri.startswith(prefix):
            rel = uri[len(prefix):]
            if not (pkg_dir / "meshes" / rel).is_file():
                missing_meshes.append(uri)
        else:
            # Not pointing at this package's own meshes/ -- either an
            # un-rewritten external reference (robot_add missed it) or a
            # deliberately shared/system mesh. Flag, don't hard-fail --
            # doctor can't know which without more context than it has.
            missing_meshes.append(f"{uri} (does not point into this package's meshes/)")
    if missing_meshes:
        checks.append(Check(
            "Mesh resources", False, "error",
            "; ".join(f"missing: {m}" for m in missing_meshes[:5]) +
            (f" (+{len(missing_meshes) - 5} more)" if len(missing_meshes) > 5 else ""),
        ))
    else:
        checks.append(Check("Mesh resources", True))

    # --- kinematic analysis ---
    result = analyze(desc)
    checks.append(Check(
        "Joint definitions", result.dof > 0, "error" if result.dof == 0 else "warning",
        detail=(
            "no movable joints found -- has `motus robot add <path>` been run yet?"
            if result.dof == 0 else
            f"base={result.base_link} tip={result.tip_link} dof={result.dof}"
        ),
    ))
    missing_limit_warnings = [w for w in result.warnings if w.kind == "missing_limit"]
    checks.append(Check(
        "Joint limits", not missing_limit_warnings,
        "warning",
        detail="; ".join(w.message for w in missing_limit_warnings[:3]) +
               (f" (+{len(missing_limit_warnings) - 3} more)" if len(missing_limit_warnings) > 3 else ""),
    ))
    fork_or_dead_end = [w for w in result.warnings if w.kind in ("fork", "dead_end_frame")]
    if fork_or_dead_end:
        checks.append(Check(
            "Chain structure", True, "warning",  # informational, ok stays True
            detail="; ".join(w.message for w in fork_or_dead_end[:3]),
        ))

    # --- config files present and well-formed ---
    robot_yaml_path = pkg_dir / "config" / "robot.yaml"
    controllers_yaml_path = pkg_dir / "config" / "controllers.yaml"
    checks.append(Check("config/robot.yaml present", robot_yaml_path.is_file()))
    checks.append(Check("config/controllers.yaml present", controllers_yaml_path.is_file()))

    controllers_yaml = None
    if controllers_yaml_path.is_file():
        try:
            controllers_yaml = yaml.safe_load(controllers_yaml_path.read_text(encoding="utf-8"))
            checks.append(Check("config/controllers.yaml parses", True))
        except yaml.YAMLError as e:
            checks.append(Check("config/controllers.yaml parses", False, "error", str(e)))

    if robot_yaml_path.is_file():
        try:
            yaml.safe_load(robot_yaml_path.read_text(encoding="utf-8"))
            checks.append(Check("config/robot.yaml parses", True))
        except yaml.YAMLError as e:
            checks.append(Check("config/robot.yaml parses", False, "error", str(e)))

    # --- controllers.yaml joint list matches the URDF's actual joints ---
    # This is the #1 real-world hand-edit failure mode noted in the
    # original design doc -- catch it explicitly rather than letting it
    # surface as an opaque ros2_control error at launch time.
    if controllers_yaml is not None and result.dof > 0:
        configured = set(
            controllers_yaml.get("arm_controller", {})
            .get("ros__parameters", {})
            .get("joints", [])
        )
        expected = set(result.joint_names)
        if configured != expected:
            missing = expected - configured
            extra = configured - expected
            detail_parts = []
            if missing:
                detail_parts.append(f"missing from controllers.yaml: {', '.join(sorted(missing))}")
            if extra:
                detail_parts.append(f"in controllers.yaml but not in URDF: {', '.join(sorted(extra))}")
            checks.append(Check(
                "controllers.yaml joints match URDF", False, "error",
                detail="; ".join(detail_parts),
            ))
        else:
            checks.append(Check("controllers.yaml joints match URDF", True))

    # --- launch file present ---
    launch_path = pkg_dir / "launch" / f"{robot_name}.launch.py"
    checks.append(Check("Launch file", launch_path.is_file()))

    return checks


def print_report(robot_name: str, checks: list[Check]) -> bool:
    """Returns True if the project is build-ready (no error-level failures;
    warnings don't block)."""
    errors = [c for c in checks if not c.ok and c.level == "error"]
    warnings = [c for c in checks if not c.ok and c.level == "warning"]

    print(f"Motus Project: {robot_name}\n")
    for c in checks:
        if c.ok:
            print(f"  \u2713 {c.name}")
        elif c.level == "warning":
            print(f"  \u26a0 {c.name}: {c.detail}")
        else:
            print(f"  \u2717 {c.name}: {c.detail}")

    print()
    if not errors and not warnings:
        print("Project is ready to build.")
        return True
    if errors:
        print(f"\u2717 {len(errors)} problem(s) found ({len(warnings)} warning(s) also present)")
        for c in errors:
            print(f"  [ERROR] {c.name}: {c.detail}")
        for c in warnings:
            print(f"  [WARNING] {c.name}: {c.detail}")
        return False
    print(f"\u26a0 {len(warnings)} warning(s) -- not build-blocking, but worth fixing:")
    for c in warnings:
        print(f"  [WARNING] {c.name}: {c.detail}")
    return True
