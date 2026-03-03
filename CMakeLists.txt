#Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

#Название твоего проекта
    project(CafedraApp)

#Указываем стандарт C++(11 или выше, так как мы используем nullptr)
        set(CMAKE_CXX_STANDARD 17) set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Собираем исполняемый файл из всех исходников
#Заголовочный файл(.h) указывать не обязательно, но полезно для IDE
            add_executable(CafedraApp maincafedra.cpp cafedra.cpp cafedra.h)
