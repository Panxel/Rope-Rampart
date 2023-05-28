#ifndef LOADTEXTURE_HPP
#define LOADTEXTURE_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

/**
 * @brief Classe singleton pour charger les textures.
 */
class LoadTexture {
public:
    /**
     * @brief Obtient l'instance unique de la classe LoadTexture.
     * @return Référence vers l'instance unique de LoadTexture.
     */
    static LoadTexture& get_instance() {
        static LoadTexture instance;
        return instance;
    }

    /**
     * @brief Charge une texture à partir d'un fichier et l'ajoute à la map des textures.
     * @param path Chemin du fichier de la texture.
     */
    void loadFile(std::string path);

    /**
     * @brief Obtient la map des textures chargées.
     * @return Map des textures chargées.
     */
    std::unordered_map<std::string, sf::Texture>& getMap() { return mapTexture_; }
        

private:
    /**
     * @brief Constructeur privé de la classe LoadTexture.
     */
    LoadTexture();

    /**
     * @brief Constructeur de copie privé de la classe LoadTexture (pour empêcher la copie).
     */
    LoadTexture(const LoadTexture&) = delete;

    /**
     * @brief Opérateur d'assignation privé de la classe LoadTexture (pour empêcher l'assignation).
     */
    LoadTexture& operator=(const LoadTexture&) = delete;

    std::unordered_map<std::string, sf::Texture> mapTexture_; ///< Map des textures chargées.
    sf::Texture texture_;
};

#endif
