//
// Created by Yujia Li on 2020/5/9.
//

#include "main.h"
#include "variadic.h"
#include "thread.h"
#include "future.h"
#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <valarray>
#include <regex>
#include <map>
#include <any>
#include <variant>
#include <charconv>
#include <functional>
#include <iomanip>
//#include <filesystem>

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

// 类型别名模板
template<typename T>
using arr12 = std::array<T, 12>;

inline double f_rvref(double tf) {
    return 5.0 * (tf = 32.0) / 9.0;
}

void ref(std::string &str) {
    cout << "左值：" << str << endl;
}

void ref(std::string &&str) {
    cout << "右值：" << str << endl;
}

auto get_student(int id) {
    if (id == 0) {
        return std::make_tuple(3.8, 'A', "张三");
    }
    if (id == 1) {
        return std::make_tuple(2.9, 'C', "李四");
    }
    return std::make_tuple(1.7, 'D', "王五");
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
    auto auto_arr = new auto(10);
    // auto无法推导数组类型
    // 见前面sum函数的实现
    // auto只能对变量进行类型推导

    // #3 decltype
    // 主要用于表达式类型推导
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

    std::string lv1 = "string, "; // 左值
    // 如果一个prvalue被绑定到一个引用上，它的生命周期则会延长到跟这个引用变量一样长
    const std::string &lv2 = lv1 + lv1; // 常量左值引用延长了临时变量的生命周期
    std::string &&rv2 = lv1 + lv2; // 右值引用延长了临时变量的生命周期
    std::string &&rv3 = std::move(lv1 + lv2); // prvalue变成了xvalue，生命周期没有延长，这里会产生一个ub

    ref(rv2); // 声明的右值引用变量实际上是个左值

    // 返回函数体内的局部变量时，g++优化有可能让数据直接构造到其受益方上，即不产生临时变量，避免了不必要的拷贝/移动。
    // #2 移动
    // 参考Useless

    // #2 新的类功能
    // #3 默认的方法和禁用的方法
    // default只能用于6个特殊成员函数，但delete可用于任何成员函数。有一种用法是禁止特定的转换。

    // #3 委托构造函数
    class Notes {
        int k;
        double x;
    public:
        Notes(int k, double x) : k(k), x(x) {}

        Notes() : Notes(0, 0.0) {} // 委托
    };

    // #3 继承构造函数
    // 可以在子类中使用`using 基类`语法使子类继承基类的构造函数，当构造子类时，如果构造函数和子类的构造函数都不匹配，则可以匹配继承来的父类的构造函数。

    // #3 管理虚方法：override和final
    // override基本于Java中的@Override注解功能是一样的
    // final禁止子类重新定义指定函数

    // #2 Lambda
    // [](int x) {return x % 3 == 0}
    // [](double x) ->double { int y = x; return x - y;}
    // [&] 按引用捕获所有局部变量，[=]按值拷贝捕获所有变量。[ted, &ed] 按值拷贝捕获ted，按引用捕获ed
    // 值拷贝发生在lambda表达式创建的时候，而不是调用时
    // 可以捕获this指针[this](){...}

    // #2 包装器
    // 使用不同的参数类型调用同一个模板函数可以会产生大量的实例。如果参数中有函数的，可以考虑用std::function以减少不必要的实例化。

    // #2 可变参数模板
    show_list(1, 3.1, "haha", 'a');

    // #2 其他
    // random、chrono、 ratio

    // #3 tuple
    auto student = get_student(0);
    cout << "GPA: " << std::get<0>(student) << ", "
         << "成绩：" << std::get<1>(student) << ", "
         << "姓名：" << std::get<2>(student) << endl;

    double gpa;
    char grade;
    std::string name;
    std::tie(gpa, grade, name) = get_student(1);
    cout << "GPA: " << gpa << ", "
         << "成绩：" << grade << ", "
         << "姓名：" << name << endl;

    // #3 regex
    std::string fnames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    std::regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname: fnames) {
        cout << fname << ": " << std::regex_match(fname, txt_regex) << endl;
    }
    // 还能获取子匹配的结果，这里先不列出

    // #3 并行编程
    // 见standard/thread.cpp
    // standard/future



    // #2 外部模板
    // 只要在每个编译单元（文件）中编译的代码遇到了被完整定义的模板，都会实例化，这就产生了重复实例化而导致的编译时间的增加。
    // C++11引入外部模板来解决这个问题
