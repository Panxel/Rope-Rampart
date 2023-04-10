#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include <memory>

class Observer{

    public :

    virtual void update() = 0;

};

typedef std::shared_ptr<Observer> observer_ptr;


#endif