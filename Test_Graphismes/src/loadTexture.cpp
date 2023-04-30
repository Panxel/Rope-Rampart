#include "loadTexture.hpp"

LoadTexture :: LoadTexture(){
    loadFile();
    mapTexture_.insert({{"Robot",textureRobot_}, {"Guerrier1",textureGuerrier1_},{"Guerrier2",textureGuerrier2_}});
}

void LoadTexture :: loadFile(){
    textureGuerrier1_.loadFromFile("../res/Joueur1.png");
    textureGuerrier2_.loadFromFile("../res/Joueur2.png");
    textureRobot_.loadFromFile("../res/robot_small.jpg");
    //textureFond_.loadFromFile("../res/MAP_V2.png");
}