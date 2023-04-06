#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include <SFML/Graphics.hpp>

class Guerrier : public Unite {

    public : 
    Guerrier(int x,int y,int health,int dmg, int spd);
    void afficher(sf::RenderWindow& window);
    void attack() const;

    protected :

};


#endif
