#ifndef UNITE_HPP
#define UNITE_HPP
#include "entite.hpp"
#include <iostream>

class Unite : public Entite {

    public : 
    Unite(float x,float y,int health,int dmg, int spd);
    
    virtual void attack() const = 0;

    const bool dead() const{return hp_<=0;};

    //Getters lecture/ecrite
    const int& getHP() const {return hp_;};
    int& getHP(){return hp_;};
    const int& getDamage() const {return damage_;};
    int& getDamage(){return damage_;};
    const int& getSpeed() const {return speed_;};
    int& getSpeed(){return speed_;};


    protected :

    int hp_;
    int damage_;
    int speed_;

};


#endif
