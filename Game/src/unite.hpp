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
    Unite(sf::Texture& texture, float x,float y,int health,int id,int atk, int spd);
    
    virtual void attack()= 0;

    //Getters lecture/ecrite

    const int& getAttack() const {return attack_;};
    int& getAttack(){return attack_;};
    const int& getSpeed() const {return speed_;};
    int& getSpeed(){return speed_;};
    const Direction& getDirection() const {return direction_;};
    Direction& getDirection(){return direction_;};

    
    //Sujet
    void addObserverChateau(chateau_ptr observer);
    void removeObserverChateau(chateau_ptr observer);
    void notifyObserverChateau(std::shared_ptr<Unite> unite);

    protected :
    std:: vector<chateau_ptr> vectorObserverChateau_;

    Direction direction_ = Bas;
    int attack_;
    int speed_;

};

typedef std::shared_ptr<Unite> unite_ptr;

#endif
