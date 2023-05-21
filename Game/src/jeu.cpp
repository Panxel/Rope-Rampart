#include "jeu.hpp"

Jeu :: Jeu(){ //Constructeur initial
    //Ajoute les 2 joueurs et le chateau dans les vecteurs
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],JOUEUR1_INITX,JOUEUR1_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j2"],JOUEUR2_INITX,JOUEUR2_INITY,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addChateau(std :: make_shared<Chateau>(loadTexture_.getMap()["Chateau"],CHATEAU_INITX,CHATEAU_INITY,CHATEAU_HP,CHATEAU_ID));
    // Chargement des textures de la map et de la minimap.
    background.loadSprites(loadTexture_.getMap()["Map"], loadTexture_.getMap()["Minimap"], loadTexture_.getMap()["Rope"],loadTexture_.getMap()["HUD_j1"],loadTexture_.getMap()["HUD_j2"]);
    background.loadSpritesScreen(loadTexture_.getMap()["New_level"]);
    //Met les liaisons d'observer
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->addObserverChateau(chateau_[0]);
    }
     // Set position j1 et j2 et background 
    background.getX()=-200;
    background.getY()=-200;
    vectorJoueurs_[0]->getX() = 500 - 200;
    vectorJoueurs_[0]->getY()= 520-200;
    vectorJoueurs_[1]->getX() = 550-200;
    vectorJoueurs_[1]->getY() = 520-200;
    chateau_[0]->getX() -= 200;
    chateau_[0]->getY() -= 200;
    // Set position Lifebar j1 et j2
    vectorJoueurs_[0]->getLifebar().getX() = 52;
    vectorJoueurs_[0]->getLifebar().getY() = 568;
    vectorJoueurs_[1]->getLifebar().getX() = 654;
    vectorJoueurs_[1]->getLifebar().getY() = 568;
    // Ajoute nom des joueurs
    background.getHUD_j1().setText("PLAYER ONE",16,sf::Color::Red);
    background.getHUD_j2().setText("PLAYER TWO",16,sf::Color::Blue);
    background.getHUD_j1().getText().setPosition(60,545);
    background.getHUD_j2().getText().setPosition(655,545);
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

