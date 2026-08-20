// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robokpy_interfaces:action/ExecuteMoveStep.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
#include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_Goal_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_Goal(_init);
}

void ExecuteMoveStep_Goal_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_Goal *>(message_memory);
  typed_message->~ExecuteMoveStep_Goal();
}

size_t size_function__ExecuteMoveStep_Goal__leg_step_ids(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_Goal__leg_step_ids(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_Goal__leg_step_ids(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_Goal__leg_step_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__ExecuteMoveStep_Goal__leg_step_ids(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_Goal__leg_step_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__ExecuteMoveStep_Goal__leg_step_ids(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_Goal__leg_step_ids(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ExecuteMoveStep_Goal__leg_target_poses(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_Goal__leg_target_poses(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_Goal__leg_target_poses(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_Goal__leg_target_poses(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const geometry_msgs::msg::Pose *>(
    get_const_function__ExecuteMoveStep_Goal__leg_target_poses(untyped_member, index));
  auto & value = *reinterpret_cast<geometry_msgs::msg::Pose *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_Goal__leg_target_poses(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<geometry_msgs::msg::Pose *>(
    get_function__ExecuteMoveStep_Goal__leg_target_poses(untyped_member, index));
  const auto & value = *reinterpret_cast<const geometry_msgs::msg::Pose *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_Goal__leg_target_poses(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<geometry_msgs::msg::Pose> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ExecuteMoveStep_Goal__leg_traj_methods(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_Goal__leg_traj_methods(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_Goal__leg_traj_methods(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_Goal__leg_traj_methods(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__ExecuteMoveStep_Goal__leg_traj_methods(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_Goal__leg_traj_methods(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__ExecuteMoveStep_Goal__leg_traj_methods(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_Goal__leg_traj_methods(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ExecuteMoveStep_Goal__leg_traj_types(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_Goal__leg_traj_types(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_Goal__leg_traj_types(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_Goal__leg_traj_types(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__ExecuteMoveStep_Goal__leg_traj_types(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_Goal__leg_traj_types(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__ExecuteMoveStep_Goal__leg_traj_types(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_Goal__leg_traj_types(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ExecuteMoveStep_Goal__leg_blend_radii(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_Goal__leg_blend_radii(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_Goal__leg_blend_radii(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_Goal__leg_blend_radii(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ExecuteMoveStep_Goal__leg_blend_radii(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_Goal__leg_blend_radii(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ExecuteMoveStep_Goal__leg_blend_radii(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_Goal__leg_blend_radii(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_Goal_message_member_array[6] = {
  {
    "leg_step_ids",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Goal, leg_step_ids),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_Goal__leg_step_ids,  // size() function pointer
    get_const_function__ExecuteMoveStep_Goal__leg_step_ids,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_Goal__leg_step_ids,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_Goal__leg_step_ids,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_Goal__leg_step_ids,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_Goal__leg_step_ids  // resize(index) function pointer
  },
  {
    "leg_target_poses",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<geometry_msgs::msg::Pose>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Goal, leg_target_poses),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_Goal__leg_target_poses,  // size() function pointer
    get_const_function__ExecuteMoveStep_Goal__leg_target_poses,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_Goal__leg_target_poses,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_Goal__leg_target_poses,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_Goal__leg_target_poses,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_Goal__leg_target_poses  // resize(index) function pointer
  },
  {
    "leg_traj_methods",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Goal, leg_traj_methods),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_Goal__leg_traj_methods,  // size() function pointer
    get_const_function__ExecuteMoveStep_Goal__leg_traj_methods,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_Goal__leg_traj_methods,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_Goal__leg_traj_methods,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_Goal__leg_traj_methods,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_Goal__leg_traj_methods  // resize(index) function pointer
  },
  {
    "leg_traj_types",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Goal, leg_traj_types),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_Goal__leg_traj_types,  // size() function pointer
    get_const_function__ExecuteMoveStep_Goal__leg_traj_types,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_Goal__leg_traj_types,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_Goal__leg_traj_types,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_Goal__leg_traj_types,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_Goal__leg_traj_types  // resize(index) function pointer
  },
  {
    "leg_blend_radii",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Goal, leg_blend_radii),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_Goal__leg_blend_radii,  // size() function pointer
    get_const_function__ExecuteMoveStep_Goal__leg_blend_radii,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_Goal__leg_blend_radii,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_Goal__leg_blend_radii,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_Goal__leg_blend_radii,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_Goal__leg_blend_radii  // resize(index) function pointer
  },
  {
    "speed_scale",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Goal, speed_scale),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_Goal_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_Goal",  // message name
  6,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_Goal),
  false,  // has_any_key_member_
  ExecuteMoveStep_Goal_message_member_array,  // message members
  ExecuteMoveStep_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_Goal_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_Goal_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_Goal_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_Goal__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_Goal__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Goal>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_Goal_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_Goal)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_Goal_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_Result_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_Result(_init);
}

void ExecuteMoveStep_Result_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_Result *>(message_memory);
  typed_message->~ExecuteMoveStep_Result();
}

size_t size_function__ExecuteMoveStep_Result__final_state(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_Result__final_state(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_Result__final_state(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_Result__final_state(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__ExecuteMoveStep_Result__final_state(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_Result__final_state(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__ExecuteMoveStep_Result__final_state(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_Result__final_state(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_Result_message_member_array[4] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Result, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "error_code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Result, error_code),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "final_state",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Result, final_state),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_Result__final_state,  // size() function pointer
    get_const_function__ExecuteMoveStep_Result__final_state,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_Result__final_state,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_Result__final_state,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_Result__final_state,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_Result__final_state  // resize(index) function pointer
  },
  {
    "total_duration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Result, total_duration),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_Result_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_Result",  // message name
  4,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_Result),
  false,  // has_any_key_member_
  ExecuteMoveStep_Result_message_member_array,  // message members
  ExecuteMoveStep_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_Result_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_Result_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_Result_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_Result__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_Result__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Result>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_Result_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_Result)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_Result_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_Feedback_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_Feedback(_init);
}

void ExecuteMoveStep_Feedback_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_Feedback *>(message_memory);
  typed_message->~ExecuteMoveStep_Feedback();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_Feedback_message_member_array[2] = {
  {
    "current_step_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Feedback, current_step_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "percent_complete",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_Feedback, percent_complete),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_Feedback_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_Feedback",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_Feedback),
  false,  // has_any_key_member_
  ExecuteMoveStep_Feedback_message_member_array,  // message members
  ExecuteMoveStep_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_Feedback_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_Feedback__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_Feedback__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Feedback>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_Feedback_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_Feedback)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_Feedback_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_SendGoal_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request(_init);
}

void ExecuteMoveStep_SendGoal_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request *>(message_memory);
  typed_message->~ExecuteMoveStep_SendGoal_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "goal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Goal>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request, goal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_SendGoal_Request_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request),
  false,  // has_any_key_member_
  ExecuteMoveStep_SendGoal_Request_message_member_array,  // message members
  ExecuteMoveStep_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Request__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Request__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Request)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_Request_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_SendGoal_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response(_init);
}

void ExecuteMoveStep_SendGoal_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response *>(message_memory);
  typed_message->~ExecuteMoveStep_SendGoal_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response, accepted),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "stamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Time>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response, stamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_SendGoal_Response_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response),
  false,  // has_any_key_member_
  ExecuteMoveStep_SendGoal_Response_message_member_array,  // message members
  ExecuteMoveStep_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Response__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Response__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Response)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_Response_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_SendGoal_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event(_init);
}

void ExecuteMoveStep_SendGoal_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event *>(message_memory);
  typed_message->~ExecuteMoveStep_SendGoal_Event();
}

size_t size_function__ExecuteMoveStep_SendGoal_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_SendGoal_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_SendGoal_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_SendGoal_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request *>(
    get_const_function__ExecuteMoveStep_SendGoal_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_SendGoal_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request *>(
    get_function__ExecuteMoveStep_SendGoal_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_SendGoal_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ExecuteMoveStep_SendGoal_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_SendGoal_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_SendGoal_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_SendGoal_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response *>(
    get_const_function__ExecuteMoveStep_SendGoal_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_SendGoal_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response *>(
    get_function__ExecuteMoveStep_SendGoal_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_SendGoal_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_SendGoal_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_SendGoal_Event__request,  // size() function pointer
    get_const_function__ExecuteMoveStep_SendGoal_Event__request,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_SendGoal_Event__request,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_SendGoal_Event__request,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_SendGoal_Event__request,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_SendGoal_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_SendGoal_Event__response,  // size() function pointer
    get_const_function__ExecuteMoveStep_SendGoal_Event__response,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_SendGoal_Event__response,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_SendGoal_Event__response,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_SendGoal_Event__response,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_SendGoal_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_SendGoal_Event_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_SendGoal_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event),
  false,  // has_any_key_member_
  ExecuteMoveStep_SendGoal_Event_message_member_array,  // message members
  ExecuteMoveStep_SendGoal_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_SendGoal_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_SendGoal_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Event__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Event__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal_Event)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_Event_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ExecuteMoveStep_SendGoal_service_members = {
  "robokpy_interfaces::action",  // service namespace
  "ExecuteMoveStep_SendGoal",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t ExecuteMoveStep_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_SendGoal_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_SendGoal_service_type_support_handle;
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
        ::robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::action::ExecuteMoveStep_SendGoal_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_SendGoal)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_SendGoal>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_GetResult_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request(_init);
}

void ExecuteMoveStep_GetResult_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request *>(message_memory);
  typed_message->~ExecuteMoveStep_GetResult_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_GetResult_Request_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request),
  false,  // has_any_key_member_
  ExecuteMoveStep_GetResult_Request_message_member_array,  // message members
  ExecuteMoveStep_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Request__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Request__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Request)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_Request_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_GetResult_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response(_init);
}

void ExecuteMoveStep_GetResult_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response *>(message_memory);
  typed_message->~ExecuteMoveStep_GetResult_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response, status),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "result",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Result>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response, result),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_GetResult_Response_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response),
  false,  // has_any_key_member_
  ExecuteMoveStep_GetResult_Response_message_member_array,  // message members
  ExecuteMoveStep_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Response__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Response__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Response)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_Response_message_type_support_handle;
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_GetResult_Event_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event(_init);
}

void ExecuteMoveStep_GetResult_Event_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event *>(message_memory);
  typed_message->~ExecuteMoveStep_GetResult_Event();
}

size_t size_function__ExecuteMoveStep_GetResult_Event__request(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_GetResult_Event__request(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_GetResult_Event__request(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_GetResult_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request *>(
    get_const_function__ExecuteMoveStep_GetResult_Event__request(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_GetResult_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request *>(
    get_function__ExecuteMoveStep_GetResult_Event__request(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_GetResult_Event__request(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ExecuteMoveStep_GetResult_Event__response(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ExecuteMoveStep_GetResult_Event__response(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response> *>(untyped_member);
  return &member[index];
}

void * get_function__ExecuteMoveStep_GetResult_Event__response(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response> *>(untyped_member);
  return &member[index];
}

void fetch_function__ExecuteMoveStep_GetResult_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response *>(
    get_const_function__ExecuteMoveStep_GetResult_Event__response(untyped_member, index));
  auto & value = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response *>(untyped_value);
  value = item;
}

void assign_function__ExecuteMoveStep_GetResult_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response *>(
    get_function__ExecuteMoveStep_GetResult_Event__response(untyped_member, index));
  const auto & value = *reinterpret_cast<const robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response *>(untyped_value);
  item = value;
}

void resize_function__ExecuteMoveStep_GetResult_Event__response(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_GetResult_Event_message_member_array[3] = {
  {
    "info",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<service_msgs::msg::ServiceEventInfo>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event, info),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event, request),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_GetResult_Event__request,  // size() function pointer
    get_const_function__ExecuteMoveStep_GetResult_Event__request,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_GetResult_Event__request,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_GetResult_Event__request,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_GetResult_Event__request,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_GetResult_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response>(),  // members of sub message
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event, response),  // bytes offset in struct
    nullptr,  // default value
    size_function__ExecuteMoveStep_GetResult_Event__response,  // size() function pointer
    get_const_function__ExecuteMoveStep_GetResult_Event__response,  // get_const(index) function pointer
    get_function__ExecuteMoveStep_GetResult_Event__response,  // get(index) function pointer
    fetch_function__ExecuteMoveStep_GetResult_Event__response,  // fetch(index, &value) function pointer
    assign_function__ExecuteMoveStep_GetResult_Event__response,  // assign(index, value) function pointer
    resize_function__ExecuteMoveStep_GetResult_Event__response  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_GetResult_Event_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_GetResult_Event",  // message name
  3,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event),
  false,  // has_any_key_member_
  ExecuteMoveStep_GetResult_Event_message_member_array,  // message members
  ExecuteMoveStep_GetResult_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_GetResult_Event_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_GetResult_Event_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Event__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Event__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_Event_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult_Event)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace robokpy_interfaces
{

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ExecuteMoveStep_GetResult_service_members = {
  "robokpy_interfaces::action",  // service namespace
  "ExecuteMoveStep_GetResult",  // service name
  // the following fields are initialized below on first access
  // see get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult>()
  nullptr,  // request message
  nullptr,  // response message
  nullptr,  // event message
};

static const rosidl_service_type_support_t ExecuteMoveStep_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_GetResult_service_members,
  get_service_typesupport_handle_function,
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response>(),
  ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<robokpy_interfaces::action::ExecuteMoveStep_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<robokpy_interfaces::action::ExecuteMoveStep_GetResult>,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_GetResult_service_type_support_handle;
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
        ::robokpy_interfaces::action::ExecuteMoveStep_GetResult_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::action::ExecuteMoveStep_GetResult_Response
      >()->data
      );
    // initialize the event_members_ with the static function from the external library
    service_members->event_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::robokpy_interfaces::action::ExecuteMoveStep_GetResult_Event
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_GetResult)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_GetResult>();
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
// #include "robokpy_interfaces/action/detail/execute_move_step__functions.h"
// already included above
// #include "robokpy_interfaces/action/detail/execute_move_step__struct.hpp"
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

namespace action
{

namespace rosidl_typesupport_introspection_cpp
{

void ExecuteMoveStep_FeedbackMessage_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage(_init);
}

void ExecuteMoveStep_FeedbackMessage_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage *>(message_memory);
  typed_message->~ExecuteMoveStep_FeedbackMessage();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ExecuteMoveStep_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<unique_identifier_msgs::msg::UUID>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage, goal_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "feedback",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_Feedback>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage, feedback),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ExecuteMoveStep_FeedbackMessage_message_members = {
  "robokpy_interfaces::action",  // message namespace
  "ExecuteMoveStep_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage),
  false,  // has_any_key_member_
  ExecuteMoveStep_FeedbackMessage_message_member_array,  // message members
  ExecuteMoveStep_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  ExecuteMoveStep_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ExecuteMoveStep_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ExecuteMoveStep_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
  &robokpy_interfaces__action__ExecuteMoveStep_FeedbackMessage__get_type_hash,
  &robokpy_interfaces__action__ExecuteMoveStep_FeedbackMessage__get_type_description,
  &robokpy_interfaces__action__ExecuteMoveStep_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace action

}  // namespace robokpy_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robokpy_interfaces::action::ExecuteMoveStep_FeedbackMessage>()
{
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_FeedbackMessage_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robokpy_interfaces, action, ExecuteMoveStep_FeedbackMessage)() {
  return &::robokpy_interfaces::action::rosidl_typesupport_introspection_cpp::ExecuteMoveStep_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
