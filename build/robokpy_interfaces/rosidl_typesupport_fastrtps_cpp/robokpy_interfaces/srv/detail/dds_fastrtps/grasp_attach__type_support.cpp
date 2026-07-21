// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/GraspAttach.idl
// generated code does not contain a copyright notice
#include "robokpy_interfaces/srv/detail/grasp_attach__rosidl_typesupport_fastrtps_cpp.hpp"
#include "robokpy_interfaces/srv/detail/grasp_attach__functions.h"
#include "robokpy_interfaces/srv/detail/grasp_attach__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::srv::GraspAttach_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: parent_model
  cdr << ros_message.parent_model;

  // Member: parent_link
  cdr << ros_message.parent_link;

  // Member: child_model
  cdr << ros_message.child_model;

  // Member: child_link
  cdr << ros_message.child_link;

  // Member: attach
  cdr << (ros_message.attach ? true : false);

  // Member: joint_id
  cdr << ros_message.joint_id;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::srv::GraspAttach_Request & ros_message)
{
  // Member: parent_model
  cdr >> ros_message.parent_model;

  // Member: parent_link
  cdr >> ros_message.parent_link;

  // Member: child_model
  cdr >> ros_message.child_model;

  // Member: child_link
  cdr >> ros_message.child_link;

  // Member: attach
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.attach = tmp ? true : false;
  }

  // Member: joint_id
  cdr >> ros_message.joint_id;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::srv::GraspAttach_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: parent_model
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.parent_model.size() + 1);

  // Member: parent_link
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.parent_link.size() + 1);

  // Member: child_model
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.child_model.size() + 1);

  // Member: child_link
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.child_link.size() + 1);

  // Member: attach
  {
    size_t item_size = sizeof(ros_message.attach);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: joint_id
  {
    size_t item_size = sizeof(ros_message.joint_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_GraspAttach_Request(
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

  // Member: parent_model
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
  // Member: parent_link
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
  // Member: child_model
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
  // Member: child_link
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
  // Member: attach
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: joint_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces::srv::GraspAttach_Request;
    is_plain =
      (
      offsetof(DataType, joint_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::srv::GraspAttach_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: parent_model
  cdr << ros_message.parent_model;

  // Member: parent_link
  cdr << ros_message.parent_link;

  // Member: child_model
  cdr << ros_message.child_model;

  // Member: child_link
  cdr << ros_message.child_link;

  // Member: attach
  cdr << (ros_message.attach ? true : false);

  // Member: joint_id
  cdr << ros_message.joint_id;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::srv::GraspAttach_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: parent_model
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.parent_model.size() + 1);

  // Member: parent_link
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.parent_link.size() + 1);

  // Member: child_model
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.child_model.size() + 1);

  // Member: child_link
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.child_link.size() + 1);

  // Member: attach
  {
    size_t item_size = sizeof(ros_message.attach);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: joint_id
  {
    size_t item_size = sizeof(ros_message.joint_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_GraspAttach_Request(
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

  // Member: parent_model
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

  // Member: parent_link
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

  // Member: child_model
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

  // Member: child_link
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

  // Member: attach
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: joint_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces::srv::GraspAttach_Request;
    is_plain =
      (
      offsetof(DataType, joint_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _GraspAttach_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::srv::GraspAttach_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GraspAttach_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::srv::GraspAttach_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GraspAttach_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::srv::GraspAttach_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GraspAttach_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GraspAttach_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GraspAttach_Request__callbacks = {
  "robokpy_interfaces::srv",
  "GraspAttach_Request",
  _GraspAttach_Request__cdr_serialize,
  _GraspAttach_Request__cdr_deserialize,
  _GraspAttach_Request__get_serialized_size,
  _GraspAttach_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GraspAttach_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GraspAttach_Request__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__GraspAttach_Request__get_type_hash,
  &robokpy_interfaces__srv__GraspAttach_Request__get_type_description,
  &robokpy_interfaces__srv__GraspAttach_Request__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::GraspAttach_Request>()
{
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, GraspAttach_Request)() {
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach_Request__handle;
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

namespace robokpy_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::srv::GraspAttach_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);

  // Member: message
  cdr << ros_message.message;

  // Member: joint_id
  cdr << ros_message.joint_id;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  robokpy_interfaces::srv::GraspAttach_Response & ros_message)
{
  // Member: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.success = tmp ? true : false;
  }

  // Member: message
  cdr >> ros_message.message;

  // Member: joint_id
  cdr >> ros_message.joint_id;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::srv::GraspAttach_Response & ros_message,
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

  // Member: message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.message.size() + 1);

  // Member: joint_id
  {
    size_t item_size = sizeof(ros_message.joint_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_GraspAttach_Response(
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
  // Member: message
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
  // Member: joint_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces::srv::GraspAttach_Response;
    is_plain =
      (
      offsetof(DataType, joint_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize_key(
  const robokpy_interfaces::srv::GraspAttach_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: success
  cdr << (ros_message.success ? true : false);

  // Member: message
  cdr << ros_message.message;

  // Member: joint_id
  cdr << ros_message.joint_id;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::srv::GraspAttach_Response & ros_message,
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

  // Member: message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.message.size() + 1);

  // Member: joint_id
  {
    size_t item_size = sizeof(ros_message.joint_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_GraspAttach_Response(
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

  // Member: message
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

  // Member: joint_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = robokpy_interfaces::srv::GraspAttach_Response;
    is_plain =
      (
      offsetof(DataType, joint_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _GraspAttach_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::srv::GraspAttach_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GraspAttach_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::srv::GraspAttach_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GraspAttach_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::srv::GraspAttach_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GraspAttach_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GraspAttach_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GraspAttach_Response__callbacks = {
  "robokpy_interfaces::srv",
  "GraspAttach_Response",
  _GraspAttach_Response__cdr_serialize,
  _GraspAttach_Response__cdr_deserialize,
  _GraspAttach_Response__get_serialized_size,
  _GraspAttach_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GraspAttach_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GraspAttach_Response__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__GraspAttach_Response__get_type_hash,
  &robokpy_interfaces__srv__GraspAttach_Response__get_type_description,
  &robokpy_interfaces__srv__GraspAttach_Response__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::GraspAttach_Response>()
{
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, GraspAttach_Response)() {
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach_Response__handle;
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

// functions for robokpy_interfaces::srv::GraspAttach_Request already declared above

// functions for robokpy_interfaces::srv::GraspAttach_Response already declared above


namespace robokpy_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
cdr_serialize(
  const robokpy_interfaces::srv::GraspAttach_Event & ros_message,
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
      robokpy_interfaces::srv::typesupport_fastrtps_cpp::cdr_serialize(
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
      robokpy_interfaces::srv::typesupport_fastrtps_cpp::cdr_serialize(
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
  robokpy_interfaces::srv::GraspAttach_Event & ros_message)
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
      robokpy_interfaces::srv::typesupport_fastrtps_cpp::cdr_deserialize(
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
      robokpy_interfaces::srv::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.response[i]);
    }
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size(
  const robokpy_interfaces::srv::GraspAttach_Event & ros_message,
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::get_serialized_size(
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.response[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_GraspAttach_Event(
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::max_serialized_size_GraspAttach_Request(
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::max_serialized_size_GraspAttach_Response(
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
    using DataType = robokpy_interfaces::srv::GraspAttach_Event;
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
  const robokpy_interfaces::srv::GraspAttach_Event & ros_message,
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
      robokpy_interfaces::srv::typesupport_fastrtps_cpp::cdr_serialize_key(
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
      robokpy_interfaces::srv::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.response[i],
        cdr);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
get_serialized_size_key(
  const robokpy_interfaces::srv::GraspAttach_Event & ros_message,
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::get_serialized_size_key(
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.response[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_robokpy_interfaces
max_serialized_size_key_GraspAttach_Event(
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::max_serialized_size_key_GraspAttach_Request(
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
        robokpy_interfaces::srv::typesupport_fastrtps_cpp::max_serialized_size_key_GraspAttach_Response(
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
    using DataType = robokpy_interfaces::srv::GraspAttach_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _GraspAttach_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::srv::GraspAttach_Event *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GraspAttach_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<robokpy_interfaces::srv::GraspAttach_Event *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GraspAttach_Event__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const robokpy_interfaces::srv::GraspAttach_Event *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GraspAttach_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GraspAttach_Event(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GraspAttach_Event__callbacks = {
  "robokpy_interfaces::srv",
  "GraspAttach_Event",
  _GraspAttach_Event__cdr_serialize,
  _GraspAttach_Event__cdr_deserialize,
  _GraspAttach_Event__get_serialized_size,
  _GraspAttach_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _GraspAttach_Event__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GraspAttach_Event__callbacks,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__GraspAttach_Event__get_type_hash,
  &robokpy_interfaces__srv__GraspAttach_Event__get_type_description,
  &robokpy_interfaces__srv__GraspAttach_Event__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::GraspAttach_Event>()
{
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach_Event__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, GraspAttach_Event)() {
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach_Event__handle;
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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _GraspAttach__callbacks = {
  "robokpy_interfaces::srv",
  "GraspAttach",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, GraspAttach_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, GraspAttach_Response)(),
};

#ifdef __cplusplus
extern "C"
{
#endif

static const rosidl_service_type_support_t _GraspAttach__handle{
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GraspAttach__callbacks,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::srv::GraspAttach_Request>(),
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::srv::GraspAttach_Response>(),
  ::rosidl_typesupport_fastrtps_cpp::get_message_type_support_handle<robokpy_interfaces::srv::GraspAttach_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::GraspAttach>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::GraspAttach>,
  &robokpy_interfaces__srv__GraspAttach__get_type_hash,
  &robokpy_interfaces__srv__GraspAttach__get_type_description,
  &robokpy_interfaces__srv__GraspAttach__get_type_description_sources,
};

#ifdef __cplusplus
}
#endif

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_robokpy_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::GraspAttach>()
{
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, robokpy_interfaces, srv, GraspAttach)() {
  return &robokpy_interfaces::srv::typesupport_fastrtps_cpp::_GraspAttach__handle;
}

#ifdef __cplusplus
}
#endif
