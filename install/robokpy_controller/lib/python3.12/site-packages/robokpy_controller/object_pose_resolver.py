"""
object_pose_resolver — matches a vision-detected position to a
specific, currently-spawned catalog instance.

This is the missing link between VisionStep's detected_pose (a raw
position, no identity) and GraspAttach.srv's child_model/child_link
(a name, no position): given a position, find which known catalog
instance is physically there right now.

Live position source: /world/motus_world/dynamic_pose/info, published
natively by the SceneBroadcaster system (already loaded in
motus_world.sdf) as gz.msgs.Pose_V. Bridged here to tf2_msgs/msg/
TFMessage rather than geometry_msgs/msg/PoseArray — PoseArray entries
carry no per-entity name (confirmed against ros_gz_bridge's own
type-mapping table), so there'd be no way to tell WHICH pose belongs
to WHICH object. TFMessage's child_frame_id carries the entity name.

UNVERIFIED / NEEDS CHECKING ON YOUR SYSTEM: there's a history of
reported bugs (gazebosim/ros_gz#172, and similar) where child_frame_id
came through empty on this exact Pose_V -> TFMessage bridge in older
versions. Before trusting this node, confirm with:
    ros2 topic echo /world/motus_world/dynamic_pose/info
that child_frame_id is actually populated with model names. If it's
empty on your version, this whole approach needs a fallback (e.g.
bridging pose/info as PoseArray plus a separate name-ordering
assumption — fragile — or a custom bridge node using gz-transport
Python bindings directly instead of parameter_bridge).

Only tracks entities whose name matches a catalog instance (via
ObjectCatalog.lookup_by_model) — robot links and anything else in the
TF stream are silently ignored, not an error.

Nearest-match only considers position (see ResolveObjectPose.srv
docstring for why orientation is deliberately excluded), and requires
the caller to supply max_distance explicitly — this is the actual
mechanism protecting against the "stacked objects" mismatch discussed
earlier: too generous a threshold risks matching the wrong instance
sitting underneath/above the intended one.
"""

import math

import rclpy
from rclpy.node import Node
from tf2_msgs.msg import TFMessage

from robokpy_interfaces.srv import ResolveObjectPose

from .object_catalog import ObjectCatalog


class ObjectPoseResolver(Node):

    def __init__(self):
        super().__init__('object_pose_resolver')

        self.declare_parameter('objects_config_path', '')
        objects_config_path = self.get_parameter('objects_config_path').value
        if not objects_config_path:
            raise RuntimeError(
                'object_pose_resolver requires the objects_config_path '
                'parameter (path to objects.yaml) — none was provided')

        self._catalog = ObjectCatalog(objects_config_path)

        # child_model -> (x, y, z), most recent known position only.
        # Not persisted — rebuilt continuously from the live TF stream.
        self._live_positions: dict = {}

        self.create_subscription(
            TFMessage, '/world/motus_world/dynamic_pose/info',
            self._on_tf, 10)

        self.create_service(
            ResolveObjectPose, 'resolve_object_pose', self._handle_resolve)

        self.get_logger().info(
            f'object_pose_resolver ready — tracking up to '
            f'{len(self._catalog.all_instances())} possible catalog instances')

    def _on_tf(self, msg: TFMessage):
        for transform in msg.transforms:
            child_model = transform.child_frame_id
            if not child_model:
                continue
            try:
                self._catalog.lookup_by_model(child_model)
            except KeyError:
                continue  # not a catalog object (robot link, etc.) — ignore

            t = transform.transform.translation
            self._live_positions[child_model] = (t.x, t.y, t.z)

    def _handle_resolve(self, request, response):
        if not self._live_positions:
            response.success = False
            response.child_model = ''
            response.child_link = ''
            response.distance = 0.0
            response.message = (
                'No catalog instances currently visible on the live pose '
                'stream — is anything spawned? Is child_frame_id populated '
                '(see module docstring)?')
            self.get_logger().warn(response.message)
            return response

        best_model = None
        best_dist = float('inf')
        for child_model, (x, y, z) in self._live_positions.items():
            dist = math.sqrt(
                (x - request.x) ** 2 +
                (y - request.y) ** 2 +
                (z - request.z) ** 2)
            if dist < best_dist:
                best_dist = dist
                best_model = child_model

        if best_dist > request.max_distance:
            response.success = False
            response.child_model = ''
            response.child_link = ''
            response.distance = best_dist
            response.message = (
                f'Nearest instance "{best_model}" is {best_dist:.4f}m away, '
                f'exceeding max_distance={request.max_distance:.4f}m')
            self.get_logger().warn(response.message)
            return response

        inst = self._catalog.lookup_by_model(best_model)
        response.success = True
        response.child_model = best_model
        response.child_link = inst.child_link
        response.distance = best_dist
        response.message = f'Matched "{best_model}" at {best_dist:.4f}m'
        self.get_logger().info(response.message)
        return response


def main(args=None):
    rclpy.init(args=args)
    node = ObjectPoseResolver()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()