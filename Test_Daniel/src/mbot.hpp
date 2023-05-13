#ifndef MBOT_HPP
#define MBOT_HPP
#include "robot.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Mbot : public Robot {

    public : 
    Mbot(sf::Texture& texture, float x,float y,int health,int id,int atk, int spd);
    
    void update(unite_ptr unite);
    void attack() const;

    protected :

};

#endif
