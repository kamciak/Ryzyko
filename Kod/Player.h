#ifndef PLAYER_H
#define PLAYER_H
#include <wx/wx.h>
#include <vector>

#include "RiskCard.h"

#define NUMBER_OF_COLORS 10

enum PlayerColor{
        RED, BLUE, GREEN, YELLOW, PURPLE, GRAY, MAGENTA, CYAN, ORANGE, DARKBLUE    
};



class Player{
private:
    wxString _name;
    wxImage _soldier_image;
    wxImage _soldier_image_big;
    PlayerColor _color;
    bool _neutral;
public:
    Player(wxString player_name, PlayerColor player_color, bool neutral);
    std::vector<RiskCard*> hand;    
    wxString name();
    wxImage & image(bool big);
    PlayerColor color();
    bool isNeutral();
};






#endif
