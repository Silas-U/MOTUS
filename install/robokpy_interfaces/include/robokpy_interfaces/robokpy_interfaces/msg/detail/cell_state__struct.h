// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/msg/cell_state.h"


#ifndef ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__STRUCT_H_
#define ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'IDLE'.
enum
{
  robokpy_interfaces__msg__CellState__IDLE = 0
};

/// Constant 'PLANNING'.
enum
{
  robokpy_interfaces__msg__CellState__PLANNING = 1
};

/// Constant 'EXECUTING'.
enum
{
  robokpy_interfaces__msg__CellState__EXECUTING = 2
};

/// Constant 'PAUSED'.
enum
{
  robokpy_interfaces__msg__CellState__PAUSED = 3
};

/// Constant 'ERROR'.
enum
{
  robokpy_interfaces__msg__CellState__ERROR = 4
};

/// Constant 'ESTOP'.
enum
{
  robokpy_interfaces__msg__CellState__ESTOP = 5
};

// Include directives for member types
// Member 'active_recipe_id'
// Member 'last_error'
#include "rosidl_runtime_c/string.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/CellState in the package robokpy_interfaces.
typedef struct robokpy_interfaces__msg__CellState
{
  uint8_t state;
  rosidl_runtime_c__String active_recipe_id;
  rosidl_runtime_c__String last_error;
  builtin_interfaces__msg__Time stamp;
} robokpy_interfaces__msg__CellState;

// Struct for a sequence of robokpy_interfaces__msg__CellState.
typedef struct robokpy_interfaces__msg__CellState__Sequence
{
  robokpy_interfaces__msg__CellState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robokpy_interfaces__msg__CellState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__STRUCT_H_
