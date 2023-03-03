#include <iostream>
#include <vector>
#include "Rectangle.hpp"
#include "Trapezoid.hpp"
#include "header.hpp"

int main() {
    CVector2D c;
    c.x = 1;
    c.y = 3;
    Rectangle b(1, 2, 6, c);
    Trapezoid d(1,3,1,3,c);
    sortSys();
    printAll();
    return 0;
}
