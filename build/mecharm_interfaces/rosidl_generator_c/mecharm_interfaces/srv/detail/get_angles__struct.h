// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mecharm_interfaces:srv/GetAngles.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mecharm_interfaces/srv/get_angles.h"


#ifndef MECHARM_INTERFACES__SRV__DETAIL__GET_ANGLES__STRUCT_H_
#define MECHARM_INTERFACES__SRV__DETAIL__GET_ANGLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetAngles in the package mecharm_interfaces.
typedef struct mecharm_interfaces__srv__GetAngles_Request
{
  uint8_t structure_needs_at_least_one_member;
} mecharm_interfaces__srv__GetAngles_Request;

// Struct for a sequence of mecharm_interfaces__srv__GetAngles_Request.
typedef struct mecharm_interfaces__srv__GetAngles_Request__Sequence
{
  mecharm_interfaces__srv__GetAngles_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mecharm_interfaces__srv__GetAngles_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/GetAngles in the package mecharm_interfaces.
typedef struct mecharm_interfaces__srv__GetAngles_Response
{
  float joint_1;
  float joint_2;
  float joint_3;
  float joint_4;
  float joint_5;
  float joint_6;
} mecharm_interfaces__srv__GetAngles_Response;

// Struct for a sequence of mecharm_interfaces__srv__GetAngles_Response.
typedef struct mecharm_interfaces__srv__GetAngles_Response__Sequence
{
  mecharm_interfaces__srv__GetAngles_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mecharm_interfaces__srv__GetAngles_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  mecharm_interfaces__srv__GetAngles_Event__request__MAX_SIZE = 1
};
// response
enum
{
  mecharm_interfaces__srv__GetAngles_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetAngles in the package mecharm_interfaces.
typedef struct mecharm_interfaces__srv__GetAngles_Event
{
  service_msgs__msg__ServiceEventInfo info;
  mecharm_interfaces__srv__GetAngles_Request__Sequence request;
  mecharm_interfaces__srv__GetAngles_Response__Sequence response;
} mecharm_interfaces__srv__GetAngles_Event;

// Struct for a sequence of mecharm_interfaces__srv__GetAngles_Event.
typedef struct mecharm_interfaces__srv__GetAngles_Event__Sequence
{
  mecharm_interfaces__srv__GetAngles_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mecharm_interfaces__srv__GetAngles_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MECHARM_INTERFACES__SRV__DETAIL__GET_ANGLES__STRUCT_H_
