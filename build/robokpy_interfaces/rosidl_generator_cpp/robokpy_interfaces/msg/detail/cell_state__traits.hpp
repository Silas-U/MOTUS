// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/msg/cell_state.hpp"


#ifndef ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__TRAITS_HPP_
#define ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robokpy_interfaces/msg/detail/cell_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace robokpy_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CellState & msg,
  std::ostream & out)
{
  out << "{";
  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: active_recipe_id
  {
    out << "active_recipe_id: ";
    rosidl_generator_traits::value_to_yaml(msg.active_recipe_id, out);
    out << ", ";
  }

  // member: last_error
  {
    out << "last_error: ";
    rosidl_generator_traits::value_to_yaml(msg.last_error, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CellState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: active_recipe_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "active_recipe_id: ";
    rosidl_generator_traits::value_to_yaml(msg.active_recipe_id, out);
    out << "\n";
  }

  // member: last_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_error: ";
    rosidl_generator_traits::value_to_yaml(msg.last_error, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CellState & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::msg::CellState & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::msg::CellState & msg)
{
  return robokpy_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::msg::CellState>()
{
  return "robokpy_interfaces::msg::CellState";
}

template<>
inline const char * name<robokpy_interfaces::msg::CellState>()
{
  return "robokpy_interfaces/msg/CellState";
}

template<>
struct has_fixed_size<robokpy_interfaces::msg::CellState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::msg::CellState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::msg::CellState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__TRAITS_HPP_
