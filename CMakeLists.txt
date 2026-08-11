# 1. Require a minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# 2. Name your project and specify the language (CXX = C++)
project(packet-parser-cpp CXX)

# 3. Tell CMake to build an executable named "my_app" from your main.cpp
add_executable(my_app src/main.cpp)