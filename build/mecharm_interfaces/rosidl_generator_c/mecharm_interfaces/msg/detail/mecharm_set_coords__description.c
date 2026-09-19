// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:msg/MecharmSetCoords.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/msg/detail/mecharm_set_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__msg__MecharmSetCoords__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x35, 0x21, 0x46, 0x02, 0x34, 0xa5, 0xe3, 0x39,
      0x32, 0xac, 0xc6, 0xca, 0xa7, 0xab, 0x0e, 0x89,
      0xbe, 0xc2, 0xad, 0x32, 0x4f, 0xdb, 0xff, 0x76,
      0x74, 0x16, 0xae, 0x19, 0x21, 0x78, 0x02, 0xfb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mecharm_interfaces__msg__MecharmSetCoords__TYPE_NAME[] = "mecharm_interfaces/msg/MecharmSetCoords";

// Define type names, field names, and default values
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__x[] = "x";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__y[] = "y";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__z[] = "z";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__rx[] = "rx";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__ry[] = "ry";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__rz[] = "rz";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__speed[] = "speed";
static char mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__model[] = "model";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__msg__MecharmSetCoords__FIELDS[] = {
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__rx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__ry, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__rz, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetCoords__FIELD_NAME__model, 5, 5},
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
mecharm_interfaces__msg__MecharmSetCoords__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__msg__MecharmSetCoords__TYPE_NAME, 39, 39},
      {mecharm_interfaces__msg__MecharmSetCoords__FIELDS, 8, 8},
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
  "int8 speed\n"
  "int8 model";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__msg__MecharmSetCoords__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__msg__MecharmSetCoords__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 86, 86},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__msg__MecharmSetCoords__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__msg__MecharmSetCoords__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
