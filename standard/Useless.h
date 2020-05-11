//
// Created by Yujia Li on 2020/5/11.
//

#ifndef CPP101_USELESS_H
#define CPP101_USELESS_H


class Useless {
private:
    int n;
    char *pc;
    static int ct;

    void show_object() const;

public:
    Useless();

    explicit Useless(int k);

    Useless(int k, char ch);

    Useless(const Useless &f);

    Useless(Useless &&f) noexcept;

    ~Useless();

    Useless operator+(const Useless &f) const;

    Useless &operator=(const Useless &f);

    Useless &operator=(Useless &&f) noexcept;

    void show_data() const;
};


#endif //CPP101_USELESS_H
