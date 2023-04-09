#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

class Guerrier : public Unite {

    public : 
    Guerrier(sf::Texture& texture,float x,float y,int health,int atk, int spd);
    void afficher(sf::RenderWindow& window);
    void attack() const;

    protected :

};


#endif
