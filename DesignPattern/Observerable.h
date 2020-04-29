//
// Created by Yujia Li on 2020/4/28.
//

#ifndef CPP101_OBSERVERABLE_H
#define CPP101_OBSERVERABLE_H


#include <list>
#include <string>

#include "Observer.h"

class Observerable {
public:
    virtual ~Observerable() = default;

    void attach(Observer *p_ob);

    void detach(Observer *p_ob);
    void detach_all() {
        m_obs.clear();
    }

    int get_observer_count() const {
        return m_obs.size();
    }

    virtual void get_some_news(std::string str) = 0;

protected:
    void set_change(const std::string &news);

private:
    std::list<Observer *> m_obs;

    void notify(void *p_arg);

    bool m_change = false;
};

class News : public Observerable {
public:
    void get_some_news(std::string str) override;
};

#endif //CPP101_OBSERVERABLE_H
