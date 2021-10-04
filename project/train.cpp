#include "train.h"

int In(train* tr, FILE* in_file) {
    // Характеристика поезда.
    int count_of_cars = 0;

    int count_of_value = fscanf(in_file, "%d\n", &count_of_cars);
    // Проверка валидности входного потока.
    if (count_of_value != 1) {
        return 1;
    }

    // Присваиваем считанное значение.
    tr->count_of_cars = count_of_cars;
    return 0;
}

void InRnd(train* trn) {
    // Генерация количества вагонов.
    trn->count_of_cars = IntRnd(1, 50);
}

