#include "loadTexture.hpp"

LoadTexture :: LoadTexture(){
    loadFile();
    mapTexture_.insert({{"Robot",textureRobot_}, {"Guerrier",textureGuerrier_}});
}

void LoadTexture :: loadFile(){
    textureGuerrier_.loadFromFile("../res/test2.png");
    textureRobot_.loadFromFile("../res/robot_small.jpg");
    //textureFond_.loadFromFile("../res/MAP_V2.png");
}