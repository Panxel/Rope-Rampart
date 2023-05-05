#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


class Robot : public Unite {

    public :
    Robot(sf::Texture& texture,float x,float y,int health,int atk, int spd);
    void attack() const;
};

#endif