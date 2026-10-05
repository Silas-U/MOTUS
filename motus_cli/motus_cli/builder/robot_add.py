"""
robot_add.py

Orchestrates the pipeline stages built so far into the thing `motus robot
add <path> [--arg name=value ...]` (and `motus create project <name>
--from <path>`) actually runs: locate the source URDF/xacro within
whatever path was given -> parse (xacro args, if any, forwarded straight
through to xacro's own expansion -- see xacro_support.py) -> analyze the
kinematic chain -> resolve/copy mesh resources -> generate
robot.yaml/controllers.yaml -> write the imported URDF and regenerate
the launch wrapper -> update motus.json.

Does not raise on recoverable problems (missing limits, dead-end frames,
unresolved meshes) -- it collects everything into an ImportReport and
lets the caller (CLI) decide how to present it. `motus doctor` will
reuse the same "resolve + analyze, don't write" half of this for
non-destructive validation rather than duplicating the logic.
"""

from __future__ import annotations

from dataclasses import dataclass, field
import json
import os
from pathlib import Path

from . import templates
from .urdf_parser import RobotDescription, UrdfParseError
from .xacro_support import parse_description_file_with_includes
from .kinematic_analyzer import analyze, KinematicAnalysis
from .ros2_control_injector import inject_ros2_control
from .resource_resolver import (
    rewrite_mesh_uris, ResourceResolutionResult, patch_yaml_mesh_package_refs,
)
from . import dependency_resolver as _deps
from .config_generator import generate_configs, ConfigGenerationResult
from .safe_pose import choose_home_pose, choose_ready_pose

_URDF_EXTENSIONS = (".urdf", ".xacro", ".urdf.xacro")


@dataclass
class ImportReport:
    urdf_source: str
    pkg_dir: Path
    analysis: KinematicAnalysis
    resolution: ResourceResolutionResult
    config: ConfigGenerationResult
    tool_notes: list = field(default_factory=list)

    @property
    def ok(self) -> bool:
        """A reasonable pass/fail summary for a plain `robot add` run --
        NOT the same set of checks `motus doctor` will run later (doctor
        also re-checks things that can go stale after a hand edit, not
        just what happened during this import)."""
        return not self.resolution.unresolved and self.analysis.dof > 0

    def print_summary(self) -> None:
        print(f"Imported robot description from {self.urdf_source}")
        print(
            f"  base_link={self.analysis.base_link}  tip_link={self.analysis.tip_link}  "
            f"dof={self.analysis.dof}"
        )
        print(
            f"  meshes: {len(self.resolution.resolved)} resolved, "
            f"{len(self.resolution.unresolved)} unresolved"
        )
        for uri in self.resolution.unresolved:
            print(f"    ✗ could not locate: {uri}")
        for c in self.resolution.collisions:
            print(f"    ! {c}")
        if self.resolution.dependencies:
            print(f"  textures/materials copied: {len(self.resolution.dependencies)}")
        for d in self.resolution.missing_dependencies:
            print(f"    ! referenced file not found (material will render blank): {d}")
        all_warnings = (
            [w.message for w in self.analysis.warnings] + self.config.warnings
        )
        if all_warnings:
            print(f"  {len(all_warnings)} warning(s) -- run `motus doctor` for details:")
            for w in all_warnings[:5]:
                print(f"    - {w}")
            if len(all_warnings) > 5:
                print(f"    ... and {len(all_warnings) - 5} more")
        for n in self.tool_notes:
            print(f"  tool: {n}")
        if self.ok:
            print("  OK -- run `motus doctor` before `motus build` regardless.")
        else:
            print("  INCOMPLETE -- see above. `motus build` will refuse to run until fixed.")


class RobotAddError(ValueError):
    pass


