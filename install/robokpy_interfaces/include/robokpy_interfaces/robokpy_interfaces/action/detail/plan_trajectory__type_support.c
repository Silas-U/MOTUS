// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robokpy_interfaces:action/PlanTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
#include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
#include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `leg_step_ids`
// Member `leg_traj_methods`
// Member `leg_traj_types`
#include "rosidl_runtime_c/string_functions.h"
// Member `leg_target_poses`
#include "geometry_msgs/msg/pose.h"
// Member `leg_target_poses`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `leg_blend_radii`
// Member `seed_state`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_Goal__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_Goal__fini(message_memory);
}

size_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_step_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_step_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_step_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_step_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_step_ids(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_step_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_step_ids(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_step_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_target_poses(
  const void * untyped_member)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_target_poses(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Pose__Sequence * member =
    (const geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_target_poses(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_target_poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Pose * item =
    ((const geometry_msgs__msg__Pose *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_target_poses(untyped_member, index));
  geometry_msgs__msg__Pose * value =
    (geometry_msgs__msg__Pose *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_target_poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Pose * item =
    ((geometry_msgs__msg__Pose *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_target_poses(untyped_member, index));
  const geometry_msgs__msg__Pose * value =
    (const geometry_msgs__msg__Pose *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_target_poses(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Pose__Sequence * member =
    (geometry_msgs__msg__Pose__Sequence *)(untyped_member);
  geometry_msgs__msg__Pose__Sequence__fini(member);
  return geometry_msgs__msg__Pose__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_traj_methods(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_traj_methods(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_traj_methods(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_traj_methods(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_traj_methods(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_traj_methods(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_traj_methods(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_traj_methods(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_traj_types(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_traj_types(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_traj_types(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_traj_types(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_traj_types(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_traj_types(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_traj_types(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_traj_types(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_blend_radii(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_blend_radii(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_blend_radii(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_blend_radii(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_blend_radii(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_blend_radii(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_blend_radii(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_blend_radii(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__seed_state(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__seed_state(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__seed_state(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__seed_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__seed_state(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__seed_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__seed_state(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__seed_state(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_member_array[7] = {
  {
    "leg_step_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, leg_step_ids),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_step_ids,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_step_ids,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_step_ids,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_step_ids,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_step_ids,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_step_ids  // resize(index) function pointer
  },
  {
    "leg_target_poses",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, leg_target_poses),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_target_poses,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_target_poses,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_target_poses,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_target_poses,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_target_poses,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_target_poses  // resize(index) function pointer
  },
  {
    "leg_traj_methods",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, leg_traj_methods),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_traj_methods,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_traj_methods,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_traj_methods,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_traj_methods,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_traj_methods,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_traj_methods  // resize(index) function pointer
  },
  {
    "leg_traj_types",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, leg_traj_types),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_traj_types,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_traj_types,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_traj_types,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_traj_types,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_traj_types,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_traj_types  // resize(index) function pointer
  },
  {
    "leg_blend_radii",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, leg_blend_radii),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__leg_blend_radii,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__leg_blend_radii,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__leg_blend_radii,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__leg_blend_radii,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__leg_blend_radii,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__leg_blend_radii  // resize(index) function pointer
  },
  {
    "seed_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, seed_state),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Goal__seed_state,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Goal__seed_state,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Goal__seed_state,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Goal__seed_state,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Goal__seed_state,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Goal__seed_state  // resize(index) function pointer
  },
  {
    "speed_scale",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Goal, speed_scale),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_Goal",  // message name
  7,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_Goal),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_Goal__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_Goal__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_Goal__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Goal)() {
  robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_Goal__rosidl_typesupport_introspection_c__PlanTrajectory_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `trajectory`
#include "trajectory_msgs/msg/joint_trajectory.h"
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__rosidl_typesupport_introspection_c.h"
// Member `predicted_final_state`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_Result__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_Result__fini(message_memory);
}

size_t robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Result__predicted_final_state(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Result__predicted_final_state(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Result__predicted_final_state(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Result__predicted_final_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Result__predicted_final_state(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Result__predicted_final_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Result__predicted_final_state(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Result__predicted_final_state(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_member_array[5] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Result, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Result, trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "predicted_final_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Result, predicted_final_state),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_Result__predicted_final_state,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_Result__predicted_final_state,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_Result__predicted_final_state,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_Result__predicted_final_state,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_Result__predicted_final_state,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_Result__predicted_final_state  // resize(index) function pointer
  },
  {
    "total_duration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Result, total_duration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_Result",  // message name
  5,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_Result),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_Result__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_Result__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_Result__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Result)() {
  robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trajectory_msgs, msg, JointTrajectory)();
  if (!robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_Result__rosidl_typesupport_introspection_c__PlanTrajectory_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_Feedback__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_Feedback, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_Feedback",  // message name
  1,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_Feedback),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_Feedback__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Feedback)() {
  if (!robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_Feedback__rosidl_typesupport_introspection_c__PlanTrajectory_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "robokpy_interfaces/action/plan_trajectory.h"
// Member `goal`
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Request),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)() {
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Goal)();
  if (!robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Response),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)() {
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/action/plan_trajectory.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__fini(message_memory);
}

size_t robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_SendGoal_Event__request(
  const void * untyped_member)
{
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_SendGoal_Event__request(
  const void * untyped_member, size_t index)
{
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_SendGoal_Event__request(
  void * untyped_member, size_t index)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request * item =
    ((const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request *)
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_SendGoal_Event__request(untyped_member, index));
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request * value =
    (robokpy_interfaces__action__PlanTrajectory_SendGoal_Request *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request * item =
    ((robokpy_interfaces__action__PlanTrajectory_SendGoal_Request *)
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_SendGoal_Event__request(untyped_member, index));
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request * value =
    (const robokpy_interfaces__action__PlanTrajectory_SendGoal_Request *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_SendGoal_Event__request(
  void * untyped_member, size_t size)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence *)(untyped_member);
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence__fini(member);
  return robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_SendGoal_Event__response(
  const void * untyped_member)
{
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_SendGoal_Event__response(
  const void * untyped_member, size_t index)
{
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_SendGoal_Event__response(
  void * untyped_member, size_t index)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response * item =
    ((const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response *)
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_SendGoal_Event__response(untyped_member, index));
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response * value =
    (robokpy_interfaces__action__PlanTrajectory_SendGoal_Response *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response * item =
    ((robokpy_interfaces__action__PlanTrajectory_SendGoal_Response *)
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_SendGoal_Event__response(untyped_member, index));
  const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response * value =
    (const robokpy_interfaces__action__PlanTrajectory_SendGoal_Response *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_SendGoal_Event__response(
  void * untyped_member, size_t size)
{
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence *)(untyped_member);
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence__fini(member);
  return robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Event, request),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_SendGoal_Event__request,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_SendGoal_Event__request,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_SendGoal_Event__request,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_SendGoal_Event__request,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_SendGoal_Event__request,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_SendGoal_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Event, response),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_SendGoal_Event__response,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_SendGoal_Event__response,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_SendGoal_Event__response,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_SendGoal_Event__response,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_SendGoal_Event__response,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_SendGoal_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_SendGoal_Event),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Event)() {
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)();
  robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)();
  if (!robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_members = {
  "robokpy_interfaces__action",  // service namespace
  "PlanTrajectory_SendGoal",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_type_support_handle,
  NULL,  // response message
  // robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle
  NULL  // event_message
  // robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle
};


static rosidl_service_type_support_t robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_type_support_handle = {
  0,
  &robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_members,
  get_service_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Request__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Request_message_type_support_handle,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Response__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Response_message_type_support_handle,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal_Event__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_SendGoal
  ),
  &robokpy_interfaces__action__PlanTrajectory_SendGoal__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_SendGoal__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal)(void) {
  if (!robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_SendGoal_Event)()->data;
  }

  return &robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_GetResult_Request),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)() {
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "robokpy_interfaces/action/plan_trajectory.h"
// Member `result`
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_GetResult_Response),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)() {
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Result)();
  if (!robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/service_event_info.h"
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/action/plan_trajectory.h"
// Member `request`
// Member `response`
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__fini(message_memory);
}

size_t robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_GetResult_Event__request(
  const void * untyped_member)
{
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_GetResult_Event__request(
  const void * untyped_member, size_t index)
{
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_GetResult_Event__request(
  void * untyped_member, size_t index)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Request * item =
    ((const robokpy_interfaces__action__PlanTrajectory_GetResult_Request *)
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_GetResult_Event__request(untyped_member, index));
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request * value =
    (robokpy_interfaces__action__PlanTrajectory_GetResult_Request *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request * item =
    ((robokpy_interfaces__action__PlanTrajectory_GetResult_Request *)
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_GetResult_Event__request(untyped_member, index));
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Request * value =
    (const robokpy_interfaces__action__PlanTrajectory_GetResult_Request *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_GetResult_Event__request(
  void * untyped_member, size_t size)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence *)(untyped_member);
  robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence__fini(member);
  return robokpy_interfaces__action__PlanTrajectory_GetResult_Request__Sequence__init(member, size);
}

size_t robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_GetResult_Event__response(
  const void * untyped_member)
{
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_GetResult_Event__response(
  const void * untyped_member, size_t index)
{
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence * member =
    (const robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_GetResult_Event__response(
  void * untyped_member, size_t index)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Response * item =
    ((const robokpy_interfaces__action__PlanTrajectory_GetResult_Response *)
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_GetResult_Event__response(untyped_member, index));
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response * value =
    (robokpy_interfaces__action__PlanTrajectory_GetResult_Response *)(untyped_value);
  *value = *item;
}

void robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response * item =
    ((robokpy_interfaces__action__PlanTrajectory_GetResult_Response *)
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_GetResult_Event__response(untyped_member, index));
  const robokpy_interfaces__action__PlanTrajectory_GetResult_Response * value =
    (const robokpy_interfaces__action__PlanTrajectory_GetResult_Response *)(untyped_value);
  *item = *value;
}

bool robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_GetResult_Event__response(
  void * untyped_member, size_t size)
{
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence * member =
    (robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence *)(untyped_member);
  robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence__fini(member);
  return robokpy_interfaces__action__PlanTrajectory_GetResult_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_GetResult_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_GetResult_Event, request),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_GetResult_Event__request,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_GetResult_Event__request,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_GetResult_Event__request,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_GetResult_Event__request,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_GetResult_Event__request,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_GetResult_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_GetResult_Event, response),  // bytes offset in struct
    NULL,  // default value
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__size_function__PlanTrajectory_GetResult_Event__response,  // size() function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_const_function__PlanTrajectory_GetResult_Event__response,  // get_const(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__get_function__PlanTrajectory_GetResult_Event__response,  // get(index) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__fetch_function__PlanTrajectory_GetResult_Event__response,  // fetch(index, &value) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__assign_function__PlanTrajectory_GetResult_Event__response,  // assign(index, value) function pointer
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__resize_function__PlanTrajectory_GetResult_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_GetResult_Event),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Event)() {
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)();
  robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)();
  if (!robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_members = {
  "robokpy_interfaces__action",  // service namespace
  "PlanTrajectory_GetResult",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_type_support_handle,
  NULL,  // response message
  // robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle
  NULL  // event_message
  // robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle
};


static rosidl_service_type_support_t robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_type_support_handle = {
  0,
  &robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_members,
  get_service_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Request__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Request_message_type_support_handle,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Response__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Response_message_type_support_handle,
  &robokpy_interfaces__action__PlanTrajectory_GetResult_Event__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    robokpy_interfaces,
    action,
    PlanTrajectory_GetResult
  ),
  &robokpy_interfaces__action__PlanTrajectory_GetResult__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_GetResult__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_GetResult__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult)(void) {
  if (!robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_GetResult_Event)()->data;
  }

  return &robokpy_interfaces__action__detail__plan_trajectory__rosidl_typesupport_introspection_c__PlanTrajectory_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"
// already included above
// #include "robokpy_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "robokpy_interfaces/action/plan_trajectory.h"
// Member `feedback`
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__init(message_memory);
}

void robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_fini_function(void * message_memory)
{
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces__action__PlanTrajectory_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_members = {
  "robokpy_interfaces__action",  // message namespace
  "PlanTrajectory_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces__action__PlanTrajectory_FeedbackMessage),
  false,  // has_any_key_member_
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_member_array,  // message members
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_type_support_handle = {
  0,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_FeedbackMessage)() {
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robokpy_interfaces, action, PlanTrajectory_Feedback)();
  if (!robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robokpy_interfaces__action__PlanTrajectory_FeedbackMessage__rosidl_typesupport_introspection_c__PlanTrajectory_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
