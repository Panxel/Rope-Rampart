#include "chateau.hpp"
#include "unite.hpp"

Chateau :: Chateau(sf::Texture& texture,float x,float y,int health,int id) : Entite(texture,x,y,health,id){
    std :: cout << "Utilisation Constructeur Chateau" << std :: endl;
    // Set position Chateau
    pos_x_=852;
    pos_y_=618;
    lifebar_.getSprite().setScale(2,2);
}

void Chateau :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    // Affiche la barre de vie du chateau
    lifebar_.getX()=pos_x_+3;
    lifebar_.getY()=pos_y_-25;
    window.draw(sprite_);
    lifebar_.afficher(window);
}

void Chateau :: update( unite_ptr unite){
    if(unite->getID()==1){ //Si c'est un joueur, il y a collision avec le chateau        
        if(std::max(pos_x_,unite->getX()+GUERRIER_POS_X) < std::min(pos_x_+CHATEAU_WIDTH, unite->getX()+GUERRIER_POS_X+GUERRIER_REEL_WIDTH) && std::max(pos_y_,unite->getY()+GUERRIER_POS_Y) < std::min(pos_y_+CHATEAU_HEIGHT, unite->getY()+GUERRIER_POS_Y+GUERRIER_REEL_HEIGHT)){
            std :: cout << "Collision Chateau" << std :: endl;
            if(unite->getDirection()==Haut){
                unite->getY()=pos_y_+CHATEAU_HEIGHT-GUERRIER_POS_Y;
            }else if(unite->getDirection()==Droite){
                unite->getX()=pos_x_-GUERRIER_REEL_WIDTH-GUERRIER_POS_X;
            }else if(unite->getDirection()==Bas){
                unite->getY()=pos_y_-GUERRIER_REEL_HEIGHT-GUERRIER_POS_Y;
            }else if(unite->getDirection()==Gauche){
                unite->getX()=pos_x_+CHATEAU_WIDTH-GUERRIER_POS_X;
            }
        }
    }//Mbot
    else if(unite->getID()==2){ //Si c'est un monstre, il y a collision avec le chateau et le robot s'autodétruit et fait des dmg au chateau
        if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+CHATEAU_WIDTH, unite->getX()+MBOT_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+CHATEAU_HEIGHT, unite->getY()+MBOT_HEIGHT)){
            unite->attack();
            std :: cout << "Robot damage le Chateau" << std :: endl;
            takeDamage(unite->getAttack());
            std :: cout << "HP CHATEAU : " << getHP() << std :: endl;
            unite->getDead()=true;
        }
    }//Bombot
    else if(unite->getID()==3){ //Si c'est un monstre, il y a collision avec le chateau et le robot s'autodétruit et fait des dmg au chateau
        if(std::max(pos_x_,unite->getX()) < std::min(pos_x_+CHATEAU_WIDTH, unite->getX()+BOMBOT_WIDTH) && std::max(pos_y_,unite->getY()) < std::min(pos_y_+CHATEAU_HEIGHT, unite->getY()+BOMBOT_HEIGHT)){
            unite->attack();
            std :: cout << "Robot damage le Chateau" << std :: endl;
            takeDamage(unite->getAttack());
            std :: cout << "HP CHATEAU : " << getHP() << std :: endl;
            unite->getDead()=true;
        }
    }
}