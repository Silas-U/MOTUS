// generated from rosidl_generator_c/resource/idl__type_support.c.em
// with input from mycobot_pro450_interfaces:srv/GripperStatus.idl
// generated code does not contain a copyright notice

#include <string.h>

#include "mycobot_pro450_interfaces/srv/detail/gripper_status__struct.h"
#include "mycobot_pro450_interfaces/srv/detail/gripper_status__functions.h"
#include "mycobot_pro450_interfaces/srv/detail/gripper_status__type_support.h"
#include "rosidl_typesupport_interface/macros.h"

#ifdef __cplusplus
extern "C"
{
#endif


void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  mycobot_pro450_interfaces,
  srv,
  GripperStatus
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message)
{
  if (!allocator || !info) {
    return NULL;
  }
  mycobot_pro450_interfaces__srv__GripperStatus_Event * event_msg = (mycobot_pro450_interfaces__srv__GripperStatus_Event *)(allocator->allocate(sizeof(mycobot_pro450_interfaces__srv__GripperStatus_Event), allocator->state));
  if (!mycobot_pro450_interfaces__srv__GripperStatus_Event__init(event_msg)) {
    allocator->deallocate(event_msg, allocator->state);
    return NULL;
  }

  event_msg->info.event_type = info->event_type;
  event_msg->info.sequence_number = info->sequence_number;
  event_msg->info.stamp.sec = info->stamp_sec;
  event_msg->info.stamp.nanosec = info->stamp_nanosec;
  memcpy(event_msg->info.client_gid, info->client_gid, 16);
  if (request_message) {
    mycobot_pro450_interfaces__srv__GripperStatus_Request__Sequence__init(
      &event_msg->request,
      1);
    if (!mycobot_pro450_interfaces__srv__GripperStatus_Request__copy((const mycobot_pro450_interfaces__srv__GripperStatus_Request *)(request_message), event_msg->request.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  if (response_message) {
    mycobot_pro450_interfaces__srv__GripperStatus_Response__Sequence__init(
      &event_msg->response,
      1);
    if (!mycobot_pro450_interfaces__srv__GripperStatus_Response__copy((const mycobot_pro450_interfaces__srv__GripperStatus_Response *)(response_message), event_msg->response.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  return event_msg;
}

// Forward declare the get type support functions for this type.
bool
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  mycobot_pro450_interfaces,
  srv,
  GripperStatus
)(
  void * event_msg,
  rcutils_allocator_t * allocator)
{
  if (!allocator) {
    return false;
  }
  if (NULL == event_msg) {
    return false;
  }
  mycobot_pro450_interfaces__srv__GripperStatus_Event * _event_msg = (mycobot_pro450_interfaces__srv__GripperStatus_Event *)(event_msg);

  mycobot_pro450_interfaces__srv__GripperStatus_Event__fini((mycobot_pro450_interfaces__srv__GripperStatus_Event *)(_event_msg));
  if (_event_msg->request.data) {
    allocator->deallocate(_event_msg->request.data, allocator->state);
  }
  if (_event_msg->response.data) {
    allocator->deallocate(_event_msg->response.data, allocator->state);
  }
  allocator->deallocate(_event_msg, allocator->state);
  return true;
}

#ifdef __cplusplus
}
#endif
