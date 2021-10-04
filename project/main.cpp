#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "container.h"

// Сообщение - инструкция.
void help_message() {
    printf("REQUESTS:\n\n"
           " -f: specify input and output file\n"
           "format: -f /input_file/ /output_file/\n"
           " -n: random input\n"
           "format: -n /size_of_container/ /file_for_output/\n\n"
           "FORMAT OF INPUT FILE:\n"
           "The first line is the number of elements;\n"
           "The description of each of the elements has the form:\n"
           "The first line is the general variables: /speed/(integer) /distance/(double)\n"
           "The second line is the type of transport: 0 - airplane, 1 - train, 2 - ship;\n"
           "The third line is the characteristics of the element separated by a space:\n"
           "Airplane: /flight_range/(integer) /load_capacity/(integer)\n"
           "Train: /count_of_cars/(integer)\n"
           "Ship: /displacement/(integer) /type/(0 - liner, 1 - tugboat, 2 - tanker)\n");
}

// Сообщение ошибки командной строки.
void error_message1() {
    printf("\nIncorrect command line!\n");
}

// Сообщение ошибка чтения файла.
void error_message2() {
    printf("File opening error!\n");
}

// Сообщение ошибки указанной команды.
void error_message3() {
    printf("The specified command does not exist!\n");
}

// Точка входа.
int main(int argc, char* argv[]) {
    // Таймер для подчсета времени исполнения программы.
    srand(static_cast<unsigned int>(time(0)));
    time_t start, end;
    start = clock();
    help_message();
    if (argc != 4) {
        error_message1();
        return 1;
    }

    printf("Start\n");
    container* cont = InitCont();

    // Определяем флаг командной строки.
    if (!strcmp(argv[1], "-f")) {  // Ввод из пользовательких файлов.
        // Режим открытия файла для чтения.
        FILE* input_file = fopen(argv[2], "r");
        int condition = In(cont, input_file);
        fclose(input_file);
        if (condition == 0) {  // Ошибка не произошла.
            FILE* output_file = fopen(argv[3], "w");
            Out(cont, output_file);
            fprintf(output_file, "\n\nSorted transport:\n");
            StraightSelection(cont);
            Out(cont, output_file);
            fclose(output_file);
        }
        else {  // Ошибка произошла.
            error_message2();
            return 1;
        }
    }
    else if (!strcmp(argv[1], "-n")) {  // Рандомный ввод.
        int size_of_container = atoi(argv[2]);
        // Генерация пустого файла для записи входных данных.
        FILE* input_random = fopen(strcat(argv[3], "random"), "w");
        // Генерация пустого файла для записи выходных данных.
        FILE* output_random = fopen(strcat(argv[3], "out"), "w");
        // Заполнение контейнера случайным образом.
        InRnd(cont, size_of_container, input_random);
        Out(cont, output_random);
        fprintf(output_random, "\nSorted transport:\n");
        StraightSelection(cont);
        Out(cont, output_random);
        fclose(output_random);
    }
    else {  // Указана неверная команда.
        error_message3();
        return 1;
    }
    // Очистка памяти.
    ClearCont(cont);
    cont = NULL;
    printf("End\n");
    end = clock();
    printf("Time of completion = %f\n", difftime(end, start) / CLOCKS_PER_SEC);
    return 0;
}
