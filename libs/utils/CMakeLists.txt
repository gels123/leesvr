cmake_minimum_required(VERSION 3.20)
project(utils)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        Utils.cpp)

add_library(utils SHARED ${SOURCE_FILES})
