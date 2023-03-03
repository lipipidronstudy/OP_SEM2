#include <iostream>
#include "header.hpp"
#include <vector>
#include <list>

int main() {
    ForTest array[10];
    for (int i = 0; i < 10; ++i) {
        array[i].age = i + 18;
        array[i].grade = i * 10;

    }
    ForTest none;
    none.age= 50;
    none.grade = 80;
    int first[] = {1, 2, 3};
    std::list<std::string> second = {"bbb", "bbb", "bbb"};
    std::vector<int> third(5, 0);
    std::cout << none_of(&first[0], &first[4], 5) << ' ' << none_of(&first[0], &first[4], 2) << '\n';
    std::cout << is_sorted(second.begin(), second.end(), std::less<>()) << ' '
              << is_sorted(second.begin(), second.end(), std::equal_to<>()) << '\n';
    std::cout << find_not(third.begin(), third.end(), 1) << '\n' << find_not(third.begin(), third.end(), 0) << '\n';
    std::cout << is_sorted(&array[0], &array[10], parents) << '\n';
    ForTest found = find_not(&array[0], &array[10],none);
    std::cout << found.age << ' ' << found.grade << '\n';
    std::cout << none_of(&array[0],&array[10],none);
    return 0;
}
