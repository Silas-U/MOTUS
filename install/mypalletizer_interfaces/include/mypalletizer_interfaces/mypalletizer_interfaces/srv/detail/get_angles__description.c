// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:srv/GetAngles.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/srv/detail/get_angles__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetAngles__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc9, 0xd5, 0x30, 0xf7, 0xac, 0xef, 0x2f, 0x2c,
      0x33, 0xeb, 0x83, 0x47, 0x11, 0x55, 0x09, 0x59,
      0x52, 0xba, 0x69, 0x37, 0x28, 0x99, 0xcc, 0xf1,
      0x0a, 0x30, 0x84, 0xca, 0x9e, 0x6b, 0x02, 0xee,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetAngles_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa5, 0x57, 0x02, 0x7e, 0x52, 0xfd, 0x63, 0x13,
      0xdc, 0xdc, 0x21, 0x59, 0x6e, 0x1c, 0xfb, 0xc9,
      0x4c, 0x7f, 0x8e, 0x14, 0x21, 0xb3, 0x16, 0x07,
      0xeb, 0xff, 0x50, 0x4b, 0x76, 0xfb, 0x39, 0xa1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetAngles_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa6, 0x8a, 0x77, 0x08, 0xa9, 0x76, 0xa5, 0xb2,
      0xec, 0x92, 0xbd, 0xf8, 0xdd, 0x9b, 0x61, 0x24,
      0x56, 0xa3, 0x48, 0xca, 0x12, 0xf4, 0x7c, 0x5c,
      0xd4, 0x7a, 0xa8, 0xc8, 0xdd, 0x24, 0x53, 0x84,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetAngles_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x97, 0x6f, 0x88, 0x5b, 0x59, 0xa2, 0xb8, 0xbb,
      0xa5, 0x45, 0x97, 0x90, 0xa0, 0x7d, 0x58, 0x6b,
      0x20, 0x15, 0xc1, 0x5c, 0x1c, 0x16, 0x04, 0x3c,
      0xb6, 0xe0, 0x53, 0xd5, 0xcd, 0x30, 0x3e, 0x57,
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

static char mypalletizer_interfaces__srv__GetAngles__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetAngles";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mypalletizer_interfaces__srv__GetAngles_Event__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetAngles_Event";
static char mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetAngles_Request";
static char mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetAngles_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetAngles__FIELD_NAME__request_message[] = "request_message";
static char mypalletizer_interfaces__srv__GetAngles__FIELD_NAME__response_message[] = "response_message";
static char mypalletizer_interfaces__srv__GetAngles__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetAngles__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetAngles__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mypalletizer_interfaces__srv__GetAngles_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mypalletizer_interfaces__srv__GetAngles__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__srv__GetAngles__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetAngles__TYPE_NAME, 37, 37},
      {mypalletizer_interfaces__srv__GetAngles__FIELDS, 3, 3},
    },
    {mypalletizer_interfaces__srv__GetAngles__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mypalletizer_interfaces__srv__GetAngles_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mypalletizer_interfaces__srv__GetAngles_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mypalletizer_interfaces__srv__GetAngles_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetAngles_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetAngles_Request__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetAngles_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__srv__GetAngles_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME, 45, 45},
      {mypalletizer_interfaces__srv__GetAngles_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_1[] = "joint_1";
static char mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_2[] = "joint_2";
static char mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_3[] = "joint_3";
static char mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_4[] = "joint_4";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetAngles_Response__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_1, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_2, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_3, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Response__FIELD_NAME__joint_4, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__srv__GetAngles_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME, 46, 46},
      {mypalletizer_interfaces__srv__GetAngles_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetAngles_Event__FIELD_NAME__info[] = "info";
static char mypalletizer_interfaces__srv__GetAngles_Event__FIELD_NAME__request[] = "request";
static char mypalletizer_interfaces__srv__GetAngles_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetAngles_Event__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetAngles_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mypalletizer_interfaces__srv__GetAngles_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__srv__GetAngles_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetAngles_Event__TYPE_NAME, 43, 43},
      {mypalletizer_interfaces__srv__GetAngles_Event__FIELDS, 3, 3},
    },
    {mypalletizer_interfaces__srv__GetAngles_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mypalletizer_interfaces__srv__GetAngles_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mypalletizer_interfaces__srv__GetAngles_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "float32 joint_1\n"
  "float32 joint_2\n"
  "float32 joint_3\n"
  "float32 joint_4\n"
  "# float32 joint_5\n"
  "# float32 joint_6";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetAngles__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetAngles__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 104, 104},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetAngles_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetAngles_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetAngles_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetAngles_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetAngles_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetAngles_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetAngles__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetAngles__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mypalletizer_interfaces__srv__GetAngles_Event__get_individual_type_description_source(NULL);
    sources[3] = *mypalletizer_interfaces__srv__GetAngles_Request__get_individual_type_description_source(NULL);
    sources[4] = *mypalletizer_interfaces__srv__GetAngles_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetAngles_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetAngles_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetAngles_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetAngles_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetAngles_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetAngles_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mypalletizer_interfaces__srv__GetAngles_Request__get_individual_type_description_source(NULL);
    sources[3] = *mypalletizer_interfaces__srv__GetAngles_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
