#include "entite.hpp"
#include <string>
#include <SFML/Graphics.hpp>

Entite::Entite(int x,int y){
    pos_x=x;
    pos_y=y;
}

void Entite :: textureLoad(std::string path){
    if(!texture.loadFromFile(path)){
        std::cout << "Error texture" << std::endl;
    }
} 

void Entite :: textureLoad(std::string path,sf::IntRect(txt_x,txt_y,txt_width,txt_height)){
    if(!texture.loadFromFile(path,sf::IntRect(txt_x,txt_y,txt_width,txt_height))){
        std::cout << "Error texture" << std::endl;
    }
} 

void Entite :: setTexture(sf::Texture textur){
    sprite.setTexture(textur);
}