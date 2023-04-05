#ifndef UNITE_HPP
#define UNITE_HPP
#include "entite.hpp"

class Unite : public Entite {

    public : 
    Unite(int x,int y,int health,int dmg, int spd, int def);
    //void afficher() const;
    //virtual void attack() const = 0;

    protected :

    int hp;
    int damage;
    int speed;
    int defense;

};


#endif
