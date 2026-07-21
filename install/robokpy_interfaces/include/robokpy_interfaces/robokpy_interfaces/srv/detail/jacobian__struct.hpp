// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:srv/Jacobian.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/jacobian.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__STRUCT_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__Jacobian_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__Jacobian_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Jacobian_Request_
{
  using Type = Jacobian_Request_<ContainerAllocator>;

  explicit Jacobian_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Jacobian_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _q_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _q_type q;

  // setters for named parameter idiom
  Type & set__q(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->q = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__Jacobian_Request
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__Jacobian_Request
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jacobian_Request_ & other) const
  {
    if (this->q != other.q) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jacobian_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jacobian_Request_

// alias to use template instance with default allocator
using Jacobian_Request =
  robokpy_interfaces::srv::Jacobian_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__Jacobian_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__Jacobian_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Jacobian_Response_
{
  using Type = Jacobian_Response_<ContainerAllocator>;

  explicit Jacobian_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->rows = 0l;
      this->cols = 0l;
      this->manipulability = 0.0;
      this->condition_number = 0.0;
      this->rank = 0l;
      this->is_near_singular = false;
      this->message = "";
    }
  }

  explicit Jacobian_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->rows = 0l;
      this->cols = 0l;
      this->manipulability = 0.0;
      this->condition_number = 0.0;
      this->rank = 0l;
      this->is_near_singular = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _jacobian_flat_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _jacobian_flat_type jacobian_flat;
  using _rows_type =
    int32_t;
  _rows_type rows;
  using _cols_type =
    int32_t;
  _cols_type cols;
  using _manipulability_type =
    double;
  _manipulability_type manipulability;
  using _condition_number_type =
    double;
  _condition_number_type condition_number;
  using _rank_type =
    int32_t;
  _rank_type rank;
  using _is_near_singular_type =
    bool;
  _is_near_singular_type is_near_singular;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__jacobian_flat(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->jacobian_flat = _arg;
    return *this;
  }
  Type & set__rows(
    const int32_t & _arg)
  {
    this->rows = _arg;
    return *this;
  }
  Type & set__cols(
    const int32_t & _arg)
  {
    this->cols = _arg;
    return *this;
  }
  Type & set__manipulability(
    const double & _arg)
  {
    this->manipulability = _arg;
    return *this;
  }
  Type & set__condition_number(
    const double & _arg)
  {
    this->condition_number = _arg;
    return *this;
  }
  Type & set__rank(
    const int32_t & _arg)
  {
    this->rank = _arg;
    return *this;
  }
  Type & set__is_near_singular(
    const bool & _arg)
  {
    this->is_near_singular = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__Jacobian_Response
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__Jacobian_Response
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jacobian_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->jacobian_flat != other.jacobian_flat) {
      return false;
    }
    if (this->rows != other.rows) {
      return false;
    }
    if (this->cols != other.cols) {
      return false;
    }
    if (this->manipulability != other.manipulability) {
      return false;
    }
    if (this->condition_number != other.condition_number) {
      return false;
    }
    if (this->rank != other.rank) {
      return false;
    }
    if (this->is_near_singular != other.is_near_singular) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jacobian_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jacobian_Response_

// alias to use template instance with default allocator
using Jacobian_Response =
  robokpy_interfaces::srv::Jacobian_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__Jacobian_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__Jacobian_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Jacobian_Event_
{
  using Type = Jacobian_Event_<ContainerAllocator>;

  explicit Jacobian_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit Jacobian_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::Jacobian_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::Jacobian_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__Jacobian_Event
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__Jacobian_Event
    std::shared_ptr<robokpy_interfaces::srv::Jacobian_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Jacobian_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const Jacobian_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Jacobian_Event_

// alias to use template instance with default allocator
using Jacobian_Event =
  robokpy_interfaces::srv::Jacobian_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace srv
{

struct Jacobian
{
  using Request = robokpy_interfaces::srv::Jacobian_Request;
  using Response = robokpy_interfaces::srv::Jacobian_Response;
  using Event = robokpy_interfaces::srv::Jacobian_Event;
};

}  // namespace srv

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__JACOBIAN__STRUCT_HPP_
