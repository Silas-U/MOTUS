// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/ExecutionState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/execution_state.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__EXECUTION_STATE__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__EXECUTION_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/execution_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExecutionState_Request_new_state
{
public:
  Init_ExecutionState_Request_new_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robokpy_interfaces::srv::ExecutionState_Request new_state(::robokpy_interfaces::srv::ExecutionState_Request::_new_state_type arg)
  {
    msg_.new_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ExecutionState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ExecutionState_Request>()
{
  return robokpy_interfaces::srv::builder::Init_ExecutionState_Request_new_state();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExecutionState_Response_message
{
public:
  explicit Init_ExecutionState_Response_message(::robokpy_interfaces::srv::ExecutionState_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ExecutionState_Response message(::robokpy_interfaces::srv::ExecutionState_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ExecutionState_Response msg_;
};

class Init_ExecutionState_Response_success
{
public:
  Init_ExecutionState_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecutionState_Response_message success(::robokpy_interfaces::srv::ExecutionState_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecutionState_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::ExecutionState_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ExecutionState_Response>()
{
  return robokpy_interfaces::srv::builder::Init_ExecutionState_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExecutionState_Event_response
{
public:
  explicit Init_ExecutionState_Event_response(::robokpy_interfaces::srv::ExecutionState_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ExecutionState_Event response(::robokpy_interfaces::srv::ExecutionState_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ExecutionState_Event msg_;
};

class Init_ExecutionState_Event_request
{
public:
  explicit Init_ExecutionState_Event_request(::robokpy_interfaces::srv::ExecutionState_Event & msg)
  : msg_(msg)
  {}
  Init_ExecutionState_Event_response request(::robokpy_interfaces::srv::ExecutionState_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecutionState_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::ExecutionState_Event msg_;
};

class Init_ExecutionState_Event_info
{
public:
  Init_ExecutionState_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecutionState_Event_request info(::robokpy_interfaces::srv::ExecutionState_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecutionState_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::ExecutionState_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ExecutionState_Event>()
{
  return robokpy_interfaces::srv::builder::Init_ExecutionState_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__EXECUTION_STATE__BUILDER_HPP_
