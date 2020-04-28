//
// Created by Yujia Li on 2020/4/28.
//

#include "main.h"
#include "Singleton.h"

int DesignPattern::main() {
    Singleton::get_instance()->do_something();

    return 0;
}
