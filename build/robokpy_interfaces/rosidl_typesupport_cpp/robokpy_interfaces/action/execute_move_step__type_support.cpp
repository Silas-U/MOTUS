// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:action/ExecuteMoveStep.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
#include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_Goal_type_support_ids_t;

static const _ExecuteMoveStep_Goal_type_support_ids_t _ExecuteMoveStep_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_Goal_type_support_symbol_names_t _ExecuteMoveStep_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_Goal)),
  }
};

typedef struct _ExecuteMoveStep_Goal_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_Goal_type_support_data_t;

static _ExecuteMoveStep_Goal_type_support_data_t _ExecuteMoveStep_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_Goal_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_Goal__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_Goal__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Goal>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_Goal)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Goal>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_Result_type_support_ids_t;

static const _ExecuteMoveStep_Result_type_support_ids_t _ExecuteMoveStep_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_Result_type_support_symbol_names_t _ExecuteMoveStep_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_Result)),
  }
};

typedef struct _ExecuteMoveStep_Result_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_Result_type_support_data_t;

static _ExecuteMoveStep_Result_type_support_data_t _ExecuteMoveStep_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_Result_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_Result_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_Result_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_Result__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_Result__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Result>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_Result)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Result>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_Feedback_type_support_ids_t;

static const _ExecuteMoveStep_Feedback_type_support_ids_t _ExecuteMoveStep_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_Feedback_type_support_symbol_names_t _ExecuteMoveStep_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_Feedback)),
  }
};

typedef struct _ExecuteMoveStep_Feedback_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_Feedback_type_support_data_t;

static _ExecuteMoveStep_Feedback_type_support_data_t _ExecuteMoveStep_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_Feedback_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_Feedback__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_Feedback__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Feedback>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_Feedback)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Feedback>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_SendGoal_Request_type_support_ids_t;

static const _ExecuteMoveStep_SendGoal_Request_type_support_ids_t _ExecuteMoveStep_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_SendGoal_Request_type_support_symbol_names_t _ExecuteMoveStep_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Request)),
  }
};

typedef struct _ExecuteMoveStep_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_SendGoal_Request_type_support_data_t;

static _ExecuteMoveStep_SendGoal_Request_type_support_data_t _ExecuteMoveStep_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_SendGoal_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_SendGoal_Response_type_support_ids_t;

static const _ExecuteMoveStep_SendGoal_Response_type_support_ids_t _ExecuteMoveStep_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_SendGoal_Response_type_support_symbol_names_t _ExecuteMoveStep_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Response)),
  }
};

typedef struct _ExecuteMoveStep_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_SendGoal_Response_type_support_data_t;

static _ExecuteMoveStep_SendGoal_Response_type_support_data_t _ExecuteMoveStep_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_SendGoal_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_SendGoal_Event_type_support_ids_t;

static const _ExecuteMoveStep_SendGoal_Event_type_support_ids_t _ExecuteMoveStep_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_SendGoal_Event_type_support_symbol_names_t _ExecuteMoveStep_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Event)),
  }
};

typedef struct _ExecuteMoveStep_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_SendGoal_Event_type_support_data_t;

static _ExecuteMoveStep_SendGoal_Event_type_support_data_t _ExecuteMoveStep_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_SendGoal_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_SendGoal_type_support_ids_t;

static const _ExecuteMoveStep_SendGoal_type_support_ids_t _ExecuteMoveStep_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_SendGoal_type_support_symbol_names_t _ExecuteMoveStep_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal)),
  }
};

typedef struct _ExecuteMoveStep_SendGoal_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_SendGoal_type_support_data_t;

static _ExecuteMoveStep_SendGoal_type_support_data_t _ExecuteMoveStep_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_SendGoal_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecuteMoveStep_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_GetResult_Request_type_support_ids_t;

static const _ExecuteMoveStep_GetResult_Request_type_support_ids_t _ExecuteMoveStep_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_GetResult_Request_type_support_symbol_names_t _ExecuteMoveStep_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Request)),
  }
};

