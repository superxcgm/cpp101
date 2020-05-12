//
// Created by Yujia Li on 2020/5/12.
//

#include "thread.h"
#include <thread>
#include <iostream>

int v = 1;

void critical_section(int change_v) {
    static std::mutex mtx;
    std::lock_guard<std::mutex> lock(mtx); // 自动lock

    v = change_v;

    // 退出时自动unlock
}

void lock_guard_demo() {
    std::thread t1(critical_section, 2), t2(critical_section, 3);

    t1.join();
    t2.join();
    std::cout << v << std::endl;
}

int standard::thread::main() {
    lock_guard_demo();

    //unique_lock 可以提供更细粒度的符合RAII的锁

    return 0;
}
