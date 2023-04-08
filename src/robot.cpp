#include "robot.hpp"

Robot::Robot(float x,float y,int health,int atk, int spd) : Unite(x,y,health,atk,spd){
    texture_.loadFromFile("../res/robot_small.jpg");
    sprite_.setTexture(texture_);
    std :: cout << "Creation classe Robot" << std :: endl;
}

void Robot :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    window.draw(sprite_);
}

void Robot :: attack() const {
    std :: cout << " Utilisation attack de Robot" << std :: endl;
}
