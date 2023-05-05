#include "robot.hpp"

Robot::Robot(sf::Texture& texture,float x,float y,int health,int atk, int spd) : Unite(texture,x,y,health,atk,spd){
    std :: cout << "Creation classe Robot" << std :: endl;
}

void Robot :: attack() const {
    std :: cout << " Utilisation attack de Robot" << std :: endl;
}
