#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>


class Robot : public Unite {

    public :
    Robot(float x,float y,int health,int atk, int spd);
    void afficher(sf::RenderWindow& window);
    void attack() const;
};

#endif