#include "robot.hpp"

Robot::Robot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Robot" << std :: endl;
}

void Robot :: attack() const {
    std :: cout << " Utilisation attack de Robot" << std :: endl;
}

void Robot :: update(unite_ptr unite){

    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+ROBOT_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+ROBOT_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        std :: cout << "Robot Damaged" << std :: endl;
        takeDamage(unite->getAttack());
        std :: cout << "HP ROBOT : " << getHP() << std :: endl;
    }
}