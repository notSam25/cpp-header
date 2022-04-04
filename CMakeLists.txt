project(samHeaders)

cmake_minimum_required(VERSION 3.17)

add_library(samHeaders STATIC src/common.cpp src/logging.cpp)

add_subdirectory(vendor/spdlog)
target_link_libraries(samHeaders PUBLIC spdlog)

add_executable(testSamHeaders src/testCommon.cpp)
target_link_libraries(testSamHeaders PUBLIC samHeaders)