#include "header.hpp"
#include <math.h>

void floatWithoutFirst(float &a) {
    a = floor(a);
}

void floatWithoutSecond(float *a) {
    *a = floor(*a);
}

void changeFirst(float &a) {
    a = -a;
}

void changeSecond(float *a) {
    *a = -*a;
}

void circleFirst(circle &a, int vector[2][1]) {
    a.center[0][0] += vector[0][0];
    a.center[1][0] += vector[1][0];
}

void circleSecond(circle *a, int vector[2][1]) {
    a->center[0][0] += vector[0][0];
    a->center[1][0] += vector[1][0];
}

void matrixFirst(Matrix &matrix, float a) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix.array[i][j] *= a;
        }
    }
}

void matrixSecond(Matrix *matrix, float a) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix->array[i][j] *= a;
        }
    }
}