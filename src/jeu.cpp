#include "jeu.hpp"

Jeu :: Jeu(){
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],0.8*WIN_WIDTH,0.8*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addMonster(std :: make_shared<Robot>(loadTexture_.getMap()["Robot"],0.2*WIN_WIDTH,0.2*WIN_HEIGHT,Robot_HP,Robot_DAMAGE,Robot_SPEED));
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
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        joueurs_[0]->getX()+=0.02*joueurs_[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        joueurs_[0]->getY()-=0.02*joueurs_[0]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        joueurs_[0]->getY()+=0.02*joueurs_[0]->getSpeed();
    }

    //Joueur 2

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        joueurs_[1]->getX()-=0.02*joueurs_[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        joueurs_[1]->getX()+=0.02*joueurs_[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        joueurs_[1]->getY()-=0.02*joueurs_[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        joueurs_[1]->getY()+=0.02*joueurs_[1]->getSpeed();
    }


    // TEST
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        joueurs_[0]->setCommande(std::make_unique<AttackCommande>(monsters_[0],joueurs_[0]->getAttack()));
        joueurs_[0]->executeCommande();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
        joueurs_[0]->setCommande(std::make_unique<MoveCommande>(joueurs_[1],0.02*joueurs_[1]->getSpeed(),0.02*joueurs_[1]->getSpeed()));
        joueurs_[0]->executeCommande();
    }

}
 

void Jeu :: gameLoop(){

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
    renderer_.getWindow().draw(renderer_.getText());
    renderer_.getWindow().display();
}

//void Jeu :: gamePlay(){
//}
