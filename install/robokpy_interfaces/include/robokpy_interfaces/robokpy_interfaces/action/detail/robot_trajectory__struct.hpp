// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:action/RobotTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/robot_trajectory.hpp"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__ROBOT_TRAJECTORY__STRUCT_HPP_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__ROBOT_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Goal __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Goal __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_Goal_
{
  using Type = RobotTrajectory_Goal_<ContainerAllocator>;

  explicit RobotTrajectory_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trajectory_mode = "";
    }
  }

  explicit RobotTrajectory_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init),
    trajectory_mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->trajectory_mode = "";
    }
  }

  // field types and members
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _trajectory_mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _trajectory_mode_type trajectory_mode;

  // setters for named parameter idiom
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__trajectory_mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->trajectory_mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Goal
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Goal
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_Goal_ & other) const
  {
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->trajectory_mode != other.trajectory_mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_Goal_

// alias to use template instance with default allocator
using RobotTrajectory_Goal =
  robokpy_interfaces::action::RobotTrajectory_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Result __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Result __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_Result_
{
  using Type = RobotTrajectory_Result_<ContainerAllocator>;

  explicit RobotTrajectory_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->status_message = "";
    }
  }

  explicit RobotTrajectory_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->status_message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _status_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_message_type status_message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__status_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Result
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Result
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->status_message != other.status_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_Result_

// alias to use template instance with default allocator
using RobotTrajectory_Result =
  robokpy_interfaces::action::RobotTrajectory_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Feedback __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_Feedback_
{
  using Type = RobotTrajectory_Feedback_<ContainerAllocator>;

  explicit RobotTrajectory_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_waypoint_id = "";
      this->percent_complete = 0.0;
    }
  }

  explicit RobotTrajectory_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_waypoint_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->current_waypoint_id = "";
      this->percent_complete = 0.0;
    }
  }

  // field types and members
  using _current_waypoint_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_waypoint_id_type current_waypoint_id;
  using _percent_complete_type =
    double;
  _percent_complete_type percent_complete;

  // setters for named parameter idiom
  Type & set__current_waypoint_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_waypoint_id = _arg;
    return *this;
  }
  Type & set__percent_complete(
    const double & _arg)
  {
    this->percent_complete = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Feedback
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_Feedback
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_Feedback_ & other) const
  {
    if (this->current_waypoint_id != other.current_waypoint_id) {
      return false;
    }
    if (this->percent_complete != other.percent_complete) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_Feedback_

// alias to use template instance with default allocator
using RobotTrajectory_Feedback =
  robokpy_interfaces::action::RobotTrajectory_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "robokpy_interfaces/action/detail/robot_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_SendGoal_Request_
{
  using Type = RobotTrajectory_SendGoal_Request_<ContainerAllocator>;

  explicit RobotTrajectory_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit RobotTrajectory_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const robokpy_interfaces::action::RobotTrajectory_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Request
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Request
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_SendGoal_Request_

// alias to use template instance with default allocator
using RobotTrajectory_SendGoal_Request =
  robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_SendGoal_Response_
{
  using Type = RobotTrajectory_SendGoal_Response_<ContainerAllocator>;

  explicit RobotTrajectory_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit RobotTrajectory_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Response
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Response
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_SendGoal_Response_

// alias to use template instance with default allocator
using RobotTrajectory_SendGoal_Response =
  robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_SendGoal_Event_
{
  using Type = RobotTrajectory_SendGoal_Event_<ContainerAllocator>;

  explicit RobotTrajectory_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit RobotTrajectory_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Event
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_SendGoal_Event
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_SendGoal_Event_ & other) const
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
  bool operator!=(const RobotTrajectory_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_SendGoal_Event_

// alias to use template instance with default allocator
using RobotTrajectory_SendGoal_Event =
  robokpy_interfaces::action::RobotTrajectory_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace action
{

struct RobotTrajectory_SendGoal
{
  using Request = robokpy_interfaces::action::RobotTrajectory_SendGoal_Request;
  using Response = robokpy_interfaces::action::RobotTrajectory_SendGoal_Response;
  using Event = robokpy_interfaces::action::RobotTrajectory_SendGoal_Event;
};

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_GetResult_Request_
{
  using Type = RobotTrajectory_GetResult_Request_<ContainerAllocator>;

  explicit RobotTrajectory_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit RobotTrajectory_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Request
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Request
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_GetResult_Request_

// alias to use template instance with default allocator
using RobotTrajectory_GetResult_Request =
  robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/robot_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_GetResult_Response_
{
  using Type = RobotTrajectory_GetResult_Response_<ContainerAllocator>;

  explicit RobotTrajectory_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit RobotTrajectory_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const robokpy_interfaces::action::RobotTrajectory_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Response
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Response
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_GetResult_Response_

// alias to use template instance with default allocator
using RobotTrajectory_GetResult_Response =
  robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_GetResult_Event_
{
  using Type = RobotTrajectory_GetResult_Event_<ContainerAllocator>;

  explicit RobotTrajectory_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit RobotTrajectory_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::RobotTrajectory_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Event
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_GetResult_Event
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_GetResult_Event_ & other) const
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
  bool operator!=(const RobotTrajectory_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_GetResult_Event_

// alias to use template instance with default allocator
using RobotTrajectory_GetResult_Event =
  robokpy_interfaces::action::RobotTrajectory_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace action
{

struct RobotTrajectory_GetResult
{
  using Request = robokpy_interfaces::action::RobotTrajectory_GetResult_Request;
  using Response = robokpy_interfaces::action::RobotTrajectory_GetResult_Response;
  using Event = robokpy_interfaces::action::RobotTrajectory_GetResult_Event;
};

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/robot_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__RobotTrajectory_FeedbackMessage __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct RobotTrajectory_FeedbackMessage_
{
  using Type = RobotTrajectory_FeedbackMessage_<ContainerAllocator>;

  explicit RobotTrajectory_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit RobotTrajectory_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const robokpy_interfaces::action::RobotTrajectory_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_FeedbackMessage
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__RobotTrajectory_FeedbackMessage
    std::shared_ptr<robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RobotTrajectory_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const RobotTrajectory_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RobotTrajectory_FeedbackMessage_

// alias to use template instance with default allocator
using RobotTrajectory_FeedbackMessage =
  robokpy_interfaces::action::RobotTrajectory_FeedbackMessage_<std::allocator<void>>;

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

struct RobotTrajectory
{
  /// The goal message defined in the action definition.
  using Goal = robokpy_interfaces::action::RobotTrajectory_Goal;
  /// The result message defined in the action definition.
  using Result = robokpy_interfaces::action::RobotTrajectory_Result;
  /// The feedback message defined in the action definition.
  using Feedback = robokpy_interfaces::action::RobotTrajectory_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = robokpy_interfaces::action::RobotTrajectory_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = robokpy_interfaces::action::RobotTrajectory_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = robokpy_interfaces::action::RobotTrajectory_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct RobotTrajectory RobotTrajectory;

}  // namespace action

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__ROBOT_TRAJECTORY__STRUCT_HPP_
