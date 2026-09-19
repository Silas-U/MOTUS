// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mypalletizer_interfaces:srv/GripperStatus.idl
// generated code does not contain a copyright notice
#include "mypalletizer_interfaces/srv/detail/gripper_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
mypalletizer_interfaces__srv__GripperStatus_Request__init(mypalletizer_interfaces__srv__GripperStatus_Request * msg)
{
  if (!msg) {
    return false;
  }
  // status
  return true;
}

void
mypalletizer_interfaces__srv__GripperStatus_Request__fini(mypalletizer_interfaces__srv__GripperStatus_Request * msg)
{
  if (!msg) {
    return;
  }
  // status
}

bool
mypalletizer_interfaces__srv__GripperStatus_Request__are_equal(const mypalletizer_interfaces__srv__GripperStatus_Request * lhs, const mypalletizer_interfaces__srv__GripperStatus_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  return true;
}

bool
mypalletizer_interfaces__srv__GripperStatus_Request__copy(
  const mypalletizer_interfaces__srv__GripperStatus_Request * input,
  mypalletizer_interfaces__srv__GripperStatus_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  return true;
}

mypalletizer_interfaces__srv__GripperStatus_Request *
mypalletizer_interfaces__srv__GripperStatus_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Request * msg = (mypalletizer_interfaces__srv__GripperStatus_Request *)allocator.allocate(sizeof(mypalletizer_interfaces__srv__GripperStatus_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mypalletizer_interfaces__srv__GripperStatus_Request));
  bool success = mypalletizer_interfaces__srv__GripperStatus_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mypalletizer_interfaces__srv__GripperStatus_Request__destroy(mypalletizer_interfaces__srv__GripperStatus_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mypalletizer_interfaces__srv__GripperStatus_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__init(mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Request * data = NULL;

  if (size) {
    data = (mypalletizer_interfaces__srv__GripperStatus_Request *)allocator.zero_allocate(size, sizeof(mypalletizer_interfaces__srv__GripperStatus_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mypalletizer_interfaces__srv__GripperStatus_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mypalletizer_interfaces__srv__GripperStatus_Request__fini(&data[i - 1]);
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
mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__fini(mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * array)
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
      mypalletizer_interfaces__srv__GripperStatus_Request__fini(&array->data[i]);
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

mypalletizer_interfaces__srv__GripperStatus_Request__Sequence *
mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * array = (mypalletizer_interfaces__srv__GripperStatus_Request__Sequence *)allocator.allocate(sizeof(mypalletizer_interfaces__srv__GripperStatus_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__destroy(mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__are_equal(const mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * lhs, const mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mypalletizer_interfaces__srv__GripperStatus_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__copy(
  const mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * input,
  mypalletizer_interfaces__srv__GripperStatus_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mypalletizer_interfaces__srv__GripperStatus_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mypalletizer_interfaces__srv__GripperStatus_Request * data =
      (mypalletizer_interfaces__srv__GripperStatus_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mypalletizer_interfaces__srv__GripperStatus_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mypalletizer_interfaces__srv__GripperStatus_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mypalletizer_interfaces__srv__GripperStatus_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mypalletizer_interfaces__srv__GripperStatus_Response__init(mypalletizer_interfaces__srv__GripperStatus_Response * msg)
{
  if (!msg) {
    return false;
  }
  // flag
  return true;
}

void
mypalletizer_interfaces__srv__GripperStatus_Response__fini(mypalletizer_interfaces__srv__GripperStatus_Response * msg)
{
  if (!msg) {
    return;
  }
  // flag
}

bool
mypalletizer_interfaces__srv__GripperStatus_Response__are_equal(const mypalletizer_interfaces__srv__GripperStatus_Response * lhs, const mypalletizer_interfaces__srv__GripperStatus_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // flag
  if (lhs->flag != rhs->flag) {
    return false;
  }
  return true;
}

bool
mypalletizer_interfaces__srv__GripperStatus_Response__copy(
  const mypalletizer_interfaces__srv__GripperStatus_Response * input,
  mypalletizer_interfaces__srv__GripperStatus_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // flag
  output->flag = input->flag;
  return true;
}

mypalletizer_interfaces__srv__GripperStatus_Response *
mypalletizer_interfaces__srv__GripperStatus_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Response * msg = (mypalletizer_interfaces__srv__GripperStatus_Response *)allocator.allocate(sizeof(mypalletizer_interfaces__srv__GripperStatus_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mypalletizer_interfaces__srv__GripperStatus_Response));
  bool success = mypalletizer_interfaces__srv__GripperStatus_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mypalletizer_interfaces__srv__GripperStatus_Response__destroy(mypalletizer_interfaces__srv__GripperStatus_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mypalletizer_interfaces__srv__GripperStatus_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__init(mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Response * data = NULL;

  if (size) {
    data = (mypalletizer_interfaces__srv__GripperStatus_Response *)allocator.zero_allocate(size, sizeof(mypalletizer_interfaces__srv__GripperStatus_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mypalletizer_interfaces__srv__GripperStatus_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mypalletizer_interfaces__srv__GripperStatus_Response__fini(&data[i - 1]);
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
mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__fini(mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * array)
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
      mypalletizer_interfaces__srv__GripperStatus_Response__fini(&array->data[i]);
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

mypalletizer_interfaces__srv__GripperStatus_Response__Sequence *
mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * array = (mypalletizer_interfaces__srv__GripperStatus_Response__Sequence *)allocator.allocate(sizeof(mypalletizer_interfaces__srv__GripperStatus_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__destroy(mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__are_equal(const mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * lhs, const mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mypalletizer_interfaces__srv__GripperStatus_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__copy(
  const mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * input,
  mypalletizer_interfaces__srv__GripperStatus_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mypalletizer_interfaces__srv__GripperStatus_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mypalletizer_interfaces__srv__GripperStatus_Response * data =
      (mypalletizer_interfaces__srv__GripperStatus_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mypalletizer_interfaces__srv__GripperStatus_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mypalletizer_interfaces__srv__GripperStatus_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mypalletizer_interfaces__srv__GripperStatus_Response__copy(
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
// #include "mypalletizer_interfaces/srv/detail/gripper_status__functions.h"

bool
mypalletizer_interfaces__srv__GripperStatus_Event__init(mypalletizer_interfaces__srv__GripperStatus_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    mypalletizer_interfaces__srv__GripperStatus_Event__fini(msg);
    return false;
  }
  // request
  if (!mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__init(&msg->request, 0)) {
    mypalletizer_interfaces__srv__GripperStatus_Event__fini(msg);
    return false;
  }
  // response
  if (!mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__init(&msg->response, 0)) {
    mypalletizer_interfaces__srv__GripperStatus_Event__fini(msg);
    return false;
  }
  return true;
}

void
mypalletizer_interfaces__srv__GripperStatus_Event__fini(mypalletizer_interfaces__srv__GripperStatus_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__fini(&msg->request);
  // response
  mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__fini(&msg->response);
}

bool
mypalletizer_interfaces__srv__GripperStatus_Event__are_equal(const mypalletizer_interfaces__srv__GripperStatus_Event * lhs, const mypalletizer_interfaces__srv__GripperStatus_Event * rhs)
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
  if (!mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
mypalletizer_interfaces__srv__GripperStatus_Event__copy(
  const mypalletizer_interfaces__srv__GripperStatus_Event * input,
  mypalletizer_interfaces__srv__GripperStatus_Event * output)
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
  if (!mypalletizer_interfaces__srv__GripperStatus_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!mypalletizer_interfaces__srv__GripperStatus_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

mypalletizer_interfaces__srv__GripperStatus_Event *
mypalletizer_interfaces__srv__GripperStatus_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Event * msg = (mypalletizer_interfaces__srv__GripperStatus_Event *)allocator.allocate(sizeof(mypalletizer_interfaces__srv__GripperStatus_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mypalletizer_interfaces__srv__GripperStatus_Event));
  bool success = mypalletizer_interfaces__srv__GripperStatus_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mypalletizer_interfaces__srv__GripperStatus_Event__destroy(mypalletizer_interfaces__srv__GripperStatus_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mypalletizer_interfaces__srv__GripperStatus_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__init(mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Event * data = NULL;

  if (size) {
    data = (mypalletizer_interfaces__srv__GripperStatus_Event *)allocator.zero_allocate(size, sizeof(mypalletizer_interfaces__srv__GripperStatus_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mypalletizer_interfaces__srv__GripperStatus_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mypalletizer_interfaces__srv__GripperStatus_Event__fini(&data[i - 1]);
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
mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__fini(mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * array)
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
      mypalletizer_interfaces__srv__GripperStatus_Event__fini(&array->data[i]);
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

mypalletizer_interfaces__srv__GripperStatus_Event__Sequence *
mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * array = (mypalletizer_interfaces__srv__GripperStatus_Event__Sequence *)allocator.allocate(sizeof(mypalletizer_interfaces__srv__GripperStatus_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__destroy(mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__are_equal(const mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * lhs, const mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mypalletizer_interfaces__srv__GripperStatus_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mypalletizer_interfaces__srv__GripperStatus_Event__Sequence__copy(
  const mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * input,
  mypalletizer_interfaces__srv__GripperStatus_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mypalletizer_interfaces__srv__GripperStatus_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mypalletizer_interfaces__srv__GripperStatus_Event * data =
      (mypalletizer_interfaces__srv__GripperStatus_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mypalletizer_interfaces__srv__GripperStatus_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mypalletizer_interfaces__srv__GripperStatus_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mypalletizer_interfaces__srv__GripperStatus_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
