// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:srv/IK.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/ik.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__IK__STRUCT_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__IK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__IK_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__IK_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IK_Request_
{
  using Type = IK_Request_<ContainerAllocator>;

  explicit IK_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_pose.begin(), this->target_pose.end(), 0.0);
      this->tol = 0.0;
      this->max_iter = 0l;
    }
  }

  explicit IK_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<double, 7>::iterator, double>(this->target_pose.begin(), this->target_pose.end(), 0.0);
      this->tol = 0.0;
      this->max_iter = 0l;
    }
  }

  // field types and members
  using _target_pose_type =
    std::array<double, 7>;
  _target_pose_type target_pose;
  using _mask_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _mask_type mask;
  using _seed_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _seed_type seed;
  using _tol_type =
    double;
  _tol_type tol;
  using _max_iter_type =
    int32_t;
  _max_iter_type max_iter;

  // setters for named parameter idiom
  Type & set__target_pose(
    const std::array<double, 7> & _arg)
  {
    this->target_pose = _arg;
    return *this;
  }
  Type & set__mask(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->mask = _arg;
    return *this;
  }
  Type & set__seed(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->seed = _arg;
    return *this;
  }
  Type & set__tol(
    const double & _arg)
  {
    this->tol = _arg;
    return *this;
  }
  Type & set__max_iter(
    const int32_t & _arg)
  {
    this->max_iter = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::IK_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::IK_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__IK_Request
    std::shared_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__IK_Request
    std::shared_ptr<robokpy_interfaces::srv::IK_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IK_Request_ & other) const
  {
    if (this->target_pose != other.target_pose) {
      return false;
    }
    if (this->mask != other.mask) {
      return false;
    }
    if (this->seed != other.seed) {
      return false;
    }
    if (this->tol != other.tol) {
      return false;
    }
    if (this->max_iter != other.max_iter) {
      return false;
    }
    return true;
  }
  bool operator!=(const IK_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IK_Request_

// alias to use template instance with default allocator
using IK_Request =
  robokpy_interfaces::srv::IK_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__IK_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__IK_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IK_Response_
{
  using Type = IK_Response_<ContainerAllocator>;

  explicit IK_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error = 0.0;
      this->message = "";
    }
  }

  explicit IK_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error = 0.0;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _q_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _q_type q;
  using _error_type =
    double;
  _error_type error;
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
  Type & set__q(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->q = _arg;
    return *this;
  }
  Type & set__error(
    const double & _arg)
  {
    this->error = _arg;
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
    robokpy_interfaces::srv::IK_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::IK_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__IK_Response
    std::shared_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__IK_Response
    std::shared_ptr<robokpy_interfaces::srv::IK_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IK_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->q != other.q) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const IK_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IK_Response_

// alias to use template instance with default allocator
using IK_Response =
  robokpy_interfaces::srv::IK_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__IK_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__IK_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IK_Event_
{
  using Type = IK_Event_<ContainerAllocator>;

  explicit IK_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit IK_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::IK_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::IK_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::IK_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::IK_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::IK_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::IK_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__IK_Event
    std::shared_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__IK_Event
    std::shared_ptr<robokpy_interfaces::srv::IK_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IK_Event_ & other) const
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
  bool operator!=(const IK_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IK_Event_

// alias to use template instance with default allocator
using IK_Event =
  robokpy_interfaces::srv::IK_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace srv
{

struct IK
{
  using Request = robokpy_interfaces::srv::IK_Request;
  using Response = robokpy_interfaces::srv::IK_Response;
  using Event = robokpy_interfaces::srv::IK_Event;
};

}  // namespace srv

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__IK__STRUCT_HPP_
