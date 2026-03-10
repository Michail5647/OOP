cmake_minimum_required(VERSION 3.20)
project(CafedraProject)

# Устанавливаем стандарт C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Список всех исходных файлов (.cpp)
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cafedra.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/maincafedra.cpp
)

# 2. Список всех заголовочных файлов (.h)
# ОБРАТИ ВНИМАНИЕ: здесь новое имя cafedralab3.h
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/cafedralab3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sort_lib.h
)

# 3. Создание исполняемого файла
add_executable(Example ${SOURCES} ${HEADERS})

# 4. Настройка флагов компиляции (строгая проверка ошибок)
target_compile_options(Example PRIVATE -Wall -Wextra -Werror -Wpedantic)

# 5. Блок для автоматической проверки форматирования (clang-format)
# Это нужно для получения "зеленой галочки" на GitHub
find_program(CLANG_FORMAT_EXE clang-format)
if(CLANG_FORMAT_EXE)
    add_custom_target(
        clang-format
        COMMAND ${CLANG_FORMAT_EXE} -i ${SOURCES} ${HEADERS}
        COMMENT "Форматирование кода с помощью clang-format..."
    )
endif()
