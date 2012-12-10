#include "Controller.h"
#include "RiskFrm.h"
void Controller::setSelectedRegion(unsigned int id){
    _selected_region = id;
    _window.paintSelectedRegion(id);
}
    
void Controller::selectRegion(unsigned int x, unsigned int y){
    char red = _window.mask->GetRed(x,y);
    char blue = _window.mask->GetBlue(x,y);
    if(blue)
        setSelectedRegion(red);
    else
        setSelectedRegion(42);
}

Controller::Controller(Board & b, PlayersData & pd, RiskFrm & window) : board(b), players_data(pd), _window(window), _selected_region(42) {}
