#include "attackCommande.hpp"

AttackCommande :: AttackCommande(unite_ptr unite, int damage){
    damageDealt_=damage;
    unite_=unite;
}

void AttackCommande :: execute(){
    unite_->takeDamage(damageDealt_);
    std :: cout << "Hp de l'unité : " << unite_->getHP() << std::endl;
}