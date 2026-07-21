// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/Jacobian.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/jacobian.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'q'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/Jacobian in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__Jacobian_Request
{
  /// joint angles in radians
  rosidl_runtime_c__double__Sequence q;
} robokpy_interfaces__srv__Jacobian_Request;

// Struct for a sequence of robokpy_interfaces__srv__Jacobian_Request.
typedef struct robokpy_interfaces__srv__Jacobian_Request__Sequence
{
  robokpy_interfaces__srv__Jacobian_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__Jacobian_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'jacobian_flat'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Jacobian in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__Jacobian_Response
{
  /// Response
  bool success;
  /// flattened 6xn Jacobian (row-major: 6*n floats)
  rosidl_runtime_c__double__Sequence jacobian_flat;
  /// always 6
  int32_t rows;
  /// n = num_active_joints
  int32_t cols;
  /// Yoshikawa manipulability measure
  double manipulability;
  /// SVD condition number
  double condition_number;
  /// matrix rank
  int32_t rank;
  /// true if manipulability < threshold
  bool is_near_singular;
  rosidl_runtime_c__String message;
} robokpy_interfaces__srv__Jacobian_Response;

// Struct for a sequence of robokpy_interfaces__srv__Jacobian_Response.
typedef struct robokpy_interfaces__srv__Jacobian_Response__Sequence
{
  robokpy_interfaces__srv__Jacobian_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__Jacobian_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__Jacobian_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__Jacobian_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/Jacobian in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__Jacobian_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__Jacobian_Request__Sequence request;
  robokpy_interfaces__srv__Jacobian_Response__Sequence response;
} robokpy_interfaces__srv__Jacobian_Event;

// Struct for a sequence of robokpy_interfaces__srv__Jacobian_Event.
typedef struct robokpy_interfaces__srv__Jacobian_Event__Sequence
{
  robokpy_interfaces__srv__Jacobian_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__Jacobian_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__STRUCT_H_
