#include "jeu.hpp"

sf::Vertex line[2];
sf::RectangleShape position_small_map;
sf::CircleShape position_j1;
sf::CircleShape position_j2;

Jeu :: Jeu(){
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier1"],0.5*WIN_WIDTH,0.5*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addJoueur(std :: make_shared<Guerrier>(loadTexture_.getMap()["Guerrier2"],0.8*WIN_WIDTH,0.8*WIN_HEIGHT,GUERRIER_HP,GUERRIER_DAMAGE,GUERRIER_SPEED));
    addMonster(std :: make_shared<Robot>(loadTexture_.getMap()["Robot"],0.2*WIN_WIDTH,0.2*WIN_HEIGHT,Robot_HP,Robot_DAMAGE,Robot_SPEED));
    renderer_.getWindow().clear(sf::Color :: Black);
    joueurs_[0]->getSprite().setScale(3,3);
    joueurs_[1]->getSprite().setScale(3,3);
    joueurs_[0]->direction = 42;
    joueurs_[0]->direction = 42;
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
    // Test position grande map dans la petite
    position_small_map.setFillColor(sf::Color::Transparent);
    position_small_map.setOutlineThickness(8);
    position_small_map.setOutlineColor(sf::Color::Red);
    // Test position des joueurs dans la minimap.
    position_j1.setFillColor(sf::Color::Red);
    position_j2.setFillColor(sf::Color::Blue);
    position_j1.setRadius(12.0f);
    position_j2.setRadius(12.0f);

}

void Jeu :: gameInput(){
    bool mouvement_j1 = false;
    bool mouvement_j2 = false;

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
        mouvement_j1=true;
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
        mouvement_j1=true;
        joueurs_[0]->direction=21;
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
        mouvement_j1=true;
        joueurs_[0]->direction=42;
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
        mouvement_j1=true;
        joueurs_[0]->direction=0;
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
    if(mouvement_j1==false)
    {
        if(joueurs_[0]->direction==0 || joueurs_[0]->direction==21 || joueurs_[0]->direction==42 || joueurs_[0]->direction==63 )
        {
            joueurs_[0]->direction += 84;
        }
    }

    //Joueur 2
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        mouvement_j2=true;
        // Changement de la valeur de la direction (direction correspond à la hauteur du pixel de la bande d'animation)
        joueurs_[1]->direction=63;

        // Il faudra faire les tests pour savoir si on est vraiment au bord de l'image.
        // Test SI le joueur atteint la bordure gauche de l'écran
        if(joueurs_[1]->getX()<200)
        {
            // SI Oui, on bouge ici l'autre joueur et la map dans le sens contraire. A la fin, il faudra aussi bouger tous les robots.
            map_sp.setPosition(map_sp.getPosition().x+0.02*joueurs_[0]->getSpeed(),map_sp.getPosition().y);
            joueurs_[0]->getX()+=0.02*joueurs_[1]->getSpeed();
        }
        else
        {
            // SINON, il se déplace juste.
            joueurs_[1]->getX()-=0.02*joueurs_[1]->getSpeed();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        mouvement_j2=true;
        joueurs_[1]->direction=21;
        if(joueurs_[1]->getX()>600)
        {
            map_sp.setPosition(map_sp.getPosition().x-0.02*joueurs_[0]->getSpeed(),map_sp.getPosition().y);
            joueurs_[0]->getX()-=0.02*joueurs_[1]->getSpeed();
        }
        else
        {
            joueurs_[1]->getX()+=0.02*joueurs_[1]->getSpeed();
        }
        
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        mouvement_j2=true;
        joueurs_[1]->direction=42;
        if(joueurs_[1]->getY()<200)
        {
            map_sp.setPosition(map_sp.getPosition().x,map_sp.getPosition().y+0.02*joueurs_[0]->getSpeed());
            joueurs_[0]->getY()+=0.02*joueurs_[1]->getSpeed();
        }
        else
        {
            joueurs_[1]->getY()-=0.02*joueurs_[1]->getSpeed();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        mouvement_j2=true;
        joueurs_[1]->direction=0;
        if(joueurs_[1]->getY()>400)
        {
            map_sp.setPosition(map_sp.getPosition().x,map_sp.getPosition().y-0.02*joueurs_[0]->getSpeed());
            joueurs_[0]->getY()-=0.02*joueurs_[1]->getSpeed();
        }
        else
        {
            joueurs_[1]->getY()+=0.02*joueurs_[1]->getSpeed();
        }
    }
    if(mouvement_j2==false)
    {
        if(joueurs_[1]->direction==0 || joueurs_[1]->direction==21 || joueurs_[1]->direction==42 || joueurs_[1]->direction==63 )
        {
            joueurs_[1]->direction += 84;
        }
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
     // TEST AFFICHAGE LINE 
    line[0].position = sf::Vector2f(joueurs_[0]->getX()+25, joueurs_[0]->getY()+40);
    line[0].color  = sf::Color::Yellow;
    line[1].position = sf::Vector2f(joueurs_[1]->getX()+25, joueurs_[1]->getY()+40);
    line[1].color = sf::Color::Yellow;
    renderer_.getWindow().draw(line,2,sf::Lines);
    // Passage sur la petite map.
    renderer_.getWindow().setView(minimap);
    renderer_.getWindow().draw(map_radar);
    renderer_.getWindow().draw(rectangle);
    position_small_map.setPosition(-map_sp.getPosition().x*0.65,-map_sp.getPosition().y*0.65);
    //std::cout<<"Position en x de la grande map : "<<-map_sp.getPosition().x<<std::endl;
    //std::cout<<"POsition en y de la grande map :"<<-map_sp.getPosition().y<<std::endl;
    position_small_map.setSize(sf::Vector2f(520,390)); 
    renderer_.getWindow().draw(position_small_map);
    position_j1.setPosition(sf::Vector2f(position_small_map.getPosition().x+joueurs_[0]->getX()*0.65+5,position_small_map.getPosition().y+joueurs_[0]->getY()*0.65+5));
    position_j2.setPosition(sf::Vector2f(position_small_map.getPosition().x+joueurs_[1]->getX()*0.65+5,position_small_map.getPosition().y+joueurs_[1]->getY()*0.65+5));
    renderer_.getWindow().draw(position_j1);
    renderer_.getWindow().draw(position_j2);
    renderer_.getWindow().display();

}

//void Jeu :: gamePlay(){
//}
