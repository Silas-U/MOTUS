// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:srv/Reachable.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robokpy_interfaces/srv/detail/reachable__functions.h"
#include "robokpy_interfaces/srv/detail/reachable__struct.hpp"
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

void Reachable_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::Reachable_Request(_init);
}

void Reachable_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::Reachable_Request *>(message_memory);
  typed_message->~Reachable_Request();
}

size_t size_function__Reachable_Request__target_pose(const void * untyped_member)
{
  (void)untyped_member;
  return 7;
}

const void * get_const_function__Reachable_Request__target_pose(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void * get_function__Reachable_Request__target_pose(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<double, 7> *>(untyped_member);
  return &member[index];
}

void fetch_function__Reachable_Request__target_pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Reachable_Request__target_pose(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Reachable_Request__target_pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Reachable_Request__target_pose(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

size_t size_function__Reachable_Request__seed(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Reachable_Request__seed(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Reachable_Request__seed(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Reachable_Request__seed(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Reachable_Request__seed(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Reachable_Request__seed(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Reachable_Request__seed(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Reachable_Request__seed(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Reachable_Request_message_member_array[3] = {
  {
    "target_pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    7,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Request, target_pose),  // bytes offset in struct
    nullptr,  // default value
    size_function__Reachable_Request__target_pose,  // size() function pointer
    get_const_function__Reachable_Request__target_pose,  // get_const(index) function pointer
    get_function__Reachable_Request__target_pose,  // get(index) function pointer
    fetch_function__Reachable_Request__target_pose,  // fetch(index, &value) function pointer
    assign_function__Reachable_Request__target_pose,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "seed",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Request, seed),  // bytes offset in struct
    nullptr,  // default value
    size_function__Reachable_Request__seed,  // size() function pointer
    get_const_function__Reachable_Request__seed,  // get_const(index) function pointer
    get_function__Reachable_Request__seed,  // get(index) function pointer
    fetch_function__Reachable_Request__seed,  // fetch(index, &value) function pointer
    assign_function__Reachable_Request__seed,  // assign(index, value) function pointer
    resize_function__Reachable_Request__seed  // resize(index) function pointer
  },
  {
    "tol",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Request, tol),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Reachable_Request_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "Reachable_Request",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::srv::Reachable_Request),
  false,  // has_any_key_member_
  Reachable_Request_message_member_array,  // message members
  Reachable_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Reachable_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Reachable_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Reachable_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__Reachable_Request__get_type_hash,
  &robokpy_interfaces__srv__Reachable_Request__get_type_description,
  &robokpy_interfaces__srv__Reachable_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Request>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, Reachable_Request)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_Request_message_type_support_handle;
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
// #include "robokpy_interfaces/srv/detail/reachable__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/reachable__struct.hpp"
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

void Reachable_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::Reachable_Response(_init);
}

void Reachable_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::Reachable_Response *>(message_memory);
  typed_message->~Reachable_Response();
}

size_t size_function__Reachable_Response__q(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Reachable_Response__q(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__Reachable_Response__q(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__Reachable_Response__q(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__Reachable_Response__q(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__Reachable_Response__q(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__Reachable_Response__q(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__Reachable_Response__q(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Reachable_Response_message_member_array[4] = {
  {
    "reachable",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Response, reachable),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "q",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Response, q),  // bytes offset in struct
    nullptr,  // default value
    size_function__Reachable_Response__q,  // size() function pointer
    get_const_function__Reachable_Response__q,  // get_const(index) function pointer
    get_function__Reachable_Response__q,  // get(index) function pointer
    fetch_function__Reachable_Response__q,  // fetch(index, &value) function pointer
    assign_function__Reachable_Response__q,  // assign(index, value) function pointer
    resize_function__Reachable_Response__q  // resize(index) function pointer
  },
  {
    "error",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Response, error),  // bytes offset in struct
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
    offsetof(robokpy_interfaces::srv::Reachable_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Reachable_Response_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "Reachable_Response",  // message name
  4,  // number of fields
  sizeof(robokpy_interfaces::srv::Reachable_Response),
  false,  // has_any_key_member_
  Reachable_Response_message_member_array,  // message members
  Reachable_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Reachable_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Reachable_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Reachable_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__Reachable_Response__get_type_hash,
  &robokpy_interfaces__srv__Reachable_Response__get_type_description,
  &robokpy_interfaces__srv__Reachable_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Response>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, Reachable_Response)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_Response_message_type_support_handle;
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
// #include "robokpy_interfaces/srv/detail/reachable__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/reachable__struct.hpp"
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

void Reachable_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::srv::Reachable_Event(_init);
}

void Reachable_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::srv::Reachable_Event *>(message_memory);
  typed_message->~Reachable_Event();
}

size_t size_function__Reachable_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::srv::Reachable_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Reachable_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::srv::Reachable_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__Reachable_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::srv::Reachable_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__Reachable_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::srv::Reachable_Request *>(
    get_const_function__Reachable_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::srv::Reachable_Request *>(untyped_value);
  value = item;
}

void assign_function__Reachable_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::srv::Reachable_Request *>(
    get_function__Reachable_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::srv::Reachable_Request *>(untyped_value);
  item = value;
}

void resize_function__Reachable_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::srv::Reachable_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Reachable_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::srv::Reachable_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Reachable_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::srv::Reachable_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__Reachable_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::srv::Reachable_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__Reachable_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::srv::Reachable_Response *>(
    get_const_function__Reachable_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::srv::Reachable_Response *>(untyped_value);
  value = item;
}

void assign_function__Reachable_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::srv::Reachable_Response *>(
    get_function__Reachable_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::srv::Reachable_Response *>(untyped_value);
  item = value;
}

void resize_function__Reachable_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::srv::Reachable_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Reachable_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__Reachable_Event__request,  // size() function pointer
    get_const_function__Reachable_Event__request,  // get_const(index) function pointer
    get_function__Reachable_Event__request,  // get(index) function pointer
    fetch_function__Reachable_Event__request,  // fetch(index, &value) function pointer
    assign_function__Reachable_Event__request,  // assign(index, value) function pointer
    resize_function__Reachable_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::srv::Reachable_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__Reachable_Event__response,  // size() function pointer
    get_const_function__Reachable_Event__response,  // get_const(index) function pointer
    get_function__Reachable_Event__response,  // get(index) function pointer
    fetch_function__Reachable_Event__response,  // fetch(index, &value) function pointer
    assign_function__Reachable_Event__response,  // assign(index, value) function pointer
    resize_function__Reachable_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Reachable_Event_message_members = {
  "robokpy_interfaces::srv",  // message namespace
  "Reachable_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::srv::Reachable_Event),
  false,  // has_any_key_member_
  Reachable_Event_message_member_array,  // message members
  Reachable_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  Reachable_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Reachable_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Reachable_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__srv__Reachable_Event__get_type_hash,
  &robokpy_interfaces__srv__Reachable_Event__get_type_description,
  &robokpy_interfaces__srv__Reachable_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Event>()
{
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, Reachable_Event)() {
  return &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_Event_message_type_support_handle;
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
// #include "robokpy_interfaces/srv/detail/reachable__functions.h"
// already included above
// #include "robokpy_interfaces/srv/detail/reachable__struct.hpp"
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
static ::rosidl_typesupport_introspection_cpp::ServiceMembers Reachable_service_members = {
  "robokpy_interfaces::srv",  // service namespace
  "Reachable",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<robokpy_interfaces::srv::Reachable>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t Reachable_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Reachable_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::srv::Reachable_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::srv::Reachable>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::srv::Reachable>,
  &robokpy_interfaces__srv__Reachable__get_type_hash,
  &robokpy_interfaces__srv__Reachable__get_type_description,
  &robokpy_interfaces__srv__Reachable__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::srv::Reachable>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::robokpy_interfaces::srv::rosidl_typesupport_introspection_cpp::Reachable_service_type_support_handle;
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
        ::robokpy_interfaces::srv::Reachable_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::Reachable_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::srv::Reachable_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, srv, Reachable)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<robokpy_interfaces::srv::Reachable>();
}

#ifdef __cplusplus
}
#endif
