// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robokpy_interfaces:srv/SetPlanningTipLink.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/set_planning_tip_link.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__SET_PLANNING_TIP_LINK__TRAITS_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__SET_PLANNING_TIP_LINK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robokpy_interfaces/srv/detail/set_planning_tip_link__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPlanningTipLink_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: tip_link
  {
    out << "tip_link: ";
    rosidl_generator_traits::value_to_yaml(msg.tip_link, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPlanningTipLink_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tip_link
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tip_link: ";
    rosidl_generator_traits::value_to_yaml(msg.tip_link, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPlanningTipLink_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::srv::SetPlanningTipLink_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::SetPlanningTipLink_Request & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::SetPlanningTipLink_Request>()
{
  return "robokpy_interfaces::srv::SetPlanningTipLink_Request";
}

template<>
inline const char * name<robokpy_interfaces::srv::SetPlanningTipLink_Request>()
{
  return "robokpy_interfaces/srv/SetPlanningTipLink_Request";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::SetPlanningTipLink_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::srv::SetPlanningTipLink_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPlanningTipLink_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPlanningTipLink_Response & msg,
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

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPlanningTipLink_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::srv::SetPlanningTipLink_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::SetPlanningTipLink_Response & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::SetPlanningTipLink_Response>()
{
  return "robokpy_interfaces::srv::SetPlanningTipLink_Response";
}

template<>
inline const char * name<robokpy_interfaces::srv::SetPlanningTipLink_Response>()
{
  return "robokpy_interfaces/srv/SetPlanningTipLink_Response";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::SetPlanningTipLink_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::srv::SetPlanningTipLink_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPlanningTipLink_Event & msg,
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
  const SetPlanningTipLink_Event & msg,
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

inline std::string to_yaml(const SetPlanningTipLink_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace robokpy_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use robokpy_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robokpy_interfaces::srv::SetPlanningTipLink_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::SetPlanningTipLink_Event & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::SetPlanningTipLink_Event>()
{
  return "robokpy_interfaces::srv::SetPlanningTipLink_Event";
}

template<>
inline const char * name<robokpy_interfaces::srv::SetPlanningTipLink_Event>()
{
  return "robokpy_interfaces/srv/SetPlanningTipLink_Event";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::SetPlanningTipLink_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Event>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Request>::value && has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<robokpy_interfaces::srv::SetPlanningTipLink_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robokpy_interfaces::srv::SetPlanningTipLink>()
{
  return "robokpy_interfaces::srv::SetPlanningTipLink";
}

template<>
inline const char * name<robokpy_interfaces::srv::SetPlanningTipLink>()
{
  return "robokpy_interfaces/srv/SetPlanningTipLink";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::SetPlanningTipLink>
  : std::integral_constant<
    bool,
    has_fixed_size<robokpy_interfaces::srv::SetPlanningTipLink_Request>::value &&
    has_fixed_size<robokpy_interfaces::srv::SetPlanningTipLink_Response>::value
  >
{
};

template<>
struct has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink>
  : std::integral_constant<
    bool,
    has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Request>::value &&
    has_bounded_size<robokpy_interfaces::srv::SetPlanningTipLink_Response>::value
  >
{
};

template<>
struct is_service<robokpy_interfaces::srv::SetPlanningTipLink>
  : std::true_type
{
};

template<>
struct is_service_request<robokpy_interfaces::srv::SetPlanningTipLink_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robokpy_interfaces::srv::SetPlanningTipLink_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__SET_PLANNING_TIP_LINK__TRAITS_HPP_
