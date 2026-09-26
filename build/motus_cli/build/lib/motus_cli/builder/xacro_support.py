"""
xacro_support.py

urdf_parser.py deliberately only understands plain URDF-shaped XML (see
its docstring). A raw, unexpanded .xacro file is NOT that -- macros,
xacro:if branches, and ${...} property expressions mean the real
<link>/<joint> elements are often nested inside xacro: namespaced
wrapper tags rather than being direct children of <robot>. ElementTree
parses that structurally without error, so `root.findall("link")` would
just silently return too few/zero links instead of failing loudly --
worse than a crash, since it can masquerade as "no robot added yet"
(dof=0) rather than clearly signaling "this xacro needs expanding".

parse_description_file() is the one place that decision gets made:
plain .urdf -> straight into urdf_parser; .xacro -> run through the
`xacro` package first, parse the expanded result. Used by both
robot_add.py (parsing on import) and doctor.py (re-parsing whatever's
currently on disk, which -- by design, see robot_add.py -- is still the
ORIGINAL unexpanded xacro source, not the expanded form used only for
analysis).

LIMITATION: only resolves xacro files that fully expand with their OWN
default parameter values. An external xacro requiring caller-supplied
mappings (the way Motus's own robokpy_robot.urdf.xacro requires
arm_type/gripper_type) will fail here with whatever error the `xacro`
package raises -- there's no way for `motus robot add` to know what
mappings an arbitrary third-party xacro file expects. Supporting
explicit `--xacro-arg name:=value` passthrough is a reasonable follow-on,
not attempted yet.
"""

from __future__ import annotations

import re

from .urdf_parser import parse_urdf_string, RobotDescription, UrdfParseError

try:
    import xacro as _xacro
except ImportError:
    _xacro = None

# Matches an unresolved xacro property (${name}) or arg ($(arg name)) left
# in the expanded output. Found in practice: the same robokpy_robot.urdf.xacro
# that expands cleanly with `xacro` installed via pip left a literal
# "${mesh_pkg}" in every mesh filename when run through ROS2 Jazzy's
# apt-packaged `xacro` -- same file, different xacro package version,
# different property-resolution behavior. Rather than chase which xacro
# versions do this, treat ANY leftover substitution as a hard failure:
# a URDF with "${mesh_pkg}" in a mesh path parses and analyzes as if
# nothing were wrong (link/joint names are unaffected), and only fails
# much later and confusingly, in mesh resolution.
_UNRESOLVED_SUBSTITUTION_RE = re.compile(r"\$\{[^}]+\}|\$\([^)]+\)")


def _check_fully_resolved(xml_text: str, path: str) -> None:
    found = sorted(set(_UNRESOLVED_SUBSTITUTION_RE.findall(xml_text)))
    if found:
        looks_like_macro_params = any(
            name.strip("${}") in ("prefix", "parent", "parent_link", "child")
            for name in found
        )
        hint = (
            " This looks like a xacro MACRO FRAGMENT (prefix/parent are typically "
            "macro parameters, not standalone properties) rather than a complete, "
            "invokable robot description -- point `motus robot add` at whatever file "
            "actually CALLS this macro with real values instead of at the macro "
            "definition itself."
            if looks_like_macro_params else ""
        )
        raise UrdfParseError(
            f"'{path}' contains {len(found)} unresolved substitution(s) that were "
            f"never replaced with real values: {', '.join(found[:5])}"
            f"{' ...' if len(found) > 5 else ''}.{hint} If this is a genuine top-level "
            f"description, expand/inspect it yourself first (e.g. `xacro {path} "
            f"name:=value ...` if it's xacro, checking the output has no literal "
            f"'${{' or '$(' left) and pass the resolved .urdf to `motus robot add` "
            f"instead."
        )


