#ifndef ENTITE_HPP
#define ENTITE_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <SFML/Audio.hpp>

/**
 * @brief Classe de base pour les entités du jeu.
 */
class Entite{

    public :
    /**
     * @brief Constructeur de la classe Entite.
     * @param texture Texture de l'entité.
     * @param x Position horizontale de l'entité.
     * @param y Position verticale de l'entité.
     * @param health Points de vie de l'entité.
     * @param id Identifiant de l'entité.
     */
    Entite(sf::Texture& texture,float x,float y,int health,int id);

    /**
     * @brief Affiche l'entité sur la fenêtre spécifiée.
     * @param window Fenêtre de rendu.
     */
    virtual void afficher(sf::RenderWindow& window) = 0;

    /**
     * @brief Obtient le sprite de l'entité.
     * @return Référence constante vers le sprite.
     */
    const sf::Sprite& getSprite() const { return sprite_;};

    /**
     * @brief Charge la texture et initialise le sprite de l'entité.
     * @param texture Texture à charger.
     */
    void loadSprite(sf::Texture& texture);

    /**
     * @brief Obtient la position horizontale de l'entité.
     * @return Référence constante vers la position horizontale.
     */
    const float& getX() const {return pos_x_;};

    /**
     * @brief Obtient la position verticale de l'entité.
     * @return Référence constante vers la position verticale.
     */
    const float& getY() const {return pos_y_;};

    /**
     * @brief Obtient la position horizontale de l'entité.
     * @return Référence vers la position horizontale.
     */
    float& getX(){return pos_x_;};

     /**
     * @brief Obtient la position verticale de l'entité.
     * @return Référence vers la position verticale.
     */
    float& getY(){return pos_y_;};

    /**
     * @brief Obtient les points de vie de l'entité.
     * @return Référence constante vers les points de vie.
     */
    const int& getHP() const {return hp_;};

    /**
     * @brief Obtient les points de vie de l'entité.
     * @return Référence vers les points de vie.
     */
    int& getHP(){return hp_;};

    /**
     * @brief Obtient l'identifiant de l'entité.
     * @return Référence constante vers l'identifiant.
     */
    const int& getID() const {return id_;};

    /**
     * @brief Obtient l'identifiant de l'entité.
     * @return Référence vers l'identifiant.
     */
    int& getID(){return id_;};

    /**
     * @brief Vérifie si l'entité est morte.
     * @return Référence constante vers le statut de mort.
     */
    const bool& getDead() const {return dead_;};

    /**
     * @brief Vérifie si l'entité est morte.
     * @return Référence vers le statut de mort.
     */
    bool& getDead(){return dead_;};

    /**
     * @brief Inflige des dégâts à l'entité en réduisant ses points de vie.
     * @param damage Dégâts à infliger.
     */
    void takeDamage(const int& damage);

    protected :
    int id_;                            /**< Identifiant de l'entité. */
    int hp_;                            /**< Points de vie de l'entité. */
    bool dead_;                         /**< Indique si l'entité est morte. */
    float pos_x_;                       /**< Position horizontale de l'entité. */
    float pos_y_;                       /**< Position verticale de l'entité. */
    sf::Sprite sprite_;                 /**< Sprite de l'entité. */
    sf::IntRect rect;                   /**< Rectangle permettant de sélectionner la bonne image dans la grille d'images. */
    int compteur;                       /**< Attribut nécessaire à l'affichage et au changement de sprite pour le graphisme. Permet de ne pas avoir une animation trop rapide et illisible */
    int debut;                          /**< Attribut nécessaire à l'affichage et au changement de sprite pour le graphisme. Change le pixel de selection du rectangle */
    sf::Sound sound_;                   /**< Son pour les animations de l'entité. */
    sf::SoundBuffer soundBuffer;        /**< Buffer audio pour les animations de l'entité. */
}; 


#endif
