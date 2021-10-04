#include "ship.h"

int In(ship* shp, FILE* in_file) {
    // Характеристики корабля.
    int displacement = 0, type = 0;

    int count_of_value = fscanf(in_file, "%d %d", &displacement, &type);
    // Проверка валидности входного потока.
    if (count_of_value != 2) {
        return 1;
    }
    else {
        // Присваиваем считанные значения.
        shp->displacement = displacement;
        switch (type) {
            case 0:
                shp->type = ship::LINER;
                return 0;
            case 1:
                shp->type = ship::TUGBOAT;
                return 0;
            case 2:
                shp->type = ship::TANKER;
                return 0;
            default:
                return 1;
        }
    }
}

void InRnd(ship* shp) {
    // Генерация водоизмещения.
    shp->displacement = IntRnd(1, 20000);
    // Генерация типа корабля.
    int type = IntRnd(0, 3);
    switch (type) {
        case 0:
            shp->type = ship::LINER;
            break;
        case 1:
            shp->type = ship::TUGBOAT;
            break;
        case 2:
            shp->type = ship::TANKER;
            break;
    }
}

const char* GetType(ship::ship_type type) {
    char* ship_type[] = { "LINER", "TUGBOAT", "TANKER" };
    return ship_type[type];
}

