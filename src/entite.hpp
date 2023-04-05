#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>

class Entite{

    public : 
    Entite(int x,int y);
    //virtual void afficher() const = 0;
    void textureLoad(const std::string& path);
    void textureLoad(const std::string& path,const sf::IntRect& r);
    void setTexture(const sf::Texture& texture);
    sf::Texture& getTexture(){ return texture;};
    sf::Sprite& getSprite(){ return sprite;};

    protected :
    int pos_x;
    int pos_y;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif
