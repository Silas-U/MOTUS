// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:action/ToolExecution.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/action/detail/tool_execution__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `tool_id`
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__action__ToolExecution_Goal__init(robokpy_interfaces__action__ToolExecution_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // tool_id
  if (!rosidl_runtime_c__String__init(&msg->tool_id)) {
    robokpy_interfaces__action__ToolExecution_Goal__fini(msg);
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    robokpy_interfaces__action__ToolExecution_Goal__fini(msg);
    return false;
  }
  // timeout_duration
  return true;
}

void
robokpy_interfaces__action__ToolExecution_Goal__fini(robokpy_interfaces__action__ToolExecution_Goal * msg)
{
  if (!msg) {
    return;
  }
  // tool_id
  rosidl_runtime_c__String__fini(&msg->tool_id);
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // timeout_duration
}

bool
robokpy_interfaces__action__ToolExecution_Goal__are_equal(const robokpy_interfaces__action__ToolExecution_Goal * lhs, const robokpy_interfaces__action__ToolExecution_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tool_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->tool_id), &(rhs->tool_id)))
  {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // timeout_duration
  if (lhs->timeout_duration != rhs->timeout_duration) {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_Goal__copy(
  const robokpy_interfaces__action__ToolExecution_Goal * input,
  robokpy_interfaces__action__ToolExecution_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // tool_id
  if (!rosidl_runtime_c__String__copy(
      &(input->tool_id), &(output->tool_id)))
  {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // timeout_duration
  output->timeout_duration = input->timeout_duration;
  return true;
}

robokpy_interfaces__action__ToolExecution_Goal *
robokpy_interfaces__action__ToolExecution_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Goal * msg = (robokpy_interfaces__action__ToolExecution_Goal *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_Goal));
  bool success = robokpy_interfaces__action__ToolExecution_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_Goal__destroy(robokpy_interfaces__action__ToolExecution_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_Goal__Sequence__init(robokpy_interfaces__action__ToolExecution_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Goal * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_Goal *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_Goal__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_Goal__Sequence__fini(robokpy_interfaces__action__ToolExecution_Goal__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_Goal__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_Goal__Sequence *
robokpy_interfaces__action__ToolExecution_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Goal__Sequence * array = (robokpy_interfaces__action__ToolExecution_Goal__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_Goal__Sequence__destroy(robokpy_interfaces__action__ToolExecution_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_Goal__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_Goal__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_Goal__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_Goal__Sequence * input,
  robokpy_interfaces__action__ToolExecution_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_Goal * data =
      (robokpy_interfaces__action__ToolExecution_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status_message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__action__ToolExecution_Result__init(robokpy_interfaces__action__ToolExecution_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // status_message
  if (!rosidl_runtime_c__String__init(&msg->status_message)) {
    robokpy_interfaces__action__ToolExecution_Result__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_Result__fini(robokpy_interfaces__action__ToolExecution_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // status_message
  rosidl_runtime_c__String__fini(&msg->status_message);
}

bool
robokpy_interfaces__action__ToolExecution_Result__are_equal(const robokpy_interfaces__action__ToolExecution_Result * lhs, const robokpy_interfaces__action__ToolExecution_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_message), &(rhs->status_message)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_Result__copy(
  const robokpy_interfaces__action__ToolExecution_Result * input,
  robokpy_interfaces__action__ToolExecution_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // status_message
  if (!rosidl_runtime_c__String__copy(
      &(input->status_message), &(output->status_message)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_Result *
robokpy_interfaces__action__ToolExecution_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Result * msg = (robokpy_interfaces__action__ToolExecution_Result *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_Result));
  bool success = robokpy_interfaces__action__ToolExecution_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_Result__destroy(robokpy_interfaces__action__ToolExecution_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_Result__Sequence__init(robokpy_interfaces__action__ToolExecution_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Result * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_Result *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_Result__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_Result__Sequence__fini(robokpy_interfaces__action__ToolExecution_Result__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_Result__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_Result__Sequence *
robokpy_interfaces__action__ToolExecution_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Result__Sequence * array = (robokpy_interfaces__action__ToolExecution_Result__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_Result__Sequence__destroy(robokpy_interfaces__action__ToolExecution_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_Result__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_Result__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_Result__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_Result__Sequence * input,
  robokpy_interfaces__action__ToolExecution_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_Result * data =
      (robokpy_interfaces__action__ToolExecution_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
robokpy_interfaces__action__ToolExecution_Feedback__init(robokpy_interfaces__action__ToolExecution_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // percent_complete
  return true;
}

void
robokpy_interfaces__action__ToolExecution_Feedback__fini(robokpy_interfaces__action__ToolExecution_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // percent_complete
}

bool
robokpy_interfaces__action__ToolExecution_Feedback__are_equal(const robokpy_interfaces__action__ToolExecution_Feedback * lhs, const robokpy_interfaces__action__ToolExecution_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // percent_complete
  if (lhs->percent_complete != rhs->percent_complete) {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_Feedback__copy(
  const robokpy_interfaces__action__ToolExecution_Feedback * input,
  robokpy_interfaces__action__ToolExecution_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // percent_complete
  output->percent_complete = input->percent_complete;
  return true;
}

robokpy_interfaces__action__ToolExecution_Feedback *
robokpy_interfaces__action__ToolExecution_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Feedback * msg = (robokpy_interfaces__action__ToolExecution_Feedback *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_Feedback));
  bool success = robokpy_interfaces__action__ToolExecution_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_Feedback__destroy(robokpy_interfaces__action__ToolExecution_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_Feedback__Sequence__init(robokpy_interfaces__action__ToolExecution_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Feedback * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_Feedback *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_Feedback__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_Feedback__Sequence__fini(robokpy_interfaces__action__ToolExecution_Feedback__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_Feedback__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_Feedback__Sequence *
robokpy_interfaces__action__ToolExecution_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_Feedback__Sequence * array = (robokpy_interfaces__action__ToolExecution_Feedback__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_Feedback__Sequence__destroy(robokpy_interfaces__action__ToolExecution_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_Feedback__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_Feedback__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_Feedback__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_Feedback__Sequence * input,
  robokpy_interfaces__action__ToolExecution_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_Feedback * data =
      (robokpy_interfaces__action__ToolExecution_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "robokpy_interfaces/action/detail/tool_execution__functions.h"

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Request__init(robokpy_interfaces__action__ToolExecution_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!robokpy_interfaces__action__ToolExecution_Goal__init(&msg->goal)) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(robokpy_interfaces__action__ToolExecution_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  robokpy_interfaces__action__ToolExecution_Goal__fini(&msg->goal);
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Request__are_equal(const robokpy_interfaces__action__ToolExecution_SendGoal_Request * lhs, const robokpy_interfaces__action__ToolExecution_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!robokpy_interfaces__action__ToolExecution_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Request__copy(
  const robokpy_interfaces__action__ToolExecution_SendGoal_Request * input,
  robokpy_interfaces__action__ToolExecution_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!robokpy_interfaces__action__ToolExecution_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_SendGoal_Request *
robokpy_interfaces__action__ToolExecution_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Request * msg = (robokpy_interfaces__action__ToolExecution_SendGoal_Request *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Request));
  bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Request__destroy(robokpy_interfaces__action__ToolExecution_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__init(robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_SendGoal_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__fini(robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence *
robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * array = (robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__destroy(robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * input,
  robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_SendGoal_Request * data =
      (robokpy_interfaces__action__ToolExecution_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Response__init(robokpy_interfaces__action__ToolExecution_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Response__fini(robokpy_interfaces__action__ToolExecution_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Response__are_equal(const robokpy_interfaces__action__ToolExecution_SendGoal_Response * lhs, const robokpy_interfaces__action__ToolExecution_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
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
robokpy_interfaces__action__ToolExecution_SendGoal_Response__copy(
  const robokpy_interfaces__action__ToolExecution_SendGoal_Response * input,
  robokpy_interfaces__action__ToolExecution_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_SendGoal_Response *
robokpy_interfaces__action__ToolExecution_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Response * msg = (robokpy_interfaces__action__ToolExecution_SendGoal_Response *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Response));
  bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Response__destroy(robokpy_interfaces__action__ToolExecution_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__init(robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_SendGoal_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_SendGoal_Response__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__fini(robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_SendGoal_Response__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence *
robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * array = (robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__destroy(robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * input,
  robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_SendGoal_Response * data =
      (robokpy_interfaces__action__ToolExecution_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/action/detail/tool_execution__functions.h"

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Event__init(robokpy_interfaces__action__ToolExecution_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(robokpy_interfaces__action__ToolExecution_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Event__are_equal(const robokpy_interfaces__action__ToolExecution_SendGoal_Event * lhs, const robokpy_interfaces__action__ToolExecution_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Event__copy(
  const robokpy_interfaces__action__ToolExecution_SendGoal_Event * input,
  robokpy_interfaces__action__ToolExecution_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ToolExecution_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ToolExecution_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_SendGoal_Event *
robokpy_interfaces__action__ToolExecution_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Event * msg = (robokpy_interfaces__action__ToolExecution_SendGoal_Event *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Event));
  bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Event__destroy(robokpy_interfaces__action__ToolExecution_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__init(robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_SendGoal_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__fini(robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence *
robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * array = (robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__destroy(robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * input,
  robokpy_interfaces__action__ToolExecution_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_SendGoal_Event * data =
      (robokpy_interfaces__action__ToolExecution_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
robokpy_interfaces__action__ToolExecution_GetResult_Request__init(robokpy_interfaces__action__ToolExecution_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ToolExecution_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Request__fini(robokpy_interfaces__action__ToolExecution_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Request__are_equal(const robokpy_interfaces__action__ToolExecution_GetResult_Request * lhs, const robokpy_interfaces__action__ToolExecution_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Request__copy(
  const robokpy_interfaces__action__ToolExecution_GetResult_Request * input,
  robokpy_interfaces__action__ToolExecution_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_GetResult_Request *
robokpy_interfaces__action__ToolExecution_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Request * msg = (robokpy_interfaces__action__ToolExecution_GetResult_Request *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Request));
  bool success = robokpy_interfaces__action__ToolExecution_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Request__destroy(robokpy_interfaces__action__ToolExecution_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__init(robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_GetResult_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_GetResult_Request__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__fini(robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_GetResult_Request__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence *
robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * array = (robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__destroy(robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * input,
  robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_GetResult_Request * data =
      (robokpy_interfaces__action__ToolExecution_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "robokpy_interfaces/action/detail/tool_execution__functions.h"

bool
robokpy_interfaces__action__ToolExecution_GetResult_Response__init(robokpy_interfaces__action__ToolExecution_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!robokpy_interfaces__action__ToolExecution_Result__init(&msg->result)) {
    robokpy_interfaces__action__ToolExecution_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Response__fini(robokpy_interfaces__action__ToolExecution_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  robokpy_interfaces__action__ToolExecution_Result__fini(&msg->result);
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Response__are_equal(const robokpy_interfaces__action__ToolExecution_GetResult_Response * lhs, const robokpy_interfaces__action__ToolExecution_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!robokpy_interfaces__action__ToolExecution_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Response__copy(
  const robokpy_interfaces__action__ToolExecution_GetResult_Response * input,
  robokpy_interfaces__action__ToolExecution_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!robokpy_interfaces__action__ToolExecution_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_GetResult_Response *
robokpy_interfaces__action__ToolExecution_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Response * msg = (robokpy_interfaces__action__ToolExecution_GetResult_Response *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Response));
  bool success = robokpy_interfaces__action__ToolExecution_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Response__destroy(robokpy_interfaces__action__ToolExecution_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__init(robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_GetResult_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_GetResult_Response__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__fini(robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_GetResult_Response__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence *
robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * array = (robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__destroy(robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * input,
  robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_GetResult_Response * data =
      (robokpy_interfaces__action__ToolExecution_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/action/detail/tool_execution__functions.h"

bool
robokpy_interfaces__action__ToolExecution_GetResult_Event__init(robokpy_interfaces__action__ToolExecution_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(robokpy_interfaces__action__ToolExecution_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Event__are_equal(const robokpy_interfaces__action__ToolExecution_GetResult_Event * lhs, const robokpy_interfaces__action__ToolExecution_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Event__copy(
  const robokpy_interfaces__action__ToolExecution_GetResult_Event * input,
  robokpy_interfaces__action__ToolExecution_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ToolExecution_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ToolExecution_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_GetResult_Event *
robokpy_interfaces__action__ToolExecution_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Event * msg = (robokpy_interfaces__action__ToolExecution_GetResult_Event *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Event));
  bool success = robokpy_interfaces__action__ToolExecution_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Event__destroy(robokpy_interfaces__action__ToolExecution_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__init(robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_GetResult_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__fini(robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence *
robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * array = (robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__destroy(robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * input,
  robokpy_interfaces__action__ToolExecution_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_GetResult_Event * data =
      (robokpy_interfaces__action__ToolExecution_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "robokpy_interfaces/action/detail/tool_execution__functions.h"

bool
robokpy_interfaces__action__ToolExecution_FeedbackMessage__init(robokpy_interfaces__action__ToolExecution_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!robokpy_interfaces__action__ToolExecution_Feedback__init(&msg->feedback)) {
    robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(robokpy_interfaces__action__ToolExecution_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  robokpy_interfaces__action__ToolExecution_Feedback__fini(&msg->feedback);
}

bool
robokpy_interfaces__action__ToolExecution_FeedbackMessage__are_equal(const robokpy_interfaces__action__ToolExecution_FeedbackMessage * lhs, const robokpy_interfaces__action__ToolExecution_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!robokpy_interfaces__action__ToolExecution_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_FeedbackMessage__copy(
  const robokpy_interfaces__action__ToolExecution_FeedbackMessage * input,
  robokpy_interfaces__action__ToolExecution_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!robokpy_interfaces__action__ToolExecution_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ToolExecution_FeedbackMessage *
robokpy_interfaces__action__ToolExecution_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_FeedbackMessage * msg = (robokpy_interfaces__action__ToolExecution_FeedbackMessage *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ToolExecution_FeedbackMessage));
  bool success = robokpy_interfaces__action__ToolExecution_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ToolExecution_FeedbackMessage__destroy(robokpy_interfaces__action__ToolExecution_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__init(robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_FeedbackMessage * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ToolExecution_FeedbackMessage *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ToolExecution_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ToolExecution_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(&data[i - 1]);
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
robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__fini(robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * array)
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
      robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(&array->data[i]);
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

robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence *
robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * array = (robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__destroy(robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__are_equal(const robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * lhs, const robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence__copy(
  const robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * input,
  robokpy_interfaces__action__ToolExecution_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ToolExecution_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ToolExecution_FeedbackMessage * data =
      (robokpy_interfaces__action__ToolExecution_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ToolExecution_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ToolExecution_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ToolExecution_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
