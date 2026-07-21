// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/msg/cell_state.hpp"


#ifndef ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__BUILDER_HPP_
#define ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/msg/detail/cell_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace msg
{

namespace builder
{

class Init_CellState_stamp
{
public:
  explicit Init_CellState_stamp(::robokpy_interfaces::msg::CellState & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::msg::CellState stamp(::robokpy_interfaces::msg::CellState::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::msg::CellState msg_;
};

class Init_CellState_last_error
{
public:
  explicit Init_CellState_last_error(::robokpy_interfaces::msg::CellState & msg)
  : msg_(msg)
  {}
  Init_CellState_stamp last_error(::robokpy_interfaces::msg::CellState::_last_error_type arg)
  {
    msg_.last_error = std::move(arg);
    return Init_CellState_stamp(msg_);
  }

private:
  ::robokpy_interfaces::msg::CellState msg_;
};

class Init_CellState_active_recipe_id
{
public:
  explicit Init_CellState_active_recipe_id(::robokpy_interfaces::msg::CellState & msg)
  : msg_(msg)
  {}
  Init_CellState_last_error active_recipe_id(::robokpy_interfaces::msg::CellState::_active_recipe_id_type arg)
  {
    msg_.active_recipe_id = std::move(arg);
    return Init_CellState_last_error(msg_);
  }

private:
  ::robokpy_interfaces::msg::CellState msg_;
};

class Init_CellState_state
{
public:
  Init_CellState_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CellState_active_recipe_id state(::robokpy_interfaces::msg::CellState::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_CellState_active_recipe_id(msg_);
  }

private:
  ::robokpy_interfaces::msg::CellState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::msg::CellState>()
{
  return robokpy_interfaces::msg::builder::Init_CellState_state();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__BUILDER_HPP_
