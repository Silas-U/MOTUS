// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from robokpy_interfaces:srv/ResolveObjectPose.idl
// generated code does not contain a copyright notice

#include "robokpy_interfaces/srv/detail/resolve_object_pose__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ResolveObjectPose__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x60, 0x8c, 0x0c, 0x90, 0x6e, 0x1f, 0x7e, 0xbc,
      0x96, 0xee, 0x37, 0x31, 0xc1, 0xac, 0xbc, 0xfb,
      0x89, 0x95, 0x13, 0x62, 0x96, 0xeb, 0xb0, 0x53,
      0x3a, 0x47, 0xbf, 0x6e, 0x48, 0x32, 0xfc, 0x6c,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd3, 0xdf, 0x6e, 0xad, 0xb2, 0xb9, 0x08, 0x75,
      0x03, 0x93, 0x37, 0x91, 0x80, 0xbb, 0x2e, 0xb4,
      0x38, 0x49, 0xa8, 0x17, 0xf0, 0x50, 0xd8, 0xb9,
      0x15, 0x5e, 0xe3, 0xd1, 0x88, 0x59, 0xa5, 0xe8,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb7, 0x15, 0xdd, 0x00, 0x56, 0x1d, 0xf9, 0x8a,
      0x75, 0x02, 0x69, 0xcd, 0x7d, 0xe8, 0xad, 0x2a,
      0xbb, 0x9e, 0x05, 0x63, 0xb0, 0x23, 0xda, 0x57,
      0xcd, 0xf0, 0xb5, 0x40, 0x69, 0x79, 0xfe, 0x97,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x20, 0xb4, 0x5c, 0x3c, 0xef, 0x6b, 0xfd, 0x6e,
      0xac, 0x40, 0xa8, 0x58, 0x6a, 0x2b, 0x93, 0xea,
      0x02, 0x50, 0x5f, 0xc3, 0xa2, 0x70, 0x78, 0x83,
      0xda, 0x59, 0x77, 0x2a, 0x73, 0x74, 0x14, 0xc4,
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

static char robokpy_interfaces__srv__ResolveObjectPose__TYPE_NAME[] = "robokpy_interfaces/srv/ResolveObjectPose";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char robokpy_interfaces__srv__ResolveObjectPose_Event__TYPE_NAME[] = "robokpy_interfaces/srv/ResolveObjectPose_Event";
static char robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME[] = "robokpy_interfaces/srv/ResolveObjectPose_Request";
static char robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME[] = "robokpy_interfaces/srv/ResolveObjectPose_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char robokpy_interfaces__srv__ResolveObjectPose__FIELD_NAME__request_message[] = "request_message";
static char robokpy_interfaces__srv__ResolveObjectPose__FIELD_NAME__response_message[] = "response_message";
static char robokpy_interfaces__srv__ResolveObjectPose__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ResolveObjectPose__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ResolveObjectPose__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {robokpy_interfaces__srv__ResolveObjectPose_Event__TYPE_NAME, 46, 46},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__ResolveObjectPose__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Event__TYPE_NAME, 46, 46},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ResolveObjectPose__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ResolveObjectPose__TYPE_NAME, 40, 40},
      {robokpy_interfaces__srv__ResolveObjectPose__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__ResolveObjectPose__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__x[] = "x";
static char robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__y[] = "y";
static char robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__z[] = "z";
static char robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__max_distance[] = "max_distance";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ResolveObjectPose_Request__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__FIELD_NAME__max_distance, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME, 48, 48},
      {robokpy_interfaces__srv__ResolveObjectPose_Request__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__success[] = "success";
static char robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__child_model[] = "child_model";
static char robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__child_link[] = "child_link";
static char robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__distance[] = "distance";
static char robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ResolveObjectPose_Response__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__child_model, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__child_link, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__FIELD_NAME__message, 7, 7},
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
robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME, 49, 49},
      {robokpy_interfaces__srv__ResolveObjectPose_Response__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char robokpy_interfaces__srv__ResolveObjectPose_Event__FIELD_NAME__info[] = "info";
static char robokpy_interfaces__srv__ResolveObjectPose_Event__FIELD_NAME__request[] = "request";
static char robokpy_interfaces__srv__ResolveObjectPose_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field robokpy_interfaces__srv__ResolveObjectPose_Event__FIELDS[] = {
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME, 48, 48},
    },
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME, 49, 49},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription robokpy_interfaces__srv__ResolveObjectPose_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME, 48, 48},
    {NULL, 0, 0},
  },
  {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME, 49, 49},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {robokpy_interfaces__srv__ResolveObjectPose_Event__TYPE_NAME, 46, 46},
      {robokpy_interfaces__srv__ResolveObjectPose_Event__FIELDS, 3, 3},
    },
    {robokpy_interfaces__srv__ResolveObjectPose_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Request\n"
  "# A detected position (e.g. from a VisionStep's locate_part result) to\n"
  "# match against the live poses of currently-spawned catalog instances.\n"
  "# Orientation deliberately omitted \\xe2\\x80\\x94 disambiguating WHICH instance this\n"
  "# is (including stacked-object cases) only needs position; matching\n"
  "# orientation too would reject correct matches whenever the object had\n"
  "# settled/rotated slightly after being placed.\n"
  "float64  x\n"
  "float64  y\n"
  "float64  z\n"
  "float64  max_distance   # meters \\xe2\\x80\\x94 reject the match if the nearest known\n"
  "                         # instance is farther than this. Required, not\n"
  "                         # defaulted, so callers make a deliberate choice\n"
  "                         # given their object spacing (this is exactly\n"
  "                         # the \"stacked objects\" scenario from earlier \\xe2\\x80\\x94\n"
  "                         # too generous a threshold risks matching the\n"
  "                         # wrong instance).\n"
  "\n"
  "---\n"
  "# Response\n"
  "bool     success\n"
  "string   child_model    # empty on failure\n"
  "string   child_link      # empty on failure\n"
  "float64  distance        # actual distance to the matched instance, meters\n"
  "string   message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ResolveObjectPose__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ResolveObjectPose__TYPE_NAME, 40, 40},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 1132, 1132},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ResolveObjectPose_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ResolveObjectPose_Request__TYPE_NAME, 48, 48},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ResolveObjectPose_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ResolveObjectPose_Response__TYPE_NAME, 49, 49},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__srv__ResolveObjectPose_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {robokpy_interfaces__srv__ResolveObjectPose_Event__TYPE_NAME, 46, 46},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ResolveObjectPose__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ResolveObjectPose__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__ResolveObjectPose_Event__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__ResolveObjectPose_Request__get_individual_type_description_source(NULL);
    sources[4] = *robokpy_interfaces__srv__ResolveObjectPose_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ResolveObjectPose_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ResolveObjectPose_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ResolveObjectPose_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ResolveObjectPose_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__srv__ResolveObjectPose_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *robokpy_interfaces__srv__ResolveObjectPose_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *robokpy_interfaces__srv__ResolveObjectPose_Request__get_individual_type_description_source(NULL);
    sources[3] = *robokpy_interfaces__srv__ResolveObjectPose_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
