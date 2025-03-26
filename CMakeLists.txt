cmake_minimum_required(VERSION 3.15)

project(cmake-robot)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(FRC_TEAM_NUMBER "8193" CACHE STRING "Team number of your FRC team (used for deploying)")
option(BUILD_ROBOT_PROGRAM "Build the robot program. This will only build dependencies when disabled." OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/FRCMake/cmake/modules)
include(FRCMake)

frcmake_set_toolchain_roborio()
frcmake_get_wpilib()

if (BUILD_ROBOT_PROGRAM)
	add_executable(cmake_robot src/robot.cpp)
	target_link_libraries(cmake_robot wpilibc)

	frcmake_generate_deploy_target(cmake_robot ${FRC_TEAM_NUMBER})
endif()
