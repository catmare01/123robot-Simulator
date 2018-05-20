# 123Robot Simulator - The life of 123robot. Simulated.

cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_NAME "123")

#TODO: Change the project name
project(123)

file(GLOB ENGINE_SOURCES lib/*.cc)
file(GLOB GAME_SOURCES src/*.cc)
include_directories(include)

add_library(iage ${ENGINE_SOURCES})
add_executable(${EXECUTABLE_NAME} ${GAME_SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/vendor/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(Irrlicht REQUIRED)
if(IRRLICHT_FOUND)

  include_directories(${IRRLICHT_INCLUDE_DIRS})
  target_link_libraries(${EXECUTABLE_NAME} ${IRRLICHT_LIBRARIES} iage)

endif()
