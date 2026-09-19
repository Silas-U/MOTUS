// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mycobot_pro450_interfaces:msg/MycobotAngles.idl
// generated code does not contain a copyright notice

#include "mycobot_pro450_interfaces/msg/detail/mycobot_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__msg__MycobotAngles__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0xe5, 0x8c, 0x3a, 0x45, 0xf0, 0x37, 0x40,
      0x2d, 0xb9, 0xc8, 0x83, 0xd2, 0xf1, 0xc1, 0x64,
      0x0b, 0x08, 0x3a, 0xc1, 0xa8, 0xc9, 0xee, 0x62,
      0xf6, 0xd0, 0xb7, 0x94, 0x8f, 0x98, 0x42, 0xd6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mycobot_pro450_interfaces__msg__MycobotAngles__TYPE_NAME[] = "mycobot_pro450_interfaces/msg/MycobotAngles";

// Define type names, field names, and default values
static char mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_1[] = "joint_1";
static char mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_2[] = "joint_2";
static char mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_3[] = "joint_3";
static char mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_4[] = "joint_4";
static char mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_5[] = "joint_5";
static char mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_6[] = "joint_6";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__msg__MycobotAngles__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_5, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotAngles__FIELD_NAME__joint_6, 7, 7},
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
mycobot_pro450_interfaces__msg__MycobotAngles__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__msg__MycobotAngles__TYPE_NAME, 43, 43},
      {mycobot_pro450_interfaces__msg__MycobotAngles__FIELDS, 6, 6},
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
  "float32 joint_5\n"
  "float32 joint_6";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__msg__MycobotAngles__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__msg__MycobotAngles__TYPE_NAME, 43, 43},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 96, 96},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__msg__MycobotAngles__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__msg__MycobotAngles__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
