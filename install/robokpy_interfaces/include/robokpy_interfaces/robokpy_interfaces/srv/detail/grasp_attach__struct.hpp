// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:srv/GraspAttach.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/grasp_attach.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__STRUCT_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__GraspAttach_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__GraspAttach_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GraspAttach_Request_
{
  using Type = GraspAttach_Request_<ContainerAllocator>;

  explicit GraspAttach_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->parent_model = "";
      this->parent_link = "";
      this->child_model = "";
      this->child_link = "";
      this->attach = false;
      this->joint_id = 0ul;
    }
  }

  explicit GraspAttach_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : parent_model(_alloc),
    parent_link(_alloc),
    child_model(_alloc),
    child_link(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->parent_model = "";
      this->parent_link = "";
      this->child_model = "";
      this->child_link = "";
      this->attach = false;
      this->joint_id = 0ul;
    }
  }

  // field types and members
  using _parent_model_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _parent_model_type parent_model;
  using _parent_link_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _parent_link_type parent_link;
  using _child_model_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _child_model_type child_model;
  using _child_link_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _child_link_type child_link;
  using _attach_type =
    bool;
  _attach_type attach;
  using _joint_id_type =
    uint32_t;
  _joint_id_type joint_id;

  // setters for named parameter idiom
  Type & set__parent_model(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->parent_model = _arg;
    return *this;
  }
  Type & set__parent_link(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->parent_link = _arg;
    return *this;
  }
  Type & set__child_model(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->child_model = _arg;
    return *this;
  }
  Type & set__child_link(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->child_link = _arg;
    return *this;
  }
  Type & set__attach(
    const bool & _arg)
  {
    this->attach = _arg;
    return *this;
  }
  Type & set__joint_id(
    const uint32_t & _arg)
  {
    this->joint_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__GraspAttach_Request
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__GraspAttach_Request
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GraspAttach_Request_ & other) const
  {
    if (this->parent_model != other.parent_model) {
      return false;
    }
    if (this->parent_link != other.parent_link) {
      return false;
    }
    if (this->child_model != other.child_model) {
      return false;
    }
    if (this->child_link != other.child_link) {
      return false;
    }
    if (this->attach != other.attach) {
      return false;
    }
    if (this->joint_id != other.joint_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GraspAttach_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GraspAttach_Request_

// alias to use template instance with default allocator
using GraspAttach_Request =
  robokpy_interfaces::srv::GraspAttach_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__GraspAttach_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__GraspAttach_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GraspAttach_Response_
{
  using Type = GraspAttach_Response_<ContainerAllocator>;

  explicit GraspAttach_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->joint_id = 0ul;
    }
  }

  explicit GraspAttach_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->joint_id = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _joint_id_type =
    uint32_t;
  _joint_id_type joint_id;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__joint_id(
    const uint32_t & _arg)
  {
    this->joint_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__GraspAttach_Response
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__GraspAttach_Response
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GraspAttach_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->joint_id != other.joint_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const GraspAttach_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GraspAttach_Response_

// alias to use template instance with default allocator
using GraspAttach_Response =
  robokpy_interfaces::srv::GraspAttach_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__GraspAttach_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__GraspAttach_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GraspAttach_Event_
{
  using Type = GraspAttach_Event_<ContainerAllocator>;

  explicit GraspAttach_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GraspAttach_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::GraspAttach_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::GraspAttach_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__GraspAttach_Event
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__GraspAttach_Event
    std::shared_ptr<robokpy_interfaces::srv::GraspAttach_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GraspAttach_Event_ & other) const
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
  bool operator!=(const GraspAttach_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GraspAttach_Event_

// alias to use template instance with default allocator
using GraspAttach_Event =
  robokpy_interfaces::srv::GraspAttach_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace srv
{

struct GraspAttach
{
  using Request = robokpy_interfaces::srv::GraspAttach_Request;
  using Response = robokpy_interfaces::srv::GraspAttach_Response;
  using Event = robokpy_interfaces::srv::GraspAttach_Event;
};

}  // namespace srv

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__GRASP_ATTACH__STRUCT_HPP_
