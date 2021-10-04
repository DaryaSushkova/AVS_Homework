#ifndef PROJECT_RANDOM_H
#define PROJECT_RANDOM_H
#include "stdlib.h"
#include "math.h"

// Генерация целого числа в диапазоне [minimum, maximum).
static int IntRnd(int minimum, int maximum) {
    return rand() % maximum + minimum;
}

// Генерация действительного числа в диапазоне [minimum, maximum).
// с точностью двух знаков после запятой.
static double DoubleRnd(double minimum, double maximum) {
    double f = (double)rand() / RAND_MAX;
    return minimum + f * (maximum - minimum);
}
#endif //PROJECT_RANDOM_H
