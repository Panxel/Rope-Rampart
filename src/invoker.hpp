#ifndef INVOKER_HPP
#define INVOKER_HPP
#include "commande.hpp"
#include <iostream>

class Invoker{
    public :

    static Invoker& get_instance(){
        static Invoker instance;
        return instance;
    }

    void setCommande(commande_ptr commande);
    void executeCommande();


    protected :

    Invoker();
    
    //Empeche la copie et l'assignation
    Invoker(const Invoker&) = delete;
    Invoker& operator=(const Invoker&) = delete;

    commande_ptr commande_;

};

#endif