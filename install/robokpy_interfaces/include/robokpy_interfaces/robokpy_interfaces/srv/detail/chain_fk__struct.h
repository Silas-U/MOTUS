// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/ChainFK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/chain_fk.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__STRUCT_H_

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
// Member 'base_link'
// Member 'end_link'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChainFK in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ChainFK_Request
{
  /// joint angles for active joints in chain (radians)
  rosidl_runtime_c__double__Sequence q;
  /// name of base link
  rosidl_runtime_c__String base_link;
  /// name of end link
  rosidl_runtime_c__String end_link;
} robokpy_interfaces__srv__ChainFK_Request;

// Struct for a sequence of robokpy_interfaces__srv__ChainFK_Request.
typedef struct robokpy_interfaces__srv__ChainFK_Request__Sequence
{
  robokpy_interfaces__srv__ChainFK_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ChainFK_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ChainFK in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ChainFK_Response
{
  /// Response
  bool success;
  /// [x, y, z, qx, qy, qz, qw]
  double pose[7];
  /// [x, y, z, roll, pitch, yaw] in radians
  double pose_euler[6];
  rosidl_runtime_c__String message;
} robokpy_interfaces__srv__ChainFK_Response;

// Struct for a sequence of robokpy_interfaces__srv__ChainFK_Response.
typedef struct robokpy_interfaces__srv__ChainFK_Response__Sequence
{
  robokpy_interfaces__srv__ChainFK_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ChainFK_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__ChainFK_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__ChainFK_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ChainFK in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ChainFK_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__ChainFK_Request__Sequence request;
  robokpy_interfaces__srv__ChainFK_Response__Sequence response;
} robokpy_interfaces__srv__ChainFK_Event;

// Struct for a sequence of robokpy_interfaces__srv__ChainFK_Event.
typedef struct robokpy_interfaces__srv__ChainFK_Event__Sequence
{
  robokpy_interfaces__srv__ChainFK_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ChainFK_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__STRUCT_H_
