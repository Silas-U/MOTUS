// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/msg/detail/cell_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `active_recipe_id`
// Member `last_error`
#include "rosidl_runtime_c/string_functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
robokpy_interfaces__msg__CellState__init(robokpy_interfaces__msg__CellState * msg)
{
  if (!msg) {
    return false;
  }
  // state
  // active_recipe_id
  if (!rosidl_runtime_c__String__init(&msg->active_recipe_id)) {
    robokpy_interfaces__msg__CellState__fini(msg);
    return false;
  }
  // last_error
  if (!rosidl_runtime_c__String__init(&msg->last_error)) {
    robokpy_interfaces__msg__CellState__fini(msg);
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    robokpy_interfaces__msg__CellState__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__msg__CellState__fini(robokpy_interfaces__msg__CellState * msg)
{
  if (!msg) {
    return;
  }
  // state
  // active_recipe_id
  rosidl_runtime_c__String__fini(&msg->active_recipe_id);
  // last_error
  rosidl_runtime_c__String__fini(&msg->last_error);
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
robokpy_interfaces__msg__CellState__are_equal(const robokpy_interfaces__msg__CellState * lhs, const robokpy_interfaces__msg__CellState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // active_recipe_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->active_recipe_id), &(rhs->active_recipe_id)))
  {
    return false;
  }
  // last_error
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->last_error), &(rhs->last_error)))
  {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__msg__CellState__copy(
  const robokpy_interfaces__msg__CellState * input,
  robokpy_interfaces__msg__CellState * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  // active_recipe_id
  if (!rosidl_runtime_c__String__copy(
      &(input->active_recipe_id), &(output->active_recipe_id)))
  {
    return false;
  }
  // last_error
  if (!rosidl_runtime_c__String__copy(
      &(input->last_error), &(output->last_error)))
  {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__msg__CellState *
robokpy_interfaces__msg__CellState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__msg__CellState * msg = (robokpy_interfaces__msg__CellState *)allocator.allocate(sizeof(robokpy_interfaces__msg__CellState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__msg__CellState));
  bool success = robokpy_interfaces__msg__CellState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__msg__CellState__destroy(robokpy_interfaces__msg__CellState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__msg__CellState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__msg__CellState__Sequence__init(robokpy_interfaces__msg__CellState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__msg__CellState * data = NULL;

  if (size) {
    data = (robokpy_interfaces__msg__CellState *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__msg__CellState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__msg__CellState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__msg__CellState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
robokpy_interfaces__msg__CellState__Sequence__fini(robokpy_interfaces__msg__CellState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      robokpy_interfaces__msg__CellState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

robokpy_interfaces__msg__CellState__Sequence *
robokpy_interfaces__msg__CellState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__msg__CellState__Sequence * array = (robokpy_interfaces__msg__CellState__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__msg__CellState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__msg__CellState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__msg__CellState__Sequence__destroy(robokpy_interfaces__msg__CellState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__msg__CellState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__msg__CellState__Sequence__are_equal(const robokpy_interfaces__msg__CellState__Sequence * lhs, const robokpy_interfaces__msg__CellState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__msg__CellState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__msg__CellState__Sequence__copy(
  const robokpy_interfaces__msg__CellState__Sequence * input,
  robokpy_interfaces__msg__CellState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__msg__CellState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__msg__CellState * data =
      (robokpy_interfaces__msg__CellState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__msg__CellState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__msg__CellState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__msg__CellState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
