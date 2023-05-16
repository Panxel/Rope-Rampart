#ifndef CHATEAU_HPP
#define CHATEAU_HPP
#include "entite.hpp"
#include "settings.hpp"
#include "lifebar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Unite;


class Chateau : public Entite {

    public :
    Chateau(sf::Texture& texture, float x,float y,int health,int id);
    void afficher(sf::RenderWindow& window);
    void update(std :: shared_ptr<Unite> unite);
    const Lifebar& getLifebar() const {return lifebar_;};
    Lifebar& getLifebar(){return lifebar_;};
    
    protected :
    
    Lifebar lifebar_ = Lifebar(0,0);

};


typedef std::shared_ptr<Chateau> chateau_ptr;

#endif