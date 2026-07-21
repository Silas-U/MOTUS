// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:action/ExecuteMotion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/execute_motion.h"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__STRUCT_H_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'leg_step_ids'
// Member 'leg_traj_methods'
// Member 'leg_traj_types'
#include "rosidl_runtime_c/string.h"
// Member 'leg_target_poses'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'leg_blend_radii'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_Goal
{
  rosidl_runtime_c__String__Sequence leg_step_ids;
  geometry_msgs__msg__Pose__Sequence leg_target_poses;
  rosidl_runtime_c__String__Sequence leg_traj_methods;
  rosidl_runtime_c__String__Sequence leg_traj_types;
  /// blend INTO the next leg; last entry always forced to 0.0 by the orchestrator
  rosidl_runtime_c__double__Sequence leg_blend_radii;
  double speed_scale;
} robokpy_interfaces__action__ExecuteMotion_Goal;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_Goal.
typedef struct robokpy_interfaces__action__ExecuteMotion_Goal__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'final_state'
#include "sensor_msgs/msg/detail/joint_state__struct.h"
// Member 'actual_duration'
#include "builtin_interfaces/msg/detail/duration__struct.h"
// Member 'failed_leg_step_id'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_Result
{
  bool success;
  uint32_t error_code;
  sensor_msgs__msg__JointState final_state;
  builtin_interfaces__msg__Duration actual_duration;
  /// which leg was in progress when a failure occurred; empty on success
  rosidl_runtime_c__String failed_leg_step_id;
} robokpy_interfaces__action__ExecuteMotion_Result;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_Result.
typedef struct robokpy_interfaces__action__ExecuteMotion_Result__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_leg_step_id'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'current_state'
// already included above
// #include "sensor_msgs/msg/detail/joint_state__struct.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_Feedback
{
  rosidl_runtime_c__String current_leg_step_id;
  float leg_percent_complete;
  sensor_msgs__msg__JointState current_state;
} robokpy_interfaces__action__ExecuteMotion_Feedback;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_Feedback.
typedef struct robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robokpy_interfaces/action/detail/execute_motion__struct.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__ExecuteMotion_Goal goal;
} robokpy_interfaces__action__ExecuteMotion_SendGoal_Request;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_SendGoal_Request.
typedef struct robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robokpy_interfaces__action__ExecuteMotion_SendGoal_Response;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_SendGoal_Response.
typedef struct robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence request;
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence response;
} robokpy_interfaces__action__ExecuteMotion_SendGoal_Event;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_SendGoal_Event.
typedef struct robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robokpy_interfaces__action__ExecuteMotion_GetResult_Request;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_GetResult_Request.
typedef struct robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/execute_motion__struct.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_GetResult_Response
{
  int8_t status;
  robokpy_interfaces__action__ExecuteMotion_Result result;
} robokpy_interfaces__action__ExecuteMotion_GetResult_Response;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_GetResult_Response.
typedef struct robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence request;
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence response;
} robokpy_interfaces__action__ExecuteMotion_GetResult_Event;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_GetResult_Event.
typedef struct robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/execute_motion__struct.h"

/// Struct defined in action/ExecuteMotion in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__ExecuteMotion_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__ExecuteMotion_Feedback feedback;
} robokpy_interfaces__action__ExecuteMotion_FeedbackMessage;

// Struct for a sequence of robokpy_interfaces__action__ExecuteMotion_FeedbackMessage.
typedef struct robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence
{
  robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__STRUCT_H_
