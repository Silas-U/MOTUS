// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/IK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/ik.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__IK__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__IK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/ik__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_IK_Request_max_iter
{
public:
  explicit Init_IK_Request_max_iter(::robokpy_interfaces::srv::IK_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::IK_Request max_iter(::robokpy_interfaces::srv::IK_Request::_max_iter_type arg)
  {
    msg_.max_iter = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Request msg_;
};

class Init_IK_Request_tol
{
public:
  explicit Init_IK_Request_tol(::robokpy_interfaces::srv::IK_Request & msg)
  : msg_(msg)
  {}
  Init_IK_Request_max_iter tol(::robokpy_interfaces::srv::IK_Request::_tol_type arg)
  {
    msg_.tol = std::move(arg);
    return Init_IK_Request_max_iter(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Request msg_;
};

class Init_IK_Request_seed
{
public:
  explicit Init_IK_Request_seed(::robokpy_interfaces::srv::IK_Request & msg)
  : msg_(msg)
  {}
  Init_IK_Request_tol seed(::robokpy_interfaces::srv::IK_Request::_seed_type arg)
  {
    msg_.seed = std::move(arg);
    return Init_IK_Request_tol(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Request msg_;
};

class Init_IK_Request_mask
{
public:
  explicit Init_IK_Request_mask(::robokpy_interfaces::srv::IK_Request & msg)
  : msg_(msg)
  {}
  Init_IK_Request_seed mask(::robokpy_interfaces::srv::IK_Request::_mask_type arg)
  {
    msg_.mask = std::move(arg);
    return Init_IK_Request_seed(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Request msg_;
};

class Init_IK_Request_target_pose
{
public:
  Init_IK_Request_target_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IK_Request_mask target_pose(::robokpy_interfaces::srv::IK_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_IK_Request_mask(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::IK_Request>()
{
  return robokpy_interfaces::srv::builder::Init_IK_Request_target_pose();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_IK_Response_message
{
public:
  explicit Init_IK_Response_message(::robokpy_interfaces::srv::IK_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::IK_Response message(::robokpy_interfaces::srv::IK_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Response msg_;
};

class Init_IK_Response_error
{
public:
  explicit Init_IK_Response_error(::robokpy_interfaces::srv::IK_Response & msg)
  : msg_(msg)
  {}
  Init_IK_Response_message error(::robokpy_interfaces::srv::IK_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return Init_IK_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Response msg_;
};

class Init_IK_Response_q
{
public:
  explicit Init_IK_Response_q(::robokpy_interfaces::srv::IK_Response & msg)
  : msg_(msg)
  {}
  Init_IK_Response_error q(::robokpy_interfaces::srv::IK_Response::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_IK_Response_error(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Response msg_;
};

class Init_IK_Response_success
{
public:
  Init_IK_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IK_Response_q success(::robokpy_interfaces::srv::IK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_IK_Response_q(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::IK_Response>()
{
  return robokpy_interfaces::srv::builder::Init_IK_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_IK_Event_response
{
public:
  explicit Init_IK_Event_response(::robokpy_interfaces::srv::IK_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::IK_Event response(::robokpy_interfaces::srv::IK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Event msg_;
};

class Init_IK_Event_request
{
public:
  explicit Init_IK_Event_request(::robokpy_interfaces::srv::IK_Event & msg)
  : msg_(msg)
  {}
  Init_IK_Event_response request(::robokpy_interfaces::srv::IK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_IK_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Event msg_;
};

class Init_IK_Event_info
{
public:
  Init_IK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IK_Event_request info(::robokpy_interfaces::srv::IK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_IK_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::IK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::IK_Event>()
{
  return robokpy_interfaces::srv::builder::Init_IK_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__IK__BUILDER_HPP_
