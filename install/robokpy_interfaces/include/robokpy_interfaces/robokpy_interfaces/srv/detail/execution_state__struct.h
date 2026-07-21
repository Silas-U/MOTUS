// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/ExecutionState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/execution_state.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__EXECUTION_STATE__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__EXECUTION_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'new_state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecutionState in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ExecutionState_Request
{
  rosidl_runtime_c__String new_state;
} robokpy_interfaces__srv__ExecutionState_Request;

// Struct for a sequence of robokpy_interfaces__srv__ExecutionState_Request.
typedef struct robokpy_interfaces__srv__ExecutionState_Request__Sequence
{
  robokpy_interfaces__srv__ExecutionState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ExecutionState_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecutionState in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ExecutionState_Response
{
  bool success;
  rosidl_runtime_c__String message;
} robokpy_interfaces__srv__ExecutionState_Response;

// Struct for a sequence of robokpy_interfaces__srv__ExecutionState_Response.
typedef struct robokpy_interfaces__srv__ExecutionState_Response__Sequence
{
  robokpy_interfaces__srv__ExecutionState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ExecutionState_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__ExecutionState_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__ExecutionState_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ExecutionState in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ExecutionState_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__ExecutionState_Request__Sequence request;
  robokpy_interfaces__srv__ExecutionState_Response__Sequence response;
} robokpy_interfaces__srv__ExecutionState_Event;

// Struct for a sequence of robokpy_interfaces__srv__ExecutionState_Event.
typedef struct robokpy_interfaces__srv__ExecutionState_Event__Sequence
{
  robokpy_interfaces__srv__ExecutionState_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ExecutionState_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__EXECUTION_STATE__STRUCT_H_
