//
// Created by Yujia Li on 2020/5/3.
//

#include "main.h"
#include <thread>
#include <iostream>
#include <mutex>

std::mutex lock;

void T1() {
    lock.lock();
    std::cout << "T1: hello" << std::endl;
    lock.unlock();
}

void T2(const char *str) {
    lock.lock();
    std::cout << "T2: " << str << std::endl;
    lock.unlock();
}

int my_thread::main() {
    std::thread t1(T1);
    std::thread t2(T2, "你好");

    t1.join();
    t2.join();
    return 0;
}
