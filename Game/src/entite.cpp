#include "entite.hpp"

Entite::Entite(sf::Texture& texture,float x,float y,int health,int id){
    std :: cout << "Utilisation Constructeur Entite" << std :: endl;
    pos_x_=x;
    pos_y_=y;
    hp_=health;
    id_=id;
    dead_=false;
    loadSprite(texture);
}

void Entite::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}

void Entite :: takeDamage(const int& damage){
    hp_-=damage;
}

