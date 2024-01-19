cmake_minimum_required(VERSION 3.22)

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.25.3.tar.gz"
        SHA1 "0dfbc2cb5c4cf7e83533733bdfd2125ff96680cb"
)

project(cross_compile)

set(CMAKE_CXX_STANDARD 17)

HUNTER_ADD_PACKAGE(CURL)
HUNTER_ADD_PACKAGE(OpenSSL)

FIND_PACKAGE(OpenSSL REQUIRED)
FIND_PACKAGE(CURL CONFIG REQUIRED)

add_executable(cross_compile WIN32 MACOSX_BUNDLE src/main.cpp)
target_link_libraries(cross_compile OpenSSL::SSL CURL::libcurl)