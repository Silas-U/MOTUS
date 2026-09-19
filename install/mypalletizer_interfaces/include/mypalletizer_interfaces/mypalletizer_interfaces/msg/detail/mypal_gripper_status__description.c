// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:msg/MypalGripperStatus.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/msg/detail/mypal_gripper_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__msg__MypalGripperStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x99, 0x8d, 0xc2, 0x0e, 0x5e, 0x63, 0x19, 0x29,
      0xd4, 0xb2, 0x2d, 0x42, 0x82, 0xe3, 0x27, 0x9f,
      0xa6, 0xde, 0x38, 0x35, 0xc3, 0xaf, 0xa2, 0x0d,
      0x90, 0xab, 0x45, 0x6a, 0x7d, 0x90, 0x12, 0xa8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mypalletizer_interfaces__msg__MypalGripperStatus__TYPE_NAME[] = "mypalletizer_interfaces/msg/MypalGripperStatus";

// Define type names, field names, and default values
static char mypalletizer_interfaces__msg__MypalGripperStatus__FIELD_NAME__status[] = "status";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__msg__MypalGripperStatus__FIELDS[] = {
  {
    {mypalletizer_interfaces__msg__MypalGripperStatus__FIELD_NAME__status, 6, 6},
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
mypalletizer_interfaces__msg__MypalGripperStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__msg__MypalGripperStatus__TYPE_NAME, 46, 46},
      {mypalletizer_interfaces__msg__MypalGripperStatus__FIELDS, 1, 1},
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
mypalletizer_interfaces__msg__MypalGripperStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__msg__MypalGripperStatus__TYPE_NAME, 46, 46},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 11, 11},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__msg__MypalGripperStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__msg__MypalGripperStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
