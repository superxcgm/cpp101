//
// Created by Yujia Li on 2020/4/28.
//

#include <iostream>
#include "Singleton.h"

Singleton* Singleton::m_ins = nullptr;

Singleton *Singleton::get_instance() {
    if (!m_ins) {
        m_ins = new Singleton();
    }
    return m_ins;
}

void Singleton::do_something() {
    std::cout << "Do Something" << std::endl;
}
