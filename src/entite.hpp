#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>

class Entite{

    public : 
    Entite(int x,int y);
    virtual void afficher() const = 0;
    void textureLoad(std::string path);
    void textureLoad(std::string path,sf::IntRect(int txt_x,int txt_y,int txt_width,int txt_height));
    void setTexture(sf::Texture texture);
    sf::Texture getTexture(){ return texture;};
    sf::Sprite getSprite(){ return sprite;};

    protected :
    int pos_x;
    int pos_y;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif
