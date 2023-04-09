#ifndef MOVECOMMANDE_HPP
#define MOVECOMMANDE_HPP
#include "unite.hpp"
#include <iostream>
#include "commande.hpp"

class MoveCommande : public Commande {

    public :
    MoveCommande(unite_ptr unite,float x, float y);

    void execute();

    protected :
    unite_ptr unite_;
    
};

#endif