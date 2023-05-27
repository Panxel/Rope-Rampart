#include "map.hpp"
#include <math.h>

Map :: Map(float x,float y)
{
    pos_x_ = x;
    pos_y_ = y;
    // Paramètre cercles des joueurs dans la minimap
    circle_j1.setFillColor(sf::Color::Red);
    circle_j2.setFillColor(sf::Color::Blue);
    circle_j1.setRadius(12.0f);
    circle_j2.setRadius(12.0f);
    position_small_map.setSize(sf::Vector2f(520,390)); 

    // Paramètre pour le contour noir de minimap
    contour_minimap.setFillColor(sf::Color::Transparent);
    contour_minimap.setOutlineThickness(25);
    contour_minimap.setOutlineColor(sf::Color::Black);

    // Paramètre de la mini map et du rectangle autour de la mini map.
    minimap.setViewport(sf::FloatRect(0.80f, 0.f, 0.2, 0.22f));
    background_minimap.setScale(0.65,0.65);
    contour_minimap.setPosition(25,25);
    contour_minimap.setSize(sf::Vector2f(965,830));

    // Paramètre pour le repère (rectangle rouge) de la position de la map dans la grande map
    position_small_map.setFillColor(sf::Color::Transparent);
    position_small_map.setOutlineThickness(8);
    position_small_map.setOutlineColor(sf::Color::Red);

    // Paramètre pour la corde
    rope.setSize(sf::Vector2f(200,3));

    //Paramètre position HUD j1
    HUD_j1.getSprite().setPosition(5,550);
    HUD_j1.getSprite().setScale(3,3);
    //Paramètre position HUD j2
    HUD_j2.getSprite().setPosition(653,550);
    HUD_j2.getSprite().setScale(3,3);

    // Paramètre écran nouveau niveau
    level_up.setPosition(0,0);

    // Set BorderReached

    borderReachedX = 0;
    borderReachedX = 0;

    soundBuffer.loadFromFile("../res/Son/Tower-Defense.wav");
    sound_.setLoop(true);
    sound_.setBuffer(soundBuffer);
    sound_.setVolume(40);
    sound_.play();
    
}

void Map::loadSprites(sf::Texture& texture, sf::Texture& texture_minimap, sf::Texture& texture_rope, sf::Texture& texture_hud_j1, sf::Texture& texture_hud_j2){
    background.setTexture(texture);
    background_minimap.setTexture(texture_minimap);
    rope.setTexture(&texture_rope);
    HUD_j1.getSprite().setTexture(texture_hud_j1);
    HUD_j2.getSprite().setTexture(texture_hud_j2);
}

void Map::loadSpritesScreen(sf::Texture& texture){
    level_up.setTexture(texture);
}

void Map :: afficher(sf::RenderWindow& window){
    window.setView(window.getDefaultView());
    // Affichage du background
    background.setPosition(round(pos_x_),round(pos_y_));
    window.draw(background);
    window.draw(rope);
    HUD_j1.afficher(window);
    HUD_j2.afficher(window);
}

void Map :: afficherView(sf::RenderWindow& window, Wave& wave_){
    window.setView(minimap);
    // Affichage du fond de la minimap
    window.draw(background_minimap);
    // Affichage du contour de la view
    window.draw(contour_minimap);
    // Affichage du contour de la small map dans la view
    window.draw(position_small_map);
    // Affichage du cercles des deux joueurs;
    window.draw(circle_j1);
    window.draw(circle_j2);
    // Affichage du cercle des robots;
    //for(robot_ptr monster : wave_.getVectorMonsters()){

    for(int i=0;i<(wave_.getNbMobsSpawned()-wave_.getNbMobsDied());i++){
        sf::CircleShape circle;
        circle.setFillColor(sf::Color::Black);
        circle.setRadius(12.0f);
        circle.setPosition(position_small_map.getPosition().x+wave_.getVectorMonsters()[i]->getX()*0.65,position_small_map.getPosition().y+wave_.getVectorMonsters()[i]->getY()*0.65);
        window.draw(circle);
    }

    window.setView(window.getDefaultView());
}

void Map :: isBorderReached()
{
    if(background.getPosition().x>0)
    {
        borderReachedX = 9;
    }
    if(background.getPosition().x<-758)
    {
        borderReachedX = 3;
    }
    if(background.getPosition().y>0)
    {
        borderReachedY = 12;
    }
    if(background.getPosition().y<-720)
    {
        borderReachedY = 6;
    }
}