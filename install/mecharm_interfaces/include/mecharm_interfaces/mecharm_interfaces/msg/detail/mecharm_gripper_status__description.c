// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:msg/MecharmGripperStatus.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/msg/detail/mecharm_gripper_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__msg__MecharmGripperStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xcb, 0xd4, 0xae, 0x1f, 0x31, 0x33, 0x92, 0x43,
      0xa7, 0xe8, 0x17, 0x18, 0xe2, 0x46, 0xdb, 0xe2,
      0xf9, 0xa0, 0xa2, 0x6f, 0xb3, 0xda, 0x59, 0x4f,
      0xad, 0x3a, 0x5b, 0xf0, 0x75, 0x7b, 0xef, 0x95,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mecharm_interfaces__msg__MecharmGripperStatus__TYPE_NAME[] = "mecharm_interfaces/msg/MecharmGripperStatus";

// Define type names, field names, and default values
static char mecharm_interfaces__msg__MecharmGripperStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__msg__MecharmGripperStatus__FIELDS[] = {
  {
    {mecharm_interfaces__msg__MecharmGripperStatus__FIELD_NAME__status, 6, 6},
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
mecharm_interfaces__msg__MecharmGripperStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__msg__MecharmGripperStatus__TYPE_NAME, 43, 43},
      {mecharm_interfaces__msg__MecharmGripperStatus__FIELDS, 1, 1},
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
mecharm_interfaces__msg__MecharmGripperStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__msg__MecharmGripperStatus__TYPE_NAME, 43, 43},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 11, 11},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__msg__MecharmGripperStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__msg__MecharmGripperStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
