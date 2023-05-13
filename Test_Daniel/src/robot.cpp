#include "robot.hpp"

Robot::Robot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Robot" << std :: endl;
}

void Robot :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}


void Robot :: moveManagement(){
    float deltaX =(CHATEAU_INITX+CHATEAU_WIDTH/2)-pos_x_;
    float deltaY =(CHATEAU_INITY+CHATEAU_HEIGHT/2)-pos_y_;
    if(deltaX>0){
        pos_x_+= speed_;
    }else if(deltaX<0){
        pos_x_-= speed_;
    }
    if(deltaY>0){
        pos_y_+= speed_;
    }else if(deltaY<0){
        pos_y_-= speed_;
    }
}