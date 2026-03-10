#include "cafedralab3.h" // ИЗМЕНЕНО: новое имя заголовка
#include <iostream>
#include <cstring>

int Cafedra::counter = 0;

Cafedra::Cafedra() : name(nullptr), count(0) {
    id = ++counter;
}

Cafedra::Cafedra(const char* n, int c) : count(c) {
    id = ++counter;
    if (n) {
        name = new char[std::strlen(n) + 1];
        std::strcpy(name, n);
    } else {
        name = nullptr;
    }
}

Cafedra::Cafedra(const Cafedra& other) : count(other.count), id(other.id) {
    if (other.name) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    } else {
        name = nullptr;
    }
}

Cafedra& Cafedra::operator=(const Cafedra& other) {
    if (this == &other) return *this;
    delete[] name;
    id = other.id;
    count = other.count;
    if (other.name) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    } else {
        name = nullptr;
    }
    return *this;
}

Cafedra::~Cafedra() {
    delete[] name;
}

void Cafedra::show() const {
    std::cout << "[" << id << "] Кафедра: " << (name ? name : "Пусто")
              << ", Студентов: " << count << std::endl;
}
