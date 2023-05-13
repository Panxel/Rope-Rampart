#include "mbot.hpp"

Mbot::Mbot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Robot(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Mbot" << std :: endl;
}

void Mbot :: attack() const {
    std :: cout << " Utilisation attack de Mbot" << std :: endl;
}

void Mbot :: update(unite_ptr unite){

    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+MBOT_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+MBOT_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        std :: cout << "Mbot Damaged" << std :: endl;
        takeDamage(unite->getAttack());
        if(hp_<=0){
            dead_=true;
        }
        std :: cout << "HP Mbot : " << getHP() << std :: endl;
    }
}