//
// Created by Yujia Li on 2020/4/25.
//

#ifndef CPP101_COMPLEX_H
#define CPP101_COMPLEX_H


#include <iostream>

class Complex {
public:
    Complex();

    Complex(double r, double i);

    Complex(const Complex &other);

    virtual ~Complex();

    double GetReal() const { return _real; }

    void SetReal(double r) { _real = r; }

    double GetImage() const { return _image; }

    void SetImage(double i) { _image = i; }

    Complex operator+(const Complex &other) const;

    Complex &operator+=(const Complex &other);

    Complex &operator=(const Complex &other);

    bool operator==(const Complex &other) const;

    bool operator!=(const Complex &other) const;

    Complex &operator++();  // 前置
    Complex operator++(int);// 后置
    friend std::istream &operator>>(std::istream &is, Complex &complex);

    friend std::ostream &operator<<(std::ostream &os, const Complex &complex);

private:
    double _real;
    double _image;
};


#endif //CPP101_COMPLEX_H
