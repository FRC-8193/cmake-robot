cmake_minimum_required(VERSION 3.15)
project(cmake_robot)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Debug)
endif()

set(FRC_TEAM_NUMBER "8193" CACHE STRING "Team number of your FRC team (used for deploying)")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/FRCMake/cmake/modules)
include(FRCMake)

frcmake_set_toolchain_roborio()
frcmake_get_wpilib()

add_executable(cmake_robot src/robot.cpp)
target_link_libraries(cmake_robot wpilibc)

frcmake_generate_deploy_target(cmake_robot ${FRC_TEAM_NUMBER})
