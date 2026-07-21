// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/SystemMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/system_mode.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__SYSTEM_MODE__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__SYSTEM_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/system_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_SystemMode_Request_new_mode
{
public:
  Init_SystemMode_Request_new_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robokpy_interfaces::srv::SystemMode_Request new_mode(::robokpy_interfaces::srv::SystemMode_Request::_new_mode_type arg)
  {
    msg_.new_mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::SystemMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::SystemMode_Request>()
{
  return robokpy_interfaces::srv::builder::Init_SystemMode_Request_new_mode();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_SystemMode_Response_message
{
public:
  explicit Init_SystemMode_Response_message(::robokpy_interfaces::srv::SystemMode_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::SystemMode_Response message(::robokpy_interfaces::srv::SystemMode_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::SystemMode_Response msg_;
};

class Init_SystemMode_Response_success
{
public:
  Init_SystemMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemMode_Response_message success(::robokpy_interfaces::srv::SystemMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SystemMode_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::SystemMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::SystemMode_Response>()
{
  return robokpy_interfaces::srv::builder::Init_SystemMode_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_SystemMode_Event_response
{
public:
  explicit Init_SystemMode_Event_response(::robokpy_interfaces::srv::SystemMode_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::SystemMode_Event response(::robokpy_interfaces::srv::SystemMode_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::SystemMode_Event msg_;
};

class Init_SystemMode_Event_request
{
public:
  explicit Init_SystemMode_Event_request(::robokpy_interfaces::srv::SystemMode_Event & msg)
  : msg_(msg)
  {}
  Init_SystemMode_Event_response request(::robokpy_interfaces::srv::SystemMode_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SystemMode_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::SystemMode_Event msg_;
};

class Init_SystemMode_Event_info
{
public:
  Init_SystemMode_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SystemMode_Event_request info(::robokpy_interfaces::srv::SystemMode_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SystemMode_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::SystemMode_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::SystemMode_Event>()
{
  return robokpy_interfaces::srv::builder::Init_SystemMode_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__SYSTEM_MODE__BUILDER_HPP_
