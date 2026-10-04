"""
cli.py

`motus` command-line entry point.

    motus create project <name> [--from PATH] [--dest DIR] [--arg NAME=VALUE ...]
    motus robot add <path> [--arg NAME=VALUE ...]  # imports/replaces the robot description
    motus tool add [SOURCE] [--profile KEY] [--id ID] ...  # attach a gripper
    motus tool list | motus tool remove ID
    motus doctor [--verbose]          # validates the current project on disk
    motus build                       # doctor-gated colcon build
    motus launch [--sim/--real]       # ros2 launch wrapper

All five are wired to real logic (package_generator.py, robot_add.py,
doctor.py, build_cmd.py, launch_cmd.py). build/launch are NOT tested
against a real ROS2/colcon environment -- see the caveats in their
respective modules.
"""

from __future__ import annotations

import argparse
import json
import os
import sys

from .builder import package_generator
from .builder.robot_add import robot_add, RobotAddError
from .builder.doctor import run_doctor, print_report, DoctorFatalError
from .builder.build_cmd import run_build, BuildError
from .builder.launch_cmd import run_launch, LaunchError
from .builder.tool_add import tool_add, tool_remove, list_tools, ToolAddError


def _parse_xacro_args(raw: list[str]) -> dict[str, str]:
    """Turns repeated `--arg name=value` CLI values into a mappings dict
    for xacro. Fails loud on a malformed entry (no '=', or an empty
    name) rather than silently dropping it -- a typo'd arg here means
    xacro falls back to whatever default it has (or errors on a
    required one with no default), and either way the actual cause
    would otherwise be invisible from `motus robot add`'s output."""
    result: dict[str, str] = {}
    for entry in raw:
        if "=" not in entry:
            raise SystemExit(
                f"error: --arg '{entry}' is not in NAME=VALUE form "
                f"(e.g. --arg ur_type=ur5e)"
            )
        name, _, value = entry.partition("=")
        name = name.strip()
        if not name:
            raise SystemExit(f"error: --arg '{entry}' has an empty NAME")
        result[name] = value
    return result


def _cmd_create_project(args: argparse.Namespace) -> int:
    try:
        paths = package_generator.create_project(
            robot_name=args.name, dest=os.path.abspath(args.dest), from_path=args.from_path,
        )
    except FileExistsError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1

    print(f"Created project '{paths.robot_name}' at {paths.workspace_root}")
    print(f"  package: {paths.pkg_name}  (src/{paths.pkg_name})")

    if not args.from_path:
        print(
            "  Next: `motus robot add <path-to-robot-description>` to import a "
            "real robot, or hand-edit urdf/config yourself."
        )
        return 0

    try:
        report = robot_add(
            paths.workspace_root, args.from_path,
            xacro_args=_parse_xacro_args(args.xacro_args),
        )
    except RobotAddError as e:
        print(f"  robot import failed: {e}", file=sys.stderr)
        print("  Project was still created -- fix the source and re-run `motus robot add`.")
        return 1
    report.print_summary()
    return 0


def _cmd_robot_add(args: argparse.Namespace) -> int:
    # motus commands operate on the project in the current directory --
    # same assumption arm.launch.py-generated projects make (`cd my_robot
    # && motus ...`), consistent with the workflow in the original design.
    try:
        report = robot_add(
            os.getcwd(), args.path, xacro_args=_parse_xacro_args(args.xacro_args),
        )
    except RobotAddError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    report.print_summary()
    return 0 if report.ok else 1


def _cmd_tool_add(args: argparse.Namespace) -> int:
    try:
        report = tool_add(
            os.getcwd(), source_path=args.source, tool_id=args.tool_id, kind=args.kind,
            profile=args.profile, macro=args.macro, macro_args=_parse_xacro_args(args.macro_args),
            mount_link=args.mount, tcp_link=args.tcp, primary_joint=args.primary_joint,
            open_position=args.open_position, closed_position=args.closed_position,
            max_effort=args.max_effort, replace=args.replace,
            tcp_offset=args.tcp_offset,
            mount_rpy=args.mount_rpy, align_approach=args.align_approach,
        )
    except (ToolAddError, ValueError) as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    report.print_summary()
    return 0


def _cmd_tool_list(args: argparse.Namespace) -> int:
    try:
        tools = list_tools(os.getcwd())
    except OSError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    if not tools:
        print("no tools in this project (add one with `motus tool add`).")
    for d in tools:
        print(f"{d['id']}: {d['kind']} on {d['mount_link']}, driver={d['primary_joint']}, "
              f"tcp={d['tcp_link']}")
    return 0


def _cmd_tool_remove(args: argparse.Namespace) -> int:
    try:
        tool_remove(os.getcwd(), args.tool_id)
    except ToolAddError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    print(f"removed tool '{args.tool_id}'. Run `motus doctor`.")
    return 0


def _cmd_doctor(args: argparse.Namespace) -> int:
    project_root = os.getcwd()
    try:
        checks = run_doctor(project_root)
    except DoctorFatalError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    robot_name = json.loads(
        (open(os.path.join(project_root, "motus.json")).read())
    )["project_name"]
    ok = print_report(robot_name, checks)
    return 0 if ok else 1


