"""
object_catalog — shared loader for objects.yaml.

Single source of truth for object types, instance naming, and SDF generation.
"""

import yaml
from dataclasses import dataclass


@dataclass
class ObjectType:
    type_id: str
    child_link: str
    geometry: dict
    max_instances: int


@dataclass
class ObjectInstance:
    child_model: str
    child_link: str
    type_id: str


# ---------------------------------------------------------------------------
# Color parsing
# ---------------------------------------------------------------------------

_NAMED_COLORS = {
    'red': (1.0, 0.0, 0.0), 'green': (0.0, 1.0, 0.0), 'blue': (0.0, 0.0, 1.0),
    'yellow': (1.0, 1.0, 0.0), 'orange': (1.0, 0.65, 0.0), 'purple': (0.5, 0.0, 0.5),
    'white': (1.0, 1.0, 1.0), 'black': (0.0, 0.0, 0.0), 'grey': (0.5, 0.5, 0.5),
    'gray': (0.5, 0.5, 0.5), 'cyan': (0.0, 1.0, 1.0), 'magenta': (1.0, 0.0, 1.0),
    'lime': (0.0, 1.0, 0.0), 'pink': (1.0, 0.75, 0.8), 'teal': (0.0, 0.5, 0.5),
    'navy': (0.0, 0.0, 0.5), 'maroon': (0.5, 0.0, 0.0), 'olive': (0.5, 0.5, 0.0),
    'silver': (0.75, 0.75, 0.75), 'brown': (0.65, 0.16, 0.16),
}


def _parse_color(color_str: str) -> tuple[float, float, float]:
    """Parse a color string into RGB floats in [0, 1].

    Supports named colors, hex #RRGGBB/#RGB, and space-separated RGB.
    Empty string yields light grey (0.8, 0.8, 0.8).
    """
    if not color_str:
        return (0.8, 0.8, 0.8)

    s = color_str.strip().lower()
    if s in _NAMED_COLORS:
        return _NAMED_COLORS[s]

    if s.startswith('#'):
        h = s[1:]
        if len(h) == 3:
            h = ''.join(c * 2 for c in h)
        if len(h) == 6:
            try:
                return (
                    int(h[0:2], 16) / 255.0,
                    int(h[2:4], 16) / 255.0,
                    int(h[4:6], 16) / 255.0,
                )
            except ValueError:
                pass

    parts = s.split()
    if len(parts) >= 3:
        vals = []
        for p in parts[:3]:
            try:
                v = float(p)
                if v > 1.0:
                    v = v / 255.0
                vals.append(max(0.0, min(1.0, v)))
            except ValueError:
                vals.append(0.0)
        return tuple(vals)

    return (0.8, 0.8, 0.8)


