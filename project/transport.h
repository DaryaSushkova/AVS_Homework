#ifndef PROJECT_TRANSPORT_H
#define PROJECT_TRANSPORT_H

#include "airplane.h"
#include "train.h"
#include "ship.h"

// Структура, обобщающая весь имеющийся пассажирский транспорт.
struct transport {
    int speed; // Скорость - общая переменная.
    double distance; // Расстояние между пунктами отправления и назначения - общая переменная.
    // Тип транспорта.
    enum transport_type { AIRPLANE, TRAIN, SHIP } type;
    union {
        airplane arp;
        train trn;
        ship shp;
    };
};

// Ввод обобщенного пассажирского транспорта из входного потока.
int In(transport* tr, FILE* in_file);

// Случайный ввод обобщенного пассажирского транспорта.
void InRnd(transport* tr);

// Вывод обобщенного пассажирского транспорта в файл.
void Out(const transport* tr, FILE* out_file);

// Вычисление идеального времени прохождения пути.
double GetTime(int speed, double distance);

#endif //PROJECT_TRANSPORT_H
