// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_pro450_interfaces:srv/GetGripperValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mycobot_pro450_interfaces/srv/get_gripper_value.h"


#ifndef MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__STRUCT_H_
#define MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetGripperValue in the package mycobot_pro450_interfaces.
typedef struct mycobot_pro450_interfaces__srv__GetGripperValue_Request
{
  uint8_t structure_needs_at_least_one_member;
} mycobot_pro450_interfaces__srv__GetGripperValue_Request;

// Struct for a sequence of mycobot_pro450_interfaces__srv__GetGripperValue_Request.
typedef struct mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence
{
  mycobot_pro450_interfaces__srv__GetGripperValue_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/GetGripperValue in the package mycobot_pro450_interfaces.
typedef struct mycobot_pro450_interfaces__srv__GetGripperValue_Response
{
  int8_t gripper_angle;
} mycobot_pro450_interfaces__srv__GetGripperValue_Response;

// Struct for a sequence of mycobot_pro450_interfaces__srv__GetGripperValue_Response.
typedef struct mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence
{
  mycobot_pro450_interfaces__srv__GetGripperValue_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  mycobot_pro450_interfaces__srv__GetGripperValue_Event__request__MAX_SIZE = 1
};
// response
enum
{
  mycobot_pro450_interfaces__srv__GetGripperValue_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetGripperValue in the package mycobot_pro450_interfaces.
typedef struct mycobot_pro450_interfaces__srv__GetGripperValue_Event
{
  service_msgs__msg__ServiceEventInfo info;
  mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence request;
  mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence response;
} mycobot_pro450_interfaces__srv__GetGripperValue_Event;

// Struct for a sequence of mycobot_pro450_interfaces__srv__GetGripperValue_Event.
typedef struct mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence
{
  mycobot_pro450_interfaces__srv__GetGripperValue_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__STRUCT_H_
