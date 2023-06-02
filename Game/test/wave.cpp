#include "wave.hpp"

// Constructeur Wave
Wave::Wave(){
    level_=0;
    nb_mobs_total_=1;
    nb_mobs_spawned_=0;
    nb_mobs_died_=0;
    over_=false;
    timer_start_=false;
    std :: cout << "Creation classe Wave" << std :: endl;
}

void Wave :: afficherAllMonster(sf::RenderWindow& window){
    // Gère pour chaque robot, l'animation à charger en fonction de la direction.
    for(int i=0;i<(nb_mobs_spawned_-nb_mobs_died_);i++){
        if(vectorMonsters_[i]->getDirection()==Droite)
        {
            if(vectorMonsters_[i]->getID()==3)
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Bombot_right"]);
            }
            else
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Mbot_right"]);
            }
        }
        if(vectorMonsters_[i]->getDirection()==Gauche)
        {
            if(vectorMonsters_[i]->getID()==3)
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Bombot_left"]);
            }
            else
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Mbot_left"]);
            }
        }
        if(vectorMonsters_[i]->getDirection()==Haut)
        {
            if(vectorMonsters_[i]->getID()==3)
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Bombot_back"]);
            }
            else
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Mbot_back"]); 
            }
            
        }
        if(vectorMonsters_[i]->getDirection()==Bas)
        {
            if(vectorMonsters_[i]->getID()==3)
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Bombot_front"]);
            }
            else
            {
                vectorMonsters_[i]->loadSprite(loadTexture_.getMap()["Mbot_front"]);
            }
            
        }
        vectorMonsters_[i]->afficher(window);
    }
}

void Wave :: afficherAllBombe(sf::RenderWindow& window){
    for(bombe_ptr bombe : vectorBombe_){
        bombe->afficher(window);
    }
}

void Wave :: mobSpawnManagement(){
    if(nb_mobs_spawned_<nb_mobs_total_){
        if(!timer_start_){
            timer_start_=true;
            start_=std::chrono::system_clock::now();
        }
        end_=std::chrono::system_clock::now();
        diff_seconds_=end_-start_;
        if(diff_seconds_.count()>=3){
            nb_mobs_spawned_++;
            timer_start_=false;
        }
    }
}

void Wave :: waveLevelUp(){
    level_++;
    nb_mobs_total_=round(nb_mobs_total_*1.5);
    nb_mobs_spawned_=0;
    nb_mobs_died_=0;
    for(int i=0;i<nb_mobs_total_;i++){
        float x;
        float y;
        int cote = rand()%4; //Savoir dans quel coté de la map le mob spawn (Gauche, Haut, Droite, Bas)
        if(cote == 0){ //Cote Gauche
            x = rand()%WIN_INT_POSX;
            y = rand()%WIN_HEIGHT;
        }else if(cote == 1){ //Cote Haut
            x = rand()%WIN_WIDTH;
            y = rand()%WIN_INT_POSY;
        }else if(cote == 2){ //Cote Droite
            x = WIN_INT_WIDTH+WIN_INT_POSX+rand()%WIN_INT_POSX;
            y = rand()%WIN_HEIGHT;
        }else{ //Cote Bas
            x = rand()%WIN_WIDTH+50;
            y = WIN_INT_HEIGHT+WIN_INT_POSY+rand()%WIN_INT_POSY;
        }
        x -= 200;
        y -= 200;
        //Ajoute un monstre et la difficulté augmente
        if(rand()/static_cast<float>(RAND_MAX)>(log(level_)/5+0.002*level_)){
            addMonster(std :: make_shared<Mbot>(loadTexture_.getMap()["Mbot_front"],x,y,MBOT_HP,MBOT_ID,MBOT_DAMAGE,MBOT_SPEED));
        }else{
            addMonster(std :: make_shared<Bombot>(loadTexture_.getMap()["Bombot_front"],x,y,BOMBOT_HP,BOMBOT_ID,BOMBOT_DAMAGE,BOMBOT_SPEED));
        }   
    }
}

void Wave :: explodeAllBombe(){
    for(bombe_ptr bombe : vectorBombe_){
        std::cout << bombe->timeDiff() << std::endl;
        if(bombe->timeDiff()>=2){
            bombe->getDead()=true;
            bombe->notifyObserverGuerrier(bombe);
        }
    }
}