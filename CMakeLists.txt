cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME Plu)
set(LIB_PLU_NAME Plu)
set(LIB_PLU_IDE_NAME _${LIB_PLU_NAME})

project(${PROJECT_NAME} VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(${LIB_PLU_NAME} INTERFACE)
target_include_directories(${LIB_PLU_NAME} INTERFACE "include")

# A "hack" to have a project in the IDE that contain all the files of the library
add_custom_target(${LIB_PLU_IDE_NAME} SOURCES "include/indexedcontainer.hpp")

set_target_properties(${LIB_PLU_IDE_NAME} PROPERTIES FOLDER "Plu")

add_subdirectory("examples")