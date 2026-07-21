// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:srv/LoadRecipe.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/load_recipe.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__STRUCT_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadRecipe_Request_
{
  using Type = LoadRecipe_Request_<ContainerAllocator>;

  explicit LoadRecipe_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->recipe_path = "";
    }
  }

  explicit LoadRecipe_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : recipe_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->recipe_path = "";
    }
  }

  // field types and members
  using _recipe_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _recipe_path_type recipe_path;

  // setters for named parameter idiom
  Type & set__recipe_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->recipe_path = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Request
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Request
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadRecipe_Request_ & other) const
  {
    if (this->recipe_path != other.recipe_path) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadRecipe_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadRecipe_Request_

// alias to use template instance with default allocator
using LoadRecipe_Request =
  robokpy_interfaces::srv::LoadRecipe_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadRecipe_Response_
{
  using Type = LoadRecipe_Response_<ContainerAllocator>;

  explicit LoadRecipe_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->recipe_id = "";
      this->content_hash = "";
    }
  }

  explicit LoadRecipe_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    recipe_id(_alloc),
    content_hash(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
      this->recipe_id = "";
      this->content_hash = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _recipe_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _recipe_id_type recipe_id;
  using _content_hash_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _content_hash_type content_hash;

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
  Type & set__recipe_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->recipe_id = _arg;
    return *this;
  }
  Type & set__content_hash(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->content_hash = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Response
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Response
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadRecipe_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->recipe_id != other.recipe_id) {
      return false;
    }
    if (this->content_hash != other.content_hash) {
      return false;
    }
    return true;
  }
  bool operator!=(const LoadRecipe_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadRecipe_Response_

// alias to use template instance with default allocator
using LoadRecipe_Response =
  robokpy_interfaces::srv::LoadRecipe_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LoadRecipe_Event_
{
  using Type = LoadRecipe_Event_<ContainerAllocator>;

  explicit LoadRecipe_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit LoadRecipe_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::LoadRecipe_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::srv::LoadRecipe_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Event
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__srv__LoadRecipe_Event
    std::shared_ptr<robokpy_interfaces::srv::LoadRecipe_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LoadRecipe_Event_ & other) const
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
  bool operator!=(const LoadRecipe_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LoadRecipe_Event_

// alias to use template instance with default allocator
using LoadRecipe_Event =
  robokpy_interfaces::srv::LoadRecipe_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace srv
{

struct LoadRecipe
{
  using Request = robokpy_interfaces::srv::LoadRecipe_Request;
  using Response = robokpy_interfaces::srv::LoadRecipe_Response;
  using Event = robokpy_interfaces::srv::LoadRecipe_Event;
};

}  // namespace srv

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__STRUCT_HPP_
