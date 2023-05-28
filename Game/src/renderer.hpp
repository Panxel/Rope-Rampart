#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <iostream>
#include "settings.hpp"
#include <SFML/Graphics.hpp>

/**
 * @brief Classe Renderer pour gérer l'affichage et la fenêtre de rendu.
 */
class Renderer {

public:
    /**
     * @brief Obtient l'instance unique du Renderer (Singleton).
     * @return Référence vers l'instance du Renderer.
     */
    static Renderer& get_instance()
    {
        static Renderer instance;
        return instance;
    }
    /**
     * @brief Définit le texte à afficher.
     * @param str Chaîne de caractères du texte.
     * @param size Taille de la police.
     * @param color Couleur du texte.
     */
    void setText(const sf::String str, int size, sf::Color color);

    /**
     * @brief Charge la police de caractères.
     */
    void loadFont();

    /**
     * @brief Obtient la fenêtre de rendu.
     * @return Référence vers la fenêtre de rendu.
     */
    sf::RenderWindow& getWindow(){return window_;};

    /**
     * @brief Obtient le texte à afficher.
     * @return Référence vers l'objet de texte.
     */
    sf::Text& getText(){return txt_;};

protected:
    /**
     * @brief Constructeur du Renderer.
     */
    Renderer();

    // Empeche la copie et l'assignation
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    sf::RenderWindow window_; /**< Fenêtre de rendu.*/
    sf::Font font_;           /**< Police de caractères.*/
    sf::Text txt_;            /**< Objet de texte pour l'affichage.*/

};

#endif
