#include "guerrier.hpp"

Guerrier::Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
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