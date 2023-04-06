#include "entite.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

Entite::Entite(int x,int y){
    std :: cout << "Utilisation Constructeur Entite" << std :: endl;
    pos_x=x;
    pos_y=y;
}