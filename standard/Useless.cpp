//
// Created by Yujia Li on 2020/5/11.
//

#include "Useless.h"
#include <iostream>

int Useless::ct = 0;

using std::cout;
using std::endl;

Useless::Useless() {
    ++ct;
    n = 0;
    pc = nullptr;
    cout << "default constructor called; number of objects: " << ct << endl;
    show_object();
}

Useless::Useless(int k) : n(k) {
    ++ct;
    cout << "int constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    show_object();
}

Useless::Useless(int k, char ch) : n(k) {
    ++ct;
    cout << "int, char constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = ch;
    }
    show_object();
}

Useless::Useless(const Useless &f) : n(f.n) {
    ++ct;
    cout << "copy constructor called; number of objects: " << ct << endl;
    pc = new char[n];
    for (int i = 0; i < n; ++i) {
        pc[i] = f.pc[i];
    }
    show_object();
}

Useless::Useless(Useless &&f) noexcept: n(f.n) {
    ++ct;
    cout << "move constructor called; number of objects: " << ct << endl;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    show_object();
}

Useless::~Useless() {
    cout << "destructor called; object left: " << --ct << endl;
    cout << "deleted object:\n";
    show_object();
    delete[] pc;
}

Useless Useless::operator+(const Useless &f) const {
    cout << "Entering operator+()\n";
    Useless tmp(n + f.n);
    for (int i = 0; i < n; ++i) {
        tmp.pc[i] = pc[i];
    }
    for (int i = 0; i < f.n; ++i) {
        tmp.pc[n + i] = f.pc[i];
    }
    cout << "tmp object:\n";
    cout << "Leaving operator+()\n";
    return tmp;
}

void Useless::show_object() const {
    cout << "Number of elements: " << n;
    cout << " Data address: " << (void *) pc << endl;
}

void Useless::show_data() const {
    if (n == 0) {
        cout << "(Object empty)";
    } else {
        for (int i = 0; i < n; ++i) {
            cout << pc[i];
        }
    }
    cout << endl;
}

Useless &Useless::operator=(const Useless &f) {
    cout << "copy assignment operator called:\n";
    if (&f == this) {
        return *this;
    }
    delete[] pc;
    pc = new char[f.n];
    n = f.n;
    for (int i = 0; i < n; ++i) {
        pc[i] = f.pc[i];
    }

    return *this;
}

Useless &Useless::operator=(Useless &&f) noexcept {
    cout << "move assignment operator called:\n";
    if (&f == this) {
        return *this;
    }
    delete[] pc;
    pc = f.pc;
    n = f.n;
    f.pc = nullptr;
    f.n = 0;

    return *this;
}

