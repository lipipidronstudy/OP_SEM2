#pragma once

#include <ostream>

class Point {
public:
    int data;

    Point(int a) : data(a) {}

    void operator+=(const Point &a) {
        this->data = this->data + a.data;
    }
};

class Square {
public:
    Square(Point x1, float length) : s_x1(x1), s_length(length) {}

public:
    Point s_x1;
    float s_length;
};

class FIFO {
public:
    FIFO() {
        i = 0;
        for (int &j: array) {
            j = 0;
        }
    };
    int array[100];
    int i;
};

bool operator==(Square &a1, Square &a2);

bool operator!=(Square &a1, Square &a2);

bool operator>(Square &a1, Square &a2);

bool operator<(Square &a1, Square &a2);

void operator*(Square &a1, float b);

void operator+(Square &a1, int array[2][1]);

void operator<<(FIFO &a1, int a);

void operator>>(FIFO &a1, int &b);

std::ostream &operator<<(std::ostream &o, const Square &a);