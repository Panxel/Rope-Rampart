#include <iostream>
#include "renderer.hpp"
#include "settings.hpp"


Renderer::Renderer()
{
    window.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Rope Rampart");
    window.clear(sf::Color::Black);
    loadFont();
    setText("Salut", 26, sf::Color::Red);
}

void Renderer :: loadFont(){
    if(!font.loadFromFile("../res/Poppins-Regular.ttf")){
        std::cout << "Error Chargement Font" << std::endl;
    }
}

void Renderer :: setText(const sf::String str,int size,sf::Color color){
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(size);
    txt.setFillColor(color);
    txt.setStyle(sf::Text :: Bold);
}