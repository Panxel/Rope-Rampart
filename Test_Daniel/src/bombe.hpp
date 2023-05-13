#ifndef BOMBE_HPP
#define BOMBE_HPP
#include "entite.hpp"
#include "settings.hpp"
#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <chrono>

class Guerrier;


class Bombe : public Entite {

    public :
    Bombe(sf::Texture& texture, float x,float y,int health,int id,int atk);
    void afficher(sf::RenderWindow& window);
    
        
    const int& getAttack() const {return attack_;};
    int& getAttack(){return attack_;};

    //Sujet
    void addObserverGuerrier(std :: shared_ptr<Guerrier> guerrier);
    void removeObserverGuerrier(std :: shared_ptr<Guerrier> guerrier);
    void notifyObserverGuerrier(std::shared_ptr<Bombe> bombe);
    void update(std :: shared_ptr<Unite> unite);
    double timeDiff();
    
    protected :
    int attack_;
    std:: vector<std :: shared_ptr<Guerrier>> vectorObserverGuerrier_;
    std::chrono::time_point<std::chrono::system_clock> start_,end_;
    std::chrono::duration<double> diff_seconds_;

};


typedef std::shared_ptr<Bombe> bombe_ptr;

#endif