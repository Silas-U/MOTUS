"""
dependency_resolver.py

Generalizes resource_resolver.py's mesh-only resolution into a single
resolver that understands every way a robot description can reference
another local file:

    <mesh filename="package://pkg/meshes/x.dae"/>
    <mesh filename="../meshes/x.stl"/>
    <xacro:include filename="ur5e_macro.xacro"/>
    <xacro:include filename="$(find ur_description)/urdf/inc/ur_macro.xacro"/>

This is what closes the bug class from the ur5e_test import: the old
resolver only ever looked at Link.mesh_uris, so any xacro:include
dependency (a macro file, a shared materials.xacro, a transmission.xacro
-- any manufacturer's split-file convention) silently never got copied
into the generated package.

DESIGN: rather than re-implementing xacro's own include search (relative
paths, $(find pkg)/... substitution args, nested/transitive includes),
we let xacro do that resolution itself during expansion and just harvest
the result. xacro's own `process_includes()` appends every included
file's absolute path to a module-level `xacro.all_includes` list as a
side effect (the same mechanism `xacro --deps` uses for CMake). See
xacro_support.py's parse_description_file_with_includes().

Mesh URIs are handled separately here (via ament's package index when a
ROS env is sourced, then resource_resolver's existing path-search
fallback) because meshes are binary assets that end up in a different
destination directory (meshes/, not urdf/) with different existing
call sites (config_generator.py etc.) -- unifying return TYPES here
without forcing a directory-layout change on working code.
"""

from __future__ import annotations

from dataclasses import dataclass, field
import os
import re
import shutil

from . import resource_resolver as _mesh

try:
    from ament_index_python.packages import get_package_share_directory, PackageNotFoundError
except ImportError:  # builder must run before a ROS env is necessarily sourced
    get_package_share_directory = None
    PackageNotFoundError = Exception


_INCLUDE_RE = re.compile(r'(<(?:xacro:)?include\s+filename\s*=\s*")([^"]+)(")')
_PACKAGE_URI_RE = re.compile(r"^package://([^/]+)/(.+)$")


@dataclass
class UnresolvedDependency:
    uri: str
    kind: str            # 'mesh' | 'xacro_include'
    searched: list[str]  # what we actually tried, for the error message

    def explain(self) -> str:
        tried = "\n".join(f"  - {s}" for s in self.searched) or "  (nothing -- no source root given)"
        return (
            f"Motus could not resolve {self.kind.replace('_', ' ')}:\n\n"
            f"  {self.uri}\n\n"
            f"Searched:\n{tried}\n\n"
            f"The robot description itself is otherwise valid, but this resource "
            f"is unavailable. Run `motus inspect <path>` to see every unresolved "
            f"reference before importing."
        )


@dataclass
class DependencyResolution:
    copied_includes: dict[str, str] = field(default_factory=dict)   # basename -> source path
    mesh_result: "_mesh.ResourceResolutionResult | None" = None
    unresolved: list[UnresolvedDependency] = field(default_factory=list)

    @property
    def ok(self) -> bool:
        return not self.unresolved


def _resolve_package_share(pkg_name: str) -> str | None:
    """Try ament's package index (a sourced ROS env / built workspace).
    Most manufacturer descriptions dropped straight from a git clone
    won't be indexed -- that's expected and not an error, resource_root
    fallback handles it."""
    if get_package_share_directory is None:
        return None
    try:
        return get_package_share_directory(pkg_name)
    except PackageNotFoundError:
        return None


def resolve_includes(
    include_paths: list[str], dest_urdf_dir: str,
) -> dict[str, str]:
    """Copy every xacro:include dependency -- already resolved to
    absolute source paths by xacro itself, see xacro_support.py -- into
    dest_urdf_dir, flat, basename-deduped (first one wins, same policy
    as resource_resolver.resolve_resources). Returns {basename: source
    path} for what was actually copied."""
    os.makedirs(dest_urdf_dir, exist_ok=True)
    copied: dict[str, str] = {}
    for src in include_paths:
        if not os.path.isfile(src):
            continue
        basename = os.path.basename(src)
        if basename not in copied:
            shutil.copy2(src, os.path.join(dest_urdf_dir, basename))
            copied[basename] = src
    return copied


def rewrite_include_uris(xacro_text: str, copied: dict[str, str]) -> str:
    """Retarget every xacro:include filename="..." whose basename we
    copied to a flat relative reference -- copied files are siblings in
    the same urdf/ directory. Handles plain relative includes AND
    $(find pkg)/... substitution-arg includes identically, since we
    match by basename rather than trying to parse the original form."""
    def _sub(m):
        basename = os.path.basename(m.group(2))
        if basename in copied:
            return f"{m.group(1)}{basename}{m.group(3)}"
        return m.group(0)
    return _INCLUDE_RE.sub(_sub, xacro_text)


def resolve_all(
    urdf_file_path: str,
    mesh_uris: list[str],
    include_paths: list[str],
    dest_urdf_dir: str,
    dest_meshes_dir: str,
    source_root: str | None = None,
) -> DependencyResolution:
    """Single entry point a caller (robot_add.py / the future
    RobotImporter) uses for everything a description can reference.
    Tries the ROS package index first for package:// mesh URIs (so an
    already-installed/sourced manufacturer package resolves correctly
    even if source_root doesn't contain the actual files), then falls
    back to resource_resolver's existing path search."""
    result = DependencyResolution()

    result.copied_includes = resolve_includes(include_paths, dest_urdf_dir)

    # Prefer the ROS package index for package:// mesh URIs when available;
    # resource_resolver.resolve_resources already covers the file-layout
    # fallback (source_root walk, relative-to-urdf-dir, basename search),
    # so we only need to special-case the "package is actually installed"
    # case here and hand the rest to it unchanged.
    effective_roots = [source_root] if source_root else []
    for uri in mesh_uris:
        m = _PACKAGE_URI_RE.match(uri)
        if not m:
            continue
        share = _resolve_package_share(m.group(1))
        if share and os.path.isfile(os.path.join(share, m.group(2))):
            effective_roots.append(share)

    # resource_resolver takes one source_root; try each candidate in turn,
    # keeping the best (most-resolved) result rather than the first.
    best = None
    for root in (effective_roots or [None]):
        candidate = _mesh.resolve_resources(mesh_uris, urdf_file_path, dest_meshes_dir, root)
        if best is None or len(candidate.unresolved) < len(best.unresolved):
            best = candidate
        if not candidate.unresolved:
            break
    result.mesh_result = best

    for uri in (best.unresolved if best else mesh_uris):
        result.unresolved.append(UnresolvedDependency(
            uri=uri, kind="mesh",
            searched=[r for r in effective_roots if r] + [os.path.dirname(urdf_file_path)],
        ))

    return result