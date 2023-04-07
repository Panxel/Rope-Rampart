#ifndef UNITE_HPP
#define UNITE_HPP
#include "entite.hpp"
#include <iostream>

class Unite : public Entite {

    public : 
    Unite(float x,float y,int health,int dmg, int spd);
    
    virtual void attack() const = 0;

    const bool dead() const{return hp<=0;};

    //Getters lecture/ecrite
    const int& getHP() const {return hp;};
    int& getHP(){return hp;};
    const int& getDamage() const {return damage;};
    int& getDamage(){return damage;};
    const int& getSpeed() const {return speed;};
    int& getSpeed(){return speed;};


    protected :

    int hp;
    int damage;
    int speed;

};


#endif