typedef struct _ExecuteMoveStep_GetResult_Request_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_GetResult_Request_type_support_data_t;

static _ExecuteMoveStep_GetResult_Request_type_support_data_t _ExecuteMoveStep_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_GetResult_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Request)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_GetResult_Response_type_support_ids_t;

static const _ExecuteMoveStep_GetResult_Response_type_support_ids_t _ExecuteMoveStep_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_GetResult_Response_type_support_symbol_names_t _ExecuteMoveStep_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Response)),
  }
};

typedef struct _ExecuteMoveStep_GetResult_Response_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_GetResult_Response_type_support_data_t;

static _ExecuteMoveStep_GetResult_Response_type_support_data_t _ExecuteMoveStep_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_GetResult_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Response)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_GetResult_Event_type_support_ids_t;

static const _ExecuteMoveStep_GetResult_Event_type_support_ids_t _ExecuteMoveStep_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_GetResult_Event_type_support_symbol_names_t _ExecuteMoveStep_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Event)),
  }
};

typedef struct _ExecuteMoveStep_GetResult_Event_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_GetResult_Event_type_support_data_t;

static _ExecuteMoveStep_GetResult_Event_type_support_data_t _ExecuteMoveStep_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_GetResult_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Event)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_GetResult_type_support_ids_t;

static const _ExecuteMoveStep_GetResult_type_support_ids_t _ExecuteMoveStep_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_GetResult_type_support_symbol_names_t _ExecuteMoveStep_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult)),
  }
};

typedef struct _ExecuteMoveStep_GetResult_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_GetResult_type_support_data_t;

static _ExecuteMoveStep_GetResult_type_support_data_t _ExecuteMoveStep_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_GetResult_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ExecuteMoveStep_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::ExecuteMoveStep_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::ExecuteMoveStep_GetResult>,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

typedef struct _ExecuteMoveStep_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ExecuteMoveStep_FeedbackMessage_type_support_ids_t;

static const _ExecuteMoveStep_FeedbackMessage_type_support_ids_t _ExecuteMoveStep_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ExecuteMoveStep_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ExecuteMoveStep_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ExecuteMoveStep_FeedbackMessage_type_support_symbol_names_t _ExecuteMoveStep_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, ExecuteMoveStep_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_FeedbackMessage)),
  }
};

typedef struct _ExecuteMoveStep_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _ExecuteMoveStep_FeedbackMessage_type_support_data_t;

static _ExecuteMoveStep_FeedbackMessage_type_support_data_t _ExecuteMoveStep_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ExecuteMoveStep_FeedbackMessage_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_ExecuteMoveStep_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_ExecuteMoveStep_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_ExecuteMoveStep_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ExecuteMoveStep_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ExecuteMoveStep_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep_FeedbackMessage)() {
  return get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

static rosidl_action_type_support_t ExecuteMoveStep_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &robokpy_interfaces__action__ExecuteMoveStep__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep>()
{
  using ::robokpy_interfaces::action::rosidl_typesupport_cpp::ExecuteMoveStep_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  ExecuteMoveStep_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::robokpy_interfaces::action::ExecuteMoveStep::Impl::SendGoalService>();
  ExecuteMoveStep_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::robokpy_interfaces::action::ExecuteMoveStep::Impl::GetResultService>();
  ExecuteMoveStep_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::robokpy_interfaces::action::ExecuteMoveStep::Impl::CancelGoalService>();
  ExecuteMoveStep_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::robokpy_interfaces::action::ExecuteMoveStep::Impl::FeedbackMessage>();
  ExecuteMoveStep_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::robokpy_interfaces::action::ExecuteMoveStep::Impl::GoalStatusMessage>();
  return &ExecuteMoveStep_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, robokpy_interfaces, action, ExecuteMoveStep)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep>();
}

#ifdef __cplusplus
}
#endif
