// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from robokpy_interfaces:action/SetJointTarget.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "robokpy_interfaces/action/set_joint_target.h"


#ifndef ROBOKPY_INTERFACES__ACTION__DETAIL__SET_JOINT_TARGET__FUNCTIONS_H_
#define ROBOKPY_INTERFACES__ACTION__DETAIL__SET_JOINT_TARGET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "robokpy_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "robokpy_interfaces/action/detail/set_joint_target__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget__get_type_hash(
  const rosidl_action_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget__get_type_description(
  const rosidl_action_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget__get_individual_type_description_source(
  const rosidl_action_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget__get_type_description_sources(
  const rosidl_action_type_support_t * type_support);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_Goal
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Goal__init(robokpy_interfaces__action__SetJointTarget_Goal * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Goal__fini(robokpy_interfaces__action__SetJointTarget_Goal * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_Goal *
robokpy_interfaces__action__SetJointTarget_Goal__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Goal__destroy(robokpy_interfaces__action__SetJointTarget_Goal * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Goal__are_equal(const robokpy_interfaces__action__SetJointTarget_Goal * lhs, const robokpy_interfaces__action__SetJointTarget_Goal * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Goal__copy(
  const robokpy_interfaces__action__SetJointTarget_Goal * input,
  robokpy_interfaces__action__SetJointTarget_Goal * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_Goal__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_Goal__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_Goal__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_Goal__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Goal__Sequence__init(robokpy_interfaces__action__SetJointTarget_Goal__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Goal__Sequence__fini(robokpy_interfaces__action__SetJointTarget_Goal__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_Goal__Sequence *
robokpy_interfaces__action__SetJointTarget_Goal__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Goal__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_Goal__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Goal__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_Goal__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_Goal__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Goal__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_Goal__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_Goal__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_Result
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Result__init(robokpy_interfaces__action__SetJointTarget_Result * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Result__fini(robokpy_interfaces__action__SetJointTarget_Result * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_Result *
robokpy_interfaces__action__SetJointTarget_Result__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Result__destroy(robokpy_interfaces__action__SetJointTarget_Result * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Result__are_equal(const robokpy_interfaces__action__SetJointTarget_Result * lhs, const robokpy_interfaces__action__SetJointTarget_Result * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Result__copy(
  const robokpy_interfaces__action__SetJointTarget_Result * input,
  robokpy_interfaces__action__SetJointTarget_Result * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_Result__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_Result__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_Result__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_Result__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Result__Sequence__init(robokpy_interfaces__action__SetJointTarget_Result__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Result__Sequence__fini(robokpy_interfaces__action__SetJointTarget_Result__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_Result__Sequence *
robokpy_interfaces__action__SetJointTarget_Result__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Result__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_Result__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Result__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_Result__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_Result__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Result__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_Result__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_Result__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_Feedback
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Feedback__init(robokpy_interfaces__action__SetJointTarget_Feedback * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Feedback__fini(robokpy_interfaces__action__SetJointTarget_Feedback * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_Feedback *
robokpy_interfaces__action__SetJointTarget_Feedback__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Feedback__destroy(robokpy_interfaces__action__SetJointTarget_Feedback * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Feedback__are_equal(const robokpy_interfaces__action__SetJointTarget_Feedback * lhs, const robokpy_interfaces__action__SetJointTarget_Feedback * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Feedback__copy(
  const robokpy_interfaces__action__SetJointTarget_Feedback * input,
  robokpy_interfaces__action__SetJointTarget_Feedback * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_Feedback__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_Feedback__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_Feedback__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_Feedback__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__init(robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__fini(robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence *
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_Feedback__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_Feedback__Sequence * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_SendGoal__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__init(robokpy_interfaces__action__SetJointTarget_SendGoal_Request * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__fini(robokpy_interfaces__action__SetJointTarget_SendGoal_Request * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_SendGoal_Request *
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__destroy(robokpy_interfaces__action__SetJointTarget_SendGoal_Request * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__are_equal(const robokpy_interfaces__action__SetJointTarget_SendGoal_Request * lhs, const robokpy_interfaces__action__SetJointTarget_SendGoal_Request * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__copy(
  const robokpy_interfaces__action__SetJointTarget_SendGoal_Request * input,
  robokpy_interfaces__action__SetJointTarget_SendGoal_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__init(robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__fini(robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_SendGoal_Request__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__init(robokpy_interfaces__action__SetJointTarget_SendGoal_Response * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__fini(robokpy_interfaces__action__SetJointTarget_SendGoal_Response * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_SendGoal_Response *
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__destroy(robokpy_interfaces__action__SetJointTarget_SendGoal_Response * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__are_equal(const robokpy_interfaces__action__SetJointTarget_SendGoal_Response * lhs, const robokpy_interfaces__action__SetJointTarget_SendGoal_Response * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__copy(
  const robokpy_interfaces__action__SetJointTarget_SendGoal_Response * input,
  robokpy_interfaces__action__SetJointTarget_SendGoal_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__init(robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__fini(robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_SendGoal_Response__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__init(robokpy_interfaces__action__SetJointTarget_SendGoal_Event * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__fini(robokpy_interfaces__action__SetJointTarget_SendGoal_Event * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_SendGoal_Event *
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__destroy(robokpy_interfaces__action__SetJointTarget_SendGoal_Event * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__are_equal(const robokpy_interfaces__action__SetJointTarget_SendGoal_Event * lhs, const robokpy_interfaces__action__SetJointTarget_SendGoal_Event * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__copy(
  const robokpy_interfaces__action__SetJointTarget_SendGoal_Event * input,
  robokpy_interfaces__action__SetJointTarget_SendGoal_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__init(robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__fini(robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence *
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_SendGoal_Event__Sequence * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_GetResult__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_GetResult__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_GetResult__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Request__init(robokpy_interfaces__action__SetJointTarget_GetResult_Request * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Request__fini(robokpy_interfaces__action__SetJointTarget_GetResult_Request * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_GetResult_Request *
robokpy_interfaces__action__SetJointTarget_GetResult_Request__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Request__destroy(robokpy_interfaces__action__SetJointTarget_GetResult_Request * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Request__are_equal(const robokpy_interfaces__action__SetJointTarget_GetResult_Request * lhs, const robokpy_interfaces__action__SetJointTarget_GetResult_Request * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Request__copy(
  const robokpy_interfaces__action__SetJointTarget_GetResult_Request * input,
  robokpy_interfaces__action__SetJointTarget_GetResult_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__init(robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__fini(robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_GetResult_Request__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Response__init(robokpy_interfaces__action__SetJointTarget_GetResult_Response * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Response__fini(robokpy_interfaces__action__SetJointTarget_GetResult_Response * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_GetResult_Response *
robokpy_interfaces__action__SetJointTarget_GetResult_Response__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Response__destroy(robokpy_interfaces__action__SetJointTarget_GetResult_Response * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Response__are_equal(const robokpy_interfaces__action__SetJointTarget_GetResult_Response * lhs, const robokpy_interfaces__action__SetJointTarget_GetResult_Response * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Response__copy(
  const robokpy_interfaces__action__SetJointTarget_GetResult_Response * input,
  robokpy_interfaces__action__SetJointTarget_GetResult_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__init(robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__fini(robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_GetResult_Response__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Event__init(robokpy_interfaces__action__SetJointTarget_GetResult_Event * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Event__fini(robokpy_interfaces__action__SetJointTarget_GetResult_Event * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_GetResult_Event *
robokpy_interfaces__action__SetJointTarget_GetResult_Event__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Event__destroy(robokpy_interfaces__action__SetJointTarget_GetResult_Event * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Event__are_equal(const robokpy_interfaces__action__SetJointTarget_GetResult_Event * lhs, const robokpy_interfaces__action__SetJointTarget_GetResult_Event * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Event__copy(
  const robokpy_interfaces__action__SetJointTarget_GetResult_Event * input,
  robokpy_interfaces__action__SetJointTarget_GetResult_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__init(robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__fini(robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence *
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_GetResult_Event__Sequence * output);

/// Initialize action/SetJointTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage
 * )) before or use
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__init(robokpy_interfaces__action__SetJointTarget_FeedbackMessage * msg);

/// Finalize action/SetJointTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__fini(robokpy_interfaces__action__SetJointTarget_FeedbackMessage * msg);

/// Create action/SetJointTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_FeedbackMessage *
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__create(void);

/// Destroy action/SetJointTarget message.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__destroy(robokpy_interfaces__action__SetJointTarget_FeedbackMessage * msg);

/// Check for action/SetJointTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__are_equal(const robokpy_interfaces__action__SetJointTarget_FeedbackMessage * lhs, const robokpy_interfaces__action__SetJointTarget_FeedbackMessage * rhs);

/// Copy a action/SetJointTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__copy(
  const robokpy_interfaces__action__SetJointTarget_FeedbackMessage * input,
  robokpy_interfaces__action__SetJointTarget_FeedbackMessage * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_type_hash_t *
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource *
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of action/SetJointTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__init(robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__fini(robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * array);

/// Create array of action/SetJointTarget messages.
/**
 * It allocates the memory for the array and calls
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence *
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/SetJointTarget messages.
/**
 * It calls
 * robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
void
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__destroy(robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * array);

/// Check for action/SetJointTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__are_equal(const robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * lhs, const robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/SetJointTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_robokpy_interfaces
bool
robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence__copy(
  const robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * input,
  robokpy_interfaces__action__SetJointTarget_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ROBOKPY_INTERFACES__ACTION__DETAIL__SET_JOINT_TARGET__FUNCTIONS_H_
