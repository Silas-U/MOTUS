"""
mp_waypoints.py  —  WaypointManager

Pure data management for waypoints and motion segments. No ROS, no
kinematics, no trajectory logic. Completely unit-testable.
"""

import copy
import numpy as np
from typing import List, Optional, Dict

from .mp_types import JointWaypoint, CartesianWaypoint, Waypoint, MotionSegment


class WaypointManager:
    def __init__(self, logger):
        self._logger = logger
        self._waypoints: List[Waypoint] = []
        self._segments: List[MotionSegment] = []
        self._counter = 0

    # ------------------------------------------------------------------
    # Accessors
    # ------------------------------------------------------------------
    @property
    def waypoints(self) -> List[Waypoint]:
        return list(self._waypoints)

    @property
    def segments(self) -> List[MotionSegment]:
        return list(self._segments)

    def get(self, wp_id: str) -> Optional[Waypoint]:
        return next((wp for wp in self._waypoints if wp.id == wp_id), None)

    def index_of(self, wp_id: str) -> int:
        for i, wp in enumerate(self._waypoints):
            if wp.id == wp_id:
                return i
        return -1

    # ------------------------------------------------------------------
    # Mutations
    # ------------------------------------------------------------------
    def add(self, waypoint: Waypoint) -> str:
        """Append a waypoint. If it closes a segment, create the segment."""
        wp_id = waypoint.id or f'wp_{self._counter:03d}'
        self._counter += 1

        # Re-instantiate with guaranteed ID
        if isinstance(waypoint, JointWaypoint):
            wp = JointWaypoint(q=waypoint.q, id=wp_id)
        else:
            wp = CartesianWaypoint(pose=waypoint.pose, id=wp_id)

        if len(self._waypoints) > 0:
            prev = self._waypoints[-1]
            seg = MotionSegment(
                start_id=prev.id,
                end_id=wp.id,
            )
            self._segments.append(seg)
            self._logger.info(
                f'Segment: {prev.id} -> {wp.id}'
            )
        self._waypoints.append(wp)
        return wp.id

    def add_with_config(self, waypoint: Waypoint, config) -> str:
        """Add waypoint and tag the new segment with a config copy."""
        wp_id = self.add(waypoint)
        if self._segments:
            seg = self._segments[-1]
            seg.mode = config.traj_method
            seg.traj_type = config.traj_type
            seg.blend_radius = config.blend_radius
            seg.speed_factor = config.speed_factor
            seg.duration_per_segment = config.duration_per_segment
            seg.n_samples = config.n_samples
            seg.n_blend = config.n_blend
            seg.dt = config.dt
        return wp_id

    def delete(self, wp_id: str) -> bool:
        idx = self.index_of(wp_id)
        if idx < 0:
            self._logger.warn(f'Waypoint {wp_id} not found')
            return False

        incoming = next((s for s in self._segments if s.end_id == wp_id), None)
        outgoing = next((s for s in self._segments if s.start_id == wp_id), None)

        # Remove all segments touching this waypoint
        self._segments = [
            s for s in self._segments
            if s.start_id != wp_id and s.end_id != wp_id
        ]

        # Bridge if there were segments on both sides
        if incoming and outgoing:
            bridge = MotionSegment(
                start_id=incoming.start_id,
                end_id=outgoing.end_id,
                mode=outgoing.mode,
                traj_type=outgoing.traj_type,
                blend_radius=outgoing.blend_radius,
                speed_factor=outgoing.speed_factor,
                duration_per_segment=outgoing.duration_per_segment,
                n_samples=outgoing.n_samples,
                n_blend=outgoing.n_blend,
                dt=outgoing.dt,
            )
            self._segments.append(bridge)
            self._logger.info(f'Bridged: {bridge.start_id} -> {bridge.end_id}')

        self._waypoints.pop(idx)
        self._logger.info(f'Deleted waypoint {wp_id}')
        return True

    def clear(self):
        self._waypoints.clear()
        self._segments.clear()
        self._counter = 0

    # ------------------------------------------------------------------
    # Introspection
    # ------------------------------------------------------------------
    def summary(self) -> str:
        lines = [f'--- Waypoints ({len(self._waypoints)}) ---']
        for wp in self._waypoints:
            if isinstance(wp, JointWaypoint):
                lines.append(f'  {wp.id}  joints=[{", ".join(f"{v:.3f}" for v in wp.q)}]')
            else:
                lines.append(f'  {wp.id}  pos=[{wp.pose[0]:.3f}, {wp.pose[1]:.3f}, {wp.pose[2]:.3f}]')
        lines.append(f'--- Segments ({len(self._segments)}) ---')
        for seg in self._segments:
            cached = '[cached]' if seg.cached else ''
            lines.append(
                f'  {seg.start_id} -> {seg.end_id}  '
                f'[{seg.mode}/{seg.traj_type}  '
                f'spd={seg.speed_factor:.2f}  '
                f'blend={seg.blend_radius:.2f}] {cached}'
            )
        return "\n".join(lines)
