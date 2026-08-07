"""
object_spawner — dynamic per-recipe spawn/despawn of catalog object
instances into the running Gazebo world.

Wraps the STANDARD ros_gz_interfaces SpawnEntity/DeleteEntity services
(bridged from /world/<world>/create and /world/<world>/remove — see
launch file) with catalog-aware business logic: given a TYPE id (e.g.
"cube_small"), find a free instance slot, generate its SDF via
ObjectCatalog.instance_model_sdf(), spawn it under its catalog-assigned
child_model name, and track which instances are currently in use so
the same slot isn't double-spawned. This node does NOT invent its own
low-level spawn mechanism — /world/<world>/create + UserCommands (both
already used/available per motus_world.sdf) do the real work.

NEW INTERFACES NEEDED — not yet added to robokpy_interfaces. These
.srv definitions need creating there (and the package rebuilt) before
this node will compile/run:

  SpawnObject.srv:
    string type_id
    float64 x
    float64 y
    float64 z
    float64 qx
    float64 qy
    float64 qz
    float64 qw
    string color    # optional visual material (named, hex, or RGB)
    ---
    bool success
    string message
    string child_model

  DespawnObject.srv:
    string child_model
    ---
    bool success
    string message

REENTRANCY NOTE: each of our service callbacks below makes an async
call to another service (SpawnEntity/DeleteEntity) and needs to wait
for its result before responding. Doing that with the default
single-threaded executor deadlocks — the callback blocks waiting for a
future that only the (already-blocked) executor thread could resolve.
Fixed here by using a ReentrantCallbackGroup for both our services AND
requiring a MultiThreadedExecutor in main() — a second thread is then
free to process the sub-call's response while the first blocks. Not
a workaround, this is the standard rclpy pattern for this situation.

UNVERIFIED: ros_gz_interfaces/msg/Entity's MODEL type constant is used
below as `Entity.MODEL` — this needs confirming against the installed
ros_gz_interfaces version (field name may differ slightly).
"""

import threading
import time

import rclpy
from rclpy.node import Node
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Pose
from std_msgs.msg import Empty, String

from ros_gz_interfaces.srv import SpawnEntity, DeleteEntity
from ros_gz_interfaces.msg import Entity as GzEntity

from robokpy_interfaces.srv import SpawnObject, DespawnObject

from .object_catalog import ObjectCatalog


