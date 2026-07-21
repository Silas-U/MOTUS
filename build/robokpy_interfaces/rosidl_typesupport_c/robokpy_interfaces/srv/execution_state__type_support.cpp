// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/ExecutionState.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/srv/detail/execution_state__struct.h"
#include "robokpy_interfaces/srv/detail/execution_state__type_support.h"
#include "robokpy_interfaces/srv/detail/execution_state__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ExecutionState_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecutionState_Request_type_support_ids_t;

static const _ExecutionState_Request_type_support_ids_t _ExecutionState_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ExecutionState_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecutionState_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecutionState_Request_type_support_symbol_names_t _ExecutionState_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ExecutionState_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ExecutionState_Request)),
  }
};

typedef struct _ExecutionState_Request_type_support_data_t
{
  void * data[2];
} _ExecutionState_Request_type_support_data_t;

static _ExecutionState_Request_type_support_data_t _ExecutionState_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecutionState_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecutionState_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecutionState_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecutionState_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecutionState_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecutionState_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ExecutionState_Request__get_type_hash,
  &robokpy_interfaces__srv__ExecutionState_Request__get_type_description,
  &robokpy_interfaces__srv__ExecutionState_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ExecutionState_Request)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ExecutionState_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__type_support.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ExecutionState_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecutionState_Response_type_support_ids_t;

static const _ExecutionState_Response_type_support_ids_t _ExecutionState_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ExecutionState_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecutionState_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecutionState_Response_type_support_symbol_names_t _ExecutionState_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ExecutionState_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ExecutionState_Response)),
  }
};

typedef struct _ExecutionState_Response_type_support_data_t
{
  void * data[2];
} _ExecutionState_Response_type_support_data_t;

static _ExecutionState_Response_type_support_data_t _ExecutionState_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecutionState_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecutionState_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecutionState_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecutionState_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecutionState_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecutionState_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ExecutionState_Response__get_type_hash,
  &robokpy_interfaces__srv__ExecutionState_Response__get_type_description,
  &robokpy_interfaces__srv__ExecutionState_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ExecutionState_Response)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ExecutionState_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__type_support.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ExecutionState_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecutionState_Event_type_support_ids_t;

static const _ExecutionState_Event_type_support_ids_t _ExecutionState_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ExecutionState_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecutionState_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecutionState_Event_type_support_symbol_names_t _ExecutionState_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ExecutionState_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ExecutionState_Event)),
  }
};

typedef struct _ExecutionState_Event_type_support_data_t
{
  void * data[2];
} _ExecutionState_Event_type_support_data_t;

static _ExecutionState_Event_type_support_data_t _ExecutionState_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecutionState_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecutionState_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ExecutionState_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ExecutionState_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecutionState_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecutionState_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ExecutionState_Event__get_type_hash,
  &robokpy_interfaces__srv__ExecutionState_Event__get_type_description,
  &robokpy_interfaces__srv__ExecutionState_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ExecutionState_Event)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ExecutionState_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/execution_state__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _ExecutionState_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecutionState_type_support_ids_t;

static const _ExecutionState_type_support_ids_t _ExecutionState_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ExecutionState_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecutionState_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecutionState_type_support_symbol_names_t _ExecutionState_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ExecutionState)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ExecutionState)),
  }
};

typedef struct _ExecutionState_type_support_data_t
{
  void * data[2];
} _ExecutionState_type_support_data_t;

static _ExecutionState_type_support_data_t _ExecutionState_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecutionState_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecutionState_service_typesupport_ids.typesupport_identifier[0],
  &_ExecutionState_service_typesupport_symbol_names.symbol_name[0],
  &_ExecutionState_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecutionState_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecutionState_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &ExecutionState_Request_message_type_support_handle,
  &ExecutionState_Response_message_type_support_handle,
  &ExecutionState_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    ExecutionState
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    ExecutionState
  ),
  &robokpy_interfaces__srv__ExecutionState__get_type_hash,
  &robokpy_interfaces__srv__ExecutionState__get_type_description,
  &robokpy_interfaces__srv__ExecutionState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ExecutionState)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ExecutionState_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
