// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mecharm_interfaces:srv/SetAngles.idl
// generated code does not contain a copyright notice

#include "mecharm_interfaces/srv/detail/set_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetAngles__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xff, 0x61, 0x56, 0x9b, 0xc5, 0xa6, 0x00, 0x4e,
      0xa2, 0x7c, 0x0a, 0x0c, 0xc3, 0x9f, 0x7b, 0x1f,
      0xef, 0x8d, 0x37, 0x61, 0xc8, 0x6f, 0xb6, 0xcd,
      0xb5, 0xfc, 0xd2, 0x55, 0xe4, 0x2f, 0xfd, 0x7e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetAngles_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x23, 0x11, 0x85, 0x32, 0xd9, 0x00, 0xaa, 0xa6,
      0xe2, 0x02, 0x5f, 0xf2, 0x13, 0x25, 0x0f, 0x65,
      0xd8, 0x22, 0x10, 0x0c, 0x6c, 0xfc, 0x2f, 0x39,
      0x04, 0x93, 0xa8, 0x99, 0xa7, 0x90, 0x46, 0x21,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetAngles_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa4, 0xff, 0xd2, 0x5e, 0x7a, 0x9d, 0x89, 0xab,
      0xc0, 0xf5, 0x0f, 0x95, 0xff, 0xb9, 0x84, 0x3d,
      0x70, 0xdf, 0x20, 0xc4, 0x32, 0x6b, 0x75, 0xb8,
      0x5f, 0xa7, 0xa7, 0xf6, 0xa8, 0x55, 0x71, 0x88,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mecharm_interfaces
const rosidl_type_hash_t *
mecharm_interfaces__srv__SetAngles_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xec, 0xdb, 0x8f, 0x93, 0x06, 0xa4, 0x5d, 0x98,
      0xa2, 0x82, 0xd0, 0xfc, 0x74, 0x92, 0x46, 0xdc,
      0x98, 0x4d, 0xdc, 0x68, 0xf8, 0x39, 0x49, 0x72,
      0x72, 0x88, 0xff, 0x9a, 0xe1, 0x23, 0x98, 0x76,
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

static char mecharm_interfaces__srv__SetAngles__TYPE_NAME[] = "mecharm_interfaces/srv/SetAngles";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mecharm_interfaces__srv__SetAngles_Event__TYPE_NAME[] = "mecharm_interfaces/srv/SetAngles_Event";
static char mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME[] = "mecharm_interfaces/srv/SetAngles_Request";
static char mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME[] = "mecharm_interfaces/srv/SetAngles_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetAngles__FIELD_NAME__request_message[] = "request_message";
static char mecharm_interfaces__srv__SetAngles__FIELD_NAME__response_message[] = "response_message";
static char mecharm_interfaces__srv__SetAngles__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetAngles__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetAngles__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mecharm_interfaces__srv__SetAngles_Event__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mecharm_interfaces__srv__SetAngles__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Event__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mecharm_interfaces__srv__SetAngles__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetAngles__TYPE_NAME, 32, 32},
      {mecharm_interfaces__srv__SetAngles__FIELDS, 3, 3},
    },
    {mecharm_interfaces__srv__SetAngles__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mecharm_interfaces__srv__SetAngles_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mecharm_interfaces__srv__SetAngles_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mecharm_interfaces__srv__SetAngles_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_1[] = "joint_1";
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_2[] = "joint_2";
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_3[] = "joint_3";
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_4[] = "joint_4";
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_5[] = "joint_5";
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_6[] = "joint_6";
static char mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetAngles_Request__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_5, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__joint_6, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__FIELD_NAME__speed, 5, 5},
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
mecharm_interfaces__srv__SetAngles_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME, 40, 40},
      {mecharm_interfaces__srv__SetAngles_Request__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetAngles_Response__FIELD_NAME__flag[] = "flag";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetAngles_Response__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetAngles_Response__FIELD_NAME__flag, 4, 4},
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
mecharm_interfaces__srv__SetAngles_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME, 41, 41},
      {mecharm_interfaces__srv__SetAngles_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mecharm_interfaces__srv__SetAngles_Event__FIELD_NAME__info[] = "info";
static char mecharm_interfaces__srv__SetAngles_Event__FIELD_NAME__request[] = "request";
static char mecharm_interfaces__srv__SetAngles_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mecharm_interfaces__srv__SetAngles_Event__FIELDS[] = {
  {
    {mecharm_interfaces__srv__SetAngles_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME, 41, 41},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mecharm_interfaces__srv__SetAngles_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME, 41, 41},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mecharm_interfaces__srv__SetAngles_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mecharm_interfaces__srv__SetAngles_Event__TYPE_NAME, 38, 38},
      {mecharm_interfaces__srv__SetAngles_Event__FIELDS, 3, 3},
    },
    {mecharm_interfaces__srv__SetAngles_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mecharm_interfaces__srv__SetAngles_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mecharm_interfaces__srv__SetAngles_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
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
  "int8 speed\n"
  "---\n"
  "bool flag";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetAngles__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetAngles__TYPE_NAME, 32, 32},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 120, 120},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetAngles_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetAngles_Request__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetAngles_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetAngles_Response__TYPE_NAME, 41, 41},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mecharm_interfaces__srv__SetAngles_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mecharm_interfaces__srv__SetAngles_Event__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetAngles__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetAngles__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mecharm_interfaces__srv__SetAngles_Event__get_individual_type_description_source(NULL);
    sources[3] = *mecharm_interfaces__srv__SetAngles_Request__get_individual_type_description_source(NULL);
    sources[4] = *mecharm_interfaces__srv__SetAngles_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetAngles_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetAngles_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetAngles_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetAngles_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mecharm_interfaces__srv__SetAngles_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mecharm_interfaces__srv__SetAngles_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mecharm_interfaces__srv__SetAngles_Request__get_individual_type_description_source(NULL);
    sources[3] = *mecharm_interfaces__srv__SetAngles_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
