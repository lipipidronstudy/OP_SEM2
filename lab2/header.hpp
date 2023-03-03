#pragma once

#include "math.h"

class VectorR3 {
private:
    float a, b, c;

public:
    VectorR3() : a(0), b(0), c(0) {}

    VectorR3(float a, float b, float c) : a(a), b(b), c(c) {}

    VectorR3(VectorR3 &copy) {
        a = copy.a;
        b = copy.b;
        c = copy.c;
    }

    VectorR3(const VectorR3 &);

    VectorR3 &operator=(const VectorR3 &x);

    VectorR3 operator+(const VectorR3 &second) {
        return VectorR3(a + second.a, b + second.b, c + second.c);
    }

    VectorR3 operator-(const VectorR3 &second) {
        return VectorR3(a - second.a, b - second.b, c - second.c);
    }

    float len() {
        return sqrt(pow(a, 2) + pow(b,2) + pow(c, 2));
    }

    float angle(VectorR3 &second) {
        float numerator = a * second.a + b * second.b + c * second.c;
        float denominator = len() * second.len();
        return (acos(numerator / denominator) - remainder(acos(numerator / denominator),4));
    }


    void print() {
        std::cout << '(' << a << ", " << b << ", " << c << ')' << '\n';
    }
};

