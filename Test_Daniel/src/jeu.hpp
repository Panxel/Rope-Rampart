#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "entite.hpp"
#include "guerrier.hpp"
#include "unite.hpp"
#include <vector>
#include "robot.hpp"
#include "loadTexture.hpp"
#include "chateau.hpp"
#include "wave.hpp"

class Jeu{

    public :  

    static Jeu& get_instance(){
        static Jeu instance;
        return instance;
    }

    void addJoueur(guerrier_ptr joueur){vectorJoueurs_.push_back(joueur);};
    void clearVectorJoueur(){vectorJoueurs_.clear();};
    void addChateau(chateau_ptr chateau){chateau_.push_back(chateau);};
    void clearVectorChateau(){chateau_.clear();};
    void clearAllObserverLink();
    void linkAllRobotObserver();
    void delinkRobotObserver(robot_ptr robot);
    void linkBombeObserver(bombe_ptr bombe);
    void delinkBombeObserver(bombe_ptr bombe);
    void afficherAllJoueur();
    void afficherChateau();

    void gameInput();
    void gamePlay();
    void gameLoop();
    void gameDraw();

    protected :
    Jeu();

    //Empeche la copie et l'assignation
    Jeu(const Jeu&) = delete;
    Jeu& operator=(const Jeu&) = delete;

    Renderer& renderer_ = Renderer :: get_instance();
    LoadTexture& loadTexture_ = LoadTexture :: get_instance();
    Wave& wave_ = Wave :: get_instance();

    std :: vector<guerrier_ptr> vectorJoueurs_;
    std :: vector<chateau_ptr> chateau_;
    sf :: Event event_;

};

#endif