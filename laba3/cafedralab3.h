#ifndef CAFEDRALAB3_H
#define CAFEDRALAB3_H

class Cafedra {
private:
    char* name;
    int count;
    int id;
    static int counter;

public:
    Cafedra();
    Cafedra(const char* n, int c);
    Cafedra(const Cafedra& other);
    ~Cafedra();

    Cafedra& operator=(const Cafedra& other);

    const char* getName() const { return name; }
    int getCount() const { return count; }
    int getId() const { return id; }

    static void resetCounter() { counter = 0; }
    void show() const;
};

#endif
