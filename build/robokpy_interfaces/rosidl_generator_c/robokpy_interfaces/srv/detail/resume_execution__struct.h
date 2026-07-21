// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/ResumeExecution.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/resume_execution.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__RESUME_EXECUTION__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__RESUME_EXECUTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'step_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResumeExecution in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ResumeExecution_Request
{
  /// step currently held for operator
  rosidl_runtime_c__String step_id;
  /// true = resume, false = abort the held step instead
  bool proceed;
} robokpy_interfaces__srv__ResumeExecution_Request;

// Struct for a sequence of robokpy_interfaces__srv__ResumeExecution_Request.
typedef struct robokpy_interfaces__srv__ResumeExecution_Request__Sequence
{
  robokpy_interfaces__srv__ResumeExecution_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ResumeExecution_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ResumeExecution in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ResumeExecution_Response
{
  bool accepted;
  rosidl_runtime_c__String message;
} robokpy_interfaces__srv__ResumeExecution_Response;

// Struct for a sequence of robokpy_interfaces__srv__ResumeExecution_Response.
typedef struct robokpy_interfaces__srv__ResumeExecution_Response__Sequence
{
  robokpy_interfaces__srv__ResumeExecution_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ResumeExecution_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__ResumeExecution_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__ResumeExecution_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ResumeExecution in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__ResumeExecution_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__ResumeExecution_Request__Sequence request;
  robokpy_interfaces__srv__ResumeExecution_Response__Sequence response;
} robokpy_interfaces__srv__ResumeExecution_Event;

// Struct for a sequence of robokpy_interfaces__srv__ResumeExecution_Event.
typedef struct robokpy_interfaces__srv__ResumeExecution_Event__Sequence
{
  robokpy_interfaces__srv__ResumeExecution_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__ResumeExecution_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__RESUME_EXECUTION__STRUCT_H_