//    template class std::vector<bool>;          // 强行实例化
//    extern template class std::vector<double>; // 不在该当前编译文件中实例化模板

    // #2 模板默认参数
//    template<typename T = int, typename U = int>
//    auto add(T x, U y) -> decltype(x+y) {
//        return x+y;
//    }

    // 移除的部分
    // register 弃用
}

// C++14, 返回类型推导
template<typename T, typename U>
auto foo1(T x, U y) {
    return x + y;
}

void _14_demo() {
    // 返回类型推导
    auto sum = foo1(2, 2.3);
    cout << sum << endl;

    // decltype(auto)
    int i = 2;
    decltype(auto) haha = i; // 等价于decltype(i) haha = i; 主要用在转发函数模板中

    // lambda表达式捕获
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) {
        return x + y + v1 + (*v2);
    };
    cout << add(3, 4) << endl;

    // 泛型lambda
    // 参数表里的auto等价于template，会在调用时进行实例化
    auto add1 = [](auto x, auto y) {
        return x + y;
    };

    // make_unique()
}


std::tuple<int, double, std::string> return_tuple() {
    return std::make_tuple(1, 2.3, "456");
}

template<typename T>
auto print_type_info(const T &t) {
    // 编译期可以优化，使得实例化后的代码不包含分支语句
    if constexpr (std::is_integral<T>::value) {
        return t + 1;
    } else {
        return t + 0.001;
    }
}

template<typename ... T>
auto sum1(T ... t) {
    return (t + ...);
}

template<auto value>
void fn() {
    cout << value << endl;
}

std::optional<std::string> find_user(std::string username) {
    if (username == "superxc") {
        return "找到了";
    }
    return std::nullopt;
}

void optional_demo() {
    auto user = find_user("superxc");

    if (user) {
        cout << *user << endl;
    }

}

void variant_demo() {
    std::variant<int, float, std::string> int_float_string;
    static_assert(std::variant_size_v<decltype(int_float_string)> == 3);

    struct PrintVisitor {
        void operator()(int i) {
            cout << "int: " << i << endl;
        }

        void operator()(float f) {
            cout << "float: " << f << endl;
        }

        void operator()(const std::string &str) {
            cout << "string: " << str << endl;
        }
    };

    std::visit(PrintVisitor{}, int_float_string);

    cout << "index = " << int_float_string.index() << endl;
    int_float_string = 3.14f;

    if (const auto int_ptr = std::get_if<float>(&int_float_string)) {
        cout << "float1: " << *int_ptr << endl;
    }

    if (std::holds_alternative<float>(int_float_string)) {
        cout << "The variant holds a float." << endl;
    }
}

void any_demo() {
    std::any a(12);

    a = std::string("Hello!");
    a = 3.14;

    cout << std::any_cast<double>(a) << endl;

    try {
        cout << std::any_cast<std::string>(a) << endl;
    } catch (const std::bad_any_cast &e) {
        cout << e.what() << endl;
    }
}

std::string_view start_from_word(std::string_view str, std::string_view word) {
    return str.substr(str.find(word));
}

void string_view_demo() {
    std::string str{"Hello Amazing Programming Environment"};
    auto sub_view = start_from_word(str, "Programming Environment");
    cout << sub_view << endl;
    // string_view 只是一个窗口，它不持有字符串的内存，所以要注意string_view所引用的字符串的生命周期
}

