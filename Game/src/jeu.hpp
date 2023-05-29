#ifndef JEU_HPP
#define JEU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "renderer.hpp"
#include "settings.hpp"
#include "entite.hpp"
#include "guerrier.hpp"
#include "unite.hpp"
#include <vector>
#include "robot.hpp"
#include "loadTexture.hpp"
#include "chateau.hpp"
#include "wave.hpp"
#include "map.hpp"

/**
 * @class Jeu
 * @brief Classe principale du jeu qui gère la logique du jeu et les interactions entre les entités.
 */
class Jeu{
public:
    /**
     * @brief Récupère l'instance unique de la classe Jeu.
     * @return Instance unique de la classe Jeu.
     */
    static Jeu& get_instance(){
        static Jeu instance;
        return instance;
    }

    /**
     * @brief Ajoute un joueur (guerrier) au jeu.
     * @param joueur Pointeur vers le joueur à ajouter.
     */
    void addJoueur(guerrier_ptr joueur){vectorJoueurs_.push_back(joueur);};

    /**
     * @brief Efface le vecteur de joueurs, enlevant ainsi tous les joueurs du jeu.
     */
    void clearVectorJoueur();

    /**
     * @brief Ajoute un château au jeu.
     * @param chateau Pointeur vers le château à ajouter.
     */
    void addChateau(chateau_ptr chateau){chateau_.push_back(chateau);};

    /**
     * @brief Efface le vecteur de châteaux, enlevant ainsi tous les châteaux du jeu.
     */
    void clearVectorChateau();

    /**
     * @brief Supprime tous les liens d'observation entre les robots et les joueurs et chateau.
     */
    void clearAllObserverLink();

    /**
     * @brief Établit les liens d'observation entre les robots et les joueurs.
     */
    void linkAllRobotObserver();

    /**
     * @brief Supprime le lien d'observation entre un robot donné et les joueurs.
     * @param robot Pointeur vers le robot dont on souhaite supprimer le lien d'observation.
     */
    void delinkRobotObserver(robot_ptr robot);

    /**
     * @brief Établit les liens d'observation entre les bombes et les joueurs.
     * @param bombe Pointeur vers la bombe dont on souhaite établir le lien d'observation.
     */
    void linkBombeObserver(bombe_ptr bombe);

    /**
     * @brief Supprime le lien d'observation entre une bombe donnée et les joueurs.
     * @param bombe Pointeur vers la bombe dont on souhaite supprimer le lien d'observation.
     */
    void delinkBombeObserver(bombe_ptr bombe);

    /**
     * @brief Affiche tous les joueurs du jeu.
     */
    void afficherAllJoueur();

    /**
     * @brief Affiche tous les châteaux du jeu.
     */
    void afficherChateau();

    /**
     * @brief Met à jour l'affichage des barres de vie des entités affichables.
     */
    void updateLifeAffichables();

    /**
     * @brief Décale les positions de tous les éléments affichables sur l'axe X.
     */
    void decalerAllAffichablesX();

    /**
     * @brief Décale les positions de tous les éléments affichables sur l'axe Y.
     */
    void decalerAllAffichablesY();

    /**
     * @brief Gère les entrées du jeu (clavier, etc.).
     */
    void gameInput();

    /**
     * @brief Gère la logique de jeu (mouvements, attaques, collisions, etc.).
     */
    void gamePlay();

    /**
     * @brief Boucle principale du jeu.
     */
    void gameLoop();

    /**
     * @brief Effectue le rendu graphique du jeu.
     */
    void gameDraw();

protected:
    /**
     * @brief Constructeur par défaut de la classe Jeu.
     * Le constructeur est déclaré protégé pour empêcher l'instanciation directe de la classe.
     */
    Jeu();

    /**
     * @brief Constructeur de copie de la classe Jeu.
     * Le constructeur de copie est supprimé pour empêcher la copie de l'instance unique de la classe.
     */
    Jeu(const Jeu&) = delete;

    /**
     * @brief Opérateur d'affectation de la classe Jeu.
     * L'opérateur d'affectation est supprimé pour empêcher l'affectation de l'instance unique de la classe.
     */
    Jeu& operator=(const Jeu&) = delete;

    Renderer& renderer_ = Renderer :: get_instance(); // Référence à l'instance du Renderer pour gérer le rendu graphique
    LoadTexture& loadTexture_ = LoadTexture :: get_instance(); // Référence à l'instance de LoadTexture pour charger les textures
    Wave& wave_ = Wave :: get_instance(); // Référence à l'instance de Wave pour gérer les vagues d'ennemis

    std::vector<guerrier_ptr> vectorJoueurs_; // Vecteur contenant les pointeurs vers les joueurs (guerriers)
    std::vector<chateau_ptr> chateau_; // Vecteur contenant les pointeurs vers les châteaux

    sf::Event event_; // Événement SFML utilisé pour gérer les entrées du jeu

    float distance; // Distance entre les deux joueurs

    Map background = Map(0,0); // Objet Map représentant les éléments affichables de la carte (radar, HUD joueur 1, HUD joueur 2, etc.)
};

#endif
