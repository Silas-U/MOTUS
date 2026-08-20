// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robokpy_interfaces:srv/ExecutionState.idl
// generated code does not contain a copyright notice

#include "robokpy_interfaces/srv/detail/execution_state__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ExecutionState__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x49, 0xf8, 0x9f, 0x7a, 0x2a, 0xdf, 0x6e, 0x9b,
      0xe7, 0xd0, 0xfa, 0x7c, 0xec, 0x12, 0x52, 0x48,
      0xeb, 0x37, 0x3d, 0xf1, 0x1d, 0xe0, 0xe8, 0xfb,
      0x01, 0xad, 0x56, 0xdf, 0xfe, 0xe5, 0xf4, 0x84,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ExecutionState_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd8, 0xeb, 0xcd, 0x0e, 0x19, 0x0f, 0x7e, 0xc0,
      0xf6, 0x7f, 0x4d, 0x69, 0xf5, 0xf7, 0x35, 0x5f,
      0xbf, 0x8c, 0xf3, 0x68, 0x5e, 0x82, 0xe9, 0x6b,
      0xa0, 0x27, 0x2e, 0x94, 0xcf, 0xa4, 0xe9, 0xb8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ExecutionState_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xdd, 0xb1, 0xac, 0xb3, 0x54, 0x70, 0xfd, 0x44,
      0x96, 0x91, 0x40, 0x17, 0x4a, 0x0f, 0x34, 0xc2,
      0x0a, 0x2d, 0xa0, 0xe4, 0x1d, 0xce, 0xe3, 0xd5,
      0xd9, 0x80, 0xc0, 0x2a, 0xf9, 0x65, 0xc6, 0xfc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ExecutionState_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x19, 0x67, 0x18, 0xfd, 0xf9, 0xfb, 0x6c, 0xf6,
      0x18, 0xee, 0x67, 0xda, 0xf4, 0x97, 0x49, 0x8f,
      0x16, 0x52, 0x1a, 0x00, 0x67, 0x40, 0x00, 0x35,
      0xb2, 0x43, 0x66, 0x1a, 0x94, 0x73, 0xad, 0xbb,
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

static char robokpy_interfaces__srv__ExecutionState__TYPE_NAME[] = "robokpy_interfaces/srv/ExecutionState";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char robokpy_interfaces__srv__ExecutionState_Event__TYPE_NAME[] = "robokpy_interfaces/srv/ExecutionState_Event";
static char robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME[] = "robokpy_interfaces/srv/ExecutionState_Request";
static char robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME[] = "robokpy_interfaces/srv/ExecutionState_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char robokpy_interfaces__srv__ExecutionState__FIELD_NAME__request_message[] = "request_message";
static char robokpy_interfaces__srv__ExecutionState__FIELD_NAME__response_message[] = "response_message";
static char robokpy_interfaces__srv__ExecutionState__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ExecutionState__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ExecutionState__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ExecutionState_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__ExecutionState__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ExecutionState__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ExecutionState__TYPE_NAME, 37, 37},
      {robokpy_interfaces__srv__ExecutionState__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__ExecutionState__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__ExecutionState_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__ExecutionState_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = robokpy_interfaces__srv__ExecutionState_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ExecutionState_Request__FIELD_NAME__new_state[] = "new_state";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ExecutionState_Request__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ExecutionState_Request__FIELD_NAME__new_state, 9, 9},
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
robokpy_interfaces__srv__ExecutionState_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME, 45, 45},
      {robokpy_interfaces__srv__ExecutionState_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ExecutionState_Response__FIELD_NAME__success[] = "success";
static char robokpy_interfaces__srv__ExecutionState_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ExecutionState_Response__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ExecutionState_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Response__FIELD_NAME__message, 7, 7},
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
robokpy_interfaces__srv__ExecutionState_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME, 46, 46},
      {robokpy_interfaces__srv__ExecutionState_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ExecutionState_Event__FIELD_NAME__info[] = "info";
static char robokpy_interfaces__srv__ExecutionState_Event__FIELD_NAME__request[] = "request";
static char robokpy_interfaces__srv__ExecutionState_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ExecutionState_Event__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ExecutionState_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__ExecutionState_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ExecutionState_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ExecutionState_Event__TYPE_NAME, 43, 43},
      {robokpy_interfaces__srv__ExecutionState_Event__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__ExecutionState_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__ExecutionState_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__ExecutionState_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string new_state\n"
  "\n"
  "---\n"
  "\n"
  "bool success\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ExecutionState__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ExecutionState__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 50, 50},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ExecutionState_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ExecutionState_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ExecutionState_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ExecutionState_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ExecutionState_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ExecutionState_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ExecutionState__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ExecutionState__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__ExecutionState_Event__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__ExecutionState_Request__get_individual_type_description_source(NULL);
    sources[4] = *robokpy_interfaces__srv__ExecutionState_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ExecutionState_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ExecutionState_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ExecutionState_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ExecutionState_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ExecutionState_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ExecutionState_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__ExecutionState_Request__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__ExecutionState_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
