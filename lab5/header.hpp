#include <math.h>
#pragma once



template<typename T>
T power(int degree, T our) {
    return pow(our, degree);
}

class BaseException {
protected:
    std::string text;
public:
    virtual std::string what() = 0;
};

class UnavailableIdxException final : public BaseException {
public:
    UnavailableIdxException() {
        text = "This index unavailable, please try again \n";
    }

    UnavailableIdxException(std::string error) {
        text = std::move(error);
    }

    std::string what() override {
        return text;
    }
};

template<int n, class T>
class Array {
public:
    void add(int i, T val);

    T get(int i);

    T array[n];
};

template<int n, class T>
void Array<n, T>::add(int i, T val) {
    if (i < 0 || i >= n)
        throw UnavailableIdxException();
    this->array[i] = val;
}

template<int n, class T>
T Array<n, T>::get(int i) {
    if (i < 0 || i >= n)
        throw UnavailableIdxException();
    return this->array[i];
}


