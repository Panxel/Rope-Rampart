#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "entite.hpp"
#include "settings.hpp"
#include "unite.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <chrono>

class Guerrier;

/**
 * @class Bombe
 * @brief Classe représentant une bombe.
 *
 * La classe Bombe hérite de la classe Entite et ajoute des fonctionnalités spécifiques à une bombe.
 */
class Bombe : public Entite {
public:
    /**
     * @brief Constructeur de la classe Bombe.
     * @param texture La texture de la bombe.
     * @param x La position en x de la bombe.
     * @param y La position en y de la bombe.
     * @param health Les points de vie de la bombe.
     * @param id L'identifiant de la bombe.
     * @param atk La valeur d'attaque de la bombe.
     */
    Bombe(sf::Texture& texture, float x, float y, int health, int id, int atk);

    /**
     * @brief Affiche la bombe sur la fenêtre spécifiée.
     * @param window La fenêtre où afficher la bombe.
     */
    void afficher(sf::RenderWindow& window);

    /**
     * @brief Obtient la valeur d'attaque de la bombe.
     * @return Une référence constante à la valeur d'attaque de la bombe.
     */
    const int& getAttack() const { return attack_; };

    /**
     * @brief Obtient la valeur d'attaque de la bombe.
     * @return Une référence à la valeur d'attaque de la bombe.
     */
    int& getAttack() { return attack_; };

    /**
     * @brief Ajoute un observateur guerrier à la bombe.
     * @param guerrier Le pointeur partagé vers le guerrier observateur.
     */
    void addObserverGuerrier(std::shared_ptr<Guerrier> guerrier);

    /**
     * @brief Supprime un observateur guerrier de la bombe.
     * @param guerrier Le pointeur partagé vers le guerrier observateur à supprimer.
     */
    void removeObserverGuerrier(std::shared_ptr<Guerrier> guerrier);

    /**
     * @brief Notifie les observateurs guerriers de la bombe.
     * @param bombe Le pointeur partagé vers la bombe qui notifie les guerriers.
     */
    void notifyObserverGuerrier(std::shared_ptr<Bombe> bombe);

    /**
     * @brief Met à jour l'état de la bombe en fonction d'une unité spécifiée.
     * @param unite Le pointeur partagé vers l'unité qui a interagi avec la bombe.
     */
    void update(std::shared_ptr<Unite> unite);

    /**
     * @brief Calcule la différence de temps depuis la création de la bombe.
     * @return La différence de temps en secondes.
     */
    double timeDiff();

protected:
    int attack_; /**< La valeur d'attaque de la bombe. */
    std::vector<std::shared_ptr<Guerrier>> vectorObserverGuerrier_; /**< Le vecteur des observateurs guerriers de la bombe. */
    std::chrono::time_point<std::chrono::system_clock> start_; /**< Le point de départ de la bombe pour calculer la différence de temps. */
    std::chrono::time_point<std::chrono::system_clock> end_; /**< Le point de fin de la bombe pour calculer la différence de temps. */
    std::chrono::duration<double> diff_seconds_; /**< La durée écoulée depuis la création de la bombe. */
};

typedef std::shared_ptr<Bombe> bombe_ptr;

#endif