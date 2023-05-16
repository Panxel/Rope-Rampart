#include "lifebar.hpp"
#include <math.h>

Lifebar :: Lifebar(float x,float y)
{
    pos_x_ = x;
    pos_y_ = y;
    sprite_.setScale(3,3);
}

void Lifebar::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}

void Lifebar :: afficher(sf::RenderWindow& window){
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}