#include "jeu.hpp"

Jeu :: Jeu(){
    joueurs.push_back(&g1);
    joueurs.push_back(&g2);
}

void Jeu :: gameInput(){

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
        joueurs[0]->getX()-=0.02*joueurs[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        joueurs[0]->getX()+=0.02*joueurs[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        joueurs[0]->getY()-=0.02*joueurs[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        joueurs[0]->getY()+=0.02*joueurs[0]->getSpeed();
    }

    //Joueur 2

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        joueurs[1]->getX()-=0.02*joueurs[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        joueurs[1]->getX()+=0.02*joueurs[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        joueurs[1]->getY()-=0.02*joueurs[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        joueurs[1]->getY()+=0.02*joueurs[1]->getSpeed();
    }
}


void Jeu :: gameLoop(){

    while(Renderer :: get_instance().getWindow().isOpen()){
        gameInput();
        gameDraw();
    }
}

void Jeu :: gameDraw() const {
    Renderer :: get_instance().getWindow().clear(sf::Color :: Black);
    joueurs[0]->afficher(Renderer :: get_instance().getWindow());
    joueurs[1]->afficher(Renderer :: get_instance().getWindow());
    Renderer :: get_instance().getWindow().draw(Renderer :: get_instance().getText());
    Renderer :: get_instance().getWindow().display();
}

//void Jeu :: gamePlay(){
//}
