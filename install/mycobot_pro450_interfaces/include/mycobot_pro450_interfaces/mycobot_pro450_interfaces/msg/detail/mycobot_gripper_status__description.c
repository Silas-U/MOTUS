// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mycobot_pro450_interfaces:msg/MycobotGripperStatus.idl
// generated code does not contain a copyright notice

#include "mycobot_pro450_interfaces/msg/detail/mycobot_gripper_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__msg__MycobotGripperStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x0d, 0xc9, 0x1b, 0x4c, 0x92, 0x45, 0x68, 0xdb,
      0x18, 0x2c, 0x8c, 0xd3, 0xa6, 0xfd, 0x24, 0x2c,
      0x00, 0x72, 0x8c, 0x2b, 0x07, 0x28, 0xc4, 0xd1,
      0x48, 0xca, 0x21, 0x22, 0x3e, 0x66, 0x74, 0x09,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mycobot_pro450_interfaces__msg__MycobotGripperStatus__TYPE_NAME[] = "mycobot_pro450_interfaces/msg/MycobotGripperStatus";

// Define type names, field names, and default values
static char mycobot_pro450_interfaces__msg__MycobotGripperStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__msg__MycobotGripperStatus__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__msg__MycobotGripperStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mycobot_pro450_interfaces__msg__MycobotGripperStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__msg__MycobotGripperStatus__TYPE_NAME, 50, 50},
      {mycobot_pro450_interfaces__msg__MycobotGripperStatus__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool status";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__msg__MycobotGripperStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__msg__MycobotGripperStatus__TYPE_NAME, 50, 50},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 11, 11},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__msg__MycobotGripperStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__msg__MycobotGripperStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
