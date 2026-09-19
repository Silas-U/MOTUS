// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mycobot_pro450_interfaces:msg/MycobotGripperStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mycobot_pro450_interfaces/msg/mycobot_gripper_status.hpp"


#ifndef MYCOBOT_PRO450_INTERFACES__MSG__DETAIL__MYCOBOT_GRIPPER_STATUS__BUILDER_HPP_
#define MYCOBOT_PRO450_INTERFACES__MSG__DETAIL__MYCOBOT_GRIPPER_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mycobot_pro450_interfaces/msg/detail/mycobot_gripper_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mycobot_pro450_interfaces
{

namespace msg
{

namespace builder
{

class Init_MycobotGripperStatus_status
{
public:
  Init_MycobotGripperStatus_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mycobot_pro450_interfaces::msg::MycobotGripperStatus status(::mycobot_pro450_interfaces::msg::MycobotGripperStatus::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_pro450_interfaces::msg::MycobotGripperStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_pro450_interfaces::msg::MycobotGripperStatus>()
{
  return mycobot_pro450_interfaces::msg::builder::Init_MycobotGripperStatus_status();
}

}  // namespace mycobot_pro450_interfaces

#endif  // MYCOBOT_PRO450_INTERFACES__MSG__DETAIL__MYCOBOT_GRIPPER_STATUS__BUILDER_HPP_
