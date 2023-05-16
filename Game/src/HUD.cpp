#include "HUD.hpp"

HUD :: HUD(float x,float y)
{
    pos_x_ = x;
    pos_y_ = y;
    sprite_.setScale(3,3);
}

void HUD::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}

void HUD :: afficher(sf::RenderWindow& window){
    window.draw(sprite_);
}