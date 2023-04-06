#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>

class Entite{

    public : 
    Entite(int x,int y);
    virtual void afficher(sf::RenderWindow& window) = 0;
    const sf::Sprite& getSprite() const { return sprite;};
    const int& getX() const {return pos_x;};
    const int& getY() const {return pos_y;};


    protected :
    int pos_x;
    int pos_y;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif
