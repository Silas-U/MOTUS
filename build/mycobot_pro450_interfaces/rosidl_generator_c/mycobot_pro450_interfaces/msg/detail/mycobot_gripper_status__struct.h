// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mycobot_pro450_interfaces:msg/MycobotGripperStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mycobot_pro450_interfaces/msg/mycobot_gripper_status.h"


#ifndef MYCOBOT_PRO450_INTERFACES__MSG__DETAIL__MYCOBOT_GRIPPER_STATUS__STRUCT_H_
#define MYCOBOT_PRO450_INTERFACES__MSG__DETAIL__MYCOBOT_GRIPPER_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/MycobotGripperStatus in the package mycobot_pro450_interfaces.
typedef struct mycobot_pro450_interfaces__msg__MycobotGripperStatus
{
  bool status;
} mycobot_pro450_interfaces__msg__MycobotGripperStatus;

// Struct for a sequence of mycobot_pro450_interfaces__msg__MycobotGripperStatus.
typedef struct mycobot_pro450_interfaces__msg__MycobotGripperStatus__Sequence
{
  mycobot_pro450_interfaces__msg__MycobotGripperStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mycobot_pro450_interfaces__msg__MycobotGripperStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MYCOBOT_PRO450_INTERFACES__MSG__DETAIL__MYCOBOT_GRIPPER_STATUS__STRUCT_H_
