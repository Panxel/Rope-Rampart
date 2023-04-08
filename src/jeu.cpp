#include "jeu.hpp"

Jeu :: Jeu(){
    joueurs_.push_back(&g1_);
    joueurs_.push_back(&g2_);
    monsters_.push_back(&r1_);
}

void Jeu :: gameInput(){

    //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
    while(Renderer :: get_instance().getWindow().pollEvent(event_)){
    }
    if(event_.type == sf::Event::Closed){
        Renderer :: get_instance().getWindow().close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        Renderer :: get_instance().getWindow().close();
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
        g1_.setCommande(std::make_unique<AttackCommande>(monsters_[0],g1_.getAttack()));
        g1_.executeCommande();
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
    joueurs_[0]->afficher(Renderer :: get_instance().getWindow());
    joueurs_[1]->afficher(Renderer :: get_instance().getWindow());
    monsters_[0]->afficher(Renderer :: get_instance().getWindow());
    Renderer :: get_instance().getWindow().draw(Renderer :: get_instance().getText());
    Renderer :: get_instance().getWindow().display();
}

//void Jeu :: gamePlay(){
//}
