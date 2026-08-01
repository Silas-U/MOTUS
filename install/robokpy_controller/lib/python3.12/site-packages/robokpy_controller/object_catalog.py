"""
object_catalog — shared loader for objects.yaml.

Single source of truth for:
  - which object TYPES exist and their spawn geometry
  - the deterministic child_model naming pattern for every INSTANCE of
    a type, so the spawn script, the GraspAttach bridge node, and the
    future vision pose-resolver all agree on names without each
    re-implementing the pattern
  - the gripper's parent_model/parent_link (one source, so
    tool_action_server's grasp_attach config in tools.yaml and the
    spawn script's generated DetachableJoint plugins can't drift apart)

NOT YET WIRED: nothing calls this module yet. It's the shared
foundation the spawn script and bridge node (next pieces) both import.
"""

import yaml
from dataclasses import dataclass, field


@dataclass
class ObjectType:
    type_id: str
    child_link: str
    geometry: dict
    max_instances: int


@dataclass
class ObjectInstance:
    child_model: str   # e.g. "cube_small_3"
    child_link: str    # e.g. "link"
    type_id: str       # e.g. "cube_small"


class ObjectCatalog:
    """Loads objects.yaml once; every naming/lookup helper other
    components need goes through this class rather than re-parsing
    the YAML or re-deriving the naming pattern independently."""

    def __init__(self, path: str):
        with open(path, 'r') as f:
            doc = yaml.safe_load(f) or {}

        gripper = doc.get('gripper', {})
        self.parent_model = gripper.get('parent_model', '')
        self.parent_link = gripper.get('parent_link', '')

        self.types: dict[str, ObjectType] = {}
        for type_id, spec in (doc.get('object_types') or {}).items():
            self.types[type_id] = ObjectType(
                type_id=type_id,
                child_link=spec.get('child_link', 'link'),
                geometry=spec.get('geometry', {}),
                max_instances=int(spec.get('max_instances', 1)),
            )

    def instance_name(self, type_id: str, index: int) -> str:
        """Deterministic child_model name for instance `index` (1-indexed)
        of `type_id`. THE ONLY place this naming pattern is defined —
        every other component calls this instead of building the string
        itself, so the pattern can change in exactly one place later."""
        if type_id not in self.types:
            raise KeyError(f'Unknown object type "{type_id}"')
        if index < 1 or index > self.types[type_id].max_instances:
            raise ValueError(
                f'Instance index {index} out of range for "{type_id}" '
                f'(max_instances={self.types[type_id].max_instances})')
        return f'{type_id}_{index}'

    def all_instances(self) -> list:
        """Every possible instance across all types, up to max_instances
        each. This is the full set of DetachableJoint plugins the spawn
        script needs to pre-generate at launch — bounded-catalog design
        means the attach plumbing exists for all of them whether or not
        they're currently spawned into the world."""
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
        """Per-instance attach topic — matches the naming the spawn
        script uses for each DetachableJoint plugin's <attach_topic>."""
        return f'/grasp_attach/{child_model}/attach'

    def detach_topic(self, child_model: str) -> str:
        """Per-instance detach topic. NOTE: needs confirming against the
        actual gz-sim DetachableJoint SDF schema — the default detach
        topic naming/param may differ from this assumed convention;
        verify against gz-sim docs for the installed version before the
        spawn script relies on it."""
        return f'/grasp_attach/{child_model}/detach'

    def state_topic(self, child_model: str) -> str:
        """Per-instance attach/detach STATE topic — this is the
        DetachableJoint plugin's own default output topic
        (/model/<child_model>/detachable_joint/state, gz.msgs.StringMsg
        "attached"/"detached"), confirmed against gz-sim8's actual
        source (src/systems/detachable_joint/DetachableJoint.cc). No
        <output_topic> override needed in the generated plugin SDF —
        this default is deterministic from child_model alone. Exists
        because attach/detach have NO ack otherwise: attachRequested
        defaults to true in the plugin (auto-attach the instant
        child_model appears in the world), and a detach message sent
        before that auto-attach has actually landed is silently
        dropped ("already detached", no-op) rather than preventing it
        — so callers that need to force-detach a freshly spawned
        instance (see object_spawner.py) must wait for a real
        "attached" confirmation on this topic before detaching, not
        just sleep and hope the timing worked out."""
        return f'/model/{child_model}/detachable_joint/state'

    def lookup_by_model(self, child_model: str) -> ObjectInstance:
        """Reverse lookup: given a child_model name (e.g. from a
        GraspAttach.srv request), find its catalog entry. Used by the
        bridge node to know which topics to publish to."""
        for inst in self.all_instances():
            if inst.child_model == child_model:
                return inst
        raise KeyError(f'No catalog instance found for child_model "{child_model}"')

    def to_gazebo_plugin_sdf(self) -> str:
        """Generate the <gazebo> block containing one DetachableJoint
        system plugin per possible catalog instance (bounded catalog —
        one plugin per instance slot, whether or not that instance is
        currently spawned into the world). Meant to be spliced into the
        robot's URDF (model-level <gazebo> tag, no reference= attribute)
        before it's handed to Gazebo for spawning.

        Plugin filename confirmed against motus_world.sdf's existing
        convention (bare name, no lib/.so — e.g. "gz-sim-physics-system").

        IMPORTANT: each catalog instance must NOT already exist as a
        spawned model at the moment the robot model loads — the system
        attempts to attach immediately on load if a matching child_model
        is found, which would start that instance pre-welded to the
        gripper. Since instances are meant to be spawned dynamically
        per-recipe (after the robot is already up), this is a non-issue
        in normal operation, but don't pre-populate the world file with
        any catalog instance names at launch.
        """
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
        """ROS<->GZ topic mappings for ros_gz_bridge's parameter_bridge —
        one attach + one detach topic per catalog instance. ROS->GZ only
        (']' direction, matching the syntax the existing gz_clock_bridge
        entry uses, just the opposite direction since that one is GZ->ROS)
        since the bridge node only ever needs to SEND attach/detach
        commands into Gazebo, never read state back through these topics.
        Message type gz.msgs.Empty matches the gz.msgs.* convention
        already used by gz_clock_bridge in the launch file."""
        args = []
        for inst in self.all_instances():
            args.append(
                f'{self.attach_topic(inst.child_model)}@std_msgs/msg/Empty]gz.msgs.Empty')
            args.append(
                f'{self.detach_topic(inst.child_model)}@std_msgs/msg/Empty]gz.msgs.Empty')
            # GZ -> ROS (note the reversed bracket vs. the two above —
            # matches gz_clock_bridge's direction in the launch file):
            # this is state coming OUT of the plugin, not a command
            # going in. See state_topic() docstring for why this is
            # needed at all.
            args.append(
                f'{self.state_topic(inst.child_model)}@std_msgs/msg/String[gz.msgs.StringMsg')
        return args

    def instance_model_sdf(self, inst: ObjectInstance) -> str:
        """Generate a standalone SDF <model> string for one catalog
        instance, for use as the `sdf` field of
        ros_gz_interfaces/srv/SpawnEntity's request.

        Only shape: box is supported (both seeded types are boxes) —
        extend this if a non-box geometry type is added to objects.yaml.
        Inertia computed via the standard solid-box formula about the
        center of mass; this is model authoring, not physics tuning,
        so it's fine as an assumption baked into the catalog rather
        than something to ask about.
        """
        otype = self.types[inst.type_id]
        geom = otype.geometry
        shape = geom.get('shape', 'box')
        if shape != 'box':
            raise NotImplementedError(
                f'instance_model_sdf only supports box geometry so far, '
                f'got shape="{shape}" for type "{inst.type_id}" — add '
                f'other shape branches here before using non-box types.')

        sx, sy, sz = geom['size']
        mass = float(geom.get('mass', 0.01))
        ixx = mass / 12.0 * (sy ** 2 + sz ** 2)
        iyy = mass / 12.0 * (sx ** 2 + sz ** 2)
        izz = mass / 12.0 * (sx ** 2 + sy ** 2)

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
            f'      </visual>\n'
            f'    </link>\n'
            f'  </model>\n'
            f'</sdf>'
        )