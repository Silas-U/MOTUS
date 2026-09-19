// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:msg/MecharmPumpStatus.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/msg/detail/mecharm_pump_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__msg__MecharmPumpStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb4, 0x97, 0xfc, 0xe9, 0x60, 0x2e, 0x08, 0x8d,
      0xd4, 0x32, 0x32, 0x31, 0x8c, 0xff, 0x82, 0x8f,
      0x28, 0xf7, 0x7e, 0xc2, 0xba, 0x46, 0x4c, 0xa5,
      0x91, 0x26, 0x25, 0x86, 0xe4, 0x19, 0x7a, 0x8e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mecharm_interfaces__msg__MecharmPumpStatus__TYPE_NAME[] = "mecharm_interfaces/msg/MecharmPumpStatus";

// Define type names, field names, and default values
static char mecharm_interfaces__msg__MecharmPumpStatus__FIELD_NAME__status[] = "status";
static char mecharm_interfaces__msg__MecharmPumpStatus__FIELD_NAME__pin1[] = "pin1";
static char mecharm_interfaces__msg__MecharmPumpStatus__FIELD_NAME__pin2[] = "pin2";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__msg__MecharmPumpStatus__FIELDS[] = {
  {
    {mecharm_interfaces__msg__MecharmPumpStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmPumpStatus__FIELD_NAME__pin1, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__msg__MecharmPumpStatus__FIELD_NAME__pin2, 4, 4},
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
mecharm_interfaces__msg__MecharmPumpStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__msg__MecharmPumpStatus__TYPE_NAME, 40, 40},
      {mecharm_interfaces__msg__MecharmPumpStatus__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "bool status\n"
  "int8 pin1\n"
  "int8 pin2";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__msg__MecharmPumpStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__msg__MecharmPumpStatus__TYPE_NAME, 40, 40},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 32, 32},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__msg__MecharmPumpStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__msg__MecharmPumpStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
