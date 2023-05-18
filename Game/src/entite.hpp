#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Entite{

    public : 
    Entite(sf::Texture& texture,float x,float y,int health,int id);
    virtual void afficher(sf::RenderWindow& window) = 0;
    const sf::Sprite& getSprite() const { return sprite_;};
    void loadSprite(sf::Texture& texture);
    const float& getX() const {return pos_x_;};
    const float& getY() const {return pos_y_;};
    float& getX(){return pos_x_;};
    float& getY(){return pos_y_;};
    const int& getHP() const {return hp_;};
    int& getHP(){return hp_;};
    const int& getID() const {return id_;};
    int& getID(){return id_;};
    const bool& getDead() const {return dead_;};
    bool& getDead(){return dead_;};
    void takeDamage(const int& damage);


    protected :
    int id_;
    int hp_;
    bool dead_;
    float pos_x_;
    float pos_y_;
    sf::Sprite sprite_;
    // Rectangle permettant de selectionner la bonne image dans la grille d'image 
    sf::IntRect rect;
     // Attributs nécessaire à l'affichage et au changement de sprite pour le graphisme
    int compteur;
    int debut;
};


#endif
