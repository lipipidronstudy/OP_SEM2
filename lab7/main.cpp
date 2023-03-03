#include <iostream>

#include "header.hpp"

int main() {
    Buffer <int> a(5);
    a.push_back(1);
    std::cout << a[0];

    return 0;
}
