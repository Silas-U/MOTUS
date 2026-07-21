// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice
#ifndef ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "robokpy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robokpy_interfaces/msg/detail/cell_state__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
bool cdr_serialize_robokpy_interfaces__msg__CellState(
  const robokpy_interfaces__msg__CellState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
bool cdr_deserialize_robokpy_interfaces__msg__CellState(
  eprosima::fastcdr::Cdr &,
  robokpy_interfaces__msg__CellState * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t get_serialized_size_robokpy_interfaces__msg__CellState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t max_serialized_size_robokpy_interfaces__msg__CellState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
bool cdr_serialize_key_robokpy_interfaces__msg__CellState(
  const robokpy_interfaces__msg__CellState * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t get_serialized_size_key_robokpy_interfaces__msg__CellState(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t max_serialized_size_key_robokpy_interfaces__msg__CellState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, msg, CellState)();

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
