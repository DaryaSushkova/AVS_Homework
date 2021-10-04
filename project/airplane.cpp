#include "airplane.h"

int In(airplane* arp, FILE* in_file) {
    // Характеристики самолета.
    int range_of_flight = 0, lifting_capacity = 0;

    int count_of_value = fscanf(in_file, "%d %d", &range_of_flight, &lifting_capacity);
    // Проверка валидности входного потока.
    if (count_of_value != 2) {
        return 1;
    }

    // Присваиваем считанные значения.
    arp->range_of_flight = range_of_flight;
    arp->lifting_capacity = lifting_capacity;
    return 0;
}

void InRnd(airplane* arp) {
    // Генерация дальности полета.
    arp->range_of_flight = IntRnd(1, 12000);
    // Генерация грузоподъемности (в тоннах).
    arp->lifting_capacity = IntRnd(1, 150);
}

