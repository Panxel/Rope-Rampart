#ifndef UNITE_HPP
#define UNITE_HPP
#include "entite.hpp"
#include <iostream>
#include "commande.hpp"
#include <memory>
#include <SFML/Graphics.hpp>

typedef std::unique_ptr<Commande> commande_ptr;

class Unite : public Entite {

    public : 
    Unite(sf::Texture& texture, float x,float y,int health,int atk, int spd);
    
    virtual void attack() const = 0;

    const bool dead() const{return hp_<=0;};
    void takeDamage(int damage);

    //Getters lecture/ecrite
    const int& getHP() const {return hp_;};
    int& getHP(){return hp_;};
    const int& getAttack() const {return attack_;};
    int& getDamage(){return attack_;};
    const int& getSpeed() const {return speed_;};
    int& getSpeed(){return speed_;};

    void setCommande(commande_ptr commande);
    void executeCommande();

    protected : 

    int hp_;
    int attack_;
    int speed_;
    commande_ptr commande_;

};

typedef std::shared_ptr<Unite> unite_ptr;

#endif
