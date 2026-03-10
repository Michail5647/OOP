#include <iostream>
#include <fstream>
#include "cafedralab3.h"
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
            case 1: { // ЗАГРУЗКА
                std::ifstream in("data.txt");
                if (!in) { std::cout << "Файл не найден!\n"; break; }
                in >> size;
                if (size > capacity) {
                    delete[] db;
                    capacity = size + 2;
                    db = new Cafedra[capacity];
                }
                for (int i = 0; i < size; i++) {
                    char n[100]; int c;
                    in >> n >> c;
                    db[i] = Cafedra(n, c);
                    db[i].setId(i + 1);
                }
                std::cout << "Данные загружены.\n";
                break;
            }
            case 2: { // СОХРАНЕНИЕ
                std::ofstream out("data.txt");
                out << size << "\n";
                for (int i = 0; i < size; i++)
                    out << db[i].getName() << " " << db[i].getCount() << "\n";
                std::cout << "Данные сохранены в data.txt\n";
                break;
            }
            case 3: { // ДОБАВЛЕНИЕ
                if (size == capacity) {
                    capacity *= 2;
                    Cafedra* newDb = new Cafedra[capacity];
                    for (int i = 0; i < size; i++) newDb[i] = db[i];
                    delete[] db;
                    db = newDb;
                    std::cout << "--- Массив расширен до " << capacity << " ---\n";
                }
                char n[100]; int c;
                std::cout << "Название и кол-во студентов: ";
                std::cin >> n >> c;
                db[size] = Cafedra(n, c);
                db[size].setId(size + 1);
                size++;
                break;
            }
            case 4: { // УДАЛЕНИЕ ПО ПОРЯДКОВОМУ ID
                int targetId; std::cout << "Введите ID для удаления: "; std::cin >> targetId;
                int foundIdx = -1;
                for (int i = 0; i < size; i++) {
                    if (db[i].getId() == targetId) { foundIdx = i; break; }
                }
                if (foundIdx != -1) {
                    for (int i = foundIdx; i < size - 1; i++) db[i] = db[i+1];
                    size--;
                    // Пересчитываем ID для всех после удаления
                    for (int i = 0; i < size; i++) db[i].setId(i + 1);
                    std::cout << "Объект удален, ID пересчитаны.\n";
                } else std::cout << "Объект не найден.\n";
                break;
            }
            case 5: // СОРТИРОВКА
                bubbleSort(db, size);
                // На всякий случай еще раз пересчитаем ID после сортировки
                for (int i = 0; i < size; i++) db[i].setId(i + 1);
                std::cout << "Сортировка завершена.\n";
                break;
            case 6: // ВЫВОД
                if (size == 0) std::cout << "Список пуст.\n";
                for (int i = 0; i < size; i++) db[i].show();
                break;
        }
    }
    delete[] db;
    return 0;
}
