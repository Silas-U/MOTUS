// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mycobot_pro450_interfaces:msg/MycobotSetAngles.idl
// generated code does not contain a copyright notice

#include "mycobot_pro450_interfaces/msg/detail/mycobot_set_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__msg__MycobotSetAngles__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3d, 0xa7, 0x04, 0xf1, 0x15, 0x14, 0x9f, 0x34,
      0x39, 0x87, 0x6e, 0x72, 0x57, 0x44, 0xcb, 0xb2,
      0x10, 0x11, 0xa5, 0xdf, 0xf7, 0x0c, 0xc7, 0x58,
      0x15, 0x05, 0x66, 0x8f, 0x0c, 0x3e, 0x8a, 0x20,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mycobot_pro450_interfaces__msg__MycobotSetAngles__TYPE_NAME[] = "mycobot_pro450_interfaces/msg/MycobotSetAngles";

// Define type names, field names, and default values
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_1[] = "joint_1";
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_2[] = "joint_2";
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_3[] = "joint_3";
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_4[] = "joint_4";
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_5[] = "joint_5";
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_6[] = "joint_6";
static char mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_5, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__joint_6, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mycobot_pro450_interfaces__msg__MycobotSetAngles__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__msg__MycobotSetAngles__TYPE_NAME, 46, 46},
      {mycobot_pro450_interfaces__msg__MycobotSetAngles__FIELDS, 7, 7},
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
  "float32 joint_6\n"
  "\n"
  "int8 speed";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__msg__MycobotSetAngles__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__msg__MycobotSetAngles__TYPE_NAME, 46, 46},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 108, 108},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__msg__MycobotSetAngles__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__msg__MycobotSetAngles__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
