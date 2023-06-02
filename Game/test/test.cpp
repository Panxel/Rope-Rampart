#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "unite.hpp"
#include "renderer.hpp"
#include "settings.hpp"
#include "entite.hpp"
#include "guerrier.hpp"
#include <vector>
#include "robot.hpp"
#include "loadTexture.hpp"
#include "chateau.hpp"
#include "wave.hpp"
#include "map.hpp"

LoadTexture& loadTexture_ = LoadTexture :: get_instance(); // Référence à l'instance de LoadTexture pour charger les textures
Wave& wave_ = Wave :: get_instance(); // Référence à l'instance de Wave pour gérer les vagues d'ennemis
std::vector<chateau_ptr> chateau_; // Vecteur contenant les pointeurs vers les châteaux

//Comme on a plusieurs fois la meme fonction de collision avec quelques details près (pour avoir une meilleur hitbox par ex), on ne fera le cas qu'une fois

//BOMBE
TEST_CASE("takeDamage test", "[bombe]") {
    SECTION("True case"){
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        b1.takeDamage(1);
        REQUIRE(b1.getHP()==1);
    }
    SECTION("False case"){
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        b1.takeDamage(1);
        REQUIRE_FALSE(b1.getHP()==BOMBE_HP);
    }
}

TEST_CASE("update test", "[bombe]") {
    SECTION("Collision"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        b1.update(vectorJoueurs_[0]);
        REQUIRE(b1.getHP()==1);
    }
    SECTION("No collision"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],100,100,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        b1.update(vectorJoueurs_[0]);
        REQUIRE(b1.getHP()==BOMBE_HP);
    }
    SECTION("Limit collision"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300-GUERRIER_WIDTH+1,300-GUERRIER_HEIGHT+1,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        b1.update(vectorJoueurs_[0]);
        REQUIRE_FALSE(b1.getHP()==BOMBE_HP);
    }
    SECTION("Edge no collision"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300-GUERRIER_WIDTH,300-GUERRIER_HEIGHT,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        b1.update(vectorJoueurs_[0]);
        REQUIRE(b1.getHP()==BOMBE_HP);
    }   
}

TEST_CASE("timeDiff test", "[bombe]") {
    SECTION("True case"){
        Bombe b1(loadTexture_.getMap()["Bombe"],300,300,BOMBE_HP,BOMBE_ID,BOMBE_DAMAGE);
        std::cout << b1.timeDiff() << std:: endl;
        REQUIRE(b1.timeDiff()>0);
    }
}

//Guerrier

TEST_CASE("activateElastique test", "[guerrier]"){
    SECTION("Gauche No elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Gauche;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==false);
    }
    SECTION("Gauche Elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Gauche;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],400,400,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==true);
    }
    SECTION("Droite No elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Droite;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==false);
    }
    SECTION("Droite Elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Droite;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],400,400,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==true);
    }
    SECTION("Bas No elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Bas;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==false);
    }
    SECTION("Bas Elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Bas;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],400,400,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==true);
    }SECTION("Haut No elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Haut;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==false);
    }
    SECTION("Haut Elastique"){
        std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],300,300,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->getDirection()=Haut;
        vectorJoueurs_.push_back(std :: make_shared<Guerrier>(loadTexture_.getMap()["run_front_j1"],400,400,GUERRIER_HP,JOUEUR_ID,GUERRIER_DAMAGE,GUERRIER_SPEED));
        vectorJoueurs_[0]->activateElastique(10,vectorJoueurs_[1]->getX(),vectorJoueurs_[1]->getY());
        REQUIRE(vectorJoueurs_[0]->getElastique()==true);
    }
}

