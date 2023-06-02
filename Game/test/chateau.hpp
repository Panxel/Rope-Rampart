#ifndef CHATEAU_HPP
#define CHATEAU_HPP

#include "entite.hpp"
#include "settings.hpp"
#include "lifebar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

class Unite;

/**
 * @class Chateau
 * @brief Classe représentant un château.
 *
 * La classe Chateau hérite de la classe Entite et ajoute des fonctionnalités spécifiques à un château.
 */
class Chateau : public Entite {

public:
    /**
     * @brief Constructeur de la classe Chateau.
     * @param texture La texture du château.
     * @param x La position en x du château.
     * @param y La position en y du château.
     * @param health Les points de vie du château.
     * @param id L'identifiant du château.
     */
    Chateau(sf::Texture& texture, float x, float y, int health, int id);

    /**
     * @brief Affiche le château sur une fenêtre spécifiée.
     * @param window La fenêtre sur laquelle afficher le château.
     */
    void afficher(sf::RenderWindow& window);

    /**
     * @brief Met à jour l'état du château en fonction d'une unité spécifiée.
     * @param unite Le pointeur partagé vers l'unité qui a interagi avec le château.
     */
    void update(std::shared_ptr<Unite> unite);

    /**
     * @brief Obtient la barre de vie du château.
     * @return Une référence constante vers l'objet Lifebar représentant la barre de vie du château.
     */
    const Lifebar& getLifebar() const { return lifebar_; }

    /**
     * @brief Obtient la barre de vie du château.
     * @return Une référence vers l'objet Lifebar représentant la barre de vie du château.
     */
    Lifebar& getLifebar() { return lifebar_; }

protected:
    Lifebar lifebar_ = Lifebar(0,0); /**< La barre de vie du château. */

};

typedef std::shared_ptr<Chateau> chateau_ptr;

#endif
