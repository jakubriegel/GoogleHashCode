cmake_minimum_required(VERSION 3.8)
project(GoogleHashCode)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Logic.cpp Logic.h)
add_executable(GoogleHashCode ${SOURCE_FILES})