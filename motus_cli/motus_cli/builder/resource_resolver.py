"""
resource_resolver.py

Locates the actual mesh (and other resource) files a robot description's
`package://...` / relative / bare-filename URIs refer to, copies them
into the generated package's meshes/ directory (a SIBLING of urdf/, see
the note in package_generator.py), and returns a rewritten copy of the
URDF/xacro text pointing at the new package.

Real-world robot descriptions are not always installed ROS packages --
`motus robot add ~/Downloads/mycobot_ros` is very likely just a raw git
clone, so `package://mycobot_description/...` can't be resolved via
ament's package index. Tested against a real Elephant Robotics URDF
(mycobot_280pi_with_camera_flange.urdf, fetched from
github.com/elephantrobotics/mycobot_ros): its mesh URIs are
`package://mycobot_description/urdf/mycobot_280_pi/G_base.dae` etc, and
in that repo's actual layout `urdf/mycobot_280_pi/G_base.dae` (i.e. the
URI's path with the package name stripped) sits directly under the
package root, which is what `source_root` should point at.
"""

from __future__ import annotations

from dataclasses import dataclass, field
import os
import re
import shutil


_PACKAGE_URI_RE = re.compile(r"^package://([^/]+)/(.+)$")
_MESH_FILENAME_RE = re.compile(r'(<mesh\s+filename\s*=\s*")([^"]+)(")')


@dataclass
class ResolvedResource:
    original_uri: str
    dest_relative_path: str   # path under the generated package's meshes/
    source_path: str          # where it was actually found on disk


@dataclass
class ResourceResolutionResult:
    resolved: list[ResolvedResource] = field(default_factory=list)
    unresolved: list[str] = field(default_factory=list)   # original URIs not found anywhere
    collisions: list[str] = field(default_factory=list)   # basename collisions, informational


def _candidate_paths(uri: str, urdf_dir: str, source_root: str | None) -> list[str]:
    m = _PACKAGE_URI_RE.match(uri)
    if m:
        _pkg_name, rel = m.group(1), m.group(2)
    elif uri.startswith("file://"):
        return [uri[len("file://"):]]
    else:
        rel = uri  # bare relative path

    candidates = []
    if source_root:
        candidates.append(os.path.join(source_root, rel))
    candidates.append(os.path.join(urdf_dir, os.path.basename(rel)))
    candidates.append(os.path.join(urdf_dir, rel))
    if source_root:
        # last resort: recursive basename search under source_root, for
        # repo layouts where the package-relative path in the URI doesn't
        # match the actual directory structure on disk (common after
        # someone reorganizes a vendor repo, or symlinks meshes/ in)
        target_basename = os.path.basename(rel)
        for root, _dirs, files in os.walk(source_root):
            if target_basename in files:
                candidates.append(os.path.join(root, target_basename))
    return candidates


def resolve_resources(
    mesh_uris: list[str], urdf_file_path: str, dest_meshes_dir: str,
    source_root: str | None = None,
) -> ResourceResolutionResult:
    """
    mesh_uris: every distinct <mesh filename="..."> value pulled from the
      parsed description (urdf_parser.py's Link.mesh_uris, deduplicated
      by caller if desired -- duplicates are handled fine here too).
    urdf_file_path: path to the URDF/xacro file being imported (used to
      resolve meshes referenced relative to it).
    dest_meshes_dir: the generated package's meshes/ directory.
    source_root: the root of whatever the user pointed `motus robot add`
      at (a directory), if it was a directory. None if a single file was
      given directly.
    """
    os.makedirs(dest_meshes_dir, exist_ok=True)
    urdf_dir = os.path.dirname(os.path.abspath(urdf_file_path))
    result = ResourceResolutionResult()
    seen_basenames: dict[str, str] = {}  # basename -> first source_path that claimed it

    for uri in mesh_uris:
        found_path = None
        for candidate in _candidate_paths(uri, urdf_dir, source_root):
            if os.path.isfile(candidate):
                found_path = candidate
                break

        if found_path is None:
            result.unresolved.append(uri)
            continue

        basename = os.path.basename(found_path)
        if basename in seen_basenames and seen_basenames[basename] != found_path:
            result.collisions.append(
                f"'{basename}' resolved from two different source paths "
                f"({seen_basenames[basename]} and {found_path}) -- second one skipped, "
                f"first copy wins. Rename one of the source files if they're actually "
                f"different meshes."
            )
            dest_relative = basename
        else:
            seen_basenames[basename] = found_path
            dest_relative = basename
            shutil.copy2(found_path, os.path.join(dest_meshes_dir, dest_relative))

        result.resolved.append(ResolvedResource(
            original_uri=uri, dest_relative_path=dest_relative, source_path=found_path,
        ))

    return result


_YAML_MESH_BLOCK_RE = re.compile(
    r"^(\s*)package:\s*\S+\s*\n(\s*)path:\s*(\S+)\s*$", re.MULTILINE
)


