#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>

class Entite{

    public : 
    Entite(float x,float y);
    virtual void afficher(sf::RenderWindow& window) = 0;
    const sf::Sprite& getSprite() const { return sprite;};
    const float& getX() const {return pos_x;};
    const float& getY() const {return pos_y;};
    float& getX(){return pos_x;};
    float& getY(){return pos_y;};


    protected :
    float pos_x;
    float pos_y;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif
