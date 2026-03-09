#include <iostream>
#include "cafedra.h"

int main() {
    Group** cafedra = nullptr;
    int groupCount = 0;
    Group* tempGroup = nullptr;

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n МЕНЮ КАФЕДРЫ \n";
        std::cout << "1. Создать объект\n";
        std::cout << "2. Вывод временного объекта\n";
        std::cout << "3. Добавить в массив\n";
        std::cout << "4. Вывод массива\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) break;

        switch (choice) {
            case 1: {
                if (tempGroup != nullptr) delete tempGroup;
                tempGroup = new Group();
                std::cout << "Введите название группы и количество студентов: ";
                std::cin >> *tempGroup;
                break;
            }
            case 2: {
                if (tempGroup != nullptr) std::cout << "Объект: " << *tempGroup << "\n";
                break;
            }
            case 3: {
                if (tempGroup != nullptr) {
                    Group** newCafedra = new Group*[groupCount + 1];
                    for (int i = 0; i < groupCount; ++i) {
                        newCafedra[i] = cafedra[i];
                    }
                    newCafedra[groupCount] = new Group(*tempGroup);
                    delete[] cafedra;
                    cafedra = newCafedra;
                    groupCount++;
                }
                break;
            }
            case 4: {
                for (int i = 0; i < groupCount; ++i) {
                    std::cout << i + 1 << ". " << *(cafedra[i]) << "\n";
                }
                break;
            }
            case 5:
                break;
        }
    }

    delete tempGroup;
    for (int i = 0; i < groupCount; ++i) {
        delete cafedra[i];
    }
    delete[] cafedra;

    return 0;
}
