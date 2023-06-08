cmake_minimum_required(VERSION 3.14)
project(
  baobzi_example
  LANGUAGES CXX
  )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set (default_build_type "Release")
if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message (STATUS "No build type specified. Setting build type to Release.")
  set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Valid options: Debug, RelWithDebInfo, Release" FORCE)
endif()

set(BAOBZI_INCLUDES
  ${PROJECT_SOURCE_DIR}/extern/baobzi/include
  ${PROJECT_SOURCE_DIR}/extern/baobzi/extern/msgpack-c/include
  ${PROJECT_SOURCE_DIR}/extern/baobzi/extern/eigen
)

add_executable(baobzi_example src/baobzi_example.cpp)
target_include_directories(baobzi_example PRIVATE ${BAOBZI_INCLUDES})
