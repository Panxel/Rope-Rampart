#include "unite.hpp"
#include <iostream>

Unite :: Unite(int x,int y,int health, int dmg, int spd) : Entite(x,y){
    std :: cout << "Utilisation Constructeur Unite" << std :: endl;
    hp=health;
    damage=dmg;
    speed=spd;
}