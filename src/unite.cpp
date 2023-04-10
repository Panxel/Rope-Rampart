#include "unite.hpp"

Unite :: Unite(sf::Texture& texture,float x,float y,int health, int atk, int spd) : Entite(texture,x,y){
    std :: cout << "Utilisation Constructeur Unite" << std :: endl;
    hp_=health;
    attack_=atk;
    speed_=spd;
}

void Unite :: takeDamage(int damage){
    hp_-=damage;
}
