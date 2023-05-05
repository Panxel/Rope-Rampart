#include "jeu.hpp"

Jeu :: Jeu(){
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],0.3*WIN_WIDTH,0.3*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addMonster(std :: make_shared<Robot>(loadTexture_.getMap()["Robot"],0.2*WIN_WIDTH,0.2*WIN_HEIGHT,ROBOT_HP,ROBOT_DAMAGE,ROBOT_SPEED));
    addEntiteObserver(std :: make_shared<Chateau>(loadTexture_.getMap()["Guerrier"],0.8*WIN_WIDTH,0.8*WIN_HEIGHT,CHATEAU_HP));
}

void Jeu :: gameInput(){

    //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
    while(renderer_.getWindow().pollEvent(event_)){
    }
    if(event_.type == sf::Event::Closed){
        renderer_.getWindow().close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        renderer_.getWindow().close();
    }

    //Joueur 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        joueurs_[0]->getX()-=0.02*joueurs_[0]->getSpeed();
        joueurs_[0]->getDirection()=Gauche;
        joueurs_[0]->notifyObserver(joueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        joueurs_[0]->getX()+=0.02*joueurs_[0]->getSpeed();
        joueurs_[0]->getDirection()=Droite;
        joueurs_[0]->notifyObserver(joueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        joueurs_[0]->getY()-=0.02*joueurs_[0]->getSpeed();
        joueurs_[0]->getDirection()=Haut;
        joueurs_[0]->notifyObserver(joueurs_[0]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        joueurs_[0]->getY()+=0.02*joueurs_[0]->getSpeed();
        joueurs_[0]->getDirection()=Bas;
        joueurs_[0]->notifyObserver(joueurs_[0]);

    }

    //Joueur 2

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        joueurs_[1]->getX()-=0.02*joueurs_[1]->getSpeed();
        joueurs_[1]->getDirection()=Gauche;
        joueurs_[1]->notifyObserver(joueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        joueurs_[1]->getX()+=0.02*joueurs_[1]->getSpeed();
        joueurs_[1]->getDirection()=Droite;
        joueurs_[1]->notifyObserver(joueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        joueurs_[1]->getY()-=0.02*joueurs_[1]->getSpeed();
        joueurs_[1]->getDirection()=Haut;
        joueurs_[1]->notifyObserver(joueurs_[1]);


    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        joueurs_[1]->getY()+=0.02*joueurs_[1]->getSpeed();
        joueurs_[1]->getDirection()=Bas;
        joueurs_[1]->notifyObserver(joueurs_[1]);


    }

}
 

void Jeu :: gameLoop(){
    joueurs_[0]->addObserver(chateau_[0]);
    joueurs_[1]->addObserver(chateau_[0]);
    monsters_[0]->addObserver(chateau_[0]);
    while(renderer_.getWindow().isOpen()){
        gameInput();
        gameDraw();
    }
}

void Jeu :: gameDraw() const {
    renderer_.getWindow().clear(sf::Color :: Black);
    joueurs_[0]->afficher(renderer_.getWindow());
    joueurs_[1]->afficher(renderer_.getWindow());
    monsters_[0]->afficher(renderer_.getWindow());
    chateau_[0]->afficher(renderer_.getWindow());
    renderer_.getWindow().draw(renderer_.getText());
    renderer_.getWindow().display();
}

//void Jeu :: gamePlay(){
//}
