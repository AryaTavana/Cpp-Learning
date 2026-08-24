cmake_minimum_required(VERSION 3.16)

project(Cpp_Learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB EXERCISE_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/Ex1/*.cpp"
)

add_library(exercise_sources OBJECT EXCLUDE_FROM_ALL ${EXERCISE_SOURCES})
add_executable(current_file tools/current_file_runner.cpp)
