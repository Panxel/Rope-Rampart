#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.hpp"

class Robot : public Unite {

    public :
    Robot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd);
    void attack() const;
    void afficher(sf::RenderWindow& window);
    void update(unite_ptr unite);
    void moveManagement();

};

typedef std::shared_ptr<Robot> robot_ptr;

#endif