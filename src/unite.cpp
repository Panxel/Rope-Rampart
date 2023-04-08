#include "unite.hpp"

Unite :: Unite(float x,float y,int health, int dmg, int spd) : Entite(x,y){
    std :: cout << "Utilisation Constructeur Unite" << std :: endl;
    hp_=health;
    damage_=dmg;
    speed_=spd;
}
