#include "cafedra.h"
#include <cstring>

Group::Group() {
    name = new char[1];
    name[0] = '\0';
    count = 0;

    my_id = ++total_count;
    std::cout << "Создан объект:" << my_id << "\n";
}

Group::Group(const char* n, int c) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    count = c;

    my_id = ++total_count;
    std::cout << "Создан объект:" << my_id << " (Группа: " << name << ")" << "\n";
}

Group::Group(const Group& other) {
    count = other.count;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    my_id = ++total_count;
    std::cout << "Создан объект:" << my_id << " (КОПИЯ объекта :" << other.my_id << ")" << "\n";
}

Group::~Group() {
    delete[] name;
    --total_count;
    std::cout << "Удален объект :" << my_id << " (Осталось в памяти: " << total_count << ")" << "\n";
}

Group& Group::operator=(const Group& other) {
    if (this != &other) {
        delete[] name;

        count = other.count;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Группа: " << group.name << ", Студентов: " << group.count;
    return os;
}

std::istream& operator>>(std::istream& is, Group& group) {
    char buffer[256];
    is >> buffer >> group.count;

    delete[] group.name;

    group.name = new char[strlen(buffer) + 1];
    strcpy(group.name, buffer);

    return is;
}
