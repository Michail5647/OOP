cmake_minimum_required(VERSION 3.20)
project(Example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Список всех твоих файлов для проверки
set(SOURCES cafedra.cpp maincafedra.cpp)
set(HEADERS cafedra.h)

add_executable(Example ${SOURCES} ${HEADERS})

target_compile_options(Example PRIVATE -Wall -Wextra -Werror -Wpedantic)

# БЛОК ДЛЯ ГАЛОЧКИ (CLANG-FORMAT)
find_program(CLANG_FORMAT_EXE clang-format)
if(CLANG_FORMAT_EXE)
    add_custom_target(
        clang-format
        COMMAND ${CLANG_FORMAT_EXE}
        -i
        ${SOURCES}
        ${HEADERS}
    )
endif()
