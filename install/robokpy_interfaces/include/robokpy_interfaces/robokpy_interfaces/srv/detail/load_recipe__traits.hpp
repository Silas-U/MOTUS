// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robokpy_interfaces:srv/LoadRecipe.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/load_recipe.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__TRAITS_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robokpy_interfaces/srv/detail/load_recipe__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadRecipe_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: recipe_path
  {
    out << "recipe_path: ";
    rosidl_generator_traits::value_to_yaml(msg.recipe_path, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LoadRecipe_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: recipe_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "recipe_path: ";
    rosidl_generator_traits::value_to_yaml(msg.recipe_path, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LoadRecipe_Request & msg, bool use_flow_style = false)
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
  const robokpy_interfaces::srv::LoadRecipe_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::LoadRecipe_Request & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::LoadRecipe_Request>()
{
  return "robokpy_interfaces::srv::LoadRecipe_Request";
}

template<>
inline const char * name<robokpy_interfaces::srv::LoadRecipe_Request>()
{
  return "robokpy_interfaces/srv/LoadRecipe_Request";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::LoadRecipe_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::srv::LoadRecipe_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robokpy_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const LoadRecipe_Response & msg,
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
    out << ", ";
  }

  // member: recipe_id
  {
    out << "recipe_id: ";
    rosidl_generator_traits::value_to_yaml(msg.recipe_id, out);
    out << ", ";
  }

  // member: content_hash
  {
    out << "content_hash: ";
    rosidl_generator_traits::value_to_yaml(msg.content_hash, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LoadRecipe_Response & msg,
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

  // member: recipe_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "recipe_id: ";
    rosidl_generator_traits::value_to_yaml(msg.recipe_id, out);
    out << "\n";
  }

  // member: content_hash
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "content_hash: ";
    rosidl_generator_traits::value_to_yaml(msg.content_hash, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LoadRecipe_Response & msg, bool use_flow_style = false)
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
  const robokpy_interfaces::srv::LoadRecipe_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::LoadRecipe_Response & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::LoadRecipe_Response>()
{
  return "robokpy_interfaces::srv::LoadRecipe_Response";
}

template<>
inline const char * name<robokpy_interfaces::srv::LoadRecipe_Response>()
{
  return "robokpy_interfaces/srv/LoadRecipe_Response";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::LoadRecipe_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robokpy_interfaces::srv::LoadRecipe_Response>
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
  const LoadRecipe_Event & msg,
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
  const LoadRecipe_Event & msg,
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

inline std::string to_yaml(const LoadRecipe_Event & msg, bool use_flow_style = false)
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
  const robokpy_interfaces::srv::LoadRecipe_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  robokpy_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robokpy_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const robokpy_interfaces::srv::LoadRecipe_Event & msg)
{
  return robokpy_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robokpy_interfaces::srv::LoadRecipe_Event>()
{
  return "robokpy_interfaces::srv::LoadRecipe_Event";
}

template<>
inline const char * name<robokpy_interfaces::srv::LoadRecipe_Event>()
{
  return "robokpy_interfaces/srv/LoadRecipe_Event";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::LoadRecipe_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Event>
  : std::integral_constant<bool, has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Request>::value && has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<robokpy_interfaces::srv::LoadRecipe_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robokpy_interfaces::srv::LoadRecipe>()
{
  return "robokpy_interfaces::srv::LoadRecipe";
}

template<>
inline const char * name<robokpy_interfaces::srv::LoadRecipe>()
{
  return "robokpy_interfaces/srv/LoadRecipe";
}

template<>
struct has_fixed_size<robokpy_interfaces::srv::LoadRecipe>
  : std::integral_constant<
    bool,
    has_fixed_size<robokpy_interfaces::srv::LoadRecipe_Request>::value &&
    has_fixed_size<robokpy_interfaces::srv::LoadRecipe_Response>::value
  >
{
};

template<>
struct has_bounded_size<robokpy_interfaces::srv::LoadRecipe>
  : std::integral_constant<
    bool,
    has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Request>::value &&
    has_bounded_size<robokpy_interfaces::srv::LoadRecipe_Response>::value
  >
{
};

template<>
struct is_service<robokpy_interfaces::srv::LoadRecipe>
  : std::true_type
{
};

template<>
struct is_service_request<robokpy_interfaces::srv::LoadRecipe_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robokpy_interfaces::srv::LoadRecipe_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__TRAITS_HPP_
