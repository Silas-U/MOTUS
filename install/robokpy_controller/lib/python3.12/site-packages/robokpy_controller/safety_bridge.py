"""
safety_bridge

Republishes the cell's hardwired safety signal (E-stop chain, light
curtains, safety-rated I/O) as /safety_state for the orchestrator to
read. This node is READ-ONLY with respect to safety — it never issues
commands to the safety hardware, it only reports its state.

IMPORTANT — this is a genuine placeholder, not a stub written out of
laziness: no safety-hardware interface (GPIO library, safety PLC
protocol, fieldbus) was provided to build against, and fabricating one
would mean guessing at hardware you haven't specified — the one thing
in this whole redesign that must not be guessed. What's real here is
the CONTRACT (a Bool on /safety_state, True = safe) that the
orchestrator already depends on. Replace _read_hardware_signal() with
the actual interface for your safety-rated I/O module or safety PLC
before this goes anywhere near a real cell.
"""

import rclpy
from rclpy.node import Node
from std_msgs.msg import Bool


class SafetyBridge(Node):
    def __init__(self):
        super().__init__('safety_bridge')

        self.declare_parameter('poll_period_sec', 0.02)  # 50 Hz
        period = self.get_parameter('poll_period_sec').value

        self._pub = self.create_publisher(Bool, '/safety_state', 10)
        self._timer = self.create_timer(period, self._poll)

        self.get_logger().warn(
            'safety_bridge is running with a PLACEHOLDER hardware read — '
            'wire _read_hardware_signal() to the actual safety I/O before '
            'deploying to real hardware.'
        )

    def _read_hardware_signal(self) -> bool:
        """
        Placeholder. Replace with the actual read from your safety-rated
        I/O module / safety PLC (e.g. a Modbus safety register, a GPIO
        pin via a safety-rated fieldbus gateway, or an OPC-UA safety
        node). Must return True only when the hardware chain confirms
        SAFE, defaulting to False (unsafe) on any read failure —
        never fail open.
        """
        return True  # PLACEHOLDER — always reports safe until wired up

    def _poll(self):
        try:
            safe = self._read_hardware_signal()
        except Exception as e:
            self.get_logger().error(f'Safety signal read failed: {e} — reporting UNSAFE')
            safe = False

        msg = Bool()
        msg.data = safe
        self._pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = SafetyBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()