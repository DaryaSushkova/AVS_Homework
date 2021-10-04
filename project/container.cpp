#include "container.h"
#include "stdlib.h"
#include "stdio.h"

container* InitCont() {
    // Объявление и инициализация контейнера.
    container* cont = (container*)malloc(sizeof(container));
    cont->length = 0;
    // Начальная инициализация массива транспорта.
    for (int index = 0; index < cont->max_length; ++index) {
        cont->transports[index] = NULL;
    }
    return cont;
}

void ClearCont(container* cont) {
    // Удаление элементов массива транспорта.
    for (int index = 0; index < cont->length; ++index) {
        delete cont->transports[index];
    }

    cont->length = 0;
    delete cont;
}

int AddTr(container* cont, const transport* tr) {
    if (cont->length >= cont->max_length) {  // Контейнер заполнен, нельзя добавить элемент.
        printf("The container is full!\n");
        return 1;
    }
    else {  // Добавление транспорта.
        // Если требуемый элемент не имеет значения.
        if (cont->transports[cont->length] == NULL) {
            cont->transports[cont->length] = (transport*)malloc(sizeof(transport));
        }
        // Присваиваем тип транспорта.
        cont->transports[cont->length]->type = tr->type;
        cont->transports[cont->length]->speed = tr->speed;
        cont->transports[cont->length]->distance = tr->distance;
        // Заполнение по видам транспорта.
        cont->transports[cont->length]->arp = tr->arp;
        cont->transports[cont->length]->trn = tr->trn;
        cont->transports[cont->length]->shp = tr->shp;
        // Увеличение длины контейнера.
        cont->length++;
        return 0;
    }
}

int In(container* cont, FILE* in_file) {
    int number_of_transports = 0;
    // Считываем количество транспорта с входного потока.
    int count = fscanf(in_file, "%d\n", &number_of_transports);

    if (count != 1) {  // Считано больше данных, чем нужно.
        printf("Incorrect input data :(\n");
        return 1;
    }
    else if (number_of_transports > cont->max_length) {  // Превышение размера контейнера.
        printf("The number of elements exceeded the container size equal to 10000!\n");
        return 1;
    }
    else if (number_of_transports < 0) {  // Ввод отрицательного числа.
        printf("The number of elements must be a non-negative number!\n");
        return 1;
    }
    else {  // Корректное число транспорта.
        for (int index = 0; index < number_of_transports; ++index) {
            transport tr{};
            int condition = In(&tr, in_file);
            if (condition != 0) {  // Некорректное завершение метода In.
                printf("Incorrect input data in line number: %d\n", index + 1);
                return 1;
            }
            else if (cont->length >= cont->max_length) {
                printf("The container is full!");
            }
            else {
                // Добавление транспорта при корректных данных.
                AddTr(cont, &tr);
            }
        }
        return 0;
    }
}

int InRnd(container* cont, int count, FILE* random_file) {
    if (count > cont->max_length) {  // Длина больше максимального размера контейнера.
        printf("The number of elements exceeded the container size equal to 10000!\n");
        return 1;
    }
    else if (count < 0) {  // Длина - отрицательное число.
        printf("The number of elements must be a non-negative number!\n");
        return 1;
    }
    else {  // Запись количества элементов.
        fprintf(random_file, "%d\n", count);
    }
    // Генерация каждого элемента.
    for (int index = 0; index < count; ++index) {
        transport tr;
        InRnd(&tr);
        fprintf(random_file, "%d %lf\n%d\n", tr.speed, tr.distance, tr.type);
        switch (tr.type) {
            case (0):
                fprintf(random_file, "%d %d", tr.arp.range_of_flight, tr.arp.lifting_capacity);
                break;
            case (1):
                fprintf(random_file, "%d", tr.trn.count_of_cars);
                break;
            case (2):
                fprintf(random_file, "%d %d", tr.shp.displacement, tr.shp.type);
                break;
        }
        AddTr(cont, &tr);
    }
    return 0;
}

void Out(const container* cont, FILE* out_file) {
    // Запись количества элементов.
    fprintf(out_file, "%d elements:", cont->length);
    // Вывод каждого элемента.
    for (int index = 0; index < cont->length; ++index) {
        fprintf(out_file, "\nNumber %d: ", index + 1);
        Out(cont->transports[index], out_file);
    }
}

void StraightSelection(container* cont) {
    // Сортировка по убыванию прямым выбором.
    for (int index = 0; index < cont->length - 1; ++index) {
        // Временная переменная для хранения значения подстановки.
        transport* temporary_tr = cont->transports[index];
        for (int index_2 = index + 1; index_2 < cont->length; ++index_2) {
            if (GetTime(cont->transports[index]->speed, cont->transports[index]->distance) <
                GetTime(cont->transports[index_2]->speed, cont->transports[index_2]->distance)) {
                temporary_tr = cont->transports[index];
                cont->transports[index] = cont->transports[index_2];
                cont->transports[index_2] = temporary_tr;
            }
        }
    }
}