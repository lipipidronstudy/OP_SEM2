#pragma once

#include "header.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout, std::cin, std::vector, std::pair;

class Rectangle : public IGeoFig, IPhysObject, IPrintable, BaseCObject, IDialogInitiable {
private:
    double height;
    double width;
    double weight;
    CVector2D center;
    char *name;
    vector<pair<char *, Rectangle>> contain;
public:
    Rectangle() = default;

    ~Rectangle() = default;

    Rectangle(double height, double width, CVector2D center, char *name) : height(height), width(width),
                                                                           center(center), name(name) {
        pair<char *, Rectangle> tmp(name, *this);
        contain.push_back(tmp);
    }

    double square() override {
        return height * width;
    }

    double perimeter() override {
        return 2 * (height + width);
    }

    void draw() override {
        cout << "Height: " << height << '\n';
        cout << "Width: " << width << '\n';
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
        cout << "\t Add name: ";
        cin >> name;
        cout << "\t Add height: ";
        cin >> height;
        cout << "\t Add width: ";
        cin >> width;
        cout << "\t Add weight: ";
        cin >> weight;
        pair<char *, Rectangle> tmp(name, *this);
        contain.push_back(tmp);
    };

    CVector2D position() override {
        return center;
    }


    static bool comp(const pair<char *, Rectangle> &a, const pair<char *, Rectangle> &b) {
        return a.second < b.second;
    }

    void sortRect() {
        sort(contain.begin(), contain.end(), comp);
    }

    void printAll(){
        for (int i = 0; i < contain.size(); ++i)
            contain[i].second.draw();
    }
    double sumSquare(){
        double answer = 0;
        for (int i = 0; i < contain.size(); ++i)
            answer += contain[i].second.square();
    }
    double sumPer(){
        double answer = 0;
        for (int i = 0; i < contain.size(); ++i)
            answer += contain[i].second.perimeter();
    }

};

