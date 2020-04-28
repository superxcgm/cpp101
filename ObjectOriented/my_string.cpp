//
// Created by Yujia Li on 2020/4/26.
//

#include <cstring>
#include <cstdlib>
#include "my_string.h"

string::string(const char *str) {
    if (!str) {
        allocate_memory(1);
    } else {
        int len = strlen(str);
        allocate_memory(len + 1);
        strcpy(m_data, str);
    }
//    copy_str(str);
}

string::string(const string &other) {
    int len = strlen(other.m_data);
    allocate_memory(len + 1);
    strcpy(m_data, other.m_data);
}

string::~string() {
    delete[]m_data;
}

string &string::operator=(const string &other) {
    if (this == &other) {
        return *this;
    }
    delete []m_data;
    int len = strlen(other.m_data);
    allocate_memory(len + 1);
    strcpy(m_data, other.m_data);
    return *this;
}

void string::allocate_memory(int len) {
    m_data = new char[len];
    if (m_data) {
        *m_data = '\0';
    } else {
        exit(-1);
    }
}

std::ostream &operator<<(std::ostream &os, const string &string) {
    os << string.m_data;
    return os;
}

string &string::operator=(string &&rhs) noexcept {
    if (this != &rhs) {
        delete[] m_data;
        m_data = rhs.m_data;
        rhs.m_data = nullptr;
    }
    return *this;
}

string::string(string &&other) {
    if (other.m_data) {
        m_data = other.m_data;
        other.m_data = nullptr;
    }
}

