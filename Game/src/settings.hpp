#ifndef SETTINGS_HPP
#define SETTINGS_HPP

//Window
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

//Delimitation bordure interne

const int WIN_INT_POSX = 100;
const int WIN_INT_POSY = 100;
const int WIN_INT_WIDTH = 600;
const int WIN_INT_HEIGHT = 400;

//Id
const int CHATEAU_ID = 0;
const int JOUEUR_ID = 1;
const int MBOT_ID = 2;
const int BOMBOT_ID = 3;
const int BOMBE_ID = 4;

//Chateau

const float CHATEAU_INITX = WIN_WIDTH/2;
const float CHATEAU_INITY = WIN_HEIGHT/2;
const int CHATEAU_WIDTH = 63;
const int CHATEAU_HEIGHT = 72;
const int CHATEAU_HP = 300;

//Bombe

const int BOMBE_WIDTH = 50;
const int BOMBE_HEIGHT = 28;
const int BOMBE_HP = 2;
const int BOMBE_DAMAGE = 5;

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

//Mbot
const int MBOT_WIDTH = 50;
const int MBOT_HEIGHT = 28;
const int MBOT_HP = 10;
const int MBOT_DAMAGE = 2;
const int MBOT_SPEED = 1;

//Bombot

const int BOMBOT_WIDTH = 50;
const int BOMBOT_HEIGHT = 28;
const int BOMBOT_HP = 20;
const int BOMBOT_DAMAGE = 4;
const int BOMBOT_SPEED = 1;

// Corde
const float Kv = GUERRIER_SPEED/200.0;


#endif
