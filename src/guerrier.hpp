#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <SFML/Graphics.hpp>

class Guerrier : public Unite {

    public : 
    Guerrier(float x,float y,int health,int dmg, int spd);
    void afficher(sf::RenderWindow& window);
    void attack() const;

    protected :

};


#endif
