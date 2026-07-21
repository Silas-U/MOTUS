// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/GraspAttach.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/grasp_attach.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'parent_model'
// Member 'parent_link'
// Member 'child_model'
// Member 'child_link'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GraspAttach in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__GraspAttach_Request
{
  /// model owning parent_link
  rosidl_runtime_c__String parent_model;
  rosidl_runtime_c__String parent_link;
  /// empty => auto-detect
  rosidl_runtime_c__String child_model;
  /// empty => auto-detect
  rosidl_runtime_c__String child_link;
  bool attach;
  /// only used when attach=false
  uint32_t joint_id;
} robokpy_interfaces__srv__GraspAttach_Request;

// Struct for a sequence of robokpy_interfaces__srv__GraspAttach_Request.
typedef struct robokpy_interfaces__srv__GraspAttach_Request__Sequence
{
  robokpy_interfaces__srv__GraspAttach_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__GraspAttach_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GraspAttach in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__GraspAttach_Response
{
  bool success;
  rosidl_runtime_c__String message;
  uint32_t joint_id;
} robokpy_interfaces__srv__GraspAttach_Response;

// Struct for a sequence of robokpy_interfaces__srv__GraspAttach_Response.
typedef struct robokpy_interfaces__srv__GraspAttach_Response__Sequence
{
  robokpy_interfaces__srv__GraspAttach_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__GraspAttach_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__GraspAttach_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__GraspAttach_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GraspAttach in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__GraspAttach_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__GraspAttach_Request__Sequence request;
  robokpy_interfaces__srv__GraspAttach_Response__Sequence response;
} robokpy_interfaces__srv__GraspAttach_Event;

// Struct for a sequence of robokpy_interfaces__srv__GraspAttach_Event.
typedef struct robokpy_interfaces__srv__GraspAttach_Event__Sequence
{
  robokpy_interfaces__srv__GraspAttach_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__GraspAttach_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__STRUCT_H_
