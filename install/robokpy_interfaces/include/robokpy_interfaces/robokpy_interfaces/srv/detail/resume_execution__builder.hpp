// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/ResumeExecution.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/resume_execution.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__RESUME_EXECUTION__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__RESUME_EXECUTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/resume_execution__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResumeExecution_Request_proceed
{
public:
  explicit Init_ResumeExecution_Request_proceed(::robokpy_interfaces::srv::ResumeExecution_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ResumeExecution_Request proceed(::robokpy_interfaces::srv::ResumeExecution_Request::_proceed_type arg)
  {
    msg_.proceed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Request msg_;
};

class Init_ResumeExecution_Request_step_id
{
public:
  Init_ResumeExecution_Request_step_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResumeExecution_Request_proceed step_id(::robokpy_interfaces::srv::ResumeExecution_Request::_step_id_type arg)
  {
    msg_.step_id = std::move(arg);
    return Init_ResumeExecution_Request_proceed(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ResumeExecution_Request>()
{
  return robokpy_interfaces::srv::builder::Init_ResumeExecution_Request_step_id();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResumeExecution_Response_message
{
public:
  explicit Init_ResumeExecution_Response_message(::robokpy_interfaces::srv::ResumeExecution_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ResumeExecution_Response message(::robokpy_interfaces::srv::ResumeExecution_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Response msg_;
};

class Init_ResumeExecution_Response_accepted
{
public:
  Init_ResumeExecution_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResumeExecution_Response_message accepted(::robokpy_interfaces::srv::ResumeExecution_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ResumeExecution_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ResumeExecution_Response>()
{
  return robokpy_interfaces::srv::builder::Init_ResumeExecution_Response_accepted();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResumeExecution_Event_response
{
public:
  explicit Init_ResumeExecution_Event_response(::robokpy_interfaces::srv::ResumeExecution_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ResumeExecution_Event response(::robokpy_interfaces::srv::ResumeExecution_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Event msg_;
};

class Init_ResumeExecution_Event_request
{
public:
  explicit Init_ResumeExecution_Event_request(::robokpy_interfaces::srv::ResumeExecution_Event & msg)
  : msg_(msg)
  {}
  Init_ResumeExecution_Event_response request(::robokpy_interfaces::srv::ResumeExecution_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ResumeExecution_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Event msg_;
};

class Init_ResumeExecution_Event_info
{
public:
  Init_ResumeExecution_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResumeExecution_Event_request info(::robokpy_interfaces::srv::ResumeExecution_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ResumeExecution_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResumeExecution_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ResumeExecution_Event>()
{
  return robokpy_interfaces::srv::builder::Init_ResumeExecution_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__RESUME_EXECUTION__BUILDER_HPP_
