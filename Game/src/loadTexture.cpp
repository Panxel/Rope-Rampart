#include "loadTexture.hpp"

LoadTexture :: LoadTexture(){
    loadFile("../res/robot_small.jpg");
    mapTexture_.insert({"Robot",texture_});
    loadFile("../res/test_small.jpg");
    mapTexture_.insert({"Guerrier",texture_});

}

void LoadTexture :: loadFile(std::string path){
    texture_.loadFromFile(path);
}

