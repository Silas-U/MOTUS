// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:msg/MypalCoords.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/msg/detail/mypal_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__msg__MypalCoords__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x35, 0x57, 0xd5, 0xb3, 0x72, 0x56, 0xed, 0x7f,
      0x99, 0x37, 0x6e, 0x53, 0x29, 0x9f, 0xef, 0xad,
      0x3b, 0xa7, 0xa1, 0x22, 0x96, 0x91, 0x2e, 0xc4,
      0x30, 0x16, 0x93, 0xb8, 0x94, 0x78, 0xea, 0x30,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mypalletizer_interfaces__msg__MypalCoords__TYPE_NAME[] = "mypalletizer_interfaces/msg/MypalCoords";

// Define type names, field names, and default values
static char mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__x[] = "x";
static char mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__y[] = "y";
static char mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__z[] = "z";
static char mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__rx[] = "rx";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__msg__MypalCoords__FIELDS[] = {
  {
    {mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalCoords__FIELD_NAME__rx, 2, 2},
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
mypalletizer_interfaces__msg__MypalCoords__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__msg__MypalCoords__TYPE_NAME, 39, 39},
      {mypalletizer_interfaces__msg__MypalCoords__FIELDS, 4, 4},
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
  "# float32 rz";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__msg__MypalCoords__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__msg__MypalCoords__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 66, 66},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__msg__MypalCoords__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__msg__MypalCoords__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
