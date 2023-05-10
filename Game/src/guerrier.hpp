#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include "robot.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Guerrier : public Unite {

    public : 
    Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd);
    void attack() const;
    void afficher(sf::RenderWindow& window);
    //Sujet
    void addObserverRobot(robot_ptr robot);
    void removeObserverRobot(robot_ptr robot);
    void notifyObserverRobot(unite_ptr unite);
    void clearVectorObserverRobot(){vectorObserverRobot_.clear();};

    protected :
    std:: vector<robot_ptr> vectorObserverRobot_;

};

typedef std::shared_ptr<Guerrier> guerrier_ptr;


#endif