def parse_description_file(path: str) -> RobotDescription:
    if path.endswith(".xacro"):
        if _xacro is None:
            raise UrdfParseError(
                f"'{path}' is a xacro file but the `xacro` Python package isn't "
                f"importable in this environment -- install it (it ships with a "
                f"sourced ROS2 install, or `pip install xacro` standalone) to import "
                f"xacro-based descriptions."
            )
        try:
            processed_xml = _xacro.process_file(path, mappings={}).toxml()
        except Exception as e:  # xacro raises a mix of its own and expat/lxml errors
            raise UrdfParseError(
                f"failed to expand xacro file '{path}': {e}. If this xacro requires "
                f"specific arguments (arm_type, gripper_type, etc -- the way Motus's "
                f"own robot macros do), `motus robot add` can't supply those "
                f"automatically; expand it yourself with `xacro {path} arg:=value ...` "
                f"and pass the resulting .urdf instead."
            ) from e
    else:
        with open(path, "r", encoding="utf-8") as f:
            processed_xml = f.read()

    # Applies regardless of extension: a file literally named .urdf can
    # still contain unresolved ${...}/$(...) text -- seen in practice when
    # someone points the importer at a xacro MACRO FRAGMENT (a reusable
    # definition with prefix/parent/etc as macro parameters, only ever
    # filled in by whatever file actually invokes the macro) that happens
    # to be named with a .urdf extension rather than .xacro. A plain
    # ElementTree read of that file "succeeds" and even produces
    # plausible-looking link/joint names (e.g. base_link=${parent}), which
    # is far more misleading than a load-time error would be.
    _check_fully_resolved(processed_xml, path)
    return parse_urdf_string(processed_xml)


def parse_description_file_with_includes(path: str) -> tuple[RobotDescription, list[str], str]:
    """Same as parse_description_file, but also returns:
      - the absolute path of every file pulled in via xacro:include
        (transitively across nested includes)
      - the fully xacro-EXPANDED XML text itself

    xacro resolves relative paths AND $(find pkg)/... substitution args
    internally while expanding a description -- that resolution is the
    only reliable way to know where these files actually live on disk
    for an arbitrary manufacturer's layout, so we harvest it from
    xacro's own `process_includes()` side effect (`xacro.all_includes`,
    the same list `xacro --deps` reads) rather than re-implementing
    xacro's include search.

    The expanded XML is returned too (not just discarded after parsing)
    because some structural questions -- "does this robot already
    declare <ros2_control>?" being the concrete one that mattered in
    practice -- can only be answered correctly against the fully
    assembled robot. A raw-text scan of just the entry file would miss
    a <ros2_control> block that lives inside a macro DEFINITION in a
    separately xacro:include'd file (a real, common split), and would
    also false-positive on a macro that's included but never actually
    invoked. See ros2_control_injector.py.

    Plain .urdf has no includes by definition -- returns an empty list
    and the raw text unchanged for those."""
    if not path.endswith(".xacro"):
        desc = parse_description_file(path)
        with open(path, "r", encoding="utf-8") as f:
            return desc, [], f.read()
    if _xacro is None:
        raise UrdfParseError(
            f"'{path}' is a xacro file but the `xacro` Python package isn't "
            f"importable in this environment -- install it (it ships with a "
            f"sourced ROS2 install, or `pip install xacro` standalone) to import "
            f"xacro-based descriptions."
        )
    if hasattr(_xacro, "all_includes"):
        _xacro.all_includes.clear()  # module-global; don't inherit a prior call's list
    try:
        processed_xml = _xacro.process_file(path, mappings={}).toxml()
    except Exception as e:
        raise UrdfParseError(
            f"failed to expand xacro file '{path}': {e}. If this xacro requires "
            f"specific arguments (arm_type, gripper_type, etc), expand it yourself "
            f"with `xacro {path} arg:=value ...` and pass the resulting .urdf instead."
        ) from e

    include_paths = list(dict.fromkeys(getattr(_xacro, "all_includes", [])))  # dedupe, keep order
    _check_fully_resolved(processed_xml, path)
    return parse_urdf_string(processed_xml), include_paths, processed_xml