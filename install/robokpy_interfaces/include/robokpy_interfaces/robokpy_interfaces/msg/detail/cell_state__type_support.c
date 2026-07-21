// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robokpy_interfaces/msg/detail/cell_state__rosidl_typesupport_introspection_c.h"
#include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robokpy_interfaces/msg/detail/cell_state__functions.h"
#include "robokpy_interfaces/msg/detail/cell_state__struct.h"


// Include directives for member types
// Member `active_recipe_id`
// Member `last_error`
#include "rosidl_runtime_c/string_functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__msg__CellState__init(message_memory);
}

void robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_fini_function(void * message_memory)
{
  robokpy_interfaces__msg__CellState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_member_array[4] = {
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__msg__CellState, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "active_recipe_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__msg__CellState, active_recipe_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__msg__CellState, last_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__msg__CellState, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_members = {
  "robokpy_interfaces__msg",  // message namespace
  "CellState",  // message name
  4,  // number of fields
  sizeof(robokpy_interfaces__msg__CellState),
  false,  // has_any_key_member_
  robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_member_array,  // message members
  robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_type_support_handle = {
  0,
  &robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__msg__CellState__get_type_hash,
  &robokpy_interfaces__msg__CellState__get_type_description,
  &robokpy_interfaces__msg__CellState__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, msg, CellState)() {
  robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__msg__CellState__rosidl_typesupport_introspection_c__CellState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
