#include <iostream>
#include "input.hpp"
#include <SFML/Graphics.hpp>




void input(Event event,Renderer& renderer){
    if(event.type==Event::Closed){
        renderer.getWindow().close();
    }
    if(event.type==Event::KeyPressed){
        if(event.key.code==Keyboard::Escape){
            renderer.getWindow().close();
        }
        if(event.key.code==Keyboard::Left){
            renderer.setText("Gauche", 26, sf::Color::Red);
        }
        if(event.key.code==Keyboard::Right){
            renderer.setText("Droite", 26, sf::Color::Red);
        }
    }
    if(event.type == Event::MouseButtonPressed){
        if(event.mouseButton.button== Mouse :: Left){
            renderer.setText("Gauche", 26, sf::Color::Red);
        }
        if(event.mouseButton.button== Mouse :: Right){
            renderer.setText("Droite", 26, sf::Color::Red);
        }
    }
}
