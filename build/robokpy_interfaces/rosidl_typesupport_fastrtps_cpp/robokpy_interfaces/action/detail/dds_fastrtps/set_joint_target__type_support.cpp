// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:action/SetJointTarget.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/action/detail/set_joint_target__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robokpy_interfaces/action/detail/set_joint_target__functions.h"
#include "robokpy_interfaces/action/detail/set_joint_target__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_Goal & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: target_joints
  {
    cdr << ros_message.target_joints;
  }

  // Member: speed_scale
  cdr << ros_message.speed_scale;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_Goal & ros_message)
{
  // Member: target_joints
  {
    cdr >> ros_message.target_joints;
  }

  // Member: speed_scale
  cdr >> ros_message.speed_scale;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_Goal & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: target_joints
  {
    size_t array_size = ros_message.target_joints.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.target_joints[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_scale
  {
    size_t item_size = sizeof(ros_message.speed_scale);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_Goal(
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

  // Member: target_joints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: speed_scale
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces::action::SetJointTarget_Goal;
    is_plain =
      (
      offsetof(DataType, speed_scale) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_Goal & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: target_joints
  {
    cdr << ros_message.target_joints;
  }

  // Member: speed_scale
  cdr << ros_message.speed_scale;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_Goal & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: target_joints
  {
    size_t array_size = ros_message.target_joints.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.target_joints[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: speed_scale
  {
    size_t item_size = sizeof(ros_message.speed_scale);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_Goal(
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

  // Member: target_joints
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: speed_scale
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces::action::SetJointTarget_Goal;
    is_plain =
      (
      offsetof(DataType, speed_scale) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_Goal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_Goal *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_Goal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_Goal *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_Goal__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_Goal *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_Goal__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_Goal(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_Goal__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_Goal",
  _SetJointTarget_Goal__cdr_serialize,
  _SetJointTarget_Goal__cdr_deserialize,
  _SetJointTarget_Goal__get_serialized_size,
  _SetJointTarget_Goal__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_Goal__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_Goal__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_Goal__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_Goal__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_Goal__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_Goal>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_Goal__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_Goal)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_Goal__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace sensor_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const sensor_msgs::msg::JointState &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  sensor_msgs::msg::JointState &);
size_t get_serialized_size(
  const sensor_msgs::msg::JointState &,
  size_t current_alignment);
size_t
max_serialized_size_JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const sensor_msgs::msg::JointState &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const sensor_msgs::msg::JointState &,
  size_t current_alignment);
size_t
max_serialized_size_key_JointState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace sensor_msgs


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_Result & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);

  // Member: error_code
  cdr << ros_message.error_code;

  // Member: final_state
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.final_state,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_Result & ros_message)
{
  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  // Member: error_code
  cdr >> ros_message.error_code;

  // Member: final_state
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.final_state);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_Result & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: error_code
  {
    size_t item_size = sizeof(ros_message.error_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: final_state
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.final_state, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_Result(
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

  // Member: success
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: error_code
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: final_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_JointState(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_Result;
    is_plain =
      (
      offsetof(DataType, final_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_Result & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);

  // Member: error_code
  cdr << ros_message.error_code;

  // Member: final_state
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.final_state,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_Result & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: success
  {
    size_t item_size = sizeof(ros_message.success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: error_code
  {
    size_t item_size = sizeof(ros_message.error_code);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: final_state
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.final_state, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_Result(
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

  // Member: success
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: error_code
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: final_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_JointState(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_Result;
    is_plain =
      (
      offsetof(DataType, final_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_Result__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_Result *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_Result__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_Result *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_Result__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_Result *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_Result__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_Result(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_Result__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_Result",
  _SetJointTarget_Result__cdr_serialize,
  _SetJointTarget_Result__cdr_deserialize,
  _SetJointTarget_Result__get_serialized_size,
  _SetJointTarget_Result__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_Result__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_Result__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_Result__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_Result__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_Result__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_Result>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_Result__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_Result)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_Result__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
// functions for sensor_msgs::msg::JointState already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_Feedback & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: percent_complete
  cdr << ros_message.percent_complete;

  // Member: current_state
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.current_state,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_Feedback & ros_message)
{
  // Member: percent_complete
  cdr >> ros_message.percent_complete;

  // Member: current_state
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.current_state);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_Feedback & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: percent_complete
  {
    size_t item_size = sizeof(ros_message.percent_complete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: current_state
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.current_state, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_Feedback(
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

  // Member: percent_complete
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: current_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_JointState(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_Feedback;
    is_plain =
      (
      offsetof(DataType, current_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_Feedback & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: percent_complete
  cdr << ros_message.percent_complete;

  // Member: current_state
  sensor_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.current_state,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_Feedback & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: percent_complete
  {
    size_t item_size = sizeof(ros_message.percent_complete);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: current_state
  current_alignment +=
    sensor_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.current_state, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_Feedback(
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

  // Member: percent_complete
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current_state
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        sensor_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_JointState(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_Feedback;
    is_plain =
      (
      offsetof(DataType, current_state) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_Feedback__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_Feedback *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_Feedback__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_Feedback *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_Feedback__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_Feedback *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_Feedback__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_Feedback(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_Feedback__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_Feedback",
  _SetJointTarget_Feedback__cdr_serialize,
  _SetJointTarget_Feedback__cdr_deserialize,
  _SetJointTarget_Feedback__get_serialized_size,
  _SetJointTarget_Feedback__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_Feedback__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_Feedback__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_Feedback__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_Feedback__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_Feedback__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_Feedback>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_Feedback__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_Feedback)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_Feedback__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace unique_identifier_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const unique_identifier_msgs::msg::UUID &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  unique_identifier_msgs::msg::UUID &);
size_t get_serialized_size(
  const unique_identifier_msgs::msg::UUID &,
  size_t current_alignment);
size_t
max_serialized_size_UUID(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const unique_identifier_msgs::msg::UUID &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const unique_identifier_msgs::msg::UUID &,
  size_t current_alignment);
size_t
max_serialized_size_key_UUID(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace unique_identifier_msgs

// functions for robokpy_interfaces::action::SetJointTarget_Goal already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.goal_id,
    cdr);

  // Member: goal
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.goal,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_SendGoal_Request & ros_message)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.goal_id);

  // Member: goal
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.goal);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_id
  current_alignment +=
    unique_identifier_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.goal_id, current_alignment);

  // Member: goal
  current_alignment +=
    robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.goal, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_SendGoal_Request(
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

  // Member: goal_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        unique_identifier_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: goal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_Goal(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_SendGoal_Request;
    is_plain =
      (
      offsetof(DataType, goal) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.goal_id,
    cdr);

  // Member: goal
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.goal,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_id
  current_alignment +=
    unique_identifier_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.goal_id, current_alignment);

  // Member: goal
  current_alignment +=
    robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.goal, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_SendGoal_Request(
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

  // Member: goal_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        unique_identifier_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: goal
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_Goal(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_SendGoal_Request;
    is_plain =
      (
      offsetof(DataType, goal) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_SendGoal_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_SendGoal_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_SendGoal_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_SendGoal_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_SendGoal_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_SendGoal_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_SendGoal_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_SendGoal_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_SendGoal_Request__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_SendGoal_Request",
  _SetJointTarget_SendGoal_Request__cdr_serialize,
  _SetJointTarget_SendGoal_Request__cdr_deserialize,
  _SetJointTarget_SendGoal_Request__get_serialized_size,
  _SetJointTarget_SendGoal_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_SendGoal_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_SendGoal_Request__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal_Request>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_SendGoal_Request)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  builtin_interfaces::msg::Time &);
size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_key_Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: accepted
  cdr << (ros_message.accepted ? true : false);

  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.stamp,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_SendGoal_Response & ros_message)
{
  // Member: accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.accepted = tmp ? true : false;
  }

  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.stamp);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: accepted
  {
    size_t item_size = sizeof(ros_message.accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: stamp
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.stamp, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_SendGoal_Response(
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

  // Member: accepted
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: stamp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_SendGoal_Response;
    is_plain =
      (
      offsetof(DataType, stamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: accepted
  cdr << (ros_message.accepted ? true : false);

  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.stamp,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: accepted
  {
    size_t item_size = sizeof(ros_message.accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: stamp
  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.stamp, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_SendGoal_Response(
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

  // Member: accepted
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: stamp
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Time(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_SendGoal_Response;
    is_plain =
      (
      offsetof(DataType, stamp) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_SendGoal_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_SendGoal_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_SendGoal_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_SendGoal_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_SendGoal_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_SendGoal_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_SendGoal_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_SendGoal_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_SendGoal_Response__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_SendGoal_Response",
  _SetJointTarget_SendGoal_Response__cdr_serialize,
  _SetJointTarget_SendGoal_Response__cdr_deserialize,
  _SetJointTarget_SendGoal_Response__get_serialized_size,
  _SetJointTarget_SendGoal_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_SendGoal_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_SendGoal_Response__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal_Response>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_SendGoal_Response)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal_Response__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace service_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const service_msgs::msg::ServiceEventInfo &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  service_msgs::msg::ServiceEventInfo &);
size_t get_serialized_size(
  const service_msgs::msg::ServiceEventInfo &,
  size_t current_alignment);
size_t
max_serialized_size_ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const service_msgs::msg::ServiceEventInfo &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const service_msgs::msg::ServiceEventInfo &,
  size_t current_alignment);
size_t
max_serialized_size_key_ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace service_msgs

// functions for robokpy_interfaces::action::SetJointTarget_SendGoal_Request already declared above

// functions for robokpy_interfaces::action::SetJointTarget_SendGoal_Response already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: info
  service_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.info,
    cdr);

  // Member: request
  {
    size_t size = ros_message.request.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.request[i],
        cdr);
    }
  }

  // Member: response
  {
    size_t size = ros_message.response.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.response[i],
        cdr);
    }
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_SendGoal_Event & ros_message)
{
  // Member: info
  service_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.info);

  // Member: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.request.resize(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.request[i]);
    }
  }

  // Member: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.response.resize(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.response[i]);
    }
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Event & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: info
  current_alignment +=
    service_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.info, current_alignment);

  // Member: request
  {
    size_t array_size = ros_message.request.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.request[index], current_alignment);
    }
  }

  // Member: response
  {
    size_t array_size = ros_message.response.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.response[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_SendGoal_Event(
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

  // Member: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        service_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_SendGoal_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_SendGoal_Response(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_SendGoal_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: info
  service_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.info,
    cdr);

  // Member: request
  {
    size_t size = ros_message.request.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.request[i],
        cdr);
    }
  }

  // Member: response
  {
    size_t size = ros_message.response.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.response[i],
        cdr);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_SendGoal_Event & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: info
  current_alignment +=
    service_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.info, current_alignment);

  // Member: request
  {
    size_t array_size = ros_message.request.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.request[index], current_alignment);
    }
  }

  // Member: response
  {
    size_t array_size = ros_message.response.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.response[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_SendGoal_Event(
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

  // Member: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        service_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_SendGoal_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_SendGoal_Response(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_SendGoal_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_SendGoal_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_SendGoal_Event *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_SendGoal_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_SendGoal_Event *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_SendGoal_Event__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_SendGoal_Event *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_SendGoal_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_SendGoal_Event(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_SendGoal_Event__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_SendGoal_Event",
  _SetJointTarget_SendGoal_Event__cdr_serialize,
  _SetJointTarget_SendGoal_Event__cdr_deserialize,
  _SetJointTarget_SendGoal_Event__get_serialized_size,
  _SetJointTarget_SendGoal_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_SendGoal_Event__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_SendGoal_Event__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal_Event>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal_Event__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_SendGoal_Event)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal_Event__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SetJointTarget_SendGoal__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_SendGoal",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_SendGoal_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_SendGoal_Response)(),
};

#ifdef __cplusplus
extern "C"
{
#endif

static const rosidl_service_type_support_t _SetJointTarget_SendGoal__handle{
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_SendGoal__callbacks,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal_Request>(),
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal_Response>(),
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::SetJointTarget_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::SetJointTarget_SendGoal>,
  &robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_description_sources,
};

#ifdef __cplusplus
}
#endif

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::SetJointTarget_SendGoal>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_SendGoal)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_SendGoal__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
// functions for unique_identifier_msgs::msg::UUID already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.goal_id,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_GetResult_Request & ros_message)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.goal_id);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_id
  current_alignment +=
    unique_identifier_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.goal_id, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_GetResult_Request(
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

  // Member: goal_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        unique_identifier_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_UUID(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_GetResult_Request;
    is_plain =
      (
      offsetof(DataType, goal_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.goal_id,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_id
  current_alignment +=
    unique_identifier_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.goal_id, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_GetResult_Request(
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

  // Member: goal_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        unique_identifier_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_UUID(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_GetResult_Request;
    is_plain =
      (
      offsetof(DataType, goal_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_GetResult_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_GetResult_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_GetResult_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_GetResult_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_GetResult_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_GetResult_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_GetResult_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_GetResult_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_GetResult_Request__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_GetResult_Request",
  _SetJointTarget_GetResult_Request__cdr_serialize,
  _SetJointTarget_GetResult_Request__cdr_deserialize,
  _SetJointTarget_GetResult_Request__get_serialized_size,
  _SetJointTarget_GetResult_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_GetResult_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_GetResult_Request__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult_Request>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_GetResult_Request)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
// functions for robokpy_interfaces::action::SetJointTarget_Result already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: status
  cdr << ros_message.status;

  // Member: result
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.result,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_GetResult_Response & ros_message)
{
  // Member: status
  cdr >> ros_message.status;

  // Member: result
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.result);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: status
  {
    size_t item_size = sizeof(ros_message.status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: result
  current_alignment +=
    robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.result, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_GetResult_Response(
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

  // Member: status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: result
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_Result(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_GetResult_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: status
  cdr << ros_message.status;

  // Member: result
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.result,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: status
  {
    size_t item_size = sizeof(ros_message.status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: result
  current_alignment +=
    robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.result, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_GetResult_Response(
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

  // Member: status
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: result
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_Result(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_GetResult_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_GetResult_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_GetResult_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_GetResult_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_GetResult_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_GetResult_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_GetResult_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_GetResult_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_GetResult_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_GetResult_Response__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_GetResult_Response",
  _SetJointTarget_GetResult_Response__cdr_serialize,
  _SetJointTarget_GetResult_Response__cdr_deserialize,
  _SetJointTarget_GetResult_Response__get_serialized_size,
  _SetJointTarget_GetResult_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_GetResult_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_GetResult_Response__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult_Response>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_GetResult_Response)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult_Response__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
// functions for service_msgs::msg::ServiceEventInfo already declared above

// functions for robokpy_interfaces::action::SetJointTarget_GetResult_Request already declared above

// functions for robokpy_interfaces::action::SetJointTarget_GetResult_Response already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: info
  service_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.info,
    cdr);

  // Member: request
  {
    size_t size = ros_message.request.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.request[i],
        cdr);
    }
  }

  // Member: response
  {
    size_t size = ros_message.response.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.response[i],
        cdr);
    }
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_GetResult_Event & ros_message)
{
  // Member: info
  service_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.info);

  // Member: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.request.resize(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.request[i]);
    }
  }

  // Member: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.response.resize(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.response[i]);
    }
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Event & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: info
  current_alignment +=
    service_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.info, current_alignment);

  // Member: request
  {
    size_t array_size = ros_message.request.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.request[index], current_alignment);
    }
  }

  // Member: response
  {
    size_t array_size = ros_message.response.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.response[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_GetResult_Event(
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

  // Member: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        service_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_GetResult_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_GetResult_Response(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_GetResult_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Event & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: info
  service_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.info,
    cdr);

  // Member: request
  {
    size_t size = ros_message.request.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.request[i],
        cdr);
    }
  }

  // Member: response
  {
    size_t size = ros_message.response.size();
    if (size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.response[i],
        cdr);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_GetResult_Event & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: info
  current_alignment +=
    service_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.info, current_alignment);

  // Member: request
  {
    size_t array_size = ros_message.request.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.request[index], current_alignment);
    }
  }

  // Member: response
  {
    size_t array_size = ros_message.response.size();
    if (array_size > 1) {
      throw std::runtime_error("array size exceeds upper bound");
    }
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.response[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_GetResult_Event(
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

  // Member: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        service_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_GetResult_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_GetResult_Response(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_GetResult_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_GetResult_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_GetResult_Event *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_GetResult_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_GetResult_Event *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_GetResult_Event__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_GetResult_Event *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_GetResult_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_GetResult_Event(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_GetResult_Event__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_GetResult_Event",
  _SetJointTarget_GetResult_Event__cdr_serialize,
  _SetJointTarget_GetResult_Event__cdr_deserialize,
  _SetJointTarget_GetResult_Event__get_serialized_size,
  _SetJointTarget_GetResult_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_GetResult_Event__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_GetResult_Event__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult_Event>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult_Event__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_GetResult_Event)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult_Event__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _SetJointTarget_GetResult__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_GetResult",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_GetResult_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_GetResult_Response)(),
};

#ifdef __cplusplus
extern "C"
{
#endif

static const rosidl_service_type_support_t _SetJointTarget_GetResult__handle{
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_GetResult__callbacks,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult_Request>(),
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult_Response>(),
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::SetJointTarget_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::SetJointTarget_GetResult>,
  &robokpy_interfaces__action__SetJointTarget_GetResult__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_GetResult__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_GetResult__get_type_description_sources,
};

#ifdef __cplusplus
}
#endif

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::SetJointTarget_GetResult>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_GetResult)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_GetResult__handle;
}

#ifdef __cplusplus
}
#endif
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
// functions for unique_identifier_msgs::msg::UUID already declared above

// functions for robokpy_interfaces::action::SetJointTarget_Feedback already declared above


namespace robokpy_interfaces
{

namespace action
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::action::SetJointTarget_FeedbackMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.goal_id,
    cdr);

  // Member: feedback
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.feedback,
    cdr);

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::action::SetJointTarget_FeedbackMessage & ros_message)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.goal_id);

  // Member: feedback
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.feedback);

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::action::SetJointTarget_FeedbackMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_id
  current_alignment +=
    unique_identifier_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.goal_id, current_alignment);

  // Member: feedback
  current_alignment +=
    robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.feedback, current_alignment);

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_SetJointTarget_FeedbackMessage(
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

  // Member: goal_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        unique_identifier_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // Member: feedback
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_SetJointTarget_Feedback(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_FeedbackMessage;
    is_plain =
      (
      offsetof(DataType, feedback) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::action::SetJointTarget_FeedbackMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: goal_id
  unique_identifier_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.goal_id,
    cdr);

  // Member: feedback
  robokpy_interfaces::action::typesupport_fastrtps_cpp::cdr_serialize_key(
    ros_message.feedback,
    cdr);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::action::SetJointTarget_FeedbackMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: goal_id
  current_alignment +=
    unique_identifier_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.goal_id, current_alignment);

  // Member: feedback
  current_alignment +=
    robokpy_interfaces::action::typesupport_fastrtps_cpp::get_serialized_size_key(
    ros_message.feedback, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_SetJointTarget_FeedbackMessage(
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

  // Member: goal_id
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        unique_identifier_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_key_UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: feedback
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        robokpy_interfaces::action::typesupport_fastrtps_cpp::max_serialized_size_key_SetJointTarget_Feedback(
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
    using DataType = robokpy_interfaces::action::SetJointTarget_FeedbackMessage;
    is_plain =
      (
      offsetof(DataType, feedback) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SetJointTarget_FeedbackMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_FeedbackMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetJointTarget_FeedbackMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::action::SetJointTarget_FeedbackMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetJointTarget_FeedbackMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::action::SetJointTarget_FeedbackMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetJointTarget_FeedbackMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetJointTarget_FeedbackMessage(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetJointTarget_FeedbackMessage__callbacks = {
  "robokpy_interfaces::action",
  "SetJointTarget_FeedbackMessage",
  _SetJointTarget_FeedbackMessage__cdr_serialize,
  _SetJointTarget_FeedbackMessage__cdr_deserialize,
  _SetJointTarget_FeedbackMessage__get_serialized_size,
  _SetJointTarget_FeedbackMessage__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SetJointTarget_FeedbackMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetJointTarget_FeedbackMessage__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::SetJointTarget_FeedbackMessage>()
{
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_FeedbackMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, action, SetJointTarget_FeedbackMessage)() {
  return &robokpy_interfaces::action::typesupport_fastrtps_cpp::_SetJointTarget_FeedbackMessage__handle;
}

#ifdef __cplusplus
}
#endif
