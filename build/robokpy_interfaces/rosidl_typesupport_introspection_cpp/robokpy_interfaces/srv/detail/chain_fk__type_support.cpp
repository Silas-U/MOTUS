// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/ChainFK.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robokpy_interfaces/srv/detail/chain_fk__functions.h"
#include "robokpy_interfaces/srv/detail/chain_fk__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ChainFK_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::ChainFK_Request(_init);
}

void ChainFK_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::ChainFK_Request *>(message_memory);
  typed_message->~ChainFK_Request();
}

size_t size_function__ChainFK_Request__q(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ChainFK_Request__q(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__ChainFK_Request__q(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__ChainFK_Request__q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ChainFK_Request__q(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ChainFK_Request__q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ChainFK_Request__q(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__ChainFK_Request__q(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ChainFK_Request_message_member_array[3] = {
  {
    "q",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Request, q),  // bytes offset in struct
    nullptr,  // default value
    size_function__ChainFK_Request__q,  // size() function pointer
    get_const_function__ChainFK_Request__q,  // get_const(index) function pointer
    get_function__ChainFK_Request__q,  // get(index) function pointer
    fetch_function__ChainFK_Request__q,  // fetch(index, &value) function pointer
    assign_function__ChainFK_Request__q,  // assign(index, value) function pointer
    resize_function__ChainFK_Request__q  // resize(index) function pointer
  },
  {
    "base_link",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Request, base_link),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "end_link",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Request, end_link),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ChainFK_Request_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "ChainFK_Request",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::srv::ChainFK_Request),
  false,  // has_any_key_member_
  ChainFK_Request_message_member_array,  // message members
  ChainFK_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ChainFK_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ChainFK_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ChainFK_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ChainFK_Request__get_type_hash,
  &robokpy_interfaces__srv__ChainFK_Request__get_type_description,
  &robokpy_interfaces__srv__ChainFK_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Request>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, ChainFK_Request)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "robokpy_interfaces/srv/detail/chain_fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/chain_fk__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ChainFK_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::ChainFK_Response(_init);
}

void ChainFK_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::ChainFK_Response *>(message_memory);
  typed_message->~ChainFK_Response();
}

size_t size_function__ChainFK_Response__pose(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__ChainFK_Response__pose(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__ChainFK_Response__pose(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__ChainFK_Response__pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ChainFK_Response__pose(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ChainFK_Response__pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ChainFK_Response__pose(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__ChainFK_Response__pose_euler(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__ChainFK_Response__pose_euler(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__ChainFK_Response__pose_euler(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__ChainFK_Response__pose_euler(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ChainFK_Response__pose_euler(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ChainFK_Response__pose_euler(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ChainFK_Response__pose_euler(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ChainFK_Response_message_member_array[4] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Response, pose),  // bytes offset in struct
    nullptr,  // default value
    size_function__ChainFK_Response__pose,  // size() function pointer
    get_const_function__ChainFK_Response__pose,  // get_const(index) function pointer
    get_function__ChainFK_Response__pose,  // get(index) function pointer
    fetch_function__ChainFK_Response__pose,  // fetch(index, &value) function pointer
    assign_function__ChainFK_Response__pose,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pose_euler",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    6,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Response, pose_euler),  // bytes offset in struct
    nullptr,  // default value
    size_function__ChainFK_Response__pose_euler,  // size() function pointer
    get_const_function__ChainFK_Response__pose_euler,  // get_const(index) function pointer
    get_function__ChainFK_Response__pose_euler,  // get(index) function pointer
    fetch_function__ChainFK_Response__pose_euler,  // fetch(index, &value) function pointer
    assign_function__ChainFK_Response__pose_euler,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ChainFK_Response_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "ChainFK_Response",  // message name
  4,  // number of fields
  sizeof(robokpy_interfaces::srv::ChainFK_Response),
  false,  // has_any_key_member_
  ChainFK_Response_message_member_array,  // message members
  ChainFK_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ChainFK_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ChainFK_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ChainFK_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ChainFK_Response__get_type_hash,
  &robokpy_interfaces__srv__ChainFK_Response__get_type_description,
  &robokpy_interfaces__srv__ChainFK_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Response>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, ChainFK_Response)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "robokpy_interfaces/srv/detail/chain_fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/chain_fk__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ChainFK_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::ChainFK_Event(_init);
}

void ChainFK_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::ChainFK_Event *>(message_memory);
  typed_message->~ChainFK_Event();
}

size_t size_function__ChainFK_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::srv::ChainFK_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ChainFK_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::srv::ChainFK_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__ChainFK_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::srv::ChainFK_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__ChainFK_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::srv::ChainFK_Request *>(
    get_const_function__ChainFK_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::srv::ChainFK_Request *>(untyped_value);
  value = item;
}

void assign_function__ChainFK_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::srv::ChainFK_Request *>(
    get_function__ChainFK_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::srv::ChainFK_Request *>(untyped_value);
  item = value;
}

void resize_function__ChainFK_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::srv::ChainFK_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ChainFK_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::srv::ChainFK_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ChainFK_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::srv::ChainFK_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__ChainFK_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::srv::ChainFK_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__ChainFK_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::srv::ChainFK_Response *>(
    get_const_function__ChainFK_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::srv::ChainFK_Response *>(untyped_value);
  value = item;
}

void assign_function__ChainFK_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::srv::ChainFK_Response *>(
    get_function__ChainFK_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::srv::ChainFK_Response *>(untyped_value);
  item = value;
}

void resize_function__ChainFK_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::srv::ChainFK_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ChainFK_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Event, info),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "request",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__ChainFK_Event__request,  // size() function pointer
    get_const_function__ChainFK_Event__request,  // get_const(index) function pointer
    get_function__ChainFK_Event__request,  // get(index) function pointer
    fetch_function__ChainFK_Event__request,  // fetch(index, &value) function pointer
    assign_function__ChainFK_Event__request,  // assign(index, value) function pointer
    resize_function__ChainFK_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::srv::ChainFK_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__ChainFK_Event__response,  // size() function pointer
    get_const_function__ChainFK_Event__response,  // get_const(index) function pointer
    get_function__ChainFK_Event__response,  // get(index) function pointer
    fetch_function__ChainFK_Event__response,  // fetch(index, &value) function pointer
    assign_function__ChainFK_Event__response,  // assign(index, value) function pointer
    resize_function__ChainFK_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ChainFK_Event_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "ChainFK_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::srv::ChainFK_Event),
  false,  // has_any_key_member_
  ChainFK_Event_message_member_array,  // message members
  ChainFK_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ChainFK_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ChainFK_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ChainFK_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__ChainFK_Event__get_type_hash,
  &robokpy_interfaces__srv__ChainFK_Event__get_type_description,
  &robokpy_interfaces__srv__ChainFK_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Event>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, ChainFK_Event)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "robokpy_interfaces/srv/detail/chain_fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/chain_fk__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace robokpy_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ChainFK_service_members = {
  "robokpy_interfaces::srv",  // service namespace
  "ChainFK",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<robokpy_interfaces::srv::ChainFK>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t ChainFK_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ChainFK_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::ChainFK_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::ChainFK>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::ChainFK>,
  &robokpy_interfaces__srv__ChainFK__get_type_hash,
  &robokpy_interfaces__srv__ChainFK__get_type_description,
  &robokpy_interfaces__srv__ChainFK__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::ChainFK>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::ChainFK_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure all of the service_members are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr ||
    service_members->event_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::ChainFK_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::ChainFK_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::ChainFK_Event
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, ChainFK)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<robokpy_interfaces::srv::ChainFK>();
}

#ifdef __cplusplus
}
#endif
