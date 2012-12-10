#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Board.h"
#include "PlayersData.h"
class RiskFrm;

class Controller{
private:    
    Controller(const Controller & c);
    Controller & operator=(const Controller & c);
    unsigned int _selected_region;    
    RiskFrm & _window;
public:
    void setSelectedRegion(unsigned int id);
    void selectRegion(unsigned int x, unsigned int y);
    Controller(Board & b, PlayersData & pd, RiskFrm & window);
    PlayersData & players_data;
    Board & board;    
};



#endif
