//
// Created by Yujia Li on 2020/4/28.
//

#ifndef CPP101_RAII_SHAPE_AUTOPTR_H
#define CPP101_RAII_SHAPE_AUTOPTR_H

#include <algorithm>

template<typename T>
class unique_ptr {
public:
    explicit unique_ptr(T *ptr = nullptr) : ptr_(ptr) {}

    unique_ptr(unique_ptr &&other) {
        ptr_ = other.release();
    }

    unique_ptr &operator=(unique_ptr rhs) {
        rhs.swap(*this);
        return *this;
    }

    ~unique_ptr() {
        delete ptr_;
    }

    T *get() const { return ptr_; }

    T &operator*() const { return *ptr_; }

    T *operator->() const { return ptr_; }

    operator bool() const { return ptr_; }

    T *release() {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(unique_ptr &rhs) {
        std::swap(ptr_, rhs.ptr_);
    }

private:
    T *ptr_;
};


#endif //CPP101_RAII_SHAPE_AUTOPTR_H
