// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robokpy_interfaces:action/ExecuteMotion.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/action/detail/execute_motion__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `leg_step_ids`
// Member `leg_traj_methods`
// Member `leg_traj_types`
#include "rosidl_runtime_c/string_functions.h"
// Member `leg_target_poses`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `leg_blend_radii`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_Goal__init(robokpy_interfaces__action__ExecuteMotion_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // leg_step_ids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->leg_step_ids, 0)) {
    robokpy_interfaces__action__ExecuteMotion_Goal__fini(msg);
    return false;
  }
  // leg_target_poses
  if (!geometry_msgs__msg__Pose__Sequence__init(&msg->leg_target_poses, 0)) {
    robokpy_interfaces__action__ExecuteMotion_Goal__fini(msg);
    return false;
  }
  // leg_traj_methods
  if (!rosidl_runtime_c__String__Sequence__init(&msg->leg_traj_methods, 0)) {
    robokpy_interfaces__action__ExecuteMotion_Goal__fini(msg);
    return false;
  }
  // leg_traj_types
  if (!rosidl_runtime_c__String__Sequence__init(&msg->leg_traj_types, 0)) {
    robokpy_interfaces__action__ExecuteMotion_Goal__fini(msg);
    return false;
  }
  // leg_blend_radii
  if (!rosidl_runtime_c__double__Sequence__init(&msg->leg_blend_radii, 0)) {
    robokpy_interfaces__action__ExecuteMotion_Goal__fini(msg);
    return false;
  }
  // speed_scale
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_Goal__fini(robokpy_interfaces__action__ExecuteMotion_Goal * msg)
{
  if (!msg) {
    return;
  }
  // leg_step_ids
  rosidl_runtime_c__String__Sequence__fini(&msg->leg_step_ids);
  // leg_target_poses
  geometry_msgs__msg__Pose__Sequence__fini(&msg->leg_target_poses);
  // leg_traj_methods
  rosidl_runtime_c__String__Sequence__fini(&msg->leg_traj_methods);
  // leg_traj_types
  rosidl_runtime_c__String__Sequence__fini(&msg->leg_traj_types);
  // leg_blend_radii
  rosidl_runtime_c__double__Sequence__fini(&msg->leg_blend_radii);
  // speed_scale
}

bool
robokpy_interfaces__action__ExecuteMotion_Goal__are_equal(const robokpy_interfaces__action__ExecuteMotion_Goal * lhs, const robokpy_interfaces__action__ExecuteMotion_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // leg_step_ids
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->leg_step_ids), &(rhs->leg_step_ids)))
  {
    return false;
  }
  // leg_target_poses
  if (!geometry_msgs__msg__Pose__Sequence__are_equal(
      &(lhs->leg_target_poses), &(rhs->leg_target_poses)))
  {
    return false;
  }
  // leg_traj_methods
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->leg_traj_methods), &(rhs->leg_traj_methods)))
  {
    return false;
  }
  // leg_traj_types
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->leg_traj_types), &(rhs->leg_traj_types)))
  {
    return false;
  }
  // leg_blend_radii
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->leg_blend_radii), &(rhs->leg_blend_radii)))
  {
    return false;
  }
  // speed_scale
  if (lhs->speed_scale != rhs->speed_scale) {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_Goal__copy(
  const robokpy_interfaces__action__ExecuteMotion_Goal * input,
  robokpy_interfaces__action__ExecuteMotion_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // leg_step_ids
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->leg_step_ids), &(output->leg_step_ids)))
  {
    return false;
  }
  // leg_target_poses
  if (!geometry_msgs__msg__Pose__Sequence__copy(
      &(input->leg_target_poses), &(output->leg_target_poses)))
  {
    return false;
  }
  // leg_traj_methods
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->leg_traj_methods), &(output->leg_traj_methods)))
  {
    return false;
  }
  // leg_traj_types
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->leg_traj_types), &(output->leg_traj_types)))
  {
    return false;
  }
  // leg_blend_radii
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->leg_blend_radii), &(output->leg_blend_radii)))
  {
    return false;
  }
  // speed_scale
  output->speed_scale = input->speed_scale;
  return true;
}

