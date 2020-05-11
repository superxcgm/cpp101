//
// Created by Yujia Li on 2020/5/9.
//

#include "main.h"
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <valarray>

using std::cout;
using std::endl;
using std::vector;

double sum(std::initializer_list<double> il) {
    double tot = 0;
    for (auto p = il.begin(); p != il.end(); p++) {
//    for (std::initializer_list<double>::iterator p = il.begin(); p != il.end(); p++) {
        tot += *p;
    }
    return tot;
}

// 返回类型后置，主要用于模版
auto foo(double a, int b) -> double {
    return a + b;
}

template<typename T>
using arr12 = std::array<T, 12>;

inline double f_rvref(double tf) {
    return 5.0 * (tf = 32.0) / 9.0;
}

void _11_demo() {
    // #2 new type
    long long ll = 2147483648;
    cout << ll << endl;

    char16_t c16; // for UTF-16
    char32_t c32; // for UTF-32

    // #2 initializer_list
    int *arr = new int[4]{2, 4, 5, 7};
    cout << arr[2] << endl;

    // #3 narrow
    char c2 = 45985821; // int to char, undefined behavior
    //char c3 = {45985821}; // int to char, out of range, compile-time error
    char c1{66}; // int to char, in range, allowed

    vector<int> a1(10); // uninitialized vector with 10 elements
    vector<int> a2{10}; // initializer-list, a2 has 1 element set to 10
    vector<int> a3{4, 6, 1}; // 3 elements set to 4, 6, 1

    cout << sum({1, 2, 3}) << endl;

    // #2 declaration
    // #3 auto
    // 见前面sum函数的实现

    // #3 decltype
    int j = 3;
    decltype(j) j1; // j1 has same type to j
    j1 = 4;
    cout << j1 << endl;

    // #3 返回类型后置
    cout << foo(2.3, 3) << endl;

    // #3 using
    typedef std::vector<std::string>::iterator itType;
    using itType1 = std::vector<std::string>::iterator;
    // 主要用处还是在于和模版一起使用
    arr12<double> a12;

    // #3 nullptr
    int *p = nullptr;

    // #2 smart pointer
    // unique_ptr, shared_ptr, weak_ptr

    // #2 异常规范方面的修改
//    void f501(int) throw (bad_dog); can throw bad_dog exception
//    void f733(long long) throw() // doesn't throw an exception
    // 上面两种异常的写法在C++11中被摒弃了，但添加了noexcept关键字

    // #2 作用域内枚举
    enum Old {
        yes, no, maybe
    };
    enum class New1 {
        never, sometimes, often, always
    };
    enum class New2 {
        never, lever, server
    };

    New1 n = New1::never;

    // #2 对类的修改
    // #3 之前的explicit 只能用在构造函数，C++11之后可以用在转换函数上
    // #3 类内成员初始化（in-class initialization）
    class Session {
        int mem1 = 10;
        double mem2{19.6};
        // ...
        // 不能使用圆括号初始化
    };

    // #2 模板和STL方面的修改
    // #3 range for
    for (auto x : {2, 3, 4}) {
        cout << x << " ";
    }
    cout << endl;
    // #3 new STL container
    // forward_list, unordered_map, unordered_multimap, unordered_set, unordered_multiset
    // array

    // #3 new STL method
    // cbegin(), cend()

    // #3 valarray升级
    // C++11 中的全局函数begin(), end()支持valarray
    std::valarray<int> vl;
    std::begin(vl);

    // #3 摒弃export，但保留为关键字

    // #3 尖括号
    // before C++11, 在两个尖括号之间需要有一个空格
    std::vector<std::list<int> > vecl;
    // C++11，不再需要
    std::vector<std::list<int>> vecl1;

    // #2 右值引用
    double tc = 21.5;
    double &&rd1 = 7.07;
    double &&rd2 = 1.8 * tc + 32.0;
    double &&rd3 = f_rvref(rd2);
    cout << " tc value and address: " << tc << ", " << &tc << endl;
    cout << "rd1 value and address: " << rd1 << ", " << &rd1 << endl;
    cout << "rd2 value and address: " << rd2 << ", " << &rd2 << endl;
    cout << "rd3 value and address: " << rd3 << ", " << &rd3 << endl;

    // 返回函数体内的局部变量时，g++优化有可能让数据直接构造到其受益方上，即不产生临时变量，避免了不必要的拷贝/移动。

}

int standard::main() {
    _11_demo();
    return 0;
}