class ObjectSpawner(Node):

    def __init__(self):
        super().__init__('object_spawner')

        self.declare_parameter('objects_config_path', '')
        self.declare_parameter('world_name', 'motus_world')
        objects_config_path = self.get_parameter('objects_config_path').value
        world_name = self.get_parameter('world_name').value
        if not objects_config_path:
            raise RuntimeError(
                'object_spawner requires the objects_config_path parameter '
                '(path to objects.yaml) — none was provided')

        self._catalog = ObjectCatalog(objects_config_path)

        # child_model -> type_id, for currently-spawned instances only.
        # Not persisted — resets on node restart, matching sim's own
        # reset-on-relaunch semantics (same as grasp_attach_bridge).
        self._in_use: dict = {}
        # Guards every read/write of _in_use. Both service handlers
        # below span a multi-second blocking round-trip (SpawnEntity/
        # DeleteEntity + attach-confirm waits) between checking _in_use
        # and finalizing it, and ReentrantCallbackGroup +
        # MultiThreadedExecutor(num_threads=8) means two spawn/despawn
        # requests can genuinely run that gap concurrently. The lock is
        # only ever held for the bookkeeping itself (reserve, roll back,
        # restore) — never across the blocking network calls, same rule
        # as orchestrator.py's DAG lock.
        self._lock = threading.Lock()

        # DetachableJoint plugins are pre-wired onto the robot for every
        # catalog instance (see ObjectCatalog.to_gazebo_plugin_sdf()) and
        # — on this installed gz-sim version (8.6.0, confirmed via its
        # own source) — default to attachRequested=true, meaning they
        # auto-attach the instant their child_model appears in the
        # world, with NO attach_topic message required.
        #
        # A detach published before that auto-attach has actually run
        # is a silent no-op (confirmed in DetachableJoint.cc:
        # OnDetachRequest returns early if !isAttached, without
        # remembering the request) — so a blind "detach right after
        # spawn, then sleep" can lose the race and leave the instance
        # permanently welded. Instead we wait for the plugin's own
        # state topic to confirm "attached" before detaching — see
        # ObjectCatalog.state_topic() for why that topic is safe to
        # rely on (it's the plugin's own default output, not something
        # we're inferring).
        self._attach_confirmed: dict = {}   # child_model -> threading.Event
        self._detach_pubs = {}
        for inst in self._catalog.all_instances():
            self._attach_confirmed[inst.child_model] = threading.Event()
            self._detach_pubs[inst.child_model] = self.create_publisher(
                Empty, self._catalog.detach_topic(inst.child_model), 10)
            self.create_subscription(
                String, self._catalog.state_topic(inst.child_model),
                self._make_state_cb(inst.child_model), 10,
                callback_group=ReentrantCallbackGroup())

        cb_group = ReentrantCallbackGroup()

        self._create_client = self.create_client(
            SpawnEntity, f'/world/{world_name}/create', callback_group=cb_group)
        self._remove_client = self.create_client(
            DeleteEntity, f'/world/{world_name}/remove', callback_group=cb_group)

        self.create_service(
            SpawnObject, 'spawn_object', self._handle_spawn,
            callback_group=cb_group)
        self.create_service(
            DespawnObject, 'despawn_object', self._handle_despawn,
            callback_group=cb_group)

        self.get_logger().info(
            f'object_spawner ready — world="{world_name}", '
            f'{len(self._catalog.all_instances())} possible instances '
            f'across {len(self._catalog.types)} types')

    @staticmethod
    def _wait_for_clear(event: threading.Event, timeout: float) -> bool:
        """threading.Event only has wait-for-set built in; this polls
        for the inverse (wait-for-clear), used to confirm a detach
        landed. Short timeout, coarse poll — this is a confirmation
        check, not a hot path."""
        deadline = time.monotonic() + timeout
        while time.monotonic() < deadline:
            if not event.is_set():
                return True
            time.sleep(0.02)
        return not event.is_set()

    def _make_state_cb(self, child_model: str):
        """Returns a callback bound to one catalog instance's state
        topic. Sets the instance's Event on a real "attached"
        confirmation from the plugin itself, clears it on "detached" —
        this is what lets _handle_spawn wait for a genuine attach
        instead of racing a blind sleep against it."""
        def _cb(msg: String):
            ev = self._attach_confirmed[child_model]
            if msg.data == 'attached':
                ev.set()
            elif msg.data == 'detached':
                ev.clear()
        return _cb

    @staticmethod
    def _wait_for_future(future, timeout_sec: float) -> bool:
        """Correct replacement for
        rclpy.spin_until_future_complete(self, future, executor=...) —
        that call deadlocks when invoked from inside a callback that's
        already running on the executor passed to it (or even on the
        node's own default executor with none passed): re-entering an
        executor's own wait-set processing from a thread it's already
        using to run this callback is unsafe, REGARDLESS of whether
        it's the same executor instance or a freshly-created one.
        Confirmed by hitting this as a real, consistent deadlock on
        despawn (never on spawn, purely by scheduling luck — same bug,
        both call sites had it).

        This just polls future.done() instead. No spinning happens
        here at all — the OTHER executor threads (we run with
        num_threads=8, see main()) independently process the
        service response and resolve the future in the background;
        this thread only checks and sleeps, never touching the
        executor's wait-set itself."""
        start = time.monotonic()
        while not future.done() and time.monotonic() - start < timeout_sec:
            time.sleep(0.01)
        return future.done()

    def _free_instance(self, type_id: str):
        """First not-currently-spawned instance name of type_id, or
        None if every slot in the bounded pool is in use."""
        if type_id not in self._catalog.types:
            return None
        max_n = self._catalog.types[type_id].max_instances
        for i in range(1, max_n + 1):
            name = self._catalog.instance_name(type_id, i)
            if name not in self._in_use:
                return name
        return None

    def _handle_spawn(self, request, response):
        if request.type_id not in self._catalog.types:
            response.success = False
            response.message = f'Unknown object type "{request.type_id}"'
            response.child_model = ''
            return response

        # Find a free slot AND reserve it in the same locked step. Doing
        # this in two steps (as the original code did, reserving only on
        # success at the bottom) leaves the entire multi-second spawn
        # round-trip below as an unguarded window — a second concurrent
        # request for the same type_id would see the same slot as
        # "free" and spawn the identical child_model into Gazebo.
        with self._lock:
            child_model = self._free_instance(request.type_id)
            if child_model is not None:
                self._in_use[child_model] = request.type_id

        if child_model is None:
            max_n = self._catalog.types[request.type_id].max_instances
            response.success = False
            response.message = (
                f'No free instance slot for type "{request.type_id}" — '
                f'all {max_n} catalog instances are currently in use')
            response.child_model = ''
            self.get_logger().warn(response.message)
            return response

        inst = self._catalog.lookup_by_model(child_model)
        sdf = self._catalog.instance_model_sdf(inst, request.color)

        if not self._create_client.wait_for_service(timeout_sec=20.0):
            with self._lock:
                del self._in_use[child_model]  # release the reservation — spawn never happened
            response.success = False
            response.message = f'/world/.../create service unavailable'
            response.child_model = ''
            self.get_logger().error(response.message)
            return response

        req = SpawnEntity.Request()
        req.entity_factory.name = child_model
        req.entity_factory.sdf = sdf
        req.entity_factory.allow_renaming = False  # fail clearly on name collision, don't silently rename
        req.entity_factory.pose = Pose()
        req.entity_factory.pose.position.x = request.x
        req.entity_factory.pose.position.y = request.y
        req.entity_factory.pose.position.z = request.z
        req.entity_factory.pose.orientation.x = request.qx
        req.entity_factory.pose.orientation.y = request.qy
        req.entity_factory.pose.orientation.z = request.qz
        req.entity_factory.pose.orientation.w = request.qw

        future = self._create_client.call_async(req)
        self._wait_for_future(future, timeout_sec=5.0)

        if future.result() is None or not future.result().success:
            with self._lock:
                del self._in_use[child_model]  # release the reservation — spawn failed
            response.success = False
            response.message = f'SpawnEntity call failed for "{child_model}"'
            response.child_model = ''
            self.get_logger().error(response.message)
            return response

        # Reservation already made above, before the spawn call — no
        # further self._in_use bookkeeping needed on this success path.

        # Undo the auto-weld — see __init__ comment for why a blind
        # "detach then sleep" isn't safe: detach before the plugin's
        # own auto-attach has landed is silently dropped, not queued.
        # Wait for the plugin's own confirmation instead.
        attach_event = self._attach_confirmed[child_model]
        if not attach_event.wait(timeout=5.0):
            self.get_logger().warn(
                f'"{child_model}": no attach confirmation from '
                f'DetachableJoint within 5.0s — detaching anyway as a '
                f'best effort, but this instance may end up welded to '
                f'the gripper if the auto-attach lands after this point')
        self._detach_pubs[child_model].publish(Empty())

        # Confirm the detach itself actually landed too (Event.clear()
        # happens in _make_state_cb on a real "detached" message) —
        # best-effort: log if it doesn't confirm, don't fail the spawn
        # over it, since a stuck weld will surface immediately and
        # obviously in the very next motion leg rather than silently.
        if not self._wait_for_clear(attach_event, timeout=1.0):
            self.get_logger().warn(
                f'"{child_model}": no detach confirmation within 1.0s '
                f'after publishing — proceeding anyway')

        response.success = True
        response.message = f'Spawned "{child_model}" at ' \
                            f'({request.x}, {request.y}, {request.z})'
        response.child_model = child_model
        self.get_logger().info(response.message)
        return response

    def _handle_despawn(self, request, response):
        child_model = request.child_model
        # Pop (not just check) under the lock, right away — this makes
        # the check-and-claim atomic. A second concurrent despawn for
        # the same child_model then correctly falls into the "not
        # currently tracked" branch above instead of both threads
        # reaching `del self._in_use[child_model]` independently later,
        # where the second one hits a bare KeyError and crashes the
        # callback with no response ever sent to that client.
        with self._lock:
            if child_model not in self._in_use:
                response.success = False
                response.message = f'"{child_model}" is not currently tracked as spawned'
                self.get_logger().warn(response.message)
                return response
            type_id = self._in_use.pop(child_model)

        if not self._remove_client.wait_for_service(timeout_sec=20.0):
            with self._lock:
                self._in_use[child_model] = type_id  # restore — despawn never happened
            response.success = False
            response.message = '/world/.../remove service unavailable'
            self.get_logger().error(response.message)
            return response

        req = DeleteEntity.Request()
        req.entity = GzEntity()
        req.entity.name = child_model
        req.entity.type = GzEntity.MODEL  # confirmed valid (=2) against ros_gz_interfaces jazzy branch

        future = self._remove_client.call_async(req)
        if not self._wait_for_future(future, timeout_sec=5.0):
            with self._lock:
                self._in_use[child_model] = type_id  # restore — outcome unknown, treat as still spawned
            response.success = False
            response.message = f'DeleteEntity call for "{child_model}" timed out'
            self.get_logger().error(response.message)
            return response

        if future.result() is None or not future.result().success:
            with self._lock:
                self._in_use[child_model] = type_id  # restore — despawn failed
            response.success = False
            response.message = f'DeleteEntity call failed for "{child_model}"'
            self.get_logger().error(response.message)
            return response

        # Already popped from self._in_use above — genuinely gone now.
        response.success = True
        response.message = f'Despawned "{child_model}"'
        self.get_logger().info(response.message)
        return response


def main(args=None):
    rclpy.init(args=args)
    node = ObjectSpawner()
    # Explicit num_threads, NOT the bare default (which falls back to
    # os.cpu_count() — tying this node's correctness to whatever
    # machine happens to run it, which is exactly what caused a real
    # hang on a 2-core i3: _handle_spawn/_handle_despawn can each block
    # one thread for up to ~11s [5s attach-confirm wait + 5s
    # DeleteEntity/SpawnEntity response poll + 1s detach-confirm poll],
    # and while blocked they depend on at least one OTHER thread being
    # free to run the state-topic callback that resolves what they're
    # waiting
    # on, plus another for the underlying SpawnEntity/DeleteEntity
    # response itself. On a small core count, those can't all get a
    # thread at once and the request just queues forever — no error,
    # no log, since the callback body never starts. 8 gives comfortable
    # headroom for this node's actual reentrant callback count
    # (2 services + one state-topic subscription per catalog instance)
    # regardless of host hardware.
    executor = MultiThreadedExecutor(num_threads=8)
    executor.add_node(node)
    try:
        executor.spin()
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()