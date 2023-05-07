#include "chateau.hpp"
#include "unite.hpp"

Chateau :: Chateau(sf::Texture& texture,float x,float y,int health,int id) : Entite(texture,x,y,health,id){
    std :: cout << "Utilisation Constructeur Chateau" << std :: endl;
}


void Chateau :: update( unite_ptr unite){
    if(unite->getID()==1){
        if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+CHATEAU_WIDTH, unite->getX()+GUERRIER_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+CHATEAU_HEIGHT, unite->getY()+GUERRIER_HEIGHT)){
            std :: cout << "Collision Chateau" << std :: endl;
            if(unite->getDirection()==Haut){
                unite->getY()=pos_y_+CHATEAU_HEIGHT;
            }else if(unite->getDirection()==Droite){
                unite->getX()=pos_x_-GUERRIER_WIDTH;
            }else if(unite->getDirection()==Bas){
                unite->getY()=pos_y_-GUERRIER_HEIGHT;
            }else if(unite->getDirection()==Gauche){
                unite->getX()=pos_x_+CHATEAU_WIDTH;
            }
        }
    }else if(unite->getID()==2){
        if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+CHATEAU_WIDTH, unite->getX()+ROBOT_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+CHATEAU_HEIGHT, unite->getY()+ROBOT_HEIGHT)){
            std :: cout << "Robot damage le Chateau" << std :: endl;
            takeDamage(unite->getAttack());
            std :: cout << "HP CHATEAU : " << getHP() << std :: endl;
            unite->getX()=ROBOT_INITX;
            unite->getY()=ROBOT_INITY;

        }
    }
}