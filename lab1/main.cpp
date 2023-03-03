#include <iostream>
#include <stdlib.h>
#include "header.hpp"

using namespace std;

int main() {
    srand(time(0));
    float var1 = 1.56;
    floatWithoutFirst(var1);
    cout << var1 << endl;
    var1 = 1.01;
    floatWithoutSecond(&var1);
    cout << var1 << endl;

    float var2 = 1.56;
    changeFirst(var2);
    cout << var2 << endl;
    var2 = -1.56;
    changeSecond(&var2);
    cout << var2 << endl;

    circle our{};
    our.center[0][0] = 1;
    our.center[1][0] = 1;
    our.r = 1;
    int vector[2][1];
    vector[0][0] = 5;
    vector[1][0] = 3;
    circleFirst(our, vector);
    cout << our.center[0][0] << ' ' << our.center[1][0] << endl;
    our.center[0][0] = -5;
    our.center[1][0] = 3;
    vector[0][0] = 5;
    vector[1][0] = -3;
    circleSecond(&our, vector);
    cout << our.center[0][0] << ' ' << our.center[1][0] << endl;

    Matrix matrix;
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            matrix.array[i][j] = rand();
        }
    }
    float var4 = -1.2;
    matrixFirst(matrix, var4);
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << matrix.array[i][j] << ' ';
        }
        cout <<'\n';
    }
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            matrix.array[i][j] = rand();
        }
    }
    var4 = 1.2;
    matrixSecond(&matrix, var4);
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << matrix.array[i][j] << ' ';
        }
        cout <<'\n';
    }

    return 0;
}
