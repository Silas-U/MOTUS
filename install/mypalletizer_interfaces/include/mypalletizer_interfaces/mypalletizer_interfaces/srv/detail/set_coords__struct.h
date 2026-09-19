// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mypalletizer_interfaces:srv/SetCoords.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mypalletizer_interfaces/srv/set_coords.h"


#ifndef MYPALLETIZER_INTERFACES__SRV__DETAIL__SET_COORDS__STRUCT_H_
#define MYPALLETIZER_INTERFACES__SRV__DETAIL__SET_COORDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetCoords in the package mypalletizer_interfaces.
typedef struct mypalletizer_interfaces__srv__SetCoords_Request
{
  float x;
  float y;
  float z;
  float rx;
  /// float32 ry
  /// float32 rz
  int8_t speed;
} mypalletizer_interfaces__srv__SetCoords_Request;

// Struct for a sequence of mypalletizer_interfaces__srv__SetCoords_Request.
typedef struct mypalletizer_interfaces__srv__SetCoords_Request__Sequence
{
  mypalletizer_interfaces__srv__SetCoords_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mypalletizer_interfaces__srv__SetCoords_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SetCoords in the package mypalletizer_interfaces.
typedef struct mypalletizer_interfaces__srv__SetCoords_Response
{
  bool flag;
} mypalletizer_interfaces__srv__SetCoords_Response;

// Struct for a sequence of mypalletizer_interfaces__srv__SetCoords_Response.
typedef struct mypalletizer_interfaces__srv__SetCoords_Response__Sequence
{
  mypalletizer_interfaces__srv__SetCoords_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mypalletizer_interfaces__srv__SetCoords_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  mypalletizer_interfaces__srv__SetCoords_Event__request__MAX_SIZE = 1
};
// response
enum
{
  mypalletizer_interfaces__srv__SetCoords_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SetCoords in the package mypalletizer_interfaces.
typedef struct mypalletizer_interfaces__srv__SetCoords_Event
{
  service_msgs__msg__ServiceEventInfo info;
  mypalletizer_interfaces__srv__SetCoords_Request__Sequence request;
  mypalletizer_interfaces__srv__SetCoords_Response__Sequence response;
} mypalletizer_interfaces__srv__SetCoords_Event;

// Struct for a sequence of mypalletizer_interfaces__srv__SetCoords_Event.
typedef struct mypalletizer_interfaces__srv__SetCoords_Event__Sequence
{
  mypalletizer_interfaces__srv__SetCoords_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mypalletizer_interfaces__srv__SetCoords_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYPALLETIZER_INTERFACES__SRV__DETAIL__SET_COORDS__STRUCT_H_
