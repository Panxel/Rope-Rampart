#include "bombot.hpp"

// Constructeur de la classe Bombot
Bombot::Bombot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Robot(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Bombot" << std :: endl;
    // Chargement du son pour l'animation "frappé par un guerrier"
    soundBuffer.loadFromFile("../res/Son/robot2.wav");
    sound_.setBuffer(soundBuffer);
    sound_.setVolume(100);
    
}

void Bombot :: attack(){
    std :: cout << " Utilisation attack de Bombot" << std :: endl;
}


void Bombot :: update(unite_ptr unite){
    // Si le guerrier frappe le bombot
    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+BOMBOT_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+BOMBOT_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        std :: cout << "Bombot Damaged" << std :: endl;
        isTouched = true;
        // On change les paramètres pour l'animation (effet clignotant quand le robot est frappé)
        compteur = 0;
        debut = 0;
        // On joue le son
        sound_.play();
        // Le bombot perd des points de vie
        takeDamage(unite->getAttack());
        // S'il n'a plus de vie, le booléan dead_ devient vrai.
        if(hp_<=0){
            dead_=true;
        }
        std :: cout << "HP Bombot : " << getHP() << std :: endl;
    }
}