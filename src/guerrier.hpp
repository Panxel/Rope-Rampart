#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"

class Guerrier : public Unite {

    public : 
    Guerrier(int x,int y,int health,int dmg, int spd, int def);
    void afficher() const;
    void attack() const;

    protected :

};


#endif
