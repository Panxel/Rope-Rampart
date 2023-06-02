#ifndef LIFEBAR_HPP
#define LIFEBAR_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * @class Lifebar
 * @brief Classe représentant une barre de vie.
 *
 * La classe Lifebar est utilisée pour contenir les informations d'une barre de vie et l'afficher
 */
class Lifebar {
public:
    /**
     * @brief Constructeur de la classe Lifebar.
     * @param x La position en x de la barre de vie.
     * @param y La position en y de la barre de vie.
     */
    Lifebar(float x, float y);

    /**
     * @brief Obtient la position en x de la barre de vie.
     * @return Une référence constante à la position en x.
     */
    const float& getX() const { return pos_x_; };

    /**
     * @brief Obtient la position en y de la barre de vie.
     * @return Une référence constante à la position en y.
     */
    const float& getY() const { return pos_y_; };

    /**
     * @brief Obtient la position en x de la barre de vie.
     * @return Une référence à la position en x.
     */
    float& getX() { return pos_x_; };

    /**
     * @brief Obtient la position en y de la barre de vie.
     * @return Une référence à la position en y.
     */
    float& getY() { return pos_y_; };

    /**
     * @brief Charge une texture pour le sprite de la barre de vie.
     * @param texture La texture à charger.
     */
    void loadSprite(sf::Texture& texture);

    /**
     * @brief Affiche la barre de vie dans une fenêtre de rendu SFML.
     * @param window La fenêtre de rendu.
     */
    void afficher(sf::RenderWindow& window);

    /**
     * @brief Obtient le sprite de la barre de vie.
     * @return Une référence au sprite.
     */
    sf::Sprite& getSprite() { return sprite_; }

    /**
     * @brief Obtient le sprite de la barre de vie.
     * @return Une référence constante au sprite.
     */
    const sf::Sprite& getSprite() const { return sprite_; }

protected:
    float pos_x_; /**< La position en x de la barre de vie. */
    float pos_y_; /**< La position en y de la barre de vie. */
    sf::Sprite sprite_; /**< Le sprite de la barre de vie. */
};

#endif
