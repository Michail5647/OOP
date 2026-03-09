cmake_minimum_required(VERSION 3.20)
project(Example)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Объединяем файлы в одну команду, чтобы избежать проблем с переносами
add_executable(Example cafedra.cpp maincafedra.cpp cafedra.h)

target_compile_options(Example PRIVATE -Wall -Wextra -Werror -Wpedantic)
