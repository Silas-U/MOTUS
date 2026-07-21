// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:action/RobotTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/robot_trajectory.h"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__ROBOT_TRAJECTORY__STRUCT_H_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__ROBOT_TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"
// Member 'trajectory_mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_Goal
{
  trajectory_msgs__msg__JointTrajectory trajectory;
  /// e.g., "blended", "strict_stop"
  rosidl_runtime_c__String trajectory_mode;
} robokpy_interfaces__action__RobotTrajectory_Goal;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_Goal.
typedef struct robokpy_interfaces__action__RobotTrajectory_Goal__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'status_message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_Result
{
  bool success;
  rosidl_runtime_c__String status_message;
} robokpy_interfaces__action__RobotTrajectory_Result;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_Result.
typedef struct robokpy_interfaces__action__RobotTrajectory_Result__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'current_waypoint_id'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_Feedback
{
  rosidl_runtime_c__String current_waypoint_id;
  double percent_complete;
} robokpy_interfaces__action__RobotTrajectory_Feedback;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_Feedback.
typedef struct robokpy_interfaces__action__RobotTrajectory_Feedback__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robokpy_interfaces/action/detail/robot_trajectory__struct.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__RobotTrajectory_Goal goal;
} robokpy_interfaces__action__RobotTrajectory_SendGoal_Request;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_SendGoal_Request.
typedef struct robokpy_interfaces__action__RobotTrajectory_SendGoal_Request__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robokpy_interfaces__action__RobotTrajectory_SendGoal_Response;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_SendGoal_Response.
typedef struct robokpy_interfaces__action__RobotTrajectory_SendGoal_Response__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Request__Sequence request;
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Response__Sequence response;
} robokpy_interfaces__action__RobotTrajectory_SendGoal_Event;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_SendGoal_Event.
typedef struct robokpy_interfaces__action__RobotTrajectory_SendGoal_Event__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robokpy_interfaces__action__RobotTrajectory_GetResult_Request;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_GetResult_Request.
typedef struct robokpy_interfaces__action__RobotTrajectory_GetResult_Request__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/robot_trajectory__struct.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_GetResult_Response
{
  int8_t status;
  robokpy_interfaces__action__RobotTrajectory_Result result;
} robokpy_interfaces__action__RobotTrajectory_GetResult_Response;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_GetResult_Response.
typedef struct robokpy_interfaces__action__RobotTrajectory_GetResult_Response__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__RobotTrajectory_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__RobotTrajectory_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__RobotTrajectory_GetResult_Request__Sequence request;
  robokpy_interfaces__action__RobotTrajectory_GetResult_Response__Sequence response;
} robokpy_interfaces__action__RobotTrajectory_GetResult_Event;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_GetResult_Event.
typedef struct robokpy_interfaces__action__RobotTrajectory_GetResult_Event__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/robot_trajectory__struct.h"

/// Struct defined in action/RobotTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__RobotTrajectory_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__RobotTrajectory_Feedback feedback;
} robokpy_interfaces__action__RobotTrajectory_FeedbackMessage;

// Struct for a sequence of robokpy_interfaces__action__RobotTrajectory_FeedbackMessage.
typedef struct robokpy_interfaces__action__RobotTrajectory_FeedbackMessage__Sequence
{
  robokpy_interfaces__action__RobotTrajectory_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__RobotTrajectory_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__ROBOT_TRAJECTORY__STRUCT_H_
