cmake_minimum_required(VERSION 3.20)
project(leesvr)

set(CMAKE_CXX_STANDARD 20)

# 设置编译输出目录
link_directories(${PROJECT_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_PDB_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

# 工具类库
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/utils)
include_directories(${PROJECT_SOURCE_DIR}/libs/utils)

# zlog库
#add_subdirectory(${PROJECT_SOURCE_DIR}/libs/zlog)
#include_directories(${PROJECT_SOURCE_DIR}/libs/zlog/src)

# hiredis库
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/hiredis)
include_directories(${PROJECT_SOURCE_DIR}/libs/hiredis)

# libco库
#add_subdirectory(libs/libco)
#include_directories(libs/libco)

# coost库
#set(WITH_BACKTRACE ON)
set(FPIC ON)
add_subdirectory(${PROJECT_SOURCE_DIR}/libs/coost)
include_directories(${PROJECT_SOURCE_DIR}/libs/coost/include)

# 可执行程序main
add_executable(main tests/test_operator_new.cpp)
target_link_libraries(main
#        pthread
#        utils
#        zlog
#        hiredis
#        co
        )


