cmake_minimum_required(VERSION 3.15)

project(cmake_libraries_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(lib_arithmetics)

add_executable(app main.cpp)
target_link_libraries(app arithmetics)
