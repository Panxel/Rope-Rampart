#include "mbot.hpp"

// Constructeur de la classe Mbot
Mbot::Mbot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Robot(texture,x,y,health,id,atk,spd){
    soundBuffer.loadFromFile("../res/Son/robot2.wav");
    sound_.setBuffer(soundBuffer);
    sound_.setVolume(100);
}

void Mbot :: attack(){
}

void Mbot :: update(unite_ptr unite){
    // Test si le mbot est attaqué.
    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+MBOT_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+MBOT_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        takeDamage(unite->getAttack());
        if(hp_<=0){
            dead_=true;

        }
    }
}