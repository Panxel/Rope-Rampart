#ifndef CHATEAU_HPP
#define CHATEAU_HPP
#include "entite.hpp"
#include "settings.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Unite;


class Chateau : public Entite {

    public :
    Chateau(sf::Texture& texture, float x,float y,int health,int id);

    void update(std :: shared_ptr<Unite> unite);
    
    protected :

};


typedef std::shared_ptr<Chateau> chateau_ptr;

#endif