//
// Created by Yujia Li on 2020/4/28.
//

#include "Observerable.h"

void Observerable::attach(Observer *p_ob) {
    if (!p_ob) {
        return;
    }
    if (std::find(m_obs.begin(), m_obs.end(), p_ob) != m_obs.end()) {
        return;
    }
    m_obs.push_back(p_ob);
}

void Observerable::notify(void *p_arg) {
    if (!m_change) {
        return;
    }
    for (auto p:m_obs) {
        p->update(p_arg);
    }
    m_change = false;
}

void Observerable::detach(Observer *p_ob) {
    if (!p_ob || m_obs.empty()) {
        return;
    }
    m_obs.remove(p_ob);
}

void Observerable::set_change(const std::string& news) {
    m_change = true;
    notify((void *) news.c_str());
}

void News::get_some_news(std::string str) {
    set_change("News: " + str);
}
