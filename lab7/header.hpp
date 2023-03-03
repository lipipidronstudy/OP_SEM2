#pragma once

class BaseFun {
public:
    virtual void push_back(size_t data) = 0;

    virtual void delete_back() = 0;

    virtual void push_front(size_t data) = 0;

    virtual void delete_front() = 0;

    virtual void resize(size_t newSize) = 0;
};

template<class T>
class Buffer final: BaseFun {
private:
    T *point = nullptr;
    size_t size, capacity, pointer;
public:
    Buffer() : size(0), capacity(0), point(nullptr), pointer(0) {}

    Buffer(size_t size) : size(size), point((T*) malloc(sizeof(T) * (size))), capacity(size),
                          pointer(0) {}

    T &operator[](size_t idx) { return point[idx]; }

    void push_back(size_t data) {
        point[pointer++] = data;
    }

    void push_front(size_t data) {
        memcpy(point + 1, point, pointer);
        point[0] = data;
    }

    void delete_back() {
        --pointer;
    }

    void delete_front() {
        memcpy(point, point + 1, --pointer);
    }

    void resize(size_t newSize) {
        size = newSize;
        capacity = (size_t) size * 1.5;
    }


};