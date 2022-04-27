project(samHeaders)
cmake_minimum_required(VERSION 3.16)

set(SOURCES
    src/testCommon.cpp
)

add_executable(samHeaders ${SOURCES})
target_include_directories(samHeaders PUBLIC include)