//
// Created by Yujia Li on 2020/4/30.
//

#include "main.h"
#include <random>
#include <iostream>

int my_random::main() {
    std::random_device r;
    std::default_random_engine random_engine(r());
    std::uniform_int_distribution u(0, 3);

    std::cout << u(random_engine) << std::endl;
    return 0;
}
