// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:srv/ChainFK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/chain_fk.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__STRUCT_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__ChainFK_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__ChainFK_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChainFK_Request_
{
  using Type = ChainFK_Request_<ContainerAllocator>;

  explicit ChainFK_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->base_link = "";
      this->end_link = "";
    }
  }

  explicit ChainFK_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : base_link(_alloc),
    end_link(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->base_link = "";
      this->end_link = "";
    }
  }

  // field types and members
  using _q_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _q_type q;
  using _base_link_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _base_link_type base_link;
  using _end_link_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _end_link_type end_link;

  // setters for named parameter idiom
  Type & set__q(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__base_link(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->base_link = _arg;
    return *this;
  }
  Type & set__end_link(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->end_link = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__ChainFK_Request
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__ChainFK_Request
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChainFK_Request_ & other) const
  {
    if (this->q != other.q) {
      return false;
    }
    if (this->base_link != other.base_link) {
      return false;
    }
    if (this->end_link != other.end_link) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChainFK_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChainFK_Request_

// alias to use template instance with default allocator
using ChainFK_Request =
  robokpy_interfaces::srv::ChainFK_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__ChainFK_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__ChainFK_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChainFK_Response_
{
  using Type = ChainFK_Response_<ContainerAllocator>;

  explicit ChainFK_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      std::fill<typename std::array<double, 7>::iterator, double>(this->pose.begin(), this->pose.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->pose_euler.begin(), this->pose_euler.end(), 0.0);
      this->message = "";
    }
  }

  explicit ChainFK_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc),
    pose_euler(_alloc),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      std::fill<typename std::array<double, 7>::iterator, double>(this->pose.begin(), this->pose.end(), 0.0);
      std::fill<typename std::array<double, 6>::iterator, double>(this->pose_euler.begin(), this->pose_euler.end(), 0.0);
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _pose_type =
    std::array<double, 7>;
  _pose_type pose;
  using _pose_euler_type =
    std::array<double, 6>;
  _pose_euler_type pose_euler;
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
  Type & set__pose(
    const std::array<double, 7> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__pose_euler(
    const std::array<double, 6> & _arg)
  {
    this->pose_euler = _arg;
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
    robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__ChainFK_Response
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__ChainFK_Response
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChainFK_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->pose_euler != other.pose_euler) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ChainFK_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChainFK_Response_

// alias to use template instance with default allocator
using ChainFK_Response =
  robokpy_interfaces::srv::ChainFK_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__ChainFK_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__ChainFK_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ChainFK_Event_
{
  using Type = ChainFK_Event_<ContainerAllocator>;

  explicit ChainFK_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ChainFK_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::ChainFK_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::ChainFK_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__ChainFK_Event
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__ChainFK_Event
    std::shared_ptr<robokpy_interfaces::srv::ChainFK_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ChainFK_Event_ & other) const
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
  bool operator!=(const ChainFK_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ChainFK_Event_

// alias to use template instance with default allocator
using ChainFK_Event =
  robokpy_interfaces::srv::ChainFK_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace srv
{

struct ChainFK
{
  using Request = robokpy_interfaces::srv::ChainFK_Request;
  using Response = robokpy_interfaces::srv::ChainFK_Response;
  using Event = robokpy_interfaces::srv::ChainFK_Event;
};

}  // namespace srv

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__CHAIN_FK__STRUCT_HPP_