def _find_source_urdf(path: str) -> tuple[str, str | None]:
    """Returns (urdf_file_path, source_root). source_root is the
    directory resource_resolver should search under for meshes -- the
    given directory if one was given, else the URDF file's own parent
    (single-file imports can still resolve meshes sitting next to the
    file, just not ones elsewhere in a larger repo)."""
    if os.path.isfile(path):
        if not path.endswith(_URDF_EXTENSIONS):
            raise RobotAddError(
                f"'{path}' is not a .urdf or .xacro file. Point `motus robot add` at "
                f"the description file itself or its containing directory."
            )
        return path, os.path.dirname(os.path.abspath(path))

    if not os.path.isdir(path):
        raise RobotAddError(f"'{path}' does not exist.")

    candidates = []
    for root, _dirs, files in os.walk(path):
        for fname in files:
            if fname.endswith(_URDF_EXTENSIONS):
                candidates.append(os.path.join(root, fname))
    if not candidates:
        raise RobotAddError(
            f"no .urdf or .xacro file found anywhere under '{path}'. Motus Builder needs "
            f"at least one to import a robot description."
        )
    if len(candidates) > 1:
        # Prefer a file whose name doesn't look like a fragment/macro
        # (macro files meant for xacro:include are a very common false
        # positive in vendor repos -- e.g. ros2_control_macros.xacro).
        non_macro = [c for c in candidates if "macro" not in os.path.basename(c).lower()]
        pool = non_macro or candidates
        chosen = sorted(pool, key=len)[0]  # shortest path = usually the top-level entry point
        print(
            f"note: {len(candidates)} URDF/xacro files found under '{path}'; "
            f"using '{chosen}'. Pass the exact file path to `motus robot add` if this "
            f"is the wrong one."
        )
        return chosen, path
    return candidates[0], path


