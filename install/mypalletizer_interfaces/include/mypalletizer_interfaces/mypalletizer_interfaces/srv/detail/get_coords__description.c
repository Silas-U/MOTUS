// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mypalletizer_interfaces:srv/GetCoords.idl
// generated code does not contain a copyright notice

#include "mypalletizer_interfaces/srv/detail/get_coords__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetCoords__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5c, 0xd9, 0x88, 0xd8, 0x20, 0x8d, 0x74, 0xe4,
      0xfc, 0xa7, 0x13, 0xc0, 0x8f, 0x06, 0xdd, 0x0a,
      0x2a, 0xfa, 0x7f, 0xc2, 0x32, 0xe1, 0xef, 0xf7,
      0x17, 0x54, 0x59, 0x2d, 0x36, 0xab, 0x7b, 0x34,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetCoords_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x54, 0xae, 0x33, 0x3c, 0x6b, 0xdd, 0x20, 0xff,
      0xb1, 0xb7, 0xed, 0x34, 0x60, 0x88, 0x42, 0x8b,
      0x6e, 0x61, 0xa4, 0x72, 0x7d, 0x0d, 0x8c, 0x52,
      0x6b, 0x44, 0x94, 0x81, 0xf4, 0x56, 0x3d, 0x0c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetCoords_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x92, 0x51, 0xc8, 0x1e, 0x8d, 0x49, 0x42, 0xb2,
      0x7c, 0x00, 0x00, 0x3b, 0x24, 0xaa, 0x70, 0xe4,
      0x05, 0xe2, 0x39, 0xef, 0x7c, 0x2b, 0x27, 0xee,
      0x70, 0x85, 0x52, 0xd1, 0x14, 0xc1, 0xcd, 0xb1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mypalletizer_interfaces
const rosidl_type_hash_t *
mypalletizer_interfaces__srv__GetCoords_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x55, 0xe4, 0xe9, 0x3f, 0x46, 0x6e, 0xff, 0x54,
      0xb1, 0x77, 0xcc, 0x9f, 0x78, 0x38, 0x7a, 0xf9,
      0x95, 0x2d, 0x75, 0x5a, 0x96, 0x19, 0x73, 0x7b,
      0x37, 0x00, 0x30, 0x81, 0xb5, 0x14, 0xe9, 0x09,
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

static char mypalletizer_interfaces__srv__GetCoords__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetCoords";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mypalletizer_interfaces__srv__GetCoords_Event__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetCoords_Event";
static char mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetCoords_Request";
static char mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME[] = "mypalletizer_interfaces/srv/GetCoords_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetCoords__FIELD_NAME__request_message[] = "request_message";
static char mypalletizer_interfaces__srv__GetCoords__FIELD_NAME__response_message[] = "response_message";
static char mypalletizer_interfaces__srv__GetCoords__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetCoords__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetCoords__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mypalletizer_interfaces__srv__GetCoords_Event__TYPE_NAME, 43, 43},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mypalletizer_interfaces__srv__GetCoords__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Event__TYPE_NAME, 43, 43},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__srv__GetCoords__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetCoords__TYPE_NAME, 37, 37},
      {mypalletizer_interfaces__srv__GetCoords__FIELDS, 3, 3},
    },
    {mypalletizer_interfaces__srv__GetCoords__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mypalletizer_interfaces__srv__GetCoords_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mypalletizer_interfaces__srv__GetCoords_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mypalletizer_interfaces__srv__GetCoords_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetCoords_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetCoords_Request__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetCoords_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
mypalletizer_interfaces__srv__GetCoords_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME, 45, 45},
      {mypalletizer_interfaces__srv__GetCoords_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__x[] = "x";
static char mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__y[] = "y";
static char mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__z[] = "z";
static char mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__rx[] = "rx";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetCoords_Response__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Response__FIELD_NAME__rx, 2, 2},
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
mypalletizer_interfaces__srv__GetCoords_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME, 46, 46},
      {mypalletizer_interfaces__srv__GetCoords_Response__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mypalletizer_interfaces__srv__GetCoords_Event__FIELD_NAME__info[] = "info";
static char mypalletizer_interfaces__srv__GetCoords_Event__FIELD_NAME__request[] = "request";
static char mypalletizer_interfaces__srv__GetCoords_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mypalletizer_interfaces__srv__GetCoords_Event__FIELDS[] = {
  {
    {mypalletizer_interfaces__srv__GetCoords_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME, 45, 45},
    },
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mypalletizer_interfaces__srv__GetCoords_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME, 45, 45},
    {NULL, 0, 0},
  },
  {
    {mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mypalletizer_interfaces__srv__GetCoords_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mypalletizer_interfaces__srv__GetCoords_Event__TYPE_NAME, 43, 43},
      {mypalletizer_interfaces__srv__GetCoords_Event__FIELDS, 3, 3},
    },
    {mypalletizer_interfaces__srv__GetCoords_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mypalletizer_interfaces__srv__GetCoords_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mypalletizer_interfaces__srv__GetCoords_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "float32 x\n"
  "float32 y\n"
  "float32 z\n"
  "float32 rx\n"
  "# float32 ry\n"
  "# float32 rz";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetCoords__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetCoords__TYPE_NAME, 37, 37},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 70, 70},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetCoords_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetCoords_Request__TYPE_NAME, 45, 45},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetCoords_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetCoords_Response__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mypalletizer_interfaces__srv__GetCoords_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mypalletizer_interfaces__srv__GetCoords_Event__TYPE_NAME, 43, 43},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetCoords__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetCoords__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mypalletizer_interfaces__srv__GetCoords_Event__get_individual_type_description_source(NULL);
    sources[3] = *mypalletizer_interfaces__srv__GetCoords_Request__get_individual_type_description_source(NULL);
    sources[4] = *mypalletizer_interfaces__srv__GetCoords_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetCoords_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetCoords_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetCoords_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetCoords_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mypalletizer_interfaces__srv__GetCoords_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mypalletizer_interfaces__srv__GetCoords_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mypalletizer_interfaces__srv__GetCoords_Request__get_individual_type_description_source(NULL);
    sources[3] = *mypalletizer_interfaces__srv__GetCoords_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
