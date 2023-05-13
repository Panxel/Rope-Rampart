#include "jeu.hpp"

Jeu :: Jeu(){ //Constructeur initial
    //Ajoute les 2 joueurs et le chateau dans les vecteurs
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],JOUEUR1_INITX,JOUEUR1_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],JOUEUR2_INITX,JOUEUR2_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addChateau(std :: make_shared<Chateau>(loadTexture_.getMap()["Chateau"],CHATEAU_INITX,CHATEAU_INITY,CHATEAU_HP,CHATEAU_ID));
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
        for(bombe_ptr bombe : wave_.getVectorBombe()){
            bombe->removeObserverGuerrier(joueur);
            joueur->removeObserverBombe(bombe);
        }
    }
}

void Jeu :: linkAllRobotObserver(){ //Permet de liés les dépendances d'observer par rapport à tous les robots
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

void Jeu :: linkBombeObserver(bombe_ptr bombe){ //Permet de liés les dépendances d'observer par rapport à la bombe
    for(guerrier_ptr guerrier : vectorJoueurs_){
        bombe->addObserverGuerrier(guerrier);
        guerrier->addObserverBombe(bombe);
    }
}

void Jeu :: delinkBombeObserver(bombe_ptr bombe){ //Permet de detacher la bombe aux dépendances d'observer
    for(guerrier_ptr guerrier : vectorJoueurs_){
        guerrier->removeObserverBombe(bombe);
        bombe->removeObserverGuerrier(guerrier);
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
}

void Jeu :: gameDraw() {
    //Clear le renderer
    renderer_.getWindow().clear(sf::Color :: Black);

    //Affiche les entités
    afficherAllJoueur();
    afficherChateau();
    if(wave_.getOver()){
        renderer_.getWindow().draw(renderer_.getText());
    }else{
        wave_.afficherAllMonster(renderer_.getWindow());
        wave_.afficherAllBombe(renderer_.getWindow());
    }
    //Affiche le renderer
    renderer_.getWindow().display();
}

void Jeu :: gamePlay(){
    int i;
    for(i=0;i<(wave_.getNbMobsSpawned()-wave_.getNbMobsDied());i++){
        robot_ptr monster = wave_.getVectorMonsters()[i];
        if(monster->getDead()){ //Supprime les robots morts
            wave_.getNbMobsDied()++;
            //Il faut delink les observer
            delinkRobotObserver(monster);
            //Si c'est un Bombot, il lâche une bombe
            if(monster->getID()==3){
                wave_.addBombe(std::make_shared<Bombe>(loadTexture_.getMap()["Bombe"],monster->getX(),monster->getY(),BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE));
                linkBombeObserver(wave_.getVectorBombe().back());
            }
            wave_.removeMonster(i);
            i--;
        }else{
            monster->moveManagement();
            monster->notifyObserverChateau(monster);
        }
    }
    //Fait exploser les bombes
    wave_.explodeAllBombe();
    //Supprime les bombes mortes
    for(i =wave_.getVectorBombe().size(); i > 0 ;i--){
        if(wave_.getVectorBombe()[i-1]->getDead()){
            delinkBombeObserver(wave_.getVectorBombe()[i-1]);
            wave_.removeBombe(i-1);
        }
    }
}
