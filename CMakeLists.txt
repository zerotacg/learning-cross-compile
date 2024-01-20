cmake_minimum_required(VERSION 3.24)

cmake_policy(SET CMP0144 NEW)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.25.3.tar.gz"
    SHA1 "0dfbc2cb5c4cf7e83533733bdfd2125ff96680cb"
    FILEPATH "${CMAKE_CURRENT_LIST_DIR}/cmake/HunterConfig.cmake"
)

project(cross_compile)

set(CMAKE_CXX_STANDARD 17)

HUNTER_ADD_PACKAGE(OpenAL)
HUNTER_ADD_PACKAGE(OpenSSL)

FIND_PACKAGE(OpenSSL REQUIRED)
FIND_PACKAGE(OpenAL REQUIRED)

add_executable(cross_compile src/main.cpp)
target_link_libraries(cross_compile OpenSSL::SSL OpenAL::OpenAL)