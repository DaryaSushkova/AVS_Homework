#ifndef PROJECT_CONTAINER_H
#define PROJECT_CONTAINER_H

#include "transport.h"

// Контейнер, хранящий транспорт: самолеты, поезда или корабли.
struct container {
    static const int max_length = 10000; // Максимальное значение длины.
    int length;   // Длина текущего контейнера.
    transport* transports[max_length];  // Массив транспорта.
};

// Конструктор контейнера.
container* InitCont();

// Очистка контейнера от элементов (деструктор).
void ClearCont(container* cont);

// Вспомогательный метод по добавлению очередного транспорта в контейнер.
int AddTr(container* cont, const transport* tr);

// Ввод содержимого контейнера из указанного потока.
int In(container* cont, FILE* in_file);

// Случайный ввод содержимого контейнера.
int InRnd(container* cont, int count, FILE* random_file);

// Вывод содержимого контейнера в указанный поток.
void Out(const container* cont, FILE* out_file);

// Сортировка элементов контейнера с помощью прямого выбора.
void StraightSelection(container* cont);

#endif //PROJECT_CONTAINER_H
