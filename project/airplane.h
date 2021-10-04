#ifndef PROJECT_AIRPLANE_H
#define PROJECT_AIRPLANE_H
#include "stdlib.h"
#include "stdio.h"
#include "random.h"

// Описание базовой структуры самолета.
struct airplane {
    int range_of_flight; // Дальность полета.
    int lifting_capacity; // Грузоподъемность.
};

// Ввод характеристик самолета из входного потока.
int In(airplane* arp, FILE* input_file);

// Случайное заполнение характеристик самолета.
void InRnd(airplane* arp);
#endif //PROJECT_AIRPLANE_H
