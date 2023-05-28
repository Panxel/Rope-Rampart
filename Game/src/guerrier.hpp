#ifndef GUERRIER_HPP
#define GUERRIER_HPP

#include "unite.hpp"
#include "robot.hpp"
#include "bombe.hpp"
#include "lifebar.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Guerrier : public Unite {

public:
    /**
     * @brief Constructeur de la classe Chateau.
     * @param texture La texture du château.
     * @param x La position en x du château.
     * @param y La position en y du château.
     * @param health Les points de vie du château.
     * @param id L'identifiant du château.
     */
    Guerrier(sf::Texture& texture, float x, float y, int health, int id, int atk, int spd);

    /**
     * @brief Déclenche l'attaque du guerrier.
     */
    void attack();

    /**
     * @brief Affiche le guerrier sur la fenêtre spécifiée.
     * @param window La fenêtre SFML sur laquelle afficher le guerrier.
     */
    void afficher(sf::RenderWindow& window);

    // Sujet
    /**
     * @brief Ajoute un robot en tant qu'observateur du guerrier.
     * @param robot Un pointeur partagé vers l'objet Robot à ajouter en tant qu'observateur.
     */
    void addObserverRobot(robot_ptr robot);

    /**
     * @brief Supprime un robot de la liste des observateurs du guerrier.
     * @param robot Un pointeur partagé vers l'objet Robot à supprimer de la liste des observateurs.
     */
    void removeObserverRobot(robot_ptr robot);

    /**
     * @brief Notifie tous les observateurs robots du guerrier.
     * @param unite Un pointeur partagé vers l'objet Unite pour la notification.
     */
    void notifyObserverRobot(unite_ptr unite);

    /**
     * @brief Ajoute une bombe en tant qu'observateur du guerrier.
     * @param bombe Un pointeur partagé vers l'objet Bombe à ajouter en tant qu'observateur.
     */
    void addObserverBombe(bombe_ptr bombe);

    /**
     * @brief Supprime une bombe de la liste des observateurs du guerrier.
     * @param bombe Un pointeur partagé vers l'objet Bombe à supprimer de la liste des observateurs.
     */
    void removeObserverBombe(bombe_ptr bombe);

    /**
     * @brief Notifie tous les observateurs bombes du guerrier.
     * @param unite Un pointeur partagé vers l'objet Unite pour la notification.
     */
    void notifyObserverBombe(unite_ptr unite);

    /**
     * @brief Met à jour le guerrier lorsqu'une bombe explose.
     * @param bombe Un pointeur partagé vers l'objet Bombe qui a explosé.
     */
    void update(bombe_ptr bombe);

    /**
     * @brief Active l'effet élastique du guerrier.
     * @param distance La distance pour activer l'effet élastique.
     * @param x La position en x pour activer l'effet élastique.
     * @param y La position en y pour activer l'effet élastique.
     */
    void activateElastique(float distance, float x, float y);

    /**
     * @brief Obtient l'état de mouvement du guerrier.
     * @return Une référence vers le booléen indiquant si le guerrier est en mouvement ou non.
     */
    bool& getMouvement() { return mouvement_; }

    /**
     * @brief Obtient l'état de mouvement du guerrier (version constante).
     * @return Une référence constante vers le booléen indiquant si le guerrier est en mouvement ou non.
     */
    const bool& getMouvement() const { return mouvement_; }

    /**
     * @brief Déplace le guerrier d'une certaine distance.
     * @param distance La distance de déplacement.
     */
    void deplacement(float distance);

    /**
     * @brief Obtient l'état de l'effet élastique du guerrier.
     * @return Une référence vers le booléen indiquant si l'effet élastique est activé ou non.
     */
    bool& getElastique() { return elastique; }

    /**
     * @brief Obtient l'état de l'effet élastique du guerrier (version constante).
     * @return Une référence constante vers le booléen indiquant si l'effet élastique est activé ou non.
     */
    const bool& getElastique() const { return elastique; }

    /**
     * @brief Obtient la barre de vie du guerrier.
     * @return Une référence constante vers l'objet Lifebar représentant la barre de vie du guerrier.
     */
    const Lifebar& getLifebar() const { return lifebar_; }

    /**
     * @brief Obtient la barre de vie du guerrier.
     * @return Une référence vers l'objet Lifebar représentant la barre de vie du guerrier.
     */
    Lifebar& getLifebar() { return lifebar_; }

    /**
     * @brief Obtient l'état d'attaque du guerrier.
     * @return Une référence vers le booléen indiquant si le guerrier est en train d'attaquer ou non.
     */
    bool& getIsAttacking() { return isAttacking; }

    /**
     * @brief Obtient l'état d'attaque du guerrier (version constante).
     * @return Une référence constante vers le booléen indiquant si le guerrier est en train d'attaquer ou non.
     */
    const bool& getIsAttacking() const { return isAttacking; }

    /**
     * @brief Obtient le compteur du guerrier.
     * @return Une référence vers l'entier représentant le compteur du guerrier.
     */
    int& getCompteur() { return compteur; }

    /**
     * @brief Obtient le compteur du guerrier (version constante).
     * @return Une référence constante vers l'entier représentant le compteur du guerrier.
     */
    const int& getCompteur() const { return compteur; }

    /**
     * @brief Obtient le début du guerrier.
     * @return Une référence vers l'entier représentant le début du guerrier.
     */
    int& getDebut() { return debut; }

    /**
     * @brief Obtient le début du guerrier (version constante).
     * @return Une référence constante vers l'entier représentant le début du guerrier.
     */
    const int& getDebut() const { return debut; }

protected:
    std::vector<robot_ptr> vectorObserverRobot_;
    std::vector<bombe_ptr> vectorObserverBombe_;
    bool elastique; // Attribut qui active l'effet élastique
    bool isAttacking; // Booléen pour savoir si le joueur est en train d'attaquer
    bool mouvement_; // Booléen pour savoir si le personnage est en mouvement afin de gérer les animations du jeu
    Lifebar lifebar_ = Lifebar(0,0); // Barre de vie du guerrier
};

typedef std::shared_ptr<Guerrier> guerrier_ptr;

#endif

