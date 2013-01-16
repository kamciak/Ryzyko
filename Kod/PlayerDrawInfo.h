#ifndef PLAYERDRAWINFO_H
#define PLAYERDRAWINFO_H

#include <wx/wx.h>

#include "Player.h"

class PlayerDrawInfo{
public:
    bool current;
    PlayerColor color;    
    unsigned int territories;
    wxString name;
    
    
    PlayerDrawInfo(bool c, PlayerColor col, unsigned int terr, wxString n) : current(c), color(col), territories(terr), name(n){}
};

#endif
