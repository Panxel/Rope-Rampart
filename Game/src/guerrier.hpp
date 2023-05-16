#ifndef GUERRIER_HPP
#define GUERRIER_HPP
#include "unite.hpp"
#include "robot.hpp"
#include "bombe.hpp"
#include "lifebar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Guerrier : public Unite {

    public : 
    Guerrier(sf::Texture& texture,float x,float y,int health,int id,int atk, int spd);
    void attack();
    void afficher(sf::RenderWindow& window);
    //Sujet
    void addObserverRobot(robot_ptr robot);
    void removeObserverRobot(robot_ptr robot);
    void notifyObserverRobot(unite_ptr unite);
    void addObserverBombe(bombe_ptr bombe);
    void removeObserverBombe(bombe_ptr bombe);
    void notifyObserverBombe(unite_ptr unite);
    void update(bombe_ptr bombe);
    void activateElastique(float distance, float x, float y);
    bool& getMouvement() {return mouvement_;};
    const bool& getMouvement() const{return mouvement_;};
    void deplacement(float distance);
    bool& getElastique(){return elastique;};
    const bool& getElastique() const{return elastique;};
    const Lifebar& getLifebar() const {return lifebar_;};
    Lifebar& getLifebar(){return lifebar_;};
    bool& getIsAttacking() {return isAttacking;};
    const bool& getIsAttacking() const{return isAttacking;};
    int& getCompteur() {return compteur;};
    const int& getCompeteur() const{return compteur;};
    int& getDebut() {return debut;};
    const int& getDebut() const{return debut;};

    protected :
    std:: vector<robot_ptr> vectorObserverRobot_;
    std:: vector<bombe_ptr> vectorObserverBombe_;
    // Attribut qui active l'effet elastique 
    bool elastique;
    // boolean qui permet de savoir si le joueur est en train d'attaquer.
    bool isAttacking;
    // Boolean pour savoir si le personnage est en mouvement afin de gerer les animations du jeu.
    bool mouvement_;
      // Attributs nécessaire à l'affichage et au changement de sprite pour le graphisme
    int compteur;
    int debut;
    // Rectangle permettant de selectionner la bonne image dans la grille d'image 
    sf::IntRect rect;
    // Barre de vie
    Lifebar lifebar_ = Lifebar(0,0);

};

typedef std::shared_ptr<Guerrier> guerrier_ptr;


#endif
