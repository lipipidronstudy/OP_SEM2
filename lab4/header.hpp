#pragma once

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
