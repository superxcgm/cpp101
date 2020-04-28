//
// Created by Yujia Li on 2020/4/27.
//

#include <iostream>
#include "Vector.h"

double &Vector::operator[](int i) {
    if (i < 0 || size() <= i) {
        throw std::out_of_range("Vector::operator[]");
    }
    return elem[i];
}

