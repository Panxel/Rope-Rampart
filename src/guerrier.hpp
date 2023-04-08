#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include <iostream>
#include "commande.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <math.h>

typedef std::unique_ptr<Commande> commande_ptr;

class Guerrier : public Unite {

    public : 
    Guerrier(float x,float y,int health,int atk, int spd);
    void afficher(sf::RenderWindow& window);
    void attack() const;
    void setCommande(commande_ptr commande);
    void executeCommande();

    protected :
    commande_ptr commande_;
};


#endif
