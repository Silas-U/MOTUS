// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:srv/LoadRecipe.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/load_recipe.h"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__STRUCT_H_
#define ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'recipe_path'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/LoadRecipe in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__LoadRecipe_Request
{
  /// absolute path, or a filename resolved under
  /// <robokpy_controller share>/recipes/
  rosidl_runtime_c__String recipe_path;
} robokpy_interfaces__srv__LoadRecipe_Request;

// Struct for a sequence of robokpy_interfaces__srv__LoadRecipe_Request.
typedef struct robokpy_interfaces__srv__LoadRecipe_Request__Sequence
{
  robokpy_interfaces__srv__LoadRecipe_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__LoadRecipe_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// Member 'recipe_id'
// Member 'content_hash'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/LoadRecipe in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__LoadRecipe_Response
{
  bool success;
  rosidl_runtime_c__String message;
  rosidl_runtime_c__String recipe_id;
  rosidl_runtime_c__String content_hash;
} robokpy_interfaces__srv__LoadRecipe_Response;

// Struct for a sequence of robokpy_interfaces__srv__LoadRecipe_Response.
typedef struct robokpy_interfaces__srv__LoadRecipe_Response__Sequence
{
  robokpy_interfaces__srv__LoadRecipe_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__LoadRecipe_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  robokpy_interfaces__srv__LoadRecipe_Event__request__MAX_SIZE = 1
};
// response
enum
{
  robokpy_interfaces__srv__LoadRecipe_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/LoadRecipe in the package robokpy_interfaces.
typedef struct robokpy_interfaces__srv__LoadRecipe_Event
{
  service_msgs__msg__ServiceEventInfo info;
  robokpy_interfaces__srv__LoadRecipe_Request__Sequence request;
  robokpy_interfaces__srv__LoadRecipe_Response__Sequence response;
} robokpy_interfaces__srv__LoadRecipe_Event;

// Struct for a sequence of robokpy_interfaces__srv__LoadRecipe_Event.
typedef struct robokpy_interfaces__srv__LoadRecipe_Event__Sequence
{
  robokpy_interfaces__srv__LoadRecipe_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__srv__LoadRecipe_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__STRUCT_H_
