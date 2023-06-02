#ifndef UNITE_HPP
#define UNITE_HPP

#include "entite.hpp"
#include "chateau.hpp"
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

enum Direction {
    Haut,
    Droite,
    Bas,
    Gauche
};

/**
 * @brief Classe Unite, héritant de la classe Entite, pour représenter une unité dans le jeu.
 */
class Unite : public Entite {

public:
    /**
     * @brief Constructeur de la classe Unite.
     * @param texture Texture de l'unité.
     * @param x Position en X de l'unité.
     * @param y Position en Y de l'unité.
     * @param health Points de vie de l'unité.
     * @param id Identifiant de l'unité.
     * @param atk Points d'attaque de l'unité.
     * @param spd Vitesse de l'unité.
     */
    Unite(sf::Texture& texture, float x, float y, int health, int id, int atk, int spd);

    /**
     * @brief Effectue l'attaque de l'unité.
     */
    virtual void attack() = 0;

    // Getters lecture/écriture

    /**
     * @brief Obtient les points d'attaque de l'unité.
     * @return Référence constante vers les points d'attaque.
     */
    const int& getAttack() const { return attack_; }

    /**
     * @brief Obtient les points d'attaque de l'unité.
     * @return Référence vers les points d'attaque.
     */
    int& getAttack() { return attack_; }

    /**
     * @brief Obtient la vitesse de l'unité.
     * @return Référence constante vers la vitesse.
     */
    const int& getSpeed() const { return speed_; }

    /**
     * @brief Obtient la vitesse de l'unité.
     * @return Référence vers la vitesse.
     */
    int& getSpeed() { return speed_; }

    /**
     * @brief Obtient la direction de l'unité.
     * @return Référence constante vers la direction.
     */
    const Direction& getDirection() const { return direction_; }

    /**
     * @brief Obtient la direction de l'unité.
     * @return Référence vers la direction.
     */
    Direction& getDirection() { return direction_; }

    // Sujet

    /**
     * @brief Ajoute un observateur de type Chateau pour l'unité.
     * @param observer Observateur de type Chateau à ajouter.
     */
    void addObserverChateau(chateau_ptr observer);

    /**
     * @brief Supprime un observateur de type Chateau pour l'unité.
     * @param observer Observateur de type Chateau à supprimer.
     */
    void removeObserverChateau(chateau_ptr observer);

    /**
     * @brief Notifie tous les observateurs de type Chateau de l'unité.
     * @param unite Pointeur vers l'unité notifiant les observateurs.
     */
    void notifyObserverChateau(std::shared_ptr<Unite> unite);

protected:
    std::vector<chateau_ptr> vectorObserverChateau_; ///< Vecteur des observateurs de type Chateau pour l'unité.
    Direction direction_ = Bas; ///< Direction de l'unité.
    int attack_; ///< Points d'attaque de l'unité.
    int speed_; ///< Vitesse de l'unité.

};

typedef std::shared_ptr<Unite> unite_ptr;

#endif