void string_conversions_demo() {
    const std::string int_str{"123456"};
    int int_value = 0;
    const auto res = std::from_chars(int_str.data(), int_str.data() + int_str.size(), int_value);

    cout << int_value << endl;

//    const std::string float_str{"3.14"};
//    double float_value = 0.0;
//    const auto format = std::chars_format::general;
//    std::from_chars(float_str.data(), float_str.data() + float_str.size(), float_value, format);
//macOS的库实现似乎有些问题


//    std::string buf{"xxxxxxxx"};
//    const int v = 1986;
//    const auto res1 = std::to_chars(buf.data(), buf.data() + buf.size(), v);
//    if (res1.ec == std::errc()) {
//        // convert successful
//        cout << buf << ", filled: " << res.ptr - buf.data() << " characters" << endl;
//    }
//同样存在问题
}

void search_demo() {
    // std::search在C++14引入，在C++17增强了，提供了执行策略（并行/串行），指定搜索算法(search object)
//    using std::string;
//    string testString = "Hello Super World";
//    string needle = "Super";
//    const auto it = std::search(std::begin(testString), std::end(testString), std::boyer_moore_searcher(std::begin(needle), end(needle)));
//    MacOS的库对boyer_moore_searcher的支持有问题
//    if (it == std::cend(testString)) {
//        cout << "The string " << needle << " not found" << endl;
//    }
}

//namespace fs = std::filesystem;

//void display_directory_tree(const fs::path &path_to_scan, int level = 0) {
//    for (const auto & entry: fs::directory_iterator(path_to_scan)) {
//        const auto filename = entry.path().filename().string();
//        if (entry.is_directory()) {
//            cout << std::setw(level * 3) << "" << filename << endl;
//            display_directory_tree(entry, level + 1);
//        } else if(entry.is_regular_file()) {
//            cout << std::setw(level * 3) << "" << filename << ", size " << fs::file_size(entry) << " bytes" << endl;
//        } else {
//            cout << std::setw(level * 3) << "" << " [?]" << filename << endl;
//        }
//    }
//}

void filesystem_demo() {
//macOS的库还不支持filesystem
//在gcc8+上支持，实测用Ubuntu 20.04可以编译过
//    const fs::path path_to_show{fs::current_path()};
//    cout << "listing files in the directory: " << fs::absolute(path_to_show).string() << endl;
//    display_directory_tree(path_to_show);
};

void _17_demo() {
    // 移除的部分
    // register 移除，但保留关键字

    // 结构化绑定
    auto[x, y, z] = return_tuple();
    cout << x << ", " << y << ", " << z << endl;

    // if语句中声明变量(init if statement)
    if (auto[a, b, c] = return_tuple(); a == 1) {
        cout << "haha" << endl;
    }
    // switch(init; condition)

    // if constexpr
    cout << print_type_info(5) << endl;
    cout << print_type_info(3.14) << endl;

    // 折叠表达式
    cout << sum1(1, 2, 3.14, 4, 5) << endl;

    // 非类型模板参数推导
    fn<10>();

    // 模型参数推导
    std::map<std::string, int> map_users_age{
            {"Alex", 45},
            {"John", 25}
    };
    std::map map_copy{map_users_age}; // 这里不用写类型

    // 表达式求值顺序
    // f(a, b, c) // a, b, c 三者的顺序还是没有限定，但是每个元素必须完成求值。比如下面的例子，不可在new T之后调用goo()，然后再调用unique_ptr<T>(...)
    // foo(unique_ptr<T>(new T), goo());

    // lambda
    // [*this](){...} 按值拷贝对象 在C++14中，只能写成[self=*this](){...}

    // 嵌套的命名空间
//    namespace aa::bb::cc {
//
//    }

    // Template Argument Deduction for Class Templates (CTAD)
    std::array arr{1, 2, 3};

    optional_demo();

    variant_demo();

    any_demo();

    string_view_demo();

    string_conversions_demo();
}

int standard::main() {
//    _11_demo();
//    _14_demo();
    _17_demo();
//    standard::thread::main();
//    standard::future::main();

    return 0;
}
