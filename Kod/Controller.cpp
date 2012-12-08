#include "Controller.h"

Controller::Controller(){
    _players.push_back(Player("Gracz 1", wxColour(255,0,0)));
    _players.push_back(Player("Gracz 2", wxColour(0,0,255)));
    _players.push_back(Player("Gracz 3", wxColour(0,255,0)));
    _players.push_back(Player("Gracz 4", wxColour(255,0,255)));
    _players.push_back(Player("Gracz 5", wxColour(255,255,0)));
    _players.push_back(Player("Gracz 6", wxColour(0,255,255)));
    _players[0].toggleUsed();
    _players[1].toggleUsed();
}

void Controller::setPlayerName(unsigned int id,const std::string name){
        _players.at(id).setName(name);
}

void Controller::setPlayerColor(unsigned int id, const wxColour color){
        _players.at(id).setColor(color);
}

void Controller::togglePlayerUsed(unsigned int id){
        _players.at(id).toggleUsed();
}
