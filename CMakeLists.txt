# Minimum version of CMake required
cmake_minimum_required(VERSION 3.27)

# Set the compilers
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

# Set include paths
set(CPLUS_INCLUDE_PATH "C:/Users/Victor/scoop/apps/mingw-nuwen/current/include")
include_directories(${CPLUS_INCLUDE_PATH})
include_directories("C:/Users/Urizen/scoop/apps/mingw-nuwen/19.0/include/")
include_directories("C:/Users/Urizen/Desktop/morse-translator/includes/")

# Project name
project(morse-translator)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the source files to the project
add_executable(main main.cpp translator/Morse_Class.cpp)
