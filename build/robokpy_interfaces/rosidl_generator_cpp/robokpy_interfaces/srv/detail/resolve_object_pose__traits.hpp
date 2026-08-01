// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robokpy_interfaces:srv/ResolveObjectPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/resolve_object_pose.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__TRAITS_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robokpy_interfaces/srv/detail/resolve_object_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResolveObjectPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: max_distance
  {
    out << "max_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.max_distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ResolveObjectPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: max_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.max_distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ResolveObjectPose_Request & msg, bool use_flow_style = false)
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
  const robokpy_interfaces::srv::ResolveObjectPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::ResolveObjectPose_Request & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::ResolveObjectPose_Request>()
{
  return "robokpy_interfaces::srv::ResolveObjectPose_Request";
}

template<>
inline const char * name<robokpy_interfaces::srv::ResolveObjectPose_Request>()
{
  return "robokpy_interfaces/srv/ResolveObjectPose_Request";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::ResolveObjectPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robokpy_interfaces::srv::ResolveObjectPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ResolveObjectPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: child_model
  {
    out << "child_model: ";
    rosidl_generator_traits::value_to_yaml(msg.child_model, out);
    out << ", ";
  }

  // member: child_link
  {
    out << "child_link: ";
    rosidl_generator_traits::value_to_yaml(msg.child_link, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
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
  const ResolveObjectPose_Response & msg,
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

  // member: child_model
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "child_model: ";
    rosidl_generator_traits::value_to_yaml(msg.child_model, out);
    out << "\n";
  }

  // member: child_link
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "child_link: ";
    rosidl_generator_traits::value_to_yaml(msg.child_link, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
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

inline std::string to_yaml(const ResolveObjectPose_Response & msg, bool use_flow_style = false)
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
  const robokpy_interfaces::srv::ResolveObjectPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::ResolveObjectPose_Response & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::ResolveObjectPose_Response>()
{
  return "robokpy_interfaces::srv::ResolveObjectPose_Response";
}

template<>
inline const char * name<robokpy_interfaces::srv::ResolveObjectPose_Response>()
{
  return "robokpy_interfaces/srv/ResolveObjectPose_Response";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::ResolveObjectPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::srv::ResolveObjectPose_Response>
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
  const ResolveObjectPose_Event & msg,
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
  const ResolveObjectPose_Event & msg,
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

inline std::string to_yaml(const ResolveObjectPose_Event & msg, bool use_flow_style = false)
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
  const robokpy_interfaces::srv::ResolveObjectPose_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::ResolveObjectPose_Event & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::ResolveObjectPose_Event>()
{
  return "robokpy_interfaces::srv::ResolveObjectPose_Event";
}

template<>
inline const char * name<robokpy_interfaces::srv::ResolveObjectPose_Event>()
{
  return "robokpy_interfaces/srv/ResolveObjectPose_Event";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::ResolveObjectPose_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Event>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Request>::value && has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<robokpy_interfaces::srv::ResolveObjectPose_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robokpy_interfaces::srv::ResolveObjectPose>()
{
  return "robokpy_interfaces::srv::ResolveObjectPose";
}

template<>
inline const char * name<robokpy_interfaces::srv::ResolveObjectPose>()
{
  return "robokpy_interfaces/srv/ResolveObjectPose";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::ResolveObjectPose>
  : std::integral_constant<
    bool,
    has_fixed_size<robokpy_interfaces::srv::ResolveObjectPose_Request>::value &&
    has_fixed_size<robokpy_interfaces::srv::ResolveObjectPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose>
  : std::integral_constant<
    bool,
    has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Request>::value &&
    has_bounded_size<robokpy_interfaces::srv::ResolveObjectPose_Response>::value
  >
{
};

template<>
struct is_service<robokpy_interfaces::srv::ResolveObjectPose>
  : std::true_type
{
};

template<>
struct is_service_request<robokpy_interfaces::srv::ResolveObjectPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robokpy_interfaces::srv::ResolveObjectPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__RESOLVE_OBJECT_POSE__TRAITS_HPP_
