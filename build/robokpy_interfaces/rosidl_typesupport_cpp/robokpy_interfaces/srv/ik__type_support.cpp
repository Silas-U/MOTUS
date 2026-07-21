// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/IK.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/srv/detail/ik__functions.h"
#include "robokpy_interfaces/srv/detail/ik__struct.hpp"
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

typedef struct _IK_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IK_Request_type_support_ids_t;

static const _IK_Request_type_support_ids_t _IK_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _IK_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IK_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IK_Request_type_support_symbol_names_t _IK_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, IK_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, IK_Request)),
  }
};

typedef struct _IK_Request_type_support_data_t
{
  void * data[2];
} _IK_Request_type_support_data_t;

static _IK_Request_type_support_data_t _IK_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IK_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_IK_Request_message_typesupport_ids.typesupport_identifier[0],
  &_IK_Request_message_typesupport_symbol_names.symbol_name[0],
  &_IK_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t IK_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IK_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__IK_Request__get_type_hash,
  &robokpy_interfaces__srv__IK_Request__get_type_description,
  &robokpy_interfaces__srv__IK_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::IK_Request>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::IK_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, IK_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::IK_Request>();
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
// #include "robokpy_interfaces/srv/detail/ik__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/ik__struct.hpp"
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

typedef struct _IK_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IK_Response_type_support_ids_t;

static const _IK_Response_type_support_ids_t _IK_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _IK_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IK_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IK_Response_type_support_symbol_names_t _IK_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, IK_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, IK_Response)),
  }
};

typedef struct _IK_Response_type_support_data_t
{
  void * data[2];
} _IK_Response_type_support_data_t;

static _IK_Response_type_support_data_t _IK_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IK_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_IK_Response_message_typesupport_ids.typesupport_identifier[0],
  &_IK_Response_message_typesupport_symbol_names.symbol_name[0],
  &_IK_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t IK_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IK_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__IK_Response__get_type_hash,
  &robokpy_interfaces__srv__IK_Response__get_type_description,
  &robokpy_interfaces__srv__IK_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::IK_Response>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::IK_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, IK_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::IK_Response>();
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
// #include "robokpy_interfaces/srv/detail/ik__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/ik__struct.hpp"
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

typedef struct _IK_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IK_Event_type_support_ids_t;

static const _IK_Event_type_support_ids_t _IK_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _IK_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IK_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IK_Event_type_support_symbol_names_t _IK_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, IK_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, IK_Event)),
  }
};

typedef struct _IK_Event_type_support_data_t
{
  void * data[2];
} _IK_Event_type_support_data_t;

static _IK_Event_type_support_data_t _IK_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IK_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_IK_Event_message_typesupport_ids.typesupport_identifier[0],
  &_IK_Event_message_typesupport_symbol_names.symbol_name[0],
  &_IK_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t IK_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IK_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__IK_Event__get_type_hash,
  &robokpy_interfaces__srv__IK_Event__get_type_description,
  &robokpy_interfaces__srv__IK_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::IK_Event>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::IK_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, IK_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::srv::IK_Event>();
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
// #include "robokpy_interfaces/srv/detail/ik__struct.hpp"
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

typedef struct _IK_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IK_type_support_ids_t;

static const _IK_type_support_ids_t _IK_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _IK_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IK_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IK_type_support_symbol_names_t _IK_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, IK)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, IK)),
  }
};

typedef struct _IK_type_support_data_t
{
  void * data[2];
} _IK_type_support_data_t;

static _IK_type_support_data_t _IK_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IK_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_IK_service_typesupport_ids.typesupport_identifier[0],
  &_IK_service_typesupport_symbol_names.symbol_name[0],
  &_IK_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t IK_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IK_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::IK_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::IK_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::srv::IK_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::IK>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::IK>,
  &robokpy_interfaces__srv__IK__get_type_hash,
  &robokpy_interfaces__srv__IK__get_type_description,
  &robokpy_interfaces__srv__IK__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::IK>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_cpp::IK_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, srv, IK)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::srv::IK>();
}

#ifdef __cplusplus
}
#endif
