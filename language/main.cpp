//
// Created by Yujia Li on 2020/4/29.
//

#include "main.h"
#include <iostream>

void func(void *i) {
    std::cout << "void func(void *i)" << std::endl;
}

void func(int i) {
    std::cout << "void func(int i)" << std::endl;
}

int Test() {
    return 0;
}

int language::main() {
//    int *pi = NULL;
//    int *pi2 = nullptr;
//    char *pc = NULL;
//    char *pc2 = nullptr;
//
////    func(NULL);
//    func(nullptr);
//    func(pi);
//    func(pi2);
//    func(pc);
//    func(pc2);

    // const_cast
    const int a = 5;
    int *p_a = const_cast<int *>(&a);
    *p_a = 10;

    std::cout << a << std::endl;
    std::cout << *p_a << std::endl;

    typedef void(*FuncPtr)();
    FuncPtr func_p;
//    func_p = Test;
    func_p = reinterpret_cast<FuncPtr >(Test);

    return 0;
}
