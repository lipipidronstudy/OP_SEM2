#include <iostream>
#include "header.hpp"

using namespace std;

int main() {
    cout << power(10, 2.1) << '\n';
    Array<12, double> arr{};
    try {
        arr.add(-1, 3);
    } catch(UnavailableIdxException q){
        cout << q.what();
    }
    try {
        arr.add(2, 2);
    }catch(UnavailableIdxException q){
        cout << q.what();
    }
    cout << arr.get(2);
    return 0;
}