def _cmd_build(args: argparse.Namespace) -> int:
    try:
        return run_build(os.getcwd())
    except BuildError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1


def _cmd_launch(args: argparse.Namespace) -> int:
    try:
        return run_launch(os.getcwd(), sim=args.sim)
    except LaunchError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(prog="motus")
    sub = parser.add_subparsers(dest="command", required=True)

    create = sub.add_parser("create", help="create a new Motus project")
    create_sub = create.add_subparsers(dest="create_command", required=True)
    project = create_sub.add_parser("project", help="scaffold a new robot project")
    project.add_argument("name", help="project/robot name, e.g. my_robot")
    project.add_argument(
        "--from", dest="from_path", default=None,
        help="path to an existing robot description to import (URDF/xacro dir or file)")
    project.add_argument(
        "--dest", default=".", help="directory to create the project workspace in")
    project.add_argument(
        "--arg", dest="xacro_args", action="append", default=[], metavar="NAME=VALUE",
        help="xacro argument to pass through when expanding --from's description "
             "(repeatable, e.g. --arg ur_type=ur5e); ignored without --from")
    project.set_defaults(func=_cmd_create_project)

    robot = sub.add_parser("robot", help="manage a robot description within a project")
    robot_sub = robot.add_subparsers(dest="robot_command", required=True)
    robot_add_parser = robot_sub.add_parser("add", help="import/replace this project's robot description")
    robot_add_parser.add_argument("path", help="path to a robot description (URDF/xacro dir or file)")
    robot_add_parser.add_argument(
        "--arg", dest="xacro_args", action="append", default=[], metavar="NAME=VALUE",
        help="xacro argument to pass through when expanding the description "
             "(repeatable, e.g. --arg ur_type=ur5e)")
    robot_add_parser.set_defaults(func=_cmd_robot_add)

    tool = sub.add_parser("tool", help="manage end-effector tools in this project")
    tool_sub = tool.add_subparsers(dest="tool_command", required=True)
    ta = tool_sub.add_parser("add", help="attach a gripper from a xacro macro description")
    ta.add_argument("source", nargs="?", default=None,
                    help="description file or package directory containing the tool's xacro macro "
                         "(optional with --profile when the parent workspace has it)")
    ta.add_argument("--profile", default=None, help="known tool profile, e.g. robotiq_2f_85")
    ta.add_argument("--id", dest="tool_id", default="gripper_1", help="tool id used in recipes (default gripper_1)")
    ta.add_argument("--kind", default="parallel_gripper")
    ta.add_argument("--macro", default=None, help="xacro macro name (auto-detected if unambiguous)")
    ta.add_argument("--mount", default=None, help="link to mount on (default: the arm's tip link)")
    ta.add_argument("--tcp", default=None, help="TCP link (default: auto-detected)")
    ta.add_argument("--tcp-offset", dest="tcp_offset", type=float, nargs=3, default=None,
                    metavar=("X", "Y", "Z"),
                    help="grasp point in the mount/flange frame (m, +Z out of the flange); creates "
                         "a TCP frame when the description has none")
    ta.add_argument("--mount-rpy", dest="mount_rpy", type=float, nargs=3, default=None,
                    metavar=("R", "P", "Y"), help="rotate the tool on the mount (radians)")
    ta.add_argument("--align-approach", dest="align_approach", action="store_true",
                    help="auto-rotate the tool so its fingertip direction points out of the flange (+Z)")
    ta.add_argument("--primary-joint", default=None, help="driver joint (default: the joint others mimic)")
    ta.add_argument("--open", dest="open_position", type=float, default=None)
    ta.add_argument("--closed", dest="closed_position", type=float, default=None)
    ta.add_argument("--max-effort", dest="max_effort", type=float, default=None)
    ta.add_argument("--arg", dest="macro_args", action="append", default=[], metavar="NAME=VALUE",
                    help="macro parameter (repeatable)")
    ta.add_argument("--replace", action="store_true", help="redo an existing tool of the same id")
    ta.set_defaults(func=_cmd_tool_add)
    tl = tool_sub.add_parser("list", help="list this project's tools")
    tl.set_defaults(func=_cmd_tool_list)
    tr = tool_sub.add_parser("remove", help="remove a tool and its managed config")
    tr.add_argument("tool_id")
    tr.set_defaults(func=_cmd_tool_remove)

    doctor = sub.add_parser("doctor", help="validate the current project")
    doctor.add_argument("--verbose", action="store_true")
    doctor.set_defaults(func=_cmd_doctor)

    build = sub.add_parser("build", help="validate then colcon build this project's package")
    build.set_defaults(func=_cmd_build)

    launch = sub.add_parser("launch", help="launch this project")
    launch.add_argument("--sim", action="store_true", default=True)
    launch.add_argument("--real", dest="sim", action="store_false")
    launch.set_defaults(func=_cmd_launch)

    return parser


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    raise SystemExit(main())