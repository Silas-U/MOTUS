# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robokpy_interfaces:srv/ChainFK.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'q'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ChainFK_Request(type):
    """Metaclass of message 'ChainFK_Request'."""

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
                'robokpy_interfaces.srv.ChainFK_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__chain_fk__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__chain_fk__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__chain_fk__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__chain_fk__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__chain_fk__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChainFK_Request(metaclass=Metaclass_ChainFK_Request):
    """Message class 'ChainFK_Request'."""

    __slots__ = [
        '_q',
        '_base_link',
        '_end_link',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'q': 'sequence<double>',
        'base_link': 'string',
        'end_link': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.q = array.array('d', kwargs.get('q', []))
        self.base_link = kwargs.get('base_link', str())
        self.end_link = kwargs.get('end_link', str())

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
        if self.q != other.q:
            return False
        if self.base_link != other.base_link:
            return False
        if self.end_link != other.end_link:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def q(self):
        """Message field 'q'."""
        return self._q

    @q.setter
    def q(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'q' array.array() must have the type code of 'd'"
                self._q = value
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
                "The 'q' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._q = array.array('d', value)

    @builtins.property
    def base_link(self):
        """Message field 'base_link'."""
        return self._base_link

    @base_link.setter
    def base_link(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'base_link' field must be of type 'str'"
        self._base_link = value

    @builtins.property
    def end_link(self):
        """Message field 'end_link'."""
        return self._end_link

    @end_link.setter
    def end_link(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'end_link' field must be of type 'str'"
        self._end_link = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# Member 'pose'
# Member 'pose_euler'
import numpy  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_ChainFK_Response(type):
    """Metaclass of message 'ChainFK_Response'."""

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
                'robokpy_interfaces.srv.ChainFK_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__chain_fk__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__chain_fk__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__chain_fk__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__chain_fk__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__chain_fk__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChainFK_Response(metaclass=Metaclass_ChainFK_Response):
    """Message class 'ChainFK_Response'."""

    __slots__ = [
        '_success',
        '_pose',
        '_pose_euler',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'pose': 'double[7]',
        'pose_euler': 'double[6]',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 7),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('double'), 6),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        if 'pose' not in kwargs:
            self.pose = numpy.zeros(7, dtype=numpy.float64)
        else:
            self.pose = numpy.array(kwargs.get('pose'), dtype=numpy.float64)
            assert self.pose.shape == (7, )
        if 'pose_euler' not in kwargs:
            self.pose_euler = numpy.zeros(6, dtype=numpy.float64)
        else:
            self.pose_euler = numpy.array(kwargs.get('pose_euler'), dtype=numpy.float64)
            assert self.pose_euler.shape == (6, )
        self.message = kwargs.get('message', str())

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
        if all(self.pose != other.pose):
            return False
        if all(self.pose_euler != other.pose_euler):
            return False
        if self.message != other.message:
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
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if self._check_fields:
            if isinstance(value, numpy.ndarray):
                assert value.dtype == numpy.float64, \
                    "The 'pose' numpy.ndarray() must have the dtype of 'numpy.float64'"
                assert value.size == 7, \
                    "The 'pose' numpy.ndarray() must have a size of 7"
                self._pose = value
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
                 len(value) == 7 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'pose' field must be a set or sequence with length 7 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._pose = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def pose_euler(self):
        """Message field 'pose_euler'."""
        return self._pose_euler

    @pose_euler.setter
    def pose_euler(self, value):
        if self._check_fields:
            if isinstance(value, numpy.ndarray):
                assert value.dtype == numpy.float64, \
                    "The 'pose_euler' numpy.ndarray() must have the dtype of 'numpy.float64'"
                assert value.size == 6, \
                    "The 'pose_euler' numpy.ndarray() must have a size of 6"
                self._pose_euler = value
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
                 len(value) == 6 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'pose_euler' field must be a set or sequence with length 6 and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._pose_euler = numpy.array(value, dtype=numpy.float64)

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ChainFK_Event(type):
    """Metaclass of message 'ChainFK_Event'."""

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
                'robokpy_interfaces.srv.ChainFK_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__chain_fk__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__chain_fk__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__chain_fk__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__chain_fk__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__chain_fk__event

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


class ChainFK_Event(metaclass=Metaclass_ChainFK_Event):
    """Message class 'ChainFK_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<robokpy_interfaces/ChainFK_Request, 1>',
        'response': 'sequence<robokpy_interfaces/ChainFK_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'srv'], 'ChainFK_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'srv'], 'ChainFK_Response'), 1),  # noqa: E501
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
            from robokpy_interfaces.srv import ChainFK_Request
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
                 all(isinstance(v, ChainFK_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ChainFK_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from robokpy_interfaces.srv import ChainFK_Response
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
                 all(isinstance(v, ChainFK_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ChainFK_Response'"
        self._response = value


class Metaclass_ChainFK(type):
    """Metaclass of service 'ChainFK'."""

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
                'robokpy_interfaces.srv.ChainFK')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__chain_fk

            from robokpy_interfaces.srv import _chain_fk
            if _chain_fk.Metaclass_ChainFK_Request._TYPE_SUPPORT is None:
                _chain_fk.Metaclass_ChainFK_Request.__import_type_support__()
            if _chain_fk.Metaclass_ChainFK_Response._TYPE_SUPPORT is None:
                _chain_fk.Metaclass_ChainFK_Response.__import_type_support__()
            if _chain_fk.Metaclass_ChainFK_Event._TYPE_SUPPORT is None:
                _chain_fk.Metaclass_ChainFK_Event.__import_type_support__()


class ChainFK(metaclass=Metaclass_ChainFK):
    from robokpy_interfaces.srv._chain_fk import ChainFK_Request as Request
    from robokpy_interfaces.srv._chain_fk import ChainFK_Response as Response
    from robokpy_interfaces.srv._chain_fk import ChainFK_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
