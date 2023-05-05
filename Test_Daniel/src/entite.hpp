#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Entite{

    public : 
    Entite(sf::Texture& texture,float x,float y,int health);
    void afficher(sf::RenderWindow& window);
    const sf::Sprite& getSprite() const { return sprite_;};
    void loadSprite(sf::Texture& texture);
    const float& getX() const {return pos_x_;};
    const float& getY() const {return pos_y_;};
    float& getX(){return pos_x_;};
    float& getY(){return pos_y_;};
    const int& getHP() const {return hp_;};
    int& getHP(){return hp_;};


    protected :
    int hp_;
    float pos_x_;
    float pos_y_;
    sf::Sprite sprite_;
};


#endif
