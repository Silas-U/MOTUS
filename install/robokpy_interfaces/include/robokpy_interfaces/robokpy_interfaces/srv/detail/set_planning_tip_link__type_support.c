// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robokpy_interfaces:srv/SetPlanningTipLink.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robokpy_interfaces/srv/detail/set_planning_tip_link__rosidl_typesupport_introspection_c.h"
#include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robokpy_interfaces/srv/detail/set_planning_tip_link__functions.h"
#include "robokpy_interfaces/srv/detail/set_planning_tip_link__struct.h"


// Include directives for member types
// Member `tip_link`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__srv__SetPlanningTipLink_Request__init(message_memory);
}

void robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_fini_function(void * message_memory)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_member_array[1] = {
  {
    "tip_link",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__srv__SetPlanningTipLink_Request, tip_link),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_members = {
  "robokpy_interfaces__srv",  // message namespace
  "SetPlanningTipLink_Request",  // message name
  1,  // number of fields
  sizeof(robokpy_interfaces__srv__SetPlanningTipLink_Request),
  false,  // has_any_key_member_
  robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_member_array,  // message members
  robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_type_support_handle = {
  0,
  &robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__SetPlanningTipLink_Request__get_type_hash,
  &robokpy_interfaces__srv__SetPlanningTipLink_Request__get_type_description,
  &robokpy_interfaces__srv__SetPlanningTipLink_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Request)() {
  if (!robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__srv__SetPlanningTipLink_Response__init(message_memory);
}

void robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_fini_function(void * message_memory)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__srv__SetPlanningTipLink_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__srv__SetPlanningTipLink_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_members = {
  "robokpy_interfaces__srv",  // message namespace
  "SetPlanningTipLink_Response",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces__srv__SetPlanningTipLink_Response),
  false,  // has_any_key_member_
  robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_member_array,  // message members
  robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle = {
  0,
  &robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__SetPlanningTipLink_Response__get_type_hash,
  &robokpy_interfaces__srv__SetPlanningTipLink_Response__get_type_description,
  &robokpy_interfaces__srv__SetPlanningTipLink_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Response)() {
  if (!robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "robokpy_interfaces/srv/set_planning_tip_link.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__srv__SetPlanningTipLink_Event__init(message_memory);
}

void robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_fini_function(void * message_memory)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Event__fini(message_memory);
}

size_t robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__size_function__SetPlanningTipLink_Event__request(
  const void * untyped_member)
{
  const robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence * member =
    (const robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_const_function__SetPlanningTipLink_Event__request(
  const void * untyped_member, size_t index)
{
  const robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence * member =
    (const robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_function__SetPlanningTipLink_Event__request(
  void * untyped_member, size_t index)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence * member =
    (robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__fetch_function__SetPlanningTipLink_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robokpy_interfaces__srv__SetPlanningTipLink_Request * item =
    ((const robokpy_interfaces__srv__SetPlanningTipLink_Request *)
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_const_function__SetPlanningTipLink_Event__request(untyped_member, index));
  robokpy_interfaces__srv__SetPlanningTipLink_Request * value =
    (robokpy_interfaces__srv__SetPlanningTipLink_Request *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__assign_function__SetPlanningTipLink_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Request * item =
    ((robokpy_interfaces__srv__SetPlanningTipLink_Request *)
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_function__SetPlanningTipLink_Event__request(untyped_member, index));
  const robokpy_interfaces__srv__SetPlanningTipLink_Request * value =
    (const robokpy_interfaces__srv__SetPlanningTipLink_Request *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__resize_function__SetPlanningTipLink_Event__request(
  void * untyped_member, size_t size)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence * member =
    (robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence *)(untyped_member);
  robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence__fini(member);
  return robokpy_interfaces__srv__SetPlanningTipLink_Request__Sequence__init(member, size);
}

size_t robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__size_function__SetPlanningTipLink_Event__response(
  const void * untyped_member)
{
  const robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence * member =
    (const robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_const_function__SetPlanningTipLink_Event__response(
  const void * untyped_member, size_t index)
{
  const robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence * member =
    (const robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_function__SetPlanningTipLink_Event__response(
  void * untyped_member, size_t index)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence * member =
    (robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__fetch_function__SetPlanningTipLink_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robokpy_interfaces__srv__SetPlanningTipLink_Response * item =
    ((const robokpy_interfaces__srv__SetPlanningTipLink_Response *)
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_const_function__SetPlanningTipLink_Event__response(untyped_member, index));
  robokpy_interfaces__srv__SetPlanningTipLink_Response * value =
    (robokpy_interfaces__srv__SetPlanningTipLink_Response *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__assign_function__SetPlanningTipLink_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Response * item =
    ((robokpy_interfaces__srv__SetPlanningTipLink_Response *)
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_function__SetPlanningTipLink_Event__response(untyped_member, index));
  const robokpy_interfaces__srv__SetPlanningTipLink_Response * value =
    (const robokpy_interfaces__srv__SetPlanningTipLink_Response *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__resize_function__SetPlanningTipLink_Event__response(
  void * untyped_member, size_t size)
{
  robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence * member =
    (robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence *)(untyped_member);
  robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence__fini(member);
  return robokpy_interfaces__srv__SetPlanningTipLink_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__srv__SetPlanningTipLink_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces__srv__SetPlanningTipLink_Event, request),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__size_function__SetPlanningTipLink_Event__request,  // size() function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_const_function__SetPlanningTipLink_Event__request,  // get_const(index) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_function__SetPlanningTipLink_Event__request,  // get(index) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__fetch_function__SetPlanningTipLink_Event__request,  // fetch(index, &value) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__assign_function__SetPlanningTipLink_Event__request,  // assign(index, value) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__resize_function__SetPlanningTipLink_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces__srv__SetPlanningTipLink_Event, response),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__size_function__SetPlanningTipLink_Event__response,  // size() function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_const_function__SetPlanningTipLink_Event__response,  // get_const(index) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__get_function__SetPlanningTipLink_Event__response,  // get(index) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__fetch_function__SetPlanningTipLink_Event__response,  // fetch(index, &value) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__assign_function__SetPlanningTipLink_Event__response,  // assign(index, value) function pointer
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__resize_function__SetPlanningTipLink_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_members = {
  "robokpy_interfaces__srv",  // message namespace
  "SetPlanningTipLink_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces__srv__SetPlanningTipLink_Event),
  false,  // has_any_key_member_
  robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_member_array,  // message members
  robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_type_support_handle = {
  0,
  &robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__SetPlanningTipLink_Event__get_type_hash,
  &robokpy_interfaces__srv__SetPlanningTipLink_Event__get_type_description,
  &robokpy_interfaces__srv__SetPlanningTipLink_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Event)() {
  robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Request)();
  robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Response)();
  if (!robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "robokpy_interfaces/srv/detail/set_planning_tip_link__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_members = {
  "robokpy_interfaces__srv",  // service namespace
  "SetPlanningTipLink",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_type_support_handle,
  NULL,  // response message
  // robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle
  NULL  // event_message
  // robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle
};


static rosidl_service_type_support_t robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_type_support_handle = {
  0,
  &robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_members,
  get_service_typesupport_handle_function,
  &robokpy_interfaces__srv__SetPlanningTipLink_Request__rosidl_typesupport_introspection_c__SetPlanningTipLink_Request_message_type_support_handle,
  &robokpy_interfaces__srv__SetPlanningTipLink_Response__rosidl_typesupport_introspection_c__SetPlanningTipLink_Response_message_type_support_handle,
  &robokpy_interfaces__srv__SetPlanningTipLink_Event__rosidl_typesupport_introspection_c__SetPlanningTipLink_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    SetPlanningTipLink
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    srv,
    SetPlanningTipLink
  ),
  &robokpy_interfaces__srv__SetPlanningTipLink__get_type_hash,
  &robokpy_interfaces__srv__SetPlanningTipLink__get_type_description,
  &robokpy_interfaces__srv__SetPlanningTipLink__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink)(void) {
  if (!robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, srv, SetPlanningTipLink_Event)()->data;
  }

  return &robokpy_interfaces__srv__detail__set_planning_tip_link__rosidl_typesupport_introspection_c__SetPlanningTipLink_service_type_support_handle;
}
