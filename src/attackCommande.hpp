#ifndef ATTACKCOMMANDE_HPP
#define ATTACKCOMMANDE_HPP
#include "unite.hpp"
#include <iostream>
#include "commande.hpp"

class AttackCommande : public Commande {

    public :
    AttackCommande(unite_ptr unite, int damage);

    void execute();

    protected :
    int damageDealt_;
    unite_ptr unite_;


};

#endif