class ObjectCatalog:
    """Loads objects.yaml once; every naming/lookup helper other
    components need goes through this class."""

    def __init__(self, path: str):
        with open(path, 'r') as f:
            doc = yaml.safe_load(f) or {}

        gripper = doc.get('gripper', {})
        self.parent_model = gripper.get('parent_model', '')
        self.parent_link = gripper.get('parent_link', '')
        self.approach_offset = float(gripper.get('approach_offset', 0.0))

        self.types: dict[str, ObjectType] = {}
        for type_id, spec in (doc.get('object_types') or {}).items():
            self.types[type_id] = ObjectType(
                type_id=type_id,
                child_link=spec.get('child_link', 'link'),
                geometry=spec.get('geometry', {}),
                max_instances=int(spec.get('max_instances', 1)),
            )

    def instance_name(self, type_id: str, index: int) -> str:
        if type_id not in self.types:
            raise KeyError(f'Unknown object type "{type_id}"')
        if index < 1 or index > self.types[type_id].max_instances:
            raise ValueError(
                f'Instance index {index} out of range for "{type_id}"')
        return f'{type_id}_{index}'

    def all_instances(self) -> list:
        instances = []
        for type_id, otype in self.types.items():
            for i in range(1, otype.max_instances + 1):
                instances.append(ObjectInstance(
                    child_model=self.instance_name(type_id, i),
                    child_link=otype.child_link,
                    type_id=type_id,
                ))
        return instances

    def attach_topic(self, child_model: str) -> str:
        return f'/grasp_attach/{child_model}/attach'

    def detach_topic(self, child_model: str) -> str:
        return f'/grasp_attach/{child_model}/detach'

    def state_topic(self, child_model: str) -> str:
        return f'/model/{child_model}/detachable_joint/state'

    def lookup_by_model(self, child_model: str) -> ObjectInstance:
        for inst in self.all_instances():
            if inst.child_model == child_model:
                return inst
        raise KeyError(f'No catalog instance found for child_model "{child_model}"')

    def to_gazebo_plugin_sdf(self) -> str:
        lines = ['  <gazebo>']
        for inst in self.all_instances():
            lines.append(
                f'    <plugin filename="gz-sim-detachable-joint-system" '
                f'name="gz::sim::systems::DetachableJoint">\n'
                f'      <parent_link>{self.parent_link}</parent_link>\n'
                f'      <child_model>{inst.child_model}</child_model>\n'
                f'      <child_link>{inst.child_link}</child_link>\n'
                f'      <attach_topic>{self.attach_topic(inst.child_model)}</attach_topic>\n'
                f'      <detach_topic>{self.detach_topic(inst.child_model)}</detach_topic>\n'
                f'    </plugin>'
            )
        lines.append('  </gazebo>')
        return '\n'.join(lines)

    def to_ros_gz_bridge_args(self) -> list:
        args = []
        for inst in self.all_instances():
            args.append(
                f'{self.attach_topic(inst.child_model)}@std_msgs/msg/Empty]gz.msgs.Empty')
            args.append(
                f'{self.detach_topic(inst.child_model)}@std_msgs/msg/Empty]gz.msgs.Empty')
            args.append(
                f'{self.state_topic(inst.child_model)}@std_msgs/msg/String[gz.msgs.StringMsg')
        return args

    def instance_model_sdf(self, inst: ObjectInstance, color_str: str = '') -> str:
        """Generate SDF <model> for one catalog instance.

        Optional color_str sets visual material (named, hex, or RGB).
        """
        otype = self.types[inst.type_id]
        geom = otype.geometry
        shape = geom.get('shape', 'box')
        if shape != 'box':
            raise NotImplementedError(
                f'instance_model_sdf only supports box geometry, '
                f'got shape="{shape}"')

        sx, sy, sz = geom['size']
        mass = float(geom.get('mass', 0.01))
        ixx = mass / 12.0 * (sy ** 2 + sz ** 2)
        iyy = mass / 12.0 * (sx ** 2 + sz ** 2)
        izz = mass / 12.0 * (sx ** 2 + sy ** 2)

        r, g, b = _parse_color(color_str)
        material_block = (
            f'      <material>\n'
            f'        <ambient>{r} {g} {b} 1</ambient>\n'
            f'        <diffuse>{r} {g} {b} 1</diffuse>\n'
            f'        <specular>0.1 0.1 0.1 1</specular>\n'
            f'        <emissive>0 0 0 1</emissive>\n'
            f'      </material>\n'
        )

        return (
            '<?xml version="1.0"?>\n'
            f'<sdf version="1.9">\n'
            f'  <model name="{inst.child_model}">\n'
            f'    <link name="{inst.child_link}">\n'
            f'      <inertial>\n'
            f'        <mass>{mass}</mass>\n'
            f'        <inertia>\n'
            f'          <ixx>{ixx}</ixx><iyy>{iyy}</iyy><izz>{izz}</izz>\n'
            f'          <ixy>0</ixy><ixz>0</ixz><iyz>0</iyz>\n'
            f'        </inertia>\n'
            f'      </inertial>\n'
            f'      <collision name="collision">\n'
            f'        <geometry><box><size>{sx} {sy} {sz}</size></box></geometry>\n'
            f'      </collision>\n'
            f'      <visual name="visual">\n'
            f'        <geometry><box><size>{sx} {sy} {sz}</size></box></geometry>\n'
            f'{material_block}'
            f'      </visual>\n'
            f'    </link>\n'
            f'  </model>\n'
            f'</sdf>'
        )

    def grasp_insertion_depth(self, inst: ObjectInstance,
                               approach_axis: str = 'z',
                               engagement_fraction: float = 0.5) -> float:
        otype = self.types[inst.type_id]
        geom = otype.geometry
        shape = geom.get('shape', 'box')
        if shape != 'box':
            raise NotImplementedError(
                f'grasp_insertion_depth only supports box geometry, '
                f'got shape="{shape}"')
        axis_index = {'x': 0, 'y': 1, 'z': 2}.get(approach_axis)
        if axis_index is None:
            raise ValueError(f'approach_axis must be x/y/z, got "{approach_axis}"')
        if not (0.0 < engagement_fraction <= 1.0):
            raise ValueError(
                f'engagement_fraction must be in (0.0, 1.0], got {engagement_fraction}')
        size_along_axis = geom['size'][axis_index]
        return size_along_axis * (engagement_fraction - 0.5)

    def grasp_approach_offset(self, inst: ObjectInstance,
                               approach_axis: str = 'z',
                               engagement_fraction: float = 0.5) -> float:
        return (self.approach_offset +
                self.grasp_insertion_depth(inst, approach_axis, engagement_fraction))
