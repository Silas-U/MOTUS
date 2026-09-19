// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:srv/SetCoords.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/srv/detail/set_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetCoords__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd1, 0xd8, 0x41, 0x5e, 0xda, 0xdf, 0x26, 0xa4,
      0xd1, 0xd7, 0x94, 0xd6, 0xd5, 0x43, 0x0f, 0xae,
      0xd1, 0x6c, 0xea, 0x18, 0xfb, 0x14, 0xc9, 0x94,
      0x71, 0x4a, 0xb4, 0x58, 0xef, 0x21, 0x6f, 0x5a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetCoords_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0x8c, 0xc6, 0x9e, 0xac, 0xdd, 0x23, 0x94,
      0x5b, 0x43, 0x2c, 0x9e, 0xeb, 0x54, 0x7a, 0xc7,
      0x81, 0xcd, 0x22, 0x27, 0xab, 0x2a, 0x4b, 0x8e,
      0x4b, 0x21, 0x62, 0xef, 0x57, 0xb5, 0x49, 0x99,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetCoords_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3a, 0x52, 0x82, 0x74, 0x53, 0x32, 0x25, 0x18,
      0xc7, 0x5b, 0x74, 0x00, 0x66, 0x0f, 0x6c, 0xdb,
      0x57, 0x94, 0x5f, 0xaf, 0x4d, 0xdf, 0x7e, 0x0c,
      0xa7, 0x79, 0x11, 0x9c, 0x44, 0x97, 0xd1, 0x09,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetCoords_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0xa9, 0xc9, 0xba, 0x79, 0xe3, 0x72, 0x1e,
      0x3f, 0xae, 0x97, 0xbc, 0x46, 0x71, 0x56, 0x26,
      0x5d, 0xb3, 0xc5, 0x4b, 0xca, 0xf4, 0x11, 0xe7,
      0x09, 0x53, 0x37, 0x7a, 0x85, 0x31, 0xcd, 0x24,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char mecharm_interfaces__srv__SetCoords__TYPE_NAME[] = "mecharm_interfaces/srv/SetCoords";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mecharm_interfaces__srv__SetCoords_Event__TYPE_NAME[] = "mecharm_interfaces/srv/SetCoords_Event";
static char mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME[] = "mecharm_interfaces/srv/SetCoords_Request";
static char mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME[] = "mecharm_interfaces/srv/SetCoords_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetCoords__FIELD_NAME__request_message[] = "request_message";
static char mecharm_interfaces__srv__SetCoords__FIELD_NAME__response_message[] = "response_message";
static char mecharm_interfaces__srv__SetCoords__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetCoords__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetCoords__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mecharm_interfaces__srv__SetCoords_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mecharm_interfaces__srv__SetCoords__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mecharm_interfaces__srv__SetCoords__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetCoords__TYPE_NAME, 32, 32},
      {mecharm_interfaces__srv__SetCoords__FIELDS, 3, 3},
    },
    {mecharm_interfaces__srv__SetCoords__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mecharm_interfaces__srv__SetCoords_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mecharm_interfaces__srv__SetCoords_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mecharm_interfaces__srv__SetCoords_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__x[] = "x";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__y[] = "y";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__z[] = "z";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__rx[] = "rx";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__ry[] = "ry";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__rz[] = "rz";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__speed[] = "speed";
static char mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__model[] = "model";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetCoords_Request__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__rx, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__ry, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__rz, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__FIELD_NAME__model, 5, 5},
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
mecharm_interfaces__srv__SetCoords_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME, 40, 40},
      {mecharm_interfaces__srv__SetCoords_Request__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetCoords_Response__FIELD_NAME__flag[] = "flag";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetCoords_Response__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetCoords_Response__FIELD_NAME__flag, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mecharm_interfaces__srv__SetCoords_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME, 41, 41},
      {mecharm_interfaces__srv__SetCoords_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetCoords_Event__FIELD_NAME__info[] = "info";
static char mecharm_interfaces__srv__SetCoords_Event__FIELD_NAME__request[] = "request";
static char mecharm_interfaces__srv__SetCoords_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetCoords_Event__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetCoords_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mecharm_interfaces__srv__SetCoords_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mecharm_interfaces__srv__SetCoords_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetCoords_Event__TYPE_NAME, 38, 38},
      {mecharm_interfaces__srv__SetCoords_Event__FIELDS, 3, 3},
    },
    {mecharm_interfaces__srv__SetCoords_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mecharm_interfaces__srv__SetCoords_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mecharm_interfaces__srv__SetCoords_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
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
  "int8 speed\n"
  "int8 model\n"
  "---\n"
  "bool flag";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetCoords__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetCoords__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 98, 98},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetCoords_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetCoords_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetCoords_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetCoords_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetCoords_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetCoords_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetCoords__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetCoords__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mecharm_interfaces__srv__SetCoords_Event__get_individual_type_description_source(NULL);
    sources[3] = *mecharm_interfaces__srv__SetCoords_Request__get_individual_type_description_source(NULL);
    sources[4] = *mecharm_interfaces__srv__SetCoords_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetCoords_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetCoords_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetCoords_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetCoords_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetCoords_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetCoords_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mecharm_interfaces__srv__SetCoords_Request__get_individual_type_description_source(NULL);
    sources[3] = *mecharm_interfaces__srv__SetCoords_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
