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


def rewrite_mesh_uris(urdf_text: str, resolution: ResourceResolutionResult, new_pkg_name: str) -> str:
    """Replace every resolved mesh URI in the URDF/xacro text with
    package://<new_pkg_name>/meshes/<basename>. Unresolved URIs are left
    untouched -- they're already reported in `resolution.unresolved` for
    `motus doctor` to surface as a hard error; silently rewriting them to
    a path that doesn't exist would hide the problem instead."""
    out = urdf_text
    for r in resolution.resolved:
        new_uri = f"package://{new_pkg_name}/meshes/{r.dest_relative_path}"
        out = out.replace(r.original_uri, new_uri)
    return out
