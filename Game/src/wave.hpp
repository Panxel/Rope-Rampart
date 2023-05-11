#ifndef WAVE_HPP
#define WAVE_HPP
#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include "settings.hpp"
#include "robot.hpp"
#include "loadTexture.hpp"

class Wave{

    public : 

    static Wave& get_instance(){
        static Wave instance;
        return instance;
    }

    const int& getNbMobsSpawned() const {return nb_mobs_spawned_;};
    int& getNbMobsSpawned(){return nb_mobs_spawned_;};
    const int& getNbMobsDied() const {return nb_mobs_died_;};
    int& getNbMobsDied(){return nb_mobs_died_;};
    const bool& getOver() const {return over_;};
    bool& getOver(){return over_;};
    const std::vector<robot_ptr>& getVectorMonsters() const {return vectorMonsters_;};
    std::vector<robot_ptr>& getVectorMonsters(){return vectorMonsters_;};
    void addMonster(robot_ptr monster){vectorMonsters_.push_back(monster);};
    void removeMonster(const int& index){vectorMonsters_.erase(vectorMonsters_.begin()+index);};
    void clearVectorMonster(){vectorMonsters_.clear();};
    void afficherAllMonster(sf::RenderWindow& window);
    void mobSpawnManagement();
    void waveLevelUp();

    protected :

    Wave();
    LoadTexture& loadTexture_ = LoadTexture :: get_instance();
    int level_;
    int nb_mobs_total_;
    int nb_mobs_spawned_;
    int nb_mobs_died_;
    bool over_;
    bool timer_start_;
    std::chrono::time_point<std::chrono::system_clock> start_,end_;
    std::chrono::duration<double> diff_seconds_;
    std :: vector<robot_ptr> vectorMonsters_;
    
    //Empeche la copie et l'assignation
    Wave(const Wave&) = delete;
    Wave& operator=(const Wave&) = delete;
};


#endif
