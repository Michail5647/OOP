cmake_minimum_required(VERSION 3.20)
project(Example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем полные пути к файлам
set(SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/cafedra.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/maincafedra.cpp
)
set(HEADERS 
    ${CMAKE_CURRENT_SOURCE_DIR}/cafedra.h
)

add_executable(Example ${SOURCES} ${HEADERS})

target_compile_options(Example PRIVATE -Wall -Wextra -Werror -Wpedantic)

# Ищем clang-format
find_program(CLANG_FORMAT_EXE clang-format)
if(CLANG_FORMAT_EXE)
    add_custom_target(
        clang-format
        COMMAND ${CLANG_FORMAT_EXE} -i ${SOURCES} ${HEADERS}
        COMMENT "Formatting source files with clang-format"
    )
endif()
