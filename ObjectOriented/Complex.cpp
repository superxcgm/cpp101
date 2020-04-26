//
// Created by Yujia Li on 2020/4/25.
//

#include "Complex.h"
#include <iostream>

Complex::Complex(double r, double i) {
    _real = r;
    _image = i;
    std::cout << "Complex::Complex(double r, double i)" << std::endl;
}

Complex::Complex() {
    _real = 0;
    _image = 0;
    std::cout << "Complex::Complex()" << std::endl;
}

Complex::Complex(const Complex &other) {
    _real = other._real;
    _image = other._image;
    std::cout << "Complex::Complex(const Complex &other)" << std::endl;
}

Complex::~Complex() {
    std::cout << "Complex::~Complex()" << std::endl;
}

Complex Complex::operator+(const Complex &other) const {
//    Complex ret;
//    ret._real = _real + other._real;
//    ret._image = _image + other._image;
//    return ret; // 可能会触发拷贝构造
    return Complex(_real + other._real, _image + other._image);
}

Complex &Complex::operator+=(const Complex &other) {
    _real += other._real;
    _image += other._image;
    return *this;
}

Complex &Complex::operator=(const Complex &other) {
    if (&other != this) {
        this->_real = other._real;
        this->_image = other._image;
    }
    return *this;
}

Complex &Complex::operator++() {
    _real++;
    _image++;
    return *this;
}

Complex Complex::operator++(int) {
//    Complex before(*this);
//    _image++;
//    _real++;
//    return before;
    return Complex(_real++, _image++);
}

std::ostream &operator<<(std::ostream &os, const Complex &complex) {
//    os << "_real: " << complex._real << " _image: " << complex._image;
    os << complex._real << "+" << complex._image << "i";
    return os;
}

std::istream &operator>>(std::istream &is, Complex &complex) {
    is >> complex._real >> complex._image;
    return is;
}

bool Complex::operator==(const Complex &other) const {
    if (&other == this) {
        return true;
    }
    return _real == other._real && _image == other._image;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}
