#ifndef HUD_HPP
#define HUD_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class HUD{
    public :
    HUD(float x,float y);
    const float& getX() const {return pos_x_;};
    const float& getY() const {return pos_y_;};
    float& getX(){return pos_x_;};
    float& getY(){return pos_y_;};
    void loadSprite(sf::Texture& texture);
    void afficher(sf::RenderWindow& window);
    sf::Sprite& getSprite(){return sprite_;};
    const sf::Sprite& getSprite() const {return sprite_;};
    
    protected :
    float pos_x_;
    float pos_y_;
    sf::Sprite sprite_;
    
};

#endif