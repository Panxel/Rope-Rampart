#include "unite.hpp"

Unite :: Unite(int x,int y,int health, int dmg, int spd, int def) : Entite(x,y){
    hp=health;
    damage=dmg;
    speed=spd;
    defense=def;
}