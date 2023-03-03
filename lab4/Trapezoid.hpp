#pragma once

#include "header.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using std::cout, std::cin, std::vector;

class Trapezoid : public IFig {
private:
    double height;
    double bottom_base;
    double top_base;
    double weight;
    CVector2D center;
    const char *name = "Trapezoid";
public:
    Trapezoid() = default;

    ~Trapezoid() = default;

    Trapezoid(double height, double bottom_base, double top_base, double weight, CVector2D center) :
            height(height), bottom_base(bottom_base), top_base(top_base), weight(weight), center(center) {
        contain.push_back(this);
    }

    double square() override {
        return height * (bottom_base + top_base) / 2;
    }

    double perimeter() override {
        return top_base + bottom_base + 2 * sqrt(pow(height, 2) + pow(((bottom_base - top_base) / 2), 2));
    }

    void draw() override {
        cout << "Name: " << name << '\n';
        cout << "Height: " << height << '\n';
        cout << "Bottom base: " << bottom_base << '\n';
        cout << "Top base: " << top_base << '\n';
        cout << "Center x,y: " << center.x << "," << center.y << '\n';
        cout << "Weight: " << weight << '\n';
    }

    double mass() const override {
        return weight;
    }

    bool operator==(IPhysObject &ob) const override {
        return weight == ob.mass();
    }

    bool operator<(const Trapezoid &b) const {
        return weight < b.weight;
    }


    bool operator<(IPhysObject &ob) const override {
        return weight < ob.mass();
    }

    const char *classname() override {
        return name;
    }

    unsigned int size() override {
        return sizeof(*this);
    }

    void initFromDialog() override {
        cout << " Add height: ";
        cin >> height;
        cout << "Add bottom base: ";
        cin >> bottom_base;
        cout << "Add top base: ";
        cin >> top_base;
        cout << "Add center x and y: ";
        cin >> center.x >> center.y;
        cout << "Add weight: ";
        cin >> weight;
        contain.push_back(this);
    };

    CVector2D position() override {
        return center;
    }
};

