// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/GraspAttach.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/grasp_attach.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/grasp_attach__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_GraspAttach_Request_joint_id
{
public:
  explicit Init_GraspAttach_Request_joint_id(::robokpy_interfaces::srv::GraspAttach_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::GraspAttach_Request joint_id(::robokpy_interfaces::srv::GraspAttach_Request::_joint_id_type arg)
  {
    msg_.joint_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Request msg_;
};

class Init_GraspAttach_Request_attach
{
public:
  explicit Init_GraspAttach_Request_attach(::robokpy_interfaces::srv::GraspAttach_Request & msg)
  : msg_(msg)
  {}
  Init_GraspAttach_Request_joint_id attach(::robokpy_interfaces::srv::GraspAttach_Request::_attach_type arg)
  {
    msg_.attach = std::move(arg);
    return Init_GraspAttach_Request_joint_id(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Request msg_;
};

class Init_GraspAttach_Request_child_link
{
public:
  explicit Init_GraspAttach_Request_child_link(::robokpy_interfaces::srv::GraspAttach_Request & msg)
  : msg_(msg)
  {}
  Init_GraspAttach_Request_attach child_link(::robokpy_interfaces::srv::GraspAttach_Request::_child_link_type arg)
  {
    msg_.child_link = std::move(arg);
    return Init_GraspAttach_Request_attach(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Request msg_;
};

class Init_GraspAttach_Request_child_model
{
public:
  explicit Init_GraspAttach_Request_child_model(::robokpy_interfaces::srv::GraspAttach_Request & msg)
  : msg_(msg)
  {}
  Init_GraspAttach_Request_child_link child_model(::robokpy_interfaces::srv::GraspAttach_Request::_child_model_type arg)
  {
    msg_.child_model = std::move(arg);
    return Init_GraspAttach_Request_child_link(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Request msg_;
};

class Init_GraspAttach_Request_parent_link
{
public:
  explicit Init_GraspAttach_Request_parent_link(::robokpy_interfaces::srv::GraspAttach_Request & msg)
  : msg_(msg)
  {}
  Init_GraspAttach_Request_child_model parent_link(::robokpy_interfaces::srv::GraspAttach_Request::_parent_link_type arg)
  {
    msg_.parent_link = std::move(arg);
    return Init_GraspAttach_Request_child_model(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Request msg_;
};

class Init_GraspAttach_Request_parent_model
{
public:
  Init_GraspAttach_Request_parent_model()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GraspAttach_Request_parent_link parent_model(::robokpy_interfaces::srv::GraspAttach_Request::_parent_model_type arg)
  {
    msg_.parent_model = std::move(arg);
    return Init_GraspAttach_Request_parent_link(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::GraspAttach_Request>()
{
  return robokpy_interfaces::srv::builder::Init_GraspAttach_Request_parent_model();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_GraspAttach_Response_joint_id
{
public:
  explicit Init_GraspAttach_Response_joint_id(::robokpy_interfaces::srv::GraspAttach_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::GraspAttach_Response joint_id(::robokpy_interfaces::srv::GraspAttach_Response::_joint_id_type arg)
  {
    msg_.joint_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Response msg_;
};

class Init_GraspAttach_Response_message
{
public:
  explicit Init_GraspAttach_Response_message(::robokpy_interfaces::srv::GraspAttach_Response & msg)
  : msg_(msg)
  {}
  Init_GraspAttach_Response_joint_id message(::robokpy_interfaces::srv::GraspAttach_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GraspAttach_Response_joint_id(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Response msg_;
};

class Init_GraspAttach_Response_success
{
public:
  Init_GraspAttach_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GraspAttach_Response_message success(::robokpy_interfaces::srv::GraspAttach_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GraspAttach_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::GraspAttach_Response>()
{
  return robokpy_interfaces::srv::builder::Init_GraspAttach_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_GraspAttach_Event_response
{
public:
  explicit Init_GraspAttach_Event_response(::robokpy_interfaces::srv::GraspAttach_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::GraspAttach_Event response(::robokpy_interfaces::srv::GraspAttach_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Event msg_;
};

class Init_GraspAttach_Event_request
{
public:
  explicit Init_GraspAttach_Event_request(::robokpy_interfaces::srv::GraspAttach_Event & msg)
  : msg_(msg)
  {}
  Init_GraspAttach_Event_response request(::robokpy_interfaces::srv::GraspAttach_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GraspAttach_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Event msg_;
};

class Init_GraspAttach_Event_info
{
public:
  Init_GraspAttach_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GraspAttach_Event_request info(::robokpy_interfaces::srv::GraspAttach_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GraspAttach_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::GraspAttach_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::GraspAttach_Event>()
{
  return robokpy_interfaces::srv::builder::Init_GraspAttach_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__BUILDER_HPP_
