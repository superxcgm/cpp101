//
// Created by Yujia Li on 2020/4/28.
//

#ifndef CPP101_DESIGN_PATTERN_OBSERVER_H
#define CPP101_DESIGN_PATTERN_OBSERVER_H


#include <iostream>

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(void *p_arg) = 0;
};

class User1: public Observer {
public:
    void update(void *p_arg) override {
        std::cout << "User1 Got News: " << reinterpret_cast<const char *>(p_arg)  << std::endl;
    }
};

class User2: public Observer {
public:
    void update(void *p_arg) override {
        std::cout << "User2 Got News: " << reinterpret_cast<const char *>(p_arg)  << std::endl;
    }
};

#endif //CPP101_DESIGN_PATTERN_OBSERVER_H
