cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(PROJECT_NAME cpp-advent-of-code)

project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME} 
day9p2.cpp
)

find_package(OpenSSL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenSSL::SSL OpenSSL::Crypto)
