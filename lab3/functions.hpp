#pragma once

#include <ostream>

class Point {
public:
    int data;

    Point() = default;

    Point(int a);

    void operator+=(const Point &a);
};

class Square {
public:
    Point s_x1;
    float s_length;
    float angle;
    Square(Point x1, float length);

};

class FIFO {
public:
    int array[100];
    int i;

    FIFO();
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