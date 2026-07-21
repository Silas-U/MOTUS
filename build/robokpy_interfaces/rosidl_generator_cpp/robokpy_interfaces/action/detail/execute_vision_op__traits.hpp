// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robokpy_interfaces:action/ExecuteVisionOp.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/execute_vision_op.hpp"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__TRAITS_HPP_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robokpy_interfaces/action/detail/execute_vision_op__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: vision_id
  {
    out << "vision_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vision_id, out);
    out << ", ";
  }

  // member: operation
  {
    out << "operation: ";
    rosidl_generator_traits::value_to_yaml(msg.operation, out);
    out << ", ";
  }

  // member: params
  {
    if (msg.params.size() == 0) {
      out << "params: []";
    } else {
      out << "params: [";
      size_t pending_items = msg.params.size();
      for (auto item : msg.params) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: vision_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vision_id: ";
    rosidl_generator_traits::value_to_yaml(msg.vision_id, out);
    out << "\n";
  }

  // member: operation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operation: ";
    rosidl_generator_traits::value_to_yaml(msg.operation, out);
    out << "\n";
  }

  // member: params
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.params.size() == 0) {
      out << "params: []\n";
    } else {
      out << "params:\n";
      for (auto item : msg.params) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_Goal & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_Goal>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_Goal";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_Goal>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_Goal";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'detected_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: detected_pose
  {
    out << "detected_pose: ";
    to_flow_style_yaml(msg.detected_pose, out);
    out << ", ";
  }

  // member: detected_value
  {
    out << "detected_value: ";
    rosidl_generator_traits::value_to_yaml(msg.detected_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }

  // member: detected_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected_pose:\n";
    to_block_style_yaml(msg.detected_pose, out, indentation + 2);
  }

  // member: detected_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected_value: ";
    rosidl_generator_traits::value_to_yaml(msg.detected_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_Result & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_Result>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_Result";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_Result>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_Result";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: percent_complete
  {
    out << "percent_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.percent_complete, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: percent_complete
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "percent_complete: ";
    rosidl_generator_traits::value_to_yaml(msg.percent_complete, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_Feedback & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_Feedback>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_Feedback";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_Feedback>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_Feedback";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "robokpy_interfaces/action/detail/execute_vision_op__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_SendGoal_Request";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_SendGoal_Response";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_SendGoal_Event";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>::value && has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_SendGoal";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_SendGoal";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>::value &&
    has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>::value &&
    has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<robokpy_interfaces::action::ExecuteVisionOp_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robokpy_interfaces::action::ExecuteVisionOp_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_GetResult_Request";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_GetResult_Response";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_Result>::value> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_Result>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_GetResult_Event";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>::value && has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_GetResult>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_GetResult";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_GetResult>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_GetResult";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>::value &&
    has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>::value &&
    has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>::value
  >
{
};

template<>
struct is_service<robokpy_interfaces::action::ExecuteVisionOp_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robokpy_interfaces::action::ExecuteVisionOp_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "robokpy_interfaces/action/detail/execute_vision_op__traits.hpp"

namespace robokpy_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const ExecuteVisionOp_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecuteVisionOp_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecuteVisionOp_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage & msg)
{
  return robokpy_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>()
{
  return "robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage";
}

template<>
inline const char * name<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>()
{
  return "robokpy_interfaces/action/ExecuteVisionOp_FeedbackMessage";
}

template<>
struct has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<robokpy_interfaces::action::ExecuteVisionOp_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::action::ExecuteVisionOp_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<robokpy_interfaces::action::ExecuteVisionOp_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<robokpy_interfaces::action::ExecuteVisionOp>
  : std::true_type
{
};

template<>
struct is_action_goal<robokpy_interfaces::action::ExecuteVisionOp_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<robokpy_interfaces::action::ExecuteVisionOp_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<robokpy_interfaces::action::ExecuteVisionOp_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__EXECUTE_VISION_OP__TRAITS_HPP_
