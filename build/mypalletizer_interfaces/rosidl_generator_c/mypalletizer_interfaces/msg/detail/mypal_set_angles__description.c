// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:msg/MypalSetAngles.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/msg/detail/mypal_set_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__msg__MypalSetAngles__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0xbf, 0x72, 0x6e, 0x13, 0x15, 0xca, 0x30,
      0x65, 0x75, 0x4c, 0x88, 0xa4, 0x4a, 0x1d, 0xf1,
      0x19, 0xce, 0x1c, 0xb5, 0xde, 0xd4, 0xb9, 0x69,
      0x14, 0x9e, 0xa0, 0x5d, 0xd6, 0xff, 0x77, 0xf2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mypalletizer_interfaces__msg__MypalSetAngles__TYPE_NAME[] = "mypalletizer_interfaces/msg/MypalSetAngles";

// Define type names, field names, and default values
static char mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_1[] = "joint_1";
static char mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_2[] = "joint_2";
static char mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_3[] = "joint_3";
static char mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_4[] = "joint_4";
static char mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__msg__MypalSetAngles__FIELDS[] = {
  {
    {mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetAngles__FIELD_NAME__speed, 5, 5},
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
mypalletizer_interfaces__msg__MypalSetAngles__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__msg__MypalSetAngles__TYPE_NAME, 42, 42},
      {mypalletizer_interfaces__msg__MypalSetAngles__FIELDS, 5, 5},
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
  "# float32 joint_6\n"
  "\n"
  "int8 speed";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__msg__MypalSetAngles__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__msg__MypalSetAngles__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 112, 112},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__msg__MypalSetAngles__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__msg__MypalSetAngles__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
