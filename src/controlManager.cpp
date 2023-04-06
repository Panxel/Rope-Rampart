#include <iostream>
#include "controlManager.hpp"
#include "renderer.hpp"
#include "jeu.hpp"
#include <SFML/Graphics.hpp>


void ControlManager :: gameInput(){

    //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
    while(Renderer :: get_instance().getWindow().pollEvent(event)){
    }

    
    if(event.type == sf::Event::Closed){
        Renderer :: get_instance().getWindow().close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        Renderer :: get_instance().getWindow().close();
    }

    //Joueur 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        getJoueurs()[0]->getX()-=0.02*getJoueurs()[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        getJoueurs()[0]->getX()+=0.02*getJoueurs()[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        getJoueurs()[0]->getY()-=0.02*getJoueurs()[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        getJoueurs()[0]->getY()+=0.02*getJoueurs()[0]->getSpeed();
    }

    //Joueur 2

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        getJoueurs()[1]->getX()-=0.02*getJoueurs()[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        getJoueurs()[1]->getX()+=0.02*getJoueurs()[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        getJoueurs()[1]->getY()-=0.02*getJoueurs()[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        getJoueurs()[1]->getY()+=0.02*getJoueurs()[1]->getSpeed();
    }
}
