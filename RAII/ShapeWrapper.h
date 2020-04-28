//
// Created by Yujia Li on 2020/4/28.
//

#ifndef CPP101_RAII_SHAPE_WRAPPER_H
#define CPP101_RAII_SHAPE_WRAPPER_H

class shape {

};

class shape_wrapper {
public:
    explicit shape_wrapper(shape *ptr = nullptr) : ptr_(ptr) {}

    ~shape_wrapper() { delete ptr_; }

    shape *get() const { return ptr_; }

private:
    shape *ptr_;
};


#endif //CPP101_RAII_SHAPE_WRAPPER_H
