#ifndef BOMBOT_HPP
#define BOMBOT_HPP

#include "robot.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * @class Bombot
 * @brief Classe représentant un robot bombe.
 *
 * La classe Bombot hérite de la classe Robot et ajoute des fonctionnalités spécifiques à un robot bombe.
 */
class Bombot : public Robot {

public:
    /**
     * @brief Constructeur de la classe Bombot.
     * @param texture La texture du robot bombe.
     * @param x La position en x du robot bombe.
     * @param y La position en y du robot bombe.
     * @param health Les points de vie du robot bombe.
     * @param id L'identifiant du robot bombe.
     * @param atk La valeur d'attaque du robot bombe.
     * @param spd La vitesse du robot bombe.
     */
    Bombot(sf::Texture& texture, float x, float y, int health, int id, int atk, int spd);

    /**
     * @brief Met à jour l'état du robot bombe en fonction d'une unité spécifiée.
     * @param unite Le pointeur partagé vers l'unité qui a interagi avec le robot bombe.
     */
    void update(std::shared_ptr<Unite> unite);

    /**
     * @brief Attaque l'unité ennemie.
     */
    void attack();

protected:
    // Aucun attribut protégé spécifique pour le robot bombe.

};

#endif