robokpy_interfaces__action__ExecuteMotion_Goal *
robokpy_interfaces__action__ExecuteMotion_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Goal * msg = (robokpy_interfaces__action__ExecuteMotion_Goal *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_Goal));
  bool success = robokpy_interfaces__action__ExecuteMotion_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_Goal__destroy(robokpy_interfaces__action__ExecuteMotion_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__init(robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Goal * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_Goal *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_Goal__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_Goal__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_Goal__Sequence *
robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_Goal__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_Goal__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_Goal * data =
      (robokpy_interfaces__action__ExecuteMotion_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `final_state`
#include "sensor_msgs/msg/detail/joint_state__functions.h"
// Member `actual_duration`
#include "builtin_interfaces/msg/detail/duration__functions.h"
// Member `failed_leg_step_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_Result__init(robokpy_interfaces__action__ExecuteMotion_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_code
  // final_state
  if (!sensor_msgs__msg__JointState__init(&msg->final_state)) {
    robokpy_interfaces__action__ExecuteMotion_Result__fini(msg);
    return false;
  }
  // actual_duration
  if (!builtin_interfaces__msg__Duration__init(&msg->actual_duration)) {
    robokpy_interfaces__action__ExecuteMotion_Result__fini(msg);
    return false;
  }
  // failed_leg_step_id
  if (!rosidl_runtime_c__String__init(&msg->failed_leg_step_id)) {
    robokpy_interfaces__action__ExecuteMotion_Result__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_Result__fini(robokpy_interfaces__action__ExecuteMotion_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_code
  // final_state
  sensor_msgs__msg__JointState__fini(&msg->final_state);
  // actual_duration
  builtin_interfaces__msg__Duration__fini(&msg->actual_duration);
  // failed_leg_step_id
  rosidl_runtime_c__String__fini(&msg->failed_leg_step_id);
}

bool
robokpy_interfaces__action__ExecuteMotion_Result__are_equal(const robokpy_interfaces__action__ExecuteMotion_Result * lhs, const robokpy_interfaces__action__ExecuteMotion_Result * rhs)
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
  // final_state
  if (!sensor_msgs__msg__JointState__are_equal(
      &(lhs->final_state), &(rhs->final_state)))
  {
    return false;
  }
  // actual_duration
  if (!builtin_interfaces__msg__Duration__are_equal(
      &(lhs->actual_duration), &(rhs->actual_duration)))
  {
    return false;
  }
  // failed_leg_step_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->failed_leg_step_id), &(rhs->failed_leg_step_id)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_Result__copy(
  const robokpy_interfaces__action__ExecuteMotion_Result * input,
  robokpy_interfaces__action__ExecuteMotion_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_code
  output->error_code = input->error_code;
  // final_state
  if (!sensor_msgs__msg__JointState__copy(
      &(input->final_state), &(output->final_state)))
  {
    return false;
  }
  // actual_duration
  if (!builtin_interfaces__msg__Duration__copy(
      &(input->actual_duration), &(output->actual_duration)))
  {
    return false;
  }
  // failed_leg_step_id
  if (!rosidl_runtime_c__String__copy(
      &(input->failed_leg_step_id), &(output->failed_leg_step_id)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_Result *
robokpy_interfaces__action__ExecuteMotion_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Result * msg = (robokpy_interfaces__action__ExecuteMotion_Result *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_Result));
  bool success = robokpy_interfaces__action__ExecuteMotion_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_Result__destroy(robokpy_interfaces__action__ExecuteMotion_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_Result__Sequence__init(robokpy_interfaces__action__ExecuteMotion_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Result * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_Result *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_Result__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_Result__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_Result__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_Result__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_Result__Sequence *
robokpy_interfaces__action__ExecuteMotion_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Result__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_Result__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_Result__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_Result__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_Result__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_Result__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_Result__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_Result * data =
      (robokpy_interfaces__action__ExecuteMotion_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `current_leg_step_id`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `current_state`
// already included above
// #include "sensor_msgs/msg/detail/joint_state__functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_Feedback__init(robokpy_interfaces__action__ExecuteMotion_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // current_leg_step_id
  if (!rosidl_runtime_c__String__init(&msg->current_leg_step_id)) {
    robokpy_interfaces__action__ExecuteMotion_Feedback__fini(msg);
    return false;
  }
  // leg_percent_complete
  // current_state
  if (!sensor_msgs__msg__JointState__init(&msg->current_state)) {
    robokpy_interfaces__action__ExecuteMotion_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_Feedback__fini(robokpy_interfaces__action__ExecuteMotion_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // current_leg_step_id
  rosidl_runtime_c__String__fini(&msg->current_leg_step_id);
  // leg_percent_complete
  // current_state
  sensor_msgs__msg__JointState__fini(&msg->current_state);
}

bool
robokpy_interfaces__action__ExecuteMotion_Feedback__are_equal(const robokpy_interfaces__action__ExecuteMotion_Feedback * lhs, const robokpy_interfaces__action__ExecuteMotion_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_leg_step_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->current_leg_step_id), &(rhs->current_leg_step_id)))
  {
    return false;
  }
  // leg_percent_complete
  if (lhs->leg_percent_complete != rhs->leg_percent_complete) {
    return false;
  }
  // current_state
  if (!sensor_msgs__msg__JointState__are_equal(
      &(lhs->current_state), &(rhs->current_state)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_Feedback__copy(
  const robokpy_interfaces__action__ExecuteMotion_Feedback * input,
  robokpy_interfaces__action__ExecuteMotion_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // current_leg_step_id
  if (!rosidl_runtime_c__String__copy(
      &(input->current_leg_step_id), &(output->current_leg_step_id)))
  {
    return false;
  }
  // leg_percent_complete
  output->leg_percent_complete = input->leg_percent_complete;
  // current_state
  if (!sensor_msgs__msg__JointState__copy(
      &(input->current_state), &(output->current_state)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_Feedback *
robokpy_interfaces__action__ExecuteMotion_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Feedback * msg = (robokpy_interfaces__action__ExecuteMotion_Feedback *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_Feedback));
  bool success = robokpy_interfaces__action__ExecuteMotion_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_Feedback__destroy(robokpy_interfaces__action__ExecuteMotion_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__init(robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Feedback * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_Feedback *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_Feedback__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_Feedback__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence *
robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_Feedback * data =
      (robokpy_interfaces__action__ExecuteMotion_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_Feedback__copy(
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
// #include "robokpy_interfaces/action/detail/execute_motion__functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__init(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!robokpy_interfaces__action__ExecuteMotion_Goal__init(&msg->goal)) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  robokpy_interfaces__action__ExecuteMotion_Goal__fini(&msg->goal);
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__are_equal(const robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * lhs, const robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * rhs)
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
  if (!robokpy_interfaces__action__ExecuteMotion_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__copy(
  const robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * input,
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * output)
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
  if (!robokpy_interfaces__action__ExecuteMotion_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_SendGoal_Request *
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * msg = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Request *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request));
  bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__destroy(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence *
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Request * data =
      (robokpy_interfaces__action__ExecuteMotion_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__copy(
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
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__init(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__fini(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__are_equal(const robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * lhs, const robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * rhs)
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
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__copy(
  const robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * input,
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * output)
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

robokpy_interfaces__action__ExecuteMotion_SendGoal_Response *
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * msg = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Response *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response));
  bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__destroy(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence *
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Response * data =
      (robokpy_interfaces__action__ExecuteMotion_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__copy(
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
// #include "robokpy_interfaces/action/detail/execute_motion__functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__init(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__are_equal(const robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * lhs, const robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * rhs)
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
  if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__copy(
  const robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * input,
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * output)
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
  if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_SendGoal_Event *
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * msg = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Event *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event));
  bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__destroy(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__init(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence *
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_SendGoal_Event * data =
      (robokpy_interfaces__action__ExecuteMotion_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_SendGoal_Event__copy(
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
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__init(robokpy_interfaces__action__ExecuteMotion_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__fini(robokpy_interfaces__action__ExecuteMotion_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__are_equal(const robokpy_interfaces__action__ExecuteMotion_GetResult_Request * lhs, const robokpy_interfaces__action__ExecuteMotion_GetResult_Request * rhs)
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
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__copy(
  const robokpy_interfaces__action__ExecuteMotion_GetResult_Request * input,
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request * output)
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

robokpy_interfaces__action__ExecuteMotion_GetResult_Request *
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request * msg = (robokpy_interfaces__action__ExecuteMotion_GetResult_Request *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Request));
  bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__destroy(robokpy_interfaces__action__ExecuteMotion_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_GetResult_Request *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_GetResult_Request__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_GetResult_Request__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence *
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_GetResult_Request * data =
      (robokpy_interfaces__action__ExecuteMotion_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Request__copy(
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
// #include "robokpy_interfaces/action/detail/execute_motion__functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__init(robokpy_interfaces__action__ExecuteMotion_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!robokpy_interfaces__action__ExecuteMotion_Result__init(&msg->result)) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__fini(robokpy_interfaces__action__ExecuteMotion_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  robokpy_interfaces__action__ExecuteMotion_Result__fini(&msg->result);
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__are_equal(const robokpy_interfaces__action__ExecuteMotion_GetResult_Response * lhs, const robokpy_interfaces__action__ExecuteMotion_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!robokpy_interfaces__action__ExecuteMotion_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__copy(
  const robokpy_interfaces__action__ExecuteMotion_GetResult_Response * input,
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!robokpy_interfaces__action__ExecuteMotion_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_GetResult_Response *
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response * msg = (robokpy_interfaces__action__ExecuteMotion_GetResult_Response *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Response));
  bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__destroy(robokpy_interfaces__action__ExecuteMotion_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_GetResult_Response *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_GetResult_Response__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_GetResult_Response__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence *
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_GetResult_Response * data =
      (robokpy_interfaces__action__ExecuteMotion_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Response__copy(
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
// #include "robokpy_interfaces/action/detail/execute_motion__functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__init(robokpy_interfaces__action__ExecuteMotion_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__init(&msg->request, 0)) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__init(&msg->response, 0)) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(robokpy_interfaces__action__ExecuteMotion_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__fini(&msg->request);
  // response
  robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__fini(&msg->response);
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__are_equal(const robokpy_interfaces__action__ExecuteMotion_GetResult_Event * lhs, const robokpy_interfaces__action__ExecuteMotion_GetResult_Event * rhs)
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
  if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__copy(
  const robokpy_interfaces__action__ExecuteMotion_GetResult_Event * input,
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event * output)
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
  if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_GetResult_Event *
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event * msg = (robokpy_interfaces__action__ExecuteMotion_GetResult_Event *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Event));
  bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__destroy(robokpy_interfaces__action__ExecuteMotion_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__init(robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_GetResult_Event *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence *
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_GetResult_Event * data =
      (robokpy_interfaces__action__ExecuteMotion_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_GetResult_Event__copy(
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
// #include "robokpy_interfaces/action/detail/execute_motion__functions.h"

bool
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__init(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!robokpy_interfaces__action__ExecuteMotion_Feedback__init(&msg->feedback)) {
    robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  robokpy_interfaces__action__ExecuteMotion_Feedback__fini(&msg->feedback);
}

bool
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__are_equal(const robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * lhs, const robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * rhs)
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
  if (!robokpy_interfaces__action__ExecuteMotion_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__copy(
  const robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * input,
  robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * output)
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
  if (!robokpy_interfaces__action__ExecuteMotion_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

robokpy_interfaces__action__ExecuteMotion_FeedbackMessage *
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * msg = (robokpy_interfaces__action__ExecuteMotion_FeedbackMessage *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage));
  bool success = robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__destroy(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__init(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * data = NULL;

  if (size) {
    data = (robokpy_interfaces__action__ExecuteMotion_FeedbackMessage *)allocator.zero_allocate(size, sizeof(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(&data[i - 1]);
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
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__fini(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array)
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
      robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(&array->data[i]);
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

robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence *
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array = (robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence *)allocator.allocate(sizeof(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__destroy(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__are_equal(const robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * lhs, const robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence__copy(
  const robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * input,
  robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robokpy_interfaces__action__ExecuteMotion_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robokpy_interfaces__action__ExecuteMotion_FeedbackMessage * data =
      (robokpy_interfaces__action__ExecuteMotion_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robokpy_interfaces__action__ExecuteMotion_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
