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

void thread_demo() {
    std::thread t1(T1);
    std::thread t2(T2, "你好");

    t1.join();
    t2.join();
}

void deposit(std::mutex &mutex, int *money) {
    for (int i = 0; i < 1000; i++) {
        mutex.lock();
        (*money)++;
        mutex.unlock();
    }
}

void withdraw(std::mutex &mutex, int *money) {
    for (int i = 0; i < 1000; i++) {
        mutex.lock();
        (*money)--;
        mutex.unlock();
    }
}

void bank_demo() {
    int money = 2000;
    std::mutex mutex;
    std::cout << money << std::endl;

    std::thread t1(deposit, std::ref(mutex), &money);
    std::thread t2(withdraw, std::ref(mutex), &money);

    t1.join();
    t2.join();

    std::cout << money << std::endl;
}

int my_thread::main() {

//    thread_demo();

    bank_demo();
    return 0;
}
