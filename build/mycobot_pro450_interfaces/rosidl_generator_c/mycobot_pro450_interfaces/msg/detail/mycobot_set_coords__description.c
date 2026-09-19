// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mycobot_pro450_interfaces:msg/MycobotSetCoords.idl
// generated code does not contain a copyright notice

#include "mycobot_pro450_interfaces/msg/detail/mycobot_set_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__msg__MycobotSetCoords__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1a, 0x7b, 0x07, 0xae, 0xe6, 0x91, 0x76, 0x6b,
      0x25, 0xfe, 0x71, 0xc4, 0x40, 0x0d, 0xa7, 0x42,
      0x99, 0xc5, 0xe3, 0x8b, 0x9b, 0x77, 0x8b, 0xeb,
      0xa4, 0x21, 0xe3, 0x1e, 0xb4, 0x39, 0xfc, 0xfc,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mycobot_pro450_interfaces__msg__MycobotSetCoords__TYPE_NAME[] = "mycobot_pro450_interfaces/msg/MycobotSetCoords";

// Define type names, field names, and default values
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__x[] = "x";
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__y[] = "y";
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__z[] = "z";
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__rx[] = "rx";
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__ry[] = "ry";
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__rz[] = "rz";
static char mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__rx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__ry, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__rz, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELD_NAME__speed, 5, 5},
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
mycobot_pro450_interfaces__msg__MycobotSetCoords__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__msg__MycobotSetCoords__TYPE_NAME, 46, 46},
      {mycobot_pro450_interfaces__msg__MycobotSetCoords__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "float32 z\n"
  "float32 rx\n"
  "float32 ry\n"
  "float32 rz\n"
  "\n"
  "int8 speed";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__msg__MycobotSetCoords__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__msg__MycobotSetCoords__TYPE_NAME, 46, 46},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 75, 75},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__msg__MycobotSetCoords__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__msg__MycobotSetCoords__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
