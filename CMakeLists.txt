project(samHeaders)
cmake_minimum_required(VERSION 3.16)

set(SOURCES
    src/testCommon.cpp
)

add_executable(Debug ${SOURCES})
target_include_directories(Debug PUBLIC include)