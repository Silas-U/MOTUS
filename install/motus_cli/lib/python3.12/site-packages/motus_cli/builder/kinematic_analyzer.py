"""
kinematic_analyzer.py

Given a parsed RobotDescription (urdf_parser.py), finds the robot's main
serial arm chain: base link, tip link, and the ordered list of movable
joints between them -- what config_generator.py needs for
planning_base_link/planning_tip_link and the joint list in
config/controllers.yaml.

WHY THIS IS A FORK-DETECTION WALK, NOT A "DEEPEST/MOST-DOF LEAF" SCORE:

Tested against the real UR5e+Robotiq-85 URDF this repo generates from
urdf/robokpy_robot.urdf.xacro, two structural patterns both need handling,
and they push in opposite directions:

  1. Dead-end reference frames: base_link has a `base` child (legacy
     compat frame) alongside the real continuation base_link_inertia;
     wrist_3_link has an `ft_frame` child (sensor mount) alongside the
     real continuation `flange`. Both are single fixed-joint dead ends
     with zero movable joints anywhere downstream. These must be SKIPPED
     without stopping the chain.

  2. The gripper mount: tool0 -> robotiq_85_base_link (fixed) -> four
     children (left/right knuckle, left/right inner knuckle), each a
     movable joint of the parallel-jaw mechanism. An earlier version of
     this analyzer scored leaves by total movable-joint count and simply
     followed the single deepest finger branch, returning DOF=8 (6 arm +
     2 of the finger's joints) and tip_link=a fingertip link -- wrong:
     the gripper is a separate mechanism, not additional arm DOF.

The fix: walk link-by-link from base_link. At each link, look at its
children (not the whole subtree) and classify each by whether it OR
ANYTHING BELOW IT contains a movable joint ("DOF-bearing"):

  - exactly one DOF-bearing child, any number of non-DOF-bearing (dead
    end) siblings -> follow the DOF-bearing one, record dead ends as
    warnings, keep walking (case 1 above)
  - two or more DOF-bearing children -> this is a genuine kinematic fork
    (an end-effector mechanism, or a real second limb) -- STOP here;
    this link is tip_link (case 2 above: stops at robotiq_85_base_link,
    DOF=6, gripper joints excluded from the arm chain entirely)
  - zero DOF-bearing children (a true dead end with no gripper attached
    at all) -> no movable joint decides which sibling to follow, so fall
    back to preferring a recognizable frame name (tool0/tcp/flange/
    ee_link) and otherwise the deepest fixed-frame chain, and keep
    walking through fixed joints only (never added to the DOF list)
"""

from __future__ import annotations

from dataclasses import dataclass, field

from .urdf_parser import RobotDescription, Joint

_TIP_NAME_PREFERENCE = ("tool0", "tcp", "flange", "ee_link", "end_effector", "tip")


@dataclass
class ChainWarning:
    kind: str        # 'dead_end_frame' | 'missing_limit' | 'multi_root' | 'fork'
    message: str
    link_or_joint: str


@dataclass
class KinematicAnalysis:
    base_link: str
    tip_link: str
    chain_joints: list[Joint]        # ordered base -> tip, movable joints only
    dof: int
    warnings: list[ChainWarning] = field(default_factory=list)

    @property
    def joint_names(self) -> list[str]:
        return [j.name for j in self.chain_joints]


def _find_root(desc: RobotDescription, warnings: list[ChainWarning]) -> str:
    roots = desc.root_links()
    if not roots:
        raise ValueError("no root link found -- every link is some joint's child (cyclic?)")
    if len(roots) > 1:
        warnings.append(ChainWarning(
            kind="multi_root",
            message=(
                f"description has {len(roots)} disconnected root links "
                f"({', '.join(roots)}); using the first. The others are either "
                f"unreachable or this is actually a multi-robot/scene file."
            ),
            link_or_joint=roots[0],
        ))
    root = roots[0]
    # A root literally named 'world' is the standard convention for "the
    # fixed frame this robot is mounted into a scene at" -- it is virtual,
    # not a robot link, so the real base is its (normally sole) child.
    if root == "world":
        children = desc.children_of("world")
        if len(children) == 1:
            return children[0].child
        if len(children) > 1:
            warnings.append(ChainWarning(
                kind="multi_root",
                message=(
                    f"root link 'world' has {len(children)} children "
                    f"({', '.join(j.child for j in children)}) -- multiple robots "
                    f"in one description? Treating '{children[0].child}' as base_link."
                ),
                link_or_joint="world",
            ))
            return children[0].child
    return root


def _has_movable_descendant(desc: RobotDescription, link: str, memo: dict[str, bool],
                             visiting: set[str]) -> bool:
    if link in memo:
        return memo[link]
    if link in visiting:
        return False  # cycle guard
    visiting = visiting | {link}
    result = False
    for j in desc.children_of(link):
        if j.is_movable or _has_movable_descendant(desc, j.child, memo, visiting):
            result = True
            break
    memo[link] = result
    return result


