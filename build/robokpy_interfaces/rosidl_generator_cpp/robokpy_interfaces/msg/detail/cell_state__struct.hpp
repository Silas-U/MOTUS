// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/msg/cell_state.hpp"


#ifndef ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__STRUCT_HPP_
#define ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__msg__CellState __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__msg__CellState __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CellState_
{
  using Type = CellState_<ContainerAllocator>;

  explicit CellState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->active_recipe_id = "";
      this->last_error = "";
    }
  }

  explicit CellState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : active_recipe_id(_alloc),
    last_error(_alloc),
    stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->active_recipe_id = "";
      this->last_error = "";
    }
  }

  // field types and members
  using _state_type =
    uint8_t;
  _state_type state;
  using _active_recipe_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _active_recipe_id_type active_recipe_id;
  using _last_error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _last_error_type last_error;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__active_recipe_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->active_recipe_id = _arg;
    return *this;
  }
  Type & set__last_error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->last_error = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t PLANNING =
    1u;
  static constexpr uint8_t EXECUTING =
    2u;
  static constexpr uint8_t PAUSED =
    3u;
  // guard against 'ERROR' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(ERROR)
#    pragma push_macro("ERROR")
#    undef ERROR
#  endif
#endif
  static constexpr uint8_t ERROR =
    4u;
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("ERROR")
#endif
  static constexpr uint8_t ESTOP =
    5u;

  // pointer types
  using RawPtr =
    robokpy_interfaces::msg::CellState_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::msg::CellState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::msg::CellState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::msg::CellState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__msg__CellState
    std::shared_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__msg__CellState
    std::shared_ptr<robokpy_interfaces::msg::CellState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CellState_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    if (this->active_recipe_id != other.active_recipe_id) {
      return false;
    }
    if (this->last_error != other.last_error) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const CellState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CellState_

// alias to use template instance with default allocator
using CellState =
  robokpy_interfaces::msg::CellState_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CellState_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CellState_<ContainerAllocator>::PLANNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CellState_<ContainerAllocator>::EXECUTING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CellState_<ContainerAllocator>::PAUSED;
#endif  // __cplusplus < 201703L
// guard against 'ERROR' being predefined by MSVC by temporarily undefining it
#if defined(_WIN32)
#  if defined(ERROR)
#    pragma push_macro("ERROR")
#    undef ERROR
#  endif
#endif
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CellState_<ContainerAllocator>::ERROR;
#endif  // __cplusplus < 201703L
#if defined(_WIN32)
#  pragma warning(suppress : 4602)
#  pragma pop_macro("ERROR")
#endif
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t CellState_<ContainerAllocator>::ESTOP;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__MSG__DETAIL__CELL_STATE__STRUCT_HPP_
