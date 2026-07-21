// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/ChainFK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/chain_fk.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/chain_fk__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ChainFK_Request_end_link
{
public:
  explicit Init_ChainFK_Request_end_link(::robokpy_interfaces::srv::ChainFK_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ChainFK_Request end_link(::robokpy_interfaces::srv::ChainFK_Request::_end_link_type arg)
  {
    msg_.end_link = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Request msg_;
};

class Init_ChainFK_Request_base_link
{
public:
  explicit Init_ChainFK_Request_base_link(::robokpy_interfaces::srv::ChainFK_Request & msg)
  : msg_(msg)
  {}
  Init_ChainFK_Request_end_link base_link(::robokpy_interfaces::srv::ChainFK_Request::_base_link_type arg)
  {
    msg_.base_link = std::move(arg);
    return Init_ChainFK_Request_end_link(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Request msg_;
};

class Init_ChainFK_Request_q
{
public:
  Init_ChainFK_Request_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChainFK_Request_base_link q(::robokpy_interfaces::srv::ChainFK_Request::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_ChainFK_Request_base_link(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ChainFK_Request>()
{
  return robokpy_interfaces::srv::builder::Init_ChainFK_Request_q();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ChainFK_Response_message
{
public:
  explicit Init_ChainFK_Response_message(::robokpy_interfaces::srv::ChainFK_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ChainFK_Response message(::robokpy_interfaces::srv::ChainFK_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Response msg_;
};

class Init_ChainFK_Response_pose_euler
{
public:
  explicit Init_ChainFK_Response_pose_euler(::robokpy_interfaces::srv::ChainFK_Response & msg)
  : msg_(msg)
  {}
  Init_ChainFK_Response_message pose_euler(::robokpy_interfaces::srv::ChainFK_Response::_pose_euler_type arg)
  {
    msg_.pose_euler = std::move(arg);
    return Init_ChainFK_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Response msg_;
};

class Init_ChainFK_Response_pose
{
public:
  explicit Init_ChainFK_Response_pose(::robokpy_interfaces::srv::ChainFK_Response & msg)
  : msg_(msg)
  {}
  Init_ChainFK_Response_pose_euler pose(::robokpy_interfaces::srv::ChainFK_Response::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_ChainFK_Response_pose_euler(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Response msg_;
};

class Init_ChainFK_Response_success
{
public:
  Init_ChainFK_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChainFK_Response_pose success(::robokpy_interfaces::srv::ChainFK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ChainFK_Response_pose(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ChainFK_Response>()
{
  return robokpy_interfaces::srv::builder::Init_ChainFK_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ChainFK_Event_response
{
public:
  explicit Init_ChainFK_Event_response(::robokpy_interfaces::srv::ChainFK_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ChainFK_Event response(::robokpy_interfaces::srv::ChainFK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Event msg_;
};

class Init_ChainFK_Event_request
{
public:
  explicit Init_ChainFK_Event_request(::robokpy_interfaces::srv::ChainFK_Event & msg)
  : msg_(msg)
  {}
  Init_ChainFK_Event_response request(::robokpy_interfaces::srv::ChainFK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ChainFK_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Event msg_;
};

class Init_ChainFK_Event_info
{
public:
  Init_ChainFK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ChainFK_Event_request info(::robokpy_interfaces::srv::ChainFK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ChainFK_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::ChainFK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ChainFK_Event>()
{
  return robokpy_interfaces::srv::builder::Init_ChainFK_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__BUILDER_HPP_
