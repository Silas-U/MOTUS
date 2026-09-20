# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robokpy_interfaces:action/ExecuteMoveStep.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'leg_blend_radii'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ExecuteMoveStep_Goal(type):
    """Metaclass of message 'ExecuteMoveStep_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__goal

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_Goal(metaclass=Metaclass_ExecuteMoveStep_Goal):
    """Message class 'ExecuteMoveStep_Goal'."""

    __slots__ = [
        '_leg_step_ids',
        '_leg_target_poses',
        '_leg_traj_methods',
        '_leg_traj_types',
        '_leg_blend_radii',
        '_speed_scale',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'leg_step_ids': 'sequence<string>',
        'leg_target_poses': 'sequence<geometry_msgs/Pose>',
        'leg_traj_methods': 'sequence<string>',
        'leg_traj_types': 'sequence<string>',
        'leg_blend_radii': 'sequence<double>',
        'speed_scale': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
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
        self.leg_step_ids = kwargs.get('leg_step_ids', [])
        self.leg_target_poses = kwargs.get('leg_target_poses', [])
        self.leg_traj_methods = kwargs.get('leg_traj_methods', [])
        self.leg_traj_types = kwargs.get('leg_traj_types', [])
        self.leg_blend_radii = array.array('d', kwargs.get('leg_blend_radii', []))
        self.speed_scale = kwargs.get('speed_scale', float())

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
        if self.leg_step_ids != other.leg_step_ids:
            return False
        if self.leg_target_poses != other.leg_target_poses:
            return False
        if self.leg_traj_methods != other.leg_traj_methods:
            return False
        if self.leg_traj_types != other.leg_traj_types:
            return False
        if self.leg_blend_radii != other.leg_blend_radii:
            return False
        if self.speed_scale != other.speed_scale:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def leg_step_ids(self):
        """Message field 'leg_step_ids'."""
        return self._leg_step_ids

    @leg_step_ids.setter
    def leg_step_ids(self, value):
        if self._check_fields:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'leg_step_ids' field must be a set or sequence and each value of type 'str'"
        self._leg_step_ids = value

    @builtins.property
    def leg_target_poses(self):
        """Message field 'leg_target_poses'."""
        return self._leg_target_poses

    @leg_target_poses.setter
    def leg_target_poses(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Pose
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Pose) for v in value) and
                 True), \
                "The 'leg_target_poses' field must be a set or sequence and each value of type 'Pose'"
        self._leg_target_poses = value

    @builtins.property
    def leg_traj_methods(self):
        """Message field 'leg_traj_methods'."""
        return self._leg_traj_methods

    @leg_traj_methods.setter
    def leg_traj_methods(self, value):
        if self._check_fields:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'leg_traj_methods' field must be a set or sequence and each value of type 'str'"
        self._leg_traj_methods = value

    @builtins.property
    def leg_traj_types(self):
        """Message field 'leg_traj_types'."""
        return self._leg_traj_types

    @leg_traj_types.setter
    def leg_traj_types(self, value):
        if self._check_fields:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'leg_traj_types' field must be a set or sequence and each value of type 'str'"
        self._leg_traj_types = value

    @builtins.property
    def leg_blend_radii(self):
        """Message field 'leg_blend_radii'."""
        return self._leg_blend_radii

    @leg_blend_radii.setter
    def leg_blend_radii(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'leg_blend_radii' array.array() must have the type code of 'd'"
                self._leg_blend_radii = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'leg_blend_radii' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._leg_blend_radii = array.array('d', value)

    @builtins.property
    def speed_scale(self):
        """Message field 'speed_scale'."""
        return self._speed_scale

    @speed_scale.setter
    def speed_scale(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'speed_scale' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed_scale' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed_scale = value


# Import statements for member types

# Member 'final_state'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_Result(type):
    """Metaclass of message 'ExecuteMoveStep_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_Result(metaclass=Metaclass_ExecuteMoveStep_Result):
    """Message class 'ExecuteMoveStep_Result'."""

    __slots__ = [
        '_success',
        '_error_code',
        '_final_state',
        '_total_duration',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'error_code': 'uint8',
        'final_state': 'sequence<double>',
        'total_duration': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
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
        self.success = kwargs.get('success', bool())
        self.error_code = kwargs.get('error_code', int())
        self.final_state = array.array('d', kwargs.get('final_state', []))
        self.total_duration = kwargs.get('total_duration', float())

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
        if self.success != other.success:
            return False
        if self.error_code != other.error_code:
            return False
        if self.final_state != other.final_state:
            return False
        if self.total_duration != other.total_duration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def error_code(self):
        """Message field 'error_code'."""
        return self._error_code

    @error_code.setter
    def error_code(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'error_code' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'error_code' field must be an unsigned integer in [0, 255]"
        self._error_code = value

    @builtins.property
    def final_state(self):
        """Message field 'final_state'."""
        return self._final_state

    @final_state.setter
    def final_state(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'final_state' array.array() must have the type code of 'd'"
                self._final_state = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'final_state' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._final_state = array.array('d', value)

    @builtins.property
    def total_duration(self):
        """Message field 'total_duration'."""
        return self._total_duration

    @total_duration.setter
    def total_duration(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'total_duration' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'total_duration' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._total_duration = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_Feedback(type):
    """Metaclass of message 'ExecuteMoveStep_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_Feedback(metaclass=Metaclass_ExecuteMoveStep_Feedback):
    """Message class 'ExecuteMoveStep_Feedback'."""

    __slots__ = [
        '_current_step_id',
        '_percent_complete',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'current_step_id': 'string',
        'percent_complete': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
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
        self.current_step_id = kwargs.get('current_step_id', str())
        self.percent_complete = kwargs.get('percent_complete', float())

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
        if self.current_step_id != other.current_step_id:
            return False
        if self.percent_complete != other.percent_complete:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_step_id(self):
        """Message field 'current_step_id'."""
        return self._current_step_id

    @current_step_id.setter
    def current_step_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'current_step_id' field must be of type 'str'"
        self._current_step_id = value

    @builtins.property
    def percent_complete(self):
        """Message field 'percent_complete'."""
        return self._percent_complete

    @percent_complete.setter
    def percent_complete(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'percent_complete' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'percent_complete' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._percent_complete = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_SendGoal_Request(type):
    """Metaclass of message 'ExecuteMoveStep_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__send_goal__request

            from robokpy_interfaces.action import ExecuteMoveStep
            if ExecuteMoveStep.Goal.__class__._TYPE_SUPPORT is None:
                ExecuteMoveStep.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_SendGoal_Request(metaclass=Metaclass_ExecuteMoveStep_SendGoal_Request):
    """Message class 'ExecuteMoveStep_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'robokpy_interfaces/ExecuteMoveStep_Goal',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_Goal'),  # noqa: E501
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
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Goal
        self.goal = kwargs.get('goal', ExecuteMoveStep_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if self._check_fields:
            from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Goal
            assert \
                isinstance(value, ExecuteMoveStep_Goal), \
                "The 'goal' field must be a sub message of type 'ExecuteMoveStep_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_SendGoal_Response(type):
    """Metaclass of message 'ExecuteMoveStep_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_SendGoal_Response(metaclass=Metaclass_ExecuteMoveStep_SendGoal_Response):
    """Message class 'ExecuteMoveStep_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.accepted = kwargs.get('accepted', bool())
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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_SendGoal_Event(type):
    """Metaclass of message 'ExecuteMoveStep_SendGoal_Event'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_SendGoal_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__send_goal__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__send_goal__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__send_goal__event
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__send_goal__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__send_goal__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_SendGoal_Event(metaclass=Metaclass_ExecuteMoveStep_SendGoal_Event):
    """Message class 'ExecuteMoveStep_SendGoal_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<robokpy_interfaces/ExecuteMoveStep_SendGoal_Request, 1>',
        'response': 'sequence<robokpy_interfaces/ExecuteMoveStep_SendGoal_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_SendGoal_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_SendGoal_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from robokpy_interfaces.action import ExecuteMoveStep_SendGoal_Request
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, ExecuteMoveStep_SendGoal_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ExecuteMoveStep_SendGoal_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from robokpy_interfaces.action import ExecuteMoveStep_SendGoal_Response
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, ExecuteMoveStep_SendGoal_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ExecuteMoveStep_SendGoal_Response'"
        self._response = value


class Metaclass_ExecuteMoveStep_SendGoal(type):
    """Metaclass of service 'ExecuteMoveStep_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robokpy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robokpy_interfaces.action.ExecuteMoveStep_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__execute_move_step__send_goal

            from robokpy_interfaces.action import _execute_move_step
            if _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal_Request._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal_Request.__import_type_support__()
            if _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal_Response._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal_Response.__import_type_support__()
            if _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal_Event._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal_Event.__import_type_support__()


class ExecuteMoveStep_SendGoal(metaclass=Metaclass_ExecuteMoveStep_SendGoal):
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_SendGoal_Request as Request
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_SendGoal_Response as Response
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_SendGoal_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_GetResult_Request(type):
    """Metaclass of message 'ExecuteMoveStep_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_GetResult_Request(metaclass=Metaclass_ExecuteMoveStep_GetResult_Request):
    """Message class 'ExecuteMoveStep_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
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
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_GetResult_Response(type):
    """Metaclass of message 'ExecuteMoveStep_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__get_result__response

            from robokpy_interfaces.action import ExecuteMoveStep
            if ExecuteMoveStep.Result.__class__._TYPE_SUPPORT is None:
                ExecuteMoveStep.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_GetResult_Response(metaclass=Metaclass_ExecuteMoveStep_GetResult_Response):
    """Message class 'ExecuteMoveStep_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'robokpy_interfaces/ExecuteMoveStep_Result',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_Result'),  # noqa: E501
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
        self.status = kwargs.get('status', int())
        from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Result
        self.result = kwargs.get('result', ExecuteMoveStep_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if self._check_fields:
            from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Result
            assert \
                isinstance(value, ExecuteMoveStep_Result), \
                "The 'result' field must be a sub message of type 'ExecuteMoveStep_Result'"
        self._result = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_GetResult_Event(type):
    """Metaclass of message 'ExecuteMoveStep_GetResult_Event'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_GetResult_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__get_result__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__get_result__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__get_result__event
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__get_result__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__get_result__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_GetResult_Event(metaclass=Metaclass_ExecuteMoveStep_GetResult_Event):
    """Message class 'ExecuteMoveStep_GetResult_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<robokpy_interfaces/ExecuteMoveStep_GetResult_Request, 1>',
        'response': 'sequence<robokpy_interfaces/ExecuteMoveStep_GetResult_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_GetResult_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_GetResult_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from robokpy_interfaces.action import ExecuteMoveStep_GetResult_Request
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, ExecuteMoveStep_GetResult_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ExecuteMoveStep_GetResult_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from robokpy_interfaces.action import ExecuteMoveStep_GetResult_Response
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) <= 1 and
                 all(isinstance(v, ExecuteMoveStep_GetResult_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ExecuteMoveStep_GetResult_Response'"
        self._response = value


class Metaclass_ExecuteMoveStep_GetResult(type):
    """Metaclass of service 'ExecuteMoveStep_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robokpy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robokpy_interfaces.action.ExecuteMoveStep_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__execute_move_step__get_result

            from robokpy_interfaces.action import _execute_move_step
            if _execute_move_step.Metaclass_ExecuteMoveStep_GetResult_Request._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_GetResult_Request.__import_type_support__()
            if _execute_move_step.Metaclass_ExecuteMoveStep_GetResult_Response._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_GetResult_Response.__import_type_support__()
            if _execute_move_step.Metaclass_ExecuteMoveStep_GetResult_Event._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_GetResult_Event.__import_type_support__()


class ExecuteMoveStep_GetResult(metaclass=Metaclass_ExecuteMoveStep_GetResult):
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_GetResult_Request as Request
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_GetResult_Response as Response
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_GetResult_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ExecuteMoveStep_FeedbackMessage(type):
    """Metaclass of message 'ExecuteMoveStep_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'robokpy_interfaces.action.ExecuteMoveStep_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__execute_move_step__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__execute_move_step__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__execute_move_step__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__execute_move_step__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__execute_move_step__feedback_message

            from robokpy_interfaces.action import ExecuteMoveStep
            if ExecuteMoveStep.Feedback.__class__._TYPE_SUPPORT is None:
                ExecuteMoveStep.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ExecuteMoveStep_FeedbackMessage(metaclass=Metaclass_ExecuteMoveStep_FeedbackMessage):
    """Message class 'ExecuteMoveStep_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'robokpy_interfaces/ExecuteMoveStep_Feedback',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'action'], 'ExecuteMoveStep_Feedback'),  # noqa: E501
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
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Feedback
        self.feedback = kwargs.get('feedback', ExecuteMoveStep_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if self._check_fields:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if self._check_fields:
            from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Feedback
            assert \
                isinstance(value, ExecuteMoveStep_Feedback), \
                "The 'feedback' field must be a sub message of type 'ExecuteMoveStep_Feedback'"
        self._feedback = value


class Metaclass_ExecuteMoveStep(type):
    """Metaclass of action 'ExecuteMoveStep'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('robokpy_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'robokpy_interfaces.action.ExecuteMoveStep')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__execute_move_step

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from robokpy_interfaces.action import _execute_move_step
            if _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_SendGoal.__import_type_support__()
            if _execute_move_step.Metaclass_ExecuteMoveStep_GetResult._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_GetResult.__import_type_support__()
            if _execute_move_step.Metaclass_ExecuteMoveStep_FeedbackMessage._TYPE_SUPPORT is None:
                _execute_move_step.Metaclass_ExecuteMoveStep_FeedbackMessage.__import_type_support__()


class ExecuteMoveStep(metaclass=Metaclass_ExecuteMoveStep):

    # The goal message defined in the action definition.
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Goal as Goal
    # The result message defined in the action definition.
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Result as Result
    # The feedback message defined in the action definition.
    from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from robokpy_interfaces.action._execute_move_step import ExecuteMoveStep_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
