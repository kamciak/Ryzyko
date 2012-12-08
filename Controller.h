#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Player.h"
#include "Board.h"
#include <wx/colour.h>
#include <iostream>
#include <vector>

#define MAX_PLAYERS 6

///Klasa - singleton, przechowuje informacje o graczach, planszy itp.
class Controller{
private:
    //////////////////////////////////////////////
    Controller();                              //
    Controller(const Controller & c);           //  obsluga singletonu
    Controller& operator=(const Controller & c);//
    //////////////////////////////////////////////
    std::vector<Player> _players;
    Board _board;
    
public:
    ////////////////////////////////////
    static Controller & getInstance(){//
          static Controller instance; //
          return instance;            //obsluga singletonu
    }                                 //
    ////////////////////////////////////

    void setPlayerName(unsigned int id, const std::string name);
    void setPlayerColor(unsigned int id, const wxColour color);
    void togglePlayerUsed(unsigned int id);
};

#endif
