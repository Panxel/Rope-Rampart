#include "entite.hpp"

Entite::Entite(sf::Texture& texture,float x,float y,int health){
    std :: cout << "Utilisation Constructeur Entite" << std :: endl;
    pos_x_=x;
    pos_y_=y;
    hp_=health;
    loadSprite(texture);
}

void Entite :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}


void Entite::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}
