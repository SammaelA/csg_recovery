cmake_minimum_required(VERSION 3.1)

project(ransac_command)

set(CMAKE_BUILD_TYPE Release)

if(UNIX)
  add_definitions("-std=c++11 -Wall")
elseif(MSVC)
  add_definitions("-D_CRT_SECURE_NO_WARNINGS")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif()

set(SRC_DIR "src/")
include_directories(${SRC_DIR})
file(GLOB_RECURSE CPP_HEADERS ${SRC_DIR}*.h)
file(GLOB_RECURSE CPP_FILES ${SRC_DIR}*.cpp)

add_executable(ransac_command ${CPP_FILES} ${CPP_HEADERS})
