// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/msg/detail/cell_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "robokpy_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "robokpy_interfaces/msg/detail/cell_state__struct.h"
#include "robokpy_interfaces/msg/detail/cell_state__functions.h"
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

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp
#include "rosidl_runtime_c/string.h"  // active_recipe_id, last_error
#include "rosidl_runtime_c/string_functions.h"  // active_recipe_id, last_error

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
bool cdr_serialize_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
bool cdr_deserialize_builtin_interfaces__msg__Time(
  eprosima::fastcdr::Cdr & cdr,
  builtin_interfaces__msg__Time * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
bool cdr_serialize_key_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
size_t get_serialized_size_key_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
size_t max_serialized_size_key_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_robokpy_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();


using _CellState__ros_msg_type = robokpy_interfaces__msg__CellState;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
bool cdr_serialize_robokpy_interfaces__msg__CellState(
  const robokpy_interfaces__msg__CellState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: active_recipe_id
  {
    const rosidl_runtime_c__String * str = &ros_message->active_recipe_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: last_error
  {
    const rosidl_runtime_c__String * str = &ros_message->last_error;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: stamp
  {
    cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->stamp, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
bool cdr_deserialize_robokpy_interfaces__msg__CellState(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces__msg__CellState * ros_message)
{
  // Field name: state
  {
    cdr >> ros_message->state;
  }

  // Field name: active_recipe_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->active_recipe_id.data) {
      rosidl_runtime_c__String__init(&ros_message->active_recipe_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->active_recipe_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'active_recipe_id'\n");
      return false;
    }
  }

  // Field name: last_error
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->last_error.data) {
      rosidl_runtime_c__String__init(&ros_message->last_error);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->last_error,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'last_error'\n");
      return false;
    }
  }

  // Field name: stamp
  {
    cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->stamp);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t get_serialized_size_robokpy_interfaces__msg__CellState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CellState__ros_msg_type * ros_message = static_cast<const _CellState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: active_recipe_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->active_recipe_id.size + 1);

  // Field name: last_error
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->last_error.size + 1);

  // Field name: stamp
  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t max_serialized_size_robokpy_interfaces__msg__CellState(
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

  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: active_recipe_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: last_error
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: stamp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces__msg__CellState;
    is_plain =
      (
      offsetof(DataType, stamp) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
bool cdr_serialize_key_robokpy_interfaces__msg__CellState(
  const robokpy_interfaces__msg__CellState * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: state
  {
    cdr << ros_message->state;
  }

  // Field name: active_recipe_id
  {
    const rosidl_runtime_c__String * str = &ros_message->active_recipe_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: last_error
  {
    const rosidl_runtime_c__String * str = &ros_message->last_error;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: stamp
  {
    cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->stamp, cdr);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t get_serialized_size_key_robokpy_interfaces__msg__CellState(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CellState__ros_msg_type * ros_message = static_cast<const _CellState__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: state
  {
    size_t item_size = sizeof(ros_message->state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: active_recipe_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->active_recipe_id.size + 1);

  // Field name: last_error
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->last_error.size + 1);

  // Field name: stamp
  current_alignment += get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_robokpy_interfaces
size_t max_serialized_size_key_robokpy_interfaces__msg__CellState(
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
  // Field name: state
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: active_recipe_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: last_error
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: stamp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces__msg__CellState;
    is_plain =
      (
      offsetof(DataType, stamp) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CellState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const robokpy_interfaces__msg__CellState * ros_message = static_cast<const robokpy_interfaces__msg__CellState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_robokpy_interfaces__msg__CellState(ros_message, cdr);
}

static bool _CellState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  robokpy_interfaces__msg__CellState * ros_message = static_cast<robokpy_interfaces__msg__CellState *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_robokpy_interfaces__msg__CellState(cdr, ros_message);
}

static uint32_t _CellState__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_robokpy_interfaces__msg__CellState(
      untyped_ros_message, 0));
}

static size_t _CellState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_robokpy_interfaces__msg__CellState(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CellState = {
  "robokpy_interfaces::msg",
  "CellState",
  _CellState__cdr_serialize,
  _CellState__cdr_deserialize,
  _CellState__get_serialized_size,
  _CellState__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CellState__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CellState,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__msg__CellState__get_type_hash,
  &robokpy_interfaces__msg__CellState__get_type_description,
  &robokpy_interfaces__msg__CellState__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, robokpy_interfaces, msg, CellState)() {
  return &_CellState__type_support;
}

#if defined(__cplusplus)
}
#endif
