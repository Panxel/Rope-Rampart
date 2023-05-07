#include "jeu.hpp"

Jeu :: Jeu(){
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],JOUEUR1_INITX,JOUEUR1_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],JOUEUR2_INITX,JOUEUR2_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addMonster(std :: make_shared<Robot>(loadTexture_.getMap()["Robot"],ROBOT_INITX,ROBOT_INITY,ROBOT_HP,ROBOT_ID,ROBOT_DAMAGE,ROBOT_SPEED));
    addEntiteObserver(std :: make_shared<Chateau>(loadTexture_.getMap()["Guerrier"],CHATEAU_INITX,CHATEAU_INITY,CHATEAU_HP,CHATEAU_ID));
}

void Jeu :: gameInput(){

    //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
    while(renderer_.getWindow().pollEvent(event_)){
        if(event_.type == sf::Event::Closed){
        renderer_.getWindow().close();
        }else if(event_.type == sf::Event :: KeyPressed && event_.key.code== sf::Keyboard :: Space){
            std :: cout << "Utilisation Attaque" << std :: endl;
            vectorJoueurs_[0]->notifyObserverRobot(vectorJoueurs_[0]);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        renderer_.getWindow().close();
    }

    //Joueur 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        vectorJoueurs_[0]->getX()-=0.02*vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Gauche;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        vectorJoueurs_[0]->getX()+=0.02*vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Droite;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        vectorJoueurs_[0]->getY()-=0.02*vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Haut;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        vectorJoueurs_[0]->getY()+=0.02*vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Bas;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }

    /*
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        std :: cout << "Utilisation Attaque" << std :: endl;
        vectorJoueurs_[0]->notifyObserverRobot(vectorJoueurs_[0]);
    }*/
    
    //Joueur 2

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        vectorJoueurs_[1]->getX()-=0.02*vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Gauche;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        vectorJoueurs_[1]->getX()+=0.02*vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Droite;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        vectorJoueurs_[1]->getY()-=0.02*vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Haut;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        vectorJoueurs_[1]->getY()+=0.02*vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Bas;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }

}
 

void Jeu :: gameLoop(){
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->addObserverChateau(chateau_[0]);
        for(robot_ptr monster : vectorMonsters_){
            monster->addObserverChateau(chateau_[0]);
            joueur->addObserverRobot(monster);
        }
    }
    while(renderer_.getWindow().isOpen()){
        gameInput();
        gamePlay();
        gameDraw();
    }
}

void Jeu :: gameDraw() {
    renderer_.getWindow().clear(sf::Color :: Black);
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->afficher(renderer_.getWindow());
    }
    for(robot_ptr monster : vectorMonsters_){
        monster->afficher(renderer_.getWindow());
    }
    chateau_[0]->afficher(renderer_.getWindow());
    renderer_.getWindow().draw(renderer_.getText());
    renderer_.getWindow().display();
}

void Jeu :: gamePlay(){
    for(robot_ptr monster : vectorMonsters_){
        float deltaX =(CHATEAU_INITX+CHATEAU_WIDTH/2)-monster->getX();
        float deltaY =(CHATEAU_INITY+CHATEAU_HEIGHT/2)-monster->getY();
        if(deltaX>0){
            monster->getX()+= 0.02*monster->getSpeed();
        }else if(deltaX<0){
            monster->getX()-= 0.02*monster->getSpeed();
        }
        if(deltaY>0){
            monster->getY()+= 0.02*monster->getSpeed();
        }else if(deltaY<0){
            monster->getY()-= 0.02*monster->getSpeed();
        }
        monster->notifyObserverChateau(monster);        
    }
}
