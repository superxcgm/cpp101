//
// Created by Yujia Li on 2020/5/2.
//

#include "main.h"
#include "boost/lexical_cast.hpp"
#include <iostream>

int cpp_101_boost::main() {
    int i = boost::lexical_cast<int>("123");
    std::cout << i << std::endl;


    int ii;
    try{
        ii = boost::lexical_cast<int>("abc");
    }catch(boost::bad_lexical_cast &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
