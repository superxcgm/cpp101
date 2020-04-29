//
// Created by Yujia Li on 2020/4/29.
//

#ifndef CPP101_DESIGN_PATTERN_ADAPTER_H
#define CPP101_DESIGN_PATTERN_ADAPTER_H


#include <iostream>

class LegacyRectangle {
public:
    LegacyRectangle(double x1, double y1, double x2, double y2) {
        m_x1 = x1;
        m_y1 = y1;
        m_x2 = x2;
        m_y2 = y2;
    }

    void legacy_draw() {
        std::cout << "LegacyRectangle::legacy_draw()" << m_x1 << " " << m_y1 << ", " << m_x2 << " " << m_y2;
    };

private:
    double m_x1;
    double m_y1;
    double m_x2;
    double m_y2;
};

class Rectangle {
public:
    virtual void draw(std::string str) = 0;
};

// 实现1：多重继承
class RectangleAdapter : public Rectangle, public LegacyRectangle {
public:
    RectangleAdapter(double x, double y, double w, double h) : LegacyRectangle(x, y, x + w, y + h) {
        std::cout << "RectangleAdapter(double x, double y, double w, double h)" << std::endl;
    }

    void draw(std::string str) override {
        std::cout << "RectangleAdapter::draw(std::string str)" << std::endl;
        legacy_draw();
    }
};

// 实现2：组合
class RectangleAdapter1 : public Rectangle {
public:
    RectangleAdapter1(double x, double y, double w, double h) : m_legacy_rectangle(x, y, x + w, y + h) {
        std::cout << "RectangleAdapter1(double x, double y, double w, double h)" << std::endl;
    }

    void draw(std::string str) override {
        std::cout << "RectangleAdapter1::draw(std::string str)" << std::endl;
        m_legacy_rectangle.legacy_draw();
    }

private:
    LegacyRectangle m_legacy_rectangle;
};

#endif //CPP101_DESIGN_PATTERN_ADAPTER_H
