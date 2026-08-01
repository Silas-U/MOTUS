// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/SpawnObject.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/srv/detail/spawn_object__functions.h"
#include "robokpy_interfaces/srv/detail/spawn_object__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SpawnObject_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SpawnObject_Request_type_support_ids_t;

static const _SpawnObject_Request_type_support_ids_t _SpawnObject_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SpawnObject_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SpawnObject_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SpawnObject_Request_type_support_symbol_names_t _SpawnObject_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, SpawnObject_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, SpawnObject_Request)),
  }
};

typedef struct _SpawnObject_Request_type_support_data_t
{
  void * data[2];
} _SpawnObject_Request_type_support_data_t;

static _SpawnObject_Request_type_support_data_t _SpawnObject_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SpawnObject_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SpawnObject_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SpawnObject_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SpawnObject_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SpawnObject_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SpawnObject_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__SpawnObject_Request__get_type_hash,
  &robokpy_interfaces__srv__SpawnObject_Request__get_type_description,
  &robokpy_interfaces__srv__SpawnObject_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Request>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::SpawnObject_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, SpawnObject_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/spawn_object__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/spawn_object__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SpawnObject_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SpawnObject_Response_type_support_ids_t;

static const _SpawnObject_Response_type_support_ids_t _SpawnObject_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SpawnObject_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SpawnObject_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SpawnObject_Response_type_support_symbol_names_t _SpawnObject_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, SpawnObject_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, SpawnObject_Response)),
  }
};

typedef struct _SpawnObject_Response_type_support_data_t
{
  void * data[2];
} _SpawnObject_Response_type_support_data_t;

static _SpawnObject_Response_type_support_data_t _SpawnObject_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SpawnObject_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SpawnObject_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SpawnObject_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SpawnObject_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SpawnObject_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SpawnObject_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__SpawnObject_Response__get_type_hash,
  &robokpy_interfaces__srv__SpawnObject_Response__get_type_description,
  &robokpy_interfaces__srv__SpawnObject_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Response>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::SpawnObject_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, SpawnObject_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/spawn_object__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/spawn_object__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SpawnObject_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SpawnObject_Event_type_support_ids_t;

static const _SpawnObject_Event_type_support_ids_t _SpawnObject_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SpawnObject_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SpawnObject_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SpawnObject_Event_type_support_symbol_names_t _SpawnObject_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, SpawnObject_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, SpawnObject_Event)),
  }
};

typedef struct _SpawnObject_Event_type_support_data_t
{
  void * data[2];
} _SpawnObject_Event_type_support_data_t;

static _SpawnObject_Event_type_support_data_t _SpawnObject_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SpawnObject_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SpawnObject_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SpawnObject_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SpawnObject_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SpawnObject_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SpawnObject_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__SpawnObject_Event__get_type_hash,
  &robokpy_interfaces__srv__SpawnObject_Event__get_type_description,
  &robokpy_interfaces__srv__SpawnObject_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Event>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::SpawnObject_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, SpawnObject_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "robokpy_interfaces/srv/detail/spawn_object__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _SpawnObject_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SpawnObject_type_support_ids_t;

static const _SpawnObject_type_support_ids_t _SpawnObject_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _SpawnObject_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SpawnObject_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SpawnObject_type_support_symbol_names_t _SpawnObject_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, SpawnObject)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, SpawnObject)),
  }
};

typedef struct _SpawnObject_type_support_data_t
{
  void * data[2];
} _SpawnObject_type_support_data_t;

static _SpawnObject_type_support_data_t _SpawnObject_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SpawnObject_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SpawnObject_service_typesupport_ids.typesupport_identifier[0],
  &_SpawnObject_service_typesupport_symbol_names.symbol_name[0],
  &_SpawnObject_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SpawnObject_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SpawnObject_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::SpawnObject_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::SpawnObject>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::SpawnObject>,
  &robokpy_interfaces__srv__SpawnObject__get_type_hash,
  &robokpy_interfaces__srv__SpawnObject__get_type_description,
  &robokpy_interfaces__srv__SpawnObject__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::SpawnObject>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::SpawnObject_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, SpawnObject)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::srv::SpawnObject>();
}

#ifdef __cplusplus
}
#endif
