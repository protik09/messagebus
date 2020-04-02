# CMakeList.txt : CMake project. Include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.5)
set (CMAKE_CXX_STANDARD 14)

project("messagebus")

# Add the respective subdirectories to the project
add_subdirectory(v1)
add_subdirectory(v2)
add_subdirectory(v3)
add_subdirectory(v4)