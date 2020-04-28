//
// Created by Yujia Li on 2020/4/25.
//

#include "Complex.h"
#include "my_string.h"
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

        std::cout<< "e == d " << (e == d) << std::endl;
        std::cout<< "e == a " << (e == a) << std::endl;
        std::cout<< "e != d " << (e != d) << std::endl;
        std::cout<< "e != a " << (e != a) << std::endl;

        Complex tmp;
        std::cin >> tmp;
        std::cout << tmp << std::endl;

        tmp += a;
        std::cout << tmp << std::endl;

        string s1("Hello");
        std::cout << s1 << std::endl;
//        string s2 = s1; // 拷贝构造
        string s2(s1);
        std::cout << s2 << std::endl;

        string s2A(std::move(s1));
        std::cout << s2A << std::endl;

        string s3;
        std::cout << s3 << std::endl;

        s3 = s2;
        std::cout << s3 << std::endl;

        string s3A;
        s3A = std::move(s2A);
        std::cout << s3A << std::endl;

        return 0;
    }
}