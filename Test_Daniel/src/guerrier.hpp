#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Guerrier : public Unite {

    public : 
    Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd);
    void attack() const;

    protected :

};


#endif
