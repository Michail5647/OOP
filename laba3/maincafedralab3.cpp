#include <iostream>
#include <fstream>
#include "cafedralab3.h" // ИЗМЕНЕНО: новое имя заголовка
#include "sort_lib.h"

const int INITIAL_CAPACITY = 2;

int main() {
    int capacity = INITIAL_CAPACITY;
    int size = 0;
    Cafedra* db = new Cafedra[capacity];

    int choice;
    while (true) {
        std::cout << "\n1. Загрузка 2. Сохранение 3. Добавить 4. Удалить\n"
                  << "5. Сортировка 6. Вывод 7. Выход\nВыбор: ";
        if (!(std::cin >> choice)) break;
        if (choice == 7) break;

        switch (choice) {
            case 1: {
                std::ifstream in("data.txt");
                if (!in) { std::cout << "Файл не найден!\n"; break; }
                in >> size;
                if (size > capacity) {
                    delete[] db;
                    capacity = size + 5;
                    db = new Cafedra[capacity];
                }
                for (int i = 0; i < size; i++) {
                    char n[100]; int c;
                    in >> n >> c;
                    db[i] = Cafedra(n, c);
                }
                std::cout << "Загружено.\n";
                break;
            }
            case 2: {
                std::ofstream out("data.txt");
                out << size << "\n";
                for (int i = 0; i < size; i++)
                    out << db[i].getName() << " " << db[i].getCount() << "\n";
                std::cout << "Сохранено.\n";
                break;
            }
            case 3: {
                if (size == capacity) {
                    capacity *= 2;
                    Cafedra* newDb = new Cafedra[capacity];
                    for (int i = 0; i < size; i++) newDb[i] = db[i];
                    delete[] db;
                    db = newDb;
                    std::cout << "(Массив расширен)\n";
                }
                char n[100]; int c;
                std::cout << "Название и кол-во: ";
                std::cin >> n >> c;
                db[size++] = Cafedra(n, c);
                break;
            }
            case 4: {
                int targetId; std::cout << "ID для удаления: "; std::cin >> targetId;
                int foundIdx = -1;
                for (int i = 0; i < size; i++) {
                    if (db[i].getId() == targetId) { foundIdx = i; break; }
                }
                if (foundIdx != -1) {
                    for (int i = foundIdx; i < size - 1; i++) db[i] = db[i+1];
                    size--;
                    std::cout << "Удалено.\n";
                } else std::cout << "ID не найден.\n";
                break;
            }
            case 5:
                bubbleSort(db, size);
                std::cout << "Отсортировано.\n";
                break;
            case 6:
                for (int i = 0; i < size; i++) db[i].show();
                break;
        }
    }
    delete[] db;
    return 0;
}
