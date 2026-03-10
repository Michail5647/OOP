cmake_minimum_required(VERSION 3.20)
project(CafedraLab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cafedra.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/maincafedra.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/cafedralab3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sort_lib.h
)

add_executable(Example ${SOURCES} ${HEADERS})
target_compile_options(Example PRIVATE -Wall -Wextra -Werror -Wpedantic)

find_program(CLANG_FORMAT_EXE clang-format)
if(CLANG_FORMAT_EXE)
    add_custom_target(clang-format COMMAND ${CLANG_FORMAT_EXE} -i ${SOURCES} ${HEADERS})
endif()
