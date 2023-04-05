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
    Guerrier e1 = Guerrier(0,0,20,5,2,10);
    Guerrier e2 = Guerrier(1,1,20,5,2,10);
    
    /*texture2.setSmooth(true);
    texture.setSmooth(true);
    sf::Sprite sprite;
    sf::Sprite sprite2;
    sprite.setTexture(texture);
    sprite2.setTexture(texture2);
    */
    /*
    e1.textureLoad("../res/test.jpg");
    e2.textureLoad("../res/esp32.png");
    e1.setTexture(e1.getTexture());
    e2.setTexture(e2.getTexture());
    while(renderer.getWindow().isOpen()){
        sf::Event event;
        while(renderer.getWindow().pollEvent(event)){
            input(event,renderer);
        }
        renderer.getWindow().clear(sf::Color :: Black);
        renderer.getWindow().draw(e1.getSprite());
        renderer.getWindow().draw(e2.getSprite());
        renderer.getWindow().draw(renderer.getText());
        renderer.getWindow().display();
    }
    */
    return 0;
}