cmake_minimum_required(VERSION 2.8.3)
project(Struthio_mk1)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
#set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libstdc++")
#add_compile_options(-std=c++11)
list(INSERT catkin_LIBRARIES 0 /opt/ros/melodic/lib/libroscpp.so)

add_compile_options( -lorocos-kdl -lkdl_parser)
set(PYTHON_VERSION "2.7" CACHE STRING "Python Version touse")
find_package(PythonLibs EXACT ${PYTHON_VERSION} MODULE REQUIRED)
find_package(catkin REQUIRED COMPONENTS
	roscpp
	visualization_msgs
	#gazebo_msgs
	tf
	genmsg
	geometry_msgs
	kdl_parser
	#orocos_kdl
	message_generation
	roslib
	Eigen3
#find_package(Orocos-KDL REQUIRED)
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
	INCLUDE_DIRS include
	# LIBRARIES Struthio_mk1
    CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs tf tf2 roslib
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
#include_directories( include ${catkin_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS}   ${EIGEN3_INCLUDE_DIR})
include_directories(${catkin_INCLUDE_DIRS})

## Declare a C++ library
#add_library( Struthio_mk1
#	 src/jointControl.cpp
#   src/${PROJECT_NAME}/joint_subscribe.h

#)

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/Struthio_mk1_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############
message("catkin_Libraries: ${catkin_LIBRARIES}")

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_Struthio_mk1.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()
#file( GLOB LIB_SOURCES src/cog_publisher.cpp)
#file( GLOB LIB_HEADERS src/cog_publisher.h )
file( GLOB LIB_HEADERS src/robot_link.h src/cog_publisher.h)
add_library( YourLib src/robot_link.h src/cog_publisher.h src/cog_publisher.cpp src/robot_link.cpp)
target_link_libraries(YourLib INTERFACE ${catkin_LIBRARIES} )
## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
#target_link_libraries(Struthio_mk1 ${catkin_LIBRARIES})
#set(COG_PUBLISHER_SRC src/cog_publisher_node.cpp src/cog_publisher.cpp src/robot_link.cpp)
#add_executable(cog_publisher_node  ${COG_PUBLISHER_SRC})
add_executable(cog_publisher_node src/cog_publisher_node.cpp ${catkin_LIBRARIES})#src/cog_publisher.cpp src/robot_link.cpp  ${catkin_LIBRARIES} )
target_link_libraries(cog_publisher_node YourLib ${catkin_LIBRARIES} ${BOOST_LIBRARIES})# ${GAZEBO_LIBRARIES})
#target_link_libraries(cog_publisher_node orocos-kdl)

#link_directories(usr/lib/x86_64-linux-gnu)
add_executable(jointControl src/jointControl.cpp)
target_link_libraries(jointControl ${catkin_LIBRARIES})

add_executable(model_tf_publisher src/model_tf_publisher.cpp)
target_link_libraries(model_tf_publisher ${catkin_LIBRARIES} )
#add_executable(joint_subscribe src/joint_subscribe.cpp)
#add_executable(joint_control src/joint_control.cpp)
#target_link_libraries(joint_control ${catkin_LIBRARIES})
#target_link_libraries(joint_control YourLib) 
#target_link_libraries(joint_subscribe YourLib)
#target_link_libraries(joint_subscribe ${catkin_LIBRARIES})
#add_executable(joint_subscribe src/joint_subscribe.cpp)
#target_include_directories(joint_subscribe PRIVATE ${PYTHON_INCLUDE_DIRS})
#target_link_libraries(joint_control joint_subscribe)
#target_include_directories(joint_subscribe PRIVATE ${PYTHON_INCLUDE_DIRS})
#target_include_directories(joint_control src/)

