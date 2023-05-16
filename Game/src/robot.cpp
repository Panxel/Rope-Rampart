#include "robot.hpp"

Robot::Robot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Robot" << std :: endl;
    direction_=Bas;
    rect.top=0;
    rect.left=0;
    rect.height=64;
    rect.width=64;
    compteur=0;
    debut=0;
}

void Robot :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    if(compteur==1)
        {
            compteur=0;
            debut=(debut+64)%1024;
            // Positionnement du rectangle de découpe dans l'image chargée
            rect.left=debut;
        }
    sprite_.setTextureRect(rect);
    compteur++;
    window.draw(sprite_);
}


void Robot :: moveManagement(float x, float y){
    float deltaX =(x+CHATEAU_WIDTH/2)-pos_x_;
    float deltaY =(y+CHATEAU_HEIGHT/2)-pos_y_;
    if(deltaX>=0.8){
        direction_=Droite;
        pos_x_+= 0.8*speed_;
    }
    if(deltaX<-0.8){
        direction_=Gauche;
        pos_x_-= 0.8*speed_;
    }
    if(deltaY>=0.8){
        direction_=Bas;
        pos_y_+= 0.8*speed_;
    }
    if(deltaY<-0.8){
        direction_=Haut;
        pos_y_-= 0.8*speed_;
    }
}