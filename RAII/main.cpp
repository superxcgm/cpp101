//
// Created by Yujia Li on 2020/4/28.
//

#include <iostream>
#include "main.h"
#include "UniquePtr.h"

int RAII::main() {

    {
        unique_ptr<double> p(new double (3.14));
        std::cout << *p << std::endl;
    }
    return 0;
}
