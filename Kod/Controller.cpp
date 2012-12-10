#include "Controller.h"
#include "RiskFrm.h"
void Controller::setSelectedRegion(unsigned int id){
    _selected_region = id;
    _window.paintSelectedRegion(id);
}
    
Controller::Controller(Board & b, PlayersData & pd, RiskFrm & window) : board(b), players_data(pd), _window(window), _selected_region(42) {}
