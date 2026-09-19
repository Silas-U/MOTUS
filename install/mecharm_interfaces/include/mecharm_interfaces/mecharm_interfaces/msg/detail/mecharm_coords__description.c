// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:msg/MecharmCoords.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/msg/detail/mecharm_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__msg__MecharmCoords__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x63, 0x13, 0x9f, 0x1d, 0xa7, 0x04, 0x65, 0xca,
      0xd8, 0x5b, 0xd1, 0xfc, 0x05, 0xa6, 0xf5, 0xf4,
      0xed, 0x91, 0xf8, 0x09, 0xcd, 0xe4, 0xd2, 0x8a,
      0x06, 0xba, 0x4d, 0xfe, 0x33, 0xab, 0xcc, 0x2c,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mecharm_interfaces__msg__MecharmCoords__TYPE_NAME[] = "mecharm_interfaces/msg/MecharmCoords";

// Define type names, field names, and default values
static char mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__x[] = "x";
static char mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__y[] = "y";
static char mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__z[] = "z";
static char mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__rx[] = "rx";
static char mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__ry[] = "ry";
static char mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__rz[] = "rz";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__msg__MecharmCoords__FIELDS[] = {
  {
    {mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__rx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__ry, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmCoords__FIELD_NAME__rz, 2, 2},
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
mecharm_interfaces__msg__MecharmCoords__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__msg__MecharmCoords__TYPE_NAME, 36, 36},
      {mecharm_interfaces__msg__MecharmCoords__FIELDS, 6, 6},
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
  "float32 rz";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__msg__MecharmCoords__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__msg__MecharmCoords__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 62, 62},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__msg__MecharmCoords__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__msg__MecharmCoords__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
