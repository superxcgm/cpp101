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

void thread_swap() {
    std::thread t1([]() {
        ;
    });
    std::thread t2([]() {
        ;
    });

    std::cout << "Thread 1's id is: " << t1.get_id() << std::endl;
    std::cout << "Thread 2's id is: " << t2.get_id() << std::endl;
    std::swap(t1, t2);
    std::cout << "Thread 1's id is: " << t1.get_id() << std::endl;
    std::cout << "Thread 2's id is: " << t2.get_id() << std::endl;
    t1.join();
    t2.join();
}

void thread_move() {
    std::thread t1([](){
        ;
    });
    std::cout << "thread 1's id is: " << t1.get_id() << std::endl;
    std::thread t2 = move(t1);
    std::cout << "thread 1's id is: " << t1.get_id() << std::endl;
    std::cout << "thread 2's id is: " << t2.get_id() << std::endl;
    t2.join();
}

int my_thread::main() {

//    thread_demo();

//    bank_demo();

//    thread_swap();

    thread_move();
    return 0;
}
