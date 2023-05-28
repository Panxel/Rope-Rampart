#ifndef MBOT_HPP
#define MBOT_HPP

#include "robot.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * @brief Classe représentant le robot Mbot, dérivée de la classe Robot.
 */
class Mbot : public Robot {

public:
    /**
     * @brief Constructeur de la classe Mbot.
     * @param texture Texture du Mbot.
     * @param x Position initiale en X.
     * @param y Position initiale en Y.
     * @param health Points de vie initiaux.
     * @param id ID du Mbot.
     * @param atk Valeur d'attaque du Mbot.
     * @param spd Valeur de vitesse du Mbot.
     */
    Mbot(sf::Texture& texture, float x, float y, int health, int id, int atk, int spd);

    /**
     * @brief Met à jour le Mbot en fonction de l'unité cible.
     * @param unite Un pointeur vers l'unité cible.
     */
    void update(unite_ptr unite);

    /**
     * @brief Effectue l'attaque du Mbot.
     */
    void attack();

protected:
    // ...
};

#endif
