#include "guerrier.hpp"

Guerrier::Guerrier(sf::Texture& texture,float x,float y,int health,int atk, int spd) : Unite(texture,x,y,health,atk,spd){
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
}
