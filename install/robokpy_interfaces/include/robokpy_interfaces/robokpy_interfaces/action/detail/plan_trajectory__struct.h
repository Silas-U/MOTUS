// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:action/PlanTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/plan_trajectory.h"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__PLAN_TRAJECTORY__STRUCT_H_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__PLAN_TRAJECTORY__STRUCT_H_

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
// Member 'seed_state'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_Goal
{
  rosidl_runtime_c__String__Sequence leg_step_ids;
  geometry_msgs__msg__Pose__Sequence leg_target_poses;
  rosidl_runtime_c__String__Sequence leg_traj_methods;
  rosidl_runtime_c__String__Sequence leg_traj_types;
  rosidl_runtime_c__double__Sequence leg_blend_radii;
  rosidl_runtime_c__double__Sequence seed_state;
  double speed_scale;
} robokpy_interfaces__action__PlanTrajectory_Goal;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_Goal.
typedef struct robokpy_interfaces__action__PlanTrajectory_Goal__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"
// Member 'predicted_final_state'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_Result
{
  bool success;
  int32_t error_code;
  trajectory_msgs__msg__JointTrajectory trajectory;
  rosidl_runtime_c__double__Sequence predicted_final_state;
  double total_duration;
} robokpy_interfaces__action__PlanTrajectory_Result;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_Result.
typedef struct robokpy_interfaces__action__PlanTrajectory_Result__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} robokpy_interfaces__action__PlanTrajectory_Feedback;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_Feedback.
typedef struct robokpy_interfaces__action__PlanTrajectory_Feedback__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__PlanTrajectory_Goal goal;
} robokpy_interfaces__action__PlanTrajectory_SendGoal_Request;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_SendGoal_Request.
typedef struct robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} robokpy_interfaces__action__PlanTrajectory_SendGoal_Response;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_SendGoal_Response.
typedef struct robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence request;
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence response;
} robokpy_interfaces__action__PlanTrajectory_SendGoal_Event;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_SendGoal_Event.
typedef struct robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} robokpy_interfaces__action__PlanTrajectory_GetResult_Request;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_GetResult_Request.
typedef struct robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_GetResult_Response
{
  int8_t status;
  robokpy_interfaces__action__PlanTrajectory_Result result;
} robokpy_interfaces__action__PlanTrajectory_GetResult_Response;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_GetResult_Response.
typedef struct robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence request;
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence response;
} robokpy_interfaces__action__PlanTrajectory_GetResult_Event;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_GetResult_Event.
typedef struct robokpy_interfaces__action__PlanTrajectory_GetResult_Event__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"

/// Struct defined in action/PlanTrajectory in the package robokpy_interfaces.
typedef struct robokpy_interfaces__action__PlanTrajectory_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  robokpy_interfaces__action__PlanTrajectory_Feedback feedback;
} robokpy_interfaces__action__PlanTrajectory_FeedbackMessage;

// Struct for a sequence of robokpy_interfaces__action__PlanTrajectory_FeedbackMessage.
typedef struct robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__Sequence
{
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__PLAN_TRAJECTORY__STRUCT_H_
