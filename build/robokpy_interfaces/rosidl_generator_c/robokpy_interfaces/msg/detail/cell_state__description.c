// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robokpy_interfaces:msg/CellState.idl
// generated code does not contain a copyright notice

#include "robokpy_interfaces/msg/detail/cell_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__msg__CellState__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3f, 0x5e, 0x86, 0x02, 0xb3, 0x75, 0x6c, 0xb9,
      0x95, 0x9e, 0x3e, 0xaa, 0xc3, 0xfe, 0x98, 0x65,
      0xa8, 0x24, 0xeb, 0xe3, 0x97, 0xe2, 0xe4, 0x3c,
      0x55, 0x8f, 0xbe, 0xa0, 0x75, 0x9e, 0x4f, 0x9d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
#endif

static char robokpy_interfaces__msg__CellState__TYPE_NAME[] = "robokpy_interfaces/msg/CellState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";

// Define type names, field names, and default values
static char robokpy_interfaces__msg__CellState__FIELD_NAME__state[] = "state";
static char robokpy_interfaces__msg__CellState__FIELD_NAME__active_recipe_id[] = "active_recipe_id";
static char robokpy_interfaces__msg__CellState__FIELD_NAME__last_error[] = "last_error";
static char robokpy_interfaces__msg__CellState__FIELD_NAME__stamp[] = "stamp";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__msg__CellState__FIELDS[] = {
  {
    {robokpy_interfaces__msg__CellState__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__msg__CellState__FIELD_NAME__active_recipe_id, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__msg__CellState__FIELD_NAME__last_error, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__msg__CellState__FIELD_NAME__stamp, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__msg__CellState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__msg__CellState__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__msg__CellState__TYPE_NAME, 32, 32},
      {robokpy_interfaces__msg__CellState__FIELDS, 4, 4},
    },
    {robokpy_interfaces__msg__CellState__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint8 IDLE=0\n"
  "uint8 PLANNING=1\n"
  "uint8 EXECUTING=2\n"
  "uint8 PAUSED=3\n"
  "uint8 ERROR=4\n"
  "uint8 ESTOP=5\n"
  "\n"
  "uint8 state\n"
  "string active_recipe_id\n"
  "string last_error\n"
  "builtin_interfaces/Time stamp";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__msg__CellState__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__msg__CellState__TYPE_NAME, 32, 32},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 175, 175},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__msg__CellState__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__msg__CellState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
