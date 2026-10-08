"""Default Cyclone DDS settings for Motus.

A multi-arm cell runs ~45 ROS processes; Cyclone's default participant-index
range is too small and fails with "Failed to find a free participant index".
Every Motus entry point applies this default unless the user already set
CYCLONEDDS_URI (their value always wins).
"""
import os

CYCLONEDDS_URI = (
    '<CycloneDDS><Domain><Discovery><ParticipantIndex>auto</ParticipantIndex>'
    '<MaxAutoParticipantIndex>200</MaxAutoParticipantIndex>'
    '</Discovery></Domain></CycloneDDS>'
)


def apply_default():
    """Set CYCLONEDDS_URI in this process if the user hasn't."""
    os.environ.setdefault('CYCLONEDDS_URI', CYCLONEDDS_URI)
