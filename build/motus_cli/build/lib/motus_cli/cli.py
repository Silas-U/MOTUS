"""
cli.py

`motus` command-line entry point.

    motus create project <name> [--from PATH] [--dest DIR]
    motus robot add <path>            # imports/replaces the project's robot description
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


def _cmd_create_project(args: argparse.Namespace) -> int:
    try:
        paths = package_generator.create_project(
            robot_name=args.name, dest=args.dest, from_path=args.from_path,
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
        report = robot_add(paths.workspace_root, args.from_path)
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
        report = robot_add(os.getcwd(), args.path)
    except RobotAddError as e:
        print(f"error: {e}", file=sys.stderr)
        return 1
    report.print_summary()
    return 0 if report.ok else 1


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
    project.set_defaults(func=_cmd_create_project)

    robot = sub.add_parser("robot", help="manage a robot description within a project")
    robot_sub = robot.add_subparsers(dest="robot_command", required=True)
    robot_add_parser = robot_sub.add_parser("add", help="import/replace this project's robot description")
    robot_add_parser.add_argument("path", help="path to a robot description (URDF/xacro dir or file)")
    robot_add_parser.set_defaults(func=_cmd_robot_add)

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
