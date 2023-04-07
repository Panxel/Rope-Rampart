#include "guerrier.hpp"

Guerrier::Guerrier(float x,float y,int health,int dmg, int spd) : Unite(x,y,health,dmg,spd){
    texture.loadFromFile("../res/test_small.jpg");
    sprite.setTexture(texture);
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: afficher(sf::RenderWindow& window) {
    sprite.setPosition(round(pos_x),round(pos_y));
    window.draw(sprite);
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
}