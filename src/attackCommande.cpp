#include "attackCommande.hpp"

AttackCommande :: AttackCommande(unite_ptr robot, int damage){
    damageDealt_=damage;
    robot_=robot;
}

void AttackCommande :: execute(){
    robot_->takeDamage(damageDealt_);
    std :: cout << "Hp du robot : " << robot_->getHP() << std::endl;
}