#include "loadTexture.hpp"

LoadTexture :: LoadTexture(){
    loadFile();
    mapTexture_.insert({{"Robot",textureRobot_}, {"Guerrier",textureGuerrier_}});
}

void LoadTexture :: loadFile(){
    textureGuerrier_.loadFromFile("../res/test_small.jpg");
    textureRobot_.loadFromFile("../res/robot_small.jpg");
}