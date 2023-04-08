#ifndef ATTACKCOMMANDE_HPP
#define ATTACKCOMMANDE_HPP
#include "unite.hpp"
#include "commande.hpp"

class AttackCommande : public Commande {

    public :
    AttackCommande(Unite* robot, int damage);

    void execute();

    protected :
    int damageDealt_;
    Unite* robot_;


};

#endif