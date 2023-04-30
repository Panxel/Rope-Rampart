#include "guerrier.hpp"
// Deux variables à mettre en attribut de la classe guerrier.
// Variables nécessaire au changement d'images pour les animations;
int compteur =0;
int debut=1;
sf::IntRect rect(debut,0,12,21);

Guerrier::Guerrier(sf::Texture& texture,float x,float y,int health,int atk, int spd) : Unite(texture,x,y,health,atk,spd){
    std :: cout << "Creation classe Guerrier" << std :: endl;
}

void Guerrier :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    // Compteur pour pas que le changement d'image dans l'animation soit pas trop rapide.
    if(compteur==8)
    {
        compteur=0;
        debut=(debut+13)%104;
        // Positionnement du rectangle de découpe dans l'image chargée
        rect.left=debut;
        //std::cout<<"Début "<<debut<<std::endl;
    }
    rect.top=direction;
    sprite_.setTextureRect(rect);
    window.draw(sprite_);
    compteur++;
    //std::cout<<"compteur"<<compteur<<std::endl;
}

void Guerrier :: attack() const {
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
}

