//
// Created by Yujia Li on 2020/4/25.
//

#include "Complex.h"
#include <iostream>

namespace ObjectOriented {
    int main() {
        Complex a(1.0, 2.0);

        std::cout << a.GetReal() << std::endl;  // 1.0
        std::cout << a.GetImage() << std::endl; //2.0

        a.SetReal(2.0);
        a.SetImage(3.0);
        std::cout << a.GetReal() << std::endl;  //2.0
        std::cout << a.GetImage() << std::endl; //3.0

        Complex b(2.0, 3.0);
//        Complex c;
//        c = a + b;

        Complex c = a + b;

        Complex d(c); // 拷贝构造
        std::cout << "d:" << d << std::endl;
        Complex e;
        e = d++;
        std::cout << "e:" << e << std::endl;
        e = ++d;
        std::cout << "e:" << e << std::endl;

        Complex tmp;
        std::cin >> tmp;
        std::cout << tmp << std::endl;

        return 0;
    }
}