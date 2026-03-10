#ifndef CAFEDRALAB3_H
#define CAFEDRALAB3_H

class Cafedra {
private:
    char* name;
    int count;
    int id;
    int my_id;
    static int instance_counter; // счетчик созданных объектов

public:
    Cafedra();
    Cafedra(const char* n, int c);
    Cafedra(const Cafedra& other);
    ~Cafedra();

    Cafedra& operator=(const Cafedra& other);

    // Сеттеры и геттеры
    void setId(int new_id) { id = new_id; }
    int getId() const { return id; }
    const char* getName() const { return name; }
    int getCount() const { return count; }

    void show() const;
};

#endif
