#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include "robot.hpp"
#include "bombe.hpp"
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
    void addObserverBombe(bombe_ptr bombe);
    void removeObserverBombe(bombe_ptr bombe);
    void notifyObserverBombe(unite_ptr unite);
    void update(bombe_ptr bombe);

    protected :
    std:: vector<robot_ptr> vectorObserverRobot_;
    std:: vector<bombe_ptr> vectorObserverBombe_;

};

typedef std::shared_ptr<Guerrier> guerrier_ptr;


#endif
