#include "moveCommande.hpp"

MoveCommande :: MoveCommande(unite_ptr unite,float x,float y){
    unite_=unite;
    unite_->getX()+=x;
    unite_->getY()+=y;
}

void MoveCommande :: execute(){
    std :: cout << "Move" << std::endl;
}