#ifndef PROJECT_TRAIN_H
#define PROJECT_TRAIN_H
#include "stdlib.h"
#include "stdio.h"
#include "random.h"

// Описание базовой структуры поезда.
struct train {
    int count_of_cars; // Количество вагонов.
};

// Ввод характеристик поезда из входного потока.
int In(train* trn, FILE* input_file);

// Случайное заполнение характеристик поезда.
void InRnd(train* trn);

#endif //PROJECT_TRAIN_H
