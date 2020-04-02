# CMakeList.txt : CMake project. Include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.5)
set (CMAKE_CXX_STANDARD 14)

project("v1")

# Add source to this project's executable.
file(GLOB target_sources
    "*.h"
    "*.cpp"
)

# Add the executable 
add_executable(v1_exec ${target_sources})
