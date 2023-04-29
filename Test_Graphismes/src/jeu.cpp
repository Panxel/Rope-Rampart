#include "jeu.hpp"

Jeu :: Jeu(){
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier"],0.8*WIN_WIDTH,0.8*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addMonster(std :: make_shared<Robot>(loadTexture_.getMap()["Robot"],0.2*WIN_WIDTH,0.2*WIN_HEIGHT,Robot_HP,Robot_DAMAGE,Robot_SPEED));
    renderer_.getWindow().clear(sf::Color :: Black);
    joueurs_[0]->getSprite().setScale(3,3);
    //minimap.reset(sf::FloatRect(50, 50, 15,15));
    if(!this->map.loadFromFile("../res/MAP_V2.png"))
    {
        std::cout<<"pb chargement"<<std::endl;
    }
    map_sp.setTexture(this->map);
    map_radar.setTexture(this->map);
    // Paramètre pour le contour noir de la petite map.
    this->rectangle.setFillColor(sf::Color::Transparent);
    this->rectangle.setOutlineThickness(25);
    this->rectangle.setOutlineColor(sf::Color::Black);
    // Paramètre de la mini map et du rectangle autour de la mini map.
    minimap.setViewport(sf::FloatRect(0.80f, 0.f, 0.2, 0.22f));
    map_radar.setScale(0.65,0.65);
    rectangle.setPosition(25,25);
    rectangle.setSize(sf::Vector2f(965,830));
}

void Jeu :: gameInput(){

    //POUR EVITER QUE SA CRASH CAR SFML EST MAL FOUTU
    while(renderer_.getWindow().pollEvent(event_)){
    }
    if(event_.type == sf::Event::Closed){
        renderer_.getWindow().close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        renderer_.getWindow().close();
    }

    //Joueur 1
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        // Changement de la valeur de la direction (direction correspond à la hauteur du pixel de la bande d'animation)
        joueurs_[0]->direction=63;

        // Il faudra faire les tests pour savoir si on est vraiment au bord de l'image.
        // Test SI le joueur atteint la bordure gauche de l'écran
        if(joueurs_[0]->getX()<200)
        {
            // SI Oui, on bouge ici l'autre joueur et la map dans le sens contraire. A la fin, il faudra aussi bouger tous les robots.
            map_sp.setPosition(map_sp.getPosition().x+0.02*joueurs_[0]->getSpeed(),map_sp.getPosition().y);
            joueurs_[1]->getX()+=0.02*joueurs_[0]->getSpeed();
        }
        else
        {
            // SINON, il se déplace juste.
            joueurs_[0]->getX()-=0.02*joueurs_[0]->getSpeed();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        joueurs_[0]->direction=0;
        if(joueurs_[0]->getX()>600)
        {
            map_sp.setPosition(map_sp.getPosition().x-0.02*joueurs_[0]->getSpeed(),map_sp.getPosition().y);
            joueurs_[1]->getX()-=0.02*joueurs_[0]->getSpeed();
        }
        else
        {
            joueurs_[0]->getX()+=0.02*joueurs_[0]->getSpeed();
        }
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        joueurs_[0]->direction=21;
        if(joueurs_[0]->getY()<200)
        {
            map_sp.setPosition(map_sp.getPosition().x,map_sp.getPosition().y+0.02*joueurs_[0]->getSpeed());
            joueurs_[1]->getY()+=0.02*joueurs_[0]->getSpeed();
        }
        else
        {
            joueurs_[0]->getY()-=0.02*joueurs_[0]->getSpeed();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        joueurs_[0]->direction=42;
        if(joueurs_[0]->getY()>400)
        {
            map_sp.setPosition(map_sp.getPosition().x,map_sp.getPosition().y-0.02*joueurs_[0]->getSpeed());
            joueurs_[1]->getY()-=0.02*joueurs_[0]->getSpeed();
        }
        else
        {
            joueurs_[0]->getY()+=0.02*joueurs_[0]->getSpeed();
        }
    }

    //Joueur 2 - Faire les deplacement de la map aussi sur ce joueur.

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        joueurs_[1]->getX()-=0.02*joueurs_[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        joueurs_[1]->getX()+=0.02*joueurs_[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        joueurs_[1]->getY()-=0.02*joueurs_[1]->getSpeed();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        joueurs_[1]->getY()+=0.02*joueurs_[1]->getSpeed();
    }


    // TEST
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        invoker_.setCommande(std::make_unique<AttackCommande>(monsters_[0],joueurs_[0]->getAttack()));
        invoker_.executeCommande();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
        invoker_.setCommande(std::make_unique<MoveCommande>(joueurs_[1],0.02*joueurs_[1]->getSpeed(),0.02*joueurs_[1]->getSpeed()));
        invoker_.executeCommande();
    }

}
 

void Jeu :: gameLoop(){

    while(renderer_.getWindow().isOpen()){
        gameInput();
        gameDraw();
    }
}

void Jeu :: gameDraw(){

    //minimap.setCenter(0,0);
    // PASSAGE SUR LA GRANDE VUE.
    renderer_.getWindow().setView(renderer_.getWindow().getDefaultView());
    // Affichage de la grande map.
    renderer_.getWindow().draw(map_sp);
    //Affichage des deux joueurs et robot dans la grande map.
    joueurs_[0]->afficher(renderer_.getWindow());
    joueurs_[1]->afficher(renderer_.getWindow());
    monsters_[0]->afficher(renderer_.getWindow());
    // Passage sur la petite map.
    renderer_.getWindow().setView(minimap);
    renderer_.getWindow().draw(map_radar);
    renderer_.getWindow().draw(rectangle);
    renderer_.getWindow().display();
    
}

//void Jeu :: gamePlay(){
//}
