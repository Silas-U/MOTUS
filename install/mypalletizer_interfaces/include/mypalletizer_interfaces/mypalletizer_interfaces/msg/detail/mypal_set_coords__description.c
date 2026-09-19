// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:msg/MypalSetCoords.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/msg/detail/mypal_set_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__msg__MypalSetCoords__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0xec, 0x20, 0xc6, 0x12, 0x3c, 0xb1, 0x5c,
      0xc0, 0xe6, 0xae, 0xcd, 0x29, 0x61, 0x8e, 0xc7,
      0x4e, 0x16, 0x36, 0x49, 0xf5, 0x46, 0x15, 0x22,
      0x0b, 0x5c, 0xc7, 0x32, 0x81, 0x94, 0x8a, 0x0b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mypalletizer_interfaces__msg__MypalSetCoords__TYPE_NAME[] = "mypalletizer_interfaces/msg/MypalSetCoords";

// Define type names, field names, and default values
static char mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__x[] = "x";
static char mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__y[] = "y";
static char mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__z[] = "z";
static char mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__rx[] = "rx";
static char mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__msg__MypalSetCoords__FIELDS[] = {
  {
    {mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__rx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalSetCoords__FIELD_NAME__speed, 5, 5},
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
mypalletizer_interfaces__msg__MypalSetCoords__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__msg__MypalSetCoords__TYPE_NAME, 42, 42},
      {mypalletizer_interfaces__msg__MypalSetCoords__FIELDS, 5, 5},
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
  "# float32 ry\n"
  "# float32 rz\n"
  "\n"
  "int8 speed\n"
  "# int8 model";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__msg__MypalSetCoords__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__msg__MypalSetCoords__TYPE_NAME, 42, 42},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 92, 92},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__msg__MypalSetCoords__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__msg__MypalSetCoords__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
