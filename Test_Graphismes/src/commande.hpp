#ifndef COMMANDE_HPP
#define COMMANDE_HPP
#include <memory>

class Commande{

    public :
    virtual void execute() = 0;

};

typedef std::unique_ptr<Commande> commande_ptr;

#endif