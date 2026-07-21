// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:srv/Reachable.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/srv/detail/reachable__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `seed`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robokpy_interfaces__srv__Reachable_Request__init(robokpy_interfaces__srv__Reachable_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target_pose
  // seed
  if (!rosidl_runtime_c__double__Sequence__init(&msg->seed, 0)) {
    robokpy_interfaces__srv__Reachable_Request__fini(msg);
    return false;
  }
  // tol
  return true;
}

void
robokpy_interfaces__srv__Reachable_Request__fini(robokpy_interfaces__srv__Reachable_Request * msg)
{
  if (!msg) {
    return;
  }
  // target_pose
  // seed
  rosidl_runtime_c__double__Sequence__fini(&msg->seed);
  // tol
}

bool
robokpy_interfaces__srv__Reachable_Request__are_equal(const robokpy_interfaces__srv__Reachable_Request * lhs, const robokpy_interfaces__srv__Reachable_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_pose
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->target_pose[i] != rhs->target_pose[i]) {
      return false;
    }
  }
  // seed
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->seed), &(rhs->seed)))
  {
    return false;
  }
  // tol
  if (lhs->tol != rhs->tol) {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Reachable_Request__copy(
  const robokpy_interfaces__srv__Reachable_Request * input,
  robokpy_interfaces__srv__Reachable_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // target_pose
  for (size_t i = 0; i < 7; ++i) {
    output->target_pose[i] = input->target_pose[i];
  }
  // seed
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->seed), &(output->seed)))
  {
    return false;
  }
  // tol
  output->tol = input->tol;
  return true;
}

