# Minimum version of CMake required
cmake_minimum_required(VERSION 3.27)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
set(CPLUS_INCLUDE_PATH "C:/Users/Victor/scoop/apps/mingw-nuwen/current/include")
include_directories(${CPLUS_INCLUDE_PATH})
include_directories("C:/Users/Urizen/scoop/apps/mingw-nuwen/19.0/include/")
include_directories("C:/Users/Urizen/Desktop/morse-translator/includes/")
 link_directories(lib)

# Project name
project(morse-translator)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the source file to the project
add_executable(main main.cpp)
