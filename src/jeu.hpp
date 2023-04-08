#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "guerrier.hpp"
#include "unite.hpp"
#include <vector>
#include "robot.hpp"
#include "attackCommande.hpp"

class Jeu{

    public :  

    static Jeu& get_instance(){
        static Jeu instance;
        return instance;
    }

    void gameInput();
    const std::vector<Unite*>& getJoueurs() const{return joueurs_;};

    //void gamePlay();
    void gameLoop();
    void gameDraw() const;

    protected :
    Jeu();

    //Empeche la copie et l'assignation
    Jeu(const Jeu&) = delete;
    Jeu& operator=(const Jeu&) = delete;

    Renderer& renderer_ = Renderer :: get_instance();
    Robot r1_ = Robot(0.2*WIN_WIDTH,0.2*WIN_HEIGHT,Robot_HP,Robot_DAMAGE,Robot_SPEED);
    Guerrier g1_ = Guerrier(0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED);
    Guerrier g2_ = Guerrier(0.8*WIN_WIDTH,0.8*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED);
    std :: vector<Unite*> joueurs_;
    sf :: Event event_;
    std :: vector<Unite*> monsters_;

    //std :: array<Unite*,5> decor;

};

#endif