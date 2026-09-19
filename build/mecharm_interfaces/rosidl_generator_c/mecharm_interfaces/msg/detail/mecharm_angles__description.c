// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:msg/MecharmAngles.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/msg/detail/mecharm_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__msg__MecharmAngles__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xca, 0x05, 0x35, 0xb4, 0x4b, 0x78, 0xc6, 0xd8,
      0x08, 0x23, 0xfa, 0x62, 0xff, 0xbe, 0x8d, 0xbe,
      0x04, 0x2b, 0x26, 0x27, 0xba, 0x8e, 0x04, 0x52,
      0x6b, 0xd0, 0xd3, 0xea, 0xe8, 0xda, 0x73, 0x64,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mecharm_interfaces__msg__MecharmAngles__TYPE_NAME[] = "mecharm_interfaces/msg/MecharmAngles";

// Define type names, field names, and default values
static char mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_1[] = "joint_1";
static char mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_2[] = "joint_2";
static char mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_3[] = "joint_3";
static char mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_4[] = "joint_4";
static char mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_5[] = "joint_5";
static char mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_6[] = "joint_6";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__msg__MecharmAngles__FIELDS[] = {
  {
    {mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_5, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmAngles__FIELD_NAME__joint_6, 7, 7},
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
mecharm_interfaces__msg__MecharmAngles__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__msg__MecharmAngles__TYPE_NAME, 36, 36},
      {mecharm_interfaces__msg__MecharmAngles__FIELDS, 6, 6},
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
mecharm_interfaces__msg__MecharmAngles__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__msg__MecharmAngles__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 96, 96},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__msg__MecharmAngles__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__msg__MecharmAngles__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
