// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:action/ExecuteVisionOp.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/execute_vision_op.hpp"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__STRUCT_HPP_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Goal __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Goal __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_Goal_
{
  using Type = ExecuteVisionOp_Goal_<ContainerAllocator>;

  explicit ExecuteVisionOp_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vision_id = "";
      this->operation = "";
    }
  }

  explicit ExecuteVisionOp_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : vision_id(_alloc),
    operation(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->vision_id = "";
      this->operation = "";
    }
  }

  // field types and members
  using _vision_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _vision_id_type vision_id;
  using _operation_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _operation_type operation;
  using _params_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _params_type params;

  // setters for named parameter idiom
  Type & set__vision_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->vision_id = _arg;
    return *this;
  }
  Type & set__operation(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->operation = _arg;
    return *this;
  }
  Type & set__params(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->params = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Goal
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Goal
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_Goal_ & other) const
  {
    if (this->vision_id != other.vision_id) {
      return false;
    }
    if (this->operation != other.operation) {
      return false;
    }
    if (this->params != other.params) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_Goal_

// alias to use template instance with default allocator
using ExecuteVisionOp_Goal =
  robokpy_interfaces::action::ExecuteVisionOp_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'detected_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Result __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Result __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_Result_
{
  using Type = ExecuteVisionOp_Result_<ContainerAllocator>;

  explicit ExecuteVisionOp_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : detected_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
      this->detected_value = "";
    }
  }

  explicit ExecuteVisionOp_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : detected_pose(_alloc, _init),
    detected_value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0ul;
      this->detected_value = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_code_type =
    uint32_t;
  _error_code_type error_code;
  using _detected_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _detected_pose_type detected_pose;
  using _detected_value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _detected_value_type detected_value;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__detected_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->detected_pose = _arg;
    return *this;
  }
  Type & set__detected_value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->detected_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Result
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Result
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->detected_pose != other.detected_pose) {
      return false;
    }
    if (this->detected_value != other.detected_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_Result_

// alias to use template instance with default allocator
using ExecuteVisionOp_Result =
  robokpy_interfaces::action::ExecuteVisionOp_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Feedback __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_Feedback_
{
  using Type = ExecuteVisionOp_Feedback_<ContainerAllocator>;

  explicit ExecuteVisionOp_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
      this->percent_complete = 0.0f;
    }
  }

  explicit ExecuteVisionOp_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
      this->percent_complete = 0.0f;
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _percent_complete_type =
    float;
  _percent_complete_type percent_complete;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__percent_complete(
    const float & _arg)
  {
    this->percent_complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Feedback
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_Feedback
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_Feedback_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->percent_complete != other.percent_complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_Feedback_

// alias to use template instance with default allocator
using ExecuteVisionOp_Feedback =
  robokpy_interfaces::action::ExecuteVisionOp_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_SendGoal_Request_
{
  using Type = ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>;

  explicit ExecuteVisionOp_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit ExecuteVisionOp_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const robokpy_interfaces::action::ExecuteVisionOp_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Request
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_SendGoal_Request_

// alias to use template instance with default allocator
using ExecuteVisionOp_SendGoal_Request =
  robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_SendGoal_Response_
{
  using Type = ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>;

  explicit ExecuteVisionOp_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit ExecuteVisionOp_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Response
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_SendGoal_Response_

// alias to use template instance with default allocator
using ExecuteVisionOp_SendGoal_Response =
  robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_SendGoal_Event_
{
  using Type = ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>;

  explicit ExecuteVisionOp_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ExecuteVisionOp_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_SendGoal_Event
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_SendGoal_Event_ & other) const
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
  bool operator!=(const ExecuteVisionOp_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_SendGoal_Event_

// alias to use template instance with default allocator
using ExecuteVisionOp_SendGoal_Event =
  robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace action
{

struct ExecuteVisionOp_SendGoal
{
  using Request = robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request;
  using Response = robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response;
  using Event = robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event;
};

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_GetResult_Request_
{
  using Type = ExecuteVisionOp_GetResult_Request_<ContainerAllocator>;

  explicit ExecuteVisionOp_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit ExecuteVisionOp_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Request
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_GetResult_Request_

// alias to use template instance with default allocator
using ExecuteVisionOp_GetResult_Request =
  robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_GetResult_Response_
{
  using Type = ExecuteVisionOp_GetResult_Response_<ContainerAllocator>;

  explicit ExecuteVisionOp_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit ExecuteVisionOp_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const robokpy_interfaces::action::ExecuteVisionOp_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Response
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_GetResult_Response_

// alias to use template instance with default allocator
using ExecuteVisionOp_GetResult_Response =
  robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_GetResult_Event_
{
  using Type = ExecuteVisionOp_GetResult_Event_<ContainerAllocator>;

  explicit ExecuteVisionOp_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ExecuteVisionOp_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_GetResult_Event
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_GetResult_Event_ & other) const
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
  bool operator!=(const ExecuteVisionOp_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_GetResult_Event_

// alias to use template instance with default allocator
using ExecuteVisionOp_GetResult_Event =
  robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace action
{

struct ExecuteVisionOp_GetResult
{
  using Request = robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request;
  using Response = robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response;
  using Event = robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event;
};

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct ExecuteVisionOp_FeedbackMessage_
{
  using Type = ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>;

  explicit ExecuteVisionOp_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit ExecuteVisionOp_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const robokpy_interfaces::action::ExecuteVisionOp_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__ExecuteVisionOp_FeedbackMessage
    std::shared_ptr<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteVisionOp_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteVisionOp_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteVisionOp_FeedbackMessage_

// alias to use template instance with default allocator
using ExecuteVisionOp_FeedbackMessage =
  robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace robokpy_interfaces
{

namespace action
{

struct ExecuteVisionOp
{
  /// The goal message defined in the action definition.
  using Goal = robokpy_interfaces::action::ExecuteVisionOp_Goal;
  /// The result message defined in the action definition.
  using Result = robokpy_interfaces::action::ExecuteVisionOp_Result;
  /// The feedback message defined in the action definition.
  using Feedback = robokpy_interfaces::action::ExecuteVisionOp_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = robokpy_interfaces::action::ExecuteVisionOp_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = robokpy_interfaces::action::ExecuteVisionOp_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct ExecuteVisionOp ExecuteVisionOp;

}  // namespace action

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__STRUCT_HPP_
