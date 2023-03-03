#pragma once
#include "header.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout, std::cin, std::vector;
class Rectangle;

class Rectangle : public IFig {
private:
    double height;
    double width;
    double weight;
    CVector2D center;
    const char *name = "Rectangle";
public:
    Rectangle() = default;

    ~Rectangle() = default;

    Rectangle(double height, double width, double weight, CVector2D center) : height(height), width(width),weight(weight),
                                                                           center(center) {
        contain.push_back(this);
    }

    double square() override {
        return height * width;
    }

    double perimeter() override {
        return 2 * (height + width);
    }

    void draw() override {
        cout << "Name: " << name << '\n';
        cout << "Height: " << height << '\n';
        cout << "Width: " << width << '\n';
        cout << "Center x,y: " << center.x << "," << center.y << '\n';
        cout << "Weight: " << weight << '\n';
    }

    double mass() const override {
        return weight;
    }

    bool operator==(IPhysObject &ob) const override {
        return weight == ob.mass();
    }

    bool operator<(const Rectangle &b) const {
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
        cout << "Add width: ";
        cin >> width;
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

