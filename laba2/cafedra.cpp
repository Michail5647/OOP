#include "cafedra.h"
#include <cstring>

Group::Group()
    : name(new char[1]), count(0), my_id(++total_count) {
    name[0] = '\0';
    std::cout << "Создан объект:" << my_id << "\n";
}

Group::Group(const char* n, int c)
    : name(new char[std::strlen(n) + 1]), count(c), my_id(++total_count) {
    for (size_t i = 0; i <= std::strlen(n); ++i) {
        name[i] = n[i];
    }
    std::cout << "Создан объект:" << my_id << " (Группа: " << name << ")" << "\n";
}

Group::Group(const Group& other)
    : name(new char[std::strlen(other.name) + 1]), count(other.count), my_id(++total_count) {
    for (size_t i = 0; i <= std::strlen(other.name); ++i) {
        name[i] = other.name[i];
    }
    std::cout << "Создан объект:" << my_id << " (КОПИЯ объекта :" << other.my_id << ")" << "\n";
}

Group::~Group() {
    delete[] name;
    --total_count;
    std::cout << "Удален объект :" << my_id << " (Осталось в памяти: " << total_count << ")" << "\n";
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        char* new_name = new char[std::strlen(other.name) + 1];
        for (size_t i = 0; i <= std::strlen(other.name); ++i) {
            new_name[i] = other.name[i];
        }
        delete[] name;
        name = new_name;
        count = other.count;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Группа: " << group.name << ", Студентов: " << group.count;
    return os;
}

std::istream& operator>>(std::istream& is, Group& group) {
    static constexpr int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];

    if (is >> buffer >> group.count) {
        delete[] group.name;
        group.name = new char[std::strlen(buffer) + 1];
        for (size_t i = 0; i <= std::strlen(buffer); ++i) {
            group.name[i] = buffer[i];
        }
    }
    return is;
}
