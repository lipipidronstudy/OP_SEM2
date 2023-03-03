#include <iostream>
#include "header.hpp"
int main() {
    VectorR3 a(1,2,3);
    VectorR3 b = a;
    VectorR3 n(a);
    n.print();
    VectorR3 c = (a - b);
    c.print();
    VectorR3 d = (a + b);
    d.print();
    std::cout << d.len() << '\n';
    std::cout << d.angle(a) << '\n';
    return 0;
}
