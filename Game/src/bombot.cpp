#include "bombot.hpp"

Bombot::Bombot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Robot(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Bombot" << std :: endl;
    
}

void Bombot :: attack(){
    std :: cout << " Utilisation attack de Bombot" << std :: endl;
}

void Bombot :: update(unite_ptr unite){

    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+BOMBOT_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+BOMBOT_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        std :: cout << "Bombot Damaged" << std :: endl;
        takeDamage(unite->getAttack());
        if(hp_<=0){
            dead_=true;
        }
        std :: cout << "HP Bombot : " << getHP() << std :: endl;
    }
}