"""
urdf_parser.py

A lean, dependency-light URDF reader for the Motus Builder pipeline.
Deliberately NOT a wrapper around urdf_parser_py / urdfdom: that's a
heavier, ROS-coupled dependency, and the Builder needs to run (e.g. in
`motus create project --from ...`) before a workspace necessarily has a
full ROS environment sourced. Standard-library xml.etree is enough for
what the pipeline actually needs: the link/joint graph, joint types and
limits, and mesh URIs. It does not attempt to interpret <visual>/
<collision> geometry beyond mesh filename extraction, and does not
evaluate xacro -- callers must pass already-xacro-processed URDF XML
(robot_description_import.py's job) or a plain .urdf file.
"""

from __future__ import annotations

from dataclasses import dataclass, field
import xml.etree.ElementTree as ET


@dataclass
class JointLimit:
    lower: float | None = None
    upper: float | None = None
    velocity: float | None = None
    effort: float | None = None


@dataclass
class Joint:
    name: str
    type: str  # revolute | continuous | prismatic | fixed | floating | planar
    parent: str
    child: str
    limit: JointLimit | None = None

    @property
    def is_movable(self) -> bool:
        return self.type in ("revolute", "continuous", "prismatic")


@dataclass
class Link:
    name: str
    mesh_uris: list[str] = field(default_factory=list)
    has_inertial: bool = False


@dataclass
class RobotDescription:
    name: str
    links: dict[str, Link]
    joints: dict[str, Joint]
    # child_link_name -> joint that produces it (every non-root link has exactly one)
    joint_by_child: dict[str, Joint]
    # parent_link_name -> [joints whose parent is this link], in document order
    joints_by_parent: dict[str, list[Joint]]

    def children_of(self, link_name: str) -> list[Joint]:
        return self.joints_by_parent.get(link_name, [])

    def root_links(self) -> list[str]:
        """Links that are never a joint's child -- normally exactly one
        (the true root, e.g. 'world' or 'base_link'); more than one means
        a disconnected/multi-root description, which doctor should flag."""
        return [name for name in self.links if name not in self.joint_by_child]


class UrdfParseError(ValueError):
    pass


def parse_urdf_string(xml_text: str) -> RobotDescription:
    try:
        root = ET.fromstring(xml_text)
    except ET.ParseError as e:
        raise UrdfParseError(f"not well-formed XML: {e}") from e

    if root.tag != "robot":
        raise UrdfParseError(f"root element is <{root.tag}>, expected <robot>")

    robot_name = root.get("name", "")

    links: dict[str, Link] = {}
    for link_el in root.findall("link"):
        name = link_el.get("name")
        if not name:
            raise UrdfParseError("<link> element with no name attribute")
        mesh_uris = [
            mesh_el.get("filename")
            for mesh_el in link_el.findall(".//mesh")
            if mesh_el.get("filename")
        ]
        links[name] = Link(
            name=name, mesh_uris=mesh_uris,
            has_inertial=link_el.find("inertial") is not None,
        )

    joints: dict[str, Joint] = {}
    joint_by_child: dict[str, Joint] = {}
    joints_by_parent: dict[str, list[Joint]] = {}

    for joint_el in root.findall("joint"):
        name = joint_el.get("name")
        jtype = joint_el.get("type")
        if not name or not jtype:
            raise UrdfParseError("<joint> missing name or type attribute")

        parent_el = joint_el.find("parent")
        child_el = joint_el.find("child")
        if parent_el is None or child_el is None:
            raise UrdfParseError(f"joint '{name}' missing <parent> or <child>")
        parent = parent_el.get("link")
        child = child_el.get("link")
        if not parent or not child:
            raise UrdfParseError(f"joint '{name}' has <parent>/<child> with no link attribute")

        limit = None
        limit_el = joint_el.find("limit")
        if limit_el is not None:
            def _f(attr):
                v = limit_el.get(attr)
                return float(v) if v is not None else None
            limit = JointLimit(
                lower=_f("lower"), upper=_f("upper"),
                velocity=_f("velocity"), effort=_f("effort"),
            )

        joint = Joint(name=name, type=jtype, parent=parent, child=child, limit=limit)

        if child in joint_by_child:
            raise UrdfParseError(
                f"link '{child}' is the child of more than one joint "
                f"('{joint_by_child[child].name}' and '{name}') -- URDF requires a tree"
            )
        joints[name] = joint
        joint_by_child[child] = joint
        joints_by_parent.setdefault(parent, []).append(joint)

        # A joint may reference links not declared with a <link> element
        # (rare but legal-ish in hand-edited URDFs, e.g. a typo'd parent/
        # child name). Register a stub so downstream code doesn't KeyError,
        # and let the caller / doctor decide whether that's fatal.
        for link_name in (parent, child):
            if link_name not in links:
                links[link_name] = Link(name=link_name)

    return RobotDescription(
        name=robot_name, links=links, joints=joints,
        joint_by_child=joint_by_child, joints_by_parent=joints_by_parent,
    )


def parse_urdf_file(path: str) -> RobotDescription:
    with open(path, "r", encoding="utf-8") as f:
        return parse_urdf_string(f.read())