void Jeu :: decalerAllAffichablesX(){
    background.isBorderReached();
    if(vectorJoueurs_[0]->getX()>=700 || vectorJoueurs_[1]->getX()>=700)
    {
        if(vectorJoueurs_[0]->getX()>=700 && vectorJoueurs_[0]->getMouvement()==true)
        {  
            if(background.getBorderReachedX()!=3)
            {
                vectorJoueurs_[1]->getX() = vectorJoueurs_[1]->getX()-vectorJoueurs_[0]->getSpeed();   
                chateau_[0]->getX() -= vectorJoueurs_[0]->getSpeed();
                background.getX() -= vectorJoueurs_[0]->getSpeed();
                for(robot_ptr monster : wave_.getVectorMonsters()){
                    monster->getX() -= vectorJoueurs_[0]->getSpeed();
                }
            }
            // Test pour savoir si l'élastique est la force élastique est présente.
            if(vectorJoueurs_[0]->getElastique()==true)
            {
                if(background.getBorderReachedX()!=3)
                {
                    vectorJoueurs_[1]->getX() += distance*Kv;
                    background.getX() += distance*Kv;
                    chateau_[0]->getX() += distance*Kv;
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getX() += distance*Kv;
                    }
                }
            }
        }
        else
        {
            
            if(vectorJoueurs_[1]->getX()>=700 && vectorJoueurs_[1]->getMouvement()==true)
            {
                if(background.getBorderReachedX()!=3)
                {
                    vectorJoueurs_[0]->getX() = vectorJoueurs_[0]->getX()-vectorJoueurs_[1]->getSpeed();   
                    chateau_[0]->getX() -= vectorJoueurs_[1]->getSpeed();
                    background.getX() -= vectorJoueurs_[1]->getSpeed();
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getX() -= vectorJoueurs_[1]->getSpeed();
                    }
                }

                // Test pour savoir si l'élastique est la force élastique est présente.
                if(vectorJoueurs_[1]->getElastique()==true)
                {
                    //vectorJoueurs_[0]->getX() += distance*Kv;
                    if(background.getBorderReachedX()!=3)
                    {
                        vectorJoueurs_[0]->getX() += distance*Kv;
                        chateau_[0]->getX() += distance*Kv;
                        background.getX() += distance*Kv;
                        for(robot_ptr monster : wave_.getVectorMonsters()){
                            monster->getX() += distance*Kv;
                        }
                    }
                    //map_sp.setPosition(map_sp.getPosition().x+distance*Kv,map_sp.getPosition().y);
                }

            }
        }
    }
    if(vectorJoueurs_[0]->getX()<=100 || vectorJoueurs_[1]->getX()<=100)
    {
        if(vectorJoueurs_[0]->getX()<=100 && vectorJoueurs_[0]->getMouvement()==true)
        {
            
            if(background.getBorderReachedX()!=9)
            {
                vectorJoueurs_[1]->getX() = vectorJoueurs_[1]->getX()+vectorJoueurs_[0]->getSpeed();
                chateau_[0]->getX() += vectorJoueurs_[0]->getSpeed();
                background.getX() += vectorJoueurs_[0]->getSpeed();
                for(robot_ptr monster : wave_.getVectorMonsters()){
                    monster->getX() += vectorJoueurs_[0]->getSpeed();
                }
            }

            // Test pour savoir si l'élastique est la force élastique est présente.
            if(vectorJoueurs_[0]->getElastique()==true)
            {
                if(background.getBorderReachedX()!=9)
                {
                    vectorJoueurs_[1]->getX() -= distance*Kv;
                    chateau_[0]->getX() -= distance*Kv;
                    background.getX() -= distance*Kv;
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getX() -= distance*Kv;
                    }
                }
            }
        }
        else
        {
            if(vectorJoueurs_[1]->getX()<=100 && vectorJoueurs_[1]->getMouvement()==true)
            {
                if(background.getBorderReachedX()!=9)
                {
                    vectorJoueurs_[0]->getX() = vectorJoueurs_[0]->getX()+vectorJoueurs_[1]->getSpeed();
                    chateau_[0]->getX() += vectorJoueurs_[1]->getSpeed();
                    background.getX() += vectorJoueurs_[1]->getSpeed();
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getX() += vectorJoueurs_[1]->getSpeed();
                    }
                }
                // Test pour savoir si l'élastique est la force élastique est présente.
                if(vectorJoueurs_[1]->getElastique()==true)
                {
                    if(background.getBorderReachedX()!=9)
                    {
                        vectorJoueurs_[0]->getX() -= distance*Kv;
                        chateau_[0]->getX() -= distance*Kv;
                        background.getX() -= distance*Kv;
                        for(robot_ptr monster : wave_.getVectorMonsters()){
                            monster->getX() -= distance*Kv;
                        }
                    }
                    //map_sp.setPosition(map_sp.getPosition().x+distance*Kv,map_sp.getPosition().y);
                }

            }

        }  
    }
    background.getBorderReachedX()=0;
}


