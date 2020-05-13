//
// Created by Yujia Li on 2020/5/13.
//

#include <thread>
#include <chrono>
#include <future>
#include <iostream>
#include "future.h"

int work() {
    using namespace std;
    this_thread::sleep_for(2s);
    return 42;
}

// C++ 11
int standard::future::main() {
    auto fut = std::async(std::launch::async, work);

    std::cout << "I am waiting now\n";
    std::cout << "Answer: " << fut.get() << "\n";

    return 0;
}
