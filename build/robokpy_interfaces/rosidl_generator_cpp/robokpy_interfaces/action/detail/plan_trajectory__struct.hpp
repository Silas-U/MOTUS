// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robokpy_interfaces:action/PlanTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/plan_trajectory.hpp"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__PLAN_TRAJECTORY__STRUCT_HPP_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__PLAN_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'leg_target_poses'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Goal __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Goal __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_Goal_
{
  using Type = PlanTrajectory_Goal_<ContainerAllocator>;

  explicit PlanTrajectory_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_scale = 0.0;
    }
  }

  explicit PlanTrajectory_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->speed_scale = 0.0;
    }
  }

  // field types and members
  using _leg_step_ids_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _leg_step_ids_type leg_step_ids;
  using _leg_target_poses_type =
    std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Pose_<ContainerAllocator>>>;
  _leg_target_poses_type leg_target_poses;
  using _leg_traj_methods_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _leg_traj_methods_type leg_traj_methods;
  using _leg_traj_types_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _leg_traj_types_type leg_traj_types;
  using _leg_blend_radii_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _leg_blend_radii_type leg_blend_radii;
  using _seed_state_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _seed_state_type seed_state;
  using _speed_scale_type =
    double;
  _speed_scale_type speed_scale;

  // setters for named parameter idiom
  Type & set__leg_step_ids(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->leg_step_ids = _arg;
    return *this;
  }
  Type & set__leg_target_poses(
    const std::vector<geometry_msgs::msg::Pose_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Pose_<ContainerAllocator>>> & _arg)
  {
    this->leg_target_poses = _arg;
    return *this;
  }
  Type & set__leg_traj_methods(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->leg_traj_methods = _arg;
    return *this;
  }
  Type & set__leg_traj_types(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->leg_traj_types = _arg;
    return *this;
  }
  Type & set__leg_blend_radii(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->leg_blend_radii = _arg;
    return *this;
  }
  Type & set__seed_state(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->seed_state = _arg;
    return *this;
  }
  Type & set__speed_scale(
    const double & _arg)
  {
    this->speed_scale = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Goal
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Goal
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_Goal_ & other) const
  {
    if (this->leg_step_ids != other.leg_step_ids) {
      return false;
    }
    if (this->leg_target_poses != other.leg_target_poses) {
      return false;
    }
    if (this->leg_traj_methods != other.leg_traj_methods) {
      return false;
    }
    if (this->leg_traj_types != other.leg_traj_types) {
      return false;
    }
    if (this->leg_blend_radii != other.leg_blend_radii) {
      return false;
    }
    if (this->seed_state != other.seed_state) {
      return false;
    }
    if (this->speed_scale != other.speed_scale) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_Goal_

// alias to use template instance with default allocator
using PlanTrajectory_Goal =
  robokpy_interfaces::action::PlanTrajectory_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Result __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Result __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_Result_
{
  using Type = PlanTrajectory_Result_<ContainerAllocator>;

  explicit PlanTrajectory_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0l;
      this->total_duration = 0.0;
    }
  }

  explicit PlanTrajectory_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_code = 0l;
      this->total_duration = 0.0;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_code_type =
    int32_t;
  _error_code_type error_code;
  using _trajectory_type =
    trajectory_msgs::msg::JointTrajectory_<ContainerAllocator>;
  _trajectory_type trajectory;
  using _predicted_final_state_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _predicted_final_state_type predicted_final_state;
  using _total_duration_type =
    double;
  _total_duration_type total_duration;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_code(
    const int32_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__trajectory(
    const trajectory_msgs::msg::JointTrajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }
  Type & set__predicted_final_state(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->predicted_final_state = _arg;
    return *this;
  }
  Type & set__total_duration(
    const double & _arg)
  {
    this->total_duration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Result
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Result
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->trajectory != other.trajectory) {
      return false;
    }
    if (this->predicted_final_state != other.predicted_final_state) {
      return false;
    }
    if (this->total_duration != other.total_duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_Result_

// alias to use template instance with default allocator
using PlanTrajectory_Result =
  robokpy_interfaces::action::PlanTrajectory_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Feedback __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_Feedback_
{
  using Type = PlanTrajectory_Feedback_<ContainerAllocator>;

  explicit PlanTrajectory_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit PlanTrajectory_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Feedback
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_Feedback
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_Feedback_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_Feedback_

// alias to use template instance with default allocator
using PlanTrajectory_Feedback =
  robokpy_interfaces::action::PlanTrajectory_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "robokpy_interfaces/action/detail/plan_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_SendGoal_Request_
{
  using Type = PlanTrajectory_SendGoal_Request_<ContainerAllocator>;

  explicit PlanTrajectory_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit PlanTrajectory_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const robokpy_interfaces::action::PlanTrajectory_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Request
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Request
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_SendGoal_Request_

// alias to use template instance with default allocator
using PlanTrajectory_SendGoal_Request =
  robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_SendGoal_Response_
{
  using Type = PlanTrajectory_SendGoal_Response_<ContainerAllocator>;

  explicit PlanTrajectory_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit PlanTrajectory_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Response
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Response
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_SendGoal_Response_

// alias to use template instance with default allocator
using PlanTrajectory_SendGoal_Response =
  robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_SendGoal_Event_
{
  using Type = PlanTrajectory_SendGoal_Event_<ContainerAllocator>;

  explicit PlanTrajectory_SendGoal_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PlanTrajectory_SendGoal_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_SendGoal_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_SendGoal_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Event
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_SendGoal_Event
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_SendGoal_Event_ & other) const
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
  bool operator!=(const PlanTrajectory_SendGoal_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_SendGoal_Event_

// alias to use template instance with default allocator
using PlanTrajectory_SendGoal_Event =
  robokpy_interfaces::action::PlanTrajectory_SendGoal_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace action
{

struct PlanTrajectory_SendGoal
{
  using Request = robokpy_interfaces::action::PlanTrajectory_SendGoal_Request;
  using Response = robokpy_interfaces::action::PlanTrajectory_SendGoal_Response;
  using Event = robokpy_interfaces::action::PlanTrajectory_SendGoal_Event;
};

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Request __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_GetResult_Request_
{
  using Type = PlanTrajectory_GetResult_Request_<ContainerAllocator>;

  explicit PlanTrajectory_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit PlanTrajectory_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Request
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Request
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_GetResult_Request_

// alias to use template instance with default allocator
using PlanTrajectory_GetResult_Request =
  robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Response __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_GetResult_Response_
{
  using Type = PlanTrajectory_GetResult_Response_<ContainerAllocator>;

  explicit PlanTrajectory_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit PlanTrajectory_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const robokpy_interfaces::action::PlanTrajectory_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Response
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Response
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_GetResult_Response_

// alias to use template instance with default allocator
using PlanTrajectory_GetResult_Response =
  robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Event __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Event __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_GetResult_Event_
{
  using Type = PlanTrajectory_GetResult_Event_<ContainerAllocator>;

  explicit PlanTrajectory_GetResult_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit PlanTrajectory_GetResult_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_GetResult_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robokpy_interfaces::action::PlanTrajectory_GetResult_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Event
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_GetResult_Event
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_GetResult_Event_ & other) const
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
  bool operator!=(const PlanTrajectory_GetResult_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_GetResult_Event_

// alias to use template instance with default allocator
using PlanTrajectory_GetResult_Event =
  robokpy_interfaces::action::PlanTrajectory_GetResult_Event_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace robokpy_interfaces

namespace robokpy_interfaces
{

namespace action
{

struct PlanTrajectory_GetResult
{
  using Request = robokpy_interfaces::action::PlanTrajectory_GetResult_Request;
  using Response = robokpy_interfaces::action::PlanTrajectory_GetResult_Response;
  using Event = robokpy_interfaces::action::PlanTrajectory_GetResult_Event;
};

}  // namespace action

}  // namespace robokpy_interfaces


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/plan_trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__robokpy_interfaces__action__PlanTrajectory_FeedbackMessage __declspec(deprecated)
#endif

namespace robokpy_interfaces
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct PlanTrajectory_FeedbackMessage_
{
  using Type = PlanTrajectory_FeedbackMessage_<ContainerAllocator>;

  explicit PlanTrajectory_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit PlanTrajectory_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const robokpy_interfaces::action::PlanTrajectory_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_FeedbackMessage
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robokpy_interfaces__action__PlanTrajectory_FeedbackMessage
    std::shared_ptr<robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlanTrajectory_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlanTrajectory_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlanTrajectory_FeedbackMessage_

// alias to use template instance with default allocator
using PlanTrajectory_FeedbackMessage =
  robokpy_interfaces::action::PlanTrajectory_FeedbackMessage_<std::allocator<void>>;

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

struct PlanTrajectory
{
  /// The goal message defined in the action definition.
  using Goal = robokpy_interfaces::action::PlanTrajectory_Goal;
  /// The result message defined in the action definition.
  using Result = robokpy_interfaces::action::PlanTrajectory_Result;
  /// The feedback message defined in the action definition.
  using Feedback = robokpy_interfaces::action::PlanTrajectory_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = robokpy_interfaces::action::PlanTrajectory_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = robokpy_interfaces::action::PlanTrajectory_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = robokpy_interfaces::action::PlanTrajectory_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct PlanTrajectory PlanTrajectory;

}  // namespace action

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__PLAN_TRAJECTORY__STRUCT_HPP_
