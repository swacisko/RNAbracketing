cmake_minimum_required(VERSION 2.8.7)
project(RNABracketing)

SET(CMAKE_CXX_FLAGS "-std=c++14")

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(RNABracketing ${SOURCES} )
