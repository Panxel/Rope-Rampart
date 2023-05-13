#include "guerrier.hpp"

Guerrier::Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
}

void Guerrier :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}

void Guerrier :: addObserverRobot(robot_ptr robot){
    vectorObserverRobot_.push_back(robot);
}
void Guerrier :: removeObserverRobot(robot_ptr robot){
    vectorObserverRobot_.erase(std::find(vectorObserverRobot_.begin(),vectorObserverRobot_.end(),robot));
}
void Guerrier :: notifyObserverRobot(unite_ptr unite){
    for(robot_ptr robot : vectorObserverRobot_){
        robot->update(unite);
    }
}

void Guerrier :: addObserverBombe(bombe_ptr bombe){
    vectorObserverBombe_.push_back(bombe);
}
void Guerrier :: removeObserverBombe(bombe_ptr bombe){
    vectorObserverBombe_.erase(std::find(vectorObserverBombe_.begin(),vectorObserverBombe_.end(),bombe));
}
void Guerrier :: notifyObserverBombe(unite_ptr unite){
    for(bombe_ptr bombe : vectorObserverBombe_){
        bombe->update(unite);
    }
}

void Guerrier :: update(bombe_ptr bombe){
    if(std::max(pos_x_,bombe->getX()) < std::min(pos_x_+GUERRIER_WIDTH, bombe->getX()+BOMBE_WIDTH) && std::max(pos_y_,bombe->getY()) < std::min(pos_y_+GUERRIER_HEIGHT, bombe->getY()+BOMBE_HEIGHT)){
        std :: cout << "Bombe damage le Guerrier" << std :: endl;
        takeDamage(bombe->getAttack());
        std :: cout << "HP Guerrier : " << getHP() << std :: endl;
        bombe->getDead()=true;
    }
}