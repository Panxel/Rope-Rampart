#include "entite.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

Entite::Entite(int x,int y){
    std :: cout << "Utilisation Constructeur Entite" << std :: endl;
    pos_x=x;
    pos_y=y;
}

void Entite :: textureLoad(const std::string& path){
    if(!texture.loadFromFile(path)){
        std::cout << "Error texture" << std::endl;
    }
} 

void Entite :: textureLoad(const std::string& path,const sf::IntRect& r ){
    if(!texture.loadFromFile(path,sf::IntRect (r.left,r.top,r.width,r.height))){
        std::cout << "Error texture" << std::endl;
    }
} 

void Entite :: setTexture(const sf::Texture& textur){
    sprite.setTexture(textur);
}