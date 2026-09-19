// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from mecharm_interfaces:msg/MecharmSetCoords.idl
// generated code does not contain a copyright notice
#include "mecharm_interfaces/msg/detail/mecharm_set_coords__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "mecharm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "mecharm_interfaces/msg/detail/mecharm_set_coords__struct.h"
#include "mecharm_interfaces/msg/detail/mecharm_set_coords__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MecharmSetCoords__ros_msg_type = mecharm_interfaces__msg__MecharmSetCoords;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
bool cdr_serialize_mecharm_interfaces__msg__MecharmSetCoords(
  const mecharm_interfaces__msg__MecharmSetCoords * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: rx
  {
    cdr << ros_message->rx;
  }

  // Field name: ry
  {
    cdr << ros_message->ry;
  }

  // Field name: rz
  {
    cdr << ros_message->rz;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: model
  {
    cdr << ros_message->model;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
bool cdr_deserialize_mecharm_interfaces__msg__MecharmSetCoords(
  eprosima::fastcdr::Cdr & cdr,
  mecharm_interfaces__msg__MecharmSetCoords * ros_message)
{
  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: z
  {
    cdr >> ros_message->z;
  }

  // Field name: rx
  {
    cdr >> ros_message->rx;
  }

  // Field name: ry
  {
    cdr >> ros_message->ry;
  }

  // Field name: rz
  {
    cdr >> ros_message->rz;
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: model
  {
    cdr >> ros_message->model;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
size_t get_serialized_size_mecharm_interfaces__msg__MecharmSetCoords(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MecharmSetCoords__ros_msg_type * ros_message = static_cast<const _MecharmSetCoords__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rx
  {
    size_t item_size = sizeof(ros_message->rx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ry
  {
    size_t item_size = sizeof(ros_message->ry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rz
  {
    size_t item_size = sizeof(ros_message->rz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: model
  {
    size_t item_size = sizeof(ros_message->model);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
size_t max_serialized_size_mecharm_interfaces__msg__MecharmSetCoords(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rx
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: ry
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: model
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mecharm_interfaces__msg__MecharmSetCoords;
    is_plain =
      (
      offsetof(DataType, model) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
bool cdr_serialize_key_mecharm_interfaces__msg__MecharmSetCoords(
  const mecharm_interfaces__msg__MecharmSetCoords * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: z
  {
    cdr << ros_message->z;
  }

  // Field name: rx
  {
    cdr << ros_message->rx;
  }

  // Field name: ry
  {
    cdr << ros_message->ry;
  }

  // Field name: rz
  {
    cdr << ros_message->rz;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: model
  {
    cdr << ros_message->model;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
size_t get_serialized_size_key_mecharm_interfaces__msg__MecharmSetCoords(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MecharmSetCoords__ros_msg_type * ros_message = static_cast<const _MecharmSetCoords__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: z
  {
    size_t item_size = sizeof(ros_message->z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rx
  {
    size_t item_size = sizeof(ros_message->rx);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ry
  {
    size_t item_size = sizeof(ros_message->ry);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: rz
  {
    size_t item_size = sizeof(ros_message->rz);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: model
  {
    size_t item_size = sizeof(ros_message->model);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_mecharm_interfaces
size_t max_serialized_size_key_mecharm_interfaces__msg__MecharmSetCoords(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: z
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rx
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: ry
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: rz
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: speed
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: model
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = mecharm_interfaces__msg__MecharmSetCoords;
    is_plain =
      (
      offsetof(DataType, model) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _MecharmSetCoords__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const mecharm_interfaces__msg__MecharmSetCoords * ros_message = static_cast<const mecharm_interfaces__msg__MecharmSetCoords *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_mecharm_interfaces__msg__MecharmSetCoords(ros_message, cdr);
}

static bool _MecharmSetCoords__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  mecharm_interfaces__msg__MecharmSetCoords * ros_message = static_cast<mecharm_interfaces__msg__MecharmSetCoords *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_mecharm_interfaces__msg__MecharmSetCoords(cdr, ros_message);
}

static uint32_t _MecharmSetCoords__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_mecharm_interfaces__msg__MecharmSetCoords(
      untyped_ros_message, 0));
}

static size_t _MecharmSetCoords__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_mecharm_interfaces__msg__MecharmSetCoords(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MecharmSetCoords = {
  "mecharm_interfaces::msg",
  "MecharmSetCoords",
  _MecharmSetCoords__cdr_serialize,
  _MecharmSetCoords__cdr_deserialize,
  _MecharmSetCoords__get_serialized_size,
  _MecharmSetCoords__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _MecharmSetCoords__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MecharmSetCoords,
  get_message_typesupport_handle_function,
  &mecharm_interfaces__msg__MecharmSetCoords__get_type_hash,
  &mecharm_interfaces__msg__MecharmSetCoords__get_type_description,
  &mecharm_interfaces__msg__MecharmSetCoords__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mecharm_interfaces, msg, MecharmSetCoords)() {
  return &_MecharmSetCoords__type_support;
}

#if defined(__cplusplus)
}
#endif
