#ifndef SUJET_HPP
#define SUJET_HPP
#include "observer.hpp"
#include <algorithm>
#include <vector>

class Sujet{

    public :
    Sujet()=delete;

    void addObserver(observer_ptr observer);
    void removeObserver(observer_ptr observer);
    void notifyObserver();

    protected :
    std:: vector<observer_ptr> vectorObserver_;

};

#endif