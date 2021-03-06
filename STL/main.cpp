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
    std::cout << std::count_if(arr, arr + len, std::bind(std::less<>(), std::placeholders::_1, 7)) << std::endl;
    std::cout << std::binary_search(arr, arr + len, 4) << std::endl;
    std::vector<int> vec = {3, 4};
    auto iter = std::search(arr, arr + len, vec.begin(), vec.end());
    std::cout << iter - arr << std::endl;
}

void dfs(const char *chs, int len, int deep, std::map<char, bool> &visit, char *record) {
    if (deep == len) {
        for (int i = 0; i < len; ++i) {
            std::cout << record[i];
        }
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < len; ++i) {
        if (!visit[chs[i]]) {
            visit[chs[i]] = true;
            record[deep] = chs[i];
            dfs(chs, len, deep + 1, visit, record);
            visit[chs[i]] = false;
        }
    }
}

void permutation() {
    char chs[] = "123";
    int len = strlen(chs);
    std::map<char, bool> visit;
    char record[len];
    dfs(chs, len, 0, visit, record);
}

void STL_permutation() {
    char chs[] = "abc";
    int len = strlen(chs);
    do {
        std::cout << chs << std::endl;
    } while (std::next_permutation(chs, chs + len));

}

void priority_queue() {
    std::priority_queue<int> p; // 默认是最大小优先
    p.push(3);
    p.push(1);
    p.push(2);
    while (!p.empty()) {
        std::cout << p.top() << std::endl;
        p.pop();
    }

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);
    while (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

}

class istream_line_reader {
public:
    class iterator {
    public:
        typedef ptrdiff_t difference_type;
        typedef std::string value_type;
        typedef const value_type *pointer;
        typedef const value_type &reference;
        typedef std::input_iterator_tag iterator_category;

        iterator() noexcept: stream_(nullptr) {}

        explicit iterator(std::istream &is) : stream_(&is) {
            ++*this;
        }

        reference operator*() const noexcept {
            return line_;
        }

        pointer operator->() const noexcept {
            return &line_;
        }

        iterator &operator++() {
            getline(*stream_, line_);
            if (!*stream_) {
                stream_ = nullptr;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator tmp(*this);
            ++*this;
            return tmp;
        }

        bool operator==(const iterator &rhs) const noexcept {
            return stream_ == rhs.stream_;
        }

        bool operator!=(const iterator &rhs) const noexcept {
            return !(stream_ == rhs.stream_);
        }

    private:
        std::istream *stream_;
        std::string line_;
    };

    istream_line_reader() noexcept: stream_(nullptr) {}
    explicit istream_line_reader(std::istream &is) noexcept : stream_(&is) {}

    iterator begin() {
        return iterator(*stream_);
    }

    iterator end() {
        return iterator();
    }

private:
    std::istream *stream_;
};

void iterator_demo() {
    std::vector v1{1, 2, 3, 4, 5};
    std::vector<int> v2;
    copy(v1.begin(), v1.end(), back_inserter(v2));

    std::for_each(v2.begin(), v2.end(), Display());

    copy(v2.begin(), v2.end(), std::ostream_iterator<int>(std::cout, " "));

    for (const std::string &line: istream_line_reader(std::cin)) {
        std::cout << line << std::endl;
    }
}

int STL::main() {

//    sequence_container_demo();

//    map_demo();

//    function_demo();

//    algorithm_demo();
//    permutation();
//    STL_permutation();

//    priority_queue();

    iterator_demo();
    return 0;
}
