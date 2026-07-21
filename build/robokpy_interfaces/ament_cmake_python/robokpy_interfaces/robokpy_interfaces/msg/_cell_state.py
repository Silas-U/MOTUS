# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robokpy_interfaces:msg/CellState.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CellState(type):
    """Metaclass of message 'CellState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'IDLE': 0,
        'PLANNING': 1,
        'EXECUTING': 2,
        'PAUSED': 3,
        'ERROR': 4,
        'ESTOP': 5,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robokpy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robokpy_interfaces.msg.CellState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cell_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cell_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cell_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cell_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cell_state

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'IDLE': cls.__constants['IDLE'],
            'PLANNING': cls.__constants['PLANNING'],
            'EXECUTING': cls.__constants['EXECUTING'],
            'PAUSED': cls.__constants['PAUSED'],
            'ERROR': cls.__constants['ERROR'],
            'ESTOP': cls.__constants['ESTOP'],
        }

    @property
    def IDLE(self):
        """Message constant 'IDLE'."""
        return Metaclass_CellState.__constants['IDLE']

    @property
    def PLANNING(self):
        """Message constant 'PLANNING'."""
        return Metaclass_CellState.__constants['PLANNING']

    @property
    def EXECUTING(self):
        """Message constant 'EXECUTING'."""
        return Metaclass_CellState.__constants['EXECUTING']

    @property
    def PAUSED(self):
        """Message constant 'PAUSED'."""
        return Metaclass_CellState.__constants['PAUSED']

    @property
    def ERROR(self):
        """Message constant 'ERROR'."""
        return Metaclass_CellState.__constants['ERROR']

    @property
    def ESTOP(self):
        """Message constant 'ESTOP'."""
        return Metaclass_CellState.__constants['ESTOP']


class CellState(metaclass=Metaclass_CellState):
    """
    Message class 'CellState'.

    Constants:
      IDLE
      PLANNING
      EXECUTING
      PAUSED
      ERROR
      ESTOP
    """

    __slots__ = [
        '_state',
        '_active_recipe_id',
        '_last_error',
        '_stamp',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'state': 'uint8',
        'active_recipe_id': 'string',
        'last_error': 'string',
        'stamp': 'builtin_interfaces/Time',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state = kwargs.get('state', int())
        self.active_recipe_id = kwargs.get('active_recipe_id', str())
        self.last_error = kwargs.get('last_error', str())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.state != other.state:
            return False
        if self.active_recipe_id != other.active_recipe_id:
            return False
        if self.last_error != other.last_error:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def active_recipe_id(self):
        """Message field 'active_recipe_id'."""
        return self._active_recipe_id

    @active_recipe_id.setter
    def active_recipe_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'active_recipe_id' field must be of type 'str'"
        self._active_recipe_id = value

    @builtins.property
    def last_error(self):
        """Message field 'last_error'."""
        return self._last_error

    @last_error.setter
    def last_error(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'last_error' field must be of type 'str'"
        self._last_error = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if self._check_fields:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value
