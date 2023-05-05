#include "chateau.hpp"
#include "unite.hpp"

Chateau :: Chateau(sf::Texture& texture,float x,float y,int health) : Entite(texture,x,y,health){
    std :: cout << "Utilisation Constructeur Chateau" << std :: endl;
}


void Chateau :: update(std:: shared_ptr<Unite> unite){
    float chateauWidth = GUERRIER_WIDTH;
    float chateauHeight = GUERRIER_HEIGHT;
    float uniteWidth = GUERRIER_WIDTH;
    float uniteHeight = GUERRIER_HEIGHT;

    if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+chateauWidth, unite->getX()+uniteWidth) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+chateauHeight, unite->getY()+uniteHeight)){
        std :: cout << "Collision Chateau" << std :: endl;
        if(unite->getDirection()==Haut){
            unite->getY()=pos_y_+chateauHeight;
        }else if(unite->getDirection()==Droite){
            unite->getX()=pos_x_-uniteWidth;
        }else if(unite->getDirection()==Bas){
            unite->getY()=pos_y_-uniteHeight;
        }else if(unite->getDirection()==Gauche){
            unite->getX()=pos_x_+chateauWidth;
        }
        
    }
}