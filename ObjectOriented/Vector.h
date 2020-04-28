//
// Created by Yujia Li on 2020/4/27.
//

#ifndef CPP101_OBJECT_ORIENTED_VECTOR_H
#define CPP101_OBJECT_ORIENTED_VECTOR_H


#include <variant>

class Vector {
public:
    Vector(int s) : elem{new double[s]}, sz{s} {}

    double &operator[](int i);

    int size() { return sz; }

private:
    int sz;
    double *elem;
};



#endif //CPP101_OBJECT_ORIENTED_VECTOR_H
