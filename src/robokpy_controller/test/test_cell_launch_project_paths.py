"""Runs the REAL cell.launch.py with stubbed launch/ROS modules to verify the
world_file / recipes_dir handling (defaults unchanged, bad paths abort)."""
import importlib.util, os, sys, types
import pytest

CORE = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))


class Rec:
    def __init__(self, *a, **k):
        self.a, self.k = a, k
        self.parameters = k.get('parameters')
        self.actions = k.get('actions')
        self.launch_arguments = k.get('launch_arguments')


class LC:
    values = {}
    def __init__(self, name): self.name = name
    def perform(self, ctx): return LC.values.get(self.name, '')


def load(values, mp):
    LC.values = values
    mods = {}
    def mod(name, **attrs):
        m = types.ModuleType(name); m.__dict__.update(attrs); mods[name] = m; return m
    mod('launch', LaunchDescription=lambda items: items)
    mod('launch.actions', DeclareLaunchArgument=lambda name, **k: Rec(name=name, **k),
        IncludeLaunchDescription=Rec, TimerAction=Rec, OpaqueFunction=lambda function: function,
        SetEnvironmentVariable=Rec, ExecuteProcess=Rec, RegisterEventHandler=Rec)
    mod('launch.logging', get_logger=lambda name='x': types.SimpleNamespace(info=lambda *a, **k: None, warning=lambda *a, **k: None, error=lambda *a, **k: None))
    mod('launch.conditions', IfCondition=lambda x: x, UnlessCondition=lambda x: x)
    mod('launch.substitutions', LaunchConfiguration=LC, PathJoinSubstitution=lambda x: '/'.join(map(str, x)),
        PythonExpression=Rec, TextSubstitution=Rec, Command=Rec, FindExecutable=Rec)
    mod('launch.launch_description_sources', PythonLaunchDescriptionSource=Rec)
    mod('launch_ros'); mod('launch_ros.actions', Node=Rec)
    mod('launch_ros.substitutions', FindPackageShare=lambda p: types.SimpleNamespace(find=lambda q: CORE))
    mod('ament_index_python'); mod('ament_index_python.packages', get_package_prefix=lambda p: '/nonexistent',
        get_package_share_directory=lambda p: CORE)
    mods['launch'].logging = mods['launch.logging']
    for name, m in mods.items():
        mp.setitem(sys.modules, name, m)
    mp.syspath_prepend(CORE)
    spec = importlib.util.spec_from_file_location('cell_launch', f'{CORE}/launch/cell.launch.py')
    cl = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cl)
    return cl


def run(values, mp):
    cl = load(values, mp)
    items = cl.generate_launch_description()
    configure = items[-1]
    return configure(object())


def find_gz_args(out):
    for o in out:
        if isinstance(o, Rec) and o.launch_arguments and 'gz_args' in dict(o.launch_arguments):
            return dict(o.launch_arguments)['gz_args']


def orch_params(out):
    for o in out:
        if isinstance(o, Rec) and o.actions:
            for a in o.actions:
                return a.parameters[0]


def test_defaults_unchanged(monkeypatch):
    out = run({}, monkeypatch)
    assert find_gz_args(out).strip() == f'-r {CORE}/worlds/motus_world.sdf'
    assert orch_params(out)['recipes_dir'] == ''


def test_project_world_and_recipes_used(tmp_path, monkeypatch):
    w = tmp_path / 'w.sdf'; w.write_text('<sdf version="1.9"><world name="x"/></sdf>')
    r = tmp_path / 'recipes'; r.mkdir()
    out = run({'world_file': str(w), 'recipes_dir': str(r)}, monkeypatch)
    assert find_gz_args(out).strip() == f'-r {w}'
    assert orch_params(out)['recipes_dir'] == str(r)


def test_bad_paths_abort(tmp_path, monkeypatch):
    from robokpy_controller.project_paths import ProjectPathError
    with pytest.raises(ProjectPathError):
        run({'world_file': str(tmp_path / 'missing.sdf')}, monkeypatch)
    with pytest.raises(ProjectPathError):
        run({'recipes_dir': str(tmp_path / 'missing')}, monkeypatch)
