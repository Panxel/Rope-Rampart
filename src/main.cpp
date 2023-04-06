#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "guerrier.hpp"

void input(sf::Event event,Renderer& renderer){
    if(event.type==sf::Event::Closed){
        renderer.getWindow().close();
    }
    if(event.type==sf::Event::KeyPressed){
        if(event.key.code==sf::Keyboard::Escape){
            renderer.getWindow().close();
        }
        if(event.key.code==sf::Keyboard::Left){
            renderer.setText("Gauche", 26, sf::Color::Red);
        }
        if(event.key.code==sf::Keyboard::Right){
            renderer.setText("Droite", 26, sf::Color::Red);
        }
    }
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button== sf::Mouse :: Left){
            renderer.setText("Gauche", 26, sf::Color::Red);
        }
        if(event.mouseButton.button== sf::Mouse :: Right){
            renderer.setText("Droite", 26, sf::Color::Red);
        }
    }
}

int main(){
    
    Renderer& renderer = Renderer :: get_instance();
    Guerrier e1 = Guerrier(0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED);
    while(renderer.getWindow().isOpen()){
        sf::Event event;
        while(renderer.getWindow().pollEvent(event)){
            input(event,renderer);
        }
        renderer.getWindow().clear(sf::Color :: Black);
        e1.afficher(renderer.getWindow());
        renderer.getWindow().draw(renderer.getText());
        renderer.getWindow().display();
    }
    
    return 0;
}