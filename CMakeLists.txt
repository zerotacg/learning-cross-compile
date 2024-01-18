cmake_minimum_required(VERSION 3.22)
project(cross_compile)

set(CMAKE_CXX_STANDARD 17)

FIND_PACKAGE(OpenSSL REQUIRED)

add_executable(cross_compile src/main.cpp)
target_link_libraries(cross_compile OpenSSL::SSL)