#include "entite.hpp"

Entite::Entite(sf::Texture& texture,float x,float y){
    std :: cout << "Utilisation Constructeur Entite" << std :: endl;
    pos_x_=x;
    pos_y_=y;
    loadSprite(texture);
}

void Entite::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}
