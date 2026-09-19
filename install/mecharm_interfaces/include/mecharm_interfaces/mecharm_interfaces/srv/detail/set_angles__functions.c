// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mecharm_interfaces:srv/SetAngles.idl
// generated code does not contain a copyright notice
#include "mecharm_interfaces/srv/detail/set_angles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
mecharm_interfaces__srv__SetAngles_Request__init(mecharm_interfaces__srv__SetAngles_Request * msg)
{
  if (!msg) {
    return false;
  }
  // joint_1
  // joint_2
  // joint_3
  // joint_4
  // joint_5
  // joint_6
  // speed
  return true;
}

void
mecharm_interfaces__srv__SetAngles_Request__fini(mecharm_interfaces__srv__SetAngles_Request * msg)
{
  if (!msg) {
    return;
  }
  // joint_1
  // joint_2
  // joint_3
  // joint_4
  // joint_5
  // joint_6
  // speed
}

bool
mecharm_interfaces__srv__SetAngles_Request__are_equal(const mecharm_interfaces__srv__SetAngles_Request * lhs, const mecharm_interfaces__srv__SetAngles_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint_1
  if (lhs->joint_1 != rhs->joint_1) {
    return false;
  }
  // joint_2
  if (lhs->joint_2 != rhs->joint_2) {
    return false;
  }
  // joint_3
  if (lhs->joint_3 != rhs->joint_3) {
    return false;
  }
  // joint_4
  if (lhs->joint_4 != rhs->joint_4) {
    return false;
  }
  // joint_5
  if (lhs->joint_5 != rhs->joint_5) {
    return false;
  }
  // joint_6
  if (lhs->joint_6 != rhs->joint_6) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
mecharm_interfaces__srv__SetAngles_Request__copy(
  const mecharm_interfaces__srv__SetAngles_Request * input,
  mecharm_interfaces__srv__SetAngles_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // joint_1
  output->joint_1 = input->joint_1;
  // joint_2
  output->joint_2 = input->joint_2;
  // joint_3
  output->joint_3 = input->joint_3;
  // joint_4
  output->joint_4 = input->joint_4;
  // joint_5
  output->joint_5 = input->joint_5;
  // joint_6
  output->joint_6 = input->joint_6;
  // speed
  output->speed = input->speed;
  return true;
}

mecharm_interfaces__srv__SetAngles_Request *
mecharm_interfaces__srv__SetAngles_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Request * msg = (mecharm_interfaces__srv__SetAngles_Request *)allocator.allocate(sizeof(mecharm_interfaces__srv__SetAngles_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mecharm_interfaces__srv__SetAngles_Request));
  bool success = mecharm_interfaces__srv__SetAngles_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mecharm_interfaces__srv__SetAngles_Request__destroy(mecharm_interfaces__srv__SetAngles_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mecharm_interfaces__srv__SetAngles_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mecharm_interfaces__srv__SetAngles_Request__Sequence__init(mecharm_interfaces__srv__SetAngles_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Request * data = NULL;

  if (size) {
    data = (mecharm_interfaces__srv__SetAngles_Request *)allocator.zero_allocate(size, sizeof(mecharm_interfaces__srv__SetAngles_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mecharm_interfaces__srv__SetAngles_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mecharm_interfaces__srv__SetAngles_Request__fini(&data[i - 1]);
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
mecharm_interfaces__srv__SetAngles_Request__Sequence__fini(mecharm_interfaces__srv__SetAngles_Request__Sequence * array)
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
      mecharm_interfaces__srv__SetAngles_Request__fini(&array->data[i]);
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

mecharm_interfaces__srv__SetAngles_Request__Sequence *
mecharm_interfaces__srv__SetAngles_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Request__Sequence * array = (mecharm_interfaces__srv__SetAngles_Request__Sequence *)allocator.allocate(sizeof(mecharm_interfaces__srv__SetAngles_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mecharm_interfaces__srv__SetAngles_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mecharm_interfaces__srv__SetAngles_Request__Sequence__destroy(mecharm_interfaces__srv__SetAngles_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mecharm_interfaces__srv__SetAngles_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mecharm_interfaces__srv__SetAngles_Request__Sequence__are_equal(const mecharm_interfaces__srv__SetAngles_Request__Sequence * lhs, const mecharm_interfaces__srv__SetAngles_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mecharm_interfaces__srv__SetAngles_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mecharm_interfaces__srv__SetAngles_Request__Sequence__copy(
  const mecharm_interfaces__srv__SetAngles_Request__Sequence * input,
  mecharm_interfaces__srv__SetAngles_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mecharm_interfaces__srv__SetAngles_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mecharm_interfaces__srv__SetAngles_Request * data =
      (mecharm_interfaces__srv__SetAngles_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mecharm_interfaces__srv__SetAngles_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mecharm_interfaces__srv__SetAngles_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mecharm_interfaces__srv__SetAngles_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
mecharm_interfaces__srv__SetAngles_Response__init(mecharm_interfaces__srv__SetAngles_Response * msg)
{
  if (!msg) {
    return false;
  }
  // flag
  return true;
}

void
mecharm_interfaces__srv__SetAngles_Response__fini(mecharm_interfaces__srv__SetAngles_Response * msg)
{
  if (!msg) {
    return;
  }
  // flag
}

bool
mecharm_interfaces__srv__SetAngles_Response__are_equal(const mecharm_interfaces__srv__SetAngles_Response * lhs, const mecharm_interfaces__srv__SetAngles_Response * rhs)
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
mecharm_interfaces__srv__SetAngles_Response__copy(
  const mecharm_interfaces__srv__SetAngles_Response * input,
  mecharm_interfaces__srv__SetAngles_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // flag
  output->flag = input->flag;
  return true;
}

mecharm_interfaces__srv__SetAngles_Response *
mecharm_interfaces__srv__SetAngles_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Response * msg = (mecharm_interfaces__srv__SetAngles_Response *)allocator.allocate(sizeof(mecharm_interfaces__srv__SetAngles_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mecharm_interfaces__srv__SetAngles_Response));
  bool success = mecharm_interfaces__srv__SetAngles_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mecharm_interfaces__srv__SetAngles_Response__destroy(mecharm_interfaces__srv__SetAngles_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mecharm_interfaces__srv__SetAngles_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mecharm_interfaces__srv__SetAngles_Response__Sequence__init(mecharm_interfaces__srv__SetAngles_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Response * data = NULL;

  if (size) {
    data = (mecharm_interfaces__srv__SetAngles_Response *)allocator.zero_allocate(size, sizeof(mecharm_interfaces__srv__SetAngles_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mecharm_interfaces__srv__SetAngles_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mecharm_interfaces__srv__SetAngles_Response__fini(&data[i - 1]);
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
mecharm_interfaces__srv__SetAngles_Response__Sequence__fini(mecharm_interfaces__srv__SetAngles_Response__Sequence * array)
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
      mecharm_interfaces__srv__SetAngles_Response__fini(&array->data[i]);
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

mecharm_interfaces__srv__SetAngles_Response__Sequence *
mecharm_interfaces__srv__SetAngles_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Response__Sequence * array = (mecharm_interfaces__srv__SetAngles_Response__Sequence *)allocator.allocate(sizeof(mecharm_interfaces__srv__SetAngles_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mecharm_interfaces__srv__SetAngles_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mecharm_interfaces__srv__SetAngles_Response__Sequence__destroy(mecharm_interfaces__srv__SetAngles_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mecharm_interfaces__srv__SetAngles_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mecharm_interfaces__srv__SetAngles_Response__Sequence__are_equal(const mecharm_interfaces__srv__SetAngles_Response__Sequence * lhs, const mecharm_interfaces__srv__SetAngles_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mecharm_interfaces__srv__SetAngles_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mecharm_interfaces__srv__SetAngles_Response__Sequence__copy(
  const mecharm_interfaces__srv__SetAngles_Response__Sequence * input,
  mecharm_interfaces__srv__SetAngles_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mecharm_interfaces__srv__SetAngles_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mecharm_interfaces__srv__SetAngles_Response * data =
      (mecharm_interfaces__srv__SetAngles_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mecharm_interfaces__srv__SetAngles_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mecharm_interfaces__srv__SetAngles_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mecharm_interfaces__srv__SetAngles_Response__copy(
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
// #include "mecharm_interfaces/srv/detail/set_angles__functions.h"

bool
mecharm_interfaces__srv__SetAngles_Event__init(mecharm_interfaces__srv__SetAngles_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    mecharm_interfaces__srv__SetAngles_Event__fini(msg);
    return false;
  }
  // request
  if (!mecharm_interfaces__srv__SetAngles_Request__Sequence__init(&msg->request, 0)) {
    mecharm_interfaces__srv__SetAngles_Event__fini(msg);
    return false;
  }
  // response
  if (!mecharm_interfaces__srv__SetAngles_Response__Sequence__init(&msg->response, 0)) {
    mecharm_interfaces__srv__SetAngles_Event__fini(msg);
    return false;
  }
  return true;
}

void
mecharm_interfaces__srv__SetAngles_Event__fini(mecharm_interfaces__srv__SetAngles_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  mecharm_interfaces__srv__SetAngles_Request__Sequence__fini(&msg->request);
  // response
  mecharm_interfaces__srv__SetAngles_Response__Sequence__fini(&msg->response);
}

bool
mecharm_interfaces__srv__SetAngles_Event__are_equal(const mecharm_interfaces__srv__SetAngles_Event * lhs, const mecharm_interfaces__srv__SetAngles_Event * rhs)
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
  if (!mecharm_interfaces__srv__SetAngles_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!mecharm_interfaces__srv__SetAngles_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
mecharm_interfaces__srv__SetAngles_Event__copy(
  const mecharm_interfaces__srv__SetAngles_Event * input,
  mecharm_interfaces__srv__SetAngles_Event * output)
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
  if (!mecharm_interfaces__srv__SetAngles_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!mecharm_interfaces__srv__SetAngles_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

mecharm_interfaces__srv__SetAngles_Event *
mecharm_interfaces__srv__SetAngles_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Event * msg = (mecharm_interfaces__srv__SetAngles_Event *)allocator.allocate(sizeof(mecharm_interfaces__srv__SetAngles_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mecharm_interfaces__srv__SetAngles_Event));
  bool success = mecharm_interfaces__srv__SetAngles_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mecharm_interfaces__srv__SetAngles_Event__destroy(mecharm_interfaces__srv__SetAngles_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mecharm_interfaces__srv__SetAngles_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mecharm_interfaces__srv__SetAngles_Event__Sequence__init(mecharm_interfaces__srv__SetAngles_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Event * data = NULL;

  if (size) {
    data = (mecharm_interfaces__srv__SetAngles_Event *)allocator.zero_allocate(size, sizeof(mecharm_interfaces__srv__SetAngles_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mecharm_interfaces__srv__SetAngles_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mecharm_interfaces__srv__SetAngles_Event__fini(&data[i - 1]);
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
mecharm_interfaces__srv__SetAngles_Event__Sequence__fini(mecharm_interfaces__srv__SetAngles_Event__Sequence * array)
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
      mecharm_interfaces__srv__SetAngles_Event__fini(&array->data[i]);
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

mecharm_interfaces__srv__SetAngles_Event__Sequence *
mecharm_interfaces__srv__SetAngles_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mecharm_interfaces__srv__SetAngles_Event__Sequence * array = (mecharm_interfaces__srv__SetAngles_Event__Sequence *)allocator.allocate(sizeof(mecharm_interfaces__srv__SetAngles_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mecharm_interfaces__srv__SetAngles_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mecharm_interfaces__srv__SetAngles_Event__Sequence__destroy(mecharm_interfaces__srv__SetAngles_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mecharm_interfaces__srv__SetAngles_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mecharm_interfaces__srv__SetAngles_Event__Sequence__are_equal(const mecharm_interfaces__srv__SetAngles_Event__Sequence * lhs, const mecharm_interfaces__srv__SetAngles_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mecharm_interfaces__srv__SetAngles_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mecharm_interfaces__srv__SetAngles_Event__Sequence__copy(
  const mecharm_interfaces__srv__SetAngles_Event__Sequence * input,
  mecharm_interfaces__srv__SetAngles_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mecharm_interfaces__srv__SetAngles_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mecharm_interfaces__srv__SetAngles_Event * data =
      (mecharm_interfaces__srv__SetAngles_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mecharm_interfaces__srv__SetAngles_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mecharm_interfaces__srv__SetAngles_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mecharm_interfaces__srv__SetAngles_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
