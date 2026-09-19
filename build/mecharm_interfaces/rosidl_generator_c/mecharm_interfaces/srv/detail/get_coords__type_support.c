// generated from rosidl_generator_c/resource/idl__type_support.c.em
// with input from mecharm_interfaces:srv/GetCoords.idl
// generated code does not contain a copyright notice

#include <string.h>

#include "rosidl_typesupport_interface/macros.h"
#include "mecharm_interfaces/srv/detail/get_coords__type_support.h"
#include "mecharm_interfaces/srv/detail/get_coords__functions.h"
#include "mecharm_interfaces/srv/detail/get_coords__struct.h"

#ifdef __cplusplus
extern "C"
{
#endif


void *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
  rosidl_typesupport_c,
  mecharm_interfaces,
  srv,
  GetCoords
)(
  const rosidl_service_introspection_info_t * info,
  rcutils_allocator_t * allocator,
  const void * request_message,
  const void * response_message)
{
  if (!allocator || !info) {
    return NULL;
  }
  mecharm_interfaces__srv__GetCoords_Event * event_msg = (mecharm_interfaces__srv__GetCoords_Event *)(allocator->allocate(sizeof(mecharm_interfaces__srv__GetCoords_Event), allocator->state));
  if (!mecharm_interfaces__srv__GetCoords_Event__init(event_msg)) {
    allocator->deallocate(event_msg, allocator->state);
    return NULL;
  }

  event_msg->info.event_type = info->event_type;
  event_msg->info.sequence_number = info->sequence_number;
  event_msg->info.stamp.sec = info->stamp_sec;
  event_msg->info.stamp.nanosec = info->stamp_nanosec;
  memcpy(event_msg->info.client_gid, info->client_gid, 16);
  if (request_message) {
    mecharm_interfaces__srv__GetCoords_Request__Sequence__init(
      &event_msg->request,
      1);
    if (!mecharm_interfaces__srv__GetCoords_Request__copy((const mecharm_interfaces__srv__GetCoords_Request *)(request_message), event_msg->request.data)) {
      allocator->deallocate(event_msg, allocator->state);
      return NULL;
    }
  }
  if (response_message) {
    mecharm_interfaces__srv__GetCoords_Response__Sequence__init(
      &event_msg->response,
      1);
    if (!mecharm_interfaces__srv__GetCoords_Response__copy((const mecharm_interfaces__srv__GetCoords_Response *)(response_message), event_msg->response.data)) {
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
  mecharm_interfaces,
  srv,
  GetCoords
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
  mecharm_interfaces__srv__GetCoords_Event * _event_msg = (mecharm_interfaces__srv__GetCoords_Event *)(event_msg);

  mecharm_interfaces__srv__GetCoords_Event__fini((mecharm_interfaces__srv__GetCoords_Event *)(_event_msg));
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
