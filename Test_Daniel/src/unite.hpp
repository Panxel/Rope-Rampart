#ifndef UNITE_HPP
#define UNITE_HPP
#include "entite.hpp"
#include "chateau.hpp"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

enum Direction{
    Haut,
    Droite,
    Bas,
    Gauche
};

class Unite : public Entite {

    public : 
    Unite(sf::Texture& texture, float x,float y,int health,int atk, int spd);
    
    virtual void attack() const = 0;

    const bool dead() const{return hp_<=0;};
    void takeDamage(int damage);

    //Getters lecture/ecrite

    const int& getAttack() const {return attack_;};
    int& getDamage(){return attack_;};
    const int& getSpeed() const {return speed_;};
    int& getSpeed(){return speed_;};
    const Direction& getDirection() const {return direction_;};
    Direction& getDirection(){return direction_;};

    
    //Sujet
    void addObserver(chateau_ptr observer);
    void removeObserver(chateau_ptr observer);
    void notifyObserver(std::shared_ptr<Unite> unite);

    protected :
    std:: vector<chateau_ptr> vectorObserver_;

    bool dead_ = false;
    Direction direction_ = Bas;
    int attack_;
    int speed_;

};

typedef std::shared_ptr<Unite> unite_ptr;

#endif
