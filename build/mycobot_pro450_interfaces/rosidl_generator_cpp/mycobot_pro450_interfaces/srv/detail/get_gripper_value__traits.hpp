// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mycobot_pro450_interfaces:srv/GetGripperValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "mycobot_pro450_interfaces/srv/get_gripper_value.hpp"


#ifndef MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__TRAITS_HPP_
#define MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mycobot_pro450_interfaces/srv/detail/get_gripper_value__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mycobot_pro450_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetGripperValue_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetGripperValue_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetGripperValue_Request & msg, bool use_flow_style = false)
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

}  // namespace mycobot_pro450_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mycobot_pro450_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mycobot_pro450_interfaces::srv::GetGripperValue_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_pro450_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_pro450_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_pro450_interfaces::srv::GetGripperValue_Request & msg)
{
  return mycobot_pro450_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_pro450_interfaces::srv::GetGripperValue_Request>()
{
  return "mycobot_pro450_interfaces::srv::GetGripperValue_Request";
}

template<>
inline const char * name<mycobot_pro450_interfaces::srv::GetGripperValue_Request>()
{
  return "mycobot_pro450_interfaces/srv/GetGripperValue_Request";
}

template<>
struct has_fixed_size<mycobot_pro450_interfaces::srv::GetGripperValue_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mycobot_pro450_interfaces::srv::GetGripperValue_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mycobot_pro450_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetGripperValue_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: gripper_angle
  {
    out << "gripper_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetGripperValue_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: gripper_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetGripperValue_Response & msg, bool use_flow_style = false)
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

}  // namespace mycobot_pro450_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mycobot_pro450_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mycobot_pro450_interfaces::srv::GetGripperValue_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_pro450_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_pro450_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_pro450_interfaces::srv::GetGripperValue_Response & msg)
{
  return mycobot_pro450_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_pro450_interfaces::srv::GetGripperValue_Response>()
{
  return "mycobot_pro450_interfaces::srv::GetGripperValue_Response";
}

template<>
inline const char * name<mycobot_pro450_interfaces::srv::GetGripperValue_Response>()
{
  return "mycobot_pro450_interfaces/srv/GetGripperValue_Response";
}

template<>
struct has_fixed_size<mycobot_pro450_interfaces::srv::GetGripperValue_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mycobot_pro450_interfaces::srv::GetGripperValue_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace mycobot_pro450_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetGripperValue_Event & msg,
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
  const GetGripperValue_Event & msg,
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

inline std::string to_yaml(const GetGripperValue_Event & msg, bool use_flow_style = false)
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

}  // namespace mycobot_pro450_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use mycobot_pro450_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mycobot_pro450_interfaces::srv::GetGripperValue_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  mycobot_pro450_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mycobot_pro450_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const mycobot_pro450_interfaces::srv::GetGripperValue_Event & msg)
{
  return mycobot_pro450_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mycobot_pro450_interfaces::srv::GetGripperValue_Event>()
{
  return "mycobot_pro450_interfaces::srv::GetGripperValue_Event";
}

template<>
inline const char * name<mycobot_pro450_interfaces::srv::GetGripperValue_Event>()
{
  return "mycobot_pro450_interfaces/srv/GetGripperValue_Event";
}

template<>
struct has_fixed_size<mycobot_pro450_interfaces::srv::GetGripperValue_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Event>
  : std::integral_constant<bool, has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Request>::value && has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<mycobot_pro450_interfaces::srv::GetGripperValue_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mycobot_pro450_interfaces::srv::GetGripperValue>()
{
  return "mycobot_pro450_interfaces::srv::GetGripperValue";
}

template<>
inline const char * name<mycobot_pro450_interfaces::srv::GetGripperValue>()
{
  return "mycobot_pro450_interfaces/srv/GetGripperValue";
}

template<>
struct has_fixed_size<mycobot_pro450_interfaces::srv::GetGripperValue>
  : std::integral_constant<
    bool,
    has_fixed_size<mycobot_pro450_interfaces::srv::GetGripperValue_Request>::value &&
    has_fixed_size<mycobot_pro450_interfaces::srv::GetGripperValue_Response>::value
  >
{
};

template<>
struct has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue>
  : std::integral_constant<
    bool,
    has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Request>::value &&
    has_bounded_size<mycobot_pro450_interfaces::srv::GetGripperValue_Response>::value
  >
{
};

template<>
struct is_service<mycobot_pro450_interfaces::srv::GetGripperValue>
  : std::true_type
{
};

template<>
struct is_service_request<mycobot_pro450_interfaces::srv::GetGripperValue_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mycobot_pro450_interfaces::srv::GetGripperValue_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MYCOBOT_PRO450_INTERFACES__SRV__DETAIL__GET_GRIPPER_VALUE__TRAITS_HPP_
