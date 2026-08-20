// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:action/PlanTrajectory.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
#include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
#include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_Goal_type_support_ids_t;

static const _PlanTrajectory_Goal_type_support_ids_t _PlanTrajectory_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_Goal_type_support_symbol_names_t _PlanTrajectory_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Goal)),
  }
};

typedef struct _PlanTrajectory_Goal_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_Goal_type_support_data_t;

static _PlanTrajectory_Goal_type_support_data_t _PlanTrajectory_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_Goal_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_Goal__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_Goal__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_Goal)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_Result_type_support_ids_t;

static const _PlanTrajectory_Result_type_support_ids_t _PlanTrajectory_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_Result_type_support_symbol_names_t _PlanTrajectory_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Result)),
  }
};

typedef struct _PlanTrajectory_Result_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_Result_type_support_data_t;

static _PlanTrajectory_Result_type_support_data_t _PlanTrajectory_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_Result_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_Result_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_Result_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_Result__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_Result__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_Result)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_Feedback_type_support_ids_t;

static const _PlanTrajectory_Feedback_type_support_ids_t _PlanTrajectory_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_Feedback_type_support_symbol_names_t _PlanTrajectory_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Feedback)),
  }
};

typedef struct _PlanTrajectory_Feedback_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_Feedback_type_support_data_t;

static _PlanTrajectory_Feedback_type_support_data_t _PlanTrajectory_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_Feedback_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_Feedback)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_SendGoal_Request_type_support_ids_t;

static const _PlanTrajectory_SendGoal_Request_type_support_ids_t _PlanTrajectory_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_SendGoal_Request_type_support_symbol_names_t _PlanTrajectory_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)),
  }
};

typedef struct _PlanTrajectory_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_SendGoal_Request_type_support_data_t;

static _PlanTrajectory_SendGoal_Request_type_support_data_t _PlanTrajectory_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_SendGoal_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_SendGoal_Response_type_support_ids_t;

static const _PlanTrajectory_SendGoal_Response_type_support_ids_t _PlanTrajectory_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_SendGoal_Response_type_support_symbol_names_t _PlanTrajectory_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)),
  }
};

typedef struct _PlanTrajectory_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_SendGoal_Response_type_support_data_t;

static _PlanTrajectory_SendGoal_Response_type_support_data_t _PlanTrajectory_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_SendGoal_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_SendGoal_Event_type_support_ids_t;

static const _PlanTrajectory_SendGoal_Event_type_support_ids_t _PlanTrajectory_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_SendGoal_Event_type_support_symbol_names_t _PlanTrajectory_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Event)),
  }
};

typedef struct _PlanTrajectory_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_SendGoal_Event_type_support_data_t;

static _PlanTrajectory_SendGoal_Event_type_support_data_t _PlanTrajectory_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_SendGoal_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Event)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
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
typedef struct _PlanTrajectory_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_SendGoal_type_support_ids_t;

static const _PlanTrajectory_SendGoal_type_support_ids_t _PlanTrajectory_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_SendGoal_type_support_symbol_names_t _PlanTrajectory_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal)),
  }
};

typedef struct _PlanTrajectory_SendGoal_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_SendGoal_type_support_data_t;

static _PlanTrajectory_SendGoal_type_support_data_t _PlanTrajectory_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_SendGoal_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PlanTrajectory_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &PlanTrajectory_SendGoal_Request_message_type_support_handle,
  &PlanTrajectory_SendGoal_Response_message_type_support_handle,
  &PlanTrajectory_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_SendGoal
  ),
  &robokpy_interfaces__action__PlanTrajectory_SendGoal__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_SendGoal)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_GetResult_Request_type_support_ids_t;

static const _PlanTrajectory_GetResult_Request_type_support_ids_t _PlanTrajectory_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_GetResult_Request_type_support_symbol_names_t _PlanTrajectory_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)),
  }
};

typedef struct _PlanTrajectory_GetResult_Request_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_GetResult_Request_type_support_data_t;

static _PlanTrajectory_GetResult_Request_type_support_data_t _PlanTrajectory_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_GetResult_Request_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_GetResult_Response_type_support_ids_t;

static const _PlanTrajectory_GetResult_Response_type_support_ids_t _PlanTrajectory_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_GetResult_Response_type_support_symbol_names_t _PlanTrajectory_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)),
  }
};

typedef struct _PlanTrajectory_GetResult_Response_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_GetResult_Response_type_support_data_t;

static _PlanTrajectory_GetResult_Response_type_support_data_t _PlanTrajectory_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_GetResult_Response_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_GetResult_Event_type_support_ids_t;

static const _PlanTrajectory_GetResult_Event_type_support_ids_t _PlanTrajectory_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_GetResult_Event_type_support_symbol_names_t _PlanTrajectory_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Event)),
  }
};

typedef struct _PlanTrajectory_GetResult_Event_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_GetResult_Event_type_support_data_t;

static _PlanTrajectory_GetResult_Event_type_support_data_t _PlanTrajectory_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_GetResult_Event_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Event)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
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
typedef struct _PlanTrajectory_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_GetResult_type_support_ids_t;

static const _PlanTrajectory_GetResult_type_support_ids_t _PlanTrajectory_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_GetResult_type_support_symbol_names_t _PlanTrajectory_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult)),
  }
};

typedef struct _PlanTrajectory_GetResult_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_GetResult_type_support_data_t;

static _PlanTrajectory_GetResult_type_support_data_t _PlanTrajectory_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_GetResult_service_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t PlanTrajectory_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &PlanTrajectory_GetResult_Request_message_type_support_handle,
  &PlanTrajectory_GetResult_Response_message_type_support_handle,
  &PlanTrajectory_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_GetResult
  ),
  &robokpy_interfaces__action__PlanTrajectory_GetResult__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_GetResult)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
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

typedef struct _PlanTrajectory_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _PlanTrajectory_FeedbackMessage_type_support_ids_t;

static const _PlanTrajectory_FeedbackMessage_type_support_ids_t _PlanTrajectory_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _PlanTrajectory_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _PlanTrajectory_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _PlanTrajectory_FeedbackMessage_type_support_symbol_names_t _PlanTrajectory_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, action, PlanTrajectory_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_FeedbackMessage)),
  }
};

typedef struct _PlanTrajectory_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _PlanTrajectory_FeedbackMessage_type_support_data_t;

static _PlanTrajectory_FeedbackMessage_type_support_data_t _PlanTrajectory_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _PlanTrajectory_FeedbackMessage_message_typesupport_map = {
  2,
  "robokpy_interfaces",
  &_PlanTrajectory_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_PlanTrajectory_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_PlanTrajectory_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t PlanTrajectory_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_PlanTrajectory_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace robokpy_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_FeedbackMessage)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_c::PlanTrajectory_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "robokpy_interfaces/action/plan_trajectory.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__type_support.h"

static rosidl_action_type_support_t _robokpy_interfaces__action__PlanTrajectory__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &robokpy_interfaces__action__PlanTrajectory__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory)()
{
  // Thread-safe by always writing the same values to the static struct
  _robokpy_interfaces__action__PlanTrajectory__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_SendGoal)();
  _robokpy_interfaces__action__PlanTrajectory__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_GetResult)();
  _robokpy_interfaces__action__PlanTrajectory__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _robokpy_interfaces__action__PlanTrajectory__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, robokpy_interfaces, action, PlanTrajectory_FeedbackMessage)();
  _robokpy_interfaces__action__PlanTrajectory__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_robokpy_interfaces__action__PlanTrajectory__typesupport_c;
}

#ifdef __cplusplus
}
#endif
