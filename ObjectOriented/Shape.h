//
// Created by Yujia Li on 2020/4/28.
//

#ifndef CPP101_OBJECT_ORIENTED_SHAPE_H
#define CPP101_OBJECT_ORIENTED_SHAPE_H

#include <iostream>

enum class Color {
    GREEN,
    RED,
    BLUE
};

class Shape {
public:
    virtual double area() const = 0;

    virtual void show() = 0;

    void set_color(Color color) { m_color = color; }

    void display() const {
        std::cout << area() << std::endl;
    }

private:
    Color m_color;
};

class Square : public Shape {
public:
    Square(double len) : m_len{len} {}

    void show() override {
        std::cout << "square" << std::endl;
    }

    double area() const override {
        return m_len * m_len;
    }

private:
    double m_len;
};

class Circle : public Shape {
public:
    Circle(double radius) : m_radius{radius} {}

    void show() override {
        std::cout << "circle" << std::endl;
    }

    double area() const override {
        return 3.14 * m_radius * m_radius;
    }

private:
    double m_radius;
};


#endif //CPP101_OBJECT_ORIENTED_SHAPE_H
