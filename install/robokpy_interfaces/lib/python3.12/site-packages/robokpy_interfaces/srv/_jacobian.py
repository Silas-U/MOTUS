# generated from rosidl_generator_py/resource/_idl.py.em
# with input from robokpy_interfaces:srv/Jacobian.idl
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


class Metaclass_Jacobian_Request(type):
    """Metaclass of message 'Jacobian_Request'."""

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
                'robokpy_interfaces.srv.Jacobian_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__jacobian__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__jacobian__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__jacobian__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__jacobian__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__jacobian__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Jacobian_Request(metaclass=Metaclass_Jacobian_Request):
    """Message class 'Jacobian_Request'."""

    __slots__ = [
        '_q',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'q': 'sequence<double>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
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


# Import statements for member types

# Member 'jacobian_flat'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_Jacobian_Response(type):
    """Metaclass of message 'Jacobian_Response'."""

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
                'robokpy_interfaces.srv.Jacobian_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__jacobian__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__jacobian__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__jacobian__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__jacobian__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__jacobian__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Jacobian_Response(metaclass=Metaclass_Jacobian_Response):
    """Message class 'Jacobian_Response'."""

    __slots__ = [
        '_success',
        '_jacobian_flat',
        '_rows',
        '_cols',
        '_manipulability',
        '_condition_number',
        '_rank',
        '_is_near_singular',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'jacobian_flat': 'sequence<double>',
        'rows': 'int32',
        'cols': 'int32',
        'manipulability': 'double',
        'condition_number': 'double',
        'rank': 'int32',
        'is_near_singular': 'boolean',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.jacobian_flat = array.array('d', kwargs.get('jacobian_flat', []))
        self.rows = kwargs.get('rows', int())
        self.cols = kwargs.get('cols', int())
        self.manipulability = kwargs.get('manipulability', float())
        self.condition_number = kwargs.get('condition_number', float())
        self.rank = kwargs.get('rank', int())
        self.is_near_singular = kwargs.get('is_near_singular', bool())
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
        if self.jacobian_flat != other.jacobian_flat:
            return False
        if self.rows != other.rows:
            return False
        if self.cols != other.cols:
            return False
        if self.manipulability != other.manipulability:
            return False
        if self.condition_number != other.condition_number:
            return False
        if self.rank != other.rank:
            return False
        if self.is_near_singular != other.is_near_singular:
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
    def jacobian_flat(self):
        """Message field 'jacobian_flat'."""
        return self._jacobian_flat

    @jacobian_flat.setter
    def jacobian_flat(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'jacobian_flat' array.array() must have the type code of 'd'"
                self._jacobian_flat = value
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
                "The 'jacobian_flat' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._jacobian_flat = array.array('d', value)

    @builtins.property
    def rows(self):
        """Message field 'rows'."""
        return self._rows

    @rows.setter
    def rows(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rows' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rows' field must be an integer in [-2147483648, 2147483647]"
        self._rows = value

    @builtins.property
    def cols(self):
        """Message field 'cols'."""
        return self._cols

    @cols.setter
    def cols(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'cols' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'cols' field must be an integer in [-2147483648, 2147483647]"
        self._cols = value

    @builtins.property
    def manipulability(self):
        """Message field 'manipulability'."""
        return self._manipulability

    @manipulability.setter
    def manipulability(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'manipulability' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'manipulability' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._manipulability = value

    @builtins.property
    def condition_number(self):
        """Message field 'condition_number'."""
        return self._condition_number

    @condition_number.setter
    def condition_number(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'condition_number' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'condition_number' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._condition_number = value

    @builtins.property
    def rank(self):
        """Message field 'rank'."""
        return self._rank

    @rank.setter
    def rank(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rank' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rank' field must be an integer in [-2147483648, 2147483647]"
        self._rank = value

    @builtins.property
    def is_near_singular(self):
        """Message field 'is_near_singular'."""
        return self._is_near_singular

    @is_near_singular.setter
    def is_near_singular(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'is_near_singular' field must be of type 'bool'"
        self._is_near_singular = value

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


class Metaclass_Jacobian_Event(type):
    """Metaclass of message 'Jacobian_Event'."""

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
                'robokpy_interfaces.srv.Jacobian_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__jacobian__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__jacobian__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__jacobian__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__jacobian__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__jacobian__event

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


class Jacobian_Event(metaclass=Metaclass_Jacobian_Event):
    """Message class 'Jacobian_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<robokpy_interfaces/Jacobian_Request, 1>',
        'response': 'sequence<robokpy_interfaces/Jacobian_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'srv'], 'Jacobian_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['robokpy_interfaces', 'srv'], 'Jacobian_Response'), 1),  # noqa: E501
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
            from robokpy_interfaces.srv import Jacobian_Request
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
                 all(isinstance(v, Jacobian_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'Jacobian_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from robokpy_interfaces.srv import Jacobian_Response
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
                 all(isinstance(v, Jacobian_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'Jacobian_Response'"
        self._response = value


class Metaclass_Jacobian(type):
    """Metaclass of service 'Jacobian'."""

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
                'robokpy_interfaces.srv.Jacobian')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__jacobian

            from robokpy_interfaces.srv import _jacobian
            if _jacobian.Metaclass_Jacobian_Request._TYPE_SUPPORT is None:
                _jacobian.Metaclass_Jacobian_Request.__import_type_support__()
            if _jacobian.Metaclass_Jacobian_Response._TYPE_SUPPORT is None:
                _jacobian.Metaclass_Jacobian_Response.__import_type_support__()
            if _jacobian.Metaclass_Jacobian_Event._TYPE_SUPPORT is None:
                _jacobian.Metaclass_Jacobian_Event.__import_type_support__()


class Jacobian(metaclass=Metaclass_Jacobian):
    from robokpy_interfaces.srv._jacobian import Jacobian_Request as Request
    from robokpy_interfaces.srv._jacobian import Jacobian_Response as Response
    from robokpy_interfaces.srv._jacobian import Jacobian_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
