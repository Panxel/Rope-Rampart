#include "unite.hpp"

Unite :: Unite(sf::Texture& texture,float x,float y,int health, int atk, int spd) : Entite(texture,x,y,health){
    std :: cout << "Utilisation Constructeur Unite" << std :: endl;
    attack_=atk;
    speed_=spd;
}

void Unite :: addObserver(chateau_ptr observer){
    vectorObserver_.push_back(observer);
}
void Unite :: removeObserver(chateau_ptr observer){
    vectorObserver_.erase(std::find(vectorObserver_.begin(),vectorObserver_.end(),observer));
}
void Unite :: notifyObserver(unite_ptr unite){
    for(chateau_ptr observer : vectorObserver_){
        observer->update(unite);
    }
}

void Unite :: takeDamage(int damage){
    hp_-=damage;
}
