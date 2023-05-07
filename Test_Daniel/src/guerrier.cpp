#include "guerrier.hpp"

Guerrier::Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
}
