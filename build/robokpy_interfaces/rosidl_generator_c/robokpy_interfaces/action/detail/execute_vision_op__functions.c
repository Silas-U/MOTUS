// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:action/ExecuteVisionOp.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `vision_id`
// Member `operation`
#include "rosidl_runtime_c/string_functions.h"
// Member `params`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_Goal__init(robokpy_interfaces__action__ExecuteVisionOp_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // vision_id
  if (!rosidl_runtime_c__String__init(&msg->vision_id)) {
    robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(msg);
    return false;
  }
  // operation
  if (!rosidl_runtime_c__String__init(&msg->operation)) {
    robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(msg);
    return false;
  }
  // params
  if (!rosidl_runtime_c__double__Sequence__init(&msg->params, 0)) {
    robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(robokpy_interfaces__action__ExecuteVisionOp_Goal * msg)
{
  if (!msg) {
    return;
  }
  // vision_id
  rosidl_runtime_c__String__fini(&msg->vision_id);
  // operation
  rosidl_runtime_c__String__fini(&msg->operation);
  // params
  rosidl_runtime_c__double__Sequence__fini(&msg->params);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Goal__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_Goal * lhs, const robokpy_interfaces__action__ExecuteVisionOp_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vision_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->vision_id), &(rhs->vision_id)))
  {
    return false;
  }
  // operation
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->operation), &(rhs->operation)))
  {
    return false;
  }
  // params
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->params), &(rhs->params)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Goal__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_Goal * input,
  robokpy_interfaces__action__ExecuteVisionOp_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // vision_id
  if (!rosidl_runtime_c__String__copy(
      &(input->vision_id), &(output->vision_id)))
  {
    return false;
  }
  // operation
  if (!rosidl_runtime_c__String__copy(
      &(input->operation), &(output->operation)))
  {
    return false;
  }
  // params
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->params), &(output->params)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_Goal *
robokpy_interfaces__action__ExecuteVisionOp_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Goal * msg = (robokpy_interfaces__action__ExecuteVisionOp_Goal *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_Goal));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Goal__destroy(robokpy_interfaces__action__ExecuteVisionOp_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Goal * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_Goal *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_Goal * data =
      (robokpy_interfaces__action__ExecuteVisionOp_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `detected_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `detected_value`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_Result__init(robokpy_interfaces__action__ExecuteVisionOp_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_code
  // detected_pose
  if (!geometry_msgs__msg__Pose__init(&msg->detected_pose)) {
    robokpy_interfaces__action__ExecuteVisionOp_Result__fini(msg);
    return false;
  }
  // detected_value
  if (!rosidl_runtime_c__String__init(&msg->detected_value)) {
    robokpy_interfaces__action__ExecuteVisionOp_Result__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Result__fini(robokpy_interfaces__action__ExecuteVisionOp_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_code
  // detected_pose
  geometry_msgs__msg__Pose__fini(&msg->detected_pose);
  // detected_value
  rosidl_runtime_c__String__fini(&msg->detected_value);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Result__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_Result * lhs, const robokpy_interfaces__action__ExecuteVisionOp_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  // detected_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->detected_pose), &(rhs->detected_pose)))
  {
    return false;
  }
  // detected_value
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->detected_value), &(rhs->detected_value)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Result__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_Result * input,
  robokpy_interfaces__action__ExecuteVisionOp_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_code
  output->error_code = input->error_code;
  // detected_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->detected_pose), &(output->detected_pose)))
  {
    return false;
  }
  // detected_value
  if (!rosidl_runtime_c__String__copy(
      &(input->detected_value), &(output->detected_value)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_Result *
robokpy_interfaces__action__ExecuteVisionOp_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Result * msg = (robokpy_interfaces__action__ExecuteVisionOp_Result *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_Result));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Result__destroy(robokpy_interfaces__action__ExecuteVisionOp_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Result * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_Result *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_Result__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_Result__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_Result * data =
      (robokpy_interfaces__action__ExecuteVisionOp_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `status`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_Feedback__init(robokpy_interfaces__action__ExecuteVisionOp_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(msg);
    return false;
  }
  // percent_complete
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(robokpy_interfaces__action__ExecuteVisionOp_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // percent_complete
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Feedback__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_Feedback * lhs, const robokpy_interfaces__action__ExecuteVisionOp_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // percent_complete
  if (lhs->percent_complete != rhs->percent_complete) {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Feedback__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_Feedback * input,
  robokpy_interfaces__action__ExecuteVisionOp_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // percent_complete
  output->percent_complete = input->percent_complete;
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_Feedback *
robokpy_interfaces__action__ExecuteVisionOp_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Feedback * msg = (robokpy_interfaces__action__ExecuteVisionOp_Feedback *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_Feedback));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Feedback__destroy(robokpy_interfaces__action__ExecuteVisionOp_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Feedback * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_Feedback *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_Feedback * data =
      (robokpy_interfaces__action__ExecuteVisionOp_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_Feedback__copy(
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__init(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!robokpy_interfaces__action__ExecuteVisionOp_Goal__init(&msg->goal)) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  robokpy_interfaces__action__ExecuteVisionOp_Goal__fini(&msg->goal);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * lhs, const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * rhs)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * input,
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * output)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request *
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * msg = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__destroy(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request * data =
      (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__copy(
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
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__init(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__fini(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * lhs, const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * rhs)
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
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * input,
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * output)
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

robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response *
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * msg = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__destroy(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response * data =
      (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__copy(
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__init(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * lhs, const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * rhs)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * input,
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * output)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event *
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * msg = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__destroy(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event * data =
      (robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event__copy(
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
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__init(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__fini(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * lhs, const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * rhs)
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
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * input,
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * output)
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

robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request *
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * msg = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__destroy(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request * data =
      (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__copy(
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__init(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!robokpy_interfaces__action__ExecuteVisionOp_Result__init(&msg->result)) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__fini(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  robokpy_interfaces__action__ExecuteVisionOp_Result__fini(&msg->result);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * lhs, const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!robokpy_interfaces__action__ExecuteVisionOp_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * input,
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!robokpy_interfaces__action__ExecuteVisionOp_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response *
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * msg = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__destroy(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response * data =
      (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__copy(
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__init(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * lhs, const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * rhs)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * input,
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * output)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event *
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * msg = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__destroy(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event * data =
      (robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event__copy(
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
// #include "robokpy_interfaces/action/detail/execute_vision_op__functions.h"

bool
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__init(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!robokpy_interfaces__action__ExecuteVisionOp_Feedback__init(&msg->feedback)) {
    robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  robokpy_interfaces__action__ExecuteVisionOp_Feedback__fini(&msg->feedback);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * lhs, const robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * rhs)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * input,
  robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * output)
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
  if (!robokpy_interfaces__action__ExecuteVisionOp_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage *
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * msg = (robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage));
  bool success = robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__destroy(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__init(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__fini(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * array)
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
      robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence *
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * array = (robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__destroy(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__are_equal(const robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * lhs, const robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence__copy(
  const robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * input,
  robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage * data =
      (robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
