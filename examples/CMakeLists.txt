cmake_minimum_required(VERSION 3.10)

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic-error)
endif()

add_subdirectory("indexedcontainer")