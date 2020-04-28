//
// Created by Yujia Li on 2020/4/28.
//

#ifndef CPP101_DESIGN_PATTERN_SINGLETON_H
#define CPP101_DESIGN_PATTERN_SINGLETON_H


class Singleton {
public:
    static Singleton *get_instance();
    void do_something();
private:
    Singleton() = default;

    ~Singleton() = default;

    static Singleton *m_ins;
};


#endif //CPP101_DESIGN_PATTERN_SINGLETON_H
