// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:msg/MypalPumpStatus.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/msg/detail/mypal_pump_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__msg__MypalPumpStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x62, 0x1c, 0x8b, 0x93, 0xdd, 0xd4, 0xa4, 0x2b,
      0x2a, 0xb6, 0xa1, 0xfd, 0x25, 0x34, 0xd7, 0x93,
      0xae, 0x1c, 0xc7, 0xf0, 0x4f, 0xfa, 0xe2, 0x4e,
      0x79, 0x4f, 0x4c, 0x08, 0x06, 0x58, 0xab, 0x76,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char mypalletizer_interfaces__msg__MypalPumpStatus__TYPE_NAME[] = "mypalletizer_interfaces/msg/MypalPumpStatus";

// Define type names, field names, and default values
static char mypalletizer_interfaces__msg__MypalPumpStatus__FIELD_NAME__status[] = "status";
static char mypalletizer_interfaces__msg__MypalPumpStatus__FIELD_NAME__pin1[] = "pin1";
static char mypalletizer_interfaces__msg__MypalPumpStatus__FIELD_NAME__pin2[] = "pin2";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__msg__MypalPumpStatus__FIELDS[] = {
  {
    {mypalletizer_interfaces__msg__MypalPumpStatus__FIELD_NAME__status, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalPumpStatus__FIELD_NAME__pin1, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__msg__MypalPumpStatus__FIELD_NAME__pin2, 4, 4},
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
mypalletizer_interfaces__msg__MypalPumpStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__msg__MypalPumpStatus__TYPE_NAME, 43, 43},
      {mypalletizer_interfaces__msg__MypalPumpStatus__FIELDS, 3, 3},
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
mypalletizer_interfaces__msg__MypalPumpStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__msg__MypalPumpStatus__TYPE_NAME, 43, 43},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 32, 32},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__msg__MypalPumpStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__msg__MypalPumpStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
