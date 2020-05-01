//
// Created by Yujia Li on 2020/4/29.
//

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <functional>
#include <algorithm>
#include <string>
#include "main.h"

struct Display {
    void operator()(int i) {
        std::cout << i << std::endl;
    }
};

void map_demo() {
    std::map<std::string, double> student_scores;
    student_scores["LiMing"] = 95.0;
    student_scores["LiHong"] = 98.5;
    student_scores.insert(std::pair("zhangsan", 100));
    student_scores.insert(std::map<std::string, double>::value_type("wangwu", 60));
    student_scores["zhangsan"] = 60;

    std::for_each(student_scores.begin(), student_scores.end(), [](const std::pair<std::string, double> &info) {
        std::cout << info.first << ": " << info.second << std::endl;
    });

    auto iter = student_scores.find("zhangsan");
    if (iter != student_scores.end()) {
        std::cout << iter->second << std::endl;
    }

    iter = student_scores.begin();
    while (iter != student_scores.end()) {
        if (iter->second < 95.0) {
            // 注意迭代器失效的问题
            student_scores.erase(iter++);
        } else {
            iter++;
        }
    }
    std::for_each(student_scores.begin(), student_scores.end(), [](const std::pair<std::string, double> &info) {
        std::cout << info.first << ": " << info.second << std::endl;
    });
}

void sequence_container_demo() {
    int arr[] = {1, 2, 3, 4, 5};

    std::vector<int> vec(arr, arr + 4);
    std::list<int> lst(arr, arr + 4);
    std::deque<int> dq(arr, arr + 4);

    Display display;

    std::for_each(vec.begin(), vec.end(), [](int i) { std::cout << i << std::endl; });
//    std::for_each(vec.begin(), vec.end(), display);
    std::for_each(lst.begin(), lst.end(), display);
    std::for_each(dq.begin(), dq.end(), display);

    std::queue<int> que(dq);
    std::stack<int> stc(dq);
    std::priority_queue<int> pri_que(arr, arr + 4);

    while (!que.empty()) {
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout << std::endl;

    while (!stc.empty()) {
        std::cout << stc.top() << " ";
        stc.pop();
    }
    std::cout << std::endl;

    while (!pri_que.empty()) {
        std::cout << pri_que.top() << " ";
        pri_que.pop();
    }
    std::cout << std::endl;
}

bool cmp(int a, int b) {
    return a > b;
}

template<class T>
bool cmp_T(const T &a, const T &b) {
    return a > b;
}

struct cmp_f {
    bool operator()(int a, int b) {
        return a > b;
    }
};

template<class T>
struct cmp_f_T {
    bool operator()(const T &a, const T &b) {
        return a > b;
    }
};

void function_demo() {
    int arr[] = {4, 3, 1, 2, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    bool (*p)(int, int);
    p = cmp;

//    std::sort(arr, arr + len, cmp);
//    std::sort(arr, arr + len, cmp_T<int>);
//    std::sort(arr, arr + len, cmp_f());
    std::sort(arr, arr + len, cmp_f_T<int>());
    std::for_each(arr, arr + 5, Display());

}

void algorithm_demo() {
    int ones[] = {1, 2, 3, 4, 5};
    int twos[] = {10, 20, 30, 40, 50};
    int ret[5] = {0};
//    std::transform(ones, ones + 5, twos, ret, [](int a, int b) { return a + b;});
    std::transform(ones, ones + 5, twos, ret, std::plus<>());
    std::for_each(ret, ret + 5, Display());

    int arr[] = {0, 1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 7, 8};
    int len = sizeof(arr) / sizeof(arr[0]);
//    std::cout << std::count(arr, arr + len, 7) << std::endl;
    std::cout << std::count_if(arr, arr + len, std::bind(std::less<>(), std::placeholders::_1,7)) << std::endl;
    std::cout << std::binary_search(arr, arr + len, 4) << std::endl;
    std::vector<int> vec = {3, 4};
    auto iter = std::search(arr, arr + len, vec.begin(), vec.end());
    std::cout << iter - arr << std::endl;
}

int STL::main() {

//    sequence_container_demo();

//    map_demo();

//    function_demo();

    algorithm_demo();
    return 0;
}
