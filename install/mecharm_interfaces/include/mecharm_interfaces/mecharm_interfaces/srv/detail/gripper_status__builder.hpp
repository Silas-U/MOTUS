// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mecharm_interfaces:srv/GripperStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mecharm_interfaces/srv/gripper_status.hpp"


#ifndef MECHARM_INTERFACES__SRV__DETAIL__GRIPPER_STATUS__BUILDER_HPP_
#define MECHARM_INTERFACES__SRV__DETAIL__GRIPPER_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mecharm_interfaces/srv/detail/gripper_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mecharm_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperStatus_Request_status
{
public:
  Init_GripperStatus_Request_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mecharm_interfaces::srv::GripperStatus_Request status(::mecharm_interfaces::srv::GripperStatus_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mecharm_interfaces::srv::GripperStatus_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mecharm_interfaces::srv::GripperStatus_Request>()
{
  return mecharm_interfaces::srv::builder::Init_GripperStatus_Request_status();
}

}  // namespace mecharm_interfaces


namespace mecharm_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperStatus_Response_flag
{
public:
  Init_GripperStatus_Response_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mecharm_interfaces::srv::GripperStatus_Response flag(::mecharm_interfaces::srv::GripperStatus_Response::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mecharm_interfaces::srv::GripperStatus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mecharm_interfaces::srv::GripperStatus_Response>()
{
  return mecharm_interfaces::srv::builder::Init_GripperStatus_Response_flag();
}

}  // namespace mecharm_interfaces


namespace mecharm_interfaces
{

namespace srv
{

namespace builder
{

class Init_GripperStatus_Event_response
{
public:
  explicit Init_GripperStatus_Event_response(::mecharm_interfaces::srv::GripperStatus_Event & msg)
  : msg_(msg)
  {}
  ::mecharm_interfaces::srv::GripperStatus_Event response(::mecharm_interfaces::srv::GripperStatus_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mecharm_interfaces::srv::GripperStatus_Event msg_;
};

class Init_GripperStatus_Event_request
{
public:
  explicit Init_GripperStatus_Event_request(::mecharm_interfaces::srv::GripperStatus_Event & msg)
  : msg_(msg)
  {}
  Init_GripperStatus_Event_response request(::mecharm_interfaces::srv::GripperStatus_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GripperStatus_Event_response(msg_);
  }

private:
  ::mecharm_interfaces::srv::GripperStatus_Event msg_;
};

class Init_GripperStatus_Event_info
{
public:
  Init_GripperStatus_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GripperStatus_Event_request info(::mecharm_interfaces::srv::GripperStatus_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GripperStatus_Event_request(msg_);
  }

private:
  ::mecharm_interfaces::srv::GripperStatus_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mecharm_interfaces::srv::GripperStatus_Event>()
{
  return mecharm_interfaces::srv::builder::Init_GripperStatus_Event_info();
}

}  // namespace mecharm_interfaces

#endif  // MECHARM_INTERFACES__SRV__DETAIL__GRIPPER_STATUS__BUILDER_HPP_
