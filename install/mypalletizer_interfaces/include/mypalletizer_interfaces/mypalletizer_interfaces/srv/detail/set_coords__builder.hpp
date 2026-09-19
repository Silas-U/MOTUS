// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mypalletizer_interfaces:srv/SetCoords.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mypalletizer_interfaces/srv/set_coords.hpp"


#ifndef MYPALLETIZER_INTERFACES__SRV__DETAIL__SET_COORDS__BUILDER_HPP_
#define MYPALLETIZER_INTERFACES__SRV__DETAIL__SET_COORDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mypalletizer_interfaces/srv/detail/set_coords__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mypalletizer_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetCoords_Request_speed
{
public:
  explicit Init_SetCoords_Request_speed(::mypalletizer_interfaces::srv::SetCoords_Request & msg)
  : msg_(msg)
  {}
  ::mypalletizer_interfaces::srv::SetCoords_Request speed(::mypalletizer_interfaces::srv::SetCoords_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Request msg_;
};

class Init_SetCoords_Request_rx
{
public:
  explicit Init_SetCoords_Request_rx(::mypalletizer_interfaces::srv::SetCoords_Request & msg)
  : msg_(msg)
  {}
  Init_SetCoords_Request_speed rx(::mypalletizer_interfaces::srv::SetCoords_Request::_rx_type arg)
  {
    msg_.rx = std::move(arg);
    return Init_SetCoords_Request_speed(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Request msg_;
};

class Init_SetCoords_Request_z
{
public:
  explicit Init_SetCoords_Request_z(::mypalletizer_interfaces::srv::SetCoords_Request & msg)
  : msg_(msg)
  {}
  Init_SetCoords_Request_rx z(::mypalletizer_interfaces::srv::SetCoords_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_SetCoords_Request_rx(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Request msg_;
};

class Init_SetCoords_Request_y
{
public:
  explicit Init_SetCoords_Request_y(::mypalletizer_interfaces::srv::SetCoords_Request & msg)
  : msg_(msg)
  {}
  Init_SetCoords_Request_z y(::mypalletizer_interfaces::srv::SetCoords_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SetCoords_Request_z(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Request msg_;
};

class Init_SetCoords_Request_x
{
public:
  Init_SetCoords_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCoords_Request_y x(::mypalletizer_interfaces::srv::SetCoords_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SetCoords_Request_y(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mypalletizer_interfaces::srv::SetCoords_Request>()
{
  return mypalletizer_interfaces::srv::builder::Init_SetCoords_Request_x();
}

}  // namespace mypalletizer_interfaces


namespace mypalletizer_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetCoords_Response_flag
{
public:
  Init_SetCoords_Response_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mypalletizer_interfaces::srv::SetCoords_Response flag(::mypalletizer_interfaces::srv::SetCoords_Response::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mypalletizer_interfaces::srv::SetCoords_Response>()
{
  return mypalletizer_interfaces::srv::builder::Init_SetCoords_Response_flag();
}

}  // namespace mypalletizer_interfaces


namespace mypalletizer_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetCoords_Event_response
{
public:
  explicit Init_SetCoords_Event_response(::mypalletizer_interfaces::srv::SetCoords_Event & msg)
  : msg_(msg)
  {}
  ::mypalletizer_interfaces::srv::SetCoords_Event response(::mypalletizer_interfaces::srv::SetCoords_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Event msg_;
};

class Init_SetCoords_Event_request
{
public:
  explicit Init_SetCoords_Event_request(::mypalletizer_interfaces::srv::SetCoords_Event & msg)
  : msg_(msg)
  {}
  Init_SetCoords_Event_response request(::mypalletizer_interfaces::srv::SetCoords_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetCoords_Event_response(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Event msg_;
};

class Init_SetCoords_Event_info
{
public:
  Init_SetCoords_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetCoords_Event_request info(::mypalletizer_interfaces::srv::SetCoords_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetCoords_Event_request(msg_);
  }

private:
  ::mypalletizer_interfaces::srv::SetCoords_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mypalletizer_interfaces::srv::SetCoords_Event>()
{
  return mypalletizer_interfaces::srv::builder::Init_SetCoords_Event_info();
}

}  // namespace mypalletizer_interfaces

#endif  // MYPALLETIZER_INTERFACES__SRV__DETAIL__SET_COORDS__BUILDER_HPP_
