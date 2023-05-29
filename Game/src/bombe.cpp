#include "bombe.hpp"
#include "guerrier.hpp"
#include <SFML/Audio.hpp>


// COnstructeur Bombe
Bombe :: Bombe(sf::Texture& texture,float x,float y,int health,int id, int atk) : Entite(texture,x,y,health,id){
    attack_=atk;
    start_=std::chrono::system_clock::now();
    // Réglage des regalges de la fênetre de contour pour l'animation du sprite
    rect.top=0;
    rect.left=0;
    rect.height=32;
    rect.width=32;
    compteur=0;
    debut=0;
    // Chargement du son pour l'animation de bombe
    soundBuffer.loadFromFile("../res/Son/Bomb.wav");
    sound_.setBuffer(soundBuffer);
    std :: cout << "Utilisation Constructeur Bombe" << std :: endl;
}

void Bombe :: afficher(sf::RenderWindow& window) {
    // Set la position du sprite
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    // Il faut compteur==9 pour passer à l'image suivante et continuer l'animation
    if(compteur==9)
        {
            // On modifie les paramètres du rectangle pour passer à l'image suivante.
            compteur=0;
            debut=(debut+32)%384;
            rect.left=debut;
            if(debut==256)
                {
                    sound_.play();
                }
        }
    sprite_.setTextureRect(rect);
    compteur++;
    // On dessine le sprite
    window.draw(sprite_);
}

void Bombe :: addObserverGuerrier(guerrier_ptr guerrier){
    vectorObserverGuerrier_.push_back(guerrier);
}
void Bombe :: removeObserverGuerrier(guerrier_ptr guerrier){
    vectorObserverGuerrier_.erase(std::find(vectorObserverGuerrier_.begin(),vectorObserverGuerrier_.end(),guerrier));
}
void Bombe :: notifyObserverGuerrier(bombe_ptr bombe){
    for(guerrier_ptr guerrier : vectorObserverGuerrier_){
        guerrier->update(bombe);
    }
}

void Bombe :: update(unite_ptr unite){
    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+BOMBE_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+BOMBE_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
        std :: cout << "Guerrier damage la Bombe" << std :: endl;
        takeDamage(1);
        std :: cout << "HP Bombe : " << getHP() << std :: endl;
        if(hp_==0){
            dead_=true;
        }
    }
}

double Bombe :: timeDiff(){
    end_=std::chrono::system_clock::now();
    diff_seconds_=end_-start_;
    return diff_seconds_.count();
}