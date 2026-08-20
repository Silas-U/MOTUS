// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robokpy_interfaces:srv/ChainFK.idl
// generated code does not contain a copyright notice

#include "robokpy_interfaces/srv/detail/chain_fk__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ChainFK__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x14, 0x14, 0x7b, 0xfc, 0x8c, 0x61, 0x7a, 0x4a,
      0xda, 0xe5, 0x95, 0x51, 0xa3, 0xcc, 0xd8, 0xc7,
      0x41, 0x0c, 0x97, 0x2f, 0x33, 0x2a, 0x4b, 0x19,
      0x6f, 0xca, 0x78, 0xa3, 0x17, 0x9b, 0xb7, 0xa0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ChainFK_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa1, 0x46, 0xa5, 0x95, 0xc4, 0xb7, 0x6c, 0x20,
      0x47, 0x6c, 0x56, 0x27, 0xd3, 0x90, 0xff, 0xc1,
      0x0b, 0x4f, 0x8f, 0xcb, 0x49, 0x78, 0x71, 0xa9,
      0x97, 0xa4, 0xf7, 0x06, 0x32, 0xbe, 0xa4, 0x39,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ChainFK_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x77, 0xe0, 0x88, 0x85, 0xff, 0xda, 0x56, 0xa4,
      0xef, 0x51, 0xee, 0x58, 0x42, 0xc2, 0x0d, 0xdc,
      0xdb, 0x53, 0xdb, 0x14, 0xd2, 0xb6, 0x3a, 0xc7,
      0x13, 0x1e, 0xfa, 0x1f, 0x3d, 0x9f, 0x78, 0xc4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ChainFK_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf4, 0x2d, 0x99, 0xc6, 0x30, 0x9a, 0x93, 0x1e,
      0x05, 0x24, 0x3b, 0x0e, 0x9b, 0x91, 0x38, 0x78,
      0x12, 0x08, 0x2c, 0xfc, 0x1a, 0xfe, 0x66, 0xa3,
      0x57, 0xf3, 0x8a, 0x22, 0xd5, 0xa9, 0xb1, 0xf7,
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

static char robokpy_interfaces__srv__ChainFK__TYPE_NAME[] = "robokpy_interfaces/srv/ChainFK";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char robokpy_interfaces__srv__ChainFK_Event__TYPE_NAME[] = "robokpy_interfaces/srv/ChainFK_Event";
static char robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME[] = "robokpy_interfaces/srv/ChainFK_Request";
static char robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME[] = "robokpy_interfaces/srv/ChainFK_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char robokpy_interfaces__srv__ChainFK__FIELD_NAME__request_message[] = "request_message";
static char robokpy_interfaces__srv__ChainFK__FIELD_NAME__response_message[] = "response_message";
static char robokpy_interfaces__srv__ChainFK__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ChainFK__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ChainFK__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ChainFK_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__ChainFK__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ChainFK__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ChainFK__TYPE_NAME, 30, 30},
      {robokpy_interfaces__srv__ChainFK__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__ChainFK__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__ChainFK_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__ChainFK_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = robokpy_interfaces__srv__ChainFK_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ChainFK_Request__FIELD_NAME__q[] = "q";
static char robokpy_interfaces__srv__ChainFK_Request__FIELD_NAME__base_link[] = "base_link";
static char robokpy_interfaces__srv__ChainFK_Request__FIELD_NAME__end_link[] = "end_link";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ChainFK_Request__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ChainFK_Request__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Request__FIELD_NAME__base_link, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Request__FIELD_NAME__end_link, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ChainFK_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME, 38, 38},
      {robokpy_interfaces__srv__ChainFK_Request__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__success[] = "success";
static char robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__pose[] = "pose";
static char robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__pose_euler[] = "pose_euler";
static char robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ChainFK_Response__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__pose, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__pose_euler, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      6,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ChainFK_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME, 39, 39},
      {robokpy_interfaces__srv__ChainFK_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ChainFK_Event__FIELD_NAME__info[] = "info";
static char robokpy_interfaces__srv__ChainFK_Event__FIELD_NAME__request[] = "request";
static char robokpy_interfaces__srv__ChainFK_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ChainFK_Event__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ChainFK_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__ChainFK_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ChainFK_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ChainFK_Event__TYPE_NAME, 36, 36},
      {robokpy_interfaces__srv__ChainFK_Event__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__ChainFK_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__ChainFK_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__ChainFK_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "float64[] q                # joint angles for active joints in chain (radians)\n"
  "string base_link           # name of base link\n"
  "string end_link            # name of end link\n"
  "\n"
  "---\n"
  "\n"
  "# Response\n"
  "bool success\n"
  "float64[7] pose            # [x, y, z, qx, qy, qz, qw]\n"
  "float64[6] pose_euler      # [x, y, z, roll, pitch, yaw] in radians\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ChainFK__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ChainFK__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 350, 350},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ChainFK_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ChainFK_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ChainFK_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ChainFK_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ChainFK_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ChainFK_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ChainFK__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ChainFK__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__ChainFK_Event__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__ChainFK_Request__get_individual_type_description_source(NULL);
    sources[4] = *robokpy_interfaces__srv__ChainFK_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ChainFK_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ChainFK_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ChainFK_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ChainFK_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ChainFK_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ChainFK_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__ChainFK_Request__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__ChainFK_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
