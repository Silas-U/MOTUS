"""Offline tests for project_paths (no ROS runtime needed)."""
import os
import sys

import pytest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..'))
from robokpy_controller.project_paths import (  # noqa: E402
    ProjectPathError, resolve_recipe_path, resolve_recipes_dir, resolve_world_file,
    validate_world_file)

SDF = '<?xml version="1.0"?><sdf version="1.9"><world name="w"/></sdf>'


def test_recipe_resolution_order(tmp_path):
    core, proj = tmp_path / 'core', tmp_path / 'proj'
    core.mkdir(), proj.mkdir()
    (core / 'a.yaml').write_text('x'), (core / 'both.yaml').write_text('core')
    (proj / 'b.yaml').write_text('x'), (proj / 'both.yaml').write_text('proj')
    r = lambda name, pd='': resolve_recipe_path(name, pd, core_recipes_dir=str(core))  # noqa: E731
    assert r(str(proj / 'b.yaml')) == str(proj / 'b.yaml')          # absolute path wins
    assert r('a.yaml') == str(core / 'a.yaml')                       # no project dir: core, as before
    assert r('b.yaml', str(proj)) == str(proj / 'b.yaml')           # project folder
    assert r('both.yaml', str(proj)) == str(proj / 'both.yaml')     # project shadows core
    assert r('a.yaml', str(proj)) == str(core / 'a.yaml')           # falls back to core
    assert r('missing.yaml', str(proj)) == str(core / 'missing.yaml')  # caller reports not found


def test_empty_args_reproduce_old_behaviour(tmp_path):
    assert resolve_world_file('', '/core/motus_world.sdf') == '/core/motus_world.sdf'
    assert resolve_recipes_dir('') == ''


def test_explicit_bad_paths_fail_loudly(tmp_path):
    with pytest.raises(ProjectPathError, match='does not exist'):
        resolve_world_file(str(tmp_path / 'nope.sdf'), '/core')
    bad = tmp_path / 'bad.sdf'
    bad.write_text('<sdf')
    with pytest.raises(ProjectPathError, match='not valid XML'):
        validate_world_file(str(bad))
    notworld = tmp_path / 'nw.sdf'
    notworld.write_text('<sdf version="1.9"/>')
    with pytest.raises(ProjectPathError, match='not an SDF world'):
        validate_world_file(str(notworld))
    with pytest.raises(ProjectPathError, match='not a directory'):
        resolve_recipes_dir(str(tmp_path / 'nodir'))
    good = tmp_path / 'ok.sdf'
    good.write_text(SDF)
    assert resolve_world_file(str(good), '/core') == str(good)


def test_comments_with_double_dash_are_tolerated(tmp_path):
    """The stock world's header comment contains gz CLI flags (--reqtype ...)."""
    w = tmp_path / 'w.sdf'
    w.write_text('<?xml version="1.0"?><!-- try: gz service --reqtype x --timeout 3 -->'
                 '<sdf version="1.9"><world name="w"/></sdf>')
    assert validate_world_file(str(w)) == str(w)


def test_real_core_world_validates():
    core = os.path.join(os.path.dirname(__file__), '..', 'worlds', 'motus_world.sdf')
    assert validate_world_file(core)
