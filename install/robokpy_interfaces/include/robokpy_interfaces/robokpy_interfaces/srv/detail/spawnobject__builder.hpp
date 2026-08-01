// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/Spawnobject.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/spawnobject.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__SPAWNOBJECT__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__SPAWNOBJECT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/spawnobject__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_Spawnobject_Request_qw
{
public:
  explicit Init_Spawnobject_Request_qw(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::Spawnobject_Request qw(::robokpy_interfaces::srv::Spawnobject_Request::_qw_type arg)
  {
    msg_.qw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_qz
{
public:
  explicit Init_Spawnobject_Request_qz(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Request_qw qz(::robokpy_interfaces::srv::Spawnobject_Request::_qz_type arg)
  {
    msg_.qz = std::move(arg);
    return Init_Spawnobject_Request_qw(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_qy
{
public:
  explicit Init_Spawnobject_Request_qy(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Request_qz qy(::robokpy_interfaces::srv::Spawnobject_Request::_qy_type arg)
  {
    msg_.qy = std::move(arg);
    return Init_Spawnobject_Request_qz(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_qx
{
public:
  explicit Init_Spawnobject_Request_qx(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Request_qy qx(::robokpy_interfaces::srv::Spawnobject_Request::_qx_type arg)
  {
    msg_.qx = std::move(arg);
    return Init_Spawnobject_Request_qy(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_z
{
public:
  explicit Init_Spawnobject_Request_z(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Request_qx z(::robokpy_interfaces::srv::Spawnobject_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Spawnobject_Request_qx(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_y
{
public:
  explicit Init_Spawnobject_Request_y(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Request_z y(::robokpy_interfaces::srv::Spawnobject_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Spawnobject_Request_z(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_x
{
public:
  explicit Init_Spawnobject_Request_x(::robokpy_interfaces::srv::Spawnobject_Request & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Request_y x(::robokpy_interfaces::srv::Spawnobject_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Spawnobject_Request_y(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

class Init_Spawnobject_Request_type_id
{
public:
  Init_Spawnobject_Request_type_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spawnobject_Request_x type_id(::robokpy_interfaces::srv::Spawnobject_Request::_type_id_type arg)
  {
    msg_.type_id = std::move(arg);
    return Init_Spawnobject_Request_x(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::Spawnobject_Request>()
{
  return robokpy_interfaces::srv::builder::Init_Spawnobject_Request_type_id();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_Spawnobject_Response_child_model
{
public:
  explicit Init_Spawnobject_Response_child_model(::robokpy_interfaces::srv::Spawnobject_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::Spawnobject_Response child_model(::robokpy_interfaces::srv::Spawnobject_Response::_child_model_type arg)
  {
    msg_.child_model = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Response msg_;
};

class Init_Spawnobject_Response_message
{
public:
  explicit Init_Spawnobject_Response_message(::robokpy_interfaces::srv::Spawnobject_Response & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Response_child_model message(::robokpy_interfaces::srv::Spawnobject_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_Spawnobject_Response_child_model(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Response msg_;
};

class Init_Spawnobject_Response_success
{
public:
  Init_Spawnobject_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spawnobject_Response_message success(::robokpy_interfaces::srv::Spawnobject_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Spawnobject_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::Spawnobject_Response>()
{
  return robokpy_interfaces::srv::builder::Init_Spawnobject_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_Spawnobject_Event_response
{
public:
  explicit Init_Spawnobject_Event_response(::robokpy_interfaces::srv::Spawnobject_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::Spawnobject_Event response(::robokpy_interfaces::srv::Spawnobject_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Event msg_;
};

class Init_Spawnobject_Event_request
{
public:
  explicit Init_Spawnobject_Event_request(::robokpy_interfaces::srv::Spawnobject_Event & msg)
  : msg_(msg)
  {}
  Init_Spawnobject_Event_response request(::robokpy_interfaces::srv::Spawnobject_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Spawnobject_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Event msg_;
};

class Init_Spawnobject_Event_info
{
public:
  Init_Spawnobject_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Spawnobject_Event_request info(::robokpy_interfaces::srv::Spawnobject_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Spawnobject_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::Spawnobject_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::Spawnobject_Event>()
{
  return robokpy_interfaces::srv::builder::Init_Spawnobject_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__SPAWNOBJECT__BUILDER_HPP_
