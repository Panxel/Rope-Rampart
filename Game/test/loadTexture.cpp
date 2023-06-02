#include "loadTexture.hpp"

LoadTexture :: LoadTexture(){
    // Chargement des textures des guerriers (joueur 1 et joueur 2)
    // Joueur1
    loadFile("../res/Joueur1/run_front.png");
    mapTexture_.insert({"run_front_j1",texture_});
    loadFile("../res/Joueur1/run_right.png");
    mapTexture_.insert({"run_right_j1",texture_});
    loadFile("../res/Joueur1/run_back.png");
    mapTexture_.insert({"run_back_j1",texture_});
    loadFile("../res/Joueur1/run_left.png");
    mapTexture_.insert({"run_left_j1",texture_});
    loadFile("../res/Joueur1/standby_front.png");
    mapTexture_.insert({"standby_front_j1",texture_});
    loadFile("../res/Joueur1/standby_right.png");
    mapTexture_.insert({"standby_right_j1",texture_});
    loadFile("../res/Joueur1/standby_back.png");
    mapTexture_.insert({"standby_back_j1",texture_});
    loadFile("../res/Joueur1/standby_left.png");
    mapTexture_.insert({"standby_left_j1",texture_});
    loadFile("../res/Joueur1/HUD.png");
    mapTexture_.insert({"HUD_j1",texture_});
    // Joueur2
    loadFile("../res/Joueur2/run_front_j2.png");
    mapTexture_.insert({"run_front_j2",texture_});
    loadFile("../res/Joueur2/run_right_j2.png");
    mapTexture_.insert({"run_right_j2",texture_});
    loadFile("../res/Joueur2/run_back_j2.png");
    mapTexture_.insert({"run_back_j2",texture_});
    loadFile("../res/Joueur2/run_left_j2.png");
    mapTexture_.insert({"run_left_j2",texture_});
    loadFile("../res/Joueur2/standby_front_j2.png");
    mapTexture_.insert({"standby_front_j2",texture_});
    loadFile("../res/Joueur2/standby_right_j2.png");
    mapTexture_.insert({"standby_right_j2",texture_});
    loadFile("../res/Joueur2/standby_back_j2.png");
    mapTexture_.insert({"standby_back_j2",texture_});
    loadFile("../res/Joueur2/standby_left_j2.png");
    mapTexture_.insert({"standby_left_j2",texture_});
    loadFile("../res/Joueur2/HUD_j2.png");
    mapTexture_.insert({"HUD_j2",texture_});
    // Chargement des textures nécessaire à la MAP
    loadFile("../res/Map/MAP.png");
    mapTexture_.insert({"Map",texture_});
    loadFile("../res/Map/castle.png");
    mapTexture_.insert({"Chateau",texture_});
    loadFile("../res/Map/Minimap.png");
    mapTexture_.insert({"Minimap",texture_});
    loadFile("../res/Map/rope_texture.jpg");
    mapTexture_.insert({"Rope",texture_});
    // Chargement des textures de barre de vie
    loadFile("../res/Map/Lifebar/life0.png");
    mapTexture_.insert({"life0",texture_});
    loadFile("../res/Map/Lifebar/life1.png");
    mapTexture_.insert({"life1",texture_});
    loadFile("../res/Map/Lifebar/life2.png");
    mapTexture_.insert({"life2",texture_});
    loadFile("../res/Map/Lifebar/life3.png");
    mapTexture_.insert({"life3",texture_});
    loadFile("../res/Map/Lifebar/life4.png");
    mapTexture_.insert({"life4",texture_});
    loadFile("../res/Map/Lifebar/life5.png");
    mapTexture_.insert({"life5",texture_});
    loadFile("../res/Map/Lifebar/life6.png");
    mapTexture_.insert({"life6",texture_});
    loadFile("../res/Map/Lifebar/life7.png");
    mapTexture_.insert({"life7",texture_});
    // Chargement des textures des robots
    // MBOT
    loadFile("../res/Robot/MBOT/Mbot_Front.png");
    mapTexture_.insert({"Mbot_front",texture_});
    loadFile("../res/Robot/MBOT/Mbot_Back.png");
    mapTexture_.insert({"Mbot_back",texture_});
    loadFile("../res/Robot/MBOT/Mbot_Right.png");
    mapTexture_.insert({"Mbot_right",texture_});
    loadFile("../res/Robot/MBOT/Mbot_Left.png");
    mapTexture_.insert({"Mbot_left",texture_});
    // BOMBOT
    loadFile("../res/Robot/BOMBOT/Bombot_Front.png");
    mapTexture_.insert({"Bombot_front",texture_});
    loadFile("../res/Robot/BOMBOT/Bombot_Back.png");
    mapTexture_.insert({"Bombot_back",texture_});
    loadFile("../res/Robot/BOMBOT/Bombot_Right.png");
    mapTexture_.insert({"Bombot_right",texture_});
    loadFile("../res/Robot/BOMBOT/Bombot_Left.png");
    mapTexture_.insert({"Bombot_left",texture_});
    // Chargement texture bombe :
    loadFile("../res/Bombe/bomb.png");
    mapTexture_.insert({"Bombe",texture_});
    //Chargement des textures d'attaques
    loadFile("../res/Joueur1/attack_j1.png");
    mapTexture_.insert({"attack_j1",texture_});
    loadFile("../res/Joueur2/attack_j2.png");
    mapTexture_.insert({"attack_j2",texture_});
    // Chargement des écran de jeu
    loadFile("../res/Ecran Jeu/New_level.png");
    mapTexture_.insert({"New_level",texture_});
}

void LoadTexture :: loadFile(std::string path){
    texture_.loadFromFile(path);
}