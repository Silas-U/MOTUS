// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:srv/Spawnobject.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/srv/detail/spawnobject__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `type_id`
#include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__srv__Spawnobject_Request__init(robokpy_interfaces__srv__Spawnobject_Request * msg)
{
  if (!msg) {
    return false;
  }
  // type_id
  if (!rosidl_runtime_c__String__init(&msg->type_id)) {
    robokpy_interfaces__srv__Spawnobject_Request__fini(msg);
    return false;
  }
  // x
  // y
  // z
  // qx
  // qy
  // qz
  // qw
  return true;
}

void
robokpy_interfaces__srv__Spawnobject_Request__fini(robokpy_interfaces__srv__Spawnobject_Request * msg)
{
  if (!msg) {
    return;
  }
  // type_id
  rosidl_runtime_c__String__fini(&msg->type_id);
  // x
  // y
  // z
  // qx
  // qy
  // qz
  // qw
}

bool
robokpy_interfaces__srv__Spawnobject_Request__are_equal(const robokpy_interfaces__srv__Spawnobject_Request * lhs, const robokpy_interfaces__srv__Spawnobject_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type_id), &(rhs->type_id)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // qx
  if (lhs->qx != rhs->qx) {
    return false;
  }
  // qy
  if (lhs->qy != rhs->qy) {
    return false;
  }
  // qz
  if (lhs->qz != rhs->qz) {
    return false;
  }
  // qw
  if (lhs->qw != rhs->qw) {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Spawnobject_Request__copy(
  const robokpy_interfaces__srv__Spawnobject_Request * input,
  robokpy_interfaces__srv__Spawnobject_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // type_id
  if (!rosidl_runtime_c__String__copy(
      &(input->type_id), &(output->type_id)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // qx
  output->qx = input->qx;
  // qy
  output->qy = input->qy;
  // qz
  output->qz = input->qz;
  // qw
  output->qw = input->qw;
  return true;
}

robokpy_interfaces__srv__Spawnobject_Request *
robokpy_interfaces__srv__Spawnobject_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Request * msg = (robokpy_interfaces__srv__Spawnobject_Request *)allocator.allocate(sizeof(robokpy_interfaces__srv__Spawnobject_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Spawnobject_Request));
  bool success = robokpy_interfaces__srv__Spawnobject_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Spawnobject_Request__destroy(robokpy_interfaces__srv__Spawnobject_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Spawnobject_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Spawnobject_Request__Sequence__init(robokpy_interfaces__srv__Spawnobject_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Spawnobject_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Spawnobject_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Spawnobject_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Spawnobject_Request__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Spawnobject_Request__Sequence__fini(robokpy_interfaces__srv__Spawnobject_Request__Sequence * array)
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
      robokpy_interfaces__srv__Spawnobject_Request__fini(&array->data[i]);
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

robokpy_interfaces__srv__Spawnobject_Request__Sequence *
robokpy_interfaces__srv__Spawnobject_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Request__Sequence * array = (robokpy_interfaces__srv__Spawnobject_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Spawnobject_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Spawnobject_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Spawnobject_Request__Sequence__destroy(robokpy_interfaces__srv__Spawnobject_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Spawnobject_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Spawnobject_Request__Sequence__are_equal(const robokpy_interfaces__srv__Spawnobject_Request__Sequence * lhs, const robokpy_interfaces__srv__Spawnobject_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Spawnobject_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Spawnobject_Request__Sequence__copy(
  const robokpy_interfaces__srv__Spawnobject_Request__Sequence * input,
  robokpy_interfaces__srv__Spawnobject_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Spawnobject_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Spawnobject_Request * data =
      (robokpy_interfaces__srv__Spawnobject_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Spawnobject_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Spawnobject_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Spawnobject_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// Member `child_model`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__srv__Spawnobject_Response__init(robokpy_interfaces__srv__Spawnobject_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    robokpy_interfaces__srv__Spawnobject_Response__fini(msg);
    return false;
  }
  // child_model
  if (!rosidl_runtime_c__String__init(&msg->child_model)) {
    robokpy_interfaces__srv__Spawnobject_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Spawnobject_Response__fini(robokpy_interfaces__srv__Spawnobject_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // child_model
  rosidl_runtime_c__String__fini(&msg->child_model);
}

bool
robokpy_interfaces__srv__Spawnobject_Response__are_equal(const robokpy_interfaces__srv__Spawnobject_Response * lhs, const robokpy_interfaces__srv__Spawnobject_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // child_model
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->child_model), &(rhs->child_model)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Spawnobject_Response__copy(
  const robokpy_interfaces__srv__Spawnobject_Response * input,
  robokpy_interfaces__srv__Spawnobject_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // child_model
  if (!rosidl_runtime_c__String__copy(
      &(input->child_model), &(output->child_model)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Spawnobject_Response *
robokpy_interfaces__srv__Spawnobject_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Response * msg = (robokpy_interfaces__srv__Spawnobject_Response *)allocator.allocate(sizeof(robokpy_interfaces__srv__Spawnobject_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Spawnobject_Response));
  bool success = robokpy_interfaces__srv__Spawnobject_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Spawnobject_Response__destroy(robokpy_interfaces__srv__Spawnobject_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Spawnobject_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Spawnobject_Response__Sequence__init(robokpy_interfaces__srv__Spawnobject_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Spawnobject_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Spawnobject_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Spawnobject_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Spawnobject_Response__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Spawnobject_Response__Sequence__fini(robokpy_interfaces__srv__Spawnobject_Response__Sequence * array)
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
      robokpy_interfaces__srv__Spawnobject_Response__fini(&array->data[i]);
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

robokpy_interfaces__srv__Spawnobject_Response__Sequence *
robokpy_interfaces__srv__Spawnobject_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Response__Sequence * array = (robokpy_interfaces__srv__Spawnobject_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Spawnobject_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Spawnobject_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Spawnobject_Response__Sequence__destroy(robokpy_interfaces__srv__Spawnobject_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Spawnobject_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Spawnobject_Response__Sequence__are_equal(const robokpy_interfaces__srv__Spawnobject_Response__Sequence * lhs, const robokpy_interfaces__srv__Spawnobject_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Spawnobject_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Spawnobject_Response__Sequence__copy(
  const robokpy_interfaces__srv__Spawnobject_Response__Sequence * input,
  robokpy_interfaces__srv__Spawnobject_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Spawnobject_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Spawnobject_Response * data =
      (robokpy_interfaces__srv__Spawnobject_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Spawnobject_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Spawnobject_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Spawnobject_Response__copy(
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
// #include "robokpy_interfaces/srv/detail/spawnobject__functions.h"

bool
robokpy_interfaces__srv__Spawnobject_Event__init(robokpy_interfaces__srv__Spawnobject_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__srv__Spawnobject_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__srv__Spawnobject_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__srv__Spawnobject_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Spawnobject_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__srv__Spawnobject_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__srv__Spawnobject_Event__fini(robokpy_interfaces__srv__Spawnobject_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__srv__Spawnobject_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__srv__Spawnobject_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__srv__Spawnobject_Event__are_equal(const robokpy_interfaces__srv__Spawnobject_Event * lhs, const robokpy_interfaces__srv__Spawnobject_Event * rhs)
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
  if (!robokpy_interfaces__srv__Spawnobject_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Spawnobject_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__srv__Spawnobject_Event__copy(
  const robokpy_interfaces__srv__Spawnobject_Event * input,
  robokpy_interfaces__srv__Spawnobject_Event * output)
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
  if (!robokpy_interfaces__srv__Spawnobject_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__srv__Spawnobject_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__srv__Spawnobject_Event *
robokpy_interfaces__srv__Spawnobject_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Event * msg = (robokpy_interfaces__srv__Spawnobject_Event *)allocator.allocate(sizeof(robokpy_interfaces__srv__Spawnobject_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__srv__Spawnobject_Event));
  bool success = robokpy_interfaces__srv__Spawnobject_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__srv__Spawnobject_Event__destroy(robokpy_interfaces__srv__Spawnobject_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__srv__Spawnobject_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__srv__Spawnobject_Event__Sequence__init(robokpy_interfaces__srv__Spawnobject_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__srv__Spawnobject_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__srv__Spawnobject_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__srv__Spawnobject_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__srv__Spawnobject_Event__fini(&data[i - 1]);
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
robokpy_interfaces__srv__Spawnobject_Event__Sequence__fini(robokpy_interfaces__srv__Spawnobject_Event__Sequence * array)
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
      robokpy_interfaces__srv__Spawnobject_Event__fini(&array->data[i]);
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

robokpy_interfaces__srv__Spawnobject_Event__Sequence *
robokpy_interfaces__srv__Spawnobject_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__srv__Spawnobject_Event__Sequence * array = (robokpy_interfaces__srv__Spawnobject_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__srv__Spawnobject_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__srv__Spawnobject_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__srv__Spawnobject_Event__Sequence__destroy(robokpy_interfaces__srv__Spawnobject_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__srv__Spawnobject_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__srv__Spawnobject_Event__Sequence__are_equal(const robokpy_interfaces__srv__Spawnobject_Event__Sequence * lhs, const robokpy_interfaces__srv__Spawnobject_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__srv__Spawnobject_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__srv__Spawnobject_Event__Sequence__copy(
  const robokpy_interfaces__srv__Spawnobject_Event__Sequence * input,
  robokpy_interfaces__srv__Spawnobject_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__srv__Spawnobject_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__srv__Spawnobject_Event * data =
      (robokpy_interfaces__srv__Spawnobject_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__srv__Spawnobject_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__srv__Spawnobject_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__srv__Spawnobject_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