robokpy_interfaces__srv__Reachable_Request *
robokpy_interfaces__srv__Reachable_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Request * msg = (robokpy_interfaces__srv__Reachable_Request *)allocator.allocate(sizeof(robokpy_interfaces__srv__Reachable_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Reachable_Request));
  bool success = robokpy_interfaces__srv__Reachable_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Reachable_Request__destroy(robokpy_interfaces__srv__Reachable_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Reachable_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Reachable_Request__Sequence__init(robokpy_interfaces__srv__Reachable_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Reachable_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Reachable_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Reachable_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Reachable_Request__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Reachable_Request__Sequence__fini(robokpy_interfaces__srv__Reachable_Request__Sequence * array)
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
      robokpy_interfaces__srv__Reachable_Request__fini(&array->data[i]);
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

robokpy_interfaces__srv__Reachable_Request__Sequence *
robokpy_interfaces__srv__Reachable_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Request__Sequence * array = (robokpy_interfaces__srv__Reachable_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Reachable_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Reachable_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Reachable_Request__Sequence__destroy(robokpy_interfaces__srv__Reachable_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Reachable_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Reachable_Request__Sequence__are_equal(const robokpy_interfaces__srv__Reachable_Request__Sequence * lhs, const robokpy_interfaces__srv__Reachable_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Reachable_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Reachable_Request__Sequence__copy(
  const robokpy_interfaces__srv__Reachable_Request__Sequence * input,
  robokpy_interfaces__srv__Reachable_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Reachable_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Reachable_Request * data =
      (robokpy_interfaces__srv__Reachable_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Reachable_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Reachable_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Reachable_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `q`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__srv__Reachable_Response__init(robokpy_interfaces__srv__Reachable_Response * msg)
{
  if (!msg) {
    return false;
  }
  // reachable
  // q
  if (!rosidl_runtime_c__double__Sequence__init(&msg->q, 0)) {
    robokpy_interfaces__srv__Reachable_Response__fini(msg);
    return false;
  }
  // error
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    robokpy_interfaces__srv__Reachable_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Reachable_Response__fini(robokpy_interfaces__srv__Reachable_Response * msg)
{
  if (!msg) {
    return;
  }
  // reachable
  // q
  rosidl_runtime_c__double__Sequence__fini(&msg->q);
  // error
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
robokpy_interfaces__srv__Reachable_Response__are_equal(const robokpy_interfaces__srv__Reachable_Response * lhs, const robokpy_interfaces__srv__Reachable_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // reachable
  if (lhs->reachable != rhs->reachable) {
    return false;
  }
  // q
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->q), &(rhs->q)))
  {
    return false;
  }
  // error
  if (lhs->error != rhs->error) {
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
robokpy_interfaces__srv__Reachable_Response__copy(
  const robokpy_interfaces__srv__Reachable_Response * input,
  robokpy_interfaces__srv__Reachable_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // reachable
  output->reachable = input->reachable;
  // q
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->q), &(output->q)))
  {
    return false;
  }
  // error
  output->error = input->error;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Reachable_Response *
robokpy_interfaces__srv__Reachable_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Response * msg = (robokpy_interfaces__srv__Reachable_Response *)allocator.allocate(sizeof(robokpy_interfaces__srv__Reachable_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Reachable_Response));
  bool success = robokpy_interfaces__srv__Reachable_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Reachable_Response__destroy(robokpy_interfaces__srv__Reachable_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Reachable_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Reachable_Response__Sequence__init(robokpy_interfaces__srv__Reachable_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Reachable_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Reachable_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Reachable_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Reachable_Response__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Reachable_Response__Sequence__fini(robokpy_interfaces__srv__Reachable_Response__Sequence * array)
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
      robokpy_interfaces__srv__Reachable_Response__fini(&array->data[i]);
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

robokpy_interfaces__srv__Reachable_Response__Sequence *
robokpy_interfaces__srv__Reachable_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Response__Sequence * array = (robokpy_interfaces__srv__Reachable_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Reachable_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Reachable_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Reachable_Response__Sequence__destroy(robokpy_interfaces__srv__Reachable_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Reachable_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Reachable_Response__Sequence__are_equal(const robokpy_interfaces__srv__Reachable_Response__Sequence * lhs, const robokpy_interfaces__srv__Reachable_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Reachable_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Reachable_Response__Sequence__copy(
  const robokpy_interfaces__srv__Reachable_Response__Sequence * input,
  robokpy_interfaces__srv__Reachable_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Reachable_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Reachable_Response * data =
      (robokpy_interfaces__srv__Reachable_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Reachable_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Reachable_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Reachable_Response__copy(
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
// #include "robokpy_interfaces/srv/detail/reachable__functions.h"

bool
robokpy_interfaces__srv__Reachable_Event__init(robokpy_interfaces__srv__Reachable_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__srv__Reachable_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__srv__Reachable_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__srv__Reachable_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Reachable_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__srv__Reachable_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Reachable_Event__fini(robokpy_interfaces__srv__Reachable_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__srv__Reachable_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__srv__Reachable_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__srv__Reachable_Event__are_equal(const robokpy_interfaces__srv__Reachable_Event * lhs, const robokpy_interfaces__srv__Reachable_Event * rhs)
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
  if (!robokpy_interfaces__srv__Reachable_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Reachable_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Reachable_Event__copy(
  const robokpy_interfaces__srv__Reachable_Event * input,
  robokpy_interfaces__srv__Reachable_Event * output)
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
  if (!robokpy_interfaces__srv__Reachable_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Reachable_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Reachable_Event *
robokpy_interfaces__srv__Reachable_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Event * msg = (robokpy_interfaces__srv__Reachable_Event *)allocator.allocate(sizeof(robokpy_interfaces__srv__Reachable_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Reachable_Event));
  bool success = robokpy_interfaces__srv__Reachable_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Reachable_Event__destroy(robokpy_interfaces__srv__Reachable_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Reachable_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Reachable_Event__Sequence__init(robokpy_interfaces__srv__Reachable_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Reachable_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Reachable_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Reachable_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Reachable_Event__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Reachable_Event__Sequence__fini(robokpy_interfaces__srv__Reachable_Event__Sequence * array)
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
      robokpy_interfaces__srv__Reachable_Event__fini(&array->data[i]);
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

robokpy_interfaces__srv__Reachable_Event__Sequence *
robokpy_interfaces__srv__Reachable_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Reachable_Event__Sequence * array = (robokpy_interfaces__srv__Reachable_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Reachable_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Reachable_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Reachable_Event__Sequence__destroy(robokpy_interfaces__srv__Reachable_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Reachable_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Reachable_Event__Sequence__are_equal(const robokpy_interfaces__srv__Reachable_Event__Sequence * lhs, const robokpy_interfaces__srv__Reachable_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Reachable_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Reachable_Event__Sequence__copy(
  const robokpy_interfaces__srv__Reachable_Event__Sequence * input,
  robokpy_interfaces__srv__Reachable_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Reachable_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Reachable_Event * data =
      (robokpy_interfaces__srv__Reachable_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Reachable_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Reachable_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Reachable_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
