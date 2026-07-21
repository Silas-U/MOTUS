// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:srv/Jacobian.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/srv/detail/jacobian__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `q`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robokpy_interfaces__srv__Jacobian_Request__init(robokpy_interfaces__srv__Jacobian_Request * msg)
{
  if (!msg) {
    return false;
  }
  // q
  if (!rosidl_runtime_c__double__Sequence__init(&msg->q, 0)) {
    robokpy_interfaces__srv__Jacobian_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Jacobian_Request__fini(robokpy_interfaces__srv__Jacobian_Request * msg)
{
  if (!msg) {
    return;
  }
  // q
  rosidl_runtime_c__double__Sequence__fini(&msg->q);
}

bool
robokpy_interfaces__srv__Jacobian_Request__are_equal(const robokpy_interfaces__srv__Jacobian_Request * lhs, const robokpy_interfaces__srv__Jacobian_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // q
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->q), &(rhs->q)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Jacobian_Request__copy(
  const robokpy_interfaces__srv__Jacobian_Request * input,
  robokpy_interfaces__srv__Jacobian_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // q
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->q), &(output->q)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Jacobian_Request *
robokpy_interfaces__srv__Jacobian_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Request * msg = (robokpy_interfaces__srv__Jacobian_Request *)allocator.allocate(sizeof(robokpy_interfaces__srv__Jacobian_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Jacobian_Request));
  bool success = robokpy_interfaces__srv__Jacobian_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Jacobian_Request__destroy(robokpy_interfaces__srv__Jacobian_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Jacobian_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Jacobian_Request__Sequence__init(robokpy_interfaces__srv__Jacobian_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Jacobian_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Jacobian_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Jacobian_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Jacobian_Request__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Jacobian_Request__Sequence__fini(robokpy_interfaces__srv__Jacobian_Request__Sequence * array)
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
      robokpy_interfaces__srv__Jacobian_Request__fini(&array->data[i]);
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

robokpy_interfaces__srv__Jacobian_Request__Sequence *
robokpy_interfaces__srv__Jacobian_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Request__Sequence * array = (robokpy_interfaces__srv__Jacobian_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Jacobian_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Jacobian_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Jacobian_Request__Sequence__destroy(robokpy_interfaces__srv__Jacobian_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Jacobian_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Jacobian_Request__Sequence__are_equal(const robokpy_interfaces__srv__Jacobian_Request__Sequence * lhs, const robokpy_interfaces__srv__Jacobian_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Jacobian_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Jacobian_Request__Sequence__copy(
  const robokpy_interfaces__srv__Jacobian_Request__Sequence * input,
  robokpy_interfaces__srv__Jacobian_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Jacobian_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Jacobian_Request * data =
      (robokpy_interfaces__srv__Jacobian_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Jacobian_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Jacobian_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Jacobian_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `jacobian_flat`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__srv__Jacobian_Response__init(robokpy_interfaces__srv__Jacobian_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // jacobian_flat
  if (!rosidl_runtime_c__double__Sequence__init(&msg->jacobian_flat, 0)) {
    robokpy_interfaces__srv__Jacobian_Response__fini(msg);
    return false;
  }
  // rows
  // cols
  // manipulability
  // condition_number
  // rank
  // is_near_singular
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    robokpy_interfaces__srv__Jacobian_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Jacobian_Response__fini(robokpy_interfaces__srv__Jacobian_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // jacobian_flat
  rosidl_runtime_c__double__Sequence__fini(&msg->jacobian_flat);
  // rows
  // cols
  // manipulability
  // condition_number
  // rank
  // is_near_singular
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
robokpy_interfaces__srv__Jacobian_Response__are_equal(const robokpy_interfaces__srv__Jacobian_Response * lhs, const robokpy_interfaces__srv__Jacobian_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // jacobian_flat
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->jacobian_flat), &(rhs->jacobian_flat)))
  {
    return false;
  }
  // rows
  if (lhs->rows != rhs->rows) {
    return false;
  }
  // cols
  if (lhs->cols != rhs->cols) {
    return false;
  }
  // manipulability
  if (lhs->manipulability != rhs->manipulability) {
    return false;
  }
  // condition_number
  if (lhs->condition_number != rhs->condition_number) {
    return false;
  }
  // rank
  if (lhs->rank != rhs->rank) {
    return false;
  }
  // is_near_singular
  if (lhs->is_near_singular != rhs->is_near_singular) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Jacobian_Response__copy(
  const robokpy_interfaces__srv__Jacobian_Response * input,
  robokpy_interfaces__srv__Jacobian_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // jacobian_flat
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->jacobian_flat), &(output->jacobian_flat)))
  {
    return false;
  }
  // rows
  output->rows = input->rows;
  // cols
  output->cols = input->cols;
  // manipulability
  output->manipulability = input->manipulability;
  // condition_number
  output->condition_number = input->condition_number;
  // rank
  output->rank = input->rank;
  // is_near_singular
  output->is_near_singular = input->is_near_singular;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Jacobian_Response *
robokpy_interfaces__srv__Jacobian_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Response * msg = (robokpy_interfaces__srv__Jacobian_Response *)allocator.allocate(sizeof(robokpy_interfaces__srv__Jacobian_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Jacobian_Response));
  bool success = robokpy_interfaces__srv__Jacobian_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Jacobian_Response__destroy(robokpy_interfaces__srv__Jacobian_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Jacobian_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Jacobian_Response__Sequence__init(robokpy_interfaces__srv__Jacobian_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Jacobian_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Jacobian_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Jacobian_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Jacobian_Response__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Jacobian_Response__Sequence__fini(robokpy_interfaces__srv__Jacobian_Response__Sequence * array)
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
      robokpy_interfaces__srv__Jacobian_Response__fini(&array->data[i]);
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

robokpy_interfaces__srv__Jacobian_Response__Sequence *
robokpy_interfaces__srv__Jacobian_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Response__Sequence * array = (robokpy_interfaces__srv__Jacobian_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Jacobian_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Jacobian_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Jacobian_Response__Sequence__destroy(robokpy_interfaces__srv__Jacobian_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Jacobian_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Jacobian_Response__Sequence__are_equal(const robokpy_interfaces__srv__Jacobian_Response__Sequence * lhs, const robokpy_interfaces__srv__Jacobian_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Jacobian_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Jacobian_Response__Sequence__copy(
  const robokpy_interfaces__srv__Jacobian_Response__Sequence * input,
  robokpy_interfaces__srv__Jacobian_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Jacobian_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Jacobian_Response * data =
      (robokpy_interfaces__srv__Jacobian_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Jacobian_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Jacobian_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Jacobian_Response__copy(
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
// #include "robokpy_interfaces/srv/detail/jacobian__functions.h"

bool
robokpy_interfaces__srv__Jacobian_Event__init(robokpy_interfaces__srv__Jacobian_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__srv__Jacobian_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__srv__Jacobian_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__srv__Jacobian_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Jacobian_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__srv__Jacobian_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Jacobian_Event__fini(robokpy_interfaces__srv__Jacobian_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__srv__Jacobian_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__srv__Jacobian_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__srv__Jacobian_Event__are_equal(const robokpy_interfaces__srv__Jacobian_Event * lhs, const robokpy_interfaces__srv__Jacobian_Event * rhs)
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
  if (!robokpy_interfaces__srv__Jacobian_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Jacobian_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Jacobian_Event__copy(
  const robokpy_interfaces__srv__Jacobian_Event * input,
  robokpy_interfaces__srv__Jacobian_Event * output)
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
  if (!robokpy_interfaces__srv__Jacobian_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Jacobian_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Jacobian_Event *
robokpy_interfaces__srv__Jacobian_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Event * msg = (robokpy_interfaces__srv__Jacobian_Event *)allocator.allocate(sizeof(robokpy_interfaces__srv__Jacobian_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Jacobian_Event));
  bool success = robokpy_interfaces__srv__Jacobian_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Jacobian_Event__destroy(robokpy_interfaces__srv__Jacobian_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Jacobian_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Jacobian_Event__Sequence__init(robokpy_interfaces__srv__Jacobian_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Jacobian_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Jacobian_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Jacobian_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Jacobian_Event__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Jacobian_Event__Sequence__fini(robokpy_interfaces__srv__Jacobian_Event__Sequence * array)
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
      robokpy_interfaces__srv__Jacobian_Event__fini(&array->data[i]);
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

robokpy_interfaces__srv__Jacobian_Event__Sequence *
robokpy_interfaces__srv__Jacobian_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Jacobian_Event__Sequence * array = (robokpy_interfaces__srv__Jacobian_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Jacobian_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Jacobian_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Jacobian_Event__Sequence__destroy(robokpy_interfaces__srv__Jacobian_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Jacobian_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Jacobian_Event__Sequence__are_equal(const robokpy_interfaces__srv__Jacobian_Event__Sequence * lhs, const robokpy_interfaces__srv__Jacobian_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Jacobian_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Jacobian_Event__Sequence__copy(
  const robokpy_interfaces__srv__Jacobian_Event__Sequence * input,
  robokpy_interfaces__srv__Jacobian_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Jacobian_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Jacobian_Event * data =
      (robokpy_interfaces__srv__Jacobian_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Jacobian_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Jacobian_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Jacobian_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
