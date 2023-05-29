#include "HUD.hpp"

// Constructeur de la classe HUD.
HUD :: HUD(float x,float y)
{
    // Set la position de l'HUD
    pos_x_ = x;
    pos_y_ = y;
    // On augmente la taille de l'HUD.
    sprite_.setScale(3,3);
    // On charge la police permettant d'afficher le nom du joueur.
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