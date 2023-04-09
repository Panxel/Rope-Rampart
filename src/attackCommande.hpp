#ifndef ATTACKCOMMANDE_HPP
#define ATTACKCOMMANDE_HPP
#include "unite.hpp"
#include <iostream>
#include "commande.hpp"
#include <memory>

typedef std::shared_ptr<Unite> unite_ptr;

class AttackCommande : public Commande {

    public :
    AttackCommande(unite_ptr robot, int damage);

    void execute();

    protected :
    int damageDealt_;
    unite_ptr robot_;


};

#endif