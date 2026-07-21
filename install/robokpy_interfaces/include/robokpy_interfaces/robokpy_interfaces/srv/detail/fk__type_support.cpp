// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/FK.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robokpy_interfaces/srv/detail/fk__functions.h"
#include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

void FK_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::FK_Request(_init);
}

void FK_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::FK_Request *>(message_memory);
  typed_message->~FK_Request();
}

size_t size_function__FK_Request__q(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FK_Request__q(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__FK_Request__q(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__FK_Request__q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__FK_Request__q(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__FK_Request__q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__FK_Request__q(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__FK_Request__q(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FK_Request_message_member_array[2] = {
  {
    "q",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Request, q),  // bytes offset in struct
    nullptr,  // default value
    size_function__FK_Request__q,  // size() function pointer
    get_const_function__FK_Request__q,  // get_const(index) function pointer
    get_function__FK_Request__q,  // get(index) function pointer
    fetch_function__FK_Request__q,  // fetch(index, &value) function pointer
    assign_function__FK_Request__q,  // assign(index, value) function pointer
    resize_function__FK_Request__q  // resize(index) function pointer
  },
  {
    "include_tf_tree",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Request, include_tf_tree),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FK_Request_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "FK_Request",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces::srv::FK_Request),
  false,  // has_any_key_member_
  FK_Request_message_member_array,  // message members
  FK_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  FK_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FK_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FK_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__FK_Request__get_type_hash,
  &robokpy_interfaces__srv__FK_Request__get_type_description,
  &robokpy_interfaces__srv__FK_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::FK_Request>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK_Request)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_Request_message_type_support_handle;
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
// #include "robokpy_interfaces/srv/detail/fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

void FK_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::FK_Response(_init);
}

void FK_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::FK_Response *>(message_memory);
  typed_message->~FK_Response();
}

size_t size_function__FK_Response__pose(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__FK_Response__pose(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__FK_Response__pose(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__FK_Response__pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__FK_Response__pose(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__FK_Response__pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__FK_Response__pose(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__FK_Response__pose_euler(const void * untyped_member)
{
  (void)untyped_member;
  return 6;
}

const void * get_const_function__FK_Response__pose_euler(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void * get_function__FK_Response__pose_euler(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 6> *>(untyped_member);
  return &member[index];
}

void fetch_function__FK_Response__pose_euler(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__FK_Response__pose_euler(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__FK_Response__pose_euler(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__FK_Response__pose_euler(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__FK_Response__tf_tree_flat(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FK_Response__tf_tree_flat(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__FK_Response__tf_tree_flat(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__FK_Response__tf_tree_flat(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__FK_Response__tf_tree_flat(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__FK_Response__tf_tree_flat(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__FK_Response__tf_tree_flat(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__FK_Response__tf_tree_flat(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FK_Response_message_member_array[6] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Response, success),  // bytes offset in struct
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
    offsetof(robokpy_interfaces::srv::FK_Response, pose),  // bytes offset in struct
    nullptr,  // default value
    size_function__FK_Response__pose,  // size() function pointer
    get_const_function__FK_Response__pose,  // get_const(index) function pointer
    get_function__FK_Response__pose,  // get(index) function pointer
    fetch_function__FK_Response__pose,  // fetch(index, &value) function pointer
    assign_function__FK_Response__pose,  // assign(index, value) function pointer
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
    offsetof(robokpy_interfaces::srv::FK_Response, pose_euler),  // bytes offset in struct
    nullptr,  // default value
    size_function__FK_Response__pose_euler,  // size() function pointer
    get_const_function__FK_Response__pose_euler,  // get_const(index) function pointer
    get_function__FK_Response__pose_euler,  // get(index) function pointer
    fetch_function__FK_Response__pose_euler,  // fetch(index, &value) function pointer
    assign_function__FK_Response__pose_euler,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "tf_tree_flat",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Response, tf_tree_flat),  // bytes offset in struct
    nullptr,  // default value
    size_function__FK_Response__tf_tree_flat,  // size() function pointer
    get_const_function__FK_Response__tf_tree_flat,  // get_const(index) function pointer
    get_function__FK_Response__tf_tree_flat,  // get(index) function pointer
    fetch_function__FK_Response__tf_tree_flat,  // fetch(index, &value) function pointer
    assign_function__FK_Response__tf_tree_flat,  // assign(index, value) function pointer
    resize_function__FK_Response__tf_tree_flat  // resize(index) function pointer
  },
  {
    "num_links",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Response, num_links),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
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
    offsetof(robokpy_interfaces::srv::FK_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FK_Response_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "FK_Response",  // message name
  6,  // number of fields
  sizeof(robokpy_interfaces::srv::FK_Response),
  false,  // has_any_key_member_
  FK_Response_message_member_array,  // message members
  FK_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  FK_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FK_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FK_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__FK_Response__get_type_hash,
  &robokpy_interfaces__srv__FK_Response__get_type_description,
  &robokpy_interfaces__srv__FK_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::FK_Response>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK_Response)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_Response_message_type_support_handle;
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
// #include "robokpy_interfaces/srv/detail/fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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

void FK_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::FK_Event(_init);
}

void FK_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::FK_Event *>(message_memory);
  typed_message->~FK_Event();
}

size_t size_function__FK_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::srv::FK_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FK_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::srv::FK_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__FK_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::srv::FK_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__FK_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::srv::FK_Request *>(
    get_const_function__FK_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::srv::FK_Request *>(untyped_value);
  value = item;
}

void assign_function__FK_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::srv::FK_Request *>(
    get_function__FK_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::srv::FK_Request *>(untyped_value);
  item = value;
}

void resize_function__FK_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::srv::FK_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__FK_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::srv::FK_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FK_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::srv::FK_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__FK_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::srv::FK_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__FK_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::srv::FK_Response *>(
    get_const_function__FK_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::srv::FK_Response *>(untyped_value);
  value = item;
}

void assign_function__FK_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::srv::FK_Response *>(
    get_function__FK_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::srv::FK_Response *>(untyped_value);
  item = value;
}

void resize_function__FK_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::srv::FK_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FK_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__FK_Event__request,  // size() function pointer
    get_const_function__FK_Event__request,  // get_const(index) function pointer
    get_function__FK_Event__request,  // get(index) function pointer
    fetch_function__FK_Event__request,  // fetch(index, &value) function pointer
    assign_function__FK_Event__request,  // assign(index, value) function pointer
    resize_function__FK_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::srv::FK_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__FK_Event__response,  // size() function pointer
    get_const_function__FK_Event__response,  // get_const(index) function pointer
    get_function__FK_Event__response,  // get(index) function pointer
    fetch_function__FK_Event__response,  // fetch(index, &value) function pointer
    assign_function__FK_Event__response,  // assign(index, value) function pointer
    resize_function__FK_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FK_Event_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "FK_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::srv::FK_Event),
  false,  // has_any_key_member_
  FK_Event_message_member_array,  // message members
  FK_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  FK_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FK_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FK_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__FK_Event__get_type_hash,
  &robokpy_interfaces__srv__FK_Event__get_type_description,
  &robokpy_interfaces__srv__FK_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::FK_Event>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK_Event)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_Event_message_type_support_handle;
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
// #include "robokpy_interfaces/srv/detail/fk__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/fk__struct.hpp"
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
static ::rosidl_typesupport_introspection_cpp::ServiceMembers FK_service_members = {
  "robokpy_interfaces::srv",  // service namespace
  "FK",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<robokpy_interfaces::srv::FK>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t FK_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FK_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::FK_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::FK>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::FK>,
  &robokpy_interfaces__srv__FK__get_type_hash,
  &robokpy_interfaces__srv__FK__get_type_description,
  &robokpy_interfaces__srv__FK__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::FK>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::FK_service_type_support_handle;
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
        ::robokpy_interfaces::srv::FK_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::FK_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::FK_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, FK)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<robokpy_interfaces::srv::FK>();
}

#ifdef __cplusplus
}
#endif
