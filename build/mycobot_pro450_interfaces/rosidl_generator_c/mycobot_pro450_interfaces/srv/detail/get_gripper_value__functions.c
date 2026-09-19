// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mycobot_pro450_interfaces:srv/GetGripperValue.idl
// generated code does not contain a copyright notice
#include "mycobot_pro450_interfaces/srv/detail/get_gripper_value__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Request__init(mycobot_pro450_interfaces__srv__GetGripperValue_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Request__fini(mycobot_pro450_interfaces__srv__GetGripperValue_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Request__are_equal(const mycobot_pro450_interfaces__srv__GetGripperValue_Request * lhs, const mycobot_pro450_interfaces__srv__GetGripperValue_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Request__copy(
  const mycobot_pro450_interfaces__srv__GetGripperValue_Request * input,
  mycobot_pro450_interfaces__srv__GetGripperValue_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

mycobot_pro450_interfaces__srv__GetGripperValue_Request *
mycobot_pro450_interfaces__srv__GetGripperValue_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Request * msg = (mycobot_pro450_interfaces__srv__GetGripperValue_Request *)allocator.allocate(sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Request));
  bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Request__destroy(mycobot_pro450_interfaces__srv__GetGripperValue_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__init(mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Request * data = NULL;

  if (size) {
    data = (mycobot_pro450_interfaces__srv__GetGripperValue_Request *)allocator.zero_allocate(size, sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_pro450_interfaces__srv__GetGripperValue_Request__fini(&data[i - 1]);
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
mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__fini(mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * array)
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
      mycobot_pro450_interfaces__srv__GetGripperValue_Request__fini(&array->data[i]);
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

mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * array = (mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence *)allocator.allocate(sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__destroy(mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__are_equal(const mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * lhs, const mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_pro450_interfaces__srv__GetGripperValue_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__copy(
  const mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * input,
  mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_pro450_interfaces__srv__GetGripperValue_Request * data =
      (mycobot_pro450_interfaces__srv__GetGripperValue_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_pro450_interfaces__srv__GetGripperValue_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_pro450_interfaces__srv__GetGripperValue_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_pro450_interfaces__srv__GetGripperValue_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mycobot_pro450_interfaces__srv__GetGripperValue_Response__init(mycobot_pro450_interfaces__srv__GetGripperValue_Response * msg)
{
  if (!msg) {
    return false;
  }
  // gripper_angle
  return true;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Response__fini(mycobot_pro450_interfaces__srv__GetGripperValue_Response * msg)
{
  if (!msg) {
    return;
  }
  // gripper_angle
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Response__are_equal(const mycobot_pro450_interfaces__srv__GetGripperValue_Response * lhs, const mycobot_pro450_interfaces__srv__GetGripperValue_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // gripper_angle
  if (lhs->gripper_angle != rhs->gripper_angle) {
    return false;
  }
  return true;
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Response__copy(
  const mycobot_pro450_interfaces__srv__GetGripperValue_Response * input,
  mycobot_pro450_interfaces__srv__GetGripperValue_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // gripper_angle
  output->gripper_angle = input->gripper_angle;
  return true;
}

mycobot_pro450_interfaces__srv__GetGripperValue_Response *
mycobot_pro450_interfaces__srv__GetGripperValue_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Response * msg = (mycobot_pro450_interfaces__srv__GetGripperValue_Response *)allocator.allocate(sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Response));
  bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Response__destroy(mycobot_pro450_interfaces__srv__GetGripperValue_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__init(mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Response * data = NULL;

  if (size) {
    data = (mycobot_pro450_interfaces__srv__GetGripperValue_Response *)allocator.zero_allocate(size, sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_pro450_interfaces__srv__GetGripperValue_Response__fini(&data[i - 1]);
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
mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__fini(mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * array)
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
      mycobot_pro450_interfaces__srv__GetGripperValue_Response__fini(&array->data[i]);
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

mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * array = (mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence *)allocator.allocate(sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__destroy(mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__are_equal(const mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * lhs, const mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_pro450_interfaces__srv__GetGripperValue_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__copy(
  const mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * input,
  mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_pro450_interfaces__srv__GetGripperValue_Response * data =
      (mycobot_pro450_interfaces__srv__GetGripperValue_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_pro450_interfaces__srv__GetGripperValue_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_pro450_interfaces__srv__GetGripperValue_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_pro450_interfaces__srv__GetGripperValue_Response__copy(
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
// #include "mycobot_pro450_interfaces/srv/detail/get_gripper_value__functions.h"

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Event__init(mycobot_pro450_interfaces__srv__GetGripperValue_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(msg);
    return false;
  }
  // request
  if (!mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__init(&msg->request, 0)) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(msg);
    return false;
  }
  // response
  if (!mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__init(&msg->response, 0)) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(msg);
    return false;
  }
  return true;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(mycobot_pro450_interfaces__srv__GetGripperValue_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__fini(&msg->request);
  // response
  mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__fini(&msg->response);
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Event__are_equal(const mycobot_pro450_interfaces__srv__GetGripperValue_Event * lhs, const mycobot_pro450_interfaces__srv__GetGripperValue_Event * rhs)
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
  if (!mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Event__copy(
  const mycobot_pro450_interfaces__srv__GetGripperValue_Event * input,
  mycobot_pro450_interfaces__srv__GetGripperValue_Event * output)
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
  if (!mycobot_pro450_interfaces__srv__GetGripperValue_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!mycobot_pro450_interfaces__srv__GetGripperValue_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

mycobot_pro450_interfaces__srv__GetGripperValue_Event *
mycobot_pro450_interfaces__srv__GetGripperValue_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Event * msg = (mycobot_pro450_interfaces__srv__GetGripperValue_Event *)allocator.allocate(sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Event));
  bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Event__destroy(mycobot_pro450_interfaces__srv__GetGripperValue_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__init(mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Event * data = NULL;

  if (size) {
    data = (mycobot_pro450_interfaces__srv__GetGripperValue_Event *)allocator.zero_allocate(size, sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(&data[i - 1]);
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
mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__fini(mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * array)
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
      mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(&array->data[i]);
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

mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * array = (mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence *)allocator.allocate(sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__destroy(mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__are_equal(const mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * lhs, const mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mycobot_pro450_interfaces__srv__GetGripperValue_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence__copy(
  const mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * input,
  mycobot_pro450_interfaces__srv__GetGripperValue_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mycobot_pro450_interfaces__srv__GetGripperValue_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mycobot_pro450_interfaces__srv__GetGripperValue_Event * data =
      (mycobot_pro450_interfaces__srv__GetGripperValue_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mycobot_pro450_interfaces__srv__GetGripperValue_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mycobot_pro450_interfaces__srv__GetGripperValue_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mycobot_pro450_interfaces__srv__GetGripperValue_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
