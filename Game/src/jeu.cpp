#include "jeu.hpp"

Jeu :: Jeu(){ //Constructeur initial
    //Ajoute les 2 joueurs et le chateau dans les vecteurs
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],JOUEUR1_INITX,JOUEUR1_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],JOUEUR2_INITX,JOUEUR2_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addChateau(std :: make_shared<Chateau>(loadTexture_.getMap()["Guerrier"],CHATEAU_INITX,CHATEAU_INITY,CHATEAU_HP,CHATEAU_ID));
    //Met les liaisons d'observer
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->addObserverChateau(chateau_[0]);
    }
}

void Jeu :: clearAllObserverLink(){ //Permet d'enlever tous les liens d'observer
    for(robot_ptr monster : wave_.getVectorMonsters()){
        monster->removeObserverChateau(chateau_[0]);
        for(guerrier_ptr joueur : vectorJoueurs_){
            joueur->removeObserverRobot(monster);
        }
    }
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->removeObserverChateau(chateau_[0]);
    }
}

void Jeu :: clearAllVector(){ //Permet de clear tous les vecteurs
    clearVectorJoueur();
    clearVectorChateau();
    wave_.clearVectorMonster();
}

void Jeu :: linkAllRobotObserver(){ //Permet de liés les dépendances d'observer par rapport au robot
    for(robot_ptr monster : wave_.getVectorMonsters()){
        monster->addObserverChateau(chateau_[0]);
        for(guerrier_ptr joueur : vectorJoueurs_){
            joueur->addObserverRobot(monster);
        }
    }
}

void Jeu :: delinkRobotObserver(robot_ptr robot){ //Permet de detacher le robot aux dépendances d'observer
    robot->removeObserverChateau(chateau_[0]);
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->removeObserverRobot(robot);
    }
}

void Jeu :: afficherAllJoueur(){
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->afficher(renderer_.getWindow());
    }
}

void Jeu :: afficherChateau(){
    chateau_[0]->afficher(renderer_.getWindow());
}

void Jeu :: gameInput(){

    //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
    while(renderer_.getWindow().pollEvent(event_)){
        if(event_.type == sf::Event::Closed){
            renderer_.getWindow().close();
            wave_.getOver()=false;
        }else if(event_.type == sf::Event :: KeyPressed && event_.key.code== sf::Keyboard :: Space){
            std :: cout << "Utilisation Attaque" << std :: endl;
            vectorJoueurs_[0]->notifyObserverRobot(vectorJoueurs_[0]);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        renderer_.getWindow().close();
        wave_.getOver()=false;
    }

    //Joueur 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        vectorJoueurs_[0]->getX()-=vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Gauche;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        vectorJoueurs_[0]->getX()+=vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Droite;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        vectorJoueurs_[0]->getY()-=vectorJoueurs_[0]->getSpeed();
        vectorJoueurs_[0]->getDirection()=Haut;
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        vectorJoueurs_[0]->getY()+=vectorJoueurs_[0]->getSpeed();
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
        vectorJoueurs_[1]->getX()-=vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Gauche;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        vectorJoueurs_[1]->getX()+=vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Droite;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        vectorJoueurs_[1]->getY()-=vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Haut;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);

    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        vectorJoueurs_[1]->getY()+=vectorJoueurs_[1]->getSpeed();
        vectorJoueurs_[1]->getDirection()=Bas;
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);
    }

    //Go on next Lvl
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
        wave_.getOver()=false;
    }

}
 

void Jeu :: gameLoop(){
    srand(time(NULL)); //Permet de randomiser
    while(renderer_.getWindow().isOpen() && chateau_[0]->getHP()>0){ //Tant que le chateau est pas détruit ou qu'on ne quitte pas la fenetre
        while(wave_.getOver()){
            gameDraw();
            gameInput();
        }
        //Changement de level
        wave_.waveLevelUp();
        //Link tous les dépendances d'observer par rapport au robot
        linkAllRobotObserver();
        while(renderer_.getWindow().isOpen() && chateau_[0]->getHP()>0 && wave_.getVectorMonsters().size()!=0){ //Tant que le chateau est pas détruit ou qu'on ne quitte pas la fenetre ou que le level actuel n'est pas clear
            wave_.mobSpawnManagement();
            gameInput();
            gamePlay();
            gameDraw();
        }
        wave_.getOver()=true;
    }
    clearAllObserverLink();
    clearAllVector();
}

void Jeu :: gameDraw() {
    //Clear le renderer
    renderer_.getWindow().clear(sf::Color :: Black);

    //Affiche les entités
    afficherAllJoueur();
    afficherChateau();
    wave_.afficherAllMonster(renderer_.getWindow());

    if(wave_.getOver()){
        renderer_.getWindow().draw(renderer_.getText());
    }

    //Affiche le renderer
    renderer_.getWindow().display();
}

void Jeu :: gamePlay(){
    int index=0; //Index de parcours du vector de Monstre
    std::vector<int> vectorIndexDeadMob; //Vector stockant des index des monstres morts sur cet instant
    for(int i=0;i<(wave_.getNbMobsSpawned()-wave_.getNbMobsDied());i++){
        if(wave_.getVectorMonsters()[i]->getDead()){
            wave_.getNbMobsDied()++;
            vectorIndexDeadMob.insert(vectorIndexDeadMob.begin(),index); //Met l'index du monstre mort dans le vecteur (A la fin on aura un ordre décroissant, c'est ce que l'on veut)
            //Il faut delink les observer
            delinkRobotObserver(wave_.getVectorMonsters()[i]);
        }else{
            wave_.getVectorMonsters()[i]->moveManagement();
            wave_.getVectorMonsters()[i]->notifyObserverChateau(wave_.getVectorMonsters()[i]);
        }
        index++;
    }
    //Supprime les robots morts
    for(int i =0; i < vectorIndexDeadMob.size();i++){
        wave_.removeMonster(vectorIndexDeadMob[i]);
    }
}