def patch_yaml_mesh_package_refs(
    xacro_args: dict[str, str] | None, dest_config_dir: str, new_pkg_name: str,
) -> dict[str, str]:
    """Some vendor descriptions embed the source package's name as
    literal DATA inside a YAML file passed in via a xacro arg, not as
    text anywhere in the .xacro/.urdf source -- confirmed against the
    real Universal_Robots_ROS2_Description repo: its visual_parameters.yaml
    (passed as the `visual_params` xacro arg) has a
        mesh:
          package: ur_description
          path: meshes/ur5e/visual/base.dae
    block under every mesh entry, and urdf/inc/ur_common.xacro's
    get_mesh_path macro assembles `package://<package>/<path>` from
    THOSE TWO YAML values at expansion time. Neither "ur_description"
    nor the meshes/ur5e/visual/... subdirectory structure appears in any
    .xacro file at all in that case, so rewrite_mesh_uris() -- which
    only ever rewrites URDF/xacro TEXT -- structurally cannot fix
    either one no matter how its matching logic is tuned; both live one
    level further out, in caller-supplied config data.

    resolve_resources() (see above) copies every resolved mesh FLAT into
    dest_meshes_dir -- just the basename, no subdirectories preserved --
    so a rewrite that only fixed `package:` and left `path:` pointing at
    the vendor's own nested layout (meshes/ur5e/visual/base.dae) would
    still 404 against the flat copy (meshes/base.dae) doctor/launch
    actually finds on disk. Both keys are rewritten together as a single
    package+path BLOCK (matched by requiring `path:` to be the very next
    line after `package:`, which holds for every entry in the real UR
    file -- checked: 14 package: keys, 14 path: keys, always paired) so
    the two edits can never drift out of sync with each other.

    For every xacro_args value that is an existing .yaml/.yml file
    containing at least one such package:+path: block (matched
    generically -- this isn't UR-specific, any vendor YAML using the
    same convention under a mesh block is caught the same way), rewrite
    every block to `package: new_pkg_name` / `path: meshes/<basename>`,
    write the patched copy into dest_config_dir, and return xacro_args
    with that arg's value repointed at the patched copy. A value that
    isn't an existing yaml/yml file, or that has no such block, is
    passed through unchanged. Called BEFORE the description is ever
    parsed -- both the initial import and every later `motus doctor`
    re-parse (via the persisted, already-patched xacro_args in
    motus.json) then see the new package name AND the flat mesh layout
    consistently, matching exactly what resolve_resources() actually
    put on disk."""
    if not xacro_args:
        return {}
    patched = dict(xacro_args)
    for key, value in xacro_args.items():
        if not (value.endswith(".yaml") or value.endswith(".yml")):
            continue
        if not os.path.isfile(value):
            continue
        with open(value, "r", encoding="utf-8") as f:
            text = f.read()
        if not _YAML_MESH_BLOCK_RE.search(text):
            continue

        def _sub(m: "re.Match[str]") -> str:
            pkg_indent, path_indent, orig_path = m.group(1), m.group(2), m.group(3)
            new_path = f"meshes/{os.path.basename(orig_path)}"
            return f"{pkg_indent}package: {new_pkg_name}\n{path_indent}path: {new_path}"

        patched_text = _YAML_MESH_BLOCK_RE.sub(_sub, text)
        os.makedirs(dest_config_dir, exist_ok=True)
        dest_path = os.path.join(dest_config_dir, os.path.basename(value))
        with open(dest_path, "w", encoding="utf-8") as f:
            f.write(patched_text)
        patched[key] = dest_path
    return patched


def rewrite_mesh_uris(urdf_text: str, resolution: ResourceResolutionResult, new_pkg_name: str) -> str:
    """Replace every resolved mesh reference in the URDF/xacro TEXT with
    package://<new_pkg_name>/meshes/<basename>.

    Matches by BASENAME via regex on the <mesh filename="..."> attribute,
    not by literal-string-replacing resolution's `original_uri`. That
    distinction matters: `original_uri` came from the fully xacro-EXPANDED
    description (what analysis/resolution saw), but this function is
    called on RAW, unexpanded source text (the entry file, and -- for
    manufacturer descriptions that split mesh-owning macros into their
    own xacro:include'd files -- every one of those copied files too).
    When a manufacturer parameterizes the package name with a xacro
    property/arg (e.g. `package://${mesh_pkg}/meshes/x.stl`, a real
    pattern seen in practice, not hypothetical), the raw text literally
    contains "${mesh_pkg}" while `original_uri` holds the substituted
    value ("robokpy_controller") -- a literal-string .replace() between
    those never matches, silently leaving the old reference in place.
    The mesh FILENAME itself is essentially always a literal (paths need
    to be resolvable on disk), even when the package/prefix around it
    isn't, so basename matching is robust to this in general, not just
    for this one property name.

    Unresolved URIs are left untouched -- they're already reported in
    `resolution.unresolved` for `motus doctor` to surface as a hard
    error; silently rewriting them to a path that doesn't exist would
    hide the problem instead."""
    dest_by_basename = {
        os.path.basename(r.source_path): r.dest_relative_path
        for r in resolution.resolved
    }

    def _sub(m: "re.Match[str]") -> str:
        basename = os.path.basename(m.group(2))
        if basename not in dest_by_basename:
            return m.group(0)
        new_uri = f"package://{new_pkg_name}/meshes/{dest_by_basename[basename]}"
        return f"{m.group(1)}{new_uri}{m.group(3)}"

    return _MESH_FILENAME_RE.sub(_sub, urdf_text)