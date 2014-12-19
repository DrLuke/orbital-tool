# CMakeLists for Orbit Tool


cmake_minimum_required(VERSION 2.8.11)
project ("Orbit")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# This allows YouCompleMe to import all the compile commands for the ycm_extra_conf.py file
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(O_VERSION_MAJOR 0)
set(O_VERSION_MINOR 1)
set(O_VERSION_REVISION 1)
set(O_VERSION_PATCH 0)

add_subdirectory(src)
