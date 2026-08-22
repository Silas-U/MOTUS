"""
mp_viz.py  —  VizPublisher

All RViz marker publishing isolated in one place. No business logic.
"""

import numpy as np
from geometry_msgs.msg import Point
from visualization_msgs.msg import Marker
from builtin_interfaces.msg import Duration


class VizPublisher:
    def __init__(self, node, world_frame: str):
        self._node = node
        self._world = world_frame
        self.marker_pub = node.create_publisher(Marker, 'trajectory_marker', 10)
        self.ee_path_pub = node.create_publisher(Marker, 'ee_trajectory_marker', 10)

    def publish_waypoints(self, waypoints):
        marker = Marker()
        marker.header.frame_id = self._world
        marker.header.stamp = self._node.get_clock().now().to_msg()
        marker.type = Marker.SPHERE_LIST
        marker.id = 0
        marker.scale.x = 0.03
        marker.scale.y = 0.03
        marker.scale.z = 0.03
        marker.color.a = 1.0
        marker.color.r = 1.0
        marker.points = []
        for wp in waypoints:
            p = Point()
            if hasattr(wp, 'pose'):
                p.x, p.y, p.z = wp.pose[:3]
            else:
                # For JointWaypoint we don't have pose cached here;
                # caller should FK if needed. We skip or use cached pose.
                continue
            marker.points.append(p)
        self.marker_pub.publish(marker)

    def publish_ee_path(self, fk_path: list, frame_id: str = None,
                        marker_id: int = 100, dot_size: float = 0.008,
                        color=(0.0, 1.0, 0.0), alpha: float = 1.0,
                        lifetime: float = 0.0):
        frame_id = frame_id or self._world
        marker = Marker()
        marker.header.frame_id = frame_id
        marker.header.stamp = self._node.get_clock().now().to_msg()
        marker.ns = 'ee_trajectory'
        marker.id = marker_id
        marker.type = Marker.SPHERE_LIST
        marker.action = Marker.ADD
        marker.scale.x = dot_size
        marker.scale.y = dot_size
        marker.scale.z = dot_size
        marker.color.r = color[0]
        marker.color.g = color[1]
        marker.color.b = color[2]
        marker.color.a = alpha
        marker.lifetime = Duration(
            sec=int(lifetime), nanosec=int((lifetime % 1.0) * 1e9))
        for p in fk_path:
            pt = Point()
            pt.x, pt.y, pt.z = float(p[0]), float(p[1]), float(p[2])
            marker.points.append(pt)
        self.ee_path_pub.publish(marker)

    def clear_ee_path(self, marker_id: int = 100):
        marker = Marker()
        marker.header.frame_id = self._world
        marker.header.stamp = self._node.get_clock().now().to_msg()
        marker.ns = 'ee_trajectory'
        marker.id = marker_id
        marker.action = Marker.DELETE
        self.ee_path_pub.publish(marker)

    def clear_waypoints(self):
        marker = Marker()
        marker.header.frame_id = self._world
        marker.header.stamp = self._node.get_clock().now().to_msg()
        marker.action = Marker.DELETEALL
        self.marker_pub.publish(marker)
        self.ee_path_pub.publish(marker)