def robot_add(
    project_root: str | os.PathLike, source_path: str,
    xacro_args: dict[str, str] | None = None,
) -> ImportReport:
    project_root = Path(project_root)
    manifest_path = project_root / "motus.json"
    if not manifest_path.is_file():
        raise RobotAddError(
            f"'{project_root}' doesn't look like a Motus project (no motus.json). "
            f"Run `motus create project <name>` first."
        )
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    pkg_name = manifest["package_name"]
    robot_name = manifest["project_name"]
    pkg_dir = project_root / "src" / pkg_name

    urdf_file, source_root = _find_source_urdf(source_path)

    # Patch any xacro-arg-supplied YAML config file that embeds the
    # source package's name as literal DATA (not xacro/URDF text -- see
    # patch_yaml_mesh_package_refs) BEFORE parsing, so both this import
    # and every later `motus doctor` re-parse consistently produce mesh
    # references to the new package rather than the original source's.
    mesh_hints: dict[str, str] = {}
    xacro_args = patch_yaml_mesh_package_refs(
        xacro_args, str(pkg_dir / "config"), pkg_name, mesh_hints)

    try:
        desc: RobotDescription
        desc, include_paths, expanded_xml = parse_description_file_with_includes(
            urdf_file, xacro_args=xacro_args,
        )
    except UrdfParseError as e:
        raise RobotAddError(f"could not parse '{urdf_file}': {e}") from e

    already_has_ros2_control = "<ros2_control" in expanded_xml

    analysis = analyze(desc)

    all_mesh_uris = sorted({uri for link in desc.links.values() for uri in link.mesh_uris})
    dest_urdf_dir = pkg_dir / "urdf"
    dest_meshes_dir = pkg_dir / "meshes"
    dep_resolution = _deps.resolve_all(
        urdf_file_path=urdf_file, mesh_uris=all_mesh_uris, include_paths=include_paths,
        dest_urdf_dir=str(dest_urdf_dir), dest_meshes_dir=str(dest_meshes_dir),
        source_root=source_root, mesh_hints=mesh_hints,
    )
    resolution: ResourceResolutionResult = dep_resolution.mesh_result

    # Any xacro:include a manufacturer's entry file pulls in (a macro
    # file, a shared materials/transmission.xacro -- whatever their split
    # convention is) is now copied alongside it in urdf/; retarget every
    # xacro:include AND every mesh URI in the entry file, and -- just as
    # important -- inside each copied dependency file too (a macro file
    # can define its own <mesh> references, e.g. a gripper macro's own
    # meshes; those need rewriting right where they live, not just in the
    # entry file, or the generated package still points at the source
    # workspace's package name for anything not directly in the entry
    # file), so the generated package has no dependency on the original
    # source tree at all.
    with open(urdf_file, "r", encoding="utf-8") as f:
        urdf_text = f.read()
    urdf_text = _deps.rewrite_include_uris(urdf_text, dep_resolution.copied_includes)
    urdf_text = rewrite_mesh_uris(urdf_text, resolution, pkg_name)
    for basename in dep_resolution.copied_includes:
        dep_path = dest_urdf_dir / basename
        with open(dep_path, "r", encoding="utf-8") as f:
            dep_text = f.read()
        dep_text = _deps.rewrite_include_uris(dep_text, dep_resolution.copied_includes)
        dep_text = rewrite_mesh_uris(dep_text, resolution, pkg_name)
        dep_path.write_text(dep_text, encoding="utf-8")

    rewritten_urdf = urdf_text
    # No inertial injection: inertials come from the manufacturer's
    # description only. Warn (never edit) if a link with geometry has none.
    for _name, _link in desc.links.items():
        if not _link.has_inertial and _link.mesh_uris:
            print(f"warning: link '{_name}' has geometry but no <inertial> in the source description.")
    # Always inject <ros2_control>/<gazebo><plugin> UNLESS the source
    # already declares its own (checked against the fully xacro-expanded
    # robot, not just the entry file's raw text -- see
    # already_has_ros2_control above and ros2_control_injector.py).
    # Injecting a second one used to make two hardware components fight
    # over the same joint names at runtime and take the whole
    # controller_manager down with it -- confirmed against a real launch.
    # When injected, written as .urdf.xacro regardless of the source's
    # original extension -- the injected $(arg controllers_yaml_path)/
    # $(arg namespace) need xacro's substitution mechanism at launch
    # time; a plain .urdf has no such mechanism, so those would just sit
    # there as permanently-unresolved dead text.
    rewritten_urdf = inject_ros2_control(
        rewritten_urdf, analysis, pkg_name,
        already_has_ros2_control=already_has_ros2_control,
    )

    urdf_filename = f"{robot_name}.urdf.xacro"
    (pkg_dir / "urdf").mkdir(parents=True, exist_ok=True)
    (pkg_dir / "urdf" / urdf_filename).write_text(rewritten_urdf, encoding="utf-8")
    # Clean up a differently-named urdf file left by a previous import or
    # by package_generator's placeholder, so the package doesn't
    # accumulate stale robot description files across re-imports.
    for existing in (pkg_dir / "urdf").glob(f"{robot_name}.urdf*"):
        if existing.name != urdf_filename:
            existing.unlink()

    # home_pose is both the IK seed and the pose Gazebo spawns the arm in (the
    # injected ros2_control block reads it back via the `home_pose` xacro arg).
    # All zeros is kept when it's clear of the ground; otherwise a floor-clear
    # pose is chosen so arms like the UR5 don't spawn with the wrist in the floor.
    home_pose, home_note = choose_home_pose(
        expanded_xml, analysis.base_link, analysis.tip_link,
        [j.name for j in analysis.chain_joints],
    )
    # ready_pose: bent, non-singular IK seed / safe pre-move target (home_pose is the
    # stretched, singular spawn pose).
    ready_pose, ready_note = choose_ready_pose(
        expanded_xml, analysis.base_link, analysis.tip_link,
        [j.name for j in analysis.chain_joints], home_pose,
    )
    cfg = generate_configs(analysis, robot_name, home_pose=home_pose, ready_pose=ready_pose)
    if home_note:
        cfg.warnings.append(home_note)
    if ready_note:
        cfg.warnings.append(ready_note)
    (pkg_dir / "config").mkdir(parents=True, exist_ok=True)
    (pkg_dir / "config" / "robot.yaml").write_text(cfg.robot_yaml_text, encoding="utf-8")
    (pkg_dir / "config" / "controllers.yaml").write_text(cfg.controllers_yaml_text, encoding="utf-8")
    (pkg_dir / "config" / "objects.yaml").write_text(cfg.objects_yaml_text, encoding="utf-8")

    launch_filename = f"{robot_name}.launch.py"
    (pkg_dir / "launch").mkdir(parents=True, exist_ok=True)
    (pkg_dir / "launch" / launch_filename).write_text(
        templates.LAUNCH_WRAPPER.format(
            launch_name=launch_filename, robot_name=robot_name, pkg_name=pkg_name,
            urdf_filename=urdf_filename,
            external_xacro_args_json=repr(json.dumps(xacro_args)),
        ),
        encoding="utf-8",
    )

    manifest["source_description_path"] = os.path.abspath(source_path)
    manifest["xacro_args"] = xacro_args or {}
    manifest["last_build_fingerprint"] = None  # stale until the next `motus build`
    manifest_path.write_text(json.dumps(manifest, indent=2), encoding="utf-8")

    # A re-import regenerates the entry xacro and configs, which drops any
    # managed tool blocks; put recorded tools back (see tool_add.py).
    tool_notes: list = []
    if manifest.get("tools"):
        from .tool_add import reapply_tools
        tool_notes = reapply_tools(project_root)

    return ImportReport(
        urdf_source=urdf_file, pkg_dir=pkg_dir, analysis=analysis,
        resolution=resolution, config=cfg, tool_notes=tool_notes,
    )