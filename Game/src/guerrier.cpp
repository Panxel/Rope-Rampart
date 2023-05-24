#include "guerrier.hpp"

Guerrier::Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd) : Unite(texture,x,y,health,id,atk,spd){
    std :: cout << "Creation classe Guerrier" << std :: endl;
    rect.top=0;
    rect.left=0;
    rect.height=60;
    rect.width=60;
    mouvement_= false;
    isAttacking = false;
    compteur = 0;
    debut = 0;
    sprite_.setScale(2,2);
}

void Guerrier :: attack(){
    std :: cout << " Utilisation attack de Guerrier" << std :: endl;
    isAttacking = true;
    debut = 0;
    compteur = 0;
}

void Guerrier :: afficher(sf::RenderWindow& window) {
    sprite_.setPosition(round(pos_x_),round(pos_y_));
    if(isAttacking==true && debut==420 && compteur==3)
    {
        isAttacking=false;
    }
    if(compteur==3)
        {
            compteur=0;
            debut=(debut+60)%480;
            // Positionnement du rectangle de découpe dans l'image chargée
            rect.left=debut;
        }
    sprite_.setTextureRect(rect);
    compteur++;
    // Affiche la barre de vie
    lifebar_.afficher(window);
    window.draw(sprite_);
}

void Guerrier :: addObserverRobot(robot_ptr robot){
    vectorObserverRobot_.push_back(robot);
}
void Guerrier :: removeObserverRobot(robot_ptr robot){
    vectorObserverRobot_.erase(std::find(vectorObserverRobot_.begin(),vectorObserverRobot_.end(),robot));
}
void Guerrier :: notifyObserverRobot(unite_ptr unite){
    for(robot_ptr robot : vectorObserverRobot_){
        robot->update(unite);
    }
}

void Guerrier :: addObserverBombe(bombe_ptr bombe){
    vectorObserverBombe_.push_back(bombe);
}
void Guerrier :: removeObserverBombe(bombe_ptr bombe){
    vectorObserverBombe_.erase(std::find(vectorObserverBombe_.begin(),vectorObserverBombe_.end(),bombe));
}
void Guerrier :: notifyObserverBombe(unite_ptr unite){
    for(bombe_ptr bombe : vectorObserverBombe_){
        bombe->update(unite);
    }
}

void Guerrier :: update(bombe_ptr bombe){
    if(std::max(pos_x_+GUERRIER_POS_X,bombe->getX()) < std::min(pos_x_+GUERRIER_POS_X+GUERRIER_REEL_WIDTH, bombe->getX()+BOMBE_WIDTH) && std::max(pos_y_+GUERRIER_POS_Y,bombe->getY()) < std::min(pos_y_+GUERRIER_POS_Y+GUERRIER_REEL_HEIGHT, bombe->getY()+BOMBE_HEIGHT)){
        std :: cout << "Bombe damage le Guerrier" << std :: endl;
        takeDamage(bombe->getAttack());
        std :: cout << "HP Guerrier : " << getHP() << std :: endl;
        bombe->getDead()=true;
    }
}

void Guerrier ::activateElastique(float distance, float autre_joueur_x, float autre_joueur_y)
{
    switch(direction_)
    {
        case Gauche:
            {
                if(sqrt(pow(pos_x_-speed_-autre_joueur_x,2)+pow(pos_y_-autre_joueur_y,2))<distance)
                {
                    elastique=false;  
                }
                else
                {
                    elastique = true;
                }
                break;
            }
        case Droite:
            {
                if(sqrt(pow(pos_x_+speed_-autre_joueur_x,2)+pow(pos_y_-autre_joueur_y,2))<distance)
                {
                    elastique=false;  
                }
                else
                {
                    elastique = true;
                }
                break;
            }
        case Haut:
            {
                if(sqrt(pow(pos_x_-autre_joueur_x,2)+pow(pos_y_-speed_-autre_joueur_y,2))<distance)
                {
                    elastique=false;  
                }
                else
                {
                    elastique = true;
                }
                break;
            }
        case Bas:
            {
                if(sqrt(pow(pos_x_-autre_joueur_x,2)+pow(pos_y_+speed_-autre_joueur_y,2))<distance)
                {
                    elastique=false;  
                }
                else
                {
                    elastique = true;
                }
            }
            break;
    }
}

void Guerrier::deplacement(float distance)
{
    mouvement_= true;
    switch(direction_)
    {
        case Gauche:
        {
            if(pos_x_>100)
            {
                pos_x_=pos_x_-speed_;
                if(elastique==true)
                {
                    pos_x_+=distance*Kv;
                }
            }
            break;
        }
        case Droite:
        {
            if(pos_x_<700)
            {
                pos_x_=pos_x_+speed_;
                if(elastique==true)
                {
                    pos_x_-=distance*Kv;
                }
            }
            break;
        }
        case Haut:
        {
            if(pos_y_>100)
            {
                pos_y_=pos_y_-speed_;
                if(elastique==true)
                {
                    pos_y_+=distance*Kv;
                }
            }
            break;
        }
        case Bas:
        {
            if(pos_y_<500)
            {
                pos_y_=pos_y_+speed_;
                if(elastique==true)
                {
                    pos_y_-=distance*Kv;
                }
            }
            break;
        }
    }
}