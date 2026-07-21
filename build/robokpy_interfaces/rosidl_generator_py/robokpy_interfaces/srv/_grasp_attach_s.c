// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robokpy_interfaces:srv/GraspAttach.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robokpy_interfaces/srv/detail/grasp_attach__struct.h"
#include "robokpy_interfaces/srv/detail/grasp_attach__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robokpy_interfaces__srv__grasp_attach__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robokpy_interfaces.srv._grasp_attach.GraspAttach_Request", full_classname_dest, 56) == 0);
  }
  robokpy_interfaces__srv__GraspAttach_Request * ros_message = _ros_message;
  {  // parent_model
    PyObject * field = PyObject_GetAttrString(_pymsg, "parent_model");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->parent_model, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // parent_link
    PyObject * field = PyObject_GetAttrString(_pymsg, "parent_link");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->parent_link, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // child_model
    PyObject * field = PyObject_GetAttrString(_pymsg, "child_model");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->child_model, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // child_link
    PyObject * field = PyObject_GetAttrString(_pymsg, "child_link");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->child_link, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // attach
    PyObject * field = PyObject_GetAttrString(_pymsg, "attach");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->attach = (Py_True == field);
    Py_DECREF(field);
  }
  {  // joint_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->joint_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robokpy_interfaces__srv__grasp_attach__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GraspAttach_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robokpy_interfaces.srv._grasp_attach");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GraspAttach_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robokpy_interfaces__srv__GraspAttach_Request * ros_message = (robokpy_interfaces__srv__GraspAttach_Request *)raw_ros_message;
  {  // parent_model
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->parent_model.data,
      strlen(ros_message->parent_model.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "parent_model", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // parent_link
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->parent_link.data,
      strlen(ros_message->parent_link.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "parent_link", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // child_model
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->child_model.data,
      strlen(ros_message->child_model.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "child_model", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // child_link
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->child_link.data,
      strlen(ros_message->child_link.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "child_link", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // attach
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->attach ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "attach", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->joint_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "robokpy_interfaces/srv/detail/grasp_attach__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/grasp_attach__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robokpy_interfaces__srv__grasp_attach__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robokpy_interfaces.srv._grasp_attach.GraspAttach_Response", full_classname_dest, 57) == 0);
  }
  robokpy_interfaces__srv__GraspAttach_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // message
    PyObject * field = PyObject_GetAttrString(_pymsg, "message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // joint_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "joint_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->joint_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robokpy_interfaces__srv__grasp_attach__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GraspAttach_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robokpy_interfaces.srv._grasp_attach");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GraspAttach_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robokpy_interfaces__srv__GraspAttach_Response * ros_message = (robokpy_interfaces__srv__GraspAttach_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->message.data,
      strlen(ros_message->message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // joint_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->joint_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "joint_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "robokpy_interfaces/srv/detail/grasp_attach__struct.h"
// already included above
// #include "robokpy_interfaces/srv/detail/grasp_attach__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes


// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool service_msgs__msg__service_event_info__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * service_msgs__msg__service_event_info__convert_to_py(void * raw_ros_message);
bool robokpy_interfaces__srv__grasp_attach__request__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * robokpy_interfaces__srv__grasp_attach__request__convert_to_py(void * raw_ros_message);
bool robokpy_interfaces__srv__grasp_attach__response__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * robokpy_interfaces__srv__grasp_attach__response__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool robokpy_interfaces__srv__grasp_attach__event__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[55];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robokpy_interfaces.srv._grasp_attach.GraspAttach_Event", full_classname_dest, 54) == 0);
  }
  robokpy_interfaces__srv__GraspAttach_Event * ros_message = _ros_message;
  {  // info
    PyObject * field = PyObject_GetAttrString(_pymsg, "info");
    if (!field) {
      return false;
    }
    if (!service_msgs__msg__service_event_info__convert_from_py(field, &ros_message->info)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // request
    PyObject * field = PyObject_GetAttrString(_pymsg, "request");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'request'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!robokpy_interfaces__srv__GraspAttach_Request__Sequence__init(&(ros_message->request), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create robokpy_interfaces__srv__GraspAttach_Request__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    robokpy_interfaces__srv__GraspAttach_Request * dest = ros_message->request.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!robokpy_interfaces__srv__grasp_attach__request__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // response
    PyObject * field = PyObject_GetAttrString(_pymsg, "response");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'response'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!robokpy_interfaces__srv__GraspAttach_Response__Sequence__init(&(ros_message->response), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create robokpy_interfaces__srv__GraspAttach_Response__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    robokpy_interfaces__srv__GraspAttach_Response * dest = ros_message->response.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!robokpy_interfaces__srv__grasp_attach__response__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robokpy_interfaces__srv__grasp_attach__event__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GraspAttach_Event */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robokpy_interfaces.srv._grasp_attach");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GraspAttach_Event");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robokpy_interfaces__srv__GraspAttach_Event * ros_message = (robokpy_interfaces__srv__GraspAttach_Event *)raw_ros_message;
  {  // info
    PyObject * field = NULL;
    field = service_msgs__msg__service_event_info__convert_to_py(&ros_message->info);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "info", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // request
    PyObject * field = NULL;
    size_t size = ros_message->request.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    robokpy_interfaces__srv__GraspAttach_Request * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->request.data[i]);
      PyObject * pyitem = robokpy_interfaces__srv__grasp_attach__request__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "request", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // response
    PyObject * field = NULL;
    size_t size = ros_message->response.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    robokpy_interfaces__srv__GraspAttach_Response * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->response.data[i]);
      PyObject * pyitem = robokpy_interfaces__srv__grasp_attach__response__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "response", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
