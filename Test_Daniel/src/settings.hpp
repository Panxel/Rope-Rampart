#ifndef SETTINGS_HPP
#define SETTINGS_HPP

//Window
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

//Id
const int CHATEAU_ID = 0;
const int JOUEUR_ID = 1;
const int ROBOT_ID = 2;

//Chateau

const float CHATEAU_INITX = WIN_WIDTH/2;
const float CHATEAU_INITY = WIN_HEIGHT/2;
const int CHATEAU_WIDTH = 50;
const int CHATEAU_HEIGHT = 49;
const int CHATEAU_HP = 300;

//Joueur 1
const float JOUEUR1_INITX = WIN_WIDTH*0.3;
const float JOUEUR1_INITY = WIN_HEIGHT*0.3;

//Joueur 2
const float JOUEUR2_INITX = WIN_WIDTH*0.2;
const float JOUEUR2_INITY = WIN_HEIGHT*0.2;

//Guerrier
const int GUERRIER_WIDTH = 50;
const int GUERRIER_HEIGHT = 49;
const int GUERRIER_HP = 20;
const int GUERRIER_DAMAGE = 5;
const int GUERRIER_SPEED = 2;

//Robot
const int ROBOT_WIDTH = 50;
const int ROBOT_HEIGHT = 28;
const int ROBOT_HP = 10;
const int ROBOT_DAMAGE = 2;
const int ROBOT_SPEED = 1;

const float ROBOT_INITX = WIN_WIDTH*0.9;
const float ROBOT_INITY = WIN_HEIGHT*0.9;



#endif
