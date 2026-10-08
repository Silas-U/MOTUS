"""
grasp_attach_bridge — implements GraspAttach.srv on top of native
gz-sim DetachableJoint plugins.

Each catalog instance (see object_catalog.py) has its own pre-wired
DetachableJoint plugin in the robot's URDF, with a unique attach_topic
and detach_topic. Those topics are bridged to ROS2 by ros_gz_bridge's
parameter_bridge (see ObjectCatalog.to_ros_gz_bridge_args(), used in
the launch file) — this node just needs to publish std_msgs/Empty on
the right ROS-side topic name for whichever child_model a request
names.

GraspAttach.srv's `joint_id` field comes from the OLD custom
GraspAttachPlugin design and has no equivalent in native DetachableJoint
(which has no numeric handle — only named topics). Rather than change
the .srv or GraspAttachBackend (already built, already working against
this contract), this node fabricates its own joint_id: an incrementing
counter mapped internally to (child_model, child_link). Attach assigns
one and returns it; detach looks it up to find which topic to publish
to.

HONEST LIMITATION: publishing an Empty message to a DetachableJoint's
attach/detach topic has no acknowledgement channel — there's no way to
confirm the physical weld actually happened before returning success.
This node reports success once the message is published, not once
physically attached. If a later verification step is wanted (e.g.
polling the child model's pose to confirm it started moving with the
parent), that needs a separate mechanism — not attempted here.
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import Empty

from robokpy_interfaces.srv import GraspAttach

from .object_catalog import ObjectCatalog


class GraspAttachBridge(Node):

    def __init__(self):
        super().__init__('grasp_attach_bridge')

        self.declare_parameter('objects_config_path', '')
        objects_config_path = self.get_parameter('objects_config_path').value
        if not objects_config_path:
            raise RuntimeError(
                'grasp_attach_bridge requires the objects_config_path parameter '
                '(path to objects.yaml) — none was provided')

        self._catalog = ObjectCatalog(objects_config_path)

        # Multi-arm cells: one DetachableJoint set per arm, topics keyed
        # by arm namespace. Empty = single-arm legacy topics.
        self.declare_parameter('arms', [''])
        self._arms = [a for a in self.get_parameter('arms').value if a]
        arm_keys = self._arms or ['']

        # Pre-create one attach + one detach publisher per catalog
        # instance — bounded set, known at startup, no need to create
        # publishers dynamically per-request.
        self._attach_pubs = {}
        self._detach_pubs = {}
        for arm in arm_keys:
            for inst in self._catalog.all_instances():
                self._attach_pubs[(arm, inst.child_model)] = self.create_publisher(
                    Empty, self._catalog.attach_topic(inst.child_model, arm), 10)
                self._detach_pubs[(arm, inst.child_model)] = self.create_publisher(
                    Empty, self._catalog.detach_topic(inst.child_model, arm), 10)

        # joint_id bookkeeping — see module docstring. Not persisted;
        # resets on node restart, matching sim's own reset-on-relaunch
        # semantics.
        self._next_joint_id = 1
        self._active_joints: dict = {}  # joint_id -> (arm, child_model, child_link)

        self._srv = self.create_service(
            GraspAttach, 'grasp_attach', self._handle_request)

        self.get_logger().info(
            f'grasp_attach_bridge ready — {len(self._attach_pubs)} attach '
            f'channels (arms={self._arms or "single"}) loaded from '
            f'{objects_config_path}')

    def _arm_for(self, parent_model: str) -> str:
        """Map a request's parent_model ('arm2_robot' or 'arm2') to an arm
        namespace. Single-arm cells always resolve to ''."""
        if not self._arms:
            return ''
        name = parent_model[:-len('_robot')] if parent_model.endswith('_robot') else parent_model
        if name in self._arms:
            return name
        self.get_logger().warn(
            f'grasp_attach parent_model "{parent_model}" matches no arm in '
            f'{self._arms} — using "{self._arms[0]}"')
        return self._arms[0]

    def _handle_request(self, request, response):
        if self._arms:
            pass  # parent_model selects the arm; catalog name is not compared
        elif request.parent_model and request.parent_model != self._catalog.parent_model:
            self.get_logger().warn(
                f'grasp_attach request parent_model "{request.parent_model}" '
                f'does not match catalog parent_model "{self._catalog.parent_model}" '
                f'— proceeding anyway, topics are keyed by child_model only')

        if request.attach:
            return self._handle_attach(request, response)
        else:
            return self._handle_detach(request, response)

    def _handle_attach(self, request, response):
        child_model = request.child_model
        arm = self._arm_for(request.parent_model)
        if not child_model or (arm, child_model) not in self._attach_pubs:
            response.success = False
            response.message = f'Unknown child_model "{child_model}" — not in catalog'
            response.joint_id = 0
            self.get_logger().error(response.message)
            return response

        # Idempotency guard: a retry after a lost response (not a lost
        # attach — see orchestrator.py's epoch/watchdog docstring) would
        # otherwise re-publish attach and leak a second, never-detached
        # joint_id for the same child_model.
        for existing_id, (existing_arm, existing_model, _l) in self._active_joints.items():
            if existing_model == child_model and existing_arm != arm:
                response.success = False
                response.message = (
                    f'"{child_model}" is already held by arm "{existing_arm}" '
                    f'(joint_id={existing_id}) — detach it before "{arm}" grasps it')
                response.joint_id = 0
                self.get_logger().error(response.message)
                return response
            if existing_model == child_model:
                response.success = True
                response.message = (
                    f'"{child_model}" already attached (joint_id={existing_id}) '
                    f'— treating as idempotent, not re-publishing attach')
                response.joint_id = existing_id
                self.get_logger().info(response.message)
                return response

        try:
            inst = self._catalog.lookup_by_model(child_model)
        except KeyError as e:
            response.success = False
            response.message = str(e)
            response.joint_id = 0
            return response

        if request.child_link and request.child_link != inst.child_link:
            self.get_logger().warn(
                f'grasp_attach request child_link "{request.child_link}" for '
                f'"{child_model}" does not match catalog child_link '
                f'"{inst.child_link}" — publishing anyway, the DetachableJoint '
                f'plugin was generated with the catalog value, not this one')

        self._attach_pubs[(arm, child_model)].publish(Empty())

        joint_id = self._next_joint_id
        self._next_joint_id += 1
        self._active_joints[joint_id] = (arm, child_model, inst.child_link)

        response.success = True
        response.message = f'Published attach for "{child_model}" (joint_id={joint_id})'
        response.joint_id = joint_id
        self.get_logger().info(response.message)
        return response

    def _handle_detach(self, request, response):
        joint_id = request.joint_id
        if joint_id not in self._active_joints:
            response.success = False
            response.message = f'No active joint with joint_id={joint_id}'
            response.joint_id = 0
            self.get_logger().error(response.message)
            return response

        arm, child_model, _child_link = self._active_joints.pop(joint_id)
        self._detach_pubs[(arm, child_model)].publish(Empty())

        response.success = True
        response.message = f'Published detach for "{child_model}" (joint_id={joint_id})'
        response.joint_id = joint_id
        self.get_logger().info(response.message)
        return response


def main(args=None):
    rclpy.init(args=args)
    node = GraspAttachBridge()
    try:
        rclpy.spin(node)
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()