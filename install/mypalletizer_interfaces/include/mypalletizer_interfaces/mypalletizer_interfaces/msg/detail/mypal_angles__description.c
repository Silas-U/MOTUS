// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:msg/MypalAngles.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/msg/detail/mypal_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__msg__MypalAngles__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x54, 0xcc, 0x4c, 0xf7, 0xc5, 0x51, 0x7b, 0x13,
      0x1a, 0xe3, 0x6f, 0x68, 0x35, 0x7e, 0x99, 0x84,
      0xb9, 0x15, 0xb3, 0xc9, 0xd6, 0xee, 0x02, 0xda,
      0xe7, 0xdb, 0xa1, 0x22, 0xbc, 0x8f, 0x72, 0x45,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mypalletizer_interfaces__msg__MypalAngles__TYPE_NAME[] = "mypalletizer_interfaces/msg/MypalAngles";

// Define type names, field names, and default values
static char mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_1[] = "joint_1";
static char mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_2[] = "joint_2";
static char mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_3[] = "joint_3";
static char mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_4[] = "joint_4";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__msg__MypalAngles__FIELDS[] = {
  {
    {mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalAngles__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__msg__MypalAngles__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__msg__MypalAngles__TYPE_NAME, 39, 39},
      {mypalletizer_interfaces__msg__MypalAngles__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 joint_1\n"
  "float32 joint_2\n"
  "float32 joint_3\n"
  "float32 joint_4\n"
  "# float32 joint_5\n"
  "# float32 joint_6";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__msg__MypalAngles__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__msg__MypalAngles__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 100, 100},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__msg__MypalAngles__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__msg__MypalAngles__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
