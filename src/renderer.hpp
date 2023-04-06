#ifndef RENDERER_HPP
#define RENDERER_HPP
#include <iostream>

#include <SFML/Graphics.hpp>


//Singleton
class Renderer {

public:
    Renderer(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    static Renderer& get_instance(){
        static Renderer instance;
        return instance;
    }
    void setText(const sf::String str,int size,sf::Color color);
    void loadFont();

    
    sf::RenderWindow& getWindow() {return window;};
    sf::Text& getText() {return txt;};

protected:
    Renderer();
    sf::RenderWindow window;
    sf::Font font;
    sf::Text txt;

};

#endif
