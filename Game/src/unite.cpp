#include "unite.hpp"

Unite :: Unite(sf::Texture& texture,float x,float y,int health,int id, int atk, int spd) : Entite(texture,x,y,health,id){
    std :: cout << "Utilisation Constructeur Unite" << std :: endl;
    attack_=atk;
    speed_=spd;
}

void Unite :: addObserverChateau(chateau_ptr observer){
    vectorObserverChateau_.push_back(observer);
}
void Unite :: removeObserverChateau(chateau_ptr observer){
    vectorObserverChateau_.erase(std::find(vectorObserverChateau_.begin(),vectorObserverChateau_.end(),observer));
}
void Unite :: notifyObserverChateau(unite_ptr unite){
    for(chateau_ptr observer : vectorObserverChateau_){
        observer->update(unite);
    }
}
