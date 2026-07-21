// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:action/ExecuteVisionOp.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
#include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_Goal_type_support_ids_t;

static const _ExecuteVisionOp_Goal_type_support_ids_t _ExecuteVisionOp_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_Goal_type_support_symbol_names_t _ExecuteVisionOp_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_Goal)),
  }
};

typedef struct _ExecuteVisionOp_Goal_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_Goal_type_support_data_t;

static _ExecuteVisionOp_Goal_type_support_data_t _ExecuteVisionOp_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_Goal_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_Goal__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_Goal__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_Goal>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_Goal)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_Goal>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_Result_type_support_ids_t;

static const _ExecuteVisionOp_Result_type_support_ids_t _ExecuteVisionOp_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_Result_type_support_symbol_names_t _ExecuteVisionOp_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_Result)),
  }
};

typedef struct _ExecuteVisionOp_Result_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_Result_type_support_data_t;

static _ExecuteVisionOp_Result_type_support_data_t _ExecuteVisionOp_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_Result_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_Result_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_Result_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_Result__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_Result__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_Result>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_Result)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_Result>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_Feedback_type_support_ids_t;

static const _ExecuteVisionOp_Feedback_type_support_ids_t _ExecuteVisionOp_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_Feedback_type_support_symbol_names_t _ExecuteVisionOp_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_Feedback)),
  }
};

typedef struct _ExecuteVisionOp_Feedback_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_Feedback_type_support_data_t;

static _ExecuteVisionOp_Feedback_type_support_data_t _ExecuteVisionOp_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_Feedback_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_Feedback__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_Feedback__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_Feedback>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_Feedback)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_Feedback>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_SendGoal_Request_type_support_ids_t;

static const _ExecuteVisionOp_SendGoal_Request_type_support_ids_t _ExecuteVisionOp_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_SendGoal_Request_type_support_symbol_names_t _ExecuteVisionOp_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Request)),
  }
};

typedef struct _ExecuteVisionOp_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_SendGoal_Request_type_support_data_t;

static _ExecuteVisionOp_SendGoal_Request_type_support_data_t _ExecuteVisionOp_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_SendGoal_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_SendGoal_Response_type_support_ids_t;

static const _ExecuteVisionOp_SendGoal_Response_type_support_ids_t _ExecuteVisionOp_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_SendGoal_Response_type_support_symbol_names_t _ExecuteVisionOp_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Response)),
  }
};

typedef struct _ExecuteVisionOp_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_SendGoal_Response_type_support_data_t;

static _ExecuteVisionOp_SendGoal_Response_type_support_data_t _ExecuteVisionOp_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_SendGoal_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_SendGoal_Event_type_support_ids_t;

static const _ExecuteVisionOp_SendGoal_Event_type_support_ids_t _ExecuteVisionOp_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_SendGoal_Event_type_support_symbol_names_t _ExecuteVisionOp_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Event)),
  }
};

typedef struct _ExecuteVisionOp_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_SendGoal_Event_type_support_data_t;

static _ExecuteVisionOp_SendGoal_Event_type_support_data_t _ExecuteVisionOp_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_SendGoal_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_SendGoal_type_support_ids_t;

static const _ExecuteVisionOp_SendGoal_type_support_ids_t _ExecuteVisionOp_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_SendGoal_type_support_symbol_names_t _ExecuteVisionOp_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal)),
  }
};

typedef struct _ExecuteVisionOp_SendGoal_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_SendGoal_type_support_data_t;

static _ExecuteVisionOp_SendGoal_type_support_data_t _ExecuteVisionOp_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_SendGoal_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecuteVisionOp_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_GetResult_Request_type_support_ids_t;

static const _ExecuteVisionOp_GetResult_Request_type_support_ids_t _ExecuteVisionOp_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_GetResult_Request_type_support_symbol_names_t _ExecuteVisionOp_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Request)),
  }
};

typedef struct _ExecuteVisionOp_GetResult_Request_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_GetResult_Request_type_support_data_t;

static _ExecuteVisionOp_GetResult_Request_type_support_data_t _ExecuteVisionOp_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_GetResult_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_GetResult_Response_type_support_ids_t;

static const _ExecuteVisionOp_GetResult_Response_type_support_ids_t _ExecuteVisionOp_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_GetResult_Response_type_support_symbol_names_t _ExecuteVisionOp_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Response)),
  }
};

typedef struct _ExecuteVisionOp_GetResult_Response_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_GetResult_Response_type_support_data_t;

static _ExecuteVisionOp_GetResult_Response_type_support_data_t _ExecuteVisionOp_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_GetResult_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>();
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_GetResult_Event_type_support_ids_t;

static const _ExecuteVisionOp_GetResult_Event_type_support_ids_t _ExecuteVisionOp_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_GetResult_Event_type_support_symbol_names_t _ExecuteVisionOp_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Event)),
  }
};

typedef struct _ExecuteVisionOp_GetResult_Event_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_GetResult_Event_type_support_data_t;

static _ExecuteVisionOp_GetResult_Event_type_support_data_t _ExecuteVisionOp_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_GetResult_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_GetResult_type_support_ids_t;

static const _ExecuteVisionOp_GetResult_type_support_ids_t _ExecuteVisionOp_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_GetResult_type_support_symbol_names_t _ExecuteVisionOp_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult)),
  }
};

typedef struct _ExecuteVisionOp_GetResult_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_GetResult_type_support_data_t;

static _ExecuteVisionOp_GetResult_type_support_data_t _ExecuteVisionOp_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_GetResult_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecuteVisionOp_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::ExecuteVisionOp_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::ExecuteVisionOp_GetResult>,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _ExecuteVisionOp_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteVisionOp_FeedbackMessage_type_support_ids_t;

static const _ExecuteVisionOp_FeedbackMessage_type_support_ids_t _ExecuteVisionOp_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteVisionOp_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteVisionOp_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteVisionOp_FeedbackMessage_type_support_symbol_names_t _ExecuteVisionOp_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteVisionOp_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteVisionOp_FeedbackMessage)),
  }
};

typedef struct _ExecuteVisionOp_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _ExecuteVisionOp_FeedbackMessage_type_support_data_t;

static _ExecuteVisionOp_FeedbackMessage_type_support_data_t _ExecuteVisionOp_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteVisionOp_FeedbackMessage_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteVisionOp_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteVisionOp_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteVisionOp_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteVisionOp_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteVisionOp_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp_FeedbackMessage)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t ExecuteVisionOp_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &robokpy_interfaces__action__ExecuteVisionOp__get_type_hash,
  &robokpy_interfaces__action__ExecuteVisionOp__get_type_description,
  &robokpy_interfaces__action__ExecuteVisionOp__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp>()
{
  using ::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteVisionOp_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  ExecuteVisionOp_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::robokpy_interfaces::action::ExecuteVisionOp::Impl::SendGoalService>();
  ExecuteVisionOp_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::robokpy_interfaces::action::ExecuteVisionOp::Impl::GetResultService>();
  ExecuteVisionOp_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::robokpy_interfaces::action::ExecuteVisionOp::Impl::CancelGoalService>();
  ExecuteVisionOp_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::robokpy_interfaces::action::ExecuteVisionOp::Impl::FeedbackMessage>();
  ExecuteVisionOp_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::robokpy_interfaces::action::ExecuteVisionOp::Impl::GoalStatusMessage>();
  return &ExecuteVisionOp_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteVisionOp)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<robokpy_interfaces::action::ExecuteVisionOp>();
}

#ifdef __cplusplus
}
#endif
