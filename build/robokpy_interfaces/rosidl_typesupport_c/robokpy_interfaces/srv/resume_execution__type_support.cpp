// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/ResumeExecution.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/srv/detail/resume_execution__struct.h"
#include "robokpy_interfaces/srv/detail/resume_execution__type_support.h"
#include "robokpy_interfaces/srv/detail/resume_execution__functions.h"
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

typedef struct _ResumeExecution_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResumeExecution_Request_type_support_ids_t;

static const _ResumeExecution_Request_type_support_ids_t _ResumeExecution_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResumeExecution_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResumeExecution_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResumeExecution_Request_type_support_symbol_names_t _ResumeExecution_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResumeExecution_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResumeExecution_Request)),
  }
};

typedef struct _ResumeExecution_Request_type_support_data_t
{
  void * data[2];
} _ResumeExecution_Request_type_support_data_t;

static _ResumeExecution_Request_type_support_data_t _ResumeExecution_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResumeExecution_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResumeExecution_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ResumeExecution_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ResumeExecution_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ResumeExecution_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResumeExecution_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ResumeExecution_Request__get_type_hash,
  &robokpy_interfaces__srv__ResumeExecution_Request__get_type_description,
  &robokpy_interfaces__srv__ResumeExecution_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResumeExecution_Request)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResumeExecution_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__type_support.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__functions.h"
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

typedef struct _ResumeExecution_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResumeExecution_Response_type_support_ids_t;

static const _ResumeExecution_Response_type_support_ids_t _ResumeExecution_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResumeExecution_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResumeExecution_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResumeExecution_Response_type_support_symbol_names_t _ResumeExecution_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResumeExecution_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResumeExecution_Response)),
  }
};

typedef struct _ResumeExecution_Response_type_support_data_t
{
  void * data[2];
} _ResumeExecution_Response_type_support_data_t;

static _ResumeExecution_Response_type_support_data_t _ResumeExecution_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResumeExecution_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResumeExecution_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ResumeExecution_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ResumeExecution_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ResumeExecution_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResumeExecution_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ResumeExecution_Response__get_type_hash,
  &robokpy_interfaces__srv__ResumeExecution_Response__get_type_description,
  &robokpy_interfaces__srv__ResumeExecution_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResumeExecution_Response)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResumeExecution_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__type_support.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__functions.h"
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

typedef struct _ResumeExecution_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResumeExecution_Event_type_support_ids_t;

static const _ResumeExecution_Event_type_support_ids_t _ResumeExecution_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResumeExecution_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResumeExecution_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResumeExecution_Event_type_support_symbol_names_t _ResumeExecution_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResumeExecution_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResumeExecution_Event)),
  }
};

typedef struct _ResumeExecution_Event_type_support_data_t
{
  void * data[2];
} _ResumeExecution_Event_type_support_data_t;

static _ResumeExecution_Event_type_support_data_t _ResumeExecution_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResumeExecution_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResumeExecution_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ResumeExecution_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ResumeExecution_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ResumeExecution_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResumeExecution_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ResumeExecution_Event__get_type_hash,
  &robokpy_interfaces__srv__ResumeExecution_Event__get_type_description,
  &robokpy_interfaces__srv__ResumeExecution_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResumeExecution_Event)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResumeExecution_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resume_execution__type_support.h"
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
typedef struct _ResumeExecution_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResumeExecution_type_support_ids_t;

static const _ResumeExecution_type_support_ids_t _ResumeExecution_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResumeExecution_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResumeExecution_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResumeExecution_type_support_symbol_names_t _ResumeExecution_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResumeExecution)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResumeExecution)),
  }
};

typedef struct _ResumeExecution_type_support_data_t
{
  void * data[2];
} _ResumeExecution_type_support_data_t;

static _ResumeExecution_type_support_data_t _ResumeExecution_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResumeExecution_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResumeExecution_service_typesupport_ids.typesupport_identifier[0],
  &_ResumeExecution_service_typesupport_symbol_names.symbol_name[0],
  &_ResumeExecution_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ResumeExecution_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResumeExecution_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &ResumeExecution_Request_message_type_support_handle,
  &ResumeExecution_Response_message_type_support_handle,
  &ResumeExecution_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    ResumeExecution
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    ResumeExecution
  ),
  &robokpy_interfaces__srv__ResumeExecution__get_type_hash,
  &robokpy_interfaces__srv__ResumeExecution__get_type_description,
  &robokpy_interfaces__srv__ResumeExecution__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResumeExecution)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResumeExecution_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
