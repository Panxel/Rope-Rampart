#include "renderer.hpp"

Renderer::Renderer()
{
    window_.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Rope Rampart");
    window_.clear(sf::Color::Black);
    window_.setFramerateLimit(50);
    loadFont();
    setText("Salut", 26, sf::Color::Red);
}

void Renderer :: loadFont(){
    if(!font_.loadFromFile("../res/Poppins-Regular.ttf")){
        std::cout << "Error Chargement Font" << std::endl;
    }
}

void Renderer :: setText(const sf::String str,int size,sf::Color color){
    txt_.setFont(font_);
    txt_.setString(str);
    txt_.setCharacterSize(size);
    txt_.setFillColor(color);
    txt_.setStyle(sf::Text :: Bold);
}