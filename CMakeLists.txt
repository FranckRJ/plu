cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME plu)
set(LIB_PLU_NAME plu)

project(${PROJECT_NAME} VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(${LIB_PLU_NAME} INTERFACE)
target_include_directories(${LIB_PLU_NAME} INTERFACE "include")

# A "hack" to have a project in the IDE that contain all the files of the library
add_custom_target(${LIB_PLU_NAME}_proj SOURCES "include/indexedcontainer.hpp")

add_subdirectory("examples")