#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "guerrier.hpp"
#include "jeu.hpp"
#include <vector>

Jeu :: Jeu(){
    joueurs.push_back(&g1);
    joueurs.push_back(&g2);
}

void Jeu :: gameLoop(){

    while(Renderer :: get_instance().getWindow().isOpen()){
        //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
        while(Renderer :: get_instance().getWindow().pollEvent(event)){
        }
        input();
        gameDraw();
    }
}

void Jeu :: gameDraw() const {
    Renderer :: get_instance().getWindow().clear(sf::Color :: Black);
    getJoueurs()[0]->afficher(Renderer :: get_instance().getWindow());
    getJoueurs()[1]->afficher(Renderer :: get_instance().getWindow());
    Renderer :: get_instance().getWindow().draw(Renderer :: get_instance().getText());
    Renderer :: get_instance().getWindow().display();
}

//void Jeu :: gamePlay(){
//}

void Jeu :: input(){

    //Fermeture du jeu//
    //Utilisation de event pour donner une utilité//
    if(event.type == sf::Event::Closed){
        renderer.getWindow().close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        renderer.getWindow().close();
    }

    //Joueur 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        g1.getX()-=0.05;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        g1.getX()+=0.05;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        g1.getY()-=0.05;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        g1.getY()+=0.05;
    }

    //Joueur 2

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        g2.getX()-=0.05;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        g2.getX()+=0.05;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        g2.getY()-=0.05;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        g2.getY()+=0.05;
    }
}