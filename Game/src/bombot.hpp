#ifndef BOMBOT_HPP
#define BOMBOT_HPP
#include "robot.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Bombot : public Robot {

    public : 
    Bombot(sf::Texture& texture, float x,float y,int health,int id,int atk, int spd);
    
    void update(unite_ptr unite);
    void attack();

    protected :

};

#endif
