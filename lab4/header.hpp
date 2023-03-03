#pragma once
#include <vector>
#include <algorithm>
class CVector2D {
public:
    double x, y;

};

class IGeoFig {
public:

    virtual double square() = 0;


    virtual double perimeter() = 0;
};

// Интерфейс "Физический объект".
class IPhysObject {
public:
// Масса, кг.
    virtual double mass() const = 0;

// Координаты центра масс, м.
    virtual CVector2D position() = 0;

// Сравнение по массе.
    virtual bool operator==(IPhysObject &ob) const = 0;

// Сравнение по массе.
    virtual bool operator<(IPhysObject &ob) const = 0;
};

// Интерфейс "Отображаемый"
class IPrintable {
public:
// Отобразить на экране
// (выводить в текстовом виде параметры фигуры).
    virtual void draw() = 0;
};

// Интерфейс для классов, которые можно задать через диалог с пользователем.
class IDialogInitiable {
// Задать параметры объекта с помощью диалога с пользователем.
    virtual void initFromDialog() = 0;
};

class BaseCObject {
public:
// Имя класса (типа данных).
    virtual const char *classname() = 0;

// Размер занимаемой памяти.
    virtual unsigned int size() = 0;
};
class IFig: public IGeoFig,public  IPhysObject,public IPrintable,public  IDialogInitiable,public  BaseCObject,public CVector2D{


};
std::vector<IFig*> contain;
void printAll() {
    for (int i = 0; i < contain.size(); ++i)
        contain[i] -> draw();
}

double sumSquare() {
    double answer = 0;
    for (int i = 0; i < contain.size(); ++i)
        answer += contain[i] -> square();
}

double sumPer() {
    double answer = 0;
    for (int i = 0; i < contain.size(); ++i)
        answer += contain[i] -> perimeter();
}

CVector2D centerMas() {
    double numeratorX = 0;
    double denominator = 0;
    double numeratorY = 0;
    for (int i = 0; i < contain.size(); ++i) {
        numeratorX += contain[i] -> mass() * contain[i] -> position().x;
        numeratorY += contain[i] -> mass() * contain[i] -> position().y;
        denominator += contain[i] -> mass();
    }
    CVector2D answer;
    answer.x = numeratorX / denominator;
    answer.y = numeratorY / denominator;
    return answer;
}
unsigned int memorySys(){
    unsigned int answer = 0;
    for (int i = 0; i < contain.size(); ++i)
        answer += contain[i] -> size();
}

void sortSys() {
    sort(contain.begin(), contain.end());
}