#ifndef CAFEDRA_H
#define CAFEDRA_H

#include <iostream>

class Group {
private:
    char* name;
    int count;
    static inline int total_count = 0;
    int my_id;

public:
    Group();
    Group(const char* n, int c);
    Group(const Group& other);
    ~Group();

    Group& operator=(const Group& other);

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
    friend std::istream& operator>>(std::istream& is, Group& group);
};

#endif
