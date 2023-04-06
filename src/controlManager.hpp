#ifndef CONTROLMANAGER_HPP
#define CONTROLMANAGER_HPP
#include <SFML/Graphics.hpp>

class ControlManager {

    public :

    static ControlManager& get_instance(){
        static ControlManager instance;
        return instance;
    }

    void gameInput();
    void menuInput();
    void pauseInput();
    void shopInput();
    void endScreenInput();
    
    protected :

    ControlManager();

    //Empeche la copie et l'assignation
    ControlManager(const ControlManager&) = delete;
    ControlManager& operator=(const ControlManager&) = delete;
    
    sf :: Event event;


    bool gameON = true;
    bool menuON = true;
    bool pauseON = false;
    bool shopON = false;

};


#endif
