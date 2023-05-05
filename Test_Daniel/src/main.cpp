#include "jeu.hpp"

int main(){
    Jeu& game_manager = Jeu :: get_instance();
    game_manager.gameLoop();
    return 0;
} 