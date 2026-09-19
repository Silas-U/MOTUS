// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mypalletizer_interfaces:srv/SetAngles.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mypalletizer_interfaces/srv/detail/set_angles__rosidl_typesupport_introspection_c.h"
#include "mypalletizer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mypalletizer_interfaces/srv/detail/set_angles__functions.h"
#include "mypalletizer_interfaces/srv/detail/set_angles__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mypalletizer_interfaces__srv__SetAngles_Request__init(message_memory);
}

void mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_fini_function(void * message_memory)
{
  mypalletizer_interfaces__srv__SetAngles_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_member_array[5] = {
  {
    "joint_1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Request, joint_1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Request, joint_2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Request, joint_3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Request, joint_4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Request, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_members = {
  "mypalletizer_interfaces__srv",  // message namespace
  "SetAngles_Request",  // message name
  5,  // number of fields
  sizeof(mypalletizer_interfaces__srv__SetAngles_Request),
  false,  // has_any_key_member_
  mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_member_array,  // message members
  mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_type_support_handle = {
  0,
  &mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_members,
  get_message_typesupport_handle_function,
  &mypalletizer_interfaces__srv__SetAngles_Request__get_type_hash,
  &mypalletizer_interfaces__srv__SetAngles_Request__get_type_description,
  &mypalletizer_interfaces__srv__SetAngles_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mypalletizer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Request)() {
  if (!mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_type_support_handle.typesupport_identifier) {
    mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "mypalletizer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__functions.h"
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mypalletizer_interfaces__srv__SetAngles_Response__init(message_memory);
}

void mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_fini_function(void * message_memory)
{
  mypalletizer_interfaces__srv__SetAngles_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_member_array[1] = {
  {
    "flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Response, flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_members = {
  "mypalletizer_interfaces__srv",  // message namespace
  "SetAngles_Response",  // message name
  1,  // number of fields
  sizeof(mypalletizer_interfaces__srv__SetAngles_Response),
  false,  // has_any_key_member_
  mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_member_array,  // message members
  mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle = {
  0,
  &mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_members,
  get_message_typesupport_handle_function,
  &mypalletizer_interfaces__srv__SetAngles_Response__get_type_hash,
  &mypalletizer_interfaces__srv__SetAngles_Response__get_type_description,
  &mypalletizer_interfaces__srv__SetAngles_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mypalletizer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Response)() {
  if (!mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle.typesupport_identifier) {
    mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "mypalletizer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__functions.h"
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "mypalletizer_interfaces/srv/set_angles.h"
// Member `request`
// Member `response`
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mypalletizer_interfaces__srv__SetAngles_Event__init(message_memory);
}

void mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_fini_function(void * message_memory)
{
  mypalletizer_interfaces__srv__SetAngles_Event__fini(message_memory);
}

size_t mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__size_function__SetAngles_Event__request(
  const void * untyped_member)
{
  const mypalletizer_interfaces__srv__SetAngles_Request__Sequence * member =
    (const mypalletizer_interfaces__srv__SetAngles_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_const_function__SetAngles_Event__request(
  const void * untyped_member, size_t index)
{
  const mypalletizer_interfaces__srv__SetAngles_Request__Sequence * member =
    (const mypalletizer_interfaces__srv__SetAngles_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_function__SetAngles_Event__request(
  void * untyped_member, size_t index)
{
  mypalletizer_interfaces__srv__SetAngles_Request__Sequence * member =
    (mypalletizer_interfaces__srv__SetAngles_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__fetch_function__SetAngles_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mypalletizer_interfaces__srv__SetAngles_Request * item =
    ((const mypalletizer_interfaces__srv__SetAngles_Request *)
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_const_function__SetAngles_Event__request(untyped_member, index));
  mypalletizer_interfaces__srv__SetAngles_Request * value =
    (mypalletizer_interfaces__srv__SetAngles_Request *)(untyped_value);
  *value = *item;
}

void mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__assign_function__SetAngles_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mypalletizer_interfaces__srv__SetAngles_Request * item =
    ((mypalletizer_interfaces__srv__SetAngles_Request *)
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_function__SetAngles_Event__request(untyped_member, index));
  const mypalletizer_interfaces__srv__SetAngles_Request * value =
    (const mypalletizer_interfaces__srv__SetAngles_Request *)(untyped_value);
  *item = *value;
}

bool mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__resize_function__SetAngles_Event__request(
  void * untyped_member, size_t size)
{
  mypalletizer_interfaces__srv__SetAngles_Request__Sequence * member =
    (mypalletizer_interfaces__srv__SetAngles_Request__Sequence *)(untyped_member);
  mypalletizer_interfaces__srv__SetAngles_Request__Sequence__fini(member);
  return mypalletizer_interfaces__srv__SetAngles_Request__Sequence__init(member, size);
}

size_t mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__size_function__SetAngles_Event__response(
  const void * untyped_member)
{
  const mypalletizer_interfaces__srv__SetAngles_Response__Sequence * member =
    (const mypalletizer_interfaces__srv__SetAngles_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_const_function__SetAngles_Event__response(
  const void * untyped_member, size_t index)
{
  const mypalletizer_interfaces__srv__SetAngles_Response__Sequence * member =
    (const mypalletizer_interfaces__srv__SetAngles_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_function__SetAngles_Event__response(
  void * untyped_member, size_t index)
{
  mypalletizer_interfaces__srv__SetAngles_Response__Sequence * member =
    (mypalletizer_interfaces__srv__SetAngles_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__fetch_function__SetAngles_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const mypalletizer_interfaces__srv__SetAngles_Response * item =
    ((const mypalletizer_interfaces__srv__SetAngles_Response *)
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_const_function__SetAngles_Event__response(untyped_member, index));
  mypalletizer_interfaces__srv__SetAngles_Response * value =
    (mypalletizer_interfaces__srv__SetAngles_Response *)(untyped_value);
  *value = *item;
}

void mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__assign_function__SetAngles_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  mypalletizer_interfaces__srv__SetAngles_Response * item =
    ((mypalletizer_interfaces__srv__SetAngles_Response *)
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_function__SetAngles_Event__response(untyped_member, index));
  const mypalletizer_interfaces__srv__SetAngles_Response * value =
    (const mypalletizer_interfaces__srv__SetAngles_Response *)(untyped_value);
  *item = *value;
}

bool mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__resize_function__SetAngles_Event__response(
  void * untyped_member, size_t size)
{
  mypalletizer_interfaces__srv__SetAngles_Response__Sequence * member =
    (mypalletizer_interfaces__srv__SetAngles_Response__Sequence *)(untyped_member);
  mypalletizer_interfaces__srv__SetAngles_Response__Sequence__fini(member);
  return mypalletizer_interfaces__srv__SetAngles_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mypalletizer_interfaces__srv__SetAngles_Event, info),  // bytes offset in struct
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
    offsetof(mypalletizer_interfaces__srv__SetAngles_Event, request),  // bytes offset in struct
    NULL,  // default value
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__size_function__SetAngles_Event__request,  // size() function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_const_function__SetAngles_Event__request,  // get_const(index) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_function__SetAngles_Event__request,  // get(index) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__fetch_function__SetAngles_Event__request,  // fetch(index, &value) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__assign_function__SetAngles_Event__request,  // assign(index, value) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__resize_function__SetAngles_Event__request  // resize(index) function pointer
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
    offsetof(mypalletizer_interfaces__srv__SetAngles_Event, response),  // bytes offset in struct
    NULL,  // default value
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__size_function__SetAngles_Event__response,  // size() function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_const_function__SetAngles_Event__response,  // get_const(index) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__get_function__SetAngles_Event__response,  // get(index) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__fetch_function__SetAngles_Event__response,  // fetch(index, &value) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__assign_function__SetAngles_Event__response,  // assign(index, value) function pointer
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__resize_function__SetAngles_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_members = {
  "mypalletizer_interfaces__srv",  // message namespace
  "SetAngles_Event",  // message name
  3,  // number of fields
  sizeof(mypalletizer_interfaces__srv__SetAngles_Event),
  false,  // has_any_key_member_
  mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_member_array,  // message members
  mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_type_support_handle = {
  0,
  &mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_members,
  get_message_typesupport_handle_function,
  &mypalletizer_interfaces__srv__SetAngles_Event__get_type_hash,
  &mypalletizer_interfaces__srv__SetAngles_Event__get_type_description,
  &mypalletizer_interfaces__srv__SetAngles_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mypalletizer_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Event)() {
  mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Request)();
  mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Response)();
  if (!mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_type_support_handle.typesupport_identifier) {
    mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mypalletizer_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "mypalletizer_interfaces/srv/detail/set_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_members = {
  "mypalletizer_interfaces__srv",  // service namespace
  "SetAngles",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_Request_message_type_support_handle,
  NULL,  // response message
  // mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle
  NULL  // event_message
  // mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle
};


static rosidl_service_type_support_t mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_type_support_handle = {
  0,
  &mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_members,
  get_service_typesupport_handle_function,
  &mypalletizer_interfaces__srv__SetAngles_Request__rosidl_typesupport_introspection_c__SetAngles_Request_message_type_support_handle,
  &mypalletizer_interfaces__srv__SetAngles_Response__rosidl_typesupport_introspection_c__SetAngles_Response_message_type_support_handle,
  &mypalletizer_interfaces__srv__SetAngles_Event__rosidl_typesupport_introspection_c__SetAngles_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    mypalletizer_interfaces,
    srv,
    SetAngles
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    mypalletizer_interfaces,
    srv,
    SetAngles
  ),
  &mypalletizer_interfaces__srv__SetAngles__get_type_hash,
  &mypalletizer_interfaces__srv__SetAngles__get_type_description,
  &mypalletizer_interfaces__srv__SetAngles__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mypalletizer_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles)(void) {
  if (!mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_type_support_handle.typesupport_identifier) {
    mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mypalletizer_interfaces, srv, SetAngles_Event)()->data;
  }

  return &mypalletizer_interfaces__srv__detail__set_angles__rosidl_typesupport_introspection_c__SetAngles_service_type_support_handle;
}
