#include "cafedralab3.h"
#include <iostream>
#include <cstring>

int Cafedra::instance_counter = 0;

Cafedra::Cafedra() : name(nullptr), count(0), id(0) {
    my_id = ++instance_counter;
    std::cout << "Construct [Default] | my_id: " << my_id << std::endl;
}

Cafedra::Cafedra(const char* n, int c) : count(c), id(0) {
    my_id = ++instance_counter;
    if (n) {
        name = new char[std::strlen(n) + 1];
        std::strcpy(name, n);
    } else { name = nullptr; }
    std::cout << "Construct [Param]   | my_id: " << my_id << " | Name: " << (n?n:"NULL") << std::endl;
}

Cafedra::Cafedra(const Cafedra& other) : count(other.count), id(other.id) {
    my_id = ++instance_counter;
    if (other.name) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    } else { name = nullptr; }
    std::cout << "Construct [Copy]    | my_id: " << my_id << " (from " << other.my_id << ")" << std::endl;
}

Cafedra& Cafedra::operator=(const Cafedra& other) {
    std::cout << "Operator =          | my_id: " << my_id << " ->" << other.my_id << std::endl;
    if (this == &other) return *this;
    delete[] name;
    id = other.id;
    count = other.count;
    if (other.name) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    } else { name = nullptr; }
    return *this;
}

Cafedra::~Cafedra() {
    std::cout << "Destruct            | my_id: " << my_id << " | id: " << id << std::endl;
    delete[] name;
}

void Cafedra::show() const {
    std::cout << "[Порядок:" << id << "][Экземпляр:" << my_id << "] Кафедра: "
              << (name ? name : "Пусто") << ", Студентов: " << count << std::endl;
}
