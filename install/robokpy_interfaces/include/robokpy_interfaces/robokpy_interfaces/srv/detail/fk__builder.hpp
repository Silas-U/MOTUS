// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/FK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/fk.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__FK__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__FK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/fk__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_FK_Request_include_tf_tree
{
public:
  explicit Init_FK_Request_include_tf_tree(::robokpy_interfaces::srv::FK_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::FK_Request include_tf_tree(::robokpy_interfaces::srv::FK_Request::_include_tf_tree_type arg)
  {
    msg_.include_tf_tree = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Request msg_;
};

class Init_FK_Request_q
{
public:
  Init_FK_Request_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FK_Request_include_tf_tree q(::robokpy_interfaces::srv::FK_Request::_q_type arg)
  {
    msg_.q = std::move(arg);
    return Init_FK_Request_include_tf_tree(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::FK_Request>()
{
  return robokpy_interfaces::srv::builder::Init_FK_Request_q();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_FK_Response_message
{
public:
  explicit Init_FK_Response_message(::robokpy_interfaces::srv::FK_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::FK_Response message(::robokpy_interfaces::srv::FK_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Response msg_;
};

class Init_FK_Response_num_links
{
public:
  explicit Init_FK_Response_num_links(::robokpy_interfaces::srv::FK_Response & msg)
  : msg_(msg)
  {}
  Init_FK_Response_message num_links(::robokpy_interfaces::srv::FK_Response::_num_links_type arg)
  {
    msg_.num_links = std::move(arg);
    return Init_FK_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Response msg_;
};

class Init_FK_Response_tf_tree_flat
{
public:
  explicit Init_FK_Response_tf_tree_flat(::robokpy_interfaces::srv::FK_Response & msg)
  : msg_(msg)
  {}
  Init_FK_Response_num_links tf_tree_flat(::robokpy_interfaces::srv::FK_Response::_tf_tree_flat_type arg)
  {
    msg_.tf_tree_flat = std::move(arg);
    return Init_FK_Response_num_links(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Response msg_;
};

class Init_FK_Response_pose_euler
{
public:
  explicit Init_FK_Response_pose_euler(::robokpy_interfaces::srv::FK_Response & msg)
  : msg_(msg)
  {}
  Init_FK_Response_tf_tree_flat pose_euler(::robokpy_interfaces::srv::FK_Response::_pose_euler_type arg)
  {
    msg_.pose_euler = std::move(arg);
    return Init_FK_Response_tf_tree_flat(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Response msg_;
};

class Init_FK_Response_pose
{
public:
  explicit Init_FK_Response_pose(::robokpy_interfaces::srv::FK_Response & msg)
  : msg_(msg)
  {}
  Init_FK_Response_pose_euler pose(::robokpy_interfaces::srv::FK_Response::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_FK_Response_pose_euler(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Response msg_;
};

class Init_FK_Response_success
{
public:
  Init_FK_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FK_Response_pose success(::robokpy_interfaces::srv::FK_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_FK_Response_pose(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::FK_Response>()
{
  return robokpy_interfaces::srv::builder::Init_FK_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_FK_Event_response
{
public:
  explicit Init_FK_Event_response(::robokpy_interfaces::srv::FK_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::FK_Event response(::robokpy_interfaces::srv::FK_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Event msg_;
};

class Init_FK_Event_request
{
public:
  explicit Init_FK_Event_request(::robokpy_interfaces::srv::FK_Event & msg)
  : msg_(msg)
  {}
  Init_FK_Event_response request(::robokpy_interfaces::srv::FK_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_FK_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Event msg_;
};

class Init_FK_Event_info
{
public:
  Init_FK_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FK_Event_request info(::robokpy_interfaces::srv::FK_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_FK_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::FK_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::FK_Event>()
{
  return robokpy_interfaces::srv::builder::Init_FK_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__FK__BUILDER_HPP_
