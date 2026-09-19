"""
build_cmd.py

`motus build` = re-run the same checks `motus doctor` runs (refuse to
build a project with unresolved errors -- matches the original design's
"validate project / validate URDF / ... / colcon build / report result"
flow) -> `colcon build --packages-select <pkg>` -> record a build
fingerprint in motus.json so a future `motus doctor` (or launch) can
tell "built" from "edited since last build" apart, if that distinction
becomes useful later.

Deliberately does NOT use --symlink-install by default: regenerated
files (config/urdf/launch, from `motus robot add` re-imports) should
require an explicit `motus build` to take effect, not silently apply
themselves through a symlink -- a copy-based install makes "have I
actually rebuilt since I last changed something" unambiguous, at the
cost of needing an explicit rebuild after every `robot add`.

NOT tested against a real colcon invocation -- this sandbox has no
ROS/colcon installed. The doctor-gating logic, missing-colcon handling,
and fingerprinting are plain Python and are exercised below; the actual
`subprocess.run(['colcon', ...])` call is not something I can verify
here beyond "constructs the right argv and cwd". Worth a real run
against your workspace before trusting it blindly.
"""

from __future__ import annotations

import hashlib
import json
import os
import shutil
import subprocess
from pathlib import Path

from .doctor import run_doctor, print_report, DoctorFatalError


class BuildError(ValueError):
    pass


def _fingerprint(pkg_dir: Path) -> str:
    """Hash of the files that actually determine build/runtime
    behavior (URDF, config, controllers, launch) -- NOT a hash of the
    whole package (setup.py/package.xml boilerplate changing shouldn't
    matter for "has the robot description changed since I last built").
    Used only as an informational marker in motus.json; nothing in this
    pipeline currently reads it back to skip work."""
    h = hashlib.sha256()
    for pattern in ("urdf/**/*", "config/*.yaml", "launch/*.py"):
        for f in sorted(pkg_dir.glob(pattern)):
            if f.is_file():
                h.update(f.read_bytes())
    return h.hexdigest()[:16]


def run_build(project_root: str | os.PathLike, symlink_install: bool = False) -> int:
    project_root = Path(project_root)
    manifest_path = project_root / "motus.json"
    if not manifest_path.is_file():
        raise BuildError(f"'{project_root}' doesn't look like a Motus project (no motus.json).")
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    pkg_name = manifest["package_name"]
    robot_name = manifest["project_name"]
    pkg_dir = project_root / "src" / pkg_name

    print("Validating project before build...")
    try:
        checks = run_doctor(project_root)
    except DoctorFatalError as e:
        print(f"error: {e}")
        return 1
    ok = print_report(robot_name, checks)
    print()
    if not ok:
        print("Build refused -- fix the errors above (or re-run `motus robot add` / "
              "`motus doctor --verbose`) before building.")
        return 1

    colcon = shutil.which("colcon")
    if colcon is None:
        print(
            "error: `colcon` not found on PATH. This project passed all doctor checks "
            "and is ready to build, but you'll need a sourced ROS2 environment with "
            "colcon installed (e.g. `source /opt/ros/<distro>/setup.bash`) to actually "
            "build it. Run `colcon build --packages-select "
            f"{pkg_name}` yourself from {project_root} once that's set up."
        )
        return 1

    cmd = [colcon, "build", "--packages-select", pkg_name]
    if symlink_install:
        cmd.append("--symlink-install")

    print(f"Running: {' '.join(cmd)}  (cwd={project_root})")
    result = subprocess.run(cmd, cwd=str(project_root))

    if result.returncode == 0:
        manifest["last_build_fingerprint"] = _fingerprint(pkg_dir)
        manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")
        print()
        print(f"Build succeeded. Next: `source install/setup.bash` (from {project_root}), "
              f"then `motus launch`.")
    else:
        print()
        print(f"colcon build failed (exit {result.returncode}) -- see output above.")

    return result.returncode