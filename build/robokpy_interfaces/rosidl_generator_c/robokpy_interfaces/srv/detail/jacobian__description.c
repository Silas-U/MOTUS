// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robokpy_interfaces:srv/Jacobian.idl
// generated code does not contain a copyright notice

#include "robokpy_interfaces/srv/detail/jacobian__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__Jacobian__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5a, 0xed, 0xd1, 0x3a, 0x1c, 0xe2, 0x66, 0xd5,
      0x24, 0x4f, 0xcd, 0xc0, 0xf7, 0xd9, 0xec, 0x1b,
      0x14, 0x8c, 0x30, 0xb4, 0x71, 0x7f, 0x01, 0x37,
      0x91, 0x38, 0x54, 0x4b, 0x6d, 0x58, 0xcd, 0xed,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__Jacobian_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x49, 0x58, 0x53, 0xcd, 0xa0, 0x5c, 0xda, 0x89,
      0x79, 0xee, 0x5e, 0xdb, 0xd0, 0x92, 0x56, 0xf5,
      0x93, 0x03, 0x06, 0x68, 0x37, 0xf9, 0xff, 0x67,
      0x54, 0xff, 0x97, 0x70, 0x0c, 0xab, 0x1e, 0x0d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__Jacobian_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x40, 0xc7, 0xe6, 0x92, 0xd6, 0xf8, 0x80, 0x62,
      0x8d, 0x0e, 0x93, 0x12, 0x72, 0x09, 0xae, 0xf6,
      0xc8, 0x85, 0xd5, 0xb8, 0x46, 0xb7, 0xf0, 0x29,
      0x7c, 0xae, 0xc6, 0x7e, 0xf4, 0x0b, 0x77, 0x79,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__Jacobian_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x13, 0xa9, 0xce, 0x80, 0x3c, 0x83, 0x81, 0x09,
      0x45, 0x0a, 0xbf, 0x20, 0x33, 0x7a, 0xfa, 0x92,
      0xae, 0xa4, 0x81, 0x49, 0xbd, 0x02, 0x65, 0xc0,
      0x97, 0x37, 0xc3, 0x92, 0x32, 0xb7, 0x87, 0x5d,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"

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

static char robokpy_interfaces__srv__Jacobian__TYPE_NAME[] = "robokpy_interfaces/srv/Jacobian";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char robokpy_interfaces__srv__Jacobian_Event__TYPE_NAME[] = "robokpy_interfaces/srv/Jacobian_Event";
static char robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME[] = "robokpy_interfaces/srv/Jacobian_Request";
static char robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME[] = "robokpy_interfaces/srv/Jacobian_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char robokpy_interfaces__srv__Jacobian__FIELD_NAME__request_message[] = "request_message";
static char robokpy_interfaces__srv__Jacobian__FIELD_NAME__response_message[] = "response_message";
static char robokpy_interfaces__srv__Jacobian__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__Jacobian__FIELDS[] = {
  {
    {robokpy_interfaces__srv__Jacobian__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__Jacobian_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__Jacobian__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__Jacobian__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__Jacobian__TYPE_NAME, 31, 31},
      {robokpy_interfaces__srv__Jacobian__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__Jacobian__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__Jacobian_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__Jacobian_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = robokpy_interfaces__srv__Jacobian_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__Jacobian_Request__FIELD_NAME__q[] = "q";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__Jacobian_Request__FIELDS[] = {
  {
    {robokpy_interfaces__srv__Jacobian_Request__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__Jacobian_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME, 39, 39},
      {robokpy_interfaces__srv__Jacobian_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__success[] = "success";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__jacobian_flat[] = "jacobian_flat";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__rows[] = "rows";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__cols[] = "cols";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__manipulability[] = "manipulability";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__condition_number[] = "condition_number";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__rank[] = "rank";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__is_near_singular[] = "is_near_singular";
static char robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__Jacobian_Response__FIELDS[] = {
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__jacobian_flat, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__rows, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__cols, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__manipulability, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__condition_number, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__rank, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__is_near_singular, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__FIELD_NAME__message, 7, 7},
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
robokpy_interfaces__srv__Jacobian_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME, 40, 40},
      {robokpy_interfaces__srv__Jacobian_Response__FIELDS, 9, 9},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__Jacobian_Event__FIELD_NAME__info[] = "info";
static char robokpy_interfaces__srv__Jacobian_Event__FIELD_NAME__request[] = "request";
static char robokpy_interfaces__srv__Jacobian_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__Jacobian_Event__FIELDS[] = {
  {
    {robokpy_interfaces__srv__Jacobian_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__Jacobian_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__Jacobian_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__Jacobian_Event__TYPE_NAME, 37, 37},
      {robokpy_interfaces__srv__Jacobian_Event__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__Jacobian_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__Jacobian_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__Jacobian_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "float64[] q                # joint angles in radians\n"
  "\n"
  "---\n"
  "\n"
  "# Response\n"
  "bool success\n"
  "float64[] jacobian_flat    # flattened 6xn Jacobian (row-major: 6*n floats)\n"
  "int32 rows                 # always 6\n"
  "int32 cols                 # n = num_active_joints\n"
  "float64 manipulability     # Yoshikawa manipulability measure\n"
  "float64 condition_number   # SVD condition number\n"
  "int32 rank                 # matrix rank\n"
  "bool is_near_singular      # true if manipulability < threshold\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__Jacobian__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__Jacobian__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 490, 490},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__Jacobian_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__Jacobian_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__Jacobian_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__Jacobian_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__Jacobian_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__Jacobian_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__Jacobian__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__Jacobian__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__Jacobian_Event__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__Jacobian_Request__get_individual_type_description_source(NULL);
    sources[4] = *robokpy_interfaces__srv__Jacobian_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__Jacobian_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__Jacobian_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__Jacobian_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__Jacobian_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__Jacobian_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__Jacobian_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__Jacobian_Request__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__Jacobian_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
