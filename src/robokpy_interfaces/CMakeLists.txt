cmake_minimum_required(VERSION 3.8)
project(robokpy_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(action_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)      # Pose — used by ExecuteMotion.action, ExecuteVisionOp.action
find_package(sensor_msgs REQUIRED)        # JointState — used by ExecuteMotion.action
find_package(builtin_interfaces REQUIRED) # Duration/Time — used by ExecuteMotion.action, CellState.msg

rosidl_generate_interfaces(${PROJECT_NAME}
"srv/ExecutionState.srv"
"srv/SystemMode.srv"
"srv/FK.srv"
"srv/IK.srv"
"srv/Jacobian.srv"
"srv/Reachable.srv"
"srv/ChainFK.srv"
"srv/SetPlanningTipLink.srv"
"srv/GraspAttach.srv"
"srv/ResumeExecution.srv"
"srv/LoadRecipe.srv"
"srv/SpawnObject.srv"
"srv/DespawnObject.srv"
"srv/ResolveObjectPose.srv"
"msg/CellState.msg"
"action/ExecuteMotion.action"
"action/ExecuteToolOp.action"
"action/ExecuteVisionOp.action"
"action/SetJointTarget.action"
  DEPENDENCIES
    action_msgs
    geometry_msgs
    sensor_msgs
    builtin_interfaces
)

install(
  DIRECTORY include/
  DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()