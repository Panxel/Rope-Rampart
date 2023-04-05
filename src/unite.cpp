#include "unite.hpp"
#include <iostream>

Unite :: Unite(int x,int y,int health, int dmg, int spd, int def) : Entite(x,y){
    std :: cout << "Utilisation classe Unite" << std :: endl;
    hp=health;
    damage=dmg;
    speed=spd;
    defense=def;
}