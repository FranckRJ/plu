cmake_minimum_required(VERSION 3.10)

set(EXE_NAME IndexedContainerExample)

add_executable(${EXE_NAME} "src/main.cpp")
target_link_libraries(${EXE_NAME} PUBLIC Plu)

set_target_properties(${EXE_NAME} PROPERTIES FOLDER "Examples")