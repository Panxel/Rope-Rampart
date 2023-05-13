#include "loadTexture.hpp"

LoadTexture :: LoadTexture(){
    loadFile("../res/robot_small.jpg");
    mapTexture_.insert({"Mbot",texture_});
    loadFile("../res/test_small.jpg");
    mapTexture_.insert({"Guerrier",texture_});
    loadFile("../res/bombe.png");
    mapTexture_.insert({"Bombe",texture_});
    loadFile("../res/chateau.png");
    mapTexture_.insert({"Chateau",texture_});
    loadFile("../res/robot2.png");
    mapTexture_.insert({"Bombot",texture_});

}

void LoadTexture :: loadFile(std::string path){
    texture_.loadFromFile(path);
}

