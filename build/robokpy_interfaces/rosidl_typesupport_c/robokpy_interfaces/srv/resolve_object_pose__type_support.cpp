// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/ResolveObjectPose.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/srv/detail/resolve_object_pose__struct.h"
#include "robokpy_interfaces/srv/detail/resolve_object_pose__type_support.h"
#include "robokpy_interfaces/srv/detail/resolve_object_pose__functions.h"
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

typedef struct _ResolveObjectPose_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResolveObjectPose_Request_type_support_ids_t;

static const _ResolveObjectPose_Request_type_support_ids_t _ResolveObjectPose_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResolveObjectPose_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResolveObjectPose_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResolveObjectPose_Request_type_support_symbol_names_t _ResolveObjectPose_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResolveObjectPose_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResolveObjectPose_Request)),
  }
};

typedef struct _ResolveObjectPose_Request_type_support_data_t
{
  void * data[2];
} _ResolveObjectPose_Request_type_support_data_t;

static _ResolveObjectPose_Request_type_support_data_t _ResolveObjectPose_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResolveObjectPose_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResolveObjectPose_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ResolveObjectPose_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ResolveObjectPose_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ResolveObjectPose_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResolveObjectPose_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_hash,
  &robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_description,
  &robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResolveObjectPose_Request)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResolveObjectPose_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__type_support.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__functions.h"
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

typedef struct _ResolveObjectPose_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResolveObjectPose_Response_type_support_ids_t;

static const _ResolveObjectPose_Response_type_support_ids_t _ResolveObjectPose_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResolveObjectPose_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResolveObjectPose_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResolveObjectPose_Response_type_support_symbol_names_t _ResolveObjectPose_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResolveObjectPose_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResolveObjectPose_Response)),
  }
};

typedef struct _ResolveObjectPose_Response_type_support_data_t
{
  void * data[2];
} _ResolveObjectPose_Response_type_support_data_t;

static _ResolveObjectPose_Response_type_support_data_t _ResolveObjectPose_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResolveObjectPose_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResolveObjectPose_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ResolveObjectPose_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ResolveObjectPose_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ResolveObjectPose_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResolveObjectPose_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_hash,
  &robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_description,
  &robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResolveObjectPose_Response)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResolveObjectPose_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__type_support.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__functions.h"
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

typedef struct _ResolveObjectPose_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResolveObjectPose_Event_type_support_ids_t;

static const _ResolveObjectPose_Event_type_support_ids_t _ResolveObjectPose_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResolveObjectPose_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResolveObjectPose_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResolveObjectPose_Event_type_support_symbol_names_t _ResolveObjectPose_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResolveObjectPose_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResolveObjectPose_Event)),
  }
};

typedef struct _ResolveObjectPose_Event_type_support_data_t
{
  void * data[2];
} _ResolveObjectPose_Event_type_support_data_t;

static _ResolveObjectPose_Event_type_support_data_t _ResolveObjectPose_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResolveObjectPose_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResolveObjectPose_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ResolveObjectPose_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ResolveObjectPose_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ResolveObjectPose_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResolveObjectPose_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_hash,
  &robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_description,
  &robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResolveObjectPose_Event)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResolveObjectPose_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/resolve_object_pose__type_support.h"
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
typedef struct _ResolveObjectPose_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ResolveObjectPose_type_support_ids_t;

static const _ResolveObjectPose_type_support_ids_t _ResolveObjectPose_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ResolveObjectPose_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ResolveObjectPose_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ResolveObjectPose_type_support_symbol_names_t _ResolveObjectPose_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, srv, ResolveObjectPose)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, ResolveObjectPose)),
  }
};

typedef struct _ResolveObjectPose_type_support_data_t
{
  void * data[2];
} _ResolveObjectPose_type_support_data_t;

static _ResolveObjectPose_type_support_data_t _ResolveObjectPose_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ResolveObjectPose_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ResolveObjectPose_service_typesupport_ids.typesupport_identifier[0],
  &_ResolveObjectPose_service_typesupport_symbol_names.symbol_name[0],
  &_ResolveObjectPose_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ResolveObjectPose_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ResolveObjectPose_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &ResolveObjectPose_Request_message_type_support_handle,
  &ResolveObjectPose_Response_message_type_support_handle,
  &ResolveObjectPose_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    ResolveObjectPose
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    ResolveObjectPose
  ),
  &robokpy_interfaces__srv__ResolveObjectPose__get_type_hash,
  &robokpy_interfaces__srv__ResolveObjectPose__get_type_description,
  &robokpy_interfaces__srv__ResolveObjectPose__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, srv, ResolveObjectPose)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_c::ResolveObjectPose_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
