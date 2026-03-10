#ifndef SORT_LIB_H
#define SORT_LIB_H
#include "cafedralab3.h"

// Сортировка пузырьком (своя библиотека)
inline void bubbleSort(Cafedra* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].getCount() > arr[j + 1].getCount()) {
                Cafedra temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // После обмена ПЕРЕСЧИТЫВАЕМ порядковые ID
                arr[j].setId(j + 1);
                arr[j+1].setId(j + 2);
            }
        }
    }
}
#endif