void Jeu :: decalerAllAffichablesY(){
    background.isBorderReached();
    if(vectorJoueurs_[0]->getY()>=500 || vectorJoueurs_[1]->getY()>=500)
    {
       
        if(vectorJoueurs_[0]->getY()>=500 && vectorJoueurs_[0]->getMouvement()==true)
        {
            if(background.getBorderReachedY()!=6)
            {
                vectorJoueurs_[1]->getY() = vectorJoueurs_[1]->getY()-vectorJoueurs_[0]->getSpeed();
                chateau_[0]->getY() -= vectorJoueurs_[0]->getSpeed();
                background.getY() -= vectorJoueurs_[0]->getSpeed();
                for(robot_ptr monster : wave_.getVectorMonsters()){
                    monster->getY() -= vectorJoueurs_[0]->getSpeed();
                }
            }
            // Test pour savoir si l'élastique est la force élastique est présente.
            if(vectorJoueurs_[0]->getElastique()==true)
            {
                if(background.getBorderReachedY()!=6)
                {
                    vectorJoueurs_[1]->getY() += distance*Kv;
                    background.getY() += distance*Kv;
                    chateau_[0]->getY() += distance*Kv;
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getY() += distance*Kv;
                    }
                }
            }
        }
        else
        {
            if(vectorJoueurs_[1]->getY()>=500 && vectorJoueurs_[1]->getMouvement()==true)
            {
                if(background.getBorderReachedY()!=6)
                {   
                    vectorJoueurs_[0]->getY() = vectorJoueurs_[0]->getY()-vectorJoueurs_[1]->getSpeed();
                    chateau_[0]->getY() -= vectorJoueurs_[1]->getSpeed();
                    background.getY() -= vectorJoueurs_[1]->getSpeed();
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getY() -= vectorJoueurs_[1]->getSpeed();
                    }
                }
                // Test pour savoir si l'élastique est la force élastique est présente.
                if(vectorJoueurs_[1]->getElastique()==true)
                {
                    if(background.getBorderReachedY()!=6)
                    {
                        vectorJoueurs_[0]->getY() += distance*Kv;
                        chateau_[0]->getY() += distance*Kv;
                        background.getY() += distance*Kv;
                        for(robot_ptr monster : wave_.getVectorMonsters()){
                            monster->getY() += distance*Kv;
                        }
                    }
                }

            }
        }
        
    }
    if(vectorJoueurs_[0]->getY()<=100 || vectorJoueurs_[1]->getY()<=100)
    {
        if(vectorJoueurs_[0]->getY()<=100 && vectorJoueurs_[0]->getMouvement()==true)
        {
            if(background.getBorderReachedY()!=12)
            {
                vectorJoueurs_[1]->getY() = vectorJoueurs_[1]->getY()+vectorJoueurs_[0]->getSpeed();
                chateau_[0]->getY() += vectorJoueurs_[0]->getSpeed();
                background.getY() += vectorJoueurs_[0]->getSpeed();
                for(robot_ptr monster : wave_.getVectorMonsters()){
                    monster->getY() += vectorJoueurs_[0]->getSpeed();
                }
            }
            // Test pour savoir si l'élastique est la force élastique est présente.
            if(vectorJoueurs_[0]->getElastique()==true)
            {
                if(background.getBorderReachedY()!=12)
                {
                    vectorJoueurs_[1]->getY() -= distance*Kv;
                    chateau_[0]->getY() -= distance*Kv;
                    background.getY() -= distance*Kv;
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getY() -= distance*Kv;
                    }
                }
            }
        }
        else
        {
            if(vectorJoueurs_[1]->getY()<=100 && vectorJoueurs_[1]->getMouvement()==true)
            {
                if(background.getBorderReachedY()!=12)
                {
                    vectorJoueurs_[0]->getY() = vectorJoueurs_[0]->getY()+vectorJoueurs_[1]->getSpeed();
                    chateau_[0]->getY() += vectorJoueurs_[1]->getSpeed();
                    background.getY() += vectorJoueurs_[1]->getSpeed();
                    for(robot_ptr monster : wave_.getVectorMonsters()){
                        monster->getY() += vectorJoueurs_[1]->getSpeed();
                    }
                }
                // Test pour savoir si l'élastique est la force élastique est présente.
                if(vectorJoueurs_[1]->getElastique()==true)
                {
                    if(background.getBorderReachedY()!=12)
                    {
                        vectorJoueurs_[0]->getY() -= distance*Kv;
                        chateau_[0]->getY() -= distance*Kv;
                        background.getY() -= distance*Kv;
                        for(robot_ptr monster : wave_.getVectorMonsters()){
                            monster->getY() -= distance*Kv;
                        }
                    }
                }

            }
        }
    }
    background.getBorderReachedY()=0;
}


void Jeu :: afficherAllJoueur(){
    for(guerrier_ptr joueur : vectorJoueurs_){
        joueur->afficher(renderer_.getWindow());
    }
}

void Jeu :: afficherChateau(){
    chateau_[0]->afficher(renderer_.getWindow());
}

