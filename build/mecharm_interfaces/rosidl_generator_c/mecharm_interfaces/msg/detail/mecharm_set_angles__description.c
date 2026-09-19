// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:msg/MecharmSetAngles.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/msg/detail/mecharm_set_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__msg__MecharmSetAngles__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xca, 0xdb, 0x30, 0x03, 0xa9, 0xac, 0xa3, 0x90,
      0x27, 0x43, 0x2b, 0xea, 0x41, 0x79, 0xc9, 0x92,
      0x83, 0x69, 0xc3, 0xd4, 0x07, 0x10, 0x4b, 0xfc,
      0xa5, 0xc6, 0x6c, 0x14, 0xe0, 0xec, 0x8e, 0x07,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mecharm_interfaces__msg__MecharmSetAngles__TYPE_NAME[] = "mecharm_interfaces/msg/MecharmSetAngles";

// Define type names, field names, and default values
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_1[] = "joint_1";
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_2[] = "joint_2";
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_3[] = "joint_3";
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_4[] = "joint_4";
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_5[] = "joint_5";
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_6[] = "joint_6";
static char mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__msg__MecharmSetAngles__FIELDS[] = {
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_5, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__joint_6, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmSetAngles__FIELD_NAME__speed, 5, 5},
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
mecharm_interfaces__msg__MecharmSetAngles__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__msg__MecharmSetAngles__TYPE_NAME, 39, 39},
      {mecharm_interfaces__msg__MecharmSetAngles__FIELDS, 7, 7},
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
mecharm_interfaces__msg__MecharmSetAngles__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__msg__MecharmSetAngles__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 108, 108},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__msg__MecharmSetAngles__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__msg__MecharmSetAngles__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
