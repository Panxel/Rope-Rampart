#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "HUD.hpp"
#include "wave.hpp"
#include <SFML/Graphics.hpp>

/**
 * @class Map
 * @brief Classe représentant la carte du jeu.
 *
 * La classe Map est utilisée pour afficher la carte du jeu et ses éléments associés.
 */
class Map {
public:
    /**
     * @brief Constructeur de la classe Map.
     * @param x La position en x de la carte.
     * @param y La position en y de la carte.
     */
    Map(float x, float y);

    /**
     * @brief Obtient la position en x de la carte.
     * @return Une référence constante à la position en x.
     */
    const float& getX() const { return pos_x_; };

    /**
     * @brief Obtient la position en y de la carte.
     * @return Une référence constante à la position en y.
     */
    const float& getY() const { return pos_y_; };

    /**
     * @brief Obtient la position en x de la carte.
     * @return Une référence à la position en x.
     */
    float& getX() { return pos_x_; };

    /**
     * @brief Obtient la position en y de la carte.
     * @return Une référence à la position en y.
     */
    float& getY() { return pos_y_; };

    /**
     * @brief Charge les sprites pour les éléments de la carte.
     * @param texture La texture pour le fond de la carte.
     * @param texture_minimap La texture pour la minimap.
     * @param texture_rope La texture pour la corde.
     * @param texture_hud_j1 La texture pour l'HUD du joueur 1.
     * @param texture_hud_j2 La texture pour l'HUD du joueur 2.
     */
    void loadSprites(sf::Texture& texture, sf::Texture& texture_minimap, sf::Texture& texture_rope, sf::Texture& texture_hud_j1, sf::Texture& texture_hud_j2);

    /**
     * @brief Charge le sprite pour l'écran de level up.
     * @param level_up La texture pour l'écran de level up.
     */
    void loadSpritesScreen(sf::Texture& level_up);

    /**
     * @brief Affiche la carte dans une fenêtre de rendu SFML.
     * @param window La fenêtre de rendu.
     */
    void afficher(sf::RenderWindow& window);

    /**
     * @brief Affiche la vue de la carte dans une fenêtre de rendu SFML.
     * @param window La fenêtre de rendu.
     * @param wave_ L'instance de la vague de robots du niveau.
     */
    void afficherView(sf::RenderWindow& window, Wave& wave_);

    /**
     * @brief Obtient le cercle du joueur 1 pour l'afficher dans le radar.
     * @return Une référence constante au cercle du joueur 1.
     */
    const sf::CircleShape& getCircleJ1() const { return circle_j1; };

    /**
     * @brief Obtient le cercle du joueur 1 pour l'afficher dans le radar.
     * @return Une référence au cercle du joueur 1.
     */
    sf::CircleShape& getCircleJ1() { return circle_j1; };

    /**
     * @brief Obtient le cercle du joueur 2 pour l'afficher dans le radar.
     * @return Une référence constante au cercle du joueur 2.
     */
    const sf::CircleShape& getCircleJ2() const { return circle_j2; };

    /**
     * @brief Obtient le cercle du joueur 2 pour l'afficher dans le radar.
     * @return Une référence au cercle du joueur 2.
     */
    sf::CircleShape& getCircleJ2() { return circle_j2; };

    /**
     * @brief Obtient le sprite du fond de la carte.
     * @return Une référence constante au sprite du fond de la carte.
     */
    const sf::Sprite& getBackground() const { return background; };

    /**
     * @brief Obtient le sprite du fond de la carte.
     * @return Une référence au sprite du fond de la carte.
     */
    sf::Sprite& getBackground() { return background; };

    /**
     * @brief Obtient la position de la minimap.
     * @return Une référence constante au rectangle de position de la minimap.
     */
    const sf::RectangleShape& getPositionMinimap() const { return position_small_map; };

    /**
     * @brief Obtient la position de la minimap.
     * @return Une référence au rectangle de position de la minimap.
     */
    sf::RectangleShape& getPositionMinimap() { return position_small_map; };

    /**
     * @brief Obtient la corde.
     * @return Une référence constante au rectangle de la corde.
     */
    const sf::RectangleShape& getRope() const { return rope; };

    /**
     * @brief Obtient la corde.
     * @return Une référence au rectangle de la corde.
     */
    sf::RectangleShape& getRope() { return rope; };

    /**
     * @brief Obtient le sprite pour l'écran de level up.
     * @return Une référence constante au sprite pour l'écran de level up.
     */
    const sf::Sprite& getLevelUp() const { return level_up; };

    /**
     * @brief Obtient le sprite pour l'écran de level up.
     * @return Une référence au sprite pour l'écran de level up.
     */
    sf::Sprite& getLevelUp() { return level_up; };

    /**
     * @brief Obtient l'HUD du joueur 1.
     * @return Une référence constante à l'HUD du joueur 1.
     */
    const HUD& getHUD_j1() const { return HUD_j1; };

    /**
     * @brief Obtient l'HUD du joueur 1.
     * @return Une référence à l'HUD du joueur 1.
     */
    HUD& getHUD_j1() { return HUD_j1; };

    /**
     * @brief Obtient l'HUD du joueur 2.
     * @return Une référence constante à l'HUD du joueur 2.
     */
    const HUD& getHUD_j2() const { return HUD_j2; };

    /**
     * @brief Obtient l'HUD du joueur 2.
     * @return Une référence à l'HUD du joueur 2.
     */
    HUD& getHUD_j2() { return HUD_j2; };

    /**
     * @brief Obtient la valeur du bord atteint en x.
     * @return Une référence constante à la valeur du bord atteint en x.
     */
    const int& getBorderReachedX() const { return borderReachedX; };

    /**
     * @brief Obtient la valeur du bord atteint en x.
     * @return Une référence à la valeur du bord atteint en x.
     */
    int& getBorderReachedX() { return borderReachedX; };

    /**
     * @brief Obtient la valeur du bord atteint en y.
     * @return Une référence constante à la valeur du bord atteint en y.
     */
    const int& getBorderReachedY() const { return borderReachedY; };

    /**
     * @brief Obtient la valeur du bord atteint en y.
     * @return Une référence à la valeur du bord atteint en y.
     */
    int& getBorderReachedY() { return borderReachedY; };

    /**
     * @brief Vérifie si le bord de la carte a été atteint.
     */
    void isBorderReached();


protected:
    float pos_x_; /**< La position en x de la carte. */
    float pos_y_; /**< La position en y de la carte. */
    sf::Sprite background; /**< Le sprite du fond de la carte. */
    sf::Sprite background_minimap; /**< Le sprite du fond de la minimap. */
    sf::Sprite level_up; /**< Le sprite de l'écran de level up. */
    sf::View minimap; /**< La vue de la minimap. */
    sf::RectangleShape position_small_map; /**< Le rectangle de position de la minimap. */
    sf::RectangleShape contour_minimap; /**< Le contour de la minimap. */
    sf::CircleShape circle_j1; /**< Le cercle du joueur 1. */
    sf::CircleShape circle_j2; /**< Le cercle du joueur 2. */
    sf::RectangleShape rope; /**< La corde. */
    // HUD j1
    HUD HUD_j1 = HUD(0, 0);
    // HUD j2
    HUD HUD_j2 = HUD(0, 0);
    //
    int borderReachedX; /**< La valeur du bord atteint en x. */
    int borderReachedY; /**< La valeur du bord atteint en y. */

    // Nécessaire au son de fond
    sf::Sound sound_;
    sf::SoundBuffer soundBuffer;
    
    

};

#endif
