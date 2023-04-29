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
#include "moveCommande.hpp"
#include "loadTexture.hpp"
#include "invoker.hpp"

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
    //void gamePlay();
    void gameLoop();
    void gameDraw();

     // Test pour l'affichage du jeu - Mis en Public pour le moment ici.
    sf::Sprite map_sp;
    sf::Texture map;
    sf::View minimap;
    sf::Sprite map_radar;
    sf::RectangleShape rectangle;

    protected :
    Jeu();

    //Empeche la copie et l'assignation
    Jeu(const Jeu&) = delete;
    Jeu& operator=(const Jeu&) = delete;

    Renderer& renderer_ = Renderer :: get_instance();
    LoadTexture& loadTexture_ = LoadTexture :: get_instance();
    Invoker& invoker_ = Invoker :: get_instance();

    std :: vector<unite_ptr> joueurs_;
    sf :: Event event_;
    std :: vector<unite_ptr> monsters_;

    //std :: array<Unite*,5> decor;

};

#endif