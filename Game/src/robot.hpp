#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "unite.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "settings.hpp"

/**
 * @brief Classe Robot, héritant de la classe Unite, pour représenter un robot dans le jeu.
 */
class Robot : public Unite {

public:
    /**
     * @brief Constructeur de la classe Robot.
     * @param texture Texture du robot.
     * @param x Position en X du robot.
     * @param y Position en Y du robot.
     * @param health Points de vie du robot.
     * @param id Identifiant du robot.
     * @param atk Points d'attaque du robot.
     * @param spd Vitesse du robot.
     */
    Robot(sf::Texture& texture, float x, float y, int health, int id, int atk, int spd);

    /**
     * @brief Affiche le robot dans une fenêtre de rendu.
     * @param window Fenêtre de rendu où afficher le robot.
     */
    void afficher(sf::RenderWindow& window);

    /**
     * @brief Gère le déplacement du robot.
     * @param x Déplacement en X.
     * @param y Déplacement en Y.
     */
    void moveManagement(float x, float y);

    /**
     * @brief Met à jour le robot en fonction d'une unité spécifique.
     * @param unite Pointeur vers l'unité avec laquelle mettre à jour le robot.
     */
    virtual void update(unite_ptr unite) = 0;

    /**
     * @brief Obtient l'état indiquant si le robot a été touché ou non.
     * @return Référence constante vers l'état de touche.
     */
    const bool& getIsTouched() const { return isTouched; }

    /**
     * @brief Obtient l'état indiquant si le robot a été touché ou non.
     * @return Référence vers l'état de touche.
     */
    bool& getIsTouched() { return isTouched; }

protected:
    bool isTouched; /**< État indiquant si le robot a été touché ou non.*/

};

typedef std::shared_ptr<Robot> robot_ptr;

#endif
