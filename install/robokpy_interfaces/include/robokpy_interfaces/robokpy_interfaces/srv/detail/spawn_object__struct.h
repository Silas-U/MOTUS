// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/SpawnObject.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/spawn_object.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__SPAWN_OBJECT__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__SPAWN_OBJECT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type_id'
// Member 'color'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SpawnObject in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__SpawnObject_Request
{
  rosidl_runtime_c__String type_id;
  double x;
  double y;
  double z;
  double qx;
  double qy;
  double qz;
  double qw;
  /// optional visual material color — named color,
  /// hex #RRGGBB, or space-separated RGB floats.
  /// Empty string yields the catalog default.
  rosidl_runtime_c__String color;
} robokpy_interfaces__srv__SpawnObject_Request;

// Struct for a sequence of robokpy_interfaces__srv__SpawnObject_Request.
typedef struct robokpy_interfaces__srv__SpawnObject_Request__Sequence
{
  robokpy_interfaces__srv__SpawnObject_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__SpawnObject_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// Member 'child_model'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SpawnObject in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__SpawnObject_Response
{
  bool success;
  rosidl_runtime_c__String message;
  /// the actual catalog instance name assigned
  /// (e.g. "cube_small_3") — empty on failure.
  /// Callers need this to later despawn or to
  /// pass into GraspAttach.srv's child_model field.
  rosidl_runtime_c__String child_model;
} robokpy_interfaces__srv__SpawnObject_Response;

// Struct for a sequence of robokpy_interfaces__srv__SpawnObject_Response.
typedef struct robokpy_interfaces__srv__SpawnObject_Response__Sequence
{
  robokpy_interfaces__srv__SpawnObject_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__SpawnObject_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__SpawnObject_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__SpawnObject_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SpawnObject in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__SpawnObject_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__SpawnObject_Request__Sequence request;
  robokpy_interfaces__srv__SpawnObject_Response__Sequence response;
} robokpy_interfaces__srv__SpawnObject_Event;

// Struct for a sequence of robokpy_interfaces__srv__SpawnObject_Event.
typedef struct robokpy_interfaces__srv__SpawnObject_Event__Sequence
{
  robokpy_interfaces__srv__SpawnObject_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__SpawnObject_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__SPAWN_OBJECT__STRUCT_H_
