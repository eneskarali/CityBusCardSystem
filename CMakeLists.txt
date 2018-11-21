cmake_minimum_required(VERSION 3.8)
project(bp3Preoject2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Person.cpp Person.h User.cpp User.h Admin.cpp Admin.h Card.cpp Card.h)
add_executable(bp3Preoject2 ${SOURCE_FILES})