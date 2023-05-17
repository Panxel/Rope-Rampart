#include "HUD.hpp"

HUD :: HUD(float x,float y)
{
    pos_x_ = x;
    pos_y_ = y;
    sprite_.setScale(3,3);
    loadFont();
    nom_.setFont(font_);
}

void HUD::loadSprite(sf::Texture& texture){
    sprite_.setTexture(texture);
}

void HUD :: afficher(sf::RenderWindow& window){
    window.draw(nom_);
    window.draw(sprite_);
}

void HUD :: loadFont(){
    if(!font_.loadFromFile("../res/Font.ttf")){
        std::cout << "Error Chargement Font" << std::endl;
    }
}

void HUD :: setText(const sf::String str,int size,sf::Color color){
    nom_.setString(str);
    nom_.setCharacterSize(size);
    nom_.setFillColor(color);
    //nom_.setStyle(sf::Text :: Bold);
}