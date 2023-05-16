#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.hpp"

class Robot : public Unite {

    public :
    Robot(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd);
    void afficher(sf::RenderWindow& window);
    void moveManagement(float x, float y);
    virtual void update(unite_ptr unite) = 0;

    protected :
     // Attributs nécessaire à l'affichage et au changement de sprite pour le graphisme
    int compteur;
    int debut;
    // Rectangle permettant de selectionner la bonne image dans la grille d'image 
    sf::IntRect rect;

};

typedef std::shared_ptr<Robot> robot_ptr;

#endif