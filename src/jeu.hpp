#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "guerrier.hpp"
#include "unite.hpp"
#include <vector>

class Jeu{

    public :  

    static Jeu& get_instance(){
        static Jeu instance;
        return instance;
    }

    void gameInput();
    const std::vector<Unite*>& getJoueurs() const{return joueurs;};

    //void gamePlay();
    void gameLoop();
    void gameDraw() const;

    protected :
    Jeu();

    //Empeche la copie et l'assignation
    Jeu(const Jeu&) = delete;
    Jeu& operator=(const Jeu&) = delete;

    Renderer& renderer = Renderer :: get_instance();
    Guerrier g1 = Guerrier(0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED);
    Guerrier g2 = Guerrier(0.8*WIN_WIDTH,0.8*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED);
    std :: vector<Unite*> joueurs;
    sf :: Event event;
    //std :: vector<Unite*> monsters;
    //std :: array<Unite*,5> decor;

};

#endif