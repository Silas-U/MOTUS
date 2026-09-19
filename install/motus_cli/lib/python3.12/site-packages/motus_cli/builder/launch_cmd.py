"""
launch_cmd.py

`motus launch [--sim/--real]` = `ros2 launch <pkg> <robot>.launch.py
use_sim:=<true|false>`, run through a login-less bash so the workspace's
own install/setup.bash can be sourced on top of the environment.

Sources TWO overlays, in order, before running: the parent Motus
workspace (recorded in motus.json as `parent_workspace_root` -- the
directory `motus create project` was run from, which is where
robokpy_controller actually lives), then this project's own
install/setup.bash on top. Confirmed the hard way that skipping the
parent workspace produces a clean but wrong failure ("package
'robokpy_controller' not found") -- a generated project is a SEPARATE
colcon workspace from the Motus repo itself, and ROS2 overlays don't
chain automatically; each has to be sourced explicitly, parent first.

Does not attempt to source the base ROS distro itself (e.g.
/opt/ros/jazzy/setup.bash) -- assumed already active in the caller's
shell, same as build_cmd.py assumes for `colcon build`.

NOT tested against a real `ros2 launch` invocation for the same reason
as build_cmd.py -- no ROS installed in this sandbox. What IS exercised
below: refusing to launch an unbuilt project, and constructing the
correct command line (now including the parent-workspace overlay).
"""

from __future__ import annotations

import json
import os
import shutil
import subprocess
from pathlib import Path


class LaunchError(ValueError):
    pass


def run_launch(project_root: str | os.PathLike, sim: bool = True,
                extra_launch_args: list[str] | None = None) -> int:
    project_root = Path(project_root)
    manifest_path = project_root / "motus.json"
    if not manifest_path.is_file():
        raise LaunchError(f"'{project_root}' doesn't look like a Motus project (no motus.json).")
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    pkg_name = manifest["package_name"]
    robot_name = manifest["project_name"]

    install_setup = project_root / "install" / "setup.bash"
    if not install_setup.is_file():
        raise LaunchError(
            f"'{install_setup}' not found -- this project hasn't been built yet. "
            f"Run `motus build` first."
        )

    bash = shutil.which("bash")
    if bash is None:
        raise LaunchError("`bash` not found on PATH -- needed to source the workspace overlay.")

    source_lines = []
    parent_root = manifest.get("parent_workspace_root")
    if parent_root:
        parent_setup = Path(parent_root) / "install" / "setup.bash"
        if parent_setup.is_file():
            source_lines.append(f"source {parent_setup}")
        else:
            print(
                f"warning: recorded parent workspace '{parent_root}' has no "
                f"install/setup.bash (never built?) -- skipping it. If `robokpy_controller` "
                f"isn't found below, build/source that workspace manually first."
            )
    else:
        print(
            "warning: this project's motus.json has no recorded parent_workspace_root "
            "(created before this was tracked) -- only this project's own install/setup.bash "
            "will be sourced. If `robokpy_controller` isn't found below, source your Motus "
            "workspace's install/setup.bash manually before `motus launch`."
        )
    source_lines.append(f"source {install_setup}")

    launch_file = f"{robot_name}.launch.py"
    use_sim = "true" if sim else "false"
    ros2_args = ["ros2", "launch", pkg_name, launch_file, f"use_sim:={use_sim}"]
    ros2_args += extra_launch_args or []

    shell_cmd = " && ".join(source_lines) + " && exec " + " ".join(ros2_args)
    print(f"Running: {shell_cmd}")
    result = subprocess.run([bash, "-c", shell_cmd], cwd=str(project_root))
    return result.returncode