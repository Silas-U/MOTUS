// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/ResolveObjectPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/resolve_object_pose.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ResolveObjectPose in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ResolveObjectPose_Request
{
  double x;
  double y;
  double z;
  /// meters — reject the match if the nearest known
  /// instance is farther than this. Required, not
  /// defaulted, so callers make a deliberate choice
  /// given their object spacing (this is exactly
  /// the "stacked objects" scenario from earlier —
  /// too generous a threshold risks matching the
  /// wrong instance).
  double max_distance;
} robokpy_interfaces__srv__ResolveObjectPose_Request;

// Struct for a sequence of robokpy_interfaces__srv__ResolveObjectPose_Request.
typedef struct robokpy_interfaces__srv__ResolveObjectPose_Request__Sequence
{
  robokpy_interfaces__srv__ResolveObjectPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ResolveObjectPose_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'child_model'
// Member 'child_link'
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResolveObjectPose in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ResolveObjectPose_Response
{
  bool success;
  /// empty on failure
  rosidl_runtime_c__String child_model;
  /// empty on failure
  rosidl_runtime_c__String child_link;
  /// actual distance to the matched instance, meters
  double distance;
  rosidl_runtime_c__String message;
} robokpy_interfaces__srv__ResolveObjectPose_Response;

// Struct for a sequence of robokpy_interfaces__srv__ResolveObjectPose_Response.
typedef struct robokpy_interfaces__srv__ResolveObjectPose_Response__Sequence
{
  robokpy_interfaces__srv__ResolveObjectPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ResolveObjectPose_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__ResolveObjectPose_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__ResolveObjectPose_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ResolveObjectPose in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ResolveObjectPose_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__ResolveObjectPose_Request__Sequence request;
  robokpy_interfaces__srv__ResolveObjectPose_Response__Sequence response;
} robokpy_interfaces__srv__ResolveObjectPose_Event;

// Struct for a sequence of robokpy_interfaces__srv__ResolveObjectPose_Event.
typedef struct robokpy_interfaces__srv__ResolveObjectPose_Event__Sequence
{
  robokpy_interfaces__srv__ResolveObjectPose_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ResolveObjectPose_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__STRUCT_H_
