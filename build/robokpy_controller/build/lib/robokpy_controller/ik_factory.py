"""Factory for building Init_Model with an injectable IK backend."""
import importlib
import logging
from robokpy import Init_Model

_logger = logging.getLogger('ik_factory')


def build_model(robot_description: str, base_link: str, tip_link: str,
                backend: str = 'robokpy', **backend_kwargs):
    """Build an Init_Model using the specified IK backend.

    Args:
        robot_description: URDF string.
        base_link:  root link name.
        tip_link:   end-effector link name.
        backend:    'robokpy' | 'trac_ik' | 'pinocchio' | ...
        **backend_kwargs: passed to backend.initialize().

    Returns:
        Init_Model instance with .ik set to the chosen backend.
    """
    if backend == 'robokpy':
        # Fast path — no adapter overhead.
        return Init_Model(robot_description, base_link=base_link, tip_link=tip_link)

    # Dynamic backend loading
    module_name = f'robokpy_controller.ik_backends.{backend}_backend'
    class_name = ''.join(
        p.capitalize() for p in backend.split('_')
    ) + 'Backend'

    try:
        module = importlib.import_module(module_name)
        BackendClass = getattr(module, class_name)
    except (ImportError, ModuleNotFoundError, AttributeError) as e:
        _logger.warning(
            f"Backend '{backend}' unavailable ({e}). "
            f"Falling back to 'robokpy'."
            f"  To install Pinocchio:  pip install pin"
            f"  To install Trac-IK:    pip install trac-ik-python  "
            f"(or build from source on ROS 2 Jazzy)"
        )
        return Init_Model(robot_description, base_link=base_link, tip_link=tip_link)

    ik_backend = BackendClass()
    ik_backend.initialize(robot_description, base_link, tip_link, **backend_kwargs)

    return Init_Model(
        robot_description,
        base_link=base_link,
        tip_link=tip_link,
        ik=ik_backend,
    )
