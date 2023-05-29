#ifndef HUD_HPP
#define HUD_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

/**
 * @class HUD
 * @brief Classe représentant l'interface utilisateur tête haute (HUD) (Head Up Display en anglais).
 *
 * Le HUD est utilisé pour afficher des informations à l'écran, telles que la position
 * d'un objet, un texte, etc. Ici, il est utilisé pour afficher les informations du joueur au cours
 * du jeu, sa barre de vie et sa tête et son nom
 **/
class HUD{
    public :
    /**
     * @brief Constructeur de la classe HUD.
     * @param x La position en x du HUD.
     * @param y La position en y du HUD.
     */
    HUD(float x,float y);

    /**
     * @brief Obtient la position en x du HUD.
     * @return Une référence constante à la position en x.
     */
    const float& getX() const {return pos_x_;};

    /**
     * @brief Obtient la position en y du HUD.
     * @return Une référence constante à la position en y.
     */
    const float& getY() const {return pos_y_;};

    /**
     * @brief Obtient la position en x du HUD.
     * @return Une référence à la position en x.
     */
    float& getX(){return pos_x_;};

    /**
     * @brief Obtient la position en y du HUD.
     * @return Une référence à la position en y.
     */
    float& getY(){return pos_y_;};

    /**
     * @brief Charge une texture pour le sprite du HUD.
     * @param texture La texture à charger.
     */
    void loadSprite(sf::Texture& texture);

    /**
     * @brief Affiche le HUD dans une fenêtre de rendu SFML.
     * @param window La fenêtre de rendu.
     */
    void afficher(sf::RenderWindow& window);

    /**
     * @brief Obtient le sprite du HUD.
     * @return Une référence au sprite.
     */
    sf::Sprite& getSprite(){return sprite_;};

    /**
     * @brief Obtient le sprite du HUD.
     * @return Une référence constante au sprite.
     */
    const sf::Sprite& getSprite() const {return sprite_;};

    /**
     * @brief Définit le texte à afficher dans le HUD, soit le nom du joueur.
     * @param str La chaîne de caractères du texte.
     * @param size La taille de la police du texte.
     * @param color La couleur du texte.
     */
    void setText(const sf::String str,int size,sf::Color color);

     /**
     * @brief Obtient le texte du HUD.
     * @return Une référence au texte.
     */
    sf::Text& getText(){return nom_;};

    /**
    * @brief Obtient le texte du HUD.
    * @return Une référence constante au texte.
    */
    const sf::Text& getText() const {return nom_;};

    /**
    * @brief Charge la police de caractères pour le texte du HUD.
    */
    void loadFont();
    
    protected :

    float pos_x_; /**< La position en x du HUD. */
    float pos_y_; /**< La position en y du HUD. */
    sf::Sprite sprite_; /**< Le sprite du HUD. */
    sf::Font font_; /**< La police de caractères du texte. */
    sf::Text nom_; /**< Le texte à afficher dans le HUD. */  
};

#endif