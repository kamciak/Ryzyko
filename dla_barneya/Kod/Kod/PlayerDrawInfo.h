#ifndef PLAYERDRAWINFO_H
#define PLAYERDRAWINFO_H

#include <wx/wx.h>

#include "Player.h"

class PlayerDrawInfo{
public:
    bool dead;
    bool current;
    PlayerColor color;    
    unsigned int territories;
    wxString name;
    
    
    PlayerDrawInfo(bool d, bool c, PlayerColor col, unsigned int terr, wxString n) : dead(d), current(c), color(col), territories(terr), name(n){}
};

#endif
