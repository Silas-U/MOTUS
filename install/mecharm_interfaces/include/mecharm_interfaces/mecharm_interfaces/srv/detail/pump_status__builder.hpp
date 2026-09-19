// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mecharm_interfaces:srv/PumpStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mecharm_interfaces/srv/pump_status.hpp"


#ifndef MECHARM_INTERFACES__SRV__DETAIL__PUMP_STATUS__BUILDER_HPP_
#define MECHARM_INTERFACES__SRV__DETAIL__PUMP_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mecharm_interfaces/srv/detail/pump_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mecharm_interfaces
{

namespace srv
{

namespace builder
{

class Init_PumpStatus_Request_pin2
{
public:
  explicit Init_PumpStatus_Request_pin2(::mecharm_interfaces::srv::PumpStatus_Request & msg)
  : msg_(msg)
  {}
  ::mecharm_interfaces::srv::PumpStatus_Request pin2(::mecharm_interfaces::srv::PumpStatus_Request::_pin2_type arg)
  {
    msg_.pin2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Request msg_;
};

class Init_PumpStatus_Request_pin1
{
public:
  explicit Init_PumpStatus_Request_pin1(::mecharm_interfaces::srv::PumpStatus_Request & msg)
  : msg_(msg)
  {}
  Init_PumpStatus_Request_pin2 pin1(::mecharm_interfaces::srv::PumpStatus_Request::_pin1_type arg)
  {
    msg_.pin1 = std::move(arg);
    return Init_PumpStatus_Request_pin2(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Request msg_;
};

class Init_PumpStatus_Request_status
{
public:
  Init_PumpStatus_Request_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PumpStatus_Request_pin1 status(::mecharm_interfaces::srv::PumpStatus_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_PumpStatus_Request_pin1(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mecharm_interfaces::srv::PumpStatus_Request>()
{
  return mecharm_interfaces::srv::builder::Init_PumpStatus_Request_status();
}

}  // namespace mecharm_interfaces


namespace mecharm_interfaces
{

namespace srv
{

namespace builder
{

class Init_PumpStatus_Response_flag
{
public:
  Init_PumpStatus_Response_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mecharm_interfaces::srv::PumpStatus_Response flag(::mecharm_interfaces::srv::PumpStatus_Response::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mecharm_interfaces::srv::PumpStatus_Response>()
{
  return mecharm_interfaces::srv::builder::Init_PumpStatus_Response_flag();
}

}  // namespace mecharm_interfaces


namespace mecharm_interfaces
{

namespace srv
{

namespace builder
{

class Init_PumpStatus_Event_response
{
public:
  explicit Init_PumpStatus_Event_response(::mecharm_interfaces::srv::PumpStatus_Event & msg)
  : msg_(msg)
  {}
  ::mecharm_interfaces::srv::PumpStatus_Event response(::mecharm_interfaces::srv::PumpStatus_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Event msg_;
};

class Init_PumpStatus_Event_request
{
public:
  explicit Init_PumpStatus_Event_request(::mecharm_interfaces::srv::PumpStatus_Event & msg)
  : msg_(msg)
  {}
  Init_PumpStatus_Event_response request(::mecharm_interfaces::srv::PumpStatus_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PumpStatus_Event_response(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Event msg_;
};

class Init_PumpStatus_Event_info
{
public:
  Init_PumpStatus_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PumpStatus_Event_request info(::mecharm_interfaces::srv::PumpStatus_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PumpStatus_Event_request(msg_);
  }

private:
  ::mecharm_interfaces::srv::PumpStatus_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mecharm_interfaces::srv::PumpStatus_Event>()
{
  return mecharm_interfaces::srv::builder::Init_PumpStatus_Event_info();
}

}  // namespace mecharm_interfaces

#endif  // MECHARM_INTERFACES__SRV__DETAIL__PUMP_STATUS__BUILDER_HPP_
