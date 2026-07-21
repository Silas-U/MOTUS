// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/IK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/ik.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__IK__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__IK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mask'
// Member 'seed'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/IK in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__IK_Request
{
  /// [x, y, z, qx, qy, qz, qw]
  double target_pose[7];
  /// [px, py, pz, rx, ry, rz] — 1=constrained, 0=free
  rosidl_runtime_c__int32__Sequence mask;
  /// initial joint config seed (optional, empty = zeros)
  rosidl_runtime_c__double__Sequence seed;
  /// convergence tolerance (default 1e-3 if 0)
  double tol;
  /// max iterations (default 30 if 0)
  int32_t max_iter;
} robokpy_interfaces__srv__IK_Request;

// Struct for a sequence of robokpy_interfaces__srv__IK_Request.
typedef struct robokpy_interfaces__srv__IK_Request__Sequence
{
  robokpy_interfaces__srv__IK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__IK_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'q'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/IK in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__IK_Response
{
  /// Response
  bool success;
  /// joint angles in radians
  rosidl_runtime_c__double__Sequence q;
  /// final error norm
  double error;
  rosidl_runtime_c__String message;
} robokpy_interfaces__srv__IK_Response;

// Struct for a sequence of robokpy_interfaces__srv__IK_Response.
typedef struct robokpy_interfaces__srv__IK_Response__Sequence
{
  robokpy_interfaces__srv__IK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__IK_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__IK_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__IK_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/IK in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__IK_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__IK_Request__Sequence request;
  robokpy_interfaces__srv__IK_Response__Sequence response;
} robokpy_interfaces__srv__IK_Event;

// Struct for a sequence of robokpy_interfaces__srv__IK_Event.
typedef struct robokpy_interfaces__srv__IK_Event__Sequence
{
  robokpy_interfaces__srv__IK_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__IK_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__IK__STRUCT_H_
