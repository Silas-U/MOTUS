// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/ResolveObjectPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/resolve_object_pose.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/resolve_object_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResolveObjectPose_Request_max_distance
{
public:
  explicit Init_ResolveObjectPose_Request_max_distance(::robokpy_interfaces::srv::ResolveObjectPose_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ResolveObjectPose_Request max_distance(::robokpy_interfaces::srv::ResolveObjectPose_Request::_max_distance_type arg)
  {
    msg_.max_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Request msg_;
};

class Init_ResolveObjectPose_Request_z
{
public:
  explicit Init_ResolveObjectPose_Request_z(::robokpy_interfaces::srv::ResolveObjectPose_Request & msg)
  : msg_(msg)
  {}
  Init_ResolveObjectPose_Request_max_distance z(::robokpy_interfaces::srv::ResolveObjectPose_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_ResolveObjectPose_Request_max_distance(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Request msg_;
};

class Init_ResolveObjectPose_Request_y
{
public:
  explicit Init_ResolveObjectPose_Request_y(::robokpy_interfaces::srv::ResolveObjectPose_Request & msg)
  : msg_(msg)
  {}
  Init_ResolveObjectPose_Request_z y(::robokpy_interfaces::srv::ResolveObjectPose_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ResolveObjectPose_Request_z(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Request msg_;
};

class Init_ResolveObjectPose_Request_x
{
public:
  Init_ResolveObjectPose_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResolveObjectPose_Request_y x(::robokpy_interfaces::srv::ResolveObjectPose_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ResolveObjectPose_Request_y(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ResolveObjectPose_Request>()
{
  return robokpy_interfaces::srv::builder::Init_ResolveObjectPose_Request_x();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResolveObjectPose_Response_message
{
public:
  explicit Init_ResolveObjectPose_Response_message(::robokpy_interfaces::srv::ResolveObjectPose_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ResolveObjectPose_Response message(::robokpy_interfaces::srv::ResolveObjectPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Response msg_;
};

class Init_ResolveObjectPose_Response_distance
{
public:
  explicit Init_ResolveObjectPose_Response_distance(::robokpy_interfaces::srv::ResolveObjectPose_Response & msg)
  : msg_(msg)
  {}
  Init_ResolveObjectPose_Response_message distance(::robokpy_interfaces::srv::ResolveObjectPose_Response::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_ResolveObjectPose_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Response msg_;
};

class Init_ResolveObjectPose_Response_child_link
{
public:
  explicit Init_ResolveObjectPose_Response_child_link(::robokpy_interfaces::srv::ResolveObjectPose_Response & msg)
  : msg_(msg)
  {}
  Init_ResolveObjectPose_Response_distance child_link(::robokpy_interfaces::srv::ResolveObjectPose_Response::_child_link_type arg)
  {
    msg_.child_link = std::move(arg);
    return Init_ResolveObjectPose_Response_distance(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Response msg_;
};

class Init_ResolveObjectPose_Response_child_model
{
public:
  explicit Init_ResolveObjectPose_Response_child_model(::robokpy_interfaces::srv::ResolveObjectPose_Response & msg)
  : msg_(msg)
  {}
  Init_ResolveObjectPose_Response_child_link child_model(::robokpy_interfaces::srv::ResolveObjectPose_Response::_child_model_type arg)
  {
    msg_.child_model = std::move(arg);
    return Init_ResolveObjectPose_Response_child_link(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Response msg_;
};

class Init_ResolveObjectPose_Response_success
{
public:
  Init_ResolveObjectPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResolveObjectPose_Response_child_model success(::robokpy_interfaces::srv::ResolveObjectPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ResolveObjectPose_Response_child_model(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ResolveObjectPose_Response>()
{
  return robokpy_interfaces::srv::builder::Init_ResolveObjectPose_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_ResolveObjectPose_Event_response
{
public:
  explicit Init_ResolveObjectPose_Event_response(::robokpy_interfaces::srv::ResolveObjectPose_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::ResolveObjectPose_Event response(::robokpy_interfaces::srv::ResolveObjectPose_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Event msg_;
};

class Init_ResolveObjectPose_Event_request
{
public:
  explicit Init_ResolveObjectPose_Event_request(::robokpy_interfaces::srv::ResolveObjectPose_Event & msg)
  : msg_(msg)
  {}
  Init_ResolveObjectPose_Event_response request(::robokpy_interfaces::srv::ResolveObjectPose_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ResolveObjectPose_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Event msg_;
};

class Init_ResolveObjectPose_Event_info
{
public:
  Init_ResolveObjectPose_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ResolveObjectPose_Event_request info(::robokpy_interfaces::srv::ResolveObjectPose_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ResolveObjectPose_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::ResolveObjectPose_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::ResolveObjectPose_Event>()
{
  return robokpy_interfaces::srv::builder::Init_ResolveObjectPose_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__BUILDER_HPP_
