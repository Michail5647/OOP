#ifndef CAFEDRALAB3_H
#define CAFEDRALAB3_H

class Cafedra {
private:
    char* name;
    int count;
    int id;             // Порядковый номер в списке
    int my_id;          // Уникальный номер экземпляра (для отчета)

    static int instance_counter; // Общий счетчик созданных объектов в памяти

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