void Jeu:: updateLifeAffichables()
{
    std::string result;
    int life;
    for(guerrier_ptr joueur : vectorJoueurs_){
        life = round((joueur->getHP()/20.0)*7);
        result = "life" + std::to_string(life);
        joueur->getLifebar().loadSprite(loadTexture_.getMap()[result]);
    }
    life = floor(chateau_[0]->getHP()/300.0*7);
    result = "life" + std::to_string(life);
    chateau_[0]->getLifebar().loadSprite(loadTexture_.getMap()[result]);
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
    distance = sqrt(pow(vectorJoueurs_[0]->getX()-vectorJoueurs_[1]->getX(),2)+pow(vectorJoueurs_[0]->getY()-vectorJoueurs_[1]->getY(),2));
    vectorJoueurs_[0]->getMouvement() = false;
    vectorJoueurs_[1]->getMouvement() = false;

    //Joueur 1
     //Joueur 1
    vectorJoueurs_[0]->getElastique()=false;
    if(vectorJoueurs_[0]->getIsAttacking()==false)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        //std::cout<<"Valeur Vitesse "<<vectorJoueurs_[0]->getSpeed()<<std::endl;
        vectorJoueurs_[0]->getDirection()=Gauche;
        vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["run_left_j1"]);
        vectorJoueurs_[0]->activateElastique(distance, vectorJoueurs_[1]->getX(), vectorJoueurs_[1]->getY());
        vectorJoueurs_[0]->deplacement(distance);
        vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
        //decalerAllAffichablesX();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            vectorJoueurs_[0]->getDirection()=Droite;
            vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["run_right_j1"]);
            vectorJoueurs_[0]->activateElastique(distance, vectorJoueurs_[1]->getX(), vectorJoueurs_[1]->getY());
            vectorJoueurs_[0]->deplacement(distance);
            vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
            //decalerAllAffichablesX();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            vectorJoueurs_[0]->getDirection()=Haut;
            vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["run_back_j1"]);
            vectorJoueurs_[0]->activateElastique(distance, vectorJoueurs_[1]->getX(), vectorJoueurs_[1]->getY());
            vectorJoueurs_[0]->deplacement(distance);
            vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
            //decalerAllAffichablesY();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            vectorJoueurs_[0]->getDirection()=Bas;
            vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["run_front_j1"]);
            vectorJoueurs_[0]->activateElastique(distance, vectorJoueurs_[1]->getX(), vectorJoueurs_[1]->getY());
            vectorJoueurs_[0]->deplacement(distance);
            vectorJoueurs_[0]->notifyObserverChateau(vectorJoueurs_[0]);
            //decalerAllAffichablesY();
        }

        if(vectorJoueurs_[0]->getMouvement()==false)
        {
            if(vectorJoueurs_[0]->getDirection()==Gauche)
            {
                vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["standby_left_j1"]);
            }
            if(vectorJoueurs_[0]->getDirection()==Droite)
            {
                vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["standby_right_j1"]);
            }
            if(vectorJoueurs_[0]->getDirection()==Haut)
            {
                vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["standby_back_j1"]);
            }
            if(vectorJoueurs_[0]->getDirection()==Bas)
            {
                vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["standby_front_j1"]);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && vectorJoueurs_[0]->getIsAttacking()==false){
            std :: cout << "Utilisation Attaque" << std :: endl;
            vectorJoueurs_[0]->attack();
            vectorJoueurs_[0]->notifyObserverRobot(vectorJoueurs_[0]);
            vectorJoueurs_[0]->loadSprite(loadTexture_.getMap()["attack_j1"]);
        }
    }
   
    //Joueur 2
    if(vectorJoueurs_[1]->getIsAttacking()==false)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        //std::cout<<"Valeur Vitesse "<<vectorJoueurs_[0]->getSpeed()<<std::endl;
        vectorJoueurs_[1]->getDirection()=Gauche;
        vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["run_left_j2"]);
        vectorJoueurs_[1]->activateElastique(distance, vectorJoueurs_[0]->getX(), vectorJoueurs_[0]->getY());
        vectorJoueurs_[1]->deplacement(distance);
        vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);
        //decalerAllAffichablesX();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            vectorJoueurs_[1]->getDirection()=Droite;
            vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["run_right_j2"]);
            vectorJoueurs_[1]->activateElastique(distance, vectorJoueurs_[0]->getX(), vectorJoueurs_[0]->getY());
            vectorJoueurs_[1]->deplacement(distance);
            vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);
            //decalerAllAffichablesX();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
            vectorJoueurs_[1]->getDirection()=Haut;
            vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["run_back_j2"]);
            vectorJoueurs_[1]->activateElastique(distance, vectorJoueurs_[0]->getX(), vectorJoueurs_[0]->getY());
            vectorJoueurs_[1]->deplacement(distance);
            vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);
            //decalerAllAffichablesY();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            vectorJoueurs_[1]->getDirection()=Bas;
            vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["run_front_j2"]);
            vectorJoueurs_[1]->activateElastique(distance, vectorJoueurs_[0]->getX(), vectorJoueurs_[0]->getY());
            vectorJoueurs_[1]->deplacement(distance);
            vectorJoueurs_[1]->notifyObserverChateau(vectorJoueurs_[1]);
            //decalerAllAffichablesY();
        }

        if(vectorJoueurs_[1]->getMouvement()==false)
        {
            if(vectorJoueurs_[1]->getDirection()==Gauche)
            {
                vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["standby_left_j2"]);
            }
            if(vectorJoueurs_[1]->getDirection()==Droite)
            {
                vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["standby_right_j2"]);
            }
            if(vectorJoueurs_[1]->getDirection()==Haut)
            {
                vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["standby_back_j2"]);
            }
            if(vectorJoueurs_[1]->getDirection()==Bas)
            {
                vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["standby_front_j2"]);
            }
        }
        decalerAllAffichablesX();
        decalerAllAffichablesY();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && vectorJoueurs_[1]->getIsAttacking()==false){
            std :: cout << "Utilisation Attaque J2" << std :: endl;
            vectorJoueurs_[1]->attack();
            vectorJoueurs_[1]->notifyObserverRobot(vectorJoueurs_[1]);
            vectorJoueurs_[1]->loadSprite(loadTexture_.getMap()["attack_j2"]);
        }
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
        //Si il reste des bombes
        while(wave_.getVectorBombe().size()!=0){
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
    // Recupère la position des joueurs et de la Map pour l'afficher dans la minimap
    background.getPositionMinimap().setPosition(-background.getBackground().getPosition().x*0.65,-background.getBackground().getPosition().y*0.65);
    background.getCircleJ1().setPosition(background.getPositionMinimap().getPosition().x+vectorJoueurs_[0]->getX()*0.65+25, background.getPositionMinimap().getPosition().y+vectorJoueurs_[0]->getY()*0.65+15);
    background.getCircleJ2().setPosition(background.getPositionMinimap().getPosition().x+vectorJoueurs_[1]->getX()*0.65+25, background.getPositionMinimap().getPosition().y+vectorJoueurs_[1]->getY()*0.65+15);
    // Afficher la MAP
    background.afficher(renderer_.getWindow());
    // Update position Corde
    background.getRope().setPosition(vectorJoueurs_[0]->getX()+60,vectorJoueurs_[0]->getY()+60);
    background.getRope().setSize(sf::Vector2f(distance,3));
    background.getRope().setRotation(atan2(vectorJoueurs_[1]->getY()-vectorJoueurs_[0]->getY(),vectorJoueurs_[1]->getX()-vectorJoueurs_[0]->getX())*180/M_PI);
    //Update des barres de vie des joueurs et du chateau;
    updateLifeAffichables();

    //Affiche les entités
    afficherChateau();
    afficherAllJoueur();
    if(wave_.getOver()){
        renderer_.getWindow().draw(background.getLevelUp());
        renderer_.getWindow().draw(renderer_.getText());
    }else{
        wave_.afficherAllMonster(renderer_.getWindow());
        wave_.afficherAllBombe(renderer_.getWindow());
    }
    //Affiche la mini vue de la map et les HUD
    background.afficherView(renderer_.getWindow(),wave_);
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
                wave_.addBombe(std::make_shared<Bombe>(loadTexture_.getMap()["Bombe"],monster->getX()+15,monster->getY()+15,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE));
                std::cout<<"Bombe posé en : "<<monster->getX()<<" "<<monster->getY()<<std::endl;
                linkBombeObserver(wave_.getVectorBombe().back());
            }
            wave_.removeMonster(i);
            i--;
        }else{
            monster->moveManagement(chateau_[0]->getX(),chateau_[0]->getY());
            monster->notifyObserverChateau(monster);
        }
    }
    //Supprime les bombes mortes
    for(i =wave_.getVectorBombe().size(); i > 0 ;i--){
        if(wave_.getVectorBombe()[i-1]->getDead()){
            delinkBombeObserver(wave_.getVectorBombe()[i-1]);
            wave_.removeBombe(i-1);
        }
    }
    //Fait exploser les bombes
    wave_.explodeAllBombe();
}
