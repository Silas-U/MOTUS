// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mycobot_pro450_interfaces:srv/GetGripperValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mycobot_pro450_interfaces/srv/get_gripper_value.hpp"


#ifndef MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__BUILDER_HPP_
#define MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mycobot_pro450_interfaces/srv/detail/get_gripper_value__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mycobot_pro450_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_pro450_interfaces::srv::GetGripperValue_Request>()
{
  return ::mycobot_pro450_interfaces::srv::GetGripperValue_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace mycobot_pro450_interfaces


namespace mycobot_pro450_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetGripperValue_Response_gripper_angle
{
public:
  Init_GetGripperValue_Response_gripper_angle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mycobot_pro450_interfaces::srv::GetGripperValue_Response gripper_angle(::mycobot_pro450_interfaces::srv::GetGripperValue_Response::_gripper_angle_type arg)
  {
    msg_.gripper_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_pro450_interfaces::srv::GetGripperValue_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_pro450_interfaces::srv::GetGripperValue_Response>()
{
  return mycobot_pro450_interfaces::srv::builder::Init_GetGripperValue_Response_gripper_angle();
}

}  // namespace mycobot_pro450_interfaces


namespace mycobot_pro450_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetGripperValue_Event_response
{
public:
  explicit Init_GetGripperValue_Event_response(::mycobot_pro450_interfaces::srv::GetGripperValue_Event & msg)
  : msg_(msg)
  {}
  ::mycobot_pro450_interfaces::srv::GetGripperValue_Event response(::mycobot_pro450_interfaces::srv::GetGripperValue_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mycobot_pro450_interfaces::srv::GetGripperValue_Event msg_;
};

class Init_GetGripperValue_Event_request
{
public:
  explicit Init_GetGripperValue_Event_request(::mycobot_pro450_interfaces::srv::GetGripperValue_Event & msg)
  : msg_(msg)
  {}
  Init_GetGripperValue_Event_response request(::mycobot_pro450_interfaces::srv::GetGripperValue_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetGripperValue_Event_response(msg_);
  }

private:
  ::mycobot_pro450_interfaces::srv::GetGripperValue_Event msg_;
};

class Init_GetGripperValue_Event_info
{
public:
  Init_GetGripperValue_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetGripperValue_Event_request info(::mycobot_pro450_interfaces::srv::GetGripperValue_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetGripperValue_Event_request(msg_);
  }

private:
  ::mycobot_pro450_interfaces::srv::GetGripperValue_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mycobot_pro450_interfaces::srv::GetGripperValue_Event>()
{
  return mycobot_pro450_interfaces::srv::builder::Init_GetGripperValue_Event_info();
}

}  // namespace mycobot_pro450_interfaces

#endif  // MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__BUILDER_HPP_
