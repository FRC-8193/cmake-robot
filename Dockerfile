FROM wpilib/roborio-cross-ubuntu:2025-22.04

RUN apt-get update -y && apt-get install -y build-essential cmake

WORKDIR /workspace

COPY ./FRCMake/ /workspace/FRCMake
COPY ./CMakeLists.txt /workspace/CMakeLists.txt

ARG FRC_TEAM_NUMBER=8193

RUN cmake -B build . -DBUILD_ROBOT_PROGRAM=OFF -DFRC_TEAM_NUMBER=${FRC_TEAM_NUMBER} && cmake --build build -j 16

WORKDIR /workspace

COPY ./src /workspace/src

RUN cmake -B build . -DBUILD_ROBOT_PROGRAM=ON -DFRC_TEAM_NUMBER=${FRC_TEAM_NUMBER} && cmake --build build --target deploy_cmake_robot
