// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/Jacobian.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/jacobian.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/jacobian__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_Jacobian_Request_q
{
public:
  Init_Jacobian_Request_q()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robokpy_interfaces::srv::Jacobian_Request q(::robokpy_interfaces::srv::Jacobian_Request::_q_type arg)
  {
    msg_.q = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::Jacobian_Request>()
{
  return robokpy_interfaces::srv::builder::Init_Jacobian_Request_q();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_Jacobian_Response_message
{
public:
  explicit Init_Jacobian_Response_message(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::Jacobian_Response message(::robokpy_interfaces::srv::Jacobian_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_is_near_singular
{
public:
  explicit Init_Jacobian_Response_is_near_singular(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_message is_near_singular(::robokpy_interfaces::srv::Jacobian_Response::_is_near_singular_type arg)
  {
    msg_.is_near_singular = std::move(arg);
    return Init_Jacobian_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_rank
{
public:
  explicit Init_Jacobian_Response_rank(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_is_near_singular rank(::robokpy_interfaces::srv::Jacobian_Response::_rank_type arg)
  {
    msg_.rank = std::move(arg);
    return Init_Jacobian_Response_is_near_singular(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_condition_number
{
public:
  explicit Init_Jacobian_Response_condition_number(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_rank condition_number(::robokpy_interfaces::srv::Jacobian_Response::_condition_number_type arg)
  {
    msg_.condition_number = std::move(arg);
    return Init_Jacobian_Response_rank(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_manipulability
{
public:
  explicit Init_Jacobian_Response_manipulability(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_condition_number manipulability(::robokpy_interfaces::srv::Jacobian_Response::_manipulability_type arg)
  {
    msg_.manipulability = std::move(arg);
    return Init_Jacobian_Response_condition_number(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_cols
{
public:
  explicit Init_Jacobian_Response_cols(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_manipulability cols(::robokpy_interfaces::srv::Jacobian_Response::_cols_type arg)
  {
    msg_.cols = std::move(arg);
    return Init_Jacobian_Response_manipulability(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_rows
{
public:
  explicit Init_Jacobian_Response_rows(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_cols rows(::robokpy_interfaces::srv::Jacobian_Response::_rows_type arg)
  {
    msg_.rows = std::move(arg);
    return Init_Jacobian_Response_cols(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_jacobian_flat
{
public:
  explicit Init_Jacobian_Response_jacobian_flat(::robokpy_interfaces::srv::Jacobian_Response & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Response_rows jacobian_flat(::robokpy_interfaces::srv::Jacobian_Response::_jacobian_flat_type arg)
  {
    msg_.jacobian_flat = std::move(arg);
    return Init_Jacobian_Response_rows(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

class Init_Jacobian_Response_success
{
public:
  Init_Jacobian_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jacobian_Response_jacobian_flat success(::robokpy_interfaces::srv::Jacobian_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Jacobian_Response_jacobian_flat(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::Jacobian_Response>()
{
  return robokpy_interfaces::srv::builder::Init_Jacobian_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_Jacobian_Event_response
{
public:
  explicit Init_Jacobian_Event_response(::robokpy_interfaces::srv::Jacobian_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::Jacobian_Event response(::robokpy_interfaces::srv::Jacobian_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Event msg_;
};

class Init_Jacobian_Event_request
{
public:
  explicit Init_Jacobian_Event_request(::robokpy_interfaces::srv::Jacobian_Event & msg)
  : msg_(msg)
  {}
  Init_Jacobian_Event_response request(::robokpy_interfaces::srv::Jacobian_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Jacobian_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Event msg_;
};

class Init_Jacobian_Event_info
{
public:
  Init_Jacobian_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Jacobian_Event_request info(::robokpy_interfaces::srv::Jacobian_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Jacobian_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::Jacobian_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::Jacobian_Event>()
{
  return robokpy_interfaces::srv::builder::Init_Jacobian_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__BUILDER_HPP_
