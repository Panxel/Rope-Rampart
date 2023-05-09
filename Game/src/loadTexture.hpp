#ifndef LOADTEXTURE_HPP
#define LOADTEXTURE_HPP
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class LoadTexture{

    public :
        static LoadTexture& get_instance(){
            static LoadTexture instance;
            return instance;
        }
        void loadFile(std:: string path);
        std::unordered_map<std::string,sf::Texture>& getMap(){return mapTexture_;}; 
    protected :

        LoadTexture();
        //Empeche la copie et l'assignation
        LoadTexture(const LoadTexture&) = delete;
        LoadTexture& operator=(const LoadTexture&) = delete;

        std::unordered_map<std::string,sf::Texture> mapTexture_;
        sf::Texture texture_;
};      

#endif