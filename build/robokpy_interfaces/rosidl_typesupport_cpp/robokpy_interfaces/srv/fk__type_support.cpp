// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/FK.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/srv/detail/fk__functions.h"
#include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

typedef struct _FK_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FK_Request_type_support_ids_t;

static const _FK_Request_type_support_ids_t _FK_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FK_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FK_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FK_Request_type_support_symbol_names_t _FK_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, FK_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK_Request)),
  }
};

typedef struct _FK_Request_type_support_data_t
{
  void * data[2];
} _FK_Request_type_support_data_t;

static _FK_Request_type_support_data_t _FK_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FK_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_FK_Request_message_typesupport_ids.typesupport_identifier[0],
  &_FK_Request_message_typesupport_symbol_names.symbol_name[0],
  &_FK_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FK_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FK_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__FK_Request__get_type_hash,
  &robokpy_interfaces__srv__FK_Request__get_type_description,
  &robokpy_interfaces__srv__FK_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::FK_Request>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::FK_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, FK_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::FK_Request>();
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
// #include "robokpy_interfaces/srv/detail/fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

typedef struct _FK_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FK_Response_type_support_ids_t;

static const _FK_Response_type_support_ids_t _FK_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FK_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FK_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FK_Response_type_support_symbol_names_t _FK_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, FK_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK_Response)),
  }
};

typedef struct _FK_Response_type_support_data_t
{
  void * data[2];
} _FK_Response_type_support_data_t;

static _FK_Response_type_support_data_t _FK_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FK_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_FK_Response_message_typesupport_ids.typesupport_identifier[0],
  &_FK_Response_message_typesupport_symbol_names.symbol_name[0],
  &_FK_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FK_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FK_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__FK_Response__get_type_hash,
  &robokpy_interfaces__srv__FK_Response__get_type_description,
  &robokpy_interfaces__srv__FK_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::FK_Response>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::FK_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, FK_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::FK_Response>();
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
// #include "robokpy_interfaces/srv/detail/fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

typedef struct _FK_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FK_Event_type_support_ids_t;

static const _FK_Event_type_support_ids_t _FK_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FK_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FK_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FK_Event_type_support_symbol_names_t _FK_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, FK_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK_Event)),
  }
};

typedef struct _FK_Event_type_support_data_t
{
  void * data[2];
} _FK_Event_type_support_data_t;

static _FK_Event_type_support_data_t _FK_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FK_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_FK_Event_message_typesupport_ids.typesupport_identifier[0],
  &_FK_Event_message_typesupport_symbol_names.symbol_name[0],
  &_FK_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FK_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FK_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__FK_Event__get_type_hash,
  &robokpy_interfaces__srv__FK_Event__get_type_description,
  &robokpy_interfaces__srv__FK_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::FK_Event>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::FK_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, FK_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::FK_Event>();
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
// #include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

typedef struct _FK_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FK_type_support_ids_t;

static const _FK_type_support_ids_t _FK_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FK_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FK_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FK_type_support_symbol_names_t _FK_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, FK)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK)),
  }
};

typedef struct _FK_type_support_data_t
{
  void * data[2];
} _FK_type_support_data_t;

static _FK_type_support_data_t _FK_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FK_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_FK_service_typesupport_ids.typesupport_identifier[0],
  &_FK_service_typesupport_symbol_names.symbol_name[0],
  &_FK_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t FK_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FK_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::FK>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::FK>,
  &robokpy_interfaces__srv__FK__get_type_hash,
  &robokpy_interfaces__srv__FK__get_type_description,
  &robokpy_interfaces__srv__FK__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::FK>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::FK_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, FK)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::srv::FK>();
}

#ifdef __cplusplus
}
#endif
