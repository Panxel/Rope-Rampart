#include "unite.hpp"


// Constructeur Unité
Unite :: Unite(sf::Texture& texture,float x,float y,int health,int id, int atk, int spd) : Entite(texture,x,y,health,id){
    std :: cout << "Utilisation Constructeur Unite" << std :: endl;
    attack_=atk;
    speed_=spd;
}

void Unite :: addObserverChateau(chateau_ptr chateau){
    vectorObserverChateau_.push_back(chateau);
}
void Unite :: removeObserverChateau(chateau_ptr chateau){
    vectorObserverChateau_.erase(std::find(vectorObserverChateau_.begin(),vectorObserverChateau_.end(),chateau));
}
void Unite :: notifyObserverChateau(unite_ptr unite){
    for(chateau_ptr chateau : vectorObserverChateau_){
        chateau->update(unite);
    }
}