def _deepest_fixed_leaf(desc: RobotDescription, link: str, visited: set[str]) -> tuple[int, str]:
    """For a subtree known to contain no movable joints at all: how many
    fixed-joint hops to its deepest leaf, and that leaf's name. Used only
    to pick a sensible continuation among several equally-dead-end
    branches (e.g. ft_frame vs flange when no gripper is attached)."""
    children = desc.children_of(link)
    if not children or link in visited:
        return 0, link
    visited = visited | {link}
    best = (0, link)
    for j in children:
        depth, leaf = _deepest_fixed_leaf(desc, j.child, visited)
        candidate = (depth + 1, leaf)
        name_rank = 0 if candidate[1] in _TIP_NAME_PREFERENCE else 1
        best_rank = 0 if best[1] in _TIP_NAME_PREFERENCE else 1
        if (name_rank, -candidate[0]) < (best_rank, -best[0]):
            best = candidate
    return best


def analyze(desc: RobotDescription) -> KinematicAnalysis:
    warnings: list[ChainWarning] = []
    base_link = _find_root(desc, warnings)

    chain_joints: list[Joint] = []
    current = base_link
    visited = {base_link}
    memo: dict[str, bool] = {}

    while True:
        children = desc.children_of(current)
        if not children:
            break  # true leaf -- tip_link = current

        dof_bearing = [
            j for j in children
            if j.is_movable or _has_movable_descendant(desc, j.child, memo, set())
        ]

        if len(dof_bearing) >= 2:
            warnings.append(ChainWarning(
                kind="fork",
                message=(
                    f"link '{current}' forks into {len(dof_bearing)} branches that each "
                    f"contain movable joints ({', '.join(j.child for j in dof_bearing)}) -- "
                    f"treating this as an end-effector/mechanism boundary and stopping the "
                    f"arm chain here rather than descending into it."
                ),
                link_or_joint=current,
            ))
            break  # current is tip_link

        if len(dof_bearing) == 1:
            chosen = dof_bearing[0]
            for j in children:
                if j is not chosen:
                    warnings.append(ChainWarning(
                        kind="dead_end_frame",
                        message=(
                            f"link '{j.child}' branches off at '{current}' via a fixed joint "
                            f"and leads nowhere useful (likely a reference/mounting frame) -- "
                            f"excluded from the planning chain."
                        ),
                        link_or_joint=j.child,
                    ))
            if chosen.is_movable:
                chain_joints.append(chosen)
            current = chosen.child
            visited.add(current)
            continue

        # len(dof_bearing) == 0: every child is a dead end. No movable
        # joint to disambiguate -- follow whichever leads to the deepest/
        # best-named fixed-frame chain, note the rest as dead ends.
        scored = []
        for j in children:
            depth, leaf = _deepest_fixed_leaf(desc, j.child, set())
            name_rank = 0 if leaf in _TIP_NAME_PREFERENCE else 1
            scored.append((name_rank, -depth, j))
        scored.sort(key=lambda t: (t[0], t[1]))
        chosen = scored[0][2]
        for _, _, j in scored[1:]:
            warnings.append(ChainWarning(
                kind="dead_end_frame",
                message=(
                    f"link '{j.child}' branches off at '{current}' via a fixed joint "
                    f"and leads nowhere useful (likely a reference/mounting frame) -- "
                    f"excluded from the planning chain."
                ),
                link_or_joint=j.child,
            ))
        current = chosen.child
        visited.add(current)

    tip_link = current

    for j in chain_joints:
        if j.limit is None:
            warnings.append(ChainWarning(
                kind="missing_limit", link_or_joint=j.name,
                message=f"joint '{j.name}' ({j.type}) has no <limit> element at all.",
            ))
        else:
            if j.type == "revolute" and (j.limit.lower is None or j.limit.upper is None):
                warnings.append(ChainWarning(
                    kind="missing_limit", link_or_joint=j.name,
                    message=f"revolute joint '{j.name}' is missing position lower/upper limits.",
                ))
            if j.limit.velocity is None:
                warnings.append(ChainWarning(
                    kind="missing_limit", link_or_joint=j.name,
                    message=f"joint '{j.name}' has no velocity limit -- Motus will need a default.",
                ))
            if j.limit.effort is None:
                warnings.append(ChainWarning(
                    kind="missing_limit", link_or_joint=j.name,
                    message=f"joint '{j.name}' has no effort limit -- Motus will need a default.",
                ))

    return KinematicAnalysis(
        base_link=base_link, tip_link=tip_link, chain_joints=chain_joints,
        dof=len(chain_joints), warnings=warnings,
    )
