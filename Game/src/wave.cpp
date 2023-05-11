#include "wave.hpp"

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
    for(int i=0;i<(nb_mobs_spawned_-nb_mobs_died_);i++){
        vectorMonsters_[i]->afficher(window);
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
        std :: cout << diff_seconds_.count() << std::endl;
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
            x = rand()%WIN_WIDTH;
            y = WIN_INT_HEIGHT+WIN_INT_POSY+rand()%WIN_INT_POSY;
        }
        //Ajoute le mob dans le vecteur
        addMonster(std :: make_shared<Robot>(loadTexture_.getMap()["Robot"],x,y,ROBOT_HP,ROBOT_ID,ROBOT_DAMAGE,ROBOT_SPEED));
    }
}