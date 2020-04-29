//
// Created by Yujia Li on 2020/4/29.
//

#include <cstring>
#include <iostream>
#include "main.h"

template<class T>
T max(T a, T b) {
    return a > b ? a : b;
}

// 特化
template<>
char *max(char *a, char *b) {
    return strcmp(a, b) > 0 ? a : b;
}


// 1 + 2 + 3 + ... + 99 + 100
template<int n>
struct Sum {
    enum Value {
        N = Sum<n - 1>::N + n
    };
};

template<>
struct Sum<1> {
    enum Value {
        N = 1
    };
};

int generic::main() {

    max(1, 2);
    max("gg", "mm");

    char *s1 = "hello";
    char *s2 = "world";

    max(s1, s2);

    std::cout << Sum<100>::N << std::endl;

    return 0;
}
