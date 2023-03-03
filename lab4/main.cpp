#include <iostream>
#include <vector>
#include "header.hpp"
int main() {
    std::vector<BaseCObject> myVector();
    Rectangle abc(1,1);
    myVector().push_back(abc);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
