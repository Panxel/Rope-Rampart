#include "robot.hpp"

Robot::Robot(sf::Texture& texture,float x,float y,int health,int atk, int spd) : Unite(texture,x,y,health,atk,spd){
    std :: cout << "Creation classe Robot" << std :: endl;
}

void Robot :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}

void Robot :: attack() const {
    std :: cout << " Utilisation attack de Robot" << std :: endl;
}
