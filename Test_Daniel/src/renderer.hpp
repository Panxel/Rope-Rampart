#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <iostream>
#include "settings.hpp"
#include <SFML/Graphics.hpp>


//Singleton
class Renderer {

public:
    
    static Renderer& get_instance(){
        static Renderer instance;
        return instance;
    }
    void setText(const sf::String str,int size,sf::Color color);
    void loadFont();

    
    sf::RenderWindow& getWindow() {return window_;};
    sf::Text& getText() {return txt_;};

protected:
    Renderer();
    
    //Empeche la copie et l'assignation
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    sf::RenderWindow window_;
    sf::Font font_;
    sf::Text txt_;

};

#endif

