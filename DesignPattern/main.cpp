//
// Created by Yujia Li on 2020/4/28.
//

#include <memory>
#include "main.h"
#include "Singleton.h"
#include "Observer.h"
#include "Observerable.h"

int DesignPattern::main() {
//    Singleton::get_instance()->do_something();
    User1 u1;
    User2 u2;
    News news;

    news.get_some_news("T0");
    std::cout << news.get_observer_count() << std::endl;

    news.attach(&u1);
    news.attach(&u2);
    news.get_some_news("T1");
    std::cout << news.get_observer_count() << std::endl;

    news.detach(&u2);
    news.get_some_news("T2");
    std::cout << news.get_observer_count() << std::endl;

    news.detach_all();
    news.get_some_news("T3");
    std::cout << news.get_observer_count() << std::endl;

    return 0;
}
