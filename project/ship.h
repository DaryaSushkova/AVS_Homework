#ifndef PROJECT_SHIP_H
#define PROJECT_SHIP_H

#include "stdlib.h"
#include "stdio.h"
#include "random.h"

// Описание базовой структуры корабля.
struct ship {
    int displacement; // Водоизмещение.
    // Вид судна - перечислимый тип.
    enum ship_type { LINER, TUGBOAT, TANKER } type;
};

// Ввод характеристик корабля из файла.
int In(ship* shp, FILE* in_file);

// Случайный ввод характеристик корабля.
void InRnd(ship* shp);

// Получение типа корабля.
const char* GetType(ship::ship_type index);

#endif //PROJECT_SHIP_H
