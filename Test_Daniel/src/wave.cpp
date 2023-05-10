#include "wave.hpp"

Wave::Wave(){
    level_=0;
    nb_mobs_total_=1;
    nb_mobs_spawned_=0;
    nb_mobs_died_=0;
    over_=false;
    std :: cout << "Creation classe Wave" << std :: endl;
}

void Wave :: afficherAllMonster(sf::RenderWindow& window){
    for(int i=0;i<(nb_mobs_spawned_-nb_mobs_died_);i++){
        vectorMonsters_[i]->afficher(window);
    }
}

