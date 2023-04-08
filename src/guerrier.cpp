#include "guerrier.hpp"

Guerrier::Guerrier(float x,float y,int health,int dmg, int spd) : Unite(x,y,health,dmg,spd){
    texture_.loadFromFile("../res/test_small.jpg");
    sprite_.setTexture(texture_);
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
}