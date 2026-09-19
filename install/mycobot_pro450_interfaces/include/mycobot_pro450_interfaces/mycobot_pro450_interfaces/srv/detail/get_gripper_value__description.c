// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from mycobot_pro450_interfaces:srv/GetGripperValue.idl
// generated code does not contain a copyright notice

#include "mycobot_pro450_interfaces/srv/detail/get_gripper_value__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__srv__GetGripperValue__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3e, 0xe8, 0xb3, 0x7a, 0x47, 0xd2, 0x49, 0x69,
      0x15, 0x7d, 0xda, 0xe0, 0xa6, 0x1c, 0xf4, 0x68,
      0x02, 0xe3, 0x65, 0x93, 0x99, 0x46, 0x17, 0x91,
      0xf2, 0x3b, 0xc8, 0x4b, 0xc1, 0x5c, 0x4c, 0xfa,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd7, 0x49, 0x59, 0xe7, 0x8a, 0x0b, 0xc8, 0xb7,
      0x8e, 0xf0, 0x5d, 0xb6, 0x59, 0x25, 0x8e, 0xf8,
      0x85, 0x5d, 0xa4, 0x88, 0x86, 0x2d, 0xe1, 0x28,
      0x78, 0xa9, 0x44, 0x7f, 0x56, 0x78, 0x94, 0xcc,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xac, 0x81, 0x2c, 0xfb, 0x03, 0x24, 0xb5, 0x5a,
      0xb4, 0xfa, 0x7a, 0xd9, 0x18, 0xb5, 0x17, 0xa4,
      0xbd, 0xa9, 0xfe, 0xe7, 0x75, 0x24, 0xe1, 0xa4,
      0x95, 0xed, 0x3e, 0x2e, 0xff, 0xf6, 0xd5, 0xd9,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_mycobot_pro450_interfaces
const rosidl_type_hash_t *
mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x96, 0x26, 0x04, 0xa4, 0xaa, 0x53, 0x15, 0x09,
      0xff, 0xd3, 0x99, 0xea, 0x05, 0xfa, 0x63, 0x27,
      0x53, 0xae, 0x81, 0x93, 0xee, 0x41, 0x95, 0xc0,
      0x24, 0x57, 0x29, 0x42, 0x63, 0x68, 0x11, 0x34,
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

static char mycobot_pro450_interfaces__srv__GetGripperValue__TYPE_NAME[] = "mycobot_pro450_interfaces/srv/GetGripperValue";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char mycobot_pro450_interfaces__srv__GetGripperValue_Event__TYPE_NAME[] = "mycobot_pro450_interfaces/srv/GetGripperValue_Event";
static char mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME[] = "mycobot_pro450_interfaces/srv/GetGripperValue_Request";
static char mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME[] = "mycobot_pro450_interfaces/srv/GetGripperValue_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char mycobot_pro450_interfaces__srv__GetGripperValue__FIELD_NAME__request_message[] = "request_message";
static char mycobot_pro450_interfaces__srv__GetGripperValue__FIELD_NAME__response_message[] = "response_message";
static char mycobot_pro450_interfaces__srv__GetGripperValue__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__srv__GetGripperValue__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {mycobot_pro450_interfaces__srv__GetGripperValue_Event__TYPE_NAME, 51, 51},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mycobot_pro450_interfaces__srv__GetGripperValue__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Event__TYPE_NAME, 51, 51},
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mycobot_pro450_interfaces__srv__GetGripperValue__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__srv__GetGripperValue__TYPE_NAME, 45, 45},
      {mycobot_pro450_interfaces__srv__GetGripperValue__FIELDS, 3, 3},
    },
    {mycobot_pro450_interfaces__srv__GetGripperValue__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mycobot_pro450_interfaces__srv__GetGripperValue_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__srv__GetGripperValue_Request__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
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
mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME, 53, 53},
      {mycobot_pro450_interfaces__srv__GetGripperValue_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mycobot_pro450_interfaces__srv__GetGripperValue_Response__FIELD_NAME__gripper_angle[] = "gripper_angle";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__srv__GetGripperValue_Response__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Response__FIELD_NAME__gripper_angle, 13, 13},
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
mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME, 54, 54},
      {mycobot_pro450_interfaces__srv__GetGripperValue_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELD_NAME__info[] = "info";
static char mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELD_NAME__request[] = "request";
static char mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELDS[] = {
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME, 53, 53},
    },
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME, 54, 54},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription mycobot_pro450_interfaces__srv__GetGripperValue_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME, 53, 53},
    {NULL, 0, 0},
  },
  {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME, 54, 54},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {mycobot_pro450_interfaces__srv__GetGripperValue_Event__TYPE_NAME, 51, 51},
      {mycobot_pro450_interfaces__srv__GetGripperValue_Event__FIELDS, 3, 3},
    },
    {mycobot_pro450_interfaces__srv__GetGripperValue_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "int8 gripper_angle";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__srv__GetGripperValue__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__srv__GetGripperValue__TYPE_NAME, 45, 45},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 22, 22},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Request__TYPE_NAME, 53, 53},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Response__TYPE_NAME, 54, 54},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {mycobot_pro450_interfaces__srv__GetGripperValue_Event__TYPE_NAME, 51, 51},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__srv__GetGripperValue__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_individual_type_description_source(NULL);
    sources[3] = *mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_individual_type_description_source(NULL);
    sources[4] = *mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *mycobot_pro450_interfaces__srv__GetGripperValue_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *mycobot_pro450_interfaces__srv__GetGripperValue_Request__get_individual_type_description_source(NULL);
    sources[3] = *mycobot_pro450_interfaces__srv__GetGripperValue_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
