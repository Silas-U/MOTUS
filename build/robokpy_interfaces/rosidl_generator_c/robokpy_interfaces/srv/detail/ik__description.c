// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robokpy_interfaces:srv/IK.idl
// generated code does not contain a copyright notice

#include "robokpy_interfaces/srv/detail/ik__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__IK__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb5, 0x63, 0xdb, 0x00, 0x0d, 0x7d, 0x96, 0x51,
      0x81, 0x1d, 0xf4, 0xac, 0x9c, 0x03, 0xe3, 0xf3,
      0x2f, 0xdc, 0x4d, 0x1e, 0xaa, 0x3b, 0xf5, 0xf1,
      0x00, 0x0f, 0x2e, 0x82, 0x11, 0x54, 0x8d, 0xe0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__IK_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x10, 0xd8, 0x5a, 0xcd, 0x9b, 0xb5, 0xdc, 0x36,
      0x25, 0xf6, 0xd0, 0x10, 0x77, 0xd8, 0x58, 0x71,
      0xa0, 0xa2, 0x99, 0x4f, 0xed, 0x52, 0x93, 0x87,
      0x38, 0xd7, 0xd3, 0xe6, 0x33, 0xfa, 0x51, 0xf7,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__IK_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf0, 0x6d, 0xb4, 0x93, 0x3b, 0x69, 0xef, 0x25,
      0xa8, 0x60, 0x03, 0x0c, 0xa4, 0x4a, 0x30, 0x43,
      0x76, 0x3b, 0x22, 0x01, 0x9b, 0x8f, 0xfe, 0x9e,
      0x5b, 0x04, 0x8d, 0xdc, 0x8d, 0xde, 0x86, 0x6d,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__IK_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe7, 0xf4, 0x3a, 0x53, 0xb4, 0x96, 0x02, 0x33,
      0x93, 0x2f, 0xe9, 0x96, 0x46, 0x75, 0xed, 0x32,
      0x38, 0xa2, 0x2b, 0x58, 0x9a, 0x1d, 0x23, 0x7a,
      0x3d, 0x01, 0x50, 0x83, 0xbd, 0x11, 0x7c, 0x10,
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

static char robokpy_interfaces__srv__IK__TYPE_NAME[] = "robokpy_interfaces/srv/IK";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char robokpy_interfaces__srv__IK_Event__TYPE_NAME[] = "robokpy_interfaces/srv/IK_Event";
static char robokpy_interfaces__srv__IK_Request__TYPE_NAME[] = "robokpy_interfaces/srv/IK_Request";
static char robokpy_interfaces__srv__IK_Response__TYPE_NAME[] = "robokpy_interfaces/srv/IK_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char robokpy_interfaces__srv__IK__FIELD_NAME__request_message[] = "request_message";
static char robokpy_interfaces__srv__IK__FIELD_NAME__response_message[] = "response_message";
static char robokpy_interfaces__srv__IK__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__IK__FIELDS[] = {
  {
    {robokpy_interfaces__srv__IK__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__IK_Request__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__IK_Response__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__IK_Event__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__IK__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Event__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Request__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Response__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__IK__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__IK__TYPE_NAME, 25, 25},
      {robokpy_interfaces__srv__IK__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__IK__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__IK_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__IK_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = robokpy_interfaces__srv__IK_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__IK_Request__FIELD_NAME__target_pose[] = "target_pose";
static char robokpy_interfaces__srv__IK_Request__FIELD_NAME__mask[] = "mask";
static char robokpy_interfaces__srv__IK_Request__FIELD_NAME__seed[] = "seed";
static char robokpy_interfaces__srv__IK_Request__FIELD_NAME__tol[] = "tol";
static char robokpy_interfaces__srv__IK_Request__FIELD_NAME__max_iter[] = "max_iter";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__IK_Request__FIELDS[] = {
  {
    {robokpy_interfaces__srv__IK_Request__FIELD_NAME__target_pose, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      7,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Request__FIELD_NAME__mask, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Request__FIELD_NAME__seed, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Request__FIELD_NAME__tol, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Request__FIELD_NAME__max_iter, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__IK_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__IK_Request__TYPE_NAME, 33, 33},
      {robokpy_interfaces__srv__IK_Request__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__IK_Response__FIELD_NAME__success[] = "success";
static char robokpy_interfaces__srv__IK_Response__FIELD_NAME__q[] = "q";
static char robokpy_interfaces__srv__IK_Response__FIELD_NAME__error[] = "error";
static char robokpy_interfaces__srv__IK_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__IK_Response__FIELDS[] = {
  {
    {robokpy_interfaces__srv__IK_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Response__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Response__FIELD_NAME__error, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Response__FIELD_NAME__message, 7, 7},
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
robokpy_interfaces__srv__IK_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__IK_Response__TYPE_NAME, 34, 34},
      {robokpy_interfaces__srv__IK_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__IK_Event__FIELD_NAME__info[] = "info";
static char robokpy_interfaces__srv__IK_Event__FIELD_NAME__request[] = "request";
static char robokpy_interfaces__srv__IK_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__IK_Event__FIELDS[] = {
  {
    {robokpy_interfaces__srv__IK_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__IK_Request__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__IK_Response__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__IK_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Request__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__IK_Response__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__IK_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__IK_Event__TYPE_NAME, 31, 31},
      {robokpy_interfaces__srv__IK_Event__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__IK_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__IK_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__IK_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "float64[7] target_pose     # [x, y, z, qx, qy, qz, qw]\n"
  "int32[] mask               # [px, py, pz, rx, ry, rz] \\xe2\\x80\\x94 1=constrained, 0=free\n"
  "float64[] seed             # initial joint config seed (optional, empty = zeros)\n"
  "float64 tol                # convergence tolerance (default 1e-3 if 0)\n"
  "int32 max_iter             # max iterations (default 30 if 0)\n"
  "\n"
  "---\n"
  "\n"
  "# Response\n"
  "bool success\n"
  "float64[] q                # joint angles in radians\n"
  "float64 error              # final error norm\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__IK__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__IK__TYPE_NAME, 25, 25},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 501, 501},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__IK_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__IK_Request__TYPE_NAME, 33, 33},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__IK_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__IK_Response__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__IK_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__IK_Event__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__IK__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__IK__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__IK_Event__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__IK_Request__get_individual_type_description_source(NULL);
    sources[4] = *robokpy_interfaces__srv__IK_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__IK_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__IK_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__IK_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__IK_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__IK_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__IK_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__IK_Request__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__IK_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
