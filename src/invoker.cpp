#include "invoker.hpp"

Invoker::Invoker(){
    std::cout << "Creation Invoker" << std::endl;
}

void Invoker :: setCommande(commande_ptr commande){
    commande_ = std::move(commande);
}

void Invoker :: executeCommande(){
    commande_->execute();
}