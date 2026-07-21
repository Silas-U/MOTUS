// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:action/ExecuteVisionOp.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/execute_vision_op.h"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__STRUCT_H_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'vision_id'
// Member 'operation'
#include "rosidl_runtime_c/string.h"
// Member 'params'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_Goal
{
  rosidl_runtime_c__String vision_id;
  /// e.g. locate_part, verify_presence, read_barcode
  rosidl_runtime_c__String operation;
  rosidl_runtime_c__double__Sequence params;
} robokpy_interfaces__action__ExecuteVisionOp_Goal;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_Goal.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'detected_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'detected_value'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_Result
{
  bool success;
  uint32_t error_code;
  /// populated for locate-type operations
  geometry_msgs__msg__Pose detected_pose;
  /// populated for read/verify-type operations
  rosidl_runtime_c__String detected_value;
} robokpy_interfaces__action__ExecuteVisionOp_Result;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_Result.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_Feedback
{
  /// CAPTURING/PROCESSING
  rosidl_runtime_c__String status;
  float percent_complete;
} robokpy_interfaces__action__ExecuteVisionOp_Feedback;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_Feedback.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robokpy_interfaces/action/detail/execute_vision_op__struct.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__ExecuteVisionOp_Goal goal;
} robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence request;
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence response;
} robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response
{
  int8_t status;
  robokpy_interfaces__action__ExecuteVisionOp_Result result;
} robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence request;
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence response;
} robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.h"

/// Struct defined in action/ExecuteVisionOp in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__ExecuteVisionOp_Feedback feedback;
} robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage;

// Struct for a sequence of robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage.
typedef struct robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence
{
  robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__STRUCT_H_
