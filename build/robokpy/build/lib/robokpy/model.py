# """
# Author: Silas Udofia
# Date: 2024-08-02
# GitHub: https://github.com/Silas-U/RoboKpy/tree/main

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
# """

import xml.etree.ElementTree as ET
import os
import numpy as np


class URDFModel:

    def __init__(self, source, from_string=False):

        self.active_joints   = []
        self.joint_names     = []
        self.joint_structure = []
        self.num_of_joints   = 0

        if from_string:
            self.tree = ET.ElementTree(ET.fromstring(source))
        else:
            if not os.path.exists(source):
                raise ValueError(f"URDF file not found: {source}")
            self.tree = ET.parse(source)

        self.root = self.tree.getroot()

        # ── Caches ──────────────────────────────────────────
        self._joints_cache        = None   # all joints (raw)
        self._active_joints_cache = None   # revolute / prismatic / continuous
        self._joint_names_cache   = None
        self._joint_structure_cache = None
        self._joint_limits_cache  = None
        self._link_names_cache    = None

    # =========================================================
    # INTERNAL HELPERS
    # =========================================================

    def _parse_vec3(self, text: str, default="0 0 0") -> str:
        """Return text if non-empty, else default."""
        return text.strip() if (text and text.strip()) else default

    def _is_active(self, jtype: str) -> bool:
        return jtype in ("revolute", "prismatic", "continuous")

    # =========================================================
    # ALL JOINTS
    # =========================================================

    def get_joints(self):
        """
        Parse and cache all joints from the URDF.
        Subsequent calls return the cached list.
        """
        if self._joints_cache is not None:
            return self._joints_cache

        joints = []

        for joint in self.root.findall("joint"):

            name  = joint.get("name")
            jtype = joint.get("type")

            parent_tag = joint.find("parent")
            child_tag  = joint.find("child")

            if parent_tag is None or child_tag is None:
                continue

            parent = parent_tag.get("link")
            child  = child_tag.get("link")

            # Origin
            origin = joint.find("origin")
            if origin is not None:
                xyz = self._parse_vec3(origin.get("xyz", ""), "0 0 0")
                rpy = self._parse_vec3(origin.get("rpy", ""), "0 0 0")
            else:
                xyz, rpy = "0 0 0", "0 0 0"

            # Axis
            axis_tag = joint.find("axis")
            if axis_tag is not None and axis_tag.get("xyz") is not None:
                axis = self._parse_vec3(axis_tag.get("xyz"), "0 0 1")
            else:
                axis = "0 0 1"

            # Limits
            limit_tag = joint.find("limit")
            if limit_tag is not None:
                lower    = float(limit_tag.get("lower",    "-inf"))
                upper    = float(limit_tag.get("upper",     "inf"))
                effort   = float(limit_tag.get("effort",     "0"))
                velocity = float(limit_tag.get("velocity",   "0"))
            else:
                lower = upper = effort = velocity = None

            is_continuous = (jtype == "continuous")

            joints.append({
                "name":          name,
                "type":          jtype,
                "parent":        parent,
                "child":         child,
                "xyz":           xyz,
                "rpy":           rpy,
                "axis":          axis,
                # Pre-parsed once here rather than re-split/re-parsed from
                # the strings above on every fk.joint_transform() call —
                # that call happens once per joint per FK evaluation, and
                # FK is called every IK iteration (up to max_iter times per
                # solve()), so this scales with DOF x iterations x solves.
                # Kept alongside the string fields for backward
                # compatibility with anything still reading them directly.
                "xyz_arr":       np.array(list(map(float, xyz.split())), dtype=float),
                "rpy_arr":       np.array(list(map(float, rpy.split())), dtype=float),
                "axis_arr":      np.array(list(map(float, axis.split())), dtype=float),
                "limit":         (lower, upper),
                "effort":        effort,
                "velocity":      velocity,
                "is_continuous": is_continuous,
            })

        self._joints_cache = joints
        return joints

    # =========================================================
    # ACTIVE JOINTS
    # =========================================================

    def get_active_joints(self):
        """
        Return and cache only actuated joints
        (revolute, prismatic, continuous).
        """
        if self._active_joints_cache is not None:
            return self._active_joints_cache

        self._active_joints_cache = [
            j for j in self.get_joints() if self._is_active(j["type"])
        ]
        self.active_joints = self._active_joints_cache
        return self._active_joints_cache

    def get_joint_structure(self):
        """Return list of joint type strings for active joints."""
        if self._joint_structure_cache is not None:
            return self._joint_structure_cache

        self._joint_structure_cache = [
            j["type"] for j in self.get_active_joints()
        ]
        self.joint_structure = self._joint_structure_cache
        return self._joint_structure_cache

    def get_joint_names(self):
        """Return list of joint names for active joints."""
        if self._joint_names_cache is not None:
            return self._joint_names_cache

        self._joint_names_cache = [
            j["name"] for j in self.get_active_joints()
        ]
        self.joint_names = self._joint_names_cache
        return self._joint_names_cache

    def get_num_act_joints(self) -> int:
        """Return the number of active joints."""
        return len(self.get_active_joints())

    # =========================================================
    # JOINT LIMITS
    # =========================================================

    def get_joint_limits(self):
        """
        Return (q_min, q_max) lists for all active joints.
        Continuous joints get (-inf, +inf).
        Cached after first call.
        """
        if self._joint_limits_cache is not None:
            return self._joint_limits_cache

        q_min, q_max = [], []

        for joint in self.get_active_joints():

            if joint["is_continuous"]:
                q_min.append(-float("inf"))
                q_max.append( float("inf"))
            else:
                lower, upper = joint["limit"]
                q_min.append(lower if lower is not None else -float("inf"))
                q_max.append(upper if upper is not None else  float("inf"))

        self._joint_limits_cache = (q_min, q_max)
        return self._joint_limits_cache

    # =========================================================
    # LINK NAMES
    # =========================================================

    def get_link_names(self):
        """Return all link names in the URDF."""
        if self._link_names_cache is not None:
            return self._link_names_cache

        self._link_names_cache = [
            link.get("name")
            for link in self.root.findall("link")
        ]
        return self._link_names_cache

    def _assert_link_exists(self, link_name: str):
        if link_name not in self.get_link_names():
            raise ValueError(
                f"Link '{link_name}' not found in URDF. "
                f"Available: {self.get_link_names()}"
            )

    # =========================================================
    # KINEMATIC CHAIN
    # =========================================================

    def build_chain(self, base_link: str, end_link: str):
        """
        Build the ordered list of joints from base_link to end_link
        by traversing the parent-child tree backwards from end_link.

        Validates that both links exist before traversal.
        Detects loops in the kinematic chain.
        """
        self._assert_link_exists(base_link)
        self._assert_link_exists(end_link)

        joints  = self.get_joints()
        chain   = []
        current = end_link
        visited = set()

        while current != base_link:

            if current in visited:
                raise RuntimeError(
                    f"Loop detected in kinematic chain at link: {current}"
                )

            visited.add(current)
            found = False

            for joint in joints:
                if joint["child"] == current:
                    chain.insert(0, joint)
                    current = joint["parent"]
                    found   = True
                    break

            if not found:
                raise RuntimeError(
                    f"Broken kinematic chain: cannot find parent of '{current}'. "
                    f"Check that '{base_link}' is an ancestor of '{end_link}'."
                )

        return chain

    # =========================================================
    # METADATA
    # =========================================================

    def get_joint_metadata(self):
        """Return full metadata list for all active joints."""
        return self.get_active_joints()

    # =========================================================
    # CACHE INVALIDATION
    # =========================================================

    def invalidate_cache(self):
        """
        Force re-parse on next access.
        Useful if the URDF source is modified at runtime.
        """
        self._joints_cache          = None
        self._active_joints_cache   = None
        self._joint_names_cache     = None
        self._joint_structure_cache = None
        self._joint_limits_cache    = None
        self._link_names_cache      = None

    # PLANNING GROUP chain-scoped helpers
    def get_active_joints_in_chain(self, base_link: str, end_link: str):
        chain = self.build_chain(base_link, end_link)
        return [j for j in chain if self._is_active(j["type"])]

    def get_joint_names_in_chain(self, base_link: str, end_link: str):
        return [j["name"] for j in self.get_active_joints_in_chain(base_link, end_link)]

    def get_num_act_joints_in_chain(self, base_link: str, end_link: str) -> int:
        return len(self.get_active_joints_in_chain(base_link, end_link))

    def get_joint_limits_in_chain(self, base_link: str, end_link: str):
        q_min, q_max = [], []
        for j in self.get_active_joints_in_chain(base_link, end_link):
            if j["is_continuous"]:
                q_min.append(-float("inf")); q_max.append(float("inf"))
            else:
                lo, hi = j["limit"]
                q_min.append(lo if lo is not None else -float("inf"))
                q_max.append(hi if hi is not None else  float("inf"))
        return q_min, q_max