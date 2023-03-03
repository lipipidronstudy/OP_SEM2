#include <iostream>
#include "header.hpp"

using namespace std;

int main() {
    Point a(1);
    Square a1(a, 1);
    Square a2(a, 1);
    a1 * 1.2;
    cout << (a1 == a2) << ' ' << operator!=(a1, a2) << ' ' << (a1 < a2) << ' ' << operator>(a1, a2) << '\n';
    cout << a1.s_length << '\n';
    int vector[2][1];
    vector[0][0] = 1;
    vector[1][0] = -5;
    a1 + vector;
    operator+(a2, vector);
    cout << a1 << a2;
    FIFO b1;
    b1 << 1;
    operator<<(b1, 2);
    int c;
    b1 >> c;
    cout << c << ' ';
    operator>>(b1, c);
    cout << c;
    return 0;
}
