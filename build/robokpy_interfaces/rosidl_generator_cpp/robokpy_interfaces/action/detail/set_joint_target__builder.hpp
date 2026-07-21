// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:action/SetJointTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/set_joint_target.hpp"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__SET_JOINT_TARGET__BUILDER_HPP_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__SET_JOINT_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/action/detail/set_joint_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_Goal_speed_scale
{
public:
  explicit Init_SetJointTarget_Goal_speed_scale(::robokpy_interfaces::action::SetJointTarget_Goal & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_Goal speed_scale(::robokpy_interfaces::action::SetJointTarget_Goal::_speed_scale_type arg)
  {
    msg_.speed_scale = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Goal msg_;
};

class Init_SetJointTarget_Goal_target_joints
{
public:
  Init_SetJointTarget_Goal_target_joints()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_Goal_speed_scale target_joints(::robokpy_interfaces::action::SetJointTarget_Goal::_target_joints_type arg)
  {
    msg_.target_joints = std::move(arg);
    return Init_SetJointTarget_Goal_speed_scale(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_Goal>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_Goal_target_joints();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_Result_final_state
{
public:
  explicit Init_SetJointTarget_Result_final_state(::robokpy_interfaces::action::SetJointTarget_Result & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_Result final_state(::robokpy_interfaces::action::SetJointTarget_Result::_final_state_type arg)
  {
    msg_.final_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Result msg_;
};

class Init_SetJointTarget_Result_error_code
{
public:
  explicit Init_SetJointTarget_Result_error_code(::robokpy_interfaces::action::SetJointTarget_Result & msg)
  : msg_(msg)
  {}
  Init_SetJointTarget_Result_final_state error_code(::robokpy_interfaces::action::SetJointTarget_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_SetJointTarget_Result_final_state(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Result msg_;
};

class Init_SetJointTarget_Result_success
{
public:
  Init_SetJointTarget_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_Result_error_code success(::robokpy_interfaces::action::SetJointTarget_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetJointTarget_Result_error_code(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_Result>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_Result_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_Feedback_current_state
{
public:
  explicit Init_SetJointTarget_Feedback_current_state(::robokpy_interfaces::action::SetJointTarget_Feedback & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_Feedback current_state(::robokpy_interfaces::action::SetJointTarget_Feedback::_current_state_type arg)
  {
    msg_.current_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Feedback msg_;
};

class Init_SetJointTarget_Feedback_percent_complete
{
public:
  Init_SetJointTarget_Feedback_percent_complete()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_Feedback_current_state percent_complete(::robokpy_interfaces::action::SetJointTarget_Feedback::_percent_complete_type arg)
  {
    msg_.percent_complete = std::move(arg);
    return Init_SetJointTarget_Feedback_current_state(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_Feedback>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_Feedback_percent_complete();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_SendGoal_Request_goal
{
public:
  explicit Init_SetJointTarget_SendGoal_Request_goal(::robokpy_interfaces::action::SetJointTarget_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Request goal(::robokpy_interfaces::action::SetJointTarget_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Request msg_;
};

class Init_SetJointTarget_SendGoal_Request_goal_id
{
public:
  Init_SetJointTarget_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_SendGoal_Request_goal goal_id(::robokpy_interfaces::action::SetJointTarget_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SetJointTarget_SendGoal_Request_goal(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_SendGoal_Request>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_SendGoal_Request_goal_id();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_SendGoal_Response_stamp
{
public:
  explicit Init_SetJointTarget_SendGoal_Response_stamp(::robokpy_interfaces::action::SetJointTarget_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Response stamp(::robokpy_interfaces::action::SetJointTarget_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Response msg_;
};

class Init_SetJointTarget_SendGoal_Response_accepted
{
public:
  Init_SetJointTarget_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_SendGoal_Response_stamp accepted(::robokpy_interfaces::action::SetJointTarget_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SetJointTarget_SendGoal_Response_stamp(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_SendGoal_Response>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_SendGoal_Response_accepted();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_SendGoal_Event_response
{
public:
  explicit Init_SetJointTarget_SendGoal_Event_response(::robokpy_interfaces::action::SetJointTarget_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Event response(::robokpy_interfaces::action::SetJointTarget_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Event msg_;
};

class Init_SetJointTarget_SendGoal_Event_request
{
public:
  explicit Init_SetJointTarget_SendGoal_Event_request(::robokpy_interfaces::action::SetJointTarget_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_SetJointTarget_SendGoal_Event_response request(::robokpy_interfaces::action::SetJointTarget_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetJointTarget_SendGoal_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Event msg_;
};

class Init_SetJointTarget_SendGoal_Event_info
{
public:
  Init_SetJointTarget_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_SendGoal_Event_request info(::robokpy_interfaces::action::SetJointTarget_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetJointTarget_SendGoal_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_SendGoal_Event>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_SendGoal_Event_info();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_GetResult_Request_goal_id
{
public:
  Init_SetJointTarget_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Request goal_id(::robokpy_interfaces::action::SetJointTarget_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_GetResult_Request>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_GetResult_Request_goal_id();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_GetResult_Response_result
{
public:
  explicit Init_SetJointTarget_GetResult_Response_result(::robokpy_interfaces::action::SetJointTarget_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Response result(::robokpy_interfaces::action::SetJointTarget_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Response msg_;
};

class Init_SetJointTarget_GetResult_Response_status
{
public:
  Init_SetJointTarget_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_GetResult_Response_result status(::robokpy_interfaces::action::SetJointTarget_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SetJointTarget_GetResult_Response_result(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_GetResult_Response>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_GetResult_Response_status();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_GetResult_Event_response
{
public:
  explicit Init_SetJointTarget_GetResult_Event_response(::robokpy_interfaces::action::SetJointTarget_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Event response(::robokpy_interfaces::action::SetJointTarget_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Event msg_;
};

class Init_SetJointTarget_GetResult_Event_request
{
public:
  explicit Init_SetJointTarget_GetResult_Event_request(::robokpy_interfaces::action::SetJointTarget_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_SetJointTarget_GetResult_Event_response request(::robokpy_interfaces::action::SetJointTarget_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetJointTarget_GetResult_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Event msg_;
};

class Init_SetJointTarget_GetResult_Event_info
{
public:
  Init_SetJointTarget_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_GetResult_Event_request info(::robokpy_interfaces::action::SetJointTarget_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetJointTarget_GetResult_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_GetResult_Event>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_GetResult_Event_info();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace action
{

namespace builder
{

class Init_SetJointTarget_FeedbackMessage_feedback
{
public:
  explicit Init_SetJointTarget_FeedbackMessage_feedback(::robokpy_interfaces::action::SetJointTarget_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::action::SetJointTarget_FeedbackMessage feedback(::robokpy_interfaces::action::SetJointTarget_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_FeedbackMessage msg_;
};

class Init_SetJointTarget_FeedbackMessage_goal_id
{
public:
  Init_SetJointTarget_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointTarget_FeedbackMessage_feedback goal_id(::robokpy_interfaces::action::SetJointTarget_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_SetJointTarget_FeedbackMessage_feedback(msg_);
  }

private:
  ::robokpy_interfaces::action::SetJointTarget_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::action::SetJointTarget_FeedbackMessage>()
{
  return robokpy_interfaces::action::builder::Init_SetJointTarget_FeedbackMessage_goal_id();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__SET_JOINT_TARGET__BUILDER_HPP_
