#ifndef PLAYER_H
#define PLAYER_H
#include <wx/wx.h>

enum PlayerColor{
        RED, BLUE, GREEN, YELLOW, PURPLE, GRAY, MAGENTA, CYAN, ORANGE, DARKBLUE    
};

class Player{
private:
    wxString _name;
    wxImage _soldier_image;
    wxImage _soldier_image_big;
    bool _dead;
    PlayerColor _color;
public:
    Player(wxString player_name, PlayerColor player_color);
    wxString name();
    wxImage & image(bool big);
    bool isDead();
    void kill();
    PlayerColor color();
};






#endif
