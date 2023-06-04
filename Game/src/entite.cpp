#include "entite.hpp"

// Constructeur de la classe Entité
Entite::Entite(sf::Texture& texture,float x,float y,int health,int id){
    pos_x_=x;
    pos_y_=y;
    hp_=health;
    id_=id;
    dead_=false;
    // On charge la texture sur le sprite de l'entité
    loadSprite(texture);
}

// Charge la texture du sprite de l'entité
void Entite::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}

void Entite :: takeDamage(const int& damage){
    hp_-=damage;
}

