#include "header.hpp"

bool operator==(Square &a1, Square &a2) {
    return a1.s_length == a2.s_length;
}

bool operator!=(Square &a1, Square &a2) {
    return a1.s_length != a2.s_length;
}

bool operator>(Square &a1, Square &a2) {
    return a1.s_length > a2.s_length;
}

bool operator<(Square &a1, Square &a2) {
    return a1.s_length < a2.s_length;
}

void operator*(Square &a1, float b) {
    a1.s_length *= b;
}

void operator+(Square &a1, int array[2][1]) {
    a1.s_x1 += array[0][0];
}

std::ostream &operator<<(std::ostream &o, const Square &a) {
    o << a.s_x1.data << ' ' << a.s_length << '\n';
    return o;
}
void operator<<(FIFO &a1, int a) {
    a1.array[a1.i++] = a;
}

void operator>>(FIFO &a1, int &b) {
    b = a1.array[0];
    for (int i = 1; i < a1.i; ++i) {
        a1.array[i - 1] = a1.array[i];
    }
}

