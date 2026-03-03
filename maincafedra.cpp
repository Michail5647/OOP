#include <iostream>
#include "cafedra.h"

int main() {
    Group** cafedra = nullptr;
    int groupCount = 0;

    Group* tempGroup = nullptr;

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n МЕНЮ КАФЕДРЫ \n";
        std::cout << "1. Создать объект (ввод названия группы и числа студентов)\n";
        std::cout << "2. Вывод текущего (временного) объекта\n";
        std::cout << "3. Добавить объект в динамический массив кафедры\n";
        std::cout << "4. Вывод массива кафедры\n";
        std::cout << "5. Выход из программы\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                if (tempGroup != nullptr) {
                    delete tempGroup;
                }
                tempGroup = new Group();
                std::cout << "Введите название группы (без пробелов) и количество студентов:\n";
                std::cin >> *tempGroup;
                std::cout << "Объект успешно создан!\n";
                break;
            }
            case 2: {
                if (tempGroup != nullptr) {
                    std::cout << "Текущий объект -> " << *tempGroup << "\n";
                } else {
                    std::cout << "Объект еще не создан! Сначала выполните пункт 1.\n";
                }
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

                    std::cout << "Объект успешно добавлен на кафедру!\n";
                } else {
                    std::cout << "Сначала создайте объект (пункт 1)!\n";
                }
                break;
            }
            case 4: {
                if (groupCount == 0) {
                    std::cout << "Кафедра пуста.\n";
                } else {
                    std::cout << "\n Список групп на кафедре \n";
                    for (int i = 0; i < groupCount; ++i) {
                        std::cout << i + 1 << ". " << *(cafedra[i]) << "\n";
                    }
                }
                break;
            }
            case 5: {
                std::cout << "Выход из программы\n";
                break;
            }
            default: {
                std::cout << "Неверный ввод. Попробуйте снова (цифры от 1 до 5).\n";
                break;
            }
        }
    }

    if (tempGroup != nullptr) {
        delete tempGroup;
    }

    if (cafedra != nullptr) {
        for (int i = 0; i < groupCount; ++i) {
            delete cafedra[i];
        }
        delete[] cafedra;
    }

    return 0;
}
