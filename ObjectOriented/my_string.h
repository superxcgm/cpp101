//
// Created by Yujia Li on 2020/4/26.
//

#ifndef CPP101_OBJECT_ORIENTED_STRING_H
#define CPP101_OBJECT_ORIENTED_STRING_H


#include <ostream>

class string {
public:
    string(const char *str = nullptr);

    string(const string &other);

    string(string &&other);

    ~string();

    string &operator=(const string &other);

    string &operator=(string &&rhs) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const string &string);

private:
    char *m_data;

    void allocate_memory(int len);
};


#endif //CPP101_OBJECT_ORIENTED_STRING_H
