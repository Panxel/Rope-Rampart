#ifndef WAVE_HPP
#define WAVE_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>
#include "settings.hpp"
#include "mbot.hpp"
#include "bombot.hpp"
#include "bombe.hpp"
#include "loadTexture.hpp"

/**
 * @brief Classe Wave, représentant une vague d'ennemis dans le jeu.
 */
class Wave {

public:

    /**
     * @brief Obtient l'instance unique de la classe Wave.
     * @return Référence vers l'instance de Wave.
     */
    static Wave& get_instance(){
        static Wave instance;
        return instance;
    }

    /**
     * @brief Obtient le nombre d'ennemis générés dans la vague.
     * @return Référence constante vers le nombre d'ennemis générés.
     */
    const int& getNbMobsSpawned() const{return nb_mobs_spawned_;};

    /**
     * @brief Obtient le nombre d'ennemis tués dans la vague.
     * @return Référence vers le nombre d'ennemis génerés.
     */
    int& getNbMobsSpawned(){return nb_mobs_spawned_;};

    /**
     * @brief Obtient le nombre total d'ennemis dans la vague.
     * @return Référence constante vers le nombre total d'ennemis tués.
     */
    const int& getNbMobsDied() const{return nb_mobs_died_;};

    /**
     * @brief Obtient le nombre total d'ennemis tués dans la vague.
     * @return Référence vers le nombre total d'ennemis tués.
     */
    int& getNbMobsDied(){return nb_mobs_died_;};

    /**
     * @brief Vérifie si la vague est terminée.
     * @return Référence constante vers le statut de fin de la vague.
     */
    const bool& getOver() const{return over_;};

      /**
     * @brief Vérifie si la vague est terminée.
     * @return Référence vers le statut de fin de la vague.
     */
    bool& getOver(){return over_;};

    /**
     * @brief Obtient la liste des monstres présents dans la vague.
     * @return Référence constante vers la liste des monstres.
     */
    const std::vector<robot_ptr>& getVectorMonsters() const {return vectorMonsters_;};

    /**
     * @brief Obtient la liste des monstres présents dans la vague.
     * @return Référence vers la liste des monstres.
     */
    std::vector<robot_ptr>& getVectorMonsters() {return vectorMonsters_;};

    /**
     * @brief Ajoute un monstre à la vague.
     * @param monster Pointeur vers le monstre à ajouter.
     */
    void addMonster(robot_ptr monster){vectorMonsters_.push_back(monster);};

    /**
     * @brief Supprime un monstre de la vague à l'indice spécifié.
     * @param index Indice du monstre à supprimer.
     */
    void removeMonster(const int& index){vectorMonsters_.erase(vectorMonsters_.begin()+index);};

    /**
     * @brief Affiche tous les monstres présents dans la vague sur la fenêtre spécifiée.
     * @param window Référence vers la fenêtre de rendu.
     */
    void afficherAllMonster(sf::RenderWindow& window);

    /**
     * @brief Obtient la liste des bombes présentes dans la vague.
     * @return Référence vers la liste des bombes.
     */
    const std::vector<bombe_ptr>& getVectorBombe() const{return vectorBombe_;};

    /**
     * @brief Obtient la liste des bombes présentes dans la vague.
     * @return Référence vers la liste des bombes.
     */
    std::vector<bombe_ptr>& getVectorBombe(){return vectorBombe_;};

    /**
     * @brief Ajoute une bombe à la vague.
     * @param bombe Pointeur vers la bombe à ajouter.
     */
    void addBombe(bombe_ptr bombe){vectorBombe_.push_back(bombe);};

    /**
     * @brief Supprime une bombe de la vague à l'indice spécifié.
     * @param index Indice de la bombe à supprimer.
     */
    void removeBombe(const int& index){vectorBombe_.erase(vectorBombe_.begin()+index);};

    /**
     * @brief Affiche toutes les bombes présentes dans la vague sur la fenêtre spécifiée.
     * @param window Référence vers la fenêtre de rendu.
     */
    void afficherAllBombe(sf::RenderWindow& window);

    /**
     * @brief Gère la génération des monstres dans la vague.
     */
    void mobSpawnManagement();

    /**
     * @brief Fait progresser la vague au niveau suivant.
     */
    void waveLevelUp();

    /**
     * @brief Fait exploser toutes les bombes présentes dans la vague.
     */
    void explodeAllBombe();

protected:

    Wave();
    LoadTexture& loadTexture_ =  LoadTexture :: get_instance();
    int level_;
    int nb_mobs_total_;
    int nb_mobs_spawned_;
    int nb_mobs_died_;
    bool over_;
    bool timer_start_;
    std::chrono::time_point<std::chrono::system_clock> start_, end_;
    std::chrono::duration<double> diff_seconds_;
    std::vector<robot_ptr> vectorMonsters_;
    std::vector<bombe_ptr> vectorBombe_;
    //Empeche la copie et l'assignation
    Wave(const Wave&) = delete;
    Wave& operator=(const Wave&) = delete;
};

#endif
