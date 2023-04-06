#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "guerrier.hpp"
#include "jeu.hpp"

int main(){
    Jeu& game_manager = Jeu :: get_instance();
    game_manager.gameLoop();
    return 0;
}