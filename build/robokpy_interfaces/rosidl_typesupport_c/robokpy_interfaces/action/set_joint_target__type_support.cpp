// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:action/SetJointTarget.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
#include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
#include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_Goal_type_support_ids_t;

static const _SetJointTarget_Goal_type_support_ids_t _SetJointTarget_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_Goal_type_support_symbol_names_t _SetJointTarget_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_Goal)),
  }
};

typedef struct _SetJointTarget_Goal_type_support_data_t
{
  void * data[2];
} _SetJointTarget_Goal_type_support_data_t;

static _SetJointTarget_Goal_type_support_data_t _SetJointTarget_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_Goal_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_Goal__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_Goal__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_Goal)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_Result_type_support_ids_t;

static const _SetJointTarget_Result_type_support_ids_t _SetJointTarget_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_Result_type_support_symbol_names_t _SetJointTarget_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_Result)),
  }
};

typedef struct _SetJointTarget_Result_type_support_data_t
{
  void * data[2];
} _SetJointTarget_Result_type_support_data_t;

static _SetJointTarget_Result_type_support_data_t _SetJointTarget_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_Result_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_Result_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_Result_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_Result__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_Result__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_Result)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_Feedback_type_support_ids_t;

static const _SetJointTarget_Feedback_type_support_ids_t _SetJointTarget_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_Feedback_type_support_symbol_names_t _SetJointTarget_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_Feedback)),
  }
};

typedef struct _SetJointTarget_Feedback_type_support_data_t
{
  void * data[2];
} _SetJointTarget_Feedback_type_support_data_t;

static _SetJointTarget_Feedback_type_support_data_t _SetJointTarget_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_Feedback_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_Feedback__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_Feedback__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_Feedback)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_SendGoal_Request_type_support_ids_t;

static const _SetJointTarget_SendGoal_Request_type_support_ids_t _SetJointTarget_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_SendGoal_Request_type_support_symbol_names_t _SetJointTarget_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Request)),
  }
};

typedef struct _SetJointTarget_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _SetJointTarget_SendGoal_Request_type_support_data_t;

static _SetJointTarget_SendGoal_Request_type_support_data_t _SetJointTarget_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_SendGoal_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Request)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_SendGoal_Response_type_support_ids_t;

static const _SetJointTarget_SendGoal_Response_type_support_ids_t _SetJointTarget_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_SendGoal_Response_type_support_symbol_names_t _SetJointTarget_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Response)),
  }
};

typedef struct _SetJointTarget_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _SetJointTarget_SendGoal_Response_type_support_data_t;

static _SetJointTarget_SendGoal_Response_type_support_data_t _SetJointTarget_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_SendGoal_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Response)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_SendGoal_Event_type_support_ids_t;

static const _SetJointTarget_SendGoal_Event_type_support_ids_t _SetJointTarget_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_SendGoal_Event_type_support_symbol_names_t _SetJointTarget_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Event)),
  }
};

typedef struct _SetJointTarget_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _SetJointTarget_SendGoal_Event_type_support_data_t;

static _SetJointTarget_SendGoal_Event_type_support_data_t _SetJointTarget_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_SendGoal_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_SendGoal_Event)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
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

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _SetJointTarget_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_SendGoal_type_support_ids_t;

static const _SetJointTarget_SendGoal_type_support_ids_t _SetJointTarget_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_SendGoal_type_support_symbol_names_t _SetJointTarget_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_SendGoal)),
  }
};

typedef struct _SetJointTarget_SendGoal_type_support_data_t
{
  void * data[2];
} _SetJointTarget_SendGoal_type_support_data_t;

static _SetJointTarget_SendGoal_type_support_data_t _SetJointTarget_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_SendGoal_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetJointTarget_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &SetJointTarget_SendGoal_Request_message_type_support_handle,
  &SetJointTarget_SendGoal_Response_message_type_support_handle,
  &SetJointTarget_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    SetJointTarget_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    SetJointTarget_SendGoal
  ),
  &robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_SendGoal)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_GetResult_Request_type_support_ids_t;

static const _SetJointTarget_GetResult_Request_type_support_ids_t _SetJointTarget_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_GetResult_Request_type_support_symbol_names_t _SetJointTarget_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_GetResult_Request)),
  }
};

