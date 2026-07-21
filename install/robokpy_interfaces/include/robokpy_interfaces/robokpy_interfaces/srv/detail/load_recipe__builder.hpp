// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robokpy_interfaces:srv/LoadRecipe.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/srv/load_recipe.hpp"


#ifndef ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__BUILDER_HPP_
#define ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robokpy_interfaces/srv/detail/load_recipe__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_LoadRecipe_Request_recipe_path
{
public:
  Init_LoadRecipe_Request_recipe_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robokpy_interfaces::srv::LoadRecipe_Request recipe_path(::robokpy_interfaces::srv::LoadRecipe_Request::_recipe_path_type arg)
  {
    msg_.recipe_path = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::LoadRecipe_Request>()
{
  return robokpy_interfaces::srv::builder::Init_LoadRecipe_Request_recipe_path();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_LoadRecipe_Response_content_hash
{
public:
  explicit Init_LoadRecipe_Response_content_hash(::robokpy_interfaces::srv::LoadRecipe_Response & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::LoadRecipe_Response content_hash(::robokpy_interfaces::srv::LoadRecipe_Response::_content_hash_type arg)
  {
    msg_.content_hash = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Response msg_;
};

class Init_LoadRecipe_Response_recipe_id
{
public:
  explicit Init_LoadRecipe_Response_recipe_id(::robokpy_interfaces::srv::LoadRecipe_Response & msg)
  : msg_(msg)
  {}
  Init_LoadRecipe_Response_content_hash recipe_id(::robokpy_interfaces::srv::LoadRecipe_Response::_recipe_id_type arg)
  {
    msg_.recipe_id = std::move(arg);
    return Init_LoadRecipe_Response_content_hash(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Response msg_;
};

class Init_LoadRecipe_Response_message
{
public:
  explicit Init_LoadRecipe_Response_message(::robokpy_interfaces::srv::LoadRecipe_Response & msg)
  : msg_(msg)
  {}
  Init_LoadRecipe_Response_recipe_id message(::robokpy_interfaces::srv::LoadRecipe_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_LoadRecipe_Response_recipe_id(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Response msg_;
};

class Init_LoadRecipe_Response_success
{
public:
  Init_LoadRecipe_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadRecipe_Response_message success(::robokpy_interfaces::srv::LoadRecipe_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_LoadRecipe_Response_message(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::LoadRecipe_Response>()
{
  return robokpy_interfaces::srv::builder::Init_LoadRecipe_Response_success();
}

}  // namespace robokpy_interfaces


namespace robokpy_interfaces
{

namespace srv
{

namespace builder
{

class Init_LoadRecipe_Event_response
{
public:
  explicit Init_LoadRecipe_Event_response(::robokpy_interfaces::srv::LoadRecipe_Event & msg)
  : msg_(msg)
  {}
  ::robokpy_interfaces::srv::LoadRecipe_Event response(::robokpy_interfaces::srv::LoadRecipe_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Event msg_;
};

class Init_LoadRecipe_Event_request
{
public:
  explicit Init_LoadRecipe_Event_request(::robokpy_interfaces::srv::LoadRecipe_Event & msg)
  : msg_(msg)
  {}
  Init_LoadRecipe_Event_response request(::robokpy_interfaces::srv::LoadRecipe_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_LoadRecipe_Event_response(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Event msg_;
};

class Init_LoadRecipe_Event_info
{
public:
  Init_LoadRecipe_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LoadRecipe_Event_request info(::robokpy_interfaces::srv::LoadRecipe_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_LoadRecipe_Event_request(msg_);
  }

private:
  ::robokpy_interfaces::srv::LoadRecipe_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::robokpy_interfaces::srv::LoadRecipe_Event>()
{
  return robokpy_interfaces::srv::builder::Init_LoadRecipe_Event_info();
}

}  // namespace robokpy_interfaces

#endif  // ROBOKPY_INTERFACES__SRV__DETAIL__LOAD_RECIPE__BUILDER_HPP_
