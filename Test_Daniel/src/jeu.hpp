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

class Jeu{

    public :  

    static Jeu& get_instance(){
        static Jeu instance;
        return instance;
    }

    void gameInput();
    const std::vector<unite_ptr>& getJoueurs() const{return joueurs_;};
    void addJoueur(unite_ptr joueur){joueurs_.push_back(joueur);};
    void addMonster(unite_ptr monster){monsters_.push_back(monster);};
    void addEntiteObserver(chateau_ptr chateau){chateau_.push_back(chateau);};
    //void gamePlay();
    void gameLoop();
    void gameDraw() const;

    protected :
    Jeu();

    //Empeche la copie et l'assignation
    Jeu(const Jeu&) = delete;
    Jeu& operator=(const Jeu&) = delete;

    Renderer& renderer_ = Renderer :: get_instance();
    LoadTexture& loadTexture_ = LoadTexture :: get_instance();

    std :: vector<unite_ptr> joueurs_;
    std :: vector<chateau_ptr> chateau_;
    sf :: Event event_;
    std :: vector<unite_ptr> monsters_;

    //std :: array<Unite*,5> decor;

};

#endif