typedef struct _SetJointTarget_GetResult_Request_type_support_data_t
{
  void * data[2];
} _SetJointTarget_GetResult_Request_type_support_data_t;

static _SetJointTarget_GetResult_Request_type_support_data_t _SetJointTarget_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_GetResult_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_GetResult_Request)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_GetResult_Response_type_support_ids_t;

static const _SetJointTarget_GetResult_Response_type_support_ids_t _SetJointTarget_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_GetResult_Response_type_support_symbol_names_t _SetJointTarget_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_GetResult_Response)),
  }
};

typedef struct _SetJointTarget_GetResult_Response_type_support_data_t
{
  void * data[2];
} _SetJointTarget_GetResult_Response_type_support_data_t;

static _SetJointTarget_GetResult_Response_type_support_data_t _SetJointTarget_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_GetResult_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_GetResult_Response)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_GetResult_Event_type_support_ids_t;

static const _SetJointTarget_GetResult_Event_type_support_ids_t _SetJointTarget_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_GetResult_Event_type_support_symbol_names_t _SetJointTarget_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_GetResult_Event)),
  }
};

typedef struct _SetJointTarget_GetResult_Event_type_support_data_t
{
  void * data[2];
} _SetJointTarget_GetResult_Event_type_support_data_t;

static _SetJointTarget_GetResult_Event_type_support_data_t _SetJointTarget_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_GetResult_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_GetResult_Event)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "service_msgs/msg/service_event_info.h"
// already included above
// #include "builtin_interfaces/msg/time.h"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _SetJointTarget_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_GetResult_type_support_ids_t;

static const _SetJointTarget_GetResult_type_support_ids_t _SetJointTarget_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_GetResult_type_support_symbol_names_t _SetJointTarget_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_GetResult)),
  }
};

typedef struct _SetJointTarget_GetResult_type_support_data_t
{
  void * data[2];
} _SetJointTarget_GetResult_type_support_data_t;

static _SetJointTarget_GetResult_type_support_data_t _SetJointTarget_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_GetResult_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t SetJointTarget_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &SetJointTarget_GetResult_Request_message_type_support_handle,
  &SetJointTarget_GetResult_Response_message_type_support_handle,
  &SetJointTarget_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    SetJointTarget_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    SetJointTarget_GetResult
  ),
  &robokpy_interfaces__action__SetJointTarget_GetResult__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_GetResult)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
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

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _SetJointTarget_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _SetJointTarget_FeedbackMessage_type_support_ids_t;

static const _SetJointTarget_FeedbackMessage_type_support_ids_t _SetJointTarget_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _SetJointTarget_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _SetJointTarget_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _SetJointTarget_FeedbackMessage_type_support_symbol_names_t _SetJointTarget_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, SetJointTarget_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, SetJointTarget_FeedbackMessage)),
  }
};

typedef struct _SetJointTarget_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _SetJointTarget_FeedbackMessage_type_support_data_t;

static _SetJointTarget_FeedbackMessage_type_support_data_t _SetJointTarget_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _SetJointTarget_FeedbackMessage_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_SetJointTarget_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_SetJointTarget_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_SetJointTarget_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t SetJointTarget_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_SetJointTarget_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_FeedbackMessage)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::SetJointTarget_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "robokpy_interfaces/action/set_joint_target.h"
// already included above
// #include "robokpy_interfaces/action/detail/set_joint_target__type_support.h"

static rosidl_action_type_support_t _robokpy_interfaces__action__SetJointTarget__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &robokpy_interfaces__action__SetJointTarget__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget__get_type_description,
  &robokpy_interfaces__action__SetJointTarget__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget)()
{
  // Thread-safe by always writing the same values to the static struct
  _robokpy_interfaces__action__SetJointTarget__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_SendGoal)();
  _robokpy_interfaces__action__SetJointTarget__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_GetResult)();
  _robokpy_interfaces__action__SetJointTarget__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _robokpy_interfaces__action__SetJointTarget__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, robokpy_interfaces, action, SetJointTarget_FeedbackMessage)();
  _robokpy_interfaces__action__SetJointTarget__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_robokpy_interfaces__action__SetJointTarget__typesupport_c;
}

#ifdef __cplusplus
}
#endif
