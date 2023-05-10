#include "robot.hpp"

Robot::Robot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Robot" << std :: endl;
}

void Robot :: attack() const {
    std :: cout << " Utilisation attack de Robot" << std :: endl;
}

void Robot :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}

void Robot :: update(unite_ptr unite){

    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+ROBOT_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+ROBOT_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        std :: cout << "Robot Damaged" << std :: endl;
        takeDamage(unite->getAttack());
        if(hp_<=0){
            dead_=true;
        }
        std :: cout << "HP ROBOT : " << getHP() << std :: endl;
    }
}