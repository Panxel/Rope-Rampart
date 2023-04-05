#include "guerrier.hpp"
#include <iostream>

Guerrier::Guerrier(int x,int y,int health,int dmg, int spd, int def) : Unite(x,y,health,dmg, spd, def){
    std :: cout << "Creation classe Guerrier" << std :: endl;
}