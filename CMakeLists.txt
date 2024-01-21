cmake_minimum_required(VERSION 3.24)

cmake_policy(SET CMP0132 OLD)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.25.3.tar.gz"
)

project(cross_compile)

set(CMAKE_CXX_STANDARD 17)

HUNTER_ADD_PACKAGE(OpenSSL)

FIND_PACKAGE(OpenSSL REQUIRED)

add_executable(cross_compile src/main.cpp)
target_link_libraries(cross_compile OpenSSL::SSL)