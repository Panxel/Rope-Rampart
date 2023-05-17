#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "HUD.hpp"
#include "wave.hpp"
#include <SFML/Graphics.hpp>

class Map{
    public :
    Map(float x,float y);
    const float& getX() const {return pos_x_;};
    const float& getY() const {return pos_y_;};
    float& getX(){return pos_x_;};
    float& getY(){return pos_y_;};
    void loadSprites(sf::Texture& texture, sf::Texture& texture_minimap, sf::Texture& texture_rope, sf::Texture& texture_hud_j1, sf::Texture& texture_hud_j2);
    void loadSpritesScreen(sf::Texture& level_up);
    void afficher(sf::RenderWindow& window);
    void afficherView(sf::RenderWindow& window, Wave& wave_);
    const sf::CircleShape& getCircleJ1() const {return circle_j1;};
    sf::CircleShape& getCircleJ1(){return circle_j1;};
    const sf::CircleShape& getCircleJ2() const {return circle_j2;};
    sf::CircleShape& getCircleJ2(){return circle_j2;};
    const sf::Sprite& getBackground() const {return background;};
    sf::Sprite& getBackground(){return background;};
    const sf::RectangleShape& getPositionMinimap() const {return position_small_map;};
    sf::RectangleShape& getPositionMinimap(){return position_small_map;};
    const sf::RectangleShape& getRope() const {return rope;};
    sf::RectangleShape& getRope(){return rope;};
    const sf::Sprite& getLevelUp() const {return level_up;};
    sf::Sprite& getLevelUp(){return level_up;};
    const HUD& getHUD_j1() const {return HUD_j1;};
    HUD& getHUD_j1(){return HUD_j1;};
    const HUD& getHUD_j2() const {return HUD_j2;};
    HUD& getHUD_j2(){return HUD_j2;};

    protected :
    float pos_x_;
    float pos_y_;
    sf::Sprite background;
    sf::Sprite background_minimap;
    sf::Sprite level_up;
    sf::View minimap;
    sf::RectangleShape position_small_map;
    sf::RectangleShape contour_minimap;
    sf::CircleShape circle_j1;
    sf::CircleShape circle_j2;
    sf::RectangleShape rope;
    // HUD j1
    HUD HUD_j1=HUD(0,0);
    // HUD j2
    HUD HUD_j2=HUD(0,0);
    
    

};

#endif