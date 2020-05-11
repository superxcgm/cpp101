//
// Created by Yujia Li on 2020/5/11.
//

#ifndef CPP101_STANDARD_VARIADIC_H
#define CPP101_STANDARD_VARIADIC_H

#include <iostream>

using std::cout;
using std::endl;

//void show_list() {}

template<typename T>
void show_list(const T &value) {
    cout << value << endl;
}

template<typename T, typename ...Args>
void show_list(const T &value, const Args &... args) {
    cout << value << ", ";
    show_list(args...);
}

#endif //CPP101_STANDARD_VARIADIC_H
