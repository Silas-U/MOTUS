"""
project_paths.py

Single source of truth for where a cell finds its *project-owned* world and
recipes. robokpy_controller is the engine; a generated Motus project may ship
its own `worlds/<name>.sdf` and `recipes/*.yaml` and pass them in.

Backward compatibility rule: every argument defaults to "" / None, and an
empty value reproduces the pre-existing behaviour exactly (core world, core
recipes folder). Nothing here changes what an old project does.

Pure Python (no rclpy / launch imports) so it is unit-testable offline.
"""

from __future__ import annotations

import os
import re
import xml.etree.ElementTree as ET


class ProjectPathError(RuntimeError):
    """An explicitly supplied project path is unusable. Raised instead of
    silently falling back to the core copy, because that would run the wrong
    scene/recipe without anyone noticing."""


def _core_recipes_dir() -> str:
    from ament_index_python.packages import get_package_share_directory
    return os.path.join(get_package_share_directory('robokpy_controller'), 'recipes')


def resolve_recipe_path(recipe_path: str, recipes_dir: str = '',
                        core_recipes_dir: str | None = None) -> str:
    """Resolution order:
       1. an existing absolute path,
       2. a path that exists relative to the current directory,
       3. <recipes_dir>/<recipe_path>   (only when a project folder was given),
       4. <core recipes>/<recipe_path>  (last resort; may not exist -- the
          caller reports 'Recipe not found' with this path).
    """
    if os.path.isabs(recipe_path) and os.path.exists(recipe_path):
        return recipe_path
    if os.path.exists(recipe_path):
        return recipe_path
    if recipes_dir:
        cand = os.path.join(recipes_dir, recipe_path)
        if os.path.exists(cand):
            return cand
    core = core_recipes_dir if core_recipes_dir is not None else _core_recipes_dir()
    return os.path.join(core, recipe_path)


def validate_world_file(path: str) -> str:
    """Return `path` if it is a readable SDF world; raise ProjectPathError."""
    if not os.path.isfile(path):
        raise ProjectPathError(f"world_file '{path}' does not exist.")
    try:
        # Gazebo's SDF parser tolerates '--' inside comments (the stock
        # motus_world.sdf header has gz CLI flags there); strict XML does not.
        # Comments carry no structure, so drop them before checking.
        with open(path, encoding='utf-8') as f:
            text = re.sub(r'<!--.*?-->', '', f.read(), flags=re.DOTALL)
        root = ET.fromstring(text)
    except (ET.ParseError, OSError) as e:
        raise ProjectPathError(f"world_file '{path}' is not valid XML: {e}") from e
    if root.tag != 'sdf' or root.find('world') is None:
        raise ProjectPathError(f"world_file '{path}' is not an SDF world (<sdf><world>...).")
    return path


def validate_recipes_dir(path: str) -> str:
    if not os.path.isdir(path):
        raise ProjectPathError(f"recipes_dir '{path}' is not a directory.")
    return path


def resolve_world_file(world_file: str, core_world: str) -> str:
    """'' -> the core world (unchanged behaviour); otherwise the validated project world."""
    return validate_world_file(world_file) if world_file else core_world


def resolve_recipes_dir(recipes_dir: str) -> str:
    """'' -> '' (core only); otherwise the validated project folder."""
    return validate_recipes_dir(recipes_dir) if recipes_dir else